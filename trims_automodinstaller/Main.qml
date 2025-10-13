import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtQuick.Dialogs

ApplicationWindow {
    width: 1920 / 2
    height: 1080 / 2
    visible: true
    title: qsTr("Auto Mod Installer")

    header: MenuBar {
        Menu {
            title: qsTr("&File")
            Action {
                text: qsTr("&Exit")
                onTriggered: Qt.quit()
            }
        }
    }

    Button {
        id: install_mods_button
        visible: true;
        anchors { horizontalCenter: parent.horizontalCenter; bottom: parent.bottom; bottomMargin: 100}
        scale: 1

        contentItem: Text {
            text: "Install Mods"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            scale: 2
        }

        background: Rectangle {
            implicitWidth: 480
            implicitHeight: 60
            border.width: 3
        }

        onClicked: {
            signals.download()
        }

    }

    Rectangle {
        id: folder_input_border
        width: 480
        height: 34
        anchors.centerIn: folder_input
        border.color: "black"
        border.width: 3
    }

    TextInput {
        property bool first_click: false
        id: folder_input
        anchors { horizontalCenter: install_mods_button.horizontalCenter; bottom: install_mods_button.bottom; bottomMargin: -30}
        text: "Insert Folder Here"
        scale: 1.25
        visible: true;
        activeFocusOnPress: true

        onFocusChanged: {
            if(focus) {
                if (first_click == false) {
                    clear()
                    }
            }
            first_click = true
        }
    }

    Button {
        id: quick_insert_folder_button
        visible: true
        anchors {horizontalCenter: folder_input.horizontalCenter; verticalCenter: folder_input.verticalCenter; horizontalCenterOffset: 260}
        icon.source: "icons/6700085.png"

        background: Rectangle {
            implicitWidth: 34
            implicitHeight: 34
            border.width: 3
        }

        onClicked: {

            signals.callMe()
            folderDialog.open()

    }

    FolderDialog {
        id: folderDialog

        onAccepted: {
            folder_input.first_click = true
            signals.variableChange()
            var path = selectedFolder.toString().replace("file:///", "")
            console.log(path)
            folder_input.text = path
        }

    }
}
}
