set(PROJECT_SOURCES main.cpp widget.cpp widget.h widget.ui)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(tst-release-please MANUAL_FINALIZATION ${PROJECT_SOURCES})
  # Define target properties for Android with Qt 6 as: set_property(TARGET
  # tst-release-please  APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
  # ${CMAKE_CURRENT_SOURCE_DIR}/android) For more information, see
  # https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
  if(ANDROID)
    add_library(tst-release-please SHARED ${PROJECT_SOURCES})
    # Define properties for Android with Qt 5 after find_package() calls as:
    # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
  else()
    add_executable(tst-release-please ${PROJECT_SOURCES})
  endif()
endif()

target_link_libraries(tst-release-please PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1. If
# you are developing for iOS or macOS you should consider setting an explicit,
# fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER
                       com.example.tst-release-please)
endif()
set_target_properties(
  tst-release-please
  PROPERTIES ${BUNDLE_ID_OPTION} MACOSX_BUNDLE_BUNDLE_VERSION
             ${PROJECT_VERSION} MACOSX_BUNDLE_SHORT_VERSION_STRING
             ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR} MACOSX_BUNDLE
             TRUE WIN32_EXECUTABLE
             TRUE)

include(GNUInstallDirs)
install(
  TARGETS tst-release-please
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

if(QT_VERSION_MAJOR EQUAL 6)
  qt_finalize_executable(tst-release-please)
endif()
