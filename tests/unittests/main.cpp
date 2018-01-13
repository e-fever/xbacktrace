#include <QString>
#include <QtTest>
#include <QtQuickTest/quicktest.h>
#include <CrossDebug.h>

void crash2() {
    int *s = 0;
    *s = 100;
}

void crash1() {
    crash2();
}

int main(int argc, char *argv[])
{
    CrossDebug::enableBacktraceLogOnUnhandledException([]() {
        // Set exit code to zero
        return 0;
    });

    QGuiApplication app(argc, argv);
    Q_UNUSED(app);

    crash1();

    return 0;
}
