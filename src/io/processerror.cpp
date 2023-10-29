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

#include "processerror.hpp"

bool ProcessError::_pipeError;
bool ProcessError::_dolbyError;
bool ProcessError::_cudaError;
bool ProcessError::_nvencError;
bool ProcessError::_quickSyncError;
bool ProcessError::_amfError;
bool ProcessError::_gpuThreadError;
bool ProcessError::_vkMemoryError;
bool ProcessError::_vkQueueError;
bool ProcessError::_probeError;
bool ProcessError::_ncnnError;
bool ProcessError::_nvencBitError;
bool ProcessError::_pageError;
bool ProcessError::_hasError;
bool ProcessError::_allocateMem;
bool ProcessError::_gpuInstance;
bool ProcessError::_indexError;
bool ProcessError::_indexDevice;
bool ProcessError::_invalidGpu;
bool ProcessError::_vram;
int ProcessError::_minThreads;
int ProcessError::_maxThreads;

/// <summary>
/// Raises the FFMpeg pipe error.
/// </summary>
/// <param name="error">True or false.</param>
void ProcessError::setPipeError(bool pipeError) {
	_pipeError = pipeError;
}

/// <summary>
/// Raises the dolby support error.
/// </summary>
/// <param name="dolbyError">True or false.</param>
void ProcessError::setDolbyError(bool dolbyError) {
	_dolbyError = dolbyError;
}

/// <summary>
/// Raises the Cuda runtime error.
/// </summary>
/// <param name="cudaError">True or false.</param>
void ProcessError::setCudaError(bool cudaError) {
	_cudaError = cudaError;
}

/// <summary>
/// Raises the Nvenc error.
/// </summary>
/// <param name="nvencError">True or false.</param>
void ProcessError::setNvencError(bool nvencError) {
	_nvencError = nvencError;
}

/// <summary>
/// Raises the QSV error.
/// </summary>
/// <param name="qsvError">True or false.</param>
void ProcessError::setQuickSyncError(bool qsvError) {
	_quickSyncError = qsvError;
}

/// <summary>
/// Raises the AMF error.
/// </summary>
/// <param name="amfError">True or false.</param>
void ProcessError::setAmfError(bool amfError) {
	_amfError = amfError;
}

/// <summary>
/// Raises the GPU thread error.
/// </summary>
/// <param name="threadError">True or false.</param>
void ProcessError::setGpuThreadError(bool threadError) {
	_gpuThreadError = threadError;
}

/// <summary>
/// Raises the VkAllocateMemory error.
/// </summary>
/// <param name="vkMemoryError">True or false.</param>
void ProcessError::setVkMemoryError(bool vkMemoryError) {
	_vkMemoryError = vkMemoryError;
}

/// <summary>
/// Raises the VkQueueSubmit error.
/// </summary>
/// <param name="vkQueueError">True or false.</param>
void ProcessError::setVkQueueError(bool vkQueueError) {
	_vkQueueError = vkQueueError;
}

/// <summary>
/// Raises the probe size warning.
/// </summary>
/// <param name="probeError">True or false.</param>
void ProcessError::setProbeError(bool probeError) {
	_probeError = probeError;
}

/// <summary>
/// Raises the Nvenc bit error.
/// </summary>
/// <param name="bitError">True or false.</param>
void ProcessError::setNvencBitError(bool bitError) {
	_nvencBitError = bitError;
}

/// <summary>
/// Raises the CUDA page error.
/// </summary>
/// <param name="error">True or false.</param>
void ProcessError::setPageError(bool error) {
	_pageError = error;
}

/// <summary>
/// Raises the NCNN error.
/// </summary>
/// <param name="ncnnError">True or false.</param>
void ProcessError::setNcnnError(bool ncnnError) {
	_ncnnError = ncnnError;
}

/// <summary>
/// Sets the minimum number of threads allowed.
/// </summary>
/// <param name="minThreads">The maximum number of threads.</param>
void ProcessError::setMinThreads(int minThreads) {
	_minThreads = minThreads;
}

/// <summary>
/// Sets the maximum number of threads allowed.
/// </summary>
/// <param name="maxThreads">The minimum number of threads.</param>
void ProcessError::setMaxThreads(int maxThreads) {
	_maxThreads = maxThreads;
}

/// <summary>
/// Raises the allocate memory error. 
/// </summary>
/// <param name="allocateMem">True or false.</param>
void ProcessError::setAllocateMemory(int allocateMem) {
	_allocateMem = allocateMem;
}

/// <summary>
/// Raises the GPU instance error.
/// </summary>
/// <param name="gpuInstance">True or false.</param>
void ProcessError::setGpuInstance(int gpuInstance) {
	_gpuInstance = gpuInstance;
}

/// <summary>
/// Raises the lsmas index error.
/// </summary>
/// <param name="indexError">True or false.</param>
void ProcessError::setIndexError(int indexError) {
	_indexError = indexError;
}

/// <summary>
/// Raises the GPU device index error.
/// </summary>
/// <param name="indexDevice">True or false.</param>
void ProcessError::setIndexDeviceError(int indexDevice) {
	_indexDevice = indexDevice;
}

/// <summary>
/// Raises the invalid GPU error.
/// </summary>
/// <param name="invalidGpu">True or false.</param>
void ProcessError::setInvalidGpuError(int invalidGpu) {
	_invalidGpu = invalidGpu;
}

/// <summary>
/// Raises the out of VRAM error.
/// </summary>
/// <param name="vram">True or false.</param>
void ProcessError::setVramError(int vram) {
	_vram = vram;
}

/// <summary>
/// Receives the FFMpeg pipe error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getPipeError() {
	return(_pipeError);
}

/// <summary>
/// Receives the dolby support error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getDolbyError() {
	return(_dolbyError);
}

/// <summary>
/// Receives the Cuda runtime error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getCudaError() {
	return(_cudaError);
}

/// <summary>
/// Receives the NVENC error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getNvencError() {
	return(_nvencError);
}

/// <summary>
/// Receives the QSV error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getQuickSyncError() {
	return(_quickSyncError);
}

/// <summary>
/// Receives the AMF error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getAmfError() {
	return(_amfError);
}

/// <summary>
/// Receives the GPU thread error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getGpuThreadError() {
	return(_gpuThreadError);
}

/// <summary>
/// Gets the CUDA page error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getPageError() {
	return(_pageError);
}

/// <summary>
/// Receives the VkAllocateMemory error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getVkMemoryError() {
	return(_vkMemoryError);
}

/// <summary>
/// Receives the VkQueueSubmit error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getVkQueueError() {
	return(_vkQueueError);
}

/// <summary>
/// Receives the probe size warning.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getProbeError() {
	return(_probeError);
}

/// <summary>
/// Receives the Nvenc bit error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getNvencBitError() {
	return(_nvencBitError);
}

/// <summary>
/// Receives the NCNN error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getNcnnError() {
	return(_ncnnError);
}

/// <summary>
/// Receives the allocate memory error. 
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getAllocateMemory() {
	return(_allocateMem);
}

/// <summary>
/// Receives the GPU instance error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getGpuInstance() {
	return(_gpuInstance);
}

/// <summary>
/// Receives the lsmas index error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getIndexError() {
	return(_indexError);
}

/// <summary>
/// Receives the GPU device index error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getIndexDeviceError() {
	return(_indexDevice);
}

/// <summary>
/// Receives the invalid GPU error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getInvalidGpuError() {
	return(_invalidGpu);
}

/// <summary>
/// Receives the out of VRAM error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::getVramError() {
	return(_vram);
}

/// <summary>
/// Receives the minimum number of threads allowed.
/// </summary>
/// <returns>True or false.</returns>
int ProcessError::getMinThreads() {
	return(_minThreads);
}

/// <summary>
/// Receives the maximum number of threads allowed.
/// </summary>
/// <returns>True or false.</returns>
int ProcessError::getMaxThreads() {
	return(_maxThreads);
}

/// <summary>
/// Receives the error.
/// </summary>
/// <param name="error">True or false.</param>
void ProcessError::setError(bool error) {
	_hasError = error;
}

/// <summary>
/// Raises the error.
/// </summary>
/// <returns>True or false.</returns>
bool ProcessError::error() {
	return(_hasError);
}

/// <summary>
/// Clears RPU process status bool.
/// </summary>
void ProcessError::clearRPU() {
	_dolbyError = false;
}

/// <summary>
/// Resets all private variables.
/// </summary>
void ProcessError::clearAll() {
	_pipeError = false;
	_dolbyError = false;
	_cudaError = false;
	_nvencError = false;
	_quickSyncError = false;
	_amfError = false;
	_gpuThreadError = false;
	_vkMemoryError = false;
	_vkQueueError = false;
	_nvencBitError = false;
	_probeError = false;
	_ncnnError = false;
	_hasError = false;
	_pageError = false;
	_allocateMem = false;
	_gpuInstance = false;
	_indexError = false;
	_indexDevice = false;
	_invalidGpu = false;
	_vram = false;

	_minThreads = 0;
	_maxThreads = 0;
}