#include "MainWindow.h"
#include "ui_MainForm.h"

MainWindow::MainWindow():QMainWindow(0)
{
    info = new Details(this);
    settings = new Settings(this);

    fullscreen = false;

    gui.setupUi(this);

    QDeclarativeContext* context = gui.menu->rootContext();
    context->setContextProperty("fullscreen",fullscreen);
    context->setContextProperty("windowWidth",this->width());
    gui.menu->setSource(QUrl("qrc:/menu.qml"));

    QPalette pal = this->palette();
    pal.setColor(this->backgroundRole(), Qt::black);
    this->setPalette(pal);

    gui.menu->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    setMouseTracking(true);

    QObject *item = gui.menu->rootObject();
    connect(item, SIGNAL(switchToFullscreen()), this, SLOT(toggleFullscreen()));
    connect(item, SIGNAL(switchToWindow()), this, SLOT(disableFullscreen()));
    connect(item, SIGNAL(showSettings()), this, SLOT(showSettings()));
    connect(item, SIGNAL(showInfo()), this, SLOT(showInfo()));
    connect(item, SIGNAL(closeApp()), this, SLOT(closeApp()));

    settings->loadSettings();
    this->resize(settings->getWidth(), settings->getHeight());
}

MainWindow::~MainWindow()
{
    delete info;
    delete settings;
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    settings->setWidth(this->width());
    settings->setHeight(this->height());
    settings->saveSettings();

    QDeclarativeContext* context = gui.menu->rootContext();
    context->setContextProperty("windowWidth",this->width());

    float width = this->width();
    float height = this->height();
    int dy = 0;

    if(!fullscreen)
    {
        height -= gui.menu->height();
        dy = gui.menu->height();
    }

    resizeVideoFrame(0, dy, width, height);

    gui.menu->setGeometry(0,0,this->width(), 60);
}

void MainWindow::resizeVideoFrame(int dx, int dy, int width, int height)
{
    int capture_width = gui.glWidget->getCaptureWidth();
    int capture_height = gui.glWidget->getCaptureHeight();

    int new_width = width;
    int new_height = capture_height * width / capture_width;

    if(new_height > height)
    {
        new_height = height;
        new_width = capture_width * height / capture_height;
    }

    gui.glWidget->setGeometry((width - new_width)/2+dx,(height - new_height)/2+dy,new_width,new_height);
}

void MainWindow::toggleFullscreen()
{
    if(fullscreen) return;

    gui.menu->setVisible(false);
    this->setWindowState(Qt::WindowFullScreen);
    fullscreen = true;

    QDeclarativeContext* context = gui.menu->rootContext();
    context->setContextProperty("fullscreen",fullscreen);
}

void MainWindow::disableFullscreen()
{
    if(!fullscreen) return;

    gui.menu->setVisible(true);
    this->setWindowState(Qt::WindowNoState);
    fullscreen = false;

    QDeclarativeContext* context = gui.menu->rootContext();
    context->setContextProperty("fullscreen",fullscreen);
}

void MainWindow::keyPressEvent(QKeyEvent *ke)
{
    switch (ke->key())
    {
        case Qt::Key_Escape:
            if(fullscreen)
                disableFullscreen();
            else
                exit(EXIT_SUCCESS);
            break;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *me)
{
    me->accept();

    if(fullscreen)
    {
        if(me->y() == 0)
            gui.menu->setVisible(true);
        else if(me->y() > gui.menu->height())
            gui.menu->setVisible(false);
    }
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *)
{
    if(fullscreen)
        disableFullscreen();
    else
        toggleFullscreen();
}

void MainWindow::showSettings()
{
    if(settings->exec() == 1)
    {
        settings->saveSettings();
        this->setGeometry(this->x(), this->y(), settings->getWidth(), settings->getHeight());
    }
}

void MainWindow::showInfo()
{
    info->show();
}

void MainWindow::closeApp()
{
    exit(EXIT_SUCCESS);
}
