import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtQuick.Dialogs

ApplicationWindow {
    width: 2560 / 2
    height: 1440 / 2
    visible: true
    title: qsTr("trim's AMI")

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
        anchors { horizontalCenter: parent.horizontalCenter; bottom: parent.bottom; bottomMargin: 200}
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

    Text {
        id: debug
        text: signals.debugText
        anchors { horizontalCenter: parent.horizontalCenter; bottom: parent.bottom; bottomMargin: 5 }
    }

    Rectangle {
        id: title_border
        width: 720
        height: 80
        anchors.centerIn: title
        border.color: "black"
        border.width: 3
    }

    Text {
        id: title
        anchors { horizontalCenter: parent.horizontalCenter; top: parent.top; topMargin: 100}
        scale: 4
        text: "trim's Auto Mod Installer"

    }

    TextField {
        property bool first_click: false
        id: folder_input
        anchors { horizontalCenter: install_mods_button.horizontalCenter; bottom: install_mods_button.bottom; bottomMargin: -40}
        text: "Insert Folder Here"
        visible: true;
        activeFocusOnPress: true
        clip: true
        font.pixelSize: 16
        horizontalAlignment: TextInput.AlignHCenter
        verticalAlignment: TextInput.AlignVCenter

        background: Rectangle {
            implicitWidth: 480
            implicitHeight: 34
            color: "white"
            border.color: "black"
            border.width: 3
        }

        onFocusChanged: {
            if(focus) {
                if (first_click == false) {
                    clear()
                    }
            }
            first_click = true
        }

        onAccepted: {
            folder_input.first_click = true
            var path = text.toString()
            console.log(path)
            folder_input.text = path
            signals.folderChange(path)
        }
    }

    TextField {
        property bool first_click: false
        id: url_input
        anchors { horizontalCenter: install_mods_button.horizontalCenter; bottom: install_mods_button.bottom; bottomMargin: -80}
        text: "Insert URL here"
        visible: true;
        activeFocusOnPress: true
        clip: true
        font.pixelSize: 16
        horizontalAlignment: TextInput.AlignHCenter
        verticalAlignment: TextInput.AlignVCenter

        background: Rectangle {
            implicitWidth: 480
            implicitHeight: 34
            color: "white"
            border.color: "black"
            border.width: 3
        }

        onFocusChanged: {
            if(focus) {
                if (first_click == false) {
                    clear()
                    }
            }
            first_click = true
        }

        onAccepted: {
            var path = text.toString()
            console.log(path)
            url_input.text = path
            signals.remoteChange(path)
        }
    }

    Button {
        id: quick_insert_folder_button
        visible: true
        anchors {horizontalCenter: folder_input.horizontalCenter; verticalCenter: folder_input.verticalCenter; horizontalCenterOffset: 260}
        icon.source: "icons/file_dialog.png"

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
            var path = selectedFolder.toString().replace("file:///", "")
            console.log(path)
            folder_input.text = path
            signals.folderChange(path)
        }

    }
}

    Window {
        title: qsTr("trim's AML - Mod List")
        id: subWindow
        width: 3840 / 4
        height: 2160 / 4
        visible: false

        ScrollView {
            id: view
            anchors.fill: parent

            TextArea {
                activeFocusOnPress: false
                text: "The following Names and Descriptions are from the User Generated Json file specified in the URL slot:\n\n" + signals.modListText
            }
        }
    }

    Button {
        id: show_mod_list
        visible: true
        anchors {horizontalCenter: url_input.horizontalCenter; verticalCenter: url_input.verticalCenter; horizontalCenterOffset: 260}
        icon.source: "icons/mod_list.png"

        background: Rectangle {
            implicitWidth: 34
            implicitHeight: 34
            border.width: 3
        }

        onClicked: {
            subWindow.visible = true
        }
    }
}
