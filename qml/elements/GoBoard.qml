import QtQuick 2.2
import QtQuick.Layouts 1.1

Item {
    id: board
    property int boardSize: 13

    GridLayout {
        anchors.centerIn: parent
        anchors.fill: parent

        columns: parent.boardSize

        columnSpacing: -1
        rowSpacing: -1

        Repeater {
            model : parent.columns * parent.columns

            GoSquare {
                state: index == 0 ? "TopLeft" : index < boardSize-1 ? "Top" : index == boardSize-1 ? "TopRight" : index == (boardSize*(boardSize-1)) ? "BottomLeft" : index == (boardSize*boardSize-1) ? "BottomRight" : index%boardSize==0 ? "Left" : index%boardSize==12 ? "Right" : index < (boardSize*(boardSize-1)) ? "Normal" : "Bottom"
                Layout.fillWidth: true
                Layout.fillHeight: true

                GoPiece {
                    anchors.centerIn: parent
                    width: parent.width * 3/4
                    height: width

                    state: index == 54 ? "white" : index == 55 ? "black" : "empty"
                }
            }
        }

    }

    Image {
        z: -1
        source: "images/board.svg"
        anchors.centerIn: parent
        anchors.fill: parent
    }
}
