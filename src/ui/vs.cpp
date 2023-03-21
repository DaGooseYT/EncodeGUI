#include "../../include/encodegui.hpp"

void EncodeGUI::hide_interpgpu() {
    if (CHECKED(ui.UseGPUCB)) {
        SET_ENABLED(ui.GPUInterpDD);
        SET_ENABLED(ui.GPUThreadDD);
        SET_ENABLED(ui.GPUThreadInterpLabel);
    }
    else {
        SET_DISABLED(ui.GPUInterpDD);
        SET_DISABLED(ui.GPUThreadDD);
        SET_DISABLED(ui.GPUThreadInterpLabel);
    }
}

void EncodeGUI::ModelVK() {
    if (ui.RIFEModelVKDD->currentIndex() < 4) {
        SET_VISIBLE(ui.Times2Label);
        SET_VISIBLE(ui.EqualsLabel);
        SET_DISABLED(ui.OutputFPSNUD);

        ui.OutputFPSNUD->setValue(static_cast<double>(VideoInfo::GetFrameRate().toDouble()) * 2.0);
    }
    else {
        SET_INVISIBLE(ui.Times2Label);
        SET_INVISIBLE(ui.EqualsLabel);
        SET_ENABLED(ui.OutputFPSNUD);
    }
}

void EncodeGUI::hide_interpgpucb() {
    switch (ui.BackendDD->currentIndex()) {
    case 0:
        ui.UseGPUCB->setChecked(true);
        SET_DISABLED(ui.UseGPUCB);
        SET_DISABLED(ui.GPUThreadDD);
        SET_INVISIBLE(ui.Times2Label);
        SET_INVISIBLE(ui.EqualsLabel);
        SET_ENABLED(ui.OutputFPSNUD);

        if (ui.ToolInterpDD->currentIndex() != 0) {
            SET_VISIBLE(ui.RIFEModelCADD);
            SET_INVISIBLE(ui.RIFEModelVKDD);
        }
        else if (ui.ToolInterpDD->currentIndex() == 0) {
            ui.ModelInterpDD->removeItem(2);
            ui.ModelInterpDD->setCurrentIndex(0);
        }

        ui.BackendDD->removeItem(2);

        break;
    case 1:
        if (ui.ToolInterpDD->currentIndex() != 0) {
            SET_INVISIBLE(ui.RIFEModelCADD);
            SET_VISIBLE(ui.RIFEModelVKDD);
        }
        else
            if (ui.ModelInterpDD->count() != 3)
                ui.ModelInterpDD->addItem("Slow");

        if (ui.ToolInterpDD->currentIndex() == 1) {
            SET_VISIBLE(ui.Times2Label);

            ui.UseGPUCB->setChecked(true);
            SET_DISABLED(ui.UseGPUCB);

            ModelVK();
        }

        SET_ENABLED(ui.GPUThreadDD);
        ui.BackendDD->removeItem(2);

        break;
    }
}

void EncodeGUI::tool_interp() {
    switch (ui.ToolInterpDD->currentIndex()) {
    case 0:
        SET_ENABLED(ui.BackendDD);
        SET_INVISIBLE(ui.ShaderLabel);
        SET_INVISIBLE(ui.ShaderDD);
        SET_INVISIBLE(ui.InterpModeDD);
        SET_INVISIBLE(ui.ArtefactMaskLabel);
        SET_INVISIBLE(ui.ArtefactMaskDD);
        SET_VISIBLE(ui.SceneChangeLabel);
        SET_VISIBLE(ui.SceneChangeCB);
        SET_VISIBLE(ui.ModelInterpLabel);
        SET_VISIBLE(ui.ModelInterpDD);
        SET_INVISIBLE(ui.RIFEModelCADD);
        SET_VISIBLE(ui.SCThresholdLabel);
        SET_VISIBLE(ui.SCThresholdNUD);
        SET_INVISIBLE(ui.InterpModeLabel);
        SET_INVISIBLE(ui.RIFEModelVKDD);
        SET_VISIBLE(ui.GPUThreadInterpLabel);
        SET_VISIBLE(ui.GPUThreadDD);
        SET_INVISIBLE(ui.ParamsCB);
        SET_ENABLED(ui.OutputFPSNUD);
        SET_INVISIBLE(ui.EqualsLabel);
        SET_INVISIBLE(ui.Times2Label);
        SET_INVISIBLE(ui.EqualsLabel);
        SET_ENABLED(ui.OutputFPSNUD);

        if (!VideoInfo::GetFrameRate().contains("?"))
            ui.OutputFPSNUD->setMinimum(VideoInfo::GetFrameRate().toDouble() * static_cast<double>(1.25));

        if (ui.BackendDD->currentIndex() == 0 || ui.BackendDD->currentIndex() == 2) {
            ui.ModelInterpDD->removeItem(2);
            ui.ModelInterpDD->setCurrentIndex(0);
        }
        else
            if (ui.ModelInterpDD->count() != 3)
                ui.ModelInterpDD->addItem("Slow");

        ui.BackendDD->removeItem(2);

        hide_interpgpucb();
        hide_params();
        break;
    case 1:
        SET_ENABLED(ui.BackendDD);
        SET_INVISIBLE(ui.ShaderLabel);
        SET_INVISIBLE(ui.ShaderDD);
        SET_INVISIBLE(ui.InterpModeLabel);
        SET_INVISIBLE(ui.InterpModeDD);
        SET_INVISIBLE(ui.ArtefactMaskLabel);
        SET_INVISIBLE(ui.ArtefactMaskDD);
        SET_VISIBLE(ui.SceneChangeLabel);
        SET_VISIBLE(ui.SceneChangeCB);
        SET_VISIBLE(ui.ModelInterpLabel);
        SET_VISIBLE(ui.SCThresholdLabel);
        SET_VISIBLE(ui.SCThresholdNUD);
        SET_INVISIBLE(ui.ModelInterpDD);
        SET_VISIBLE(ui.GPUThreadInterpLabel);
        SET_VISIBLE(ui.GPUThreadDD);
        SET_INVISIBLE(ui.ParamsCB);

        if (ui.BackendDD->currentIndex() == 1)
            ModelVK();

        ui.BackendDD->removeItem(2);

        hide_interpgpucb();
        hide_params();
        break;
    case 2:
        SET_DISABLED(ui.BackendDD);
        SET_VISIBLE(ui.ShaderLabel);
        SET_VISIBLE(ui.ShaderDD);
        SET_VISIBLE(ui.InterpModeLabel);
        SET_VISIBLE(ui.InterpModeDD);
        SET_VISIBLE(ui.ArtefactMaskLabel);
        SET_VISIBLE(ui.ArtefactMaskDD);
        SET_INVISIBLE(ui.SceneChangeLabel);
        SET_INVISIBLE(ui.SceneChangeCB);
        SET_INVISIBLE(ui.SCThresholdLabel);
        SET_INVISIBLE(ui.SCThresholdNUD);
        SET_INVISIBLE(ui.ModelInterpLabel);
        SET_INVISIBLE(ui.ModelInterpDD);
        SET_INVISIBLE(ui.RIFEModelCADD);
        SET_INVISIBLE(ui.RIFEModelVKDD);
        SET_INVISIBLE(ui.GPUThreadInterpLabel);
        SET_INVISIBLE(ui.GPUThreadDD);
        SET_VISIBLE(ui.ParamsCB);
        SET_ENABLED(ui.OutputFPSNUD);
        SET_INVISIBLE(ui.EqualsLabel);
        SET_INVISIBLE(ui.Times2Label);

        ui.BackendDD->addItem("OpenCL");
        ui.BackendDD->setCurrentIndex(2);

        if (ui.BackendDD->currentIndex() == 2)
            SET_ENABLED(ui.UseGPUCB);
        else
            ui.BackendDD->setCurrentIndex(2);
        if (CHECKED(ui.ParamsCB))
            hide_params();

        ui.OutputFPSNUD->setMinimum(5);

        break;
    }
}

void EncodeGUI::AutoAjustU() {
    if (CHECKED(ui.AutoAdjCB)) {
        SET_ENABLED(ui.AutoAdjDD);
        AutoAdjustUD();
    }
    else {
        SET_ENABLED(ui.Width2xNUD);
        SET_ENABLED(ui.Height2xNUD);
        SET_DISABLED(ui.AutoAdjDD);
    }
}

void EncodeGUI::AutoAdjHeight2x() {
    if (CHECKED(ui.AutoAdjCB) && !ui.Height2xNUD->isEnabled() && VideoInfo::GetHeight() != 0) {
        double multi = static_cast<double>(VideoInfo::GetHeight()) / VideoInfo::GetWidth();
        ui.Height2xNUD->setValue((int)(ui.Width2xNUD->value() * multi));
    }
}

void EncodeGUI::AutoAdjWidth2x() {
    if (CHECKED(ui.AutoAdjCB) && !ui.Width2xNUD->isEnabled() && VideoInfo::GetHeight() != 0) {
        double multi = static_cast<double>(VideoInfo::GetWidth()) / VideoInfo::GetHeight();
        ui.Width2xNUD->setValue((int)(ui.Height2xNUD->value() * multi));
    }
}

void EncodeGUI::hide_params() {
    if (CHECKED(ui.ParamsCB) && ui.ToolInterpDD->currentIndex() == 2) {
        SET_DISABLED(ui.UseGPUCB);
        SET_VISIBLE(ui.SmoothLabel);
        SET_VISIBLE(ui.SmoothTxtBox);
        SET_VISIBLE(ui.AnalyseLabel);
        SET_VISIBLE(ui.AnalyseTxtBox);
        SET_VISIBLE(ui.SuperLabel);
        SET_VISIBLE(ui.SuperTxtBox);
        SET_INVISIBLE(ui.InterpModeLabel);
        SET_INVISIBLE(ui.InterpModeDD);
        SET_INVISIBLE(ui.ShaderLabel);
        SET_INVISIBLE(ui.ShaderDD);
        SET_INVISIBLE(ui.ArtefactMaskLabel);
        SET_INVISIBLE(ui.ArtefactMaskDD);
        SET_DISABLED(ui.UseGPUCB);
        SET_INVISIBLE(ui.OutputFPSNUD);
        SET_INVISIBLE(ui.OutFPSLabel);
    }
    else {
        SET_INVISIBLE(ui.SmoothLabel);
        SET_INVISIBLE(ui.SmoothTxtBox);
        SET_INVISIBLE(ui.AnalyseLabel);
        SET_INVISIBLE(ui.AnalyseTxtBox);
        SET_INVISIBLE(ui.SuperLabel);
        SET_INVISIBLE(ui.SuperTxtBox);

        if (ui.ToolInterpDD->currentIndex() == 2) {
            SET_VISIBLE(ui.InterpModeLabel);
            SET_VISIBLE(ui.InterpModeDD);
            SET_VISIBLE(ui.ShaderLabel);
            SET_VISIBLE(ui.ShaderDD);
            SET_VISIBLE(ui.ArtefactMaskLabel);
            SET_VISIBLE(ui.ArtefactMaskDD);
            SET_ENABLED(ui.UseGPUCB);
        }

        SET_VISIBLE(ui.OutputFPSNUD);
        SET_VISIBLE(ui.OutFPSLabel);
    }
}

void EncodeGUI::AutoAdjustUD() {
    if (CHECKED(ui.AutoAdjCB))
        switch (ui.AutoAdjDD->currentIndex()) {
        case 0:
            SET_DISABLED(ui.Height2xNUD);
            SET_ENABLED(ui.Width2xNUD);
            break;
        case 1:
            SET_DISABLED(ui.Width2xNUD);
            SET_ENABLED(ui.Height2xNUD);
            break;
        }
}

void EncodeGUI::ModelUpScaleGB() {
    if (ui.ModelUpscaleDD->currentIndex() == 3 && ui.ToolUpscaleDD->currentIndex() == 0) {
        SET_DISABLED(ui.Width2xNUD);
        SET_DISABLED(ui.Height2xNUD);
        SET_DISABLED(ui.AutoAdjCB);
        SET_DISABLED(ui.AutoAdjDD);

        if (VideoInfo::GetHeight() != 0) {
            ui.Height2xNUD->setValue(VideoInfo::GetHeight());
            ui.Width2xNUD->setValue(VideoInfo::GetWidth());
        }
    }
    else {
        SET_ENABLED(ui.AutoAdjCB);
        SET_ENABLED(ui.AutoAdjDD);
        AutoAdjustUD();

        if (VideoInfo::GetHeight() != 0 && ui.ToolUpscaleDD->currentIndex() == 0) {
            ui.Height2xNUD->setValue(VideoInfo::GetHeight() * 2);
            ui.Width2xNUD->setValue(VideoInfo::GetWidth() * 2);
        }
    }
}

void EncodeGUI::hide_upscale() {
    ModelUpScaleGB();

    switch (ui.ToolUpscaleDD->currentIndex()) {
    case 0:
        SET_INVISIBLE(ui.TTA2xCB);
        SET_INVISIBLE(ui.TTA2xLabel);
        SET_ENABLED(ui.ModelUpscaleDD);
        SET_ENABLED(ui.ModelUpscaleLabel);
        SET_INVISIBLE(ui.NoiseLabelSDDD);
        SET_VISIBLE(ui.Precision2xDD);
        SET_VISIBLE(ui.Precision2xLabel);
        SET_VISIBLE(ui.NoiseReduc2xDD);
        break;
    case 1:
        SET_VISIBLE(ui.TTA2xCB);
        SET_VISIBLE(ui.TTA2xLabel);
        SET_DISABLED(ui.ModelUpscaleDD);
        SET_DISABLED(ui.ModelUpscaleLabel);
        SET_VISIBLE(ui.NoiseLabelSDDD);
        SET_INVISIBLE(ui.Precision2xDD);
        SET_INVISIBLE(ui.Precision2xLabel);
        SET_INVISIBLE(ui.NoiseReduc2xDD);
        break;
    }
}