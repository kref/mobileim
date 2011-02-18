import Qt 4.7

Rectangle {
    property alias text: textElement.text
    property alias textColor: textElement.color


    width: 100
    height: 30
    color: "grey"
    radius: 5

    Text {
        id: textElement
        anchors.centerIn: parent
        text: "Button"
        color: "black"
    }

    MouseArea {
        anchors.fill: parent
        property color oldColor: "grey"
        onPressed: {
            oldColor = parent.color
            parent.color = "lightgrey"

        }
        onReleased: {
            parent.color = oldColor
        }
    }
}
