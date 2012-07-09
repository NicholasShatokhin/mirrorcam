// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1

Rectangle {
     id:button
     color: "transparent"
     property string buttonBg: ""
     property string onHoverBg: ""
     property string pressedBg: ""

     signal buttonClick()
     signal buttonPress()
     signal buttonRelease()
     signal clicked()

     onButtonClick: {
         clicked()
     }

     onButtonPress: {
         background.source = pressedBg
     }

     onButtonRelease: {
         background.source = buttonBg
     }

     Image {
        id: background
        width: parent.width
        height: parent.height
        source: buttonMouseArea.pressed ? pressedBg : buttonBg
     }

     MouseArea{
         id: buttonMouseArea
         onClicked: buttonClick()
         onPressed: buttonPress()
         onReleased: buttonRelease()
         anchors.fill: parent
         hoverEnabled: true
         onEntered: background.source = onHoverBg
         onExited:  background.source = buttonBg
     }
 }
