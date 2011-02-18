import Qt 4.7

Rectangle {
    width: 200
    height: 200
    color: "white"

    Grid {
        anchors.fill: parent
        spacing: 10
        columns: 2
        Rectangle {
            id: r1
            width: parent.width / 2 - 10
            height: parent.height / 2 - 10
            color: focus ? "blue" : "lightblue"
            KeyNavigation.right: r2
            KeyNavigation.down: r3
            KeyNavigation.left: r4
            KeyNavigation.up: r4
            focus: true
            MouseArea {
                anchors.fill: parent
                onClicked: parent.focus = true
            }
        }
        Rectangle {
            id: r2
            width: parent.width / 2 - 10
            height: parent.height / 2 - 10
            color: focus ? "green" : "lightgreen"
            KeyNavigation.right: r3
            KeyNavigation.down: r4
            KeyNavigation.left: r1
            KeyNavigation.up: r3
            MouseArea {
                anchors.fill: parent
                onClicked: parent.focus = true
            }
        }
        Rectangle {
            id: r3
            width: parent.width / 2 - 10
            height: parent.height / 2 - 10
            color: focus ? "darkgrey" : "grey"
            KeyNavigation.right: r4
            KeyNavigation.down: r2
            KeyNavigation.left: r2
            KeyNavigation.up: r1
            MouseArea {
                anchors.fill: parent
                onClicked: parent.focus = true
            }
        }
        Rectangle {
            id: r4
            width: parent.width / 2 - 10
            height: parent.height / 2 - 10
            color: focus ? "purple" : "red"
            KeyNavigation.right: r1
            KeyNavigation.down: r1
            KeyNavigation.left: r3
            KeyNavigation.up: r2
            MouseArea {
                anchors.fill: parent
                onClicked: parent.focus = true
            }
        }
    }
}
