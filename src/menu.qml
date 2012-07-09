// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
    id: menu
    width: windowWidth
    height: 60

    //property bool fullscreen: false

    signal switchToFullscreen()
    signal switchToWindow()
    signal showSettings()
    signal showInfo()
    signal closeApp()

    Image {
         width: windowWidth; height: 60
         fillMode: Image.TileHorizontally
         smooth: false
         source: "qrc:/images/menu_bg.png"
     }

    Button {
        id: toggleFullscreen
        x: 14
        y: 14
        width: 32
        height: 32
        buttonBg: "qrc:/images/fullscreen_normal.png"
        onHoverBg: "qrc:/images/fullscreen_hover.png"
        pressedBg: "qrc:/images/fullscreen_pressed.png"
        visible: !fullscreen
        enabled: !fullscreen

        onButtonClick: {
            fullscreen = true
            switchToFullscreen()
        }
    }

    Button {
        id: disableFullscreen
        x: 14
        y: 14
        width: 32
        height: 32
        buttonBg: "qrc:/images/windowed_normal.png"
        onHoverBg: "qrc:/images/windowed_hover.png"
        pressedBg: "qrc:/images/windowed_pressed.png"
        visible: fullscreen
        enabled: fullscreen

        onButtonClick: {
            fullscreen = false
            switchToWindow()
        }
    }

    Button {
        id: settings
        x: 60
        y: 14
        width: 32
        height: 32
        buttonBg: "qrc:/images/settings_normal.png"
        onHoverBg: "qrc:/images/settings_hover.png"
        pressedBg: "qrc:/images/settings_pressed.png"

        onButtonClick: {
            showSettings()
        }
    }

    Button {
        id: info
        x: 106
        y: 14
        width: 32
        height: 32
        buttonBg: "qrc:/images/info_normal.png"
        onHoverBg: "qrc:/images/info_hover.png"
        pressedBg: "qrc:/images/info_pressed.png"

        onButtonClick: {
            showInfo()
        }
    }

    Button {
        id: exit
        x: 152
        y: 14
        width: 32
        height: 32
        buttonBg: "qrc:/images/exit_normal.png"
        onHoverBg: "qrc:/images/exit_hover.png"
        pressedBg: "qrc:/images/exit_pressed.png"

        onButtonClick: {
            closeApp()
        }
    }
}
