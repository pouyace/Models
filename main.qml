import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3

Window {
    id: root
    visible: true
    maximumWidth: 840
    maximumHeight: 480
    minimumWidth: 840
    minimumHeight: 480
    property var listItemHeight: 30
    color: "#444"
    title: qsTr("DF Monitoring")
    ListView{
        id: listView
        width: 840
        height: 440
        anchors.fill: parent
        model: myModel

        delegate:
            Column{
            spacing: 20
            Rectangle{
                width: 840
                height: root.listItemHeight
                ListItem{
                    itemBandwidth: model.Bandwidth
                    itemFrequency: model.Frequency
                    itemGain: model.Gain
                    itemResolution: model.Resolution
                    itemThreshold: model.Threshold
                    itemValidity: model.Validity
                }
            }
        }
    }
}
