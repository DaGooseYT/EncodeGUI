# EncodeGUI
![alt text][egui]

[egui]: https://github.com/DaGooseYT/EncodeGUI/blob/main/Assets/gui.png

EncodeGUI (encode-gooey) is a free and open source video transcoder GUI that utilizes AI tools for a fascinating encoding experience. Find out more at it's website, https://encodegui.com

This repository only consists of the source code; no builds are hosted here. See https://encodegui.com/downloads.html for the latest builds.

# Key Features
Below is a list of key features in EnocdeGUI **where other competing software lacks**:
- Comprehensive video encoder options; includes 6 different video codecs to select from (AVC, HEVC, ProRes, Theora, VP9, AV1) with customizable encoding options.
- Comprehensive video/audio info grabber; grabs media info at an instant.
- Advanced job queue with status indicators and an advanced control set.
- Consists of the largest selection of output video containers than any other video encoding GUI application: .mp4, .mkv, .mov, .avi, .asf, .ts, .flv, .3gp, .ogv, .webm
- GPU hardware encoding support for ALL major GPU vendors: QuickSync (Intel), AMF (AMD), and NVENC (Nvidia).
- Multi-GPU processing support for resource demanding filters (Waifu2x and SRMD).
- Built-in and fully customizable audio encoding options.
- Features the latest, exclusive AI and non-AI frame interpolation options: RIFE (NCNN/CUDA), EncodeGUI AI (NCNN/CUDA), SVPFlow (OpenGL)
- Full HDR10(+) support with configurations allowing you to convert SDR videos to HDR, and visa versa.
- Features VapourSynth filtering which **doesn't extract frames before frame rendering**, allowing a faster render than nearly all competing software. The only frame extraction that occurs is for the live encoding progress preview, which is very fast and uses very little resources.

# Usage
Documentation including the basic usage guide can be found at https://encodegui.com/docs/documentation.html.

# Support
Support for issues and directions for how to submit a proper issue/bug report are available on https://encodegui.com/support.html

# Compilation
Requires `Qt 6 SDK` and MS `Visual Studio` or `Cmake`.
Install the Qt Visual Studio extension and compile using the built in Visual Studio tools.

**Note: The Qt designer UI files for EncodeGUI and the Preview windows are not included in this source code.**

# Licensing
EncodeGUI's source code is licensed under the AGPL v3.0. See `LICENSE` for more details. Early released versions of EncodeGUI are licensed under a custom license. Read it at https://encodegui.com/privacy-terms.html.

**The setup file for EncodeGUI is closed source and is NOT a part of this repository or the AGPL license. Read the privacy and terms at EncodeGUI.com linked above for more details.**
