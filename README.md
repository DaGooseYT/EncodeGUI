# EncodeGUI
![alt text][egui]

[egui]: https://github.com/DaGooseYT/EncodeGUI/blob/main/gui.png

EncodeGUI (encode-gooey) is a free and open source video transcoder GUI that utilizes AI tools for a fascinating encoding experience. Find out more at it's website, https://encodegui.com

This repository only consists of the source code; no builds are hosted here. See https://encodegui.com/downloads for the latest builds.

# Key Features
Below is a list of key features in EnocdeGUI **that other competing software lacks**:
- Comprehensive video encoding options; includes 6 different video codecs to select from (AVC, HEVC, ProRes, Theora, VP9, AV1) with customizable encoding options.
- Allows batch (folder) inputs to apply the same encoding settings to all videos in a folder.
- Comprehensive video/audio/subtitle info grabber; grabs media info at an instant.
- Advanced job queue with status indicators and an advanced control set.
- Consists of the largest selection of output video containers than any other video encoding GUI application: .mp4, .mkv, .mov, .avi, .asf, .ts, .flv, .3gp, .ogv, .webm
- GPU hardware encoding support for ALL major GPU vendors: QuickSync (Intel), AMF (AMD), and NVENC (Nvidia).
- Multi-GPU processing support for resource demanding filters (Waifu2x and SRMD).
- Built-in and fully customizable audio AND subtitle encoding options.
- Features Intel hardware accelerated AV1 encoding. 
- Features the latest, exclusive AI and non-AI frame interpolation options: RIFE (NCNN/CUDA), EncodeGUI AI (NCNN/CUDA), SVPFlow (OpenGL)
- Full HDR10(+) support with configurations allowing you to convert SDR videos to HDR, and visa versa.
- Dolby Vision support (beta).
- Features VapourSynth filtering for ALL filters which **doesn't extract frames before rendering, allowing a faster render than nearly all competing software**.

# Usage
Documentation including the basic usage guide can be found at https://encodegui.com/docs/documentation.

# Support
Support for issues and directions for how to submit a proper issue/bug report are available on https://encodegui.com/support.

# Compilation
Requires `Qt 6.2.4 SDK` and `MSVC`.
Install the Qt Visual Studio extension and compile using the built in Visual Studio tools.

**Note: The Qt designer UI files for EncodeGUI and the Preview windows are not included in this source code.** However, you can still compile EncodeGUI completely with all of the source code present in this repository.

# Licensing
EncodeGUI's source code is released under the AGPL v3.0 license. See `LICENSE` for more details. Early released versions of EncodeGUI are released under a custom license. Read it at https://encodegui.com/privacy-terms.

**The setup file for EncodeGUI is closed source and is NOT a part of this repository or the AGPL license. Read the privacy and terms at EncodeGUI.com linked above for more details.**
