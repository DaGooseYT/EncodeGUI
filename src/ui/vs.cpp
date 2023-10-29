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

#include "encodegui.hpp"

void EncodeGUI::hideInterpGpu() {
    if (CHECKED(_ui->UseGPUCB)) {
        SET_ENABLED(_ui->GPUInterpDD);
        SET_ENABLED(_ui->GPUThreadDD);
        SET_ENABLED(_ui->GPUThreadInterpLabel);
    }
    else {
        SET_DISABLED(_ui->GPUInterpDD);
        SET_DISABLED(_ui->GPUThreadDD);
        SET_DISABLED(_ui->GPUThreadInterpLabel);
    }
}

void EncodeGUI::modelVK() {
    if (_ui->RIFEModelVKDD->currentIndex() < 4) {
        SET_VISIBLE(_ui->Times2Label);
        
        #ifdef Q_OS_WINDOWS
        SET_VISIBLE(_ui->EqualsLabel);
        #endif

        SET_DISABLED(_ui->OutputFPSNUD);

        _ui->OutputFPSNUD->setValue(static_cast<double>(VideoInfo::getFrameRate().toDouble()) * 2.0);
    }
    else {
        SET_INVISIBLE(_ui->Times2Label);

        #ifdef Q_OS_WINDOWS
        SET_INVISIBLE(_ui->EqualsLabel);
        #endif

        SET_ENABLED(_ui->OutputFPSNUD);
    }
}

#ifdef Q_OS_WINDOWS
void EncodeGUI::hideInterpGpuCB() {
    switch (_ui->BackendDD->currentIndex()) {
    case 0:
        _ui->UseGPUCB->setChecked(true);
        SET_DISABLED(_ui->UseGPUCB);
        SET_DISABLED(_ui->GPUThreadDD);
        SET_INVISIBLE(_ui->Times2Label);
        SET_INVISIBLE(_ui->EqualsLabel);
        SET_ENABLED(_ui->OutputFPSNUD);

        if (_ui->ToolInterpDD->currentIndex() != 0) {
            SET_VISIBLE(_ui->RIFEModelCADD);
            SET_INVISIBLE(_ui->RIFEModelVKDD);
        }
        else if (_ui->ToolInterpDD->currentIndex() == 0) {
            _ui->ModelInterpDD->removeItem(2);
            _ui->ModelInterpDD->setCurrentIndex(0);
        }

        _ui->BackendDD->removeItem(2);

        break;
    case 1:
        if (_ui->ToolInterpDD->currentIndex() != 0) {
            SET_INVISIBLE(_ui->RIFEModelCADD);
            SET_VISIBLE(_ui->RIFEModelVKDD);
        }
        else
            if (_ui->ModelInterpDD->count() != 3)
                _ui->ModelInterpDD->addItem(QString("Slow"));

        if (_ui->ToolInterpDD->currentIndex() == 1) {
            SET_VISIBLE(_ui->Times2Label);

            _ui->UseGPUCB->setChecked(true);
            SET_DISABLED(_ui->UseGPUCB);

            modelVK();
        }

        SET_ENABLED(_ui->GPUThreadDD);

        _ui->BackendDD->removeItem(2);

        break;
    }
}

void EncodeGUI::toolInterp() {
    switch (_ui->ToolInterpDD->currentIndex()) {
    case 0:
        SET_ENABLED(_ui->BackendDD);
        SET_VISIBLE(_ui->SceneChangeLabel);
        SET_VISIBLE(_ui->SceneChangeCB);
        SET_VISIBLE(_ui->ModelInterpLabel);
        SET_VISIBLE(_ui->SCThresholdLabel);
        SET_VISIBLE(_ui->SCThresholdNUD);
        SET_INVISIBLE(_ui->RIFEModelVKDD);
        SET_VISIBLE(_ui->GPUThreadInterpLabel);
        SET_VISIBLE(_ui->GPUThreadDD);
        SET_ENABLED(_ui->OutputFPSNUD);
        SET_INVISIBLE(_ui->EqualsLabel);
        SET_INVISIBLE(_ui->ParamsCB);
        SET_INVISIBLE(_ui->InterpModeLabel);
        SET_INVISIBLE(_ui->RIFEModelCADD);
        SET_INVISIBLE(_ui->ShaderLabel);
        SET_INVISIBLE(_ui->ShaderDD);
        SET_INVISIBLE(_ui->InterpModeDD);
        SET_INVISIBLE(_ui->ArtefactMaskLabel);
        SET_INVISIBLE(_ui->ArtefactMaskDD);
        SET_VISIBLE(_ui->ModelInterpDD);
        SET_INVISIBLE(_ui->Times2Label);
        SET_ENABLED(_ui->OutputFPSNUD);

        if (!CHECKED(_ui->BatchCB) && !VideoInfo::getFrameRate().contains(QString("?")))
            _ui->OutputFPSNUD->setMinimum(VideoInfo::getFrameRate().toDouble() * static_cast<double>(1.25));

        if (_ui->BackendDD->currentIndex() == 0 || _ui->BackendDD->currentIndex() == 2) {
            _ui->ModelInterpDD->removeItem(2);
            _ui->ModelInterpDD->setCurrentIndex(0);
        }
        else
            if (_ui->ModelInterpDD->count() != 3)
                _ui->ModelInterpDD->addItem(QString("Slow"));

        _ui->BackendDD->removeItem(2);

        hideInterpGpuCB();
        hideParams();
        break;
    case 1:
        SET_ENABLED(_ui->BackendDD);
        SET_VISIBLE(_ui->SceneChangeLabel);
        SET_VISIBLE(_ui->SceneChangeCB);
        SET_VISIBLE(_ui->ModelInterpLabel);
        SET_VISIBLE(_ui->SCThresholdLabel);
        SET_VISIBLE(_ui->SCThresholdNUD);
        SET_VISIBLE(_ui->GPUThreadInterpLabel);
        SET_VISIBLE(_ui->GPUThreadDD);
        SET_INVISIBLE(_ui->ShaderLabel);
        SET_INVISIBLE(_ui->ShaderDD);
        SET_INVISIBLE(_ui->InterpModeLabel);
        SET_INVISIBLE(_ui->InterpModeDD);
        SET_INVISIBLE(_ui->ArtefactMaskLabel);
        SET_INVISIBLE(_ui->ArtefactMaskDD);
        SET_INVISIBLE(_ui->ParamsCB);
        SET_INVISIBLE(_ui->ModelInterpDD);

        if (_ui->BackendDD->currentIndex() == 1)
            modelVK();

        _ui->BackendDD->removeItem(2);

        hideInterpGpuCB();
        hideParams();
        break;
    case 2:
        SET_DISABLED(_ui->BackendDD);
        SET_INVISIBLE(_ui->SceneChangeLabel);
        SET_INVISIBLE(_ui->SceneChangeCB);
        SET_INVISIBLE(_ui->SCThresholdLabel);
        SET_INVISIBLE(_ui->SCThresholdNUD);
        SET_INVISIBLE(_ui->ModelInterpLabel);
        SET_INVISIBLE(_ui->RIFEModelVKDD);
        SET_INVISIBLE(_ui->GPUThreadInterpLabel);
        SET_INVISIBLE(_ui->GPUThreadDD);
        SET_ENABLED(_ui->OutputFPSNUD);
        SET_INVISIBLE(_ui->Times2Label);
        SET_VISIBLE(_ui->ShaderLabel);
        SET_VISIBLE(_ui->ShaderDD);
        SET_VISIBLE(_ui->ParamsCB);
        SET_VISIBLE(_ui->InterpModeLabel);
        SET_VISIBLE(_ui->InterpModeDD);
        SET_INVISIBLE(_ui->EqualsLabel);
        SET_VISIBLE(_ui->ArtefactMaskLabel);
        SET_VISIBLE(_ui->ArtefactMaskDD);
        SET_INVISIBLE(_ui->RIFEModelCADD);
        SET_INVISIBLE(_ui->ModelInterpDD);

        _ui->BackendDD->addItem(QString("OpenCL"));
        _ui->BackendDD->setCurrentIndex(2);

        if (_ui->BackendDD->currentIndex() == 2)
            SET_ENABLED(_ui->UseGPUCB);
        else
            _ui->BackendDD->setCurrentIndex(2);
        if (CHECKED(_ui->ParamsCB))
            hideParams();

        _ui->OutputFPSNUD->setMinimum(5);

        break;
    }
}
#endif

void EncodeGUI::autoAjustU() {
    if (CHECKED(_ui->AutoAdjCB)) {
        SET_ENABLED(_ui->AutoAdjDD);
        autoAdjustUD();
    }
    else {
        SET_ENABLED(_ui->Width2xNUD);
        SET_ENABLED(_ui->Height2xNUD);
        SET_DISABLED(_ui->AutoAdjDD);
    }
}

void EncodeGUI::autoAdjHeight2x() {
    if (CHECKED(_ui->AutoAdjCB) && !_ui->Height2xNUD->isEnabled() && VideoInfo::getHeight() != 0) {
        double multi = static_cast<double>(VideoInfo::getHeight()) / VideoInfo::getWidth();
        _ui->Height2xNUD->setValue((int)(_ui->Width2xNUD->value() * multi));
    }
}

void EncodeGUI::autoAdjWidth2x() {
    if (CHECKED(_ui->AutoAdjCB) && !_ui->Width2xNUD->isEnabled() && VideoInfo::getHeight() != 0) {
        double multi = static_cast<double>(VideoInfo::getWidth()) / VideoInfo::getHeight();
        _ui->Width2xNUD->setValue((int)(_ui->Height2xNUD->value() * multi));
    }
}

#ifdef Q_OS_WINDOWS
void EncodeGUI::hideParams() {
    if (CHECKED(_ui->ParamsCB) && _ui->ToolInterpDD->currentIndex() == 2) {
        SET_DISABLED(_ui->UseGPUCB);
        SET_DISABLED(_ui->UseGPUCB);
        SET_INVISIBLE(_ui->OutputFPSNUD);
        SET_INVISIBLE(_ui->OutFPSLabel);
        SET_VISIBLE(_ui->SmoothLabel);
        SET_VISIBLE(_ui->SmoothTxtBox);
        SET_VISIBLE(_ui->AnalyseLabel);
        SET_VISIBLE(_ui->AnalyseTxtBox);
        SET_VISIBLE(_ui->SuperLabel);
        SET_VISIBLE(_ui->SuperTxtBox);
        SET_INVISIBLE(_ui->InterpModeLabel);
        SET_INVISIBLE(_ui->InterpModeDD);
        SET_INVISIBLE(_ui->ShaderLabel);
        SET_INVISIBLE(_ui->ShaderDD);
        SET_INVISIBLE(_ui->ArtefactMaskLabel);
        SET_INVISIBLE(_ui->ArtefactMaskDD);
    }
    else {
        SET_INVISIBLE(_ui->SmoothLabel);
        SET_INVISIBLE(_ui->SmoothTxtBox);
        SET_INVISIBLE(_ui->AnalyseLabel);
        SET_INVISIBLE(_ui->AnalyseTxtBox);
        SET_INVISIBLE(_ui->SuperLabel);
        SET_INVISIBLE(_ui->SuperTxtBox);

        if (_ui->ToolInterpDD->currentIndex() == 2) {
            SET_VISIBLE(_ui->InterpModeLabel);
            SET_VISIBLE(_ui->InterpModeDD);
            SET_VISIBLE(_ui->ShaderLabel);
            SET_VISIBLE(_ui->ShaderDD);
            SET_VISIBLE(_ui->ArtefactMaskLabel);
            SET_VISIBLE(_ui->ArtefactMaskDD);
            SET_ENABLED(_ui->UseGPUCB);
        }

        SET_VISIBLE(_ui->OutputFPSNUD);
        SET_VISIBLE(_ui->OutFPSLabel);
    }
}
#endif

void EncodeGUI::autoAdjustUD() {
    if (CHECKED(_ui->AutoAdjCB))
        switch (_ui->AutoAdjDD->currentIndex()) {
        case 0:
            SET_DISABLED(_ui->Height2xNUD);
            SET_ENABLED(_ui->Width2xNUD);
            break;
        case 1:
            SET_DISABLED(_ui->Width2xNUD);
            SET_ENABLED(_ui->Height2xNUD);
            break;
        }
}

void EncodeGUI::modelUpScaleGB() {
    if (_ui->ModelUpscaleDD->currentIndex() == 3 && _ui->ToolUpscaleDD->currentIndex() == 0) {
        SET_DISABLED(_ui->Width2xNUD);
        SET_DISABLED(_ui->Height2xNUD);
        SET_DISABLED(_ui->AutoAdjCB);
        SET_DISABLED(_ui->AutoAdjDD);

        if (VideoInfo::getHeight() != 0) {
            _ui->Height2xNUD->setValue(VideoInfo::getHeight());
            _ui->Width2xNUD->setValue(VideoInfo::getWidth());
        }
    }
    else {
        SET_ENABLED(_ui->AutoAdjCB);
        SET_ENABLED(_ui->AutoAdjDD);
        autoAdjustUD();

        if (VideoInfo::getHeight() != 0 && _ui->ToolUpscaleDD->currentIndex() == 0) {
            _ui->Height2xNUD->setValue(VideoInfo::getHeight() * 2);
            _ui->Width2xNUD->setValue(VideoInfo::getWidth() * 2);
        }
    }
}

void EncodeGUI::hideUpscale() {
    modelUpScaleGB();

    switch (_ui->ToolUpscaleDD->currentIndex()) {
    case 0:
        SET_INVISIBLE(_ui->TTA2xCB);
        SET_INVISIBLE(_ui->TTA2xLabel);
        SET_VISIBLE(_ui->NoiseReduc2xLabel);
        SET_VISIBLE(_ui->ModelUpscaleDD);
        SET_VISIBLE(_ui->ModelUpscaleLabel);
        SET_VISIBLE(_ui->Precision2xDD);
        SET_VISIBLE(_ui->Precision2xLabel);
        SET_VISIBLE(_ui->NoiseReduc2xDD);
        break;
    case 1:
        SET_VISIBLE(_ui->TTA2xCB);
        SET_VISIBLE(_ui->TTA2xLabel);
        SET_INVISIBLE(_ui->NoiseReduc2xLabel);
        SET_INVISIBLE(_ui->ModelUpscaleDD);
        SET_INVISIBLE(_ui->ModelUpscaleLabel);
        SET_INVISIBLE(_ui->Precision2xDD);
        SET_INVISIBLE(_ui->Precision2xLabel);
        SET_INVISIBLE(_ui->NoiseReduc2xDD);
        break;
    }
}