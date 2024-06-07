#include <QTest>
#include <spdlog/spdlog.h>

///////////////////////////////////////////////////////////////////////////////
// Tests
///////////////////////////////////////////////////////////////////////////////
class TestSpdlog : public QObject
{
    Q_OBJECT

private slots:
    void disableSpdlog()
    {
        spdlog::set_level(spdlog::level::off);
        spdlog::info("Hello, {}!", "World");
        spdlog::warn("Hello, {}!", "World");
        spdlog::error("Hello, {}!", "World");
    }

    void getSomething()
    {
        auto logger = spdlog::get("foo");
        QCOMPARE(logger, nullptr);
    }

    void printSomething()
    {
        spdlog::info("Hello, {}!", "World");
        spdlog::warn("Hello, {}!", "World");
        spdlog::error("Hello, {}!", "World");
    }
};

QTEST_MAIN(TestSpdlog)
#include "tst_spdlog.moc"
