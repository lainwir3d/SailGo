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

            MouseArea {
                Layout.fillWidth: true
                Layout.fillHeight: true

                onClicked: {
                    console.log("cliqued index "+index);
                    boardController.playMove(index);
                }

                GoSquare {
                    anchors.centerIn: parent
                    anchors.fill: parent

                    state: squareState

                    GoPiece {
                        anchors.centerIn: parent
                        width: parent.width
                        height: width

                        state: pieceState
                    }
                }
            }
        }
    }

    Image {
        z: -1
        source: "images/board.svg"

        sourceSize.width: 500
        sourceSize.height: 500

        anchors.centerIn: parent
        anchors.fill: parent
    }
}
