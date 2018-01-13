#include <QString>
#include <QtTest>
#include <QtQuickTest/quicktest.h>
#include <XBacktrace.h>

void crash2() {
    int *s = 0;
    *s = 100;
}

void crash1() {
    crash2();
}

int main(int argc, char *argv[])
{
    qDebug() << "Enable backtrace";

    XBacktrace::enableBacktraceLogOnUnhandledException([]() {
        // Set exit code to zero
        return 0;
    });

    Q_UNUSED(argc);
    Q_UNUSED(argv);

    qDebug() << "Calling crash function";

    crash1();

    return 0;
}
