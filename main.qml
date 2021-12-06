import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15
import Mike 1.0
Window {
    id: mainWindow
    width: 340
    height: 455
    visible: true
    color: "transparent"
    // Usunięcie paska okienkowego
    flags: Qt.Window | Qt.FramelessWindowHint

    // Właściwości
    property string buttonColor: "#24000000"    // 14% transparentnoci koloru czarnego
    property string buttonText: "white"
    property int fontSize: 20
    property int buttonRadius: 15
    property int buttonWidth: 75
    property int buttonHeight: 75


//    // Keyboard-Control
//    Item {

//        id: keyboardInputArea
//        width: mainWindow.width
//        height: mainWindow.height
//        focus: true

//        // Key-Input
//        Keys.onReleased:
//        {

//            // Deubg-log
//            console.log( "Key pressed #" + event.text );

//            // Logic
//            if ( event.key === Qt.Key_Enter )
//                resultText.text = logic.doMath( );
//            else if ( event.key === Qt.Key_Plus )
//                resultText.text = logic.setOperationType( "+" )
//            else if ( event.key === Qt.Key_Minus )
//                resultText.text = logic.setOperationType( "-" )
//            else if ( event.text === "/" ) // Can be replaced with key-code.
//                resultText.text = logic.setOperationType( "/" )
//            else if ( event.text === "*" ) /// Numpad multiply-key not respond.
//                resultText.text = logic.setOperationType( "*" )
//            else if ( event.text === "." )
//                resultText.text = logic.onDot( );
//            else if ( event.text === "," )
//                resultText.text = logic.onDot( );
//            else
//                resultText.text = logic.onKeyboardInput( event.text );

//            // Mark Event as handled.
//            event.accepted = true;

//        } // Keys.onReleased

//    } // Keyboard-Control

    CalculatorLogic{
        id: logic
    }


    Rectangle {
        id: background
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        radius: 28
        color: "#222222"
        Rectangle {
            id: mainPane
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.rightMargin: 5
            anchors.leftMargin: 5
            anchors.bottomMargin: 5
            anchors.topMargin: 25
            radius: 20

            LinearGradient {
                id: linearGradient
                visible: true
                anchors.fill: parent
                source: mainPane
                start: Qt.point(0, 0)
                end: Qt.point(340, 500)
                gradient: Gradient {
                    GradientStop { position: 0.0; color: "#FF7F50" }
                    GradientStop { position: 1.0; color: "#6A5ACD" }
                }
                // Wyświetlacz
                Rectangle {
                    id: display
                    x: 8
                    y: 8
                    width: 314
                    height: 87
                    color: "#24000000"
                    radius: 15

                    TextInput {
                        id: resultText
                        text: qsTr( "0" )
                        anchors.left: parent.left
                        anchors.right: parent.right
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        color: "white"
                        font.pixelSize: 30
                        horizontalAlignment: Text.AlignRight
                        verticalAlignment: Text.AlignVCenter
                        anchors.rightMargin: 8
                        anchors.leftMargin: 8
                        anchors.bottomMargin: 8
                        anchors.topMargin: 27
                    }

                    Text {
                        id: inputHistory
                        x: 79
                        y: 8
                        width: 227
                        height: 14
                        text: "0"
                        font.pixelSize: 12
                        horizontalAlignment: Text.AlignRight
                    }
                }

                // Siatka przycisków
                Grid {
                    id: grid
                    x: 8
                    width: 314
                    anchors.top: display.bottom
                    anchors.bottom: parent.bottom
                    anchors.topMargin: 11
                    anchors.bottomMargin: 4
                    columns: 4
                    rows: 4
                    spacing: 5
                    // Przyciski
                    RoundButton {id: button7; width: buttonWidth; height: buttonHeight; text:"7"; checkable: false; radius: buttonRadius; font.pointSize: fontSize; checked: false; onClicked: resultText.text = logic.onNumberInput( "7" ); palette{button: buttonColor ; buttonText: buttonText}}
                    RoundButton {id: button8; width: buttonWidth; height: buttonHeight; text:"8"; checkable: false; radius: buttonRadius; font.pointSize: fontSize; checked: false; onClicked: resultText.text = logic.onNumberInput( "8" ); palette{button: buttonColor ; buttonText: buttonText}}
                    RoundButton {id: button9; width: buttonWidth; height: buttonHeight; text:"9"; checkable: false; radius: buttonRadius; font.pointSize: fontSize; checked: false; onClicked: resultText.text = logic.onNumberInput( "9" ); palette{button: buttonColor ; buttonText: buttonText}}
                    RoundButton {id: buttonPlus; width: buttonWidth; height: buttonHeight; text:"+"; checkable: false; radius: buttonRadius; font.pointSize: fontSize; checked: false; onClicked: resultText.text = logic.setOperationType( "+" ); palette{button: buttonColor ; buttonText: buttonText}}
                    RoundButton {id: button4; width: buttonWidth; height: buttonHeight; text:"4"; checkable: false; radius: buttonRadius; font.pointSize: fontSize; checked: false; onClicked: resultText.text = logic.onNumberInput( "4" ); palette{button: buttonColor ; buttonText: buttonText}}
                    RoundButton {id: button5; width: buttonWidth; height: buttonHeight; text:"5"; checkable: false; radius: buttonRadius; font.pointSize: fontSize; checked: false; onClicked: resultText.text = logic.onNumberInput( "5" ); palette{button: buttonColor ; buttonText: buttonText}}
                    RoundButton {id: button6; width: buttonWidth; height: buttonHeight; text:"6"; checkable: false; radius: buttonRadius; font.pointSize: fontSize; checked: false; onClicked: resultText.text = logic.onNumberInput( "6" ); palette{button: buttonColor ; buttonText: buttonText}}
                    RoundButton {id: buttonMinus; width: buttonWidth; height: buttonHeight; text:"-"; checkable: false; radius: buttonRadius; font.pointSize: fontSize; checked: false; onClicked: resultText.text = logic.setOperationType( "-" ); palette{button: buttonColor ; buttonText: buttonText}}
                    RoundButton {id: button1; width: buttonWidth; height: buttonHeight; text:"1"; checkable: false; radius: buttonRadius; font.pointSize: fontSize; checked: false; onClicked: resultText.text = logic.onNumberInput( "1" ); palette{button: buttonColor ; buttonText: buttonText}}
                    RoundButton {id: button2; width: buttonWidth; height: buttonHeight; text:"2"; checkable: false; radius: buttonRadius; font.pointSize: fontSize; checked: false; onClicked: resultText.text = logic.onNumberInput( "2" ); palette{button: buttonColor ; buttonText: buttonText}}
                    RoundButton {id: button3; width: buttonWidth; height: buttonHeight; text:"3"; checkable: false; radius: buttonRadius; font.pointSize: fontSize; checked: false; onClicked: resultText.text = logic.onNumberInput( "3" ); palette{button: buttonColor ; buttonText: buttonText}}
                    RoundButton {id: buttonMultiply; width: buttonWidth; height: buttonHeight; text:"*"; checkable: false; radius: buttonRadius; font.pointSize: fontSize; checked: false; onClicked: resultText.text = logic.setOperationType( "*" ); palette{button: buttonColor ; buttonText: buttonText}}
                    RoundButton {id: buttonC; width: buttonWidth; height: buttonHeight; text:"C"; checkable: false; radius: buttonRadius; font.pointSize: fontSize; checked: false; onClicked: {logic.resetLogic( );resultText.text = "0"} palette{button: buttonColor ; buttonText: buttonText}}
                    RoundButton {id: button0; width: buttonWidth; height: buttonHeight; text:"0"; checkable: false; radius: buttonRadius; font.pointSize: fontSize; checked: false; onClicked: resultText.text = logic.onNumberInput( "0" ); palette{button: buttonColor ; buttonText: buttonText}}
                    RoundButton {id: buttonEqual; width: buttonWidth; height: buttonHeight; text:"="; checkable: false; radius: buttonRadius; font.pointSize: fontSize; checked: false; onClicked: resultText.text = logic.doMath( ); palette{button: buttonColor ; buttonText: buttonText}}
                    RoundButton {id: buttonDivide; width: buttonWidth; height: buttonHeight; text:"/"; checkable: false; radius: buttonRadius; font.pointSize: fontSize; checked: false; onClicked: resultText.text = logic.setOperationType( "/" ); palette{button: buttonColor ; buttonText: buttonText}}
                }
            }
        }
        // Przycisk zamknięcia aplikacji
        Image {
            id: exitImg
            x: 297
            y: 5
            width: 16
            height: 16
            source: "images/close.png"
            fillMode: Image.PreserveAspectFit
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    mainWindow.close()
                }
            }
        }
        // Przycisk minimalizacji
        Image {
            id: minImg
            x: 275
            y: 5
            width: 16
            height: 16
            source: "images/hide.png"
            fillMode: Image.PreserveAspectFit
        }
        // Tytuł okna
        Rectangle {
            id: titleRect
            width: 246
            color: "#00000000"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.topMargin: 5
            anchors.leftMargin: 23
            anchors.bottomMargin: 434

            Label {
                id: titleApp
                x: 14
                y: 2
                width: 68
                height: 13
                color: "#e5e8ea"
                text: qsTr("Calculator")
                anchors.verticalCenter: parent.verticalCenter
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }

            // Przesuwanie aplikacji
            MouseArea {
                id: titleArea
                anchors.fill: titleRect
                cursorShape: Qt.OpenHandCursor
                DragHandler {
                    onActiveChanged: if(active){
                                         mainWindow.startSystemMove()
                                     }
                }
            }
        }
    }



}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.66}
}
##^##*/
