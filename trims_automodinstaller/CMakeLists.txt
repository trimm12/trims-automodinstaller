cmake_minimum_required(VERSION 3.16)

project(trims_automodinstaller VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(apptrims_automodinstaller
    main.cpp
)

qt_add_qml_module(apptrims_automodinstaller
    URI trims_automodinstaller
    VERSION 1.0
    QML_FILES
        Main.qml
        RESOURCES
            icons/6700085.png
            SOURCES
            SOURCES signalsclass.h signalsclass.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(apptrims_automodinstaller PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.apptrims_automodinstaller
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(apptrims_automodinstaller
    PRIVATE Qt6::Quick
)
target_link_libraries(apptrims_automodinstaller PRIVATE Qt6::Core)
target_link_libraries(apptrims_automodinstaller PRIVATE Qt6::Core)

include(GNUInstallDirs)
install(TARGETS apptrims_automodinstaller
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
