#include "../../include/processerror.hpp"

bool ProcessError::PipeError;
bool ProcessError::CudaError;
bool ProcessError::NvencError;
bool ProcessError::QuickSyncError;
bool ProcessError::AmfError;
bool ProcessError::GpuThreadError;
bool ProcessError::VkMemoryError;
bool ProcessError::VkQueueError;
bool ProcessError::ProbeError;
bool ProcessError::NcnnError;
bool ProcessError::NvencBitError;
bool ProcessError::PageError;
bool ProcessError::HasError;
int ProcessError::MinThreads;
int ProcessError::MaxThreads;

/// <summary>
/// Raises the FFMpeg pipe error.
/// </summary>
/// <param name="error">True or false.</param>
void ProcessError::SetPipeError(bool pipeError) {
	PipeError = pipeError;
}

/// <summary>
/// Raises the Cuda runtime error.
/// </summary>
/// <param name="cudaError">True or false.</param>
void ProcessError::SetCudaError(bool cudaError) {
	CudaError = cudaError;
}

/// <summary>
/// Raises the Nvenc error.
/// </summary>
/// <param name="nvencError">True or false.</param>
void ProcessError::SetNvencError(bool nvencError) {
	NvencError = nvencError;
}

/// <summary>
/// Raises the QSV error.
/// </summary>
/// <param name="qsvError">True or false.</param>
void ProcessError::SetQuickSyncError(bool qsvError) {
	QuickSyncError = qsvError;
}

/// <summary>
/// Raises the AMF error.
/// </summary>
/// <param name="amfError">True or false.</param>
void ProcessError::SetAmfError(bool amfError) {
	AmfError = amfError;
}

/// <summary>
/// Raises the GPU thread error.
/// </summary>
/// <param name="threadError">True or false.</param>
void ProcessError::SetGpuThreadError(bool threadError) {
	GpuThreadError = threadError;
}

/// <summary>
/// Raises the VkAllocateMemory error.
/// </summary>
/// <param name="vkMemoryError">True or false.</param>
void ProcessError::SetVkMemoryError(bool vkMemoryError) {
	VkMemoryError = vkMemoryError;
}

/// <summary>
/// Raises the VkQueueSubmit error.
/// </summary>
/// <param name="vkQueueError">True or false.</param>
void ProcessError::SetVkQueueError(bool vkQueueError) {
	VkQueueError = vkQueueError;
}

/// <summary>
/// Raises the probe size warning.
/// </summary>
/// <param name="probeError">True or false.</param>
void ProcessError::SetProbeError(bool probeError) {
	ProbeError = probeError;
}

/// <summary>
/// Raises the Nvenc bit error.
/// </summary>
/// <param name="bitError">True or false.</param>
void ProcessError::SetNvencBitError(bool bitError) {
	NvencBitError = bitError;
}

/// <summary>
/// Raises the CUDA page error.
/// </summary>
/// <param name="error">True or false.</param>
void ProcessError::SetPageError(bool error) {
	PageError = error;
}

/// <summary>
/// Raises the NCNN error.
/// </summary>
/// <param name="ncnnError">True or false.</param>
void ProcessError::SetNcnnError(bool ncnnError) {
	NcnnError = ncnnError;
}

/// <summary>
/// Sets the minimum number of threads allowed.
/// </summary>
/// <param name="minThreads">The maximum number of threads.</param>
void ProcessError::SetMinThreads(int minThreads) {
	MinThreads = minThreads;
}

/// <summary>
/// Sets the maximum number of threads allowed.
/// </summary>
/// <param name="maxThreads">The minimum number of threads.</param>
void ProcessError::SetMaxThreads(int maxThreads) {
	MaxThreads = maxThreads;
}

/// <summary>
/// Receives the FFMpeg pipe error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::GetPipeError() {
	return(PipeError);
}

/// <summary>
/// Receives the Cuda runtime error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::GetCudaError() {
	return(CudaError);
}

/// <summary>
/// Receives the NVENC error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::GetNvencError() {
	return(NvencError);
}

/// <summary>
/// Receives the QSV error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::GetQuickSyncError() {
	return(QuickSyncError);
}

/// <summary>
/// Receives the AMF error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::GetAmfError() {
	return(AmfError);
}

/// <summary>
/// Receives the GPU thread error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::GetGpuThreadError() {
	return(GpuThreadError);
}

/// <summary>
/// Gets the CUDA page error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::GetPageError() {
	return(PageError);
}

/// <summary>
/// Receives the VkAllocateMemory error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::GetVkMemoryError() {
	return(VkMemoryError);
}

/// <summary>
/// Receives the VkQueueSubmit error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::GetVkQueueError() {
	return(VkQueueError);
}

/// <summary>
/// Receives the probe size warning.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::GetProbeError() {
	return(ProbeError);
}

/// <summary>
/// Receives the Nvenc bit error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::GetNvencBitError() {
	return(NvencBitError);
}

/// <summary>
/// Receives the NCNN error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::GetNcnnError() {
	return(NcnnError);
}

/// <summary>
/// Receives the minimum number of threads allowed.
/// </summary>
/// <returns>True or false.</returns>
int ProcessError::GetMinThreads() {
	return(MinThreads);
}

/// <summary>
/// Receives the maximum number of threads allowed.
/// </summary>
/// <returns>True or false.</returns>
int ProcessError::GetMaxThreads() {
	return(MaxThreads);
}

/// <summary>
/// Receives the error.
/// </summary>
/// <param name="error">True or false.</param>
void ProcessError::SetError(bool error) {
	HasError = error;
}

/// <summary>
/// Raises the error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::Error() {
	return(HasError);
}

/// <summary>
/// Resets all private variables.
/// </summary>
void ProcessError::ClearAll() {
	PipeError = false;
	CudaError = false;
	NvencError = false;
	QuickSyncError = false;
	AmfError = false;
	GpuThreadError = false;
	VkMemoryError = false;
	VkQueueError = false;
	NvencBitError = false;
	ProbeError = false;
	NcnnError = false;
	HasError = false;
	PageError = false;

	MinThreads = 0;
	MaxThreads = 0;
}