XBacktrace - Cross-platform backtrace utility
=============================================

Supported Platforms: Linux/Mac/Windows


Example usage
-----------

```
#include <xbacktrace.h>

int main(int argc, char *argv[])
{
    XBacktrace::enableBacktraceLogOnUnhandledException();
    int *s = 0;
    s = 10;
    return 0;
}

```

API
---

*XBacktrace::enableBacktraceLogOnUnhandledException()*

*XBacktrace::enableBacktraceLogOnUnhandledException(callback)*

TBD

*XBacktrace::attachConsole()*

Windows-Only API
