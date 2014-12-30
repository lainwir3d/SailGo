import QtQuick 2.2

Image {
    id: piece
    source: "images/white_piece.svg"

    state: "black"

    states: [
        State {
            name: "empty"
            PropertyChanges {
                target: piece
                visible: false
                source: "images/white_piece.svg"
            }
        },
        State {
            name: "white"
            PropertyChanges {
                target: piece
                visible: true
                source: "images/white_piece.svg"
            }
        },
        State {
            name: "black"
            PropertyChanges {
                target: piece
                visible: true
                source: "images/black_piece.svg"
            }
        }

    ]
}
