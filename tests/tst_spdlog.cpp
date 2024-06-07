#include <QTest>
#include <spdlog/spdlog.h>

///////////////////////////////////////////////////////////////////////////////
// Tests
///////////////////////////////////////////////////////////////////////////////
class TestSpdlog : public QObject
{
    Q_OBJECT

private slots:
    void printSomething()
    {
        spdlog::info("Hello, {}!", "World");
        spdlog::warn("Hello, {}!", "World");
        spdlog::error("Hello, {}!", "World");
    }

    void getSomething()
    {
        auto logger = spdlog::get("foo");
        QCOMPARE(logger, nullptr);
    }
};

QTEST_MAIN(TestSpdlog)
#include "tst_spdlog.moc"
