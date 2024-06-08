#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <spdlog/spdlog.h>

bool printSomething()
{
    spdlog::info("Hello, {}!", "World");
    spdlog::warn("Hello, {}!", "World");
    spdlog::error("Hello, {}!", "World");
    return true;
}

TEST_CASE("testing spdlog")
{
    CHECK(printSomething());
}
