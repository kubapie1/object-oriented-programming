import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
//import pl.gwizdz 1.0
import pl.kuba 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Displacement{
        id: displacement
        value: 0
        onChanged: function(value){
            speed.onDisplacementChanged(value)
        }

    }

    Acceleration{
        id: acceleration
        onChanged: function(value){
            labelAcceleration.text = value
        }
    }

    Speed{
        id: speed
        currentDisplacement: 0
        onChanged: function(value){
            labelSpeed.text = value//speed.getCurrentSpeed()
            acceleration.onSpeedChanged(value)
        }
    }

    Button {
        id: button
        x: 242
        y: 137
        text: qsTr("Button")
        onClicked: displacement.set(textInput.text)
    }

    TextInput {
        id: textInput
        x: 262
        y: 111
        width: 80
        height: 20
        text: qsTr("0")
        font.pixelSize: 12
    }



    Label {
        id: labelSpeed
        x: 283
        y: 192
        text: qsTr("Label")
    }

    Label {
        id: labelAcceleration
        x: 283
        y: 242
        text: qsTr("Label")
    }

    Label {
        id: label
        x: 183
        y: 192
        text: qsTr("V:")
    }

    Label {
        id: label1
        x: 183
        y: 242
        text: qsTr("A:")
    }

    Label {
        id: label2
        x: 183
        y: 111
        text: qsTr("D:")
    }


}
