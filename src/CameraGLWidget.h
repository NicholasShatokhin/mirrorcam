#ifndef __CameraGLWidget_h
#define __CameraGLWidget_h

#include <QtOpenGL/QtOpenGL>
#include <QTimer>
#include <QMessageBox>
#include <opencv/cv.h>
#include <opencv/highgui.h>

class QTimer;
struct CvCapture;
struct _IplImage;

class CameraGLWidget: public QGLWidget
{
    Q_OBJECT

  private:
    int window_width;
    int window_height;
    int capture_width;
    int capture_height;

    QTimer *m_timer;
	CvCapture *m_capture;
	_IplImage *m_image;
    _IplImage *m_image_resized;
				
  public:
    CameraGLWidget(QWidget *parent=NULL);
    ~CameraGLWidget();

    int getCaptureWidth();
    int getCaptureHeight();

  protected:
	void initializeGL();
	void paintGL();
    void resizeGL(int nWidth, int nHeight);

  private slots:
	void captureFrame();
};

#endif

