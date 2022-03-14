#include "FFLoader.h"
#include "Windows.h"

QProcess *video, *encode, *vs;

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
		DebugActiveProcess(process->processId());
	}
	else {
		DebugActiveProcessStop(process->processId());
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