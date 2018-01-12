#include <QString>
#include <QtTest>
#include <QtQuickTest/quicktest.h>
#include <CrossDebug.h>

int main(int argc, char *argv[])
{
    CrossDebug::installBacktraceHandler();

    QGuiApplication app(argc, argv);
    Q_UNUSED(app);

    int *s = 0;
    *s = 100;

    return 0;
}
