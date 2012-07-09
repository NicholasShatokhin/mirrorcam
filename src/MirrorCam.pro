QT       += core gui opengl declarative

DESTDIR += ../bin

HEADERS += \
    MainWindow.h \
    CameraGLWidget.h \
    details.h \
    settings.h

SOURCES += \
    MainWindow.cpp \
    CameraGLWidget.cpp \
    main.cpp \
    details.cpp \
    settings.cpp

FORMS += \
    MainForm.ui \
    details.ui \
    settings.ui

LIBS += -lopencv_core -lopencv_highgui -lopencv_imgproc

RESOURCES += \
    resource.qrc

OTHER_FILES += \
    menu.qml \
    Button.qml
