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

#pragma once

#ifndef PROCESSERROR_H
#define PROCESSERROR_H

class ProcessError {
public:
	static void setPipeError(bool pipeError);
	static void setDolbyError(bool dolbyError);
	static void setCudaError(bool cudaError);
	static void setNvencError(bool nvencError);
	static void setQuickSyncError(bool qsvError);
	static void setAmfError(bool amfError);
	static void setGpuThreadError(bool threadError);
	static void setVkMemoryError(bool vkMemoryError);
	static void setVkQueueError(bool vkQueueError);
	static void setNcnnError(bool ncnnError);
	static void setProbeError(bool probeError);
	static void setNvencBitError(bool bitError);
	static void setPageError(bool error);
	static void setMinThreads(int minThreads);
	static void setMaxThreads(int maxThreads);
	static void setAllocateMemory(int allocMem);
	static void setGpuInstance(int gpuInstance);
	static void setIndexError(int indexError);
	static void setIndexDeviceError(int indexDevice);
	static void setInvalidGpuError(int invalidGpu);
	static void setVramError(int vram);

	static bool getPipeError();
	static bool getDolbyError();
	static bool getCudaError();
	static bool getNvencError();
	static bool getQuickSyncError();
	static bool getAmfError();
	static bool getGpuThreadError();
	static bool getVkMemoryError();
	static bool getVkQueueError();
	static bool getNcnnError();
	static bool getProbeError();
	static bool getNvencBitError();
	static bool getPageError();
	static int getMinThreads();
	static int getMaxThreads();
	static bool getAllocateMemory();
	static bool getGpuInstance();
	static bool getIndexError();
	static bool getIndexDeviceError();
	static bool getInvalidGpuError();
	static bool getVramError();

	static void clearAll();
	static void clearRPU();
	static void setError(bool error);
	static bool error();
		
private:
	static bool _pipeError;
	static bool _dolbyError;
	static bool _cudaError;
	static bool _nvencError;
	static bool _quickSyncError;
	static bool _amfError;
	static bool _gpuThreadError;
	static bool _vkMemoryError;
	static bool _vkQueueError;
	static bool _probeError;
	static bool _nvencBitError;
	static bool _pageError;
	static bool _ncnnError;
	static bool _hasError;
	static bool _allocateMem;
	static bool _gpuInstance;
	static bool _indexError;
	static bool _indexDevice;
	static bool _invalidGpu;
	static bool _vram;
	static int _minThreads;
	static int _maxThreads;
};

#endif // !PROCESSERROR_H