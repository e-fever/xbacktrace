#ifndef CROSSDE_H
#define CROSSDE_H

#include <QtCore>

#if defined(Q_OS_MAC) || defined(Q_OS_LINUX)
#include <execinfo.h>
#include <unistd.h>
#include <signal.h>
#endif

#if defined(Q_OS_WIN)
#include "ExceptionHandler.h"
#endif

namespace CrossDebug {

namespace Private {
#if defined(Q_OS_MAC) || defined(Q_OS_LINUX)
inline void backtraceCallback(int sig) {
    void *array[100];
    size_t size;

    // get void*'s for all entries on the stack
    size = backtrace(array, 100);

    // print out all the frames to stderr
    fprintf(stderr, "Error: signal %d:\n", sig);
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    exit(1);
}
#endif

#if defined(Q_OS_WIN)
LONG backtraceCallback(struct _EXCEPTION_POINTERS *ExInfo)
{
    std::cerr << filterCrash(ExInfo);
    return EXCEPTION_EXECUTE_HANDLER;
}
#endif
}

inline void installBacktraceHandler() {
#if defined(Q_OS_MAC) || defined(Q_OS_LINUX)
    signal(SIGSEGV, Private::backtraceCallback);
#endif

#if defined(Q_OS_WIN)
    SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)Win32FaultHandler);
#endif
}

}

#endif // CROSSDE_H
