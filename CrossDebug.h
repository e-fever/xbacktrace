#ifndef CROSSDE_H
#define CROSSDE_H

#include <QtCore>
#include <functional>

#if defined(Q_OS_MAC) || defined(Q_OS_LINUX)
#include <execinfo.h>
#include <unistd.h>
#include <signal.h>
#endif

#if defined(Q_OS_WIN)
#include "ExceptionHandler.h"
#include <windows.h>
#endif

namespace CrossDebug {

namespace Private {

#if defined(Q_OS_WIN)
inline LONG backtraceCallback(struct _EXCEPTION_POINTERS *ExInfo)
{
    std::cerr << filterCrash(ExInfo);
}
#endif
}

inline void enableBacktraceLogOnUnhandledException(std::function<int()> callback) {

#if defined(Q_OS_MAC) || defined(Q_OS_LINUX)
    static std::function<int()> s_callback = callback;

    class Backtrace {
    public:

        static void handler(int sig) {
            void *array[100];
            size_t size;

            // get void*'s for all entries on the stack
            size = backtrace(array, 100);

            // print out all the frames to stderr
            fprintf(stderr, "Error: signal %d:\n", sig);
            backtrace_symbols_fd(array, size, STDERR_FILENO);
            exit(s_callback());
        }
    };

    signal(SIGSEGV, Backtrace::handler);
#endif

#if defined(Q_OS_WIN)
    static std::function<int()> s_callback = callback;

    class Backtrace {
    public:

        static LONG handler(struct _EXCEPTION_POINTERS *ExInfo)
        {
            std::cerr << filterCrash(ExInfo);
            exit(s_callback());
        }
    };

    SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)Backtrace::handler);
#endif
}

inline void enableBacktraceLogOnUnhandledException() {
#if defined(Q_OS_MAC) || defined(Q_OS_LINUX)
    enableBacktraceLogOnUnhandledException([]() {return -1;});
#endif

#if defined(Q_OS_WIN)
    enableBacktraceLogOnUnhandledException([]() {return EXCEPTION_EXECUTE_HANDLER;});
#endif
}

inline void attachConsole() {
    // Reference: https://forum.qt.io/topic/56484/solved-attach-console-to-gui-application-on-windows/4

#if defined(Q_OS_WIN)
    FreeConsole();

    // create a separate new console window
    AllocConsole();

    // attach the new console to this application's process
    AttachConsole(GetCurrentProcessId());

    // reopen the std I/O streams to redirect I/O to the new console
    freopen("CON", "w", stdout);
    freopen("CON", "w", stderr);
    freopen("CON", "r", stdin);
#endif
}

}

#endif // CROSSDE_H
