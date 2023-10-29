/****************************************************************************
 * Copyright (C) 2022 DaGoose
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

#include "ffloader.hpp"

void ProcessWorker::newProcess(QProcess *process, QStringList arguments, QString program) {
	if (!arguments.isEmpty())
		process->start(program, arguments);
	else
		process->start(program);
}

void ProcessWorker::pauseProcess(QProcess *process, bool pause) {
	if (pause) {
		#ifdef Q_OS_WINDOWS
		DebugActiveProcess(process->processId());
		#endif
		#ifdef Q_OS_DARWIN
		kill(process->processId(), SIGSTOP);
		#endif
	}
	else {
		#ifdef Q_OS_WINDOWS
		DebugActiveProcessStop(process->processId());
		#endif
		#ifdef Q_OS_DARWIN
		kill(process->processId(), SIGCONT);
		#endif
	}
}

void ProcessWorker::closeProcess(QProcess *process) {
	process->close();
}

void ProcessWorker::killProcess(QProcess *process) {
	process->kill();
}

void ProcessWorker::deconstruct(QProcess *process) {
	process->~QProcess();
}