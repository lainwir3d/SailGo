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
            model : boardListModel

            GoSquare {
                state: squareState
                Layout.fillWidth: true
                Layout.fillHeight: true

                GoPiece {
                    anchors.centerIn: parent
                    width: parent.width * 3/4
                    height: width

                    state: pieceState
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
