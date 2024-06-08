#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <QApplication>
#include <spdlog/spdlog.h>

bool printSomething()
{
    QApplication app();
    spdlog::info("Hello, {}!", "World");
    spdlog::warn("Hello, {}!", "World");
    spdlog::error("Hello, {}!", "World");
    return true;
}

TEST_CASE("testing spdlog")
{
    CHECK(printSomething());
}
