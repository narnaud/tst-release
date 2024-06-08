add_executable(tst_spdlog tst_spdlog.cpp)
target_link_libraries(tst_spdlog PRIVATE Qt${QT_VERSION_MAJOR}::Widgets spdlog::spdlog)
add_test(tst_spdlog ${CMAKE_BINARY_DIR}/bin/tst_spdlog)
