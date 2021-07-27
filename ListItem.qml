import QtQuick 2.12
Item{
    property double itemFrequency
    property int itemBandwidth
    property double itemResolution: 0
    property double itemGain: 0
    property double itemThreshold: 0
    property var itemValidity: 0

    property color trueValidityColor: "#22dd22"
    property color falseValidityColor: "#aaaa00"
    property color customTextColor: "#dddddd"
    anchors.fill: parent
    Rectangle{
        id: listRow
        anchors.fill: parent
        border.width: 1
        color: itemValidity ? trueValidityColor : falseValidityColor
        Row{
            topPadding:5
            Text{text: 'frequency: ' + itemFrequency; width:root.width/5; horizontalAlignment: Text.AlignHCenter;font.pointSize: 12; color: customTextColor}
            Text{text: 'bandwidth: ' + itemBandwidth; width:root.width/5; horizontalAlignment: Text.AlignHCenter;font.pointSize: 12; color: customTextColor}
            Text{text: 'resolution: ' + itemResolution;width:root.width/5;horizontalAlignment: Text.AlignHCenter; font.pointSize: 12; color: customTextColor}
            Text{text: 'threshold: ' + itemThreshold;width:root.width/5;horizontalAlignment: Text.AlignHCenter; font.pointSize: 12; color: customTextColor}
            Text{text: 'gain: ' + itemGain; width:root.width/5; horizontalAlignment: Text.AlignHCenter; font.pointSize: 12; color: customTextColor}
        }
    }
}
