import Qt 4.7

Rectangle {
    property int timerInterval: 3000

    width: 100
    height: 300
    color: "black"
    Column {
        anchors.fill: parent
        spacing: 5
        Rectangle {
            id: red
            anchors.left: parent.left
            anchors.leftMargin: 5
            width: parent.width - 10
            height: width
            radius: width / 2
            color: "red"
        }
        Rectangle {
            id: yellow
            anchors.left: parent.left
            anchors.leftMargin: 5
            width: parent.width - 10
            height: width
            radius: width / 2
            color: "yellow"
        }
        Rectangle {
            id: green
            anchors.left: parent.left
            anchors.leftMargin: 5
            width: parent.width - 10
            height: width
            radius: width / 2
            color: "green"
        }
    }
    state: "redState"
    states: [
        State {
            name: "redState"
            PropertyChanges {
                target: red
                color: "red"
            }
            PropertyChanges {
                target: yellow
                color: "grey"
            }
            PropertyChanges {
                target: green
                color: "grey"
            }

        } ,
        State {
            name: "yellowState"
            PropertyChanges {
                target: red
                color: "grey"
            }
            PropertyChanges {
                target: yellow
                color: "yellow"
            }
            PropertyChanges {
                target: green
                color: "grey"
            }
        },
        State {
            name: "greenState"
            PropertyChanges {
                target: red
                color: "darkgrey"
            }
            PropertyChanges {
                target: yellow
                color: "grey"
            }
            PropertyChanges {
                target: green
                color: "green"
            }
        },
        State {
            name: "redYellowState"
            PropertyChanges {
                target: red
                color: "red"
            }
            PropertyChanges {
                target: yellow
                color: "yellow"
            }
            PropertyChanges {
                target: green
                color: "grey"
            }
        }
    ]
    Timer {
        running: true
        interval: timerInterval
        repeat: true

        onTriggered: {
            if (state == "redState") {
                state = "redYellowState"
            }
            else if (state == "redYellowState") {
                state = "greenState"
            }
            else if (state == "greenState") {
                state = "yellowState"
            }
            else {
                state = "redState"
            }
        }
    }
}
