XBacktrace - Cross-platform backtrace utility
=============================================

It is a single header library to provide a cross platform backtrace utility.

Supported Platforms: Linux/Mac/Windows

Credit:

The Windows backtrace code is entirely based on Furkan Üzümcü's [Furkanzmc/ExceptionHandler](https://github.com/Furkanzmc/ExceptionHandler) and [Jerry Coffin's](http://stackoverflow.com/questions/15372962/in-the-handler-of-setunhandledexceptionfilter-how-to-print-a-stacktrace) code. Thanks Furkan and Jerry!


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
