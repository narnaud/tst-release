add_executable(tst_qt tst_qt.cpp)
target_link_libraries(tst_qt PRIVATE Qt${QT_VERSION_MAJOR}::Test)
add_test(tst_qt ${CMAKE_BINARY_DIR}/bin/tst_qt)

add_executable(tst_spdlog tst_spdlog.cpp)
target_link_libraries(tst_spdlog PRIVATE Qt${QT_VERSION_MAJOR}::Test spdlog::spdlog)
add_test(tst_spdlog ${CMAKE_BINARY_DIR}/bin/tst_spdlog)
