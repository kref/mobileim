import Qt 4.7

Rectangle {
    width: 400
    height: 400
    color: "grey"
    Rectangle {
        id: lightblue
        width: parent.width - 2 * 20
        height: parent.height / 2 - 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 20
        color: "lightblue"
        Rectangle {
            id: white
            height: parent.height / 3
            width: parent.width / 7
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: height
            color: "white"
        }
    }
    Rectangle {
        id: green
        width: lightblue.width
        height: lightblue.height
        anchors.top: lightblue.bottom
        anchors.left: lightblue.left

        color: "green"
        Rectangle {
            id: blue
            height: parent.height / 3
            width: parent.width / 7 * 4
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: height + white.width
            color: "blue"
        }
    }
}
