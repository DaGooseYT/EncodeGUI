#include "FFLoader.h"
#ifdef Q_OS_LINUX
#include "Signal.h"
#endif
#ifdef Q_OS_WINDOWS
#include "Windows.h"
#endif

QProcess *video, *encode, *vs, *vk;

void ProcessWorker::NewProcess(QProcess* process, QStringList arguments, QString program) {
	if (!arguments.isEmpty()) {
		process->start(program, arguments);
	}
	else {
		process->start(program);
	}
}

void ProcessWorker::PauseProcess(QProcess* process, bool pause) {
	if (pause) {
#ifdef Q_OS_WINDOWS
		DebugActiveProcess(process->processId());
#endif
#ifdef Q_OS_LINUX
		kill(process->processId(), SIGSTOP);
#endif
	}
	else {
#ifdef Q_OS_WINDOWS
		DebugActiveProcessStop(process->processId());
#endif
#ifdef Q_OS_LINUX
		kill(process->processId(), SIGCONT);
#endif
	}
}

void ProcessWorker::CloseProcess(QProcess* process) {
	process->close();
}

void ProcessWorker::KillProcess(QProcess* process) {
	process->kill();
}

void ProcessWorker::Deconstruct(QProcess* process) {
	process->~QProcess();
}