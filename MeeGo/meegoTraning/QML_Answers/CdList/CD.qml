import Qt 4.7

Rectangle {
    id: window

    width: 360
    height: 640
    color: "black"

    Component {
        id: cd_delegate

        Item {
            id: rect

            //radius: 5
            //width: coverImage.width
            //height: coverImage.height
            width: 100
            height: 100
            opacity: PathView.opacity
            scale: PathView.scale
            z: PathView.z
            Column {
                id: columni
                Image {
                    id: coverImage
                    source: "images\\" + cover
                    width: 100
                    height: 100
                    fillMode: Image.PreserveAspectFit

                }
                Text {
                    width: 100
                    id: artistText
                    color: "white"
                    text: artist
                    font.family: "Arial"
                    horizontalAlignment: Text.AlignHCenter
                }
                Text {
                    width: 100
                    id: albumText
                    color: "white"
                    text: album
                    horizontalAlignment: Text.AlignHCenter
                }
                MyButton {
                    id: button
                    color: "lightblue"
                    text: "Play"
                }

            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if( parent.state == "small" ) {
                        parent.state = "big"
                    }
                    else {
                        parent.state = "small"
                    }
                }
            }

            states: [
                State {
                    name: "small"
                    PropertyChanges {
                        target: artistText
                        opacity: 0
                    }
                    PropertyChanges {
                        target: albumText
                        opacity: 0
                    }
                    PropertyChanges {
                        target: button
                        opacity: 0
                }
                },
                State {
                    name: "big"
                   /* PropertyChanges {
                        target: artistText
                        opacity: 1
                    }
                    PropertyChanges {
                        target: albumText
                        opacity: 1
                    }*/
                    PropertyChanges {
                        target: rect

                        height: 130//columni.height
                        x: (window.width - rect.width) / 2
                        y: (window.height - rect.height) / 2
                        z: 200
                        scale: 2
                    }
                }
            ]
            state: "small"

            transitions: [
                Transition {
                    from: "*"
                    to: "*"
                    PropertyAnimation {
                        target: rect
                        properties: "scale, x, y"
                        duration: 700
                        easing.type: "OutElastic"
                    }

                }
            ]




        }


    }
  /*  GridView {
        id: view
        cellWidth: 105
        cellHeight: 105
        anchors.right: parent.right
        width: parent.width
        height: parent.height
        model: CDData{}
        delegate: cd_delegate
    }
*/
PathView {
    anchors.fill: parent
    model: CDData{}
    delegate: cd_delegate
    path: Path {
            startX: window.width/2; startY: 2* window.height / 3;
            PathAttribute { name: "opacity"; value: 1 }
            PathAttribute { name: "scale"; value: 1 }
            PathAttribute { name: "z"; value: 100 }
            PathQuad { x: window.width/2; y: window.height / 3; controlX: window.width+200; controlY: window.height/2}
            PathAttribute { name: "opacity"; value: 0.3 }
            PathAttribute { name: "scale"; value: 0.5 }
            PathAttribute { name: "z"; value: 0 }
            PathQuad { x: window.width/2; y: 2*window.height / 3; controlX: -200; controlY: window.height/2}

    }

}


}
