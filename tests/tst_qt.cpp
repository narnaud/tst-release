#include <QTest>

///////////////////////////////////////////////////////////////////////////////
// Tests
///////////////////////////////////////////////////////////////////////////////
class TestQt : public QObject
{
    Q_OBJECT

private slots:
    void printSomething() { qDebug() << "Hello, World!"; }

    void doSomething() { QCOMPARE(1, 1); }
};

QTEST_MAIN(TestQt)
#include "tst_qt.moc"
