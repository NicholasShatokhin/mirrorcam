#include "CameraGLWidget.h"

CameraGLWidget::CameraGLWidget(QWidget *parent):QGLWidget(parent)
{
    window_width = this->width();
    window_height = this->height();

    //Initialize variable members
	m_timer = new QTimer();
	m_image = 0;
    m_image_resized = 0;
	m_capture = cvCaptureFromCAM(0);
	if(!m_capture)
		QMessageBox::critical(this,"Error","Error initializing capture from WebCam");

    capture_width = cvGetCaptureProperty( m_capture, CV_CAP_PROP_FRAME_WIDTH );
    capture_height = cvGetCaptureProperty( m_capture, CV_CAP_PROP_FRAME_HEIGHT );

    //Get an initial frame from the webcam
	m_image = cvQueryFrame(m_capture);
    m_image_resized = cvCreateImage( cvSize(window_width , window_height), m_image->depth, m_image->nChannels );

	//Connect the timer signal with the capture action
	connect(m_timer, SIGNAL(timeout()), this, SLOT(captureFrame()));	

	//Start the timer scheduled for firing every 33ms (30fps)
	m_timer->start(33);	
}

CameraGLWidget::~CameraGLWidget()
{
	//Release the capture
	cvReleaseCapture(&m_capture);		
}

void CameraGLWidget::initializeGL()
{
    //Adjust the viewport
    glViewport(0,0,window_width, window_height);
	
	//Adjust the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glOrtho(-window_width/2, window_width/2, window_height/2, -window_height/2, -1, 1);
}

void CameraGLWidget::resizeGL(int nWidth, int nHeight)
{
    //Adjust the viewport
    glViewport(0,0,nWidth, nHeight);

    //Adjust the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-nWidth/2, nWidth/2, nHeight/2, -nHeight/2, -1, 1);

    window_width = nWidth;
    window_height = nHeight;

    if(m_image_resized != 0)
    {
        cvReleaseImage(&m_image_resized);
        m_image_resized = cvCreateImage( cvSize(window_width , window_height), m_image->depth, m_image->nChannels );
    }
}

void CameraGLWidget::paintGL()
{	
	//Clear the color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	//Set the raster position
	/*
	  The position seems to be the inverse because the rendering is
	  affected by the glPixelZoom call.
	 */
    glRasterPos2i(window_width/2,-window_height/2);
	//Inver the image (the data coming from OpenCV is inverted)
	glPixelZoom(-1.0f,-1.0f);

	//Draw image from OpenCV capture
    glDrawPixels(m_image_resized->width, m_image_resized->height, GL_RGB, GL_UNSIGNED_BYTE,m_image_resized->imageData);
}

void CameraGLWidget::captureFrame()
{	
	//Get an image from the webcam
	m_image = cvQueryFrame(m_capture);
    cvResize(m_image, m_image_resized);
	//Draw the scene
	glDraw();	
}

int CameraGLWidget::getCaptureWidth()
{
    return capture_width;
}

int CameraGLWidget::getCaptureHeight()
{
    return capture_height;
}
