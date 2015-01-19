import QtQuick 2.2
import QtQuick.Window 2.0
import QtQuick.Controls 1.1

import "../elements"

Window {
    visible: true
    width: 600
    height: 600
    title: qsTr("Hello World")


    GoBoard {
        anchors.centerIn: parent

        width: parent.width < parent.height ? parent.width : parent.height
        height: width

        hoverEnabled: true
    }
}
