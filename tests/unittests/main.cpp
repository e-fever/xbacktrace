#include <QString>
#include <QtTest>
#include <QtQuickTest/quicktest.h>
#include <CrossDebug.h>

void crash() {
    int *s = 0;
    *s = 100;
}

int main(int argc, char *argv[])
{
    CrossDebug::installBacktraceHandler();
    CrossDebug::attachConsole();

    QGuiApplication app(argc, argv);
    Q_UNUSED(app);

    crash();

    return 0;
}
