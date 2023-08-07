QT += core widgets gui network
TEMPLATE = app
TARGET = EncodeGUI
DESTDIR = ./x64/Release
CONFIG += ./x64/Release
LIBS += -L"."
DEPENDPATH += .
INCLUDEPATH += ./include
MOC_DIR += ./x64/Release
OBJECTS_DIR += ./x64/Release
RC_FILE = ./assets/EncodeGUI.rc
ICON = ./assets/icon.icns
HEADERS += ./include/args.hpp \
    ./include/checks.hpp \
    ./include/audioinfo.hpp \
    ./include/processerror.hpp \
    ./include/progressinfo.hpp \
    ./include/subtitleinfo.hpp \
    ./include/videoinfo.hpp \
    ./include/videoinfolist.hpp \
    ./include/mediaconfig.hpp \
    ./include/scriptbuilder.hpp \
    ./include/audiosubinforegex.hpp \
    ./include/processerrorregex.hpp \
    ./include/progressinforegex.hpp \
    ./include/videoinforegex.hpp \
    ./include/updater.hpp \
    ./include/vapoursynth.hpp \
    ./include/encodegui.hpp \
    ./include/ffloader.hpp \
    ./include/darwin/ui_encodegui.hpp \
    ./include/darwin/ui_updater.hpp \
    ./include/darwin/ui_preview.hpp
SOURCES += ./src/args/audioargs.cpp \
    ./src/args/bitrate.cpp \
    ./src/args/chapters.cpp \
    ./src/args/codec.cpp \
    ./src/args/colorsargs.cpp \
    ./src/args/entropy.cpp \
    ./src/args/frame.cpp \
    ./src/args/hdr.cpp \
    ./src/args/map.cpp \
    ./src/args/misc.cpp \
    ./src/args/pass.cpp \
    ./src/args/preset.cpp \
    ./src/args/profile.cpp \
    ./src/args/ratecontrol.cpp \
    ./src/args/resolution.cpp \
    ./src/args/sharpen.cpp \
    ./src/args/subtitleargs.cpp \
    ./src/args/tier.cpp \
    ./src/args/timecode.cpp \
    ./src/args/transpose.cpp \
    ./src/args/tune.cpp \
    ./src/args/vspipe.cpp \
    ./src/checks/files.cpp \
    ./src/checks/process.cpp \
    ./src/io/audioinfo.cpp \
    ./src/io/processError.cpp \
    ./src/io/progressinfo.cpp \
    ./src/io/subtitleinfo.cpp \
    ./src/io/videoinfo.cpp \
    ./src/io/videoinfolist.cpp \
    ./src/process/ffloader.cpp \
    ./src/process/mediaconfig.cpp \
    ./src/process/processworker.cpp \
    ./src/process/scriptbuilder.cpp \
    ./src/regex/audiosubinforegex.cpp \
    ./src/regex/processerrorregex.cpp \
    ./src/regex/progressinforegex.cpp \
    ./src/regex/videoinforegex.cpp \
    ./src/ui/audio.cpp \
    ./src/ui/av1.cpp \
    ./src/ui/avc.cpp \
    ./src/ui/config.cpp \
    ./src/ui/enviornment.cpp \
    ./src/ui/encodegui.cpp \
    ./src/ui/hevc.cpp \
    ./src/ui/jobs.cpp \
    ./src/ui/msgbox.cpp \
    ./src/ui/preview.cpp \
    ./src/ui/script.cpp \
    ./src/ui/settings.cpp \
    ./src/ui/subtitles.cpp \
    ./src/ui/theora.cpp \
    ./src/ui/updater.cpp \
    ./src/ui/vpx.cpp \
    ./src/ui/vs.cpp \
    ./src/vs/colors.cpp \
    ./src/vs/rife.cpp \
    ./src/vs/srmd.cpp \
    ./src/vs/waifu2x.cpp \
    ./src/vs/svpflow.cpp \
    ./src/vs/vapoursynth.cpp \
    ./src/main.cpp
RESOURCES += ./assets/EncodeGUI.qrc