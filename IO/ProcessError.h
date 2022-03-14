#pragma once

#ifndef PROCESSERROR_H
#define PROCESSERROR_H

class ProcessError {
public:
	static void SetPipeError(bool);
	static void SetCudaError(bool);
	static void SetNvencError(bool);
	static void SetQuickSyncError(bool);
	static void SetAmfError(bool);
	static void SetGpuThreadError(bool);
	static void SetVkMemoryError(bool);
	static void SetVkQueueError(bool);
	static void SetNcnnError(bool);
	static void SetProbeError(bool);
	static void SetNvencBitError(bool);
	static void SetPageError(bool);
	static void SetMinThreads(int);
	static void SetMaxThreads(int);

	static bool GetPipeError();
	static bool GetCudaError();
	static bool GetNvencError();
	static bool GetQuickSyncError();
	static bool GetAmfError();
	static bool GetGpuThreadError();
	static bool GetVkMemoryError();
	static bool GetVkQueueError();
	static bool GetNcnnError();
	static bool GetProbeError();
	static bool GetNvencBitError();
	static bool GetPageError();
	static int GetMinThreads();
	static int GetMaxThreads();

	static void ClearAll();
	static void SetError(bool);
	static bool Error();
		
private:
	static bool PipeError;
	static bool CudaError;
	static bool NvencError;
	static bool QuickSyncError;
	static bool AmfError;
	static bool GpuThreadError;
	static bool VkMemoryError;
	static bool VkQueueError;
	static bool ProbeError;
	static bool NvencBitError;
	static bool PageError;
	static bool NcnnError;
	static bool HasError;
	static int MinThreads;
	static int MaxThreads;
};

#endif // !PROCESSERROR_H