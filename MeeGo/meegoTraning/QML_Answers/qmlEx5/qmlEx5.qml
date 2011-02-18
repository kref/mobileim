import Qt 4.7

Rectangle {
    id: window

    width: 500
    height: 500
    color: "black"

    Component {
        id: contact_delegate
        Rectangle {
            property int oldY: 0
            property int oldX: 0
            id: wholeItem
            radius: 5
            color: mousee.containsMouse ? "lightgray" : "gray"

            width: 70
            height: picture.height + 15 + columni.height

            Image {
                anchors.margins: 5
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                id: picture
                width: 60
                height: 60
                fillMode: Image.PreserveAspectFit
                source: (photo == undefined) ? "default.png" : photo
            }

            Text {
                id: teksti
                text: "joo"
                width: picture.width

            }

            MouseArea {
                id: mousee
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    if (parent.state == "small") {
                        parent.oldY = parent.y
                        parent.oldX = parent.x
                        parent.state = "big"

                    }
                    else {
                        parent.state = "small"

                    }
                }
            }

        Column {
            id: columni
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: picture.bottom
            anchors.margins: 5
                Text {

                    id: nameText
                    text: name
                    font.pixelSize: 10
                }
                Text {
                    id: phoneText
                    text: number
                    font.pixelSize: 10
                    opacity: 1
                }
                Text {
                    id: townText
                    text: hometown
                    font.pixelSize: 10
                    opacity: 1
                }
                Rectangle {
                    id: saveButton
                    width: 40
                    height: 10
                    radius: 4
                    color: "lightblue"
                    anchors.horizontalCenter: parent.horizontalCenter
                    Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: "Save"
                        font.pixelSize: 8
                    }
                    MouseArea {

                        id: nappulaMouse
                        anchors.fill: parent
                        onPressed: {
                            parent.color = "darkblue"
                        }
                        onReleased: {
                            parent.color = "lightblue"
                         //   mw.saveData(mw.getText()+nameText+"\n"+phoneText+
                         //               "\n"+townText+"\n\n")
                        }
                    }

                }
            }





            state: "small" //Initial values of state
            states: [
                State {
                    name: "small"
                    PropertyChanges {
                        target: wholeItem
                        scale: 1
                        z: 1
                        y: oldY
                        x: oldX
                        opacity: 1

                    }
                    PropertyChanges {
                        target: phoneText
                        opacity: 0

                    }
                    PropertyChanges {
                    target: townText
                    opacity: 0

                }
                    PropertyChanges {
                target: saveButton
                opacity: 0

            }

                },
                State {
                    name: "big"
                    PropertyChanges {
                        target: wholeItem
                        scale: 4
                        z: 2
                        y: (window.height -  wholeItem.height) / 2 - title.height - 5
                        x: (window.width -  wholeItem.width) / 2
                        opacity: 0.8
                    }
                    PropertyChanges {
                        target: phoneText
                        opacity: 1

                    }
                    PropertyChanges {
                        target: townText
                        opacity: 1

                    }  PropertyChanges {
                    target: saveButton
                    opacity: 1

                }

                   }

            ]
            transitions: [
                Transition {
                    from: "*"
                    to: "*"
                    PropertyAnimation {
                        target: wholeItem
                        properties: "scale, y, x, z"
                        duration: 700
                        easing.type: "OutElastic"
                    }
                }
            ]
          }

        }

    Text {
        id: title
        text: "Contacts"
        font.underline: true
        font.bold: true
        font.pixelSize: 20
        color: "White"
        anchors.horizontalCenter: parent.horizontalCenter
    }


    GridView {
        id: view
        anchors.top: title.bottom
        anchors.topMargin: 5

        width: parent.width
        height: parent.height
        model: ContactList{}
        delegate: contact_delegate
    }


}
