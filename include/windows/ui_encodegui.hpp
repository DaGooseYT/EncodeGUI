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

#ifndef ENCODEGUIJDHGID_H
#define ENCODEGUIJDHGID_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EncodeGUIMV
{
public:
    QWidget* centralWidget;
    QTabWidget* Tabs;
    QWidget* HomeTab;
    QLabel* EGUILogo;
    QGroupBox* InputGB;
    QCheckBox* GetVidInfoCB;
    QCheckBox* SampleVidCB;
    QCheckBox* BatchCB;
    QGroupBox* EGUIGB;
    QComboBox* VideoEncDD;
    QLabel* VidEncLabel;
    QCheckBox* AudioCB;
    QComboBox* AudioDD;
    QCheckBox* SubtitlesCB;
    QComboBox* SubtitlesDD;
    QCheckBox* ChaptersCB;
    QLabel* ChaptersLabel;
    QGroupBox* CurrenProcGB;
    QLabel* WhenEncCompleteLabel;
    QComboBox* WhenEncCompleteDD;
    QPushButton* PauseBttn;
    QPushButton* CancelBttn;
    QLabel* JobIDLabel;
    QLabel* JobStatusLabel;
    QLabel* JobStartLabel;
    QLabel* JobIDValueLabel;
    QLabel* JobStatusValueLabel;
    QLabel* JobStartValueLabel;
    QLineEdit* SelectInTxtBox;
    QPushButton* SelectInBttn;
    QWidget* VideoTab;
    QTabWidget* VideoTabs;
    QWidget* x264Tab;
    QTabWidget* x264Tabs;
    QWidget* Main264Tab;
    QGroupBox* EncodingSetting264GB;
    QLabel* EncodeMode264Label;
    QComboBox* EncodeMode264DD;
    QCheckBox* Hardware264CB;
    QComboBox* Hardware264DD;
    QDoubleSpinBox* Bitrate264NUD;
    QCheckBox* Tune264CB;
    QComboBox* Tune264DD;
    QCheckBox* Preset264CB;
    QComboBox* Preset264DD;
    QLabel* Quantizer264Label;
    QSpinBox* Quantizer264NUD;
    QSpinBox* CRFValue264NUD;
    QLabel* CRFValueLabel;
    QComboBox* EncodeMode264HWDD;
    QLabel* Bitrate264Label;
    QGroupBox* Profile264GB;
    QLabel* Profile264Label;
    QComboBox* Profile264DD;
    QLabel* Level264Label;
    QComboBox* Level264DD;
    QLabel* EntropyCode264Label;
    QComboBox* EntropyCode264DD;
    QGroupBox* Colors264GB;
    QLabel* BitDepth264Label;
    QComboBox* BitDepth264DD;
    QLabel* Space264Label;
    QComboBox* ColorSpace264DD;
    QWidget* Fames264Tab;
    QGroupBox* RefFrames264GB;
    QSlider* Reference264Sldr;
    QLCDNumber* Reference264LED;
    QGroupBox* BFrames264GB;
    QSlider* BFrame264Sldr;
    QLCDNumber* Bframe264LED;
    QWidget* x265Tab;
    QTabWidget* x265Tabs;
    QWidget* Main265Tab;
    QGroupBox* Colors265GB;
    QLabel* BitDepth265Label;
    QComboBox* BitDepth265DD;
    QLabel* Sample265Label;
    QComboBox* ColorSpace265DD;
    QGroupBox* Profile265GB;
    QLabel* Profile265Label;
    QComboBox* Profile265DD;
    QLabel* Level265Label;
    QComboBox* Level265DD;
    QLabel* Tier265Label;
    QComboBox* Tier265DD;
    QGroupBox* EncodingSetting265GB;
    QLabel* EncodeMode265Label;
    QComboBox* EncodeMode265DD;
    QCheckBox* Hardware265CB;
    QComboBox* Hardware265DD;
    QDoubleSpinBox* Bitrate265NUD;
    QCheckBox* Tune265CB;
    QComboBox* Tune265DD;
    QCheckBox* Preset265CB;
    QComboBox* Preset265DD;
    QLabel* Quantizer265Label;
    QSpinBox* Quantizer265NUD;
    QSpinBox* CRFValue265NUD;
    QLabel* CRFValue265Label;
    QComboBox* EncodeMode265HWDD;
    QLabel* Bitrate265Label;
    QLabel* FastPass265Label;
    QCheckBox* FastPass265CB;
    QWidget* Fames265Tab;
    QGroupBox* RefFrames265GB;
    QSlider* Reference265Sldr;
    QLCDNumber* Reference265LED;
    QGroupBox* BFrames265GB;
    QSlider* BFrame265Sldr;
    QLCDNumber* Bframe265LED;
    QWidget* ProResTab;
    QGroupBox* EncodingProResGB;
    QLabel* ProfileLabel;
    QComboBox* ProfileDD;
    QGroupBox* ColorsGB;
    QLabel* MatrixProResLabel;
    QComboBox* MatrixProResDD;
    QLabel* TransferProResLabel;
    QComboBox* TransferProResDD;
    QLabel* PrimariesProResLabel;
    QComboBox* PrimairesProResDD;
    QWidget* TheoraTab;
    QGroupBox* EncodeTheoraGB;
    QLabel* QualityLabel;
    QSpinBox* QualityNUD;
    QLabel* EncodeModeTLabel;
    QComboBox* EncodeModeTDD;
    QLabel* BitrateThLabel;
    QSpinBox* BitrateThNUD;
    QWidget* VPXTab;
    QGroupBox* EncodingSettingVPXGB;
    QLabel* EncodeModeVPXLabel;
    QComboBox* EncodeModeVPXDD;
    QDoubleSpinBox* BitrateVPXNUD;
    QSpinBox* crfVPXNUD;
    QLabel* crfVPXLabel;
    QLabel* BitrateVPXLabel;
    QGroupBox* ProfileVPXGB;
    QLabel* Profile264Label_2;
    QComboBox* ProfileVPXDD;
    QLabel* SpeedLabel;
    QComboBox* SpeedDD;
    QGroupBox* ColorsVPXGB;
    QLabel* BitDepthVPXLabel;
    QComboBox* BitDepthVPXDD;
    QLabel* SampleVPXLabel;
    QComboBox* SampleVPXDD;
    QWidget* av1Tab;
    QGroupBox* EncodingSettingAV1GB;
    QLabel* EncodeModeAV1Label;
    QComboBox* EncodeModeAV1DD;
    QDoubleSpinBox* BitrateAV1NUD;
    QSpinBox* crfAV1NUD;
    QLabel* crfAV1Label;
    QLabel* BitrateAV1Label;
    QGroupBox* ColorsAV1GB;
    QLabel* BitDepthAV1Label;
    QComboBox* BitDepthAV1DD;
    QWidget* HDRTab;
    QTabWidget* SignalsTabs;
    QWidget* HDRTab1;
    QGroupBox* HDRMetadataGB;
    QLabel* LightLevelLabel;
    QLabel* Slash6Label;
    QSpinBox* MaxCllNUD;
    QSpinBox* MaxFallNUD;
    QLabel* MasterDisplayLabel;
    QLineEdit* MasterDisplayTxtBox;
    QLabel* DynamicMetadataLabel;
    QPushButton* DynamicMetadataBttn;
    QLineEdit* DynamicHDRTxtBox;
    QGroupBox* DBVisionGB;
    QLabel* DBProfileLabel;
    QLabel* RpuLabel;
    QComboBox* DBProfileDD;
    QLineEdit* RpuTxtBox;
    QPushButton* RpuFileBttn;
    QWidget* Colors3Tab;
    QGroupBox* ColorsHDRGB;
    QLabel* ColorRangeLabel;
    QLabel* ColorMatrixLabel;
    QComboBox* ColorTransferDD;
    QLabel* ColorPrimariesLabel;
    QLabel* ColorTransferLabel;
    QComboBox* ColorRangeDD;
    QComboBox* ColorMatrixDD;
    QComboBox* ColorPrimariesDD;
    QWidget* VSTab;
    QTabWidget* VSTabs;
    QWidget* InterpolationTab;
    QGroupBox* InterpolationCB;
    QComboBox* ToolInterpDD;
    QLabel* ToolInterpLabel;
    QCheckBox* UseGPUCB;
    QComboBox* GPUInterpDD;
    QLabel* GPUThreadInterpLabel;
    QComboBox* GPUThreadDD;
    QLabel* ModelInterpLabel;
    QComboBox* ModelInterpDD;
    QCheckBox* SceneChangeCB;
    QDoubleSpinBox* OutputFPSNUD;
    QLabel* OutFPSLabel;
    QLabel* SceneChangeLabel;
    QComboBox* BackendDD;
    QLabel* SlashLabel;
    QLabel* ShaderLabel;
    QComboBox* RIFEModelVKDD;
    QComboBox* RIFEModelCADD;
    QComboBox* ShaderDD;
    QCheckBox* ParamsCB;
    QLabel* EqualsLabel;
    QLabel* InterpModeLabel;
    QComboBox* InterpModeDD;
    QLabel* ArtefactMaskLabel;
    QComboBox* ArtefactMaskDD;
    QLineEdit* SuperTxtBox;
    QLabel* SuperLabel;
    QLabel* AnalyseLabel;
    QLineEdit* AnalyseTxtBox;
    QLabel* SmoothLabel;
    QLineEdit* SmoothTxtBox;
    QLabel* Times2Label;
    QDoubleSpinBox* SCThresholdNUD;
    QLabel* SCThresholdLabel;
    QWidget* UpscalingTab;
    QGroupBox* UpscalingGB;
    QLabel* GPUThreadUpscaleLabel;
    QComboBox* ToolUpscaleDD;
    QLabel* ToolUpscaleLabel;
    QComboBox* GPUThreadUpscaleDD;
    QComboBox* GPUUpscaleDD;
    QLabel* GPULabel;
    QComboBox* ModelUpscaleDD;
    QLabel* ModelUpscaleLabel;
    QLabel* NoiseReduc2xLabel;
    QComboBox* NoiseReduc2xDD;
    QLabel* Precision2xLabel;
    QComboBox* Precision2xDD;
    QLabel* OutResolutionLabel;
    QSpinBox* Width2xNUD;
    QLabel* Eks2Label;
    QSpinBox* Height2xNUD;
    QComboBox* AutoAdjDD;
    QCheckBox* AutoAdjCB;
    QLabel* TTA2xLabel;
    QCheckBox* TTA2xCB;
    QWidget* VSColorsTab;
    QGroupBox* ColorPropsGB;
    QLabel* InputColorsLabel;
    QLabel* OutputColorsLabel;
    QComboBox* InputMatrixDD;
    QComboBox* InputTransferDD;
    QComboBox* InputPrimsDD;
    QComboBox* OutputMatrixDD;
    QLabel* Slash2Label;
    QLabel* Slash3Label;
    QLabel* Slash4Label;
    QLabel* Slash5Label;
    QComboBox* OutputTransferDD;
    QComboBox* OutputPrimsDD;
    QWidget* LineTab;
    QGroupBox* AntiAliasingGB;
    QLabel* UseAALabel;
    QCheckBox* UseAACB;
    QWidget* FiltersTab;
    QTabWidget* FiltersTabs;
    QWidget* ResizeTab;
    QGroupBox* ResizeGB;
    QLabel* ResolutionResLabel;
    QLabel* Eks3Label;
    QSpinBox* WidthNUD;
    QSpinBox* HeightNUD;
    QComboBox* AutoAdjResDD;
    QCheckBox* AutoAdjResCB;
    QCheckBox* ResizeAlgoCB;
    QComboBox* ResizeAlgoDD;
    QGroupBox* RotateGB;
    QLabel* AngleLabel;
    QComboBox* AngleDD;
    QCheckBox* FlipCB;
    QComboBox* FlipDD;
    QLabel* NoAutoRotateLabel;
    QCheckBox* NoAutoRotateCB;
    QGroupBox* CropGB;
    QLabel* OutSizeLabel;
    QLabel* Eks4Label;
    QSpinBox* OutWidthNUD;
    QSpinBox* OutHeightNUD;
    QLabel* LocationLabel;
    QSpinBox* EksNUD;
    QSpinBox* WhyNUD;
    QLabel* Slash4Label_2;
    QWidget* ColorsTab;
    QGroupBox* SharpenGB;
    QLabel* RadiusLabel;
    QComboBox* RadiusDD;
    QLabel* StrengthLabel;
    QComboBox* StrengthDD;
    QWidget* MiscFFTab;
    QGroupBox* DeinterlaceGB;
    QLabel* EnableDeintLabel;
    QCheckBox* UseDeintCB;
    QWidget* AudioTab;
    QTableWidget* AudioQueue;
    QGroupBox* AudioSelectorGB;
    QLabel* SelectedAudioLabel;
    QComboBox* SelectedAudioDD;
    QLabel* AudioSourceLabel;
    QPushButton* SelectBttn;
    QLineEdit* AudioSourceTxtBox;
    QGroupBox* EncodingAudioGB;
    QLabel* EncoderAudioLabel;
    QComboBox* AudioEncoderDD;
    QLabel* RealAudioBitrateLabel;
    QSpinBox* AudioBitrateNUD;
    QCheckBox* DownmixCB;
    QComboBox* DownmixDD;
    QLabel* AudioQualityLabel;
    QSpinBox* AudioQualityNUD;
    QPushButton* AddAudioJobBttn;
    QLabel* AudioQueueLabel;
    QCheckBox* AudioTitleCB;
    QLineEdit* AudioTitleTxtBox;
    QCheckBox* LangAudioCB;
    QComboBox* LangAudioDD;
    QWidget* SubtitlesTab;
    QCheckBox* SubtitleTitleCB;
    QLabel* SubtitleQueueLabel;
    QTableWidget* SubtitleQueue;
    QComboBox* SubtitleLangDD;
    QLineEdit* SubtitleTitleTxtBox;
    QCheckBox* SubtitleLangCB;
    QGroupBox* SubtitleSelectorGB;
    QLabel* SelectedSubtitleLabel;
    QComboBox* SelectedSubtitleDD;
    QLabel* SubtitleSourceLabel;
    QPushButton* SubSelectBttn;
    QLineEdit* SubSourceTxtBox;
    QPushButton* SubtitleInfoBttn;
    QGroupBox* SubtitleEncodingGB;
    QLabel* SubtitleEncoderLabel;
    QComboBox* SubtitleEncoderDD;
    QPushButton* AddSubtitleJobBttn;
    QWidget* PrefTab;
    QTabWidget* SettingsTabs;
    QWidget* EGUITab;
    QGroupBox* EGUISettingsGB;
    QCheckBox* EnablePreviewCB;
    QCheckBox* AutoDelSourceCB;
    QCheckBox* ErrorMessageCB;
    QLabel* ErrorMessageLabel;
    QLabel* DeleteSourcesLabel;
    QLabel* EnablePreviewLabel;
    QLabel* UpdateOptLabel;
    QCheckBox* UpdateOptCB;
    QLabel* GenerateOutLabel;
    QCheckBox* GenerateOutCB;
    QLabel* NotificationLabel;
    QCheckBox* NotificationCB;
    QGroupBox* ProgressBarGB;
    QCheckBox* JobsCB;
    QCheckBox* FPSCB;
    QCheckBox* BitrateCB;
    QCheckBox* TimeLeftCB;
    QCheckBox* TimeElapsedCB;
    QCheckBox* PercentageCB;
    QWidget* EncodingTab;
    QGroupBox* ProcessSettingsGB;
    QSpinBox* LimitThreadsNUD;
    QCheckBox* LimitThreadsCB;
    QGroupBox* MultiGPUGB;
    QPushButton* TestGPUBttn;
    QSpinBox* GPU1IDNUD;
    QSpinBox* GPU2IDNUD;
    QLabel* GPU1IDLabel;
    QLabel* GPU1IDLabel2;
    QWidget* JobTab;
    QTableWidget* JobQueue;
    QLabel* JobQueueLabel;
    QPushButton* ClearJobsBttn;
    QPushButton* CancelQueueBttn;
    QWidget* LogsTab;
    QGroupBox* LogsOutGB;
    QTextEdit* LogsOutRTxtBox;
    QPushButton* LogsDirBttn;
    QWidget* AboutTab;
    QGroupBox* AboutGUIGB;
    QLabel* AboutGuiLabel;
    QGroupBox* DonateGB;
    QLabel* DonateToDaGooseLabel;
    QLabel* DonateToGlitchLabel;
    QPushButton* DonateToDaGooseBttn;
    QPushButton* DonateToGlitchBttn;
    QGroupBox* LinksGB;
    QPushButton* YoutubeBttn;
    QPushButton* DiscordBttn;
    QPushButton* InstaBttn;
    QPushButton* ClearBttn;
    QPushButton* LicensesBttn;
    QProgressBar* progressBar;
    QGroupBox* VideoInfoGB;
    QLabel* EncoderLabel;
    QLabel* DurationLabel;
    QLabel* ResolutionLabel;
    QLabel* VidBitrateLabel;
    QLabel* ColorsLabel;
    QLabel* FPSLabel;
    QLabel* MatrixLabel;
    QLabel* TransferLabel;
    QLabel* VidformatValueLabel;
    QLabel* ResolutionValueLabel;
    QLabel* BitrateValueLabel;
    QLabel* ColorsValueLabel;
    QLabel* FPSValueLabel;
    QLabel* DurationValueLabel;
    QLabel* MatrixValueLabel;
    QLabel* TransferValueLabel;
    QLabel* PrimariesLabel;
    QLabel* PrimariesValueLabel;
    QLineEdit* SaveOutTxtBox;
    QComboBox* OutContainerx264DD;
    QPushButton* SaveOutBttn;
    QPushButton* PreviewBttn;
    QPushButton* AddJobBttn;
    QPushButton* StartBttn;
    QGroupBox* AudioInfoGB;
    QLabel* SampleRateLabel;
    QLabel* AudioLanguageLabel;
    QLabel* SampleRateValueLabel;
    QLabel* TrackLabel;
    QLabel* AudioLanguageValueLabel;
    QLabel* FormatLabel;
    QLabel* ChannelsLabel;
    QLabel* ChannelsValueLabel;
    QLabel* FormatValueLabel;
    QComboBox* AudioTrackDD;
    QLabel* ProgressBarLabel;
    QComboBox* OutContainerx265DD;
    QComboBox* OutContainerProResDD;
    QComboBox* OutContainerTheoraDD;
    QComboBox* OutContainerVPXDD;
    QComboBox* OutContainerAV1DD;
    QComboBox* OutContainerMuxDD;

    void setupUi(QMainWindow* EncodeGUIMV)
    {
        if (EncodeGUIMV->objectName().isEmpty())
            EncodeGUIMV->setObjectName(QString::fromUtf8("EncodeGUIMV"));
        EncodeGUIMV->resize(743, 387);
        EncodeGUIMV->setMinimumSize(QSize(743, 387));
        EncodeGUIMV->setMaximumSize(QSize(743, 387));
        EncodeGUIMV->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/EncodeGUI/egui.png"), QSize(), QIcon::Normal, QIcon::Off);
        EncodeGUIMV->setWindowIcon(icon);
        EncodeGUIMV->setIconSize(QSize(48, 48));
        EncodeGUIMV->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(EncodeGUIMV);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Tabs = new QTabWidget(centralWidget);
        Tabs->setObjectName(QString::fromUtf8("Tabs"));
        Tabs->setGeometry(QRect(6, 0, 563, 321));
        Tabs->setFocusPolicy(Qt::TabFocus);
        HomeTab = new QWidget();
        HomeTab->setObjectName(QString::fromUtf8("HomeTab"));
        EGUILogo = new QLabel(HomeTab);
        EGUILogo->setObjectName(QString::fromUtf8("EGUILogo"));
        EGUILogo->setGeometry(QRect(26, 208, 356, 57));
        EGUILogo->setTextFormat(Qt::RichText);
        EGUILogo->setPixmap(QPixmap(QString::fromUtf8(":/EncodeGUI/EGUI_logo.png")));
        EGUILogo->setScaledContents(true);
        InputGB = new QGroupBox(HomeTab);
        InputGB->setObjectName(QString::fromUtf8("InputGB"));
        InputGB->setGeometry(QRect(412, 192, 131, 89));
        InputGB->setAlignment(Qt::AlignCenter);
        GetVidInfoCB = new QCheckBox(InputGB);
        GetVidInfoCB->setObjectName(QString::fromUtf8("GetVidInfoCB"));
        GetVidInfoCB->setGeometry(QRect(16, 39, 101, 20));
        GetVidInfoCB->setChecked(true);
        SampleVidCB = new QCheckBox(InputGB);
        SampleVidCB->setObjectName(QString::fromUtf8("SampleVidCB"));
        SampleVidCB->setGeometry(QRect(16, 17, 111, 20));
        SampleVidCB->setChecked(false);
        BatchCB = new QCheckBox(InputGB);
        BatchCB->setObjectName(QString::fromUtf8("BatchCB"));
        BatchCB->setGeometry(QRect(16, 60, 100, 21));
        EGUIGB = new QGroupBox(HomeTab);
        EGUIGB->setObjectName(QString::fromUtf8("EGUIGB"));
        EGUIGB->setGeometry(QRect(15, 34, 229, 151));
        EGUIGB->setAlignment(Qt::AlignCenter);
        VideoEncDD = new QComboBox(EGUIGB);
        VideoEncDD->addItem(QString());
        VideoEncDD->addItem(QString());
        VideoEncDD->addItem(QString());
        VideoEncDD->addItem(QString());
        VideoEncDD->addItem(QString());
        VideoEncDD->addItem(QString());
        VideoEncDD->addItem(QString());
        VideoEncDD->setObjectName(QString::fromUtf8("VideoEncDD"));
        VideoEncDD->setGeometry(QRect(106, 22, 108, 22));
        VidEncLabel = new QLabel(EGUIGB);
        VidEncLabel->setObjectName(QString::fromUtf8("VidEncLabel"));
        VidEncLabel->setGeometry(QRect(16, 23, 83, 18));
        AudioCB = new QCheckBox(EGUIGB);
        AudioCB->setObjectName(QString::fromUtf8("AudioCB"));
        AudioCB->setEnabled(true);
        AudioCB->setGeometry(QRect(15, 54, 75, 20));
        AudioDD = new QComboBox(EGUIGB);
        AudioDD->addItem(QString());
        AudioDD->addItem(QString());
        AudioDD->setObjectName(QString::fromUtf8("AudioDD"));
        AudioDD->setGeometry(QRect(106, 54, 108, 22));
        SubtitlesCB = new QCheckBox(EGUIGB);
        SubtitlesCB->setObjectName(QString::fromUtf8("SubtitlesCB"));
        SubtitlesCB->setEnabled(true);
        SubtitlesCB->setGeometry(QRect(15, 86, 80, 20));
        SubtitlesCB->setCheckable(true);
        SubtitlesDD = new QComboBox(EGUIGB);
        SubtitlesDD->addItem(QString());
        SubtitlesDD->addItem(QString());
        SubtitlesDD->addItem(QString());
        SubtitlesDD->setObjectName(QString::fromUtf8("SubtitlesDD"));
        SubtitlesDD->setGeometry(QRect(106, 86, 108, 22));
        ChaptersCB = new QCheckBox(EGUIGB);
        ChaptersCB->setObjectName(QString::fromUtf8("ChaptersCB"));
        ChaptersCB->setEnabled(false);
        ChaptersCB->setGeometry(QRect(200, 118, 22, 22));
        ChaptersLabel = new QLabel(EGUIGB);
        ChaptersLabel->setObjectName(QString::fromUtf8("ChaptersLabel"));
        ChaptersLabel->setGeometry(QRect(16, 115, 77, 23));
        CurrenProcGB = new QGroupBox(HomeTab);
        CurrenProcGB->setObjectName(QString::fromUtf8("CurrenProcGB"));
        CurrenProcGB->setGeometry(QRect(259, 34, 284, 151));
        CurrenProcGB->setMaximumSize(QSize(16777215, 16777215));
        CurrenProcGB->setAlignment(Qt::AlignCenter);
        WhenEncCompleteLabel = new QLabel(CurrenProcGB);
        WhenEncCompleteLabel->setObjectName(QString::fromUtf8("WhenEncCompleteLabel"));
        WhenEncCompleteLabel->setGeometry(QRect(14, 121, 152, 16));
        WhenEncCompleteLabel->setTextFormat(Qt::AutoText);
        WhenEncCompleteDD = new QComboBox(CurrenProcGB);
        WhenEncCompleteDD->addItem(QString());
        WhenEncCompleteDD->addItem(QString());
        WhenEncCompleteDD->addItem(QString());
        WhenEncCompleteDD->addItem(QString());
        WhenEncCompleteDD->setObjectName(QString::fromUtf8("WhenEncCompleteDD"));
        WhenEncCompleteDD->setGeometry(QRect(186, 119, 86, 22));
        PauseBttn = new QPushButton(CurrenProcGB);
        PauseBttn->setObjectName(QString::fromUtf8("PauseBttn"));
        PauseBttn->setEnabled(false);
        PauseBttn->setGeometry(QRect(12, 86, 125, 24));
        QFont font;
        font.setBold(true);
        PauseBttn->setFont(font);
        CancelBttn = new QPushButton(CurrenProcGB);
        CancelBttn->setObjectName(QString::fromUtf8("CancelBttn"));
        CancelBttn->setEnabled(false);
        CancelBttn->setGeometry(QRect(146, 86, 127, 24));
        CancelBttn->setFont(font);
        JobIDLabel = new QLabel(CurrenProcGB);
        JobIDLabel->setObjectName(QString::fromUtf8("JobIDLabel"));
        JobIDLabel->setGeometry(QRect(14, 57, 35, 16));
        JobStatusLabel = new QLabel(CurrenProcGB);
        JobStatusLabel->setObjectName(QString::fromUtf8("JobStatusLabel"));
        JobStatusLabel->setGeometry(QRect(147, 55, 39, 20));
        JobStartLabel = new QLabel(CurrenProcGB);
        JobStartLabel->setObjectName(QString::fromUtf8("JobStartLabel"));
        JobStartLabel->setGeometry(QRect(14, 26, 87, 16));
        JobIDValueLabel = new QLabel(CurrenProcGB);
        JobIDValueLabel->setObjectName(QString::fromUtf8("JobIDValueLabel"));
        JobIDValueLabel->setGeometry(QRect(51, 55, 80, 20));
        JobIDValueLabel->setFont(font);
        JobIDValueLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
        JobStatusValueLabel = new QLabel(CurrenProcGB);
        JobStatusValueLabel->setObjectName(QString::fromUtf8("JobStatusValueLabel"));
        JobStatusValueLabel->setGeometry(QRect(190, 55, 82, 20));
        JobStatusValueLabel->setFont(font);
        JobStatusValueLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
        JobStartValueLabel = new QLabel(CurrenProcGB);
        JobStartValueLabel->setObjectName(QString::fromUtf8("JobStartValueLabel"));
        JobStartValueLabel->setGeometry(QRect(100, 22, 172, 24));
        JobStartValueLabel->setFont(font);
        JobStartValueLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
        SelectInTxtBox = new QLineEdit(HomeTab);
        SelectInTxtBox->setObjectName(QString::fromUtf8("SelectInTxtBox"));
        SelectInTxtBox->setEnabled(true);
        SelectInTxtBox->setGeometry(QRect(15, 7, 428, 22));
        SelectInTxtBox->setReadOnly(true);
        SelectInBttn = new QPushButton(HomeTab);
        SelectInBttn->setObjectName(QString::fromUtf8("SelectInBttn"));
        SelectInBttn->setGeometry(QRect(449, 7, 95, 24));
        Tabs->addTab(HomeTab, QString());
        VideoTab = new QWidget();
        VideoTab->setObjectName(QString::fromUtf8("VideoTab"));
        VideoTabs = new QTabWidget(VideoTab);
        VideoTabs->setObjectName(QString::fromUtf8("VideoTabs"));
        VideoTabs->setGeometry(QRect(3, 2, 553, 289));
        x264Tab = new QWidget();
        x264Tab->setObjectName(QString::fromUtf8("x264Tab"));
        x264Tabs = new QTabWidget(x264Tab);
        x264Tabs->setObjectName(QString::fromUtf8("x264Tabs"));
        x264Tabs->setGeometry(QRect(3, 2, 542, 257));
        Main264Tab = new QWidget();
        Main264Tab->setObjectName(QString::fromUtf8("Main264Tab"));
        EncodingSetting264GB = new QGroupBox(Main264Tab);
        EncodingSetting264GB->setObjectName(QString::fromUtf8("EncodingSetting264GB"));
        EncodingSetting264GB->setGeometry(QRect(12, 7, 260, 212));
        EncodingSetting264GB->setAlignment(Qt::AlignCenter);
        EncodeMode264Label = new QLabel(EncodingSetting264GB);
        EncodeMode264Label->setObjectName(QString::fromUtf8("EncodeMode264Label"));
        EncodeMode264Label->setGeometry(QRect(18, 24, 39, 16));
        EncodeMode264DD = new QComboBox(EncodingSetting264GB);
        EncodeMode264DD->addItem(QString());
        EncodeMode264DD->addItem(QString());
        EncodeMode264DD->addItem(QString());
        EncodeMode264DD->addItem(QString());
        EncodeMode264DD->setObjectName(QString::fromUtf8("EncodeMode264DD"));
        EncodeMode264DD->setGeometry(QRect(56, 22, 187, 22));
        Hardware264CB = new QCheckBox(EncodingSetting264GB);
        Hardware264CB->setObjectName(QString::fromUtf8("Hardware264CB"));
        Hardware264CB->setGeometry(QRect(18, 52, 75, 20));
        Hardware264DD = new QComboBox(EncodingSetting264GB);
        Hardware264DD->addItem(QString());
        Hardware264DD->addItem(QString());
        Hardware264DD->addItem(QString());
        Hardware264DD->setObjectName(QString::fromUtf8("Hardware264DD"));
        Hardware264DD->setGeometry(QRect(158, 53, 85, 22));
        Bitrate264NUD = new QDoubleSpinBox(EncodingSetting264GB);
        Bitrate264NUD->setObjectName(QString::fromUtf8("Bitrate264NUD"));
        Bitrate264NUD->setGeometry(QRect(169, 116, 74, 22));
        Bitrate264NUD->setDecimals(0);
        Bitrate264NUD->setMaximum(80000.000000000000000);
        Bitrate264NUD->setValue(2000.000000000000000);
        Tune264CB = new QCheckBox(EncodingSetting264GB);
        Tune264CB->setObjectName(QString::fromUtf8("Tune264CB"));
        Tune264CB->setGeometry(QRect(18, 149, 59, 20));
        Tune264DD = new QComboBox(EncodingSetting264GB);
        Tune264DD->addItem(QString());
        Tune264DD->addItem(QString());
        Tune264DD->addItem(QString());
        Tune264DD->addItem(QString());
        Tune264DD->addItem(QString());
        Tune264DD->addItem(QString());
        Tune264DD->addItem(QString());
        Tune264DD->addItem(QString());
        Tune264DD->setObjectName(QString::fromUtf8("Tune264DD"));
        Tune264DD->setGeometry(QRect(144, 149, 99, 22));
        Preset264CB = new QCheckBox(EncodingSetting264GB);
        Preset264CB->setObjectName(QString::fromUtf8("Preset264CB"));
        Preset264CB->setGeometry(QRect(18, 179, 54, 20));
        Preset264CB->setChecked(true);
        Preset264DD = new QComboBox(EncodingSetting264GB);
        Preset264DD->addItem(QString());
        Preset264DD->addItem(QString());
        Preset264DD->addItem(QString());
        Preset264DD->addItem(QString());
        Preset264DD->addItem(QString());
        Preset264DD->addItem(QString());
        Preset264DD->addItem(QString());
        Preset264DD->addItem(QString());
        Preset264DD->addItem(QString());
        Preset264DD->addItem(QString());
        Preset264DD->setObjectName(QString::fromUtf8("Preset264DD"));
        Preset264DD->setGeometry(QRect(144, 180, 99, 22));
        Quantizer264Label = new QLabel(EncodingSetting264GB);
        Quantizer264Label->setObjectName(QString::fromUtf8("Quantizer264Label"));
        Quantizer264Label->setGeometry(QRect(19, 118, 125, 16));
        Quantizer264NUD = new QSpinBox(EncodingSetting264GB);
        Quantizer264NUD->setObjectName(QString::fromUtf8("Quantizer264NUD"));
        Quantizer264NUD->setGeometry(QRect(200, 116, 43, 22));
        Quantizer264NUD->setMaximum(51);
        Quantizer264NUD->setValue(22);
        CRFValue264NUD = new QSpinBox(EncodingSetting264GB);
        CRFValue264NUD->setObjectName(QString::fromUtf8("CRFValue264NUD"));
        CRFValue264NUD->setGeometry(QRect(200, 116, 43, 22));
        CRFValue264NUD->setMaximum(51);
        CRFValue264NUD->setValue(22);
        CRFValueLabel = new QLabel(EncodingSetting264GB);
        CRFValueLabel->setObjectName(QString::fromUtf8("CRFValueLabel"));
        CRFValueLabel->setGeometry(QRect(19, 118, 79, 16));
        EncodeMode264HWDD = new QComboBox(EncodingSetting264GB);
        EncodeMode264HWDD->addItem(QString());
        EncodeMode264HWDD->addItem(QString());
        EncodeMode264HWDD->addItem(QString());
        EncodeMode264HWDD->setObjectName(QString::fromUtf8("EncodeMode264HWDD"));
        EncodeMode264HWDD->setGeometry(QRect(56, 22, 187, 22));
        Bitrate264Label = new QLabel(EncodingSetting264GB);
        Bitrate264Label->setObjectName(QString::fromUtf8("Bitrate264Label"));
        Bitrate264Label->setGeometry(QRect(19, 118, 68, 16));
        Profile264GB = new QGroupBox(Main264Tab);
        Profile264GB->setObjectName(QString::fromUtf8("Profile264GB"));
        Profile264GB->setGeometry(QRect(287, 7, 237, 122));
        Profile264GB->setAlignment(Qt::AlignCenter);
        Profile264GB->setCheckable(true);
        Profile264GB->setChecked(false);
        Profile264Label = new QLabel(Profile264GB);
        Profile264Label->setObjectName(QString::fromUtf8("Profile264Label"));
        Profile264Label->setGeometry(QRect(17, 21, 45, 20));
        Profile264DD = new QComboBox(Profile264GB);
        Profile264DD->addItem(QString());
        Profile264DD->addItem(QString());
        Profile264DD->addItem(QString());
        Profile264DD->addItem(QString());
        Profile264DD->addItem(QString());
        Profile264DD->setObjectName(QString::fromUtf8("Profile264DD"));
        Profile264DD->setGeometry(QRect(134, 21, 85, 22));
        Level264Label = new QLabel(Profile264GB);
        Level264Label->setObjectName(QString::fromUtf8("Level264Label"));
        Level264Label->setGeometry(QRect(17, 54, 50, 20));
        Level264DD = new QComboBox(Profile264GB);
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->addItem(QString());
        Level264DD->setObjectName(QString::fromUtf8("Level264DD"));
        Level264DD->setGeometry(QRect(134, 54, 85, 22));
        EntropyCode264Label = new QLabel(Profile264GB);
        EntropyCode264Label->setObjectName(QString::fromUtf8("EntropyCode264Label"));
        EntropyCode264Label->setGeometry(QRect(17, 87, 86, 20));
        EntropyCode264DD = new QComboBox(Profile264GB);
        EntropyCode264DD->addItem(QString());
        EntropyCode264DD->addItem(QString());
        EntropyCode264DD->setObjectName(QString::fromUtf8("EntropyCode264DD"));
        EntropyCode264DD->setGeometry(QRect(134, 87, 85, 22));
        Colors264GB = new QGroupBox(Main264Tab);
        Colors264GB->setObjectName(QString::fromUtf8("Colors264GB"));
        Colors264GB->setGeometry(QRect(287, 135, 237, 84));
        Colors264GB->setAlignment(Qt::AlignCenter);
        Colors264GB->setCheckable(false);
        Colors264GB->setChecked(false);
        BitDepth264Label = new QLabel(Colors264GB);
        BitDepth264Label->setObjectName(QString::fromUtf8("BitDepth264Label"));
        BitDepth264Label->setGeometry(QRect(17, 22, 55, 20));
        BitDepth264DD = new QComboBox(Colors264GB);
        BitDepth264DD->addItem(QString());
        BitDepth264DD->addItem(QString());
        BitDepth264DD->setObjectName(QString::fromUtf8("BitDepth264DD"));
        BitDepth264DD->setGeometry(QRect(149, 21, 70, 22));
        Space264Label = new QLabel(Colors264GB);
        Space264Label->setObjectName(QString::fromUtf8("Space264Label"));
        Space264Label->setGeometry(QRect(17, 53, 94, 20));
        ColorSpace264DD = new QComboBox(Colors264GB);
        ColorSpace264DD->addItem(QString());
        ColorSpace264DD->addItem(QString());
        ColorSpace264DD->setObjectName(QString::fromUtf8("ColorSpace264DD"));
        ColorSpace264DD->setGeometry(QRect(149, 53, 70, 22));
        x264Tabs->addTab(Main264Tab, QString());
        Fames264Tab = new QWidget();
        Fames264Tab->setObjectName(QString::fromUtf8("Fames264Tab"));
        RefFrames264GB = new QGroupBox(Fames264Tab);
        RefFrames264GB->setObjectName(QString::fromUtf8("RefFrames264GB"));
        RefFrames264GB->setGeometry(QRect(12, 7, 260, 76));
        RefFrames264GB->setAlignment(Qt::AlignCenter);
        RefFrames264GB->setCheckable(true);
        RefFrames264GB->setChecked(false);
        Reference264Sldr = new QSlider(RefFrames264GB);
        Reference264Sldr->setObjectName(QString::fromUtf8("Reference264Sldr"));
        Reference264Sldr->setGeometry(QRect(15, 31, 178, 24));
        Reference264Sldr->setMaximum(16);
        Reference264Sldr->setValue(2);
        Reference264Sldr->setOrientation(Qt::Horizontal);
        Reference264LED = new QLCDNumber(RefFrames264GB);
        Reference264LED->setObjectName(QString::fromUtf8("Reference264LED"));
        Reference264LED->setGeometry(QRect(205, 24, 42, 36));
        Reference264LED->setDigitCount(2);
        Reference264LED->setMode(QLCDNumber::Dec);
        Reference264LED->setSegmentStyle(QLCDNumber::Flat);
        Reference264LED->setProperty("value", QVariant(2.000000000000000));
        BFrames264GB = new QGroupBox(Fames264Tab);
        BFrames264GB->setObjectName(QString::fromUtf8("BFrames264GB"));
        BFrames264GB->setGeometry(QRect(287, 7, 237, 76));
        BFrames264GB->setAlignment(Qt::AlignCenter);
        BFrames264GB->setCheckable(true);
        BFrames264GB->setChecked(false);
        BFrame264Sldr = new QSlider(BFrames264GB);
        BFrame264Sldr->setObjectName(QString::fromUtf8("BFrame264Sldr"));
        BFrame264Sldr->setGeometry(QRect(14, 31, 155, 24));
        BFrame264Sldr->setMaximum(16);
        BFrame264Sldr->setValue(4);
        BFrame264Sldr->setOrientation(Qt::Horizontal);
        Bframe264LED = new QLCDNumber(BFrames264GB);
        Bframe264LED->setObjectName(QString::fromUtf8("Bframe264LED"));
        Bframe264LED->setGeometry(QRect(181, 24, 41, 36));
        Bframe264LED->setDigitCount(2);
        Bframe264LED->setMode(QLCDNumber::Dec);
        Bframe264LED->setSegmentStyle(QLCDNumber::Flat);
        Bframe264LED->setProperty("value", QVariant(4.000000000000000));
        x264Tabs->addTab(Fames264Tab, QString());
        VideoTabs->addTab(x264Tab, QString());
        x265Tab = new QWidget();
        x265Tab->setObjectName(QString::fromUtf8("x265Tab"));
        x265Tabs = new QTabWidget(x265Tab);
        x265Tabs->setObjectName(QString::fromUtf8("x265Tabs"));
        x265Tabs->setGeometry(QRect(3, 2, 542, 257));
        Main265Tab = new QWidget();
        Main265Tab->setObjectName(QString::fromUtf8("Main265Tab"));
        Colors265GB = new QGroupBox(Main265Tab);
        Colors265GB->setObjectName(QString::fromUtf8("Colors265GB"));
        Colors265GB->setGeometry(QRect(287, 135, 237, 84));
        Colors265GB->setAlignment(Qt::AlignCenter);
        Colors265GB->setCheckable(false);
        Colors265GB->setChecked(false);
        BitDepth265Label = new QLabel(Colors265GB);
        BitDepth265Label->setObjectName(QString::fromUtf8("BitDepth265Label"));
        BitDepth265Label->setGeometry(QRect(17, 22, 55, 20));
        BitDepth265DD = new QComboBox(Colors265GB);
        BitDepth265DD->addItem(QString());
        BitDepth265DD->addItem(QString());
        BitDepth265DD->addItem(QString());
        BitDepth265DD->setObjectName(QString::fromUtf8("BitDepth265DD"));
        BitDepth265DD->setGeometry(QRect(149, 21, 70, 22));
        Sample265Label = new QLabel(Colors265GB);
        Sample265Label->setObjectName(QString::fromUtf8("Sample265Label"));
        Sample265Label->setGeometry(QRect(17, 53, 74, 20));
        ColorSpace265DD = new QComboBox(Colors265GB);
        ColorSpace265DD->addItem(QString());
        ColorSpace265DD->addItem(QString());
        ColorSpace265DD->addItem(QString());
        ColorSpace265DD->setObjectName(QString::fromUtf8("ColorSpace265DD"));
        ColorSpace265DD->setGeometry(QRect(149, 53, 70, 22));
        Profile265GB = new QGroupBox(Main265Tab);
        Profile265GB->setObjectName(QString::fromUtf8("Profile265GB"));
        Profile265GB->setGeometry(QRect(287, 7, 237, 122));
        Profile265GB->setAlignment(Qt::AlignCenter);
        Profile265GB->setCheckable(true);
        Profile265GB->setChecked(false);
        Profile265Label = new QLabel(Profile265GB);
        Profile265Label->setObjectName(QString::fromUtf8("Profile265Label"));
        Profile265Label->setGeometry(QRect(17, 21, 45, 20));
        Profile265DD = new QComboBox(Profile265GB);
        Profile265DD->addItem(QString());
        Profile265DD->addItem(QString());
        Profile265DD->addItem(QString());
        Profile265DD->addItem(QString());
        Profile265DD->setObjectName(QString::fromUtf8("Profile265DD"));
        Profile265DD->setGeometry(QRect(134, 21, 85, 22));
        Level265Label = new QLabel(Profile265GB);
        Level265Label->setObjectName(QString::fromUtf8("Level265Label"));
        Level265Label->setGeometry(QRect(17, 54, 50, 20));
        Level265DD = new QComboBox(Profile265GB);
        Level265DD->addItem(QString());
        Level265DD->addItem(QString());
        Level265DD->addItem(QString());
        Level265DD->addItem(QString());
        Level265DD->addItem(QString());
        Level265DD->addItem(QString());
        Level265DD->addItem(QString());
        Level265DD->addItem(QString());
        Level265DD->addItem(QString());
        Level265DD->addItem(QString());
        Level265DD->addItem(QString());
        Level265DD->addItem(QString());
        Level265DD->addItem(QString());
        Level265DD->addItem(QString());
        Level265DD->addItem(QString());
        Level265DD->setObjectName(QString::fromUtf8("Level265DD"));
        Level265DD->setGeometry(QRect(134, 54, 85, 22));
        Tier265Label = new QLabel(Profile265GB);
        Tier265Label->setObjectName(QString::fromUtf8("Tier265Label"));
        Tier265Label->setGeometry(QRect(17, 87, 38, 20));
        Tier265DD = new QComboBox(Profile265GB);
        Tier265DD->addItem(QString());
        Tier265DD->addItem(QString());
        Tier265DD->setObjectName(QString::fromUtf8("Tier265DD"));
        Tier265DD->setGeometry(QRect(134, 87, 85, 22));
        EncodingSetting265GB = new QGroupBox(Main265Tab);
        EncodingSetting265GB->setObjectName(QString::fromUtf8("EncodingSetting265GB"));
        EncodingSetting265GB->setGeometry(QRect(12, 7, 260, 212));
        EncodingSetting265GB->setAlignment(Qt::AlignCenter);
        EncodeMode265Label = new QLabel(EncodingSetting265GB);
        EncodeMode265Label->setObjectName(QString::fromUtf8("EncodeMode265Label"));
        EncodeMode265Label->setGeometry(QRect(18, 24, 39, 16));
        EncodeMode265DD = new QComboBox(EncodingSetting265GB);
        EncodeMode265DD->addItem(QString());
        EncodeMode265DD->addItem(QString());
        EncodeMode265DD->addItem(QString());
        EncodeMode265DD->addItem(QString());
        EncodeMode265DD->setObjectName(QString::fromUtf8("EncodeMode265DD"));
        EncodeMode265DD->setGeometry(QRect(56, 22, 187, 22));
        Hardware265CB = new QCheckBox(EncodingSetting265GB);
        Hardware265CB->setObjectName(QString::fromUtf8("Hardware265CB"));
        Hardware265CB->setGeometry(QRect(18, 52, 75, 20));
        Hardware265DD = new QComboBox(EncodingSetting265GB);
        Hardware265DD->addItem(QString());
        Hardware265DD->addItem(QString());
        Hardware265DD->addItem(QString());
        Hardware265DD->setObjectName(QString::fromUtf8("Hardware265DD"));
        Hardware265DD->setGeometry(QRect(158, 53, 85, 22));
        Bitrate265NUD = new QDoubleSpinBox(EncodingSetting265GB);
        Bitrate265NUD->setObjectName(QString::fromUtf8("Bitrate265NUD"));
        Bitrate265NUD->setGeometry(QRect(169, 116, 74, 22));
        Bitrate265NUD->setDecimals(0);
        Bitrate265NUD->setMaximum(80000.000000000000000);
        Bitrate265NUD->setValue(2000.000000000000000);
        Tune265CB = new QCheckBox(EncodingSetting265GB);
        Tune265CB->setObjectName(QString::fromUtf8("Tune265CB"));
        Tune265CB->setGeometry(QRect(18, 149, 59, 20));
        Tune265DD = new QComboBox(EncodingSetting265GB);
        Tune265DD->addItem(QString());
        Tune265DD->addItem(QString());
        Tune265DD->addItem(QString());
        Tune265DD->addItem(QString());
        Tune265DD->addItem(QString());
        Tune265DD->addItem(QString());
        Tune265DD->setObjectName(QString::fromUtf8("Tune265DD"));
        Tune265DD->setGeometry(QRect(144, 149, 99, 22));
        Preset265CB = new QCheckBox(EncodingSetting265GB);
        Preset265CB->setObjectName(QString::fromUtf8("Preset265CB"));
        Preset265CB->setGeometry(QRect(18, 179, 54, 20));
        Preset265CB->setChecked(true);
        Preset265DD = new QComboBox(EncodingSetting265GB);
        Preset265DD->addItem(QString());
        Preset265DD->addItem(QString());
        Preset265DD->addItem(QString());
        Preset265DD->addItem(QString());
        Preset265DD->addItem(QString());
        Preset265DD->addItem(QString());
        Preset265DD->addItem(QString());
        Preset265DD->addItem(QString());
        Preset265DD->addItem(QString());
        Preset265DD->addItem(QString());
        Preset265DD->setObjectName(QString::fromUtf8("Preset265DD"));
        Preset265DD->setGeometry(QRect(144, 180, 99, 22));
        Quantizer265Label = new QLabel(EncodingSetting265GB);
        Quantizer265Label->setObjectName(QString::fromUtf8("Quantizer265Label"));
        Quantizer265Label->setGeometry(QRect(19, 118, 125, 16));
        Quantizer265NUD = new QSpinBox(EncodingSetting265GB);
        Quantizer265NUD->setObjectName(QString::fromUtf8("Quantizer265NUD"));
        Quantizer265NUD->setGeometry(QRect(200, 116, 43, 22));
        Quantizer265NUD->setMaximum(51);
        Quantizer265NUD->setValue(22);
        CRFValue265NUD = new QSpinBox(EncodingSetting265GB);
        CRFValue265NUD->setObjectName(QString::fromUtf8("CRFValue265NUD"));
        CRFValue265NUD->setGeometry(QRect(200, 116, 43, 22));
        CRFValue265NUD->setMaximum(51);
        CRFValue265NUD->setValue(22);
        CRFValue265Label = new QLabel(EncodingSetting265GB);
        CRFValue265Label->setObjectName(QString::fromUtf8("CRFValue265Label"));
        CRFValue265Label->setGeometry(QRect(19, 118, 79, 16));
        EncodeMode265HWDD = new QComboBox(EncodingSetting265GB);
        EncodeMode265HWDD->addItem(QString());
        EncodeMode265HWDD->addItem(QString());
        EncodeMode265HWDD->addItem(QString());
        EncodeMode265HWDD->setObjectName(QString::fromUtf8("EncodeMode265HWDD"));
        EncodeMode265HWDD->setGeometry(QRect(56, 22, 187, 22));
        Bitrate265Label = new QLabel(EncodingSetting265GB);
        Bitrate265Label->setObjectName(QString::fromUtf8("Bitrate265Label"));
        Bitrate265Label->setGeometry(QRect(19, 118, 79, 16));
        FastPass265Label = new QLabel(EncodingSetting265GB);
        FastPass265Label->setObjectName(QString::fromUtf8("FastPass265Label"));
        FastPass265Label->setGeometry(QRect(19, 86, 79, 16));
        FastPass265CB = new QCheckBox(EncodingSetting265GB);
        FastPass265CB->setObjectName(QString::fromUtf8("FastPass265CB"));
        FastPass265CB->setGeometry(QRect(229, 86, 18, 20));
        x265Tabs->addTab(Main265Tab, QString());
        Fames265Tab = new QWidget();
        Fames265Tab->setObjectName(QString::fromUtf8("Fames265Tab"));
        RefFrames265GB = new QGroupBox(Fames265Tab);
        RefFrames265GB->setObjectName(QString::fromUtf8("RefFrames265GB"));
        RefFrames265GB->setGeometry(QRect(12, 7, 260, 76));
        RefFrames265GB->setAlignment(Qt::AlignCenter);
        RefFrames265GB->setCheckable(true);
        RefFrames265GB->setChecked(false);
        Reference265Sldr = new QSlider(RefFrames265GB);
        Reference265Sldr->setObjectName(QString::fromUtf8("Reference265Sldr"));
        Reference265Sldr->setGeometry(QRect(15, 31, 178, 24));
        Reference265Sldr->setMaximum(8);
        Reference265Sldr->setValue(2);
        Reference265Sldr->setOrientation(Qt::Horizontal);
        Reference265LED = new QLCDNumber(RefFrames265GB);
        Reference265LED->setObjectName(QString::fromUtf8("Reference265LED"));
        Reference265LED->setGeometry(QRect(205, 24, 42, 36));
        Reference265LED->setDigitCount(2);
        Reference265LED->setMode(QLCDNumber::Dec);
        Reference265LED->setSegmentStyle(QLCDNumber::Flat);
        Reference265LED->setProperty("value", QVariant(2.000000000000000));
        BFrames265GB = new QGroupBox(Fames265Tab);
        BFrames265GB->setObjectName(QString::fromUtf8("BFrames265GB"));
        BFrames265GB->setGeometry(QRect(287, 7, 237, 76));
        BFrames265GB->setAlignment(Qt::AlignCenter);
        BFrames265GB->setCheckable(true);
        BFrames265GB->setChecked(false);
        BFrame265Sldr = new QSlider(BFrames265GB);
        BFrame265Sldr->setObjectName(QString::fromUtf8("BFrame265Sldr"));
        BFrame265Sldr->setGeometry(QRect(14, 31, 155, 24));
        BFrame265Sldr->setMaximum(16);
        BFrame265Sldr->setValue(4);
        BFrame265Sldr->setOrientation(Qt::Horizontal);
        Bframe265LED = new QLCDNumber(BFrames265GB);
        Bframe265LED->setObjectName(QString::fromUtf8("Bframe265LED"));
        Bframe265LED->setGeometry(QRect(181, 24, 41, 36));
        Bframe265LED->setDigitCount(2);
        Bframe265LED->setMode(QLCDNumber::Dec);
        Bframe265LED->setSegmentStyle(QLCDNumber::Flat);
        Bframe265LED->setProperty("value", QVariant(4.000000000000000));
        x265Tabs->addTab(Fames265Tab, QString());
        VideoTabs->addTab(x265Tab, QString());
        ProResTab = new QWidget();
        ProResTab->setObjectName(QString::fromUtf8("ProResTab"));
        EncodingProResGB = new QGroupBox(ProResTab);
        EncodingProResGB->setObjectName(QString::fromUtf8("EncodingProResGB"));
        EncodingProResGB->setGeometry(QRect(12, 6, 523, 57));
        EncodingProResGB->setAlignment(Qt::AlignCenter);
        ProfileLabel = new QLabel(EncodingProResGB);
        ProfileLabel->setObjectName(QString::fromUtf8("ProfileLabel"));
        ProfileLabel->setGeometry(QRect(18, 23, 49, 18));
        ProfileDD = new QComboBox(EncodingProResGB);
        ProfileDD->addItem(QString());
        ProfileDD->addItem(QString());
        ProfileDD->addItem(QString());
        ProfileDD->addItem(QString());
        ProfileDD->addItem(QString());
        ProfileDD->addItem(QString());
        ProfileDD->setObjectName(QString::fromUtf8("ProfileDD"));
        ProfileDD->setGeometry(QRect(413, 21, 93, 22));
        ColorsGB = new QGroupBox(ProResTab);
        ColorsGB->setObjectName(QString::fromUtf8("ColorsGB"));
        ColorsGB->setGeometry(QRect(12, 68, 523, 112));
        ColorsGB->setAlignment(Qt::AlignCenter);
        ColorsGB->setCheckable(true);
        ColorsGB->setChecked(false);
        MatrixProResLabel = new QLabel(ColorsGB);
        MatrixProResLabel->setObjectName(QString::fromUtf8("MatrixProResLabel"));
        MatrixProResLabel->setGeometry(QRect(19, 18, 43, 27));
        MatrixProResDD = new QComboBox(ColorsGB);
        MatrixProResDD->addItem(QString());
        MatrixProResDD->addItem(QString());
        MatrixProResDD->addItem(QString());
        MatrixProResDD->addItem(QString());
        MatrixProResDD->addItem(QString());
        MatrixProResDD->setObjectName(QString::fromUtf8("MatrixProResDD"));
        MatrixProResDD->setGeometry(QRect(401, 21, 105, 22));
        TransferProResLabel = new QLabel(ColorsGB);
        TransferProResLabel->setObjectName(QString::fromUtf8("TransferProResLabel"));
        TransferProResLabel->setGeometry(QRect(19, 49, 50, 22));
        TransferProResDD = new QComboBox(ColorsGB);
        TransferProResDD->addItem(QString());
        TransferProResDD->addItem(QString());
        TransferProResDD->addItem(QString());
        TransferProResDD->addItem(QString());
        TransferProResDD->addItem(QString());
        TransferProResDD->setObjectName(QString::fromUtf8("TransferProResDD"));
        TransferProResDD->setGeometry(QRect(401, 50, 105, 22));
        PrimariesProResLabel = new QLabel(ColorsGB);
        PrimariesProResLabel->setObjectName(QString::fromUtf8("PrimariesProResLabel"));
        PrimariesProResLabel->setGeometry(QRect(19, 78, 55, 20));
        PrimairesProResDD = new QComboBox(ColorsGB);
        PrimairesProResDD->addItem(QString());
        PrimairesProResDD->addItem(QString());
        PrimairesProResDD->addItem(QString());
        PrimairesProResDD->addItem(QString());
        PrimairesProResDD->addItem(QString());
        PrimairesProResDD->addItem(QString());
        PrimairesProResDD->setObjectName(QString::fromUtf8("PrimairesProResDD"));
        PrimairesProResDD->setGeometry(QRect(401, 79, 105, 22));
        VideoTabs->addTab(ProResTab, QString());
        TheoraTab = new QWidget();
        TheoraTab->setObjectName(QString::fromUtf8("TheoraTab"));
        EncodeTheoraGB = new QGroupBox(TheoraTab);
        EncodeTheoraGB->setObjectName(QString::fromUtf8("EncodeTheoraGB"));
        EncodeTheoraGB->setGeometry(QRect(12, 6, 523, 90));
        EncodeTheoraGB->setAlignment(Qt::AlignCenter);
        QualityLabel = new QLabel(EncodeTheoraGB);
        QualityLabel->setObjectName(QString::fromUtf8("QualityLabel"));
        QualityLabel->setGeometry(QRect(18, 55, 51, 23));
        QualityNUD = new QSpinBox(EncodeTheoraGB);
        QualityNUD->setObjectName(QString::fromUtf8("QualityNUD"));
        QualityNUD->setGeometry(QRect(462, 56, 43, 22));
        QualityNUD->setMaximum(10);
        QualityNUD->setValue(6);
        EncodeModeTLabel = new QLabel(EncodeTheoraGB);
        EncodeModeTLabel->setObjectName(QString::fromUtf8("EncodeModeTLabel"));
        EncodeModeTLabel->setGeometry(QRect(18, 24, 38, 16));
        EncodeModeTDD = new QComboBox(EncodeTheoraGB);
        EncodeModeTDD->addItem(QString());
        EncodeModeTDD->addItem(QString());
        EncodeModeTDD->setObjectName(QString::fromUtf8("EncodeModeTDD"));
        EncodeModeTDD->setGeometry(QRect(336, 22, 169, 22));
        BitrateThLabel = new QLabel(EncodeTheoraGB);
        BitrateThLabel->setObjectName(QString::fromUtf8("BitrateThLabel"));
        BitrateThLabel->setGeometry(QRect(18, 59, 88, 16));
        BitrateThNUD = new QSpinBox(EncodeTheoraGB);
        BitrateThNUD->setObjectName(QString::fromUtf8("BitrateThNUD"));
        BitrateThNUD->setGeometry(QRect(441, 56, 64, 22));
        BitrateThNUD->setMinimum(500);
        BitrateThNUD->setMaximum(60000);
        BitrateThNUD->setValue(1500);
        VideoTabs->addTab(TheoraTab, QString());
        VPXTab = new QWidget();
        VPXTab->setObjectName(QString::fromUtf8("VPXTab"));
        EncodingSettingVPXGB = new QGroupBox(VPXTab);
        EncodingSettingVPXGB->setObjectName(QString::fromUtf8("EncodingSettingVPXGB"));
        EncodingSettingVPXGB->setGeometry(QRect(12, 6, 266, 122));
        EncodingSettingVPXGB->setAlignment(Qt::AlignCenter);
        EncodeModeVPXLabel = new QLabel(EncodingSettingVPXGB);
        EncodeModeVPXLabel->setObjectName(QString::fromUtf8("EncodeModeVPXLabel"));
        EncodeModeVPXLabel->setGeometry(QRect(18, 24, 39, 16));
        EncodeModeVPXDD = new QComboBox(EncodingSettingVPXGB);
        EncodeModeVPXDD->addItem(QString());
        EncodeModeVPXDD->addItem(QString());
        EncodeModeVPXDD->addItem(QString());
        EncodeModeVPXDD->setObjectName(QString::fromUtf8("EncodeModeVPXDD"));
        EncodeModeVPXDD->setGeometry(QRect(65, 22, 183, 22));
        BitrateVPXNUD = new QDoubleSpinBox(EncodingSettingVPXGB);
        BitrateVPXNUD->setObjectName(QString::fromUtf8("BitrateVPXNUD"));
        BitrateVPXNUD->setGeometry(QRect(176, 87, 72, 22));
        BitrateVPXNUD->setDecimals(0);
        BitrateVPXNUD->setMaximum(80000.000000000000000);
        BitrateVPXNUD->setValue(2000.000000000000000);
        crfVPXNUD = new QSpinBox(EncodingSettingVPXGB);
        crfVPXNUD->setObjectName(QString::fromUtf8("crfVPXNUD"));
        crfVPXNUD->setGeometry(QRect(205, 87, 43, 22));
        crfVPXNUD->setMaximum(63);
        crfVPXNUD->setValue(22);
        crfVPXLabel = new QLabel(EncodingSettingVPXGB);
        crfVPXLabel->setObjectName(QString::fromUtf8("crfVPXLabel"));
        crfVPXLabel->setGeometry(QRect(18, 89, 73, 16));
        BitrateVPXLabel = new QLabel(EncodingSettingVPXGB);
        BitrateVPXLabel->setObjectName(QString::fromUtf8("BitrateVPXLabel"));
        BitrateVPXLabel->setGeometry(QRect(19, 90, 61, 16));
        ProfileVPXGB = new QGroupBox(VPXTab);
        ProfileVPXGB->setObjectName(QString::fromUtf8("ProfileVPXGB"));
        ProfileVPXGB->setGeometry(QRect(292, 6, 243, 89));
        ProfileVPXGB->setAlignment(Qt::AlignCenter);
        ProfileVPXGB->setCheckable(false);
        ProfileVPXGB->setChecked(false);
        Profile264Label_2 = new QLabel(ProfileVPXGB);
        Profile264Label_2->setObjectName(QString::fromUtf8("Profile264Label_2"));
        Profile264Label_2->setGeometry(QRect(17, 21, 45, 20));
        ProfileVPXDD = new QComboBox(ProfileVPXGB);
        ProfileVPXDD->addItem(QString());
        ProfileVPXDD->addItem(QString());
        ProfileVPXDD->addItem(QString());
        ProfileVPXDD->addItem(QString());
        ProfileVPXDD->setObjectName(QString::fromUtf8("ProfileVPXDD"));
        ProfileVPXDD->setGeometry(QRect(147, 21, 79, 22));
        SpeedLabel = new QLabel(ProfileVPXGB);
        SpeedLabel->setObjectName(QString::fromUtf8("SpeedLabel"));
        SpeedLabel->setGeometry(QRect(17, 54, 50, 20));
        SpeedDD = new QComboBox(ProfileVPXGB);
        SpeedDD->addItem(QString());
        SpeedDD->addItem(QString());
        SpeedDD->setObjectName(QString::fromUtf8("SpeedDD"));
        SpeedDD->setGeometry(QRect(147, 54, 79, 22));
        ColorsVPXGB = new QGroupBox(VPXTab);
        ColorsVPXGB->setObjectName(QString::fromUtf8("ColorsVPXGB"));
        ColorsVPXGB->setGeometry(QRect(292, 100, 243, 89));
        ColorsVPXGB->setAlignment(Qt::AlignCenter);
        ColorsVPXGB->setCheckable(false);
        ColorsVPXGB->setChecked(false);
        BitDepthVPXLabel = new QLabel(ColorsVPXGB);
        BitDepthVPXLabel->setObjectName(QString::fromUtf8("BitDepthVPXLabel"));
        BitDepthVPXLabel->setGeometry(QRect(17, 22, 55, 20));
        BitDepthVPXDD = new QComboBox(ColorsVPXGB);
        BitDepthVPXDD->addItem(QString());
        BitDepthVPXDD->addItem(QString());
        BitDepthVPXDD->setObjectName(QString::fromUtf8("BitDepthVPXDD"));
        BitDepthVPXDD->setGeometry(QRect(165, 21, 61, 22));
        SampleVPXLabel = new QLabel(ColorsVPXGB);
        SampleVPXLabel->setObjectName(QString::fromUtf8("SampleVPXLabel"));
        SampleVPXLabel->setGeometry(QRect(17, 51, 92, 26));
        SampleVPXDD = new QComboBox(ColorsVPXGB);
        SampleVPXDD->addItem(QString());
        SampleVPXDD->addItem(QString());
        SampleVPXDD->setObjectName(QString::fromUtf8("SampleVPXDD"));
        SampleVPXDD->setGeometry(QRect(165, 53, 61, 22));
        VideoTabs->addTab(VPXTab, QString());
        av1Tab = new QWidget();
        av1Tab->setObjectName(QString::fromUtf8("av1Tab"));
        EncodingSettingAV1GB = new QGroupBox(av1Tab);
        EncodingSettingAV1GB->setObjectName(QString::fromUtf8("EncodingSettingAV1GB"));
        EncodingSettingAV1GB->setGeometry(QRect(12, 6, 266, 122));
        EncodingSettingAV1GB->setAlignment(Qt::AlignCenter);
        EncodeModeAV1Label = new QLabel(EncodingSettingAV1GB);
        EncodeModeAV1Label->setObjectName(QString::fromUtf8("EncodeModeAV1Label"));
        EncodeModeAV1Label->setGeometry(QRect(18, 24, 39, 16));
        EncodeModeAV1DD = new QComboBox(EncodingSettingAV1GB);
        EncodeModeAV1DD->addItem(QString());
        EncodeModeAV1DD->addItem(QString());
        EncodeModeAV1DD->setObjectName(QString::fromUtf8("EncodeModeAV1DD"));
        EncodeModeAV1DD->setGeometry(QRect(65, 22, 183, 22));
        BitrateAV1NUD = new QDoubleSpinBox(EncodingSettingAV1GB);
        BitrateAV1NUD->setObjectName(QString::fromUtf8("BitrateAV1NUD"));
        BitrateAV1NUD->setGeometry(QRect(176, 87, 72, 22));
        BitrateAV1NUD->setDecimals(0);
        BitrateAV1NUD->setMaximum(80000.000000000000000);
        BitrateAV1NUD->setValue(2000.000000000000000);
        crfAV1NUD = new QSpinBox(EncodingSettingAV1GB);
        crfAV1NUD->setObjectName(QString::fromUtf8("crfAV1NUD"));
        crfAV1NUD->setGeometry(QRect(205, 87, 43, 22));
        crfAV1NUD->setMaximum(63);
        crfAV1NUD->setValue(22);
        crfAV1Label = new QLabel(EncodingSettingAV1GB);
        crfAV1Label->setObjectName(QString::fromUtf8("crfAV1Label"));
        crfAV1Label->setGeometry(QRect(18, 89, 73, 16));
        BitrateAV1Label = new QLabel(EncodingSettingAV1GB);
        BitrateAV1Label->setObjectName(QString::fromUtf8("BitrateAV1Label"));
        BitrateAV1Label->setGeometry(QRect(19, 90, 61, 16));
        ColorsAV1GB = new QGroupBox(av1Tab);
        ColorsAV1GB->setObjectName(QString::fromUtf8("ColorsAV1GB"));
        ColorsAV1GB->setGeometry(QRect(292, 6, 243, 58));
        ColorsAV1GB->setAlignment(Qt::AlignCenter);
        ColorsAV1GB->setCheckable(false);
        ColorsAV1GB->setChecked(false);
        BitDepthAV1Label = new QLabel(ColorsAV1GB);
        BitDepthAV1Label->setObjectName(QString::fromUtf8("BitDepthAV1Label"));
        BitDepthAV1Label->setGeometry(QRect(17, 22, 55, 20));
        BitDepthAV1DD = new QComboBox(ColorsAV1GB);
        BitDepthAV1DD->addItem(QString());
        BitDepthAV1DD->addItem(QString());
        BitDepthAV1DD->setObjectName(QString::fromUtf8("BitDepthAV1DD"));
        BitDepthAV1DD->setGeometry(QRect(165, 21, 61, 22));
        VideoTabs->addTab(av1Tab, QString());
        HDRTab = new QWidget();
        HDRTab->setObjectName(QString::fromUtf8("HDRTab"));
        SignalsTabs = new QTabWidget(HDRTab);
        SignalsTabs->setObjectName(QString::fromUtf8("SignalsTabs"));
        SignalsTabs->setGeometry(QRect(3, 2, 543, 256));
        HDRTab1 = new QWidget();
        HDRTab1->setObjectName(QString::fromUtf8("HDRTab1"));
        HDRMetadataGB = new QGroupBox(HDRTab1);
        HDRMetadataGB->setObjectName(QString::fromUtf8("HDRMetadataGB"));
        HDRMetadataGB->setGeometry(QRect(12, 7, 512, 114));
        HDRMetadataGB->setAlignment(Qt::AlignCenter);
        HDRMetadataGB->setCheckable(true);
        HDRMetadataGB->setChecked(false);
        LightLevelLabel = new QLabel(HDRMetadataGB);
        LightLevelLabel->setObjectName(QString::fromUtf8("LightLevelLabel"));
        LightLevelLabel->setGeometry(QRect(17, 25, 156, 16));
        Slash6Label = new QLabel(HDRMetadataGB);
        Slash6Label->setObjectName(QString::fromUtf8("Slash6Label"));
        Slash6Label->setGeometry(QRect(424, 25, 16, 16));
        MaxCllNUD = new QSpinBox(HDRMetadataGB);
        MaxCllNUD->setObjectName(QString::fromUtf8("MaxCllNUD"));
        MaxCllNUD->setGeometry(QRect(357, 22, 62, 22));
        MaxCllNUD->setMinimum(0);
        MaxCllNUD->setMaximum(65535);
        MaxCllNUD->setValue(1000);
        MaxFallNUD = new QSpinBox(HDRMetadataGB);
        MaxFallNUD->setObjectName(QString::fromUtf8("MaxFallNUD"));
        MaxFallNUD->setGeometry(QRect(435, 22, 62, 22));
        MaxFallNUD->setMinimum(0);
        MaxFallNUD->setMaximum(65535);
        MaxFallNUD->setValue(1);
        MasterDisplayLabel = new QLabel(HDRMetadataGB);
        MasterDisplayLabel->setObjectName(QString::fromUtf8("MasterDisplayLabel"));
        MasterDisplayLabel->setGeometry(QRect(17, 52, 87, 16));
        MasterDisplayTxtBox = new QLineEdit(HDRMetadataGB);
        MasterDisplayTxtBox->setObjectName(QString::fromUtf8("MasterDisplayTxtBox"));
        MasterDisplayTxtBox->setGeometry(QRect(102, 51, 394, 21));
        DynamicMetadataLabel = new QLabel(HDRMetadataGB);
        DynamicMetadataLabel->setObjectName(QString::fromUtf8("DynamicMetadataLabel"));
        DynamicMetadataLabel->setGeometry(QRect(17, 76, 105, 24));
        DynamicMetadataBttn = new QPushButton(HDRMetadataGB);
        DynamicMetadataBttn->setObjectName(QString::fromUtf8("DynamicMetadataBttn"));
        DynamicMetadataBttn->setGeometry(QRect(411, 78, 86, 23));
        DynamicHDRTxtBox = new QLineEdit(HDRMetadataGB);
        DynamicHDRTxtBox->setObjectName(QString::fromUtf8("DynamicHDRTxtBox"));
        DynamicHDRTxtBox->setGeometry(QRect(123, 79, 284, 21));
        DynamicHDRTxtBox->setReadOnly(true);
        DBVisionGB = new QGroupBox(HDRTab1);
        DBVisionGB->setObjectName(QString::fromUtf8("DBVisionGB"));
        DBVisionGB->setGeometry(QRect(12, 127, 512, 88));
        DBVisionGB->setAlignment(Qt::AlignCenter);
        DBVisionGB->setCheckable(true);
        DBVisionGB->setChecked(false);
        DBProfileLabel = new QLabel(DBVisionGB);
        DBProfileLabel->setObjectName(QString::fromUtf8("DBProfileLabel"));
        DBProfileLabel->setGeometry(QRect(18, 23, 49, 16));
        RpuLabel = new QLabel(DBVisionGB);
        RpuLabel->setObjectName(QString::fromUtf8("RpuLabel"));
        RpuLabel->setGeometry(QRect(18, 53, 49, 16));
        DBProfileDD = new QComboBox(DBVisionGB);
        DBProfileDD->addItem(QString());
        DBProfileDD->addItem(QString());
        DBProfileDD->addItem(QString());
        DBProfileDD->setObjectName(QString::fromUtf8("DBProfileDD"));
        DBProfileDD->setGeometry(QRect(447, 21, 49, 22));
        RpuTxtBox = new QLineEdit(DBVisionGB);
        RpuTxtBox->setObjectName(QString::fromUtf8("RpuTxtBox"));
        RpuTxtBox->setGeometry(QRect(71, 52, 281, 21));
        RpuTxtBox->setReadOnly(true);
        RpuFileBttn = new QPushButton(DBVisionGB);
        RpuFileBttn->setObjectName(QString::fromUtf8("RpuFileBttn"));
        RpuFileBttn->setGeometry(QRect(356, 51, 141, 23));
        SignalsTabs->addTab(HDRTab1, QString());
        Colors3Tab = new QWidget();
        Colors3Tab->setObjectName(QString::fromUtf8("Colors3Tab"));
        ColorsHDRGB = new QGroupBox(Colors3Tab);
        ColorsHDRGB->setObjectName(QString::fromUtf8("ColorsHDRGB"));
        ColorsHDRGB->setGeometry(QRect(12, 7, 512, 161));
        ColorsHDRGB->setAlignment(Qt::AlignCenter);
        ColorsHDRGB->setCheckable(true);
        ColorsHDRGB->setChecked(false);
        ColorRangeLabel = new QLabel(ColorsHDRGB);
        ColorRangeLabel->setObjectName(QString::fromUtf8("ColorRangeLabel"));
        ColorRangeLabel->setGeometry(QRect(17, 22, 69, 24));
        ColorMatrixLabel = new QLabel(ColorsHDRGB);
        ColorMatrixLabel->setObjectName(QString::fromUtf8("ColorMatrixLabel"));
        ColorMatrixLabel->setGeometry(QRect(17, 59, 72, 16));
        ColorTransferDD = new QComboBox(ColorsHDRGB);
        ColorTransferDD->addItem(QString());
        ColorTransferDD->addItem(QString());
        ColorTransferDD->addItem(QString());
        ColorTransferDD->addItem(QString());
        ColorTransferDD->addItem(QString());
        ColorTransferDD->addItem(QString());
        ColorTransferDD->addItem(QString());
        ColorTransferDD->addItem(QString());
        ColorTransferDD->addItem(QString());
        ColorTransferDD->addItem(QString());
        ColorTransferDD->setObjectName(QString::fromUtf8("ColorTransferDD"));
        ColorTransferDD->setGeometry(QRect(398, 88, 97, 22));
        ColorPrimariesLabel = new QLabel(ColorsHDRGB);
        ColorPrimariesLabel->setObjectName(QString::fromUtf8("ColorPrimariesLabel"));
        ColorPrimariesLabel->setGeometry(QRect(17, 121, 89, 20));
        ColorTransferLabel = new QLabel(ColorsHDRGB);
        ColorTransferLabel->setObjectName(QString::fromUtf8("ColorTransferLabel"));
        ColorTransferLabel->setGeometry(QRect(17, 88, 85, 22));
        ColorRangeDD = new QComboBox(ColorsHDRGB);
        ColorRangeDD->addItem(QString());
        ColorRangeDD->addItem(QString());
        ColorRangeDD->setObjectName(QString::fromUtf8("ColorRangeDD"));
        ColorRangeDD->setGeometry(QRect(398, 22, 97, 22));
        ColorMatrixDD = new QComboBox(ColorsHDRGB);
        ColorMatrixDD->addItem(QString());
        ColorMatrixDD->addItem(QString());
        ColorMatrixDD->addItem(QString());
        ColorMatrixDD->addItem(QString());
        ColorMatrixDD->addItem(QString());
        ColorMatrixDD->addItem(QString());
        ColorMatrixDD->addItem(QString());
        ColorMatrixDD->addItem(QString());
        ColorMatrixDD->addItem(QString());
        ColorMatrixDD->addItem(QString());
        ColorMatrixDD->setObjectName(QString::fromUtf8("ColorMatrixDD"));
        ColorMatrixDD->setGeometry(QRect(398, 55, 97, 22));
        ColorPrimariesDD = new QComboBox(ColorsHDRGB);
        ColorPrimariesDD->addItem(QString());
        ColorPrimariesDD->addItem(QString());
        ColorPrimariesDD->addItem(QString());
        ColorPrimariesDD->addItem(QString());
        ColorPrimariesDD->addItem(QString());
        ColorPrimariesDD->addItem(QString());
        ColorPrimariesDD->addItem(QString());
        ColorPrimariesDD->addItem(QString());
        ColorPrimariesDD->addItem(QString());
        ColorPrimariesDD->addItem(QString());
        ColorPrimariesDD->setObjectName(QString::fromUtf8("ColorPrimariesDD"));
        ColorPrimariesDD->setGeometry(QRect(398, 121, 97, 22));
        SignalsTabs->addTab(Colors3Tab, QString());
        VideoTabs->addTab(HDRTab, QString());
        VSTab = new QWidget();
        VSTab->setObjectName(QString::fromUtf8("VSTab"));
        VSTabs = new QTabWidget(VSTab);
        VSTabs->setObjectName(QString::fromUtf8("VSTabs"));
        VSTabs->setGeometry(QRect(3, 2, 542, 257));
        InterpolationTab = new QWidget();
        InterpolationTab->setObjectName(QString::fromUtf8("InterpolationTab"));
        InterpolationCB = new QGroupBox(InterpolationTab);
        InterpolationCB->setObjectName(QString::fromUtf8("InterpolationCB"));
        InterpolationCB->setGeometry(QRect(12, 7, 512, 212));
        InterpolationCB->setAlignment(Qt::AlignCenter);
        InterpolationCB->setCheckable(true);
        InterpolationCB->setChecked(false);
        ToolInterpDD = new QComboBox(InterpolationCB);
        ToolInterpDD->addItem(QString());
        ToolInterpDD->addItem(QString());
        ToolInterpDD->addItem(QString());
        ToolInterpDD->setObjectName(QString::fromUtf8("ToolInterpDD"));
        ToolInterpDD->setGeometry(QRect(275, 25, 97, 22));
        ToolInterpLabel = new QLabel(InterpolationCB);
        ToolInterpLabel->setObjectName(QString::fromUtf8("ToolInterpLabel"));
        ToolInterpLabel->setGeometry(QRect(23, 28, 130, 16));
        UseGPUCB = new QCheckBox(InterpolationCB);
        UseGPUCB->setObjectName(QString::fromUtf8("UseGPUCB"));
        UseGPUCB->setGeometry(QRect(23, 56, 75, 20));
        GPUInterpDD = new QComboBox(InterpolationCB);
        GPUInterpDD->setObjectName(QString::fromUtf8("GPUInterpDD"));
        GPUInterpDD->setEnabled(false);
        GPUInterpDD->setGeometry(QRect(93, 56, 242, 22));
        GPUThreadInterpLabel = new QLabel(InterpolationCB);
        GPUThreadInterpLabel->setObjectName(QString::fromUtf8("GPUThreadInterpLabel"));
        GPUThreadInterpLabel->setEnabled(false);
        GPUThreadInterpLabel->setGeometry(QRect(383, 56, 71, 20));
        GPUThreadDD = new QComboBox(InterpolationCB);
        GPUThreadDD->addItem(QString());
        GPUThreadDD->addItem(QString());
        GPUThreadDD->addItem(QString());
        GPUThreadDD->addItem(QString());
        GPUThreadDD->setObjectName(QString::fromUtf8("GPUThreadDD"));
        GPUThreadDD->setEnabled(false);
        GPUThreadDD->setGeometry(QRect(454, 56, 37, 22));
        ModelInterpLabel = new QLabel(InterpolationCB);
        ModelInterpLabel->setObjectName(QString::fromUtf8("ModelInterpLabel"));
        ModelInterpLabel->setGeometry(QRect(23, 88, 52, 16));
        ModelInterpDD = new QComboBox(InterpolationCB);
        ModelInterpDD->addItem(QString());
        ModelInterpDD->addItem(QString());
        ModelInterpDD->addItem(QString());
        ModelInterpDD->setObjectName(QString::fromUtf8("ModelInterpDD"));
        ModelInterpDD->setGeometry(QRect(422, 87, 69, 22));
        SceneChangeCB = new QCheckBox(InterpolationCB);
        SceneChangeCB->setObjectName(QString::fromUtf8("SceneChangeCB"));
        SceneChangeCB->setGeometry(QRect(477, 119, 25, 20));
        SceneChangeCB->setChecked(true);
        OutputFPSNUD = new QDoubleSpinBox(InterpolationCB);
        OutputFPSNUD->setObjectName(QString::fromUtf8("OutputFPSNUD"));
        OutputFPSNUD->setGeometry(QRect(423, 176, 68, 22));
        OutputFPSNUD->setDecimals(3);
        OutputFPSNUD->setMinimum(10.000000000000000);
        OutputFPSNUD->setMaximum(780.000000000000000);
        OutputFPSNUD->setValue(60.000000000000000);
        OutFPSLabel = new QLabel(InterpolationCB);
        OutFPSLabel->setObjectName(QString::fromUtf8("OutFPSLabel"));
        OutFPSLabel->setGeometry(QRect(23, 178, 69, 16));
        SceneChangeLabel = new QLabel(InterpolationCB);
        SceneChangeLabel->setObjectName(QString::fromUtf8("SceneChangeLabel"));
        SceneChangeLabel->setGeometry(QRect(23, 118, 195, 16));
        BackendDD = new QComboBox(InterpolationCB);
        BackendDD->addItem(QString());
        BackendDD->addItem(QString());
        BackendDD->addItem(QString());
        BackendDD->setObjectName(QString::fromUtf8("BackendDD"));
        BackendDD->setGeometry(QRect(386, 25, 105, 22));
        SlashLabel = new QLabel(InterpolationCB);
        SlashLabel->setObjectName(QString::fromUtf8("SlashLabel"));
        SlashLabel->setGeometry(QRect(376, 28, 19, 16));
        SlashLabel->setFont(font);
        ShaderLabel = new QLabel(InterpolationCB);
        ShaderLabel->setObjectName(QString::fromUtf8("ShaderLabel"));
        ShaderLabel->setGeometry(QRect(23, 88, 49, 16));
        RIFEModelVKDD = new QComboBox(InterpolationCB);
        RIFEModelVKDD->addItem(QString());
        RIFEModelVKDD->addItem(QString());
        RIFEModelVKDD->addItem(QString());
        RIFEModelVKDD->addItem(QString());
        RIFEModelVKDD->addItem(QString());
        RIFEModelVKDD->addItem(QString());
        RIFEModelVKDD->setObjectName(QString::fromUtf8("RIFEModelVKDD"));
        RIFEModelVKDD->setGeometry(QRect(436, 87, 55, 22));
        RIFEModelCADD = new QComboBox(InterpolationCB);
        RIFEModelCADD->addItem(QString());
        RIFEModelCADD->addItem(QString());
        RIFEModelCADD->setObjectName(QString::fromUtf8("RIFEModelCADD"));
        RIFEModelCADD->setGeometry(QRect(437, 87, 54, 22));
        ShaderDD = new QComboBox(InterpolationCB);
        ShaderDD->addItem(QString());
        ShaderDD->addItem(QString());
        ShaderDD->addItem(QString());
        ShaderDD->addItem(QString());
        ShaderDD->addItem(QString());
        ShaderDD->addItem(QString());
        ShaderDD->setObjectName(QString::fromUtf8("ShaderDD"));
        ShaderDD->setGeometry(QRect(447, 87, 44, 22));
        ParamsCB = new QCheckBox(InterpolationCB);
        ParamsCB->setObjectName(QString::fromUtf8("ParamsCB"));
        ParamsCB->setGeometry(QRect(379, 57, 118, 20));
        EqualsLabel = new QLabel(InterpolationCB);
        EqualsLabel->setObjectName(QString::fromUtf8("EqualsLabel"));
        EqualsLabel->setGeometry(QRect(408, 179, 21, 16));
        InterpModeLabel = new QLabel(InterpolationCB);
        InterpModeLabel->setObjectName(QString::fromUtf8("InterpModeLabel"));
        InterpModeLabel->setGeometry(QRect(23, 117, 113, 16));
        InterpModeDD = new QComboBox(InterpolationCB);
        InterpModeDD->addItem(QString());
        InterpModeDD->addItem(QString());
        InterpModeDD->addItem(QString());
        InterpModeDD->addItem(QString());
        InterpModeDD->setObjectName(QString::fromUtf8("InterpModeDD"));
        InterpModeDD->setGeometry(QRect(419, 116, 72, 22));
        ArtefactMaskLabel = new QLabel(InterpolationCB);
        ArtefactMaskLabel->setObjectName(QString::fromUtf8("ArtefactMaskLabel"));
        ArtefactMaskLabel->setGeometry(QRect(23, 147, 98, 16));
        ArtefactMaskDD = new QComboBox(InterpolationCB);
        ArtefactMaskDD->addItem(QString());
        ArtefactMaskDD->addItem(QString());
        ArtefactMaskDD->addItem(QString());
        ArtefactMaskDD->addItem(QString());
        ArtefactMaskDD->setObjectName(QString::fromUtf8("ArtefactMaskDD"));
        ArtefactMaskDD->setGeometry(QRect(419, 145, 72, 22));
        SuperTxtBox = new QLineEdit(InterpolationCB);
        SuperTxtBox->setObjectName(QString::fromUtf8("SuperTxtBox"));
        SuperTxtBox->setGeometry(QRect(113, 88, 378, 21));
        SuperLabel = new QLabel(InterpolationCB);
        SuperLabel->setObjectName(QString::fromUtf8("SuperLabel"));
        SuperLabel->setGeometry(QRect(23, 89, 74, 16));
        AnalyseLabel = new QLabel(InterpolationCB);
        AnalyseLabel->setObjectName(QString::fromUtf8("AnalyseLabel"));
        AnalyseLabel->setGeometry(QRect(23, 119, 57, 16));
        AnalyseTxtBox = new QLineEdit(InterpolationCB);
        AnalyseTxtBox->setObjectName(QString::fromUtf8("AnalyseTxtBox"));
        AnalyseTxtBox->setGeometry(QRect(113, 118, 378, 21));
        SmoothLabel = new QLabel(InterpolationCB);
        SmoothLabel->setObjectName(QString::fromUtf8("SmoothLabel"));
        SmoothLabel->setGeometry(QRect(23, 149, 67, 16));
        SmoothTxtBox = new QLineEdit(InterpolationCB);
        SmoothTxtBox->setObjectName(QString::fromUtf8("SmoothTxtBox"));
        SmoothTxtBox->setGeometry(QRect(113, 148, 378, 21));
        Times2Label = new QLabel(InterpolationCB);
        Times2Label->setObjectName(QString::fromUtf8("Times2Label"));
        Times2Label->setGeometry(QRect(390, 179, 23, 16));
        SCThresholdNUD = new QDoubleSpinBox(InterpolationCB);
        SCThresholdNUD->setObjectName(QString::fromUtf8("SCThresholdNUD"));
        SCThresholdNUD->setEnabled(false);
        SCThresholdNUD->setGeometry(QRect(442, 147, 49, 22));
        SCThresholdNUD->setMaximum(1.000000000000000);
        SCThresholdNUD->setSingleStep(0.010000000000000);
        SCThresholdNUD->setValue(0.120000000000000);
        SCThresholdLabel = new QLabel(InterpolationCB);
        SCThresholdLabel->setObjectName(QString::fromUtf8("SCThresholdLabel"));
        SCThresholdLabel->setGeometry(QRect(23, 148, 133, 16));
        VSTabs->addTab(InterpolationTab, QString());
        UpscalingTab = new QWidget();
        UpscalingTab->setObjectName(QString::fromUtf8("UpscalingTab"));
        UpscalingGB = new QGroupBox(UpscalingTab);
        UpscalingGB->setObjectName(QString::fromUtf8("UpscalingGB"));
        UpscalingGB->setGeometry(QRect(12, 7, 512, 212));
        UpscalingGB->setAlignment(Qt::AlignCenter);
        UpscalingGB->setCheckable(true);
        UpscalingGB->setChecked(false);
        GPUThreadUpscaleLabel = new QLabel(UpscalingGB);
        GPUThreadUpscaleLabel->setObjectName(QString::fromUtf8("GPUThreadUpscaleLabel"));
        GPUThreadUpscaleLabel->setGeometry(QRect(383, 56, 71, 20));
        ToolUpscaleDD = new QComboBox(UpscalingGB);
        ToolUpscaleDD->addItem(QString());
        ToolUpscaleDD->addItem(QString());
        ToolUpscaleDD->setObjectName(QString::fromUtf8("ToolUpscaleDD"));
        ToolUpscaleDD->setGeometry(QRect(377, 25, 114, 22));
        ToolUpscaleLabel = new QLabel(UpscalingGB);
        ToolUpscaleLabel->setObjectName(QString::fromUtf8("ToolUpscaleLabel"));
        ToolUpscaleLabel->setGeometry(QRect(23, 28, 49, 16));
        GPUThreadUpscaleDD = new QComboBox(UpscalingGB);
        GPUThreadUpscaleDD->addItem(QString());
        GPUThreadUpscaleDD->addItem(QString());
        GPUThreadUpscaleDD->addItem(QString());
        GPUThreadUpscaleDD->addItem(QString());
        GPUThreadUpscaleDD->setObjectName(QString::fromUtf8("GPUThreadUpscaleDD"));
        GPUThreadUpscaleDD->setGeometry(QRect(454, 56, 37, 22));
        GPUUpscaleDD = new QComboBox(UpscalingGB);
        GPUUpscaleDD->setObjectName(QString::fromUtf8("GPUUpscaleDD"));
        GPUUpscaleDD->setGeometry(QRect(89, 56, 246, 22));
        GPULabel = new QLabel(UpscalingGB);
        GPULabel->setObjectName(QString::fromUtf8("GPULabel"));
        GPULabel->setGeometry(QRect(23, 57, 66, 16));
        ModelUpscaleDD = new QComboBox(UpscalingGB);
        ModelUpscaleDD->addItem(QString());
        ModelUpscaleDD->addItem(QString());
        ModelUpscaleDD->addItem(QString());
        ModelUpscaleDD->addItem(QString());
        ModelUpscaleDD->setObjectName(QString::fromUtf8("ModelUpscaleDD"));
        ModelUpscaleDD->setGeometry(QRect(366, 87, 125, 22));
        ModelUpscaleLabel = new QLabel(UpscalingGB);
        ModelUpscaleLabel->setObjectName(QString::fromUtf8("ModelUpscaleLabel"));
        ModelUpscaleLabel->setGeometry(QRect(23, 88, 52, 16));
        NoiseReduc2xLabel = new QLabel(UpscalingGB);
        NoiseReduc2xLabel->setObjectName(QString::fromUtf8("NoiseReduc2xLabel"));
        NoiseReduc2xLabel->setGeometry(QRect(23, 119, 123, 16));
        NoiseReduc2xDD = new QComboBox(UpscalingGB);
        NoiseReduc2xDD->addItem(QString());
        NoiseReduc2xDD->addItem(QString());
        NoiseReduc2xDD->addItem(QString());
        NoiseReduc2xDD->addItem(QString());
        NoiseReduc2xDD->addItem(QString());
        NoiseReduc2xDD->setObjectName(QString::fromUtf8("NoiseReduc2xDD"));
        NoiseReduc2xDD->setGeometry(QRect(416, 118, 75, 22));
        Precision2xLabel = new QLabel(UpscalingGB);
        Precision2xLabel->setObjectName(QString::fromUtf8("Precision2xLabel"));
        Precision2xLabel->setGeometry(QRect(23, 149, 58, 16));
        Precision2xDD = new QComboBox(UpscalingGB);
        Precision2xDD->addItem(QString());
        Precision2xDD->addItem(QString());
        Precision2xDD->setObjectName(QString::fromUtf8("Precision2xDD"));
        Precision2xDD->setGeometry(QRect(442, 149, 49, 22));
        OutResolutionLabel = new QLabel(UpscalingGB);
        OutResolutionLabel->setObjectName(QString::fromUtf8("OutResolutionLabel"));
        OutResolutionLabel->setGeometry(QRect(23, 180, 103, 16));
        Width2xNUD = new QSpinBox(UpscalingGB);
        Width2xNUD->setObjectName(QString::fromUtf8("Width2xNUD"));
        Width2xNUD->setGeometry(QRect(213, 179, 52, 22));
        Width2xNUD->setMinimum(640);
        Width2xNUD->setMaximum(7680);
        Width2xNUD->setValue(1920);
        Eks2Label = new QLabel(UpscalingGB);
        Eks2Label->setObjectName(QString::fromUtf8("Eks2Label"));
        Eks2Label->setGeometry(QRect(271, 182, 19, 16));
        Height2xNUD = new QSpinBox(UpscalingGB);
        Height2xNUD->setObjectName(QString::fromUtf8("Height2xNUD"));
        Height2xNUD->setGeometry(QRect(285, 179, 52, 22));
        Height2xNUD->setMinimum(360);
        Height2xNUD->setMaximum(4320);
        Height2xNUD->setValue(1080);
        AutoAdjDD = new QComboBox(UpscalingGB);
        AutoAdjDD->addItem(QString());
        AutoAdjDD->addItem(QString());
        AutoAdjDD->setObjectName(QString::fromUtf8("AutoAdjDD"));
        AutoAdjDD->setGeometry(QRect(432, 179, 59, 22));
        AutoAdjCB = new QCheckBox(UpscalingGB);
        AutoAdjCB->setObjectName(QString::fromUtf8("AutoAdjCB"));
        AutoAdjCB->setGeometry(QRect(348, 180, 83, 20));
        AutoAdjCB->setChecked(true);
        TTA2xLabel = new QLabel(UpscalingGB);
        TTA2xLabel->setObjectName(QString::fromUtf8("TTA2xLabel"));
        TTA2xLabel->setGeometry(QRect(23, 149, 163, 16));
        TTA2xCB = new QCheckBox(UpscalingGB);
        TTA2xCB->setObjectName(QString::fromUtf8("TTA2xCB"));
        TTA2xCB->setGeometry(QRect(478, 150, 19, 20));
        VSTabs->addTab(UpscalingTab, QString());
        VSColorsTab = new QWidget();
        VSColorsTab->setObjectName(QString::fromUtf8("VSColorsTab"));
        ColorPropsGB = new QGroupBox(VSColorsTab);
        ColorPropsGB->setObjectName(QString::fromUtf8("ColorPropsGB"));
        ColorPropsGB->setGeometry(QRect(12, 7, 512, 110));
        ColorPropsGB->setAlignment(Qt::AlignCenter);
        ColorPropsGB->setCheckable(true);
        ColorPropsGB->setChecked(false);
        InputColorsLabel = new QLabel(ColorPropsGB);
        InputColorsLabel->setObjectName(QString::fromUtf8("InputColorsLabel"));
        InputColorsLabel->setGeometry(QRect(18, 29, 160, 16));
        OutputColorsLabel = new QLabel(ColorPropsGB);
        OutputColorsLabel->setObjectName(QString::fromUtf8("OutputColorsLabel"));
        OutputColorsLabel->setGeometry(QRect(17, 71, 174, 16));
        InputMatrixDD = new QComboBox(ColorPropsGB);
        InputMatrixDD->addItem(QString());
        InputMatrixDD->addItem(QString());
        InputMatrixDD->addItem(QString());
        InputMatrixDD->addItem(QString());
        InputMatrixDD->addItem(QString());
        InputMatrixDD->addItem(QString());
        InputMatrixDD->addItem(QString());
        InputMatrixDD->addItem(QString());
        InputMatrixDD->addItem(QString());
        InputMatrixDD->addItem(QString());
        InputMatrixDD->addItem(QString());
        InputMatrixDD->setObjectName(QString::fromUtf8("InputMatrixDD"));
        InputMatrixDD->setGeometry(QRect(222, 27, 83, 22));
        InputTransferDD = new QComboBox(ColorPropsGB);
        InputTransferDD->addItem(QString());
        InputTransferDD->addItem(QString());
        InputTransferDD->addItem(QString());
        InputTransferDD->addItem(QString());
        InputTransferDD->addItem(QString());
        InputTransferDD->addItem(QString());
        InputTransferDD->addItem(QString());
        InputTransferDD->addItem(QString());
        InputTransferDD->addItem(QString());
        InputTransferDD->addItem(QString());
        InputTransferDD->addItem(QString());
        InputTransferDD->addItem(QString());
        InputTransferDD->addItem(QString());
        InputTransferDD->addItem(QString());
        InputTransferDD->setObjectName(QString::fromUtf8("InputTransferDD"));
        InputTransferDD->setGeometry(QRect(318, 27, 81, 22));
        InputPrimsDD = new QComboBox(ColorPropsGB);
        InputPrimsDD->addItem(QString());
        InputPrimsDD->addItem(QString());
        InputPrimsDD->addItem(QString());
        InputPrimsDD->addItem(QString());
        InputPrimsDD->addItem(QString());
        InputPrimsDD->addItem(QString());
        InputPrimsDD->addItem(QString());
        InputPrimsDD->addItem(QString());
        InputPrimsDD->addItem(QString());
        InputPrimsDD->addItem(QString());
        InputPrimsDD->addItem(QString());
        InputPrimsDD->setObjectName(QString::fromUtf8("InputPrimsDD"));
        InputPrimsDD->setGeometry(QRect(412, 27, 82, 22));
        OutputMatrixDD = new QComboBox(ColorPropsGB);
        OutputMatrixDD->addItem(QString());
        OutputMatrixDD->addItem(QString());
        OutputMatrixDD->addItem(QString());
        OutputMatrixDD->addItem(QString());
        OutputMatrixDD->addItem(QString());
        OutputMatrixDD->addItem(QString());
        OutputMatrixDD->addItem(QString());
        OutputMatrixDD->addItem(QString());
        OutputMatrixDD->addItem(QString());
        OutputMatrixDD->addItem(QString());
        OutputMatrixDD->addItem(QString());
        OutputMatrixDD->setObjectName(QString::fromUtf8("OutputMatrixDD"));
        OutputMatrixDD->setGeometry(QRect(222, 69, 83, 22));
        Slash2Label = new QLabel(ColorPropsGB);
        Slash2Label->setObjectName(QString::fromUtf8("Slash2Label"));
        Slash2Label->setGeometry(QRect(309, 29, 16, 16));
        Slash3Label = new QLabel(ColorPropsGB);
        Slash3Label->setObjectName(QString::fromUtf8("Slash3Label"));
        Slash3Label->setGeometry(QRect(403, 29, 16, 16));
        Slash4Label = new QLabel(ColorPropsGB);
        Slash4Label->setObjectName(QString::fromUtf8("Slash4Label"));
        Slash4Label->setGeometry(QRect(309, 71, 16, 16));
        Slash5Label = new QLabel(ColorPropsGB);
        Slash5Label->setObjectName(QString::fromUtf8("Slash5Label"));
        Slash5Label->setGeometry(QRect(403, 71, 16, 16));
        OutputTransferDD = new QComboBox(ColorPropsGB);
        OutputTransferDD->addItem(QString());
        OutputTransferDD->addItem(QString());
        OutputTransferDD->addItem(QString());
        OutputTransferDD->addItem(QString());
        OutputTransferDD->addItem(QString());
        OutputTransferDD->addItem(QString());
        OutputTransferDD->addItem(QString());
        OutputTransferDD->addItem(QString());
        OutputTransferDD->addItem(QString());
        OutputTransferDD->addItem(QString());
        OutputTransferDD->addItem(QString());
        OutputTransferDD->addItem(QString());
        OutputTransferDD->addItem(QString());
        OutputTransferDD->addItem(QString());
        OutputTransferDD->setObjectName(QString::fromUtf8("OutputTransferDD"));
        OutputTransferDD->setGeometry(QRect(318, 69, 81, 22));
        OutputPrimsDD = new QComboBox(ColorPropsGB);
        OutputPrimsDD->addItem(QString());
        OutputPrimsDD->addItem(QString());
        OutputPrimsDD->addItem(QString());
        OutputPrimsDD->addItem(QString());
        OutputPrimsDD->addItem(QString());
        OutputPrimsDD->addItem(QString());
        OutputPrimsDD->addItem(QString());
        OutputPrimsDD->addItem(QString());
        OutputPrimsDD->addItem(QString());
        OutputPrimsDD->addItem(QString());
        OutputPrimsDD->addItem(QString());
        OutputPrimsDD->setObjectName(QString::fromUtf8("OutputPrimsDD"));
        OutputPrimsDD->setGeometry(QRect(412, 69, 82, 22));
        VSTabs->addTab(VSColorsTab, QString());
        LineTab = new QWidget();
        LineTab->setObjectName(QString::fromUtf8("LineTab"));
        AntiAliasingGB = new QGroupBox(LineTab);
        AntiAliasingGB->setObjectName(QString::fromUtf8("AntiAliasingGB"));
        AntiAliasingGB->setGeometry(QRect(12, 7, 512, 57));
        AntiAliasingGB->setAlignment(Qt::AlignCenter);
        AntiAliasingGB->setCheckable(false);
        AntiAliasingGB->setChecked(false);
        UseAALabel = new QLabel(AntiAliasingGB);
        UseAALabel->setObjectName(QString::fromUtf8("UseAALabel"));
        UseAALabel->setGeometry(QRect(19, 21, 118, 21));
        UseAACB = new QCheckBox(AntiAliasingGB);
        UseAACB->setObjectName(QString::fromUtf8("UseAACB"));
        UseAACB->setGeometry(QRect(480, 23, 17, 20));
        VSTabs->addTab(LineTab, QString());
        VideoTabs->addTab(VSTab, QString());
        FiltersTab = new QWidget();
        FiltersTab->setObjectName(QString::fromUtf8("FiltersTab"));
        FiltersTabs = new QTabWidget(FiltersTab);
        FiltersTabs->setObjectName(QString::fromUtf8("FiltersTabs"));
        FiltersTabs->setGeometry(QRect(3, 2, 542, 257));
        ResizeTab = new QWidget();
        ResizeTab->setObjectName(QString::fromUtf8("ResizeTab"));
        ResizeGB = new QGroupBox(ResizeTab);
        ResizeGB->setObjectName(QString::fromUtf8("ResizeGB"));
        ResizeGB->setGeometry(QRect(12, 7, 298, 114));
        ResizeGB->setAlignment(Qt::AlignCenter);
        ResizeGB->setCheckable(true);
        ResizeGB->setChecked(false);
        ResolutionResLabel = new QLabel(ResizeGB);
        ResolutionResLabel->setObjectName(QString::fromUtf8("ResolutionResLabel"));
        ResolutionResLabel->setGeometry(QRect(18, 23, 101, 16));
        Eks3Label = new QLabel(ResizeGB);
        Eks3Label->setObjectName(QString::fromUtf8("Eks3Label"));
        Eks3Label->setGeometry(QRect(216, 24, 19, 16));
        WidthNUD = new QSpinBox(ResizeGB);
        WidthNUD->setObjectName(QString::fromUtf8("WidthNUD"));
        WidthNUD->setGeometry(QRect(158, 21, 52, 22));
        WidthNUD->setMinimum(640);
        WidthNUD->setMaximum(7680);
        WidthNUD->setValue(1920);
        HeightNUD = new QSpinBox(ResizeGB);
        HeightNUD->setObjectName(QString::fromUtf8("HeightNUD"));
        HeightNUD->setGeometry(QRect(230, 21, 52, 22));
        HeightNUD->setMinimum(360);
        HeightNUD->setMaximum(4320);
        HeightNUD->setValue(1080);
        AutoAdjResDD = new QComboBox(ResizeGB);
        AutoAdjResDD->addItem(QString());
        AutoAdjResDD->addItem(QString());
        AutoAdjResDD->setObjectName(QString::fromUtf8("AutoAdjResDD"));
        AutoAdjResDD->setGeometry(QRect(220, 51, 62, 22));
        AutoAdjResCB = new QCheckBox(ResizeGB);
        AutoAdjResCB->setObjectName(QString::fromUtf8("AutoAdjResCB"));
        AutoAdjResCB->setGeometry(QRect(18, 50, 83, 22));
        AutoAdjResCB->setChecked(true);
        ResizeAlgoCB = new QCheckBox(ResizeGB);
        ResizeAlgoCB->setObjectName(QString::fromUtf8("ResizeAlgoCB"));
        ResizeAlgoCB->setGeometry(QRect(18, 81, 52, 20));
        ResizeAlgoDD = new QComboBox(ResizeGB);
        ResizeAlgoDD->addItem(QString());
        ResizeAlgoDD->addItem(QString());
        ResizeAlgoDD->addItem(QString());
        ResizeAlgoDD->addItem(QString());
        ResizeAlgoDD->addItem(QString());
        ResizeAlgoDD->addItem(QString());
        ResizeAlgoDD->addItem(QString());
        ResizeAlgoDD->addItem(QString());
        ResizeAlgoDD->addItem(QString());
        ResizeAlgoDD->addItem(QString());
        ResizeAlgoDD->setObjectName(QString::fromUtf8("ResizeAlgoDD"));
        ResizeAlgoDD->setGeometry(QRect(181, 81, 101, 22));
        RotateGB = new QGroupBox(ResizeTab);
        RotateGB->setObjectName(QString::fromUtf8("RotateGB"));
        RotateGB->setGeometry(QRect(323, 7, 201, 114));
        RotateGB->setAlignment(Qt::AlignCenter);
        RotateGB->setCheckable(true);
        RotateGB->setChecked(false);
        AngleLabel = new QLabel(RotateGB);
        AngleLabel->setObjectName(QString::fromUtf8("AngleLabel"));
        AngleLabel->setGeometry(QRect(17, 20, 47, 20));
        AngleDD = new QComboBox(RotateGB);
        AngleDD->addItem(QString());
        AngleDD->addItem(QString());
        AngleDD->addItem(QString());
        AngleDD->addItem(QString());
        AngleDD->setObjectName(QString::fromUtf8("AngleDD"));
        AngleDD->setGeometry(QRect(129, 21, 55, 22));
        FlipCB = new QCheckBox(RotateGB);
        FlipCB->setObjectName(QString::fromUtf8("FlipCB"));
        FlipCB->setGeometry(QRect(16, 50, 47, 23));
        FlipDD = new QComboBox(RotateGB);
        FlipDD->addItem(QString());
        FlipDD->addItem(QString());
        FlipDD->setObjectName(QString::fromUtf8("FlipDD"));
        FlipDD->setGeometry(QRect(95, 51, 89, 22));
        NoAutoRotateLabel = new QLabel(RotateGB);
        NoAutoRotateLabel->setObjectName(QString::fromUtf8("NoAutoRotateLabel"));
        NoAutoRotateLabel->setGeometry(QRect(16, 82, 87, 20));
        NoAutoRotateCB = new QCheckBox(RotateGB);
        NoAutoRotateCB->setObjectName(QString::fromUtf8("NoAutoRotateCB"));
        NoAutoRotateCB->setGeometry(QRect(171, 84, 21, 20));
        NoAutoRotateCB->setChecked(true);
        CropGB = new QGroupBox(ResizeTab);
        CropGB->setObjectName(QString::fromUtf8("CropGB"));
        CropGB->setGeometry(QRect(12, 125, 511, 94));
        CropGB->setAlignment(Qt::AlignCenter);
        CropGB->setCheckable(true);
        CropGB->setChecked(false);
        OutSizeLabel = new QLabel(CropGB);
        OutSizeLabel->setObjectName(QString::fromUtf8("OutSizeLabel"));
        OutSizeLabel->setGeometry(QRect(18, 25, 119, 16));
        Eks4Label = new QLabel(CropGB);
        Eks4Label->setObjectName(QString::fromUtf8("Eks4Label"));
        Eks4Label->setGeometry(QRect(429, 25, 19, 16));
        OutWidthNUD = new QSpinBox(CropGB);
        OutWidthNUD->setObjectName(QString::fromUtf8("OutWidthNUD"));
        OutWidthNUD->setGeometry(QRect(371, 22, 52, 22));
        OutWidthNUD->setMinimum(640);
        OutWidthNUD->setMaximum(7680);
        OutWidthNUD->setValue(1920);
        OutHeightNUD = new QSpinBox(CropGB);
        OutHeightNUD->setObjectName(QString::fromUtf8("OutHeightNUD"));
        OutHeightNUD->setGeometry(QRect(443, 22, 52, 22));
        OutHeightNUD->setMinimum(360);
        OutHeightNUD->setMaximum(4320);
        OutHeightNUD->setValue(1080);
        LocationLabel = new QLabel(CropGB);
        LocationLabel->setObjectName(QString::fromUtf8("LocationLabel"));
        LocationLabel->setGeometry(QRect(19, 58, 84, 16));
        EksNUD = new QSpinBox(CropGB);
        EksNUD->setObjectName(QString::fromUtf8("EksNUD"));
        EksNUD->setGeometry(QRect(371, 55, 52, 22));
        EksNUD->setMinimum(0);
        EksNUD->setMaximum(7680);
        EksNUD->setValue(0);
        WhyNUD = new QSpinBox(CropGB);
        WhyNUD->setObjectName(QString::fromUtf8("WhyNUD"));
        WhyNUD->setGeometry(QRect(443, 55, 52, 22));
        WhyNUD->setMinimum(0);
        WhyNUD->setMaximum(4320);
        WhyNUD->setValue(0);
        Slash4Label_2 = new QLabel(CropGB);
        Slash4Label_2->setObjectName(QString::fromUtf8("Slash4Label_2"));
        Slash4Label_2->setGeometry(QRect(430, 56, 20, 20));
        FiltersTabs->addTab(ResizeTab, QString());
        ColorsTab = new QWidget();
        ColorsTab->setObjectName(QString::fromUtf8("ColorsTab"));
        SharpenGB = new QGroupBox(ColorsTab);
        SharpenGB->setObjectName(QString::fromUtf8("SharpenGB"));
        SharpenGB->setGeometry(QRect(12, 7, 511, 91));
        SharpenGB->setAlignment(Qt::AlignCenter);
        SharpenGB->setCheckable(true);
        SharpenGB->setChecked(false);
        RadiusLabel = new QLabel(SharpenGB);
        RadiusLabel->setObjectName(QString::fromUtf8("RadiusLabel"));
        RadiusLabel->setGeometry(QRect(19, 20, 47, 21));
        RadiusDD = new QComboBox(SharpenGB);
        RadiusDD->addItem(QString());
        RadiusDD->addItem(QString());
        RadiusDD->addItem(QString());
        RadiusDD->setObjectName(QString::fromUtf8("RadiusDD"));
        RadiusDD->setGeometry(QRect(385, 22, 107, 22));
        StrengthLabel = new QLabel(SharpenGB);
        StrengthLabel->setObjectName(QString::fromUtf8("StrengthLabel"));
        StrengthLabel->setGeometry(QRect(19, 56, 54, 16));
        StrengthDD = new QComboBox(SharpenGB);
        StrengthDD->addItem(QString());
        StrengthDD->addItem(QString());
        StrengthDD->addItem(QString());
        StrengthDD->addItem(QString());
        StrengthDD->addItem(QString());
        StrengthDD->setObjectName(QString::fromUtf8("StrengthDD"));
        StrengthDD->setGeometry(QRect(385, 55, 107, 22));
        FiltersTabs->addTab(ColorsTab, QString());
        MiscFFTab = new QWidget();
        MiscFFTab->setObjectName(QString::fromUtf8("MiscFFTab"));
        DeinterlaceGB = new QGroupBox(MiscFFTab);
        DeinterlaceGB->setObjectName(QString::fromUtf8("DeinterlaceGB"));
        DeinterlaceGB->setGeometry(QRect(12, 7, 511, 56));
        DeinterlaceGB->setAlignment(Qt::AlignCenter);
        DeinterlaceGB->setCheckable(false);
        DeinterlaceGB->setChecked(false);
        EnableDeintLabel = new QLabel(DeinterlaceGB);
        EnableDeintLabel->setObjectName(QString::fromUtf8("EnableDeintLabel"));
        EnableDeintLabel->setGeometry(QRect(19, 21, 124, 21));
        UseDeintCB = new QCheckBox(DeinterlaceGB);
        UseDeintCB->setObjectName(QString::fromUtf8("UseDeintCB"));
        UseDeintCB->setGeometry(QRect(480, 23, 17, 20));
        FiltersTabs->addTab(MiscFFTab, QString());
        VideoTabs->addTab(FiltersTab, QString());
        Tabs->addTab(VideoTab, QString());
        AudioTab = new QWidget();
        AudioTab->setObjectName(QString::fromUtf8("AudioTab"));
        AudioQueue = new QTableWidget(AudioTab);
        if (AudioQueue->columnCount() < 1)
            AudioQueue->setColumnCount(1);
        AudioQueue->setObjectName(QString::fromUtf8("AudioQueue"));
        AudioQueue->setGeometry(QRect(290, 35, 256, 212));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AudioQueue->sizePolicy().hasHeightForWidth());
        AudioQueue->setSizePolicy(sizePolicy);
        AudioQueue->setFocusPolicy(Qt::NoFocus);
        AudioQueue->setContextMenuPolicy(Qt::CustomContextMenu);
        AudioQueue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        AudioQueue->setEditTriggers(QAbstractItemView::NoEditTriggers);
        AudioQueue->setTabKeyNavigation(false);
        AudioQueue->setSelectionMode(QAbstractItemView::NoSelection);
        AudioQueue->setSelectionBehavior(QAbstractItemView::SelectRows);
        AudioQueue->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        AudioQueue->setColumnCount(1);
        AudioQueue->horizontalHeader()->setVisible(false);
        AudioQueue->horizontalHeader()->setHighlightSections(false);
        AudioQueue->horizontalHeader()->setStretchLastSection(true);
        AudioQueue->verticalHeader()->setVisible(false);
        AudioQueue->verticalHeader()->setMinimumSectionSize(25);
        AudioQueue->verticalHeader()->setDefaultSectionSize(25);
        AudioSelectorGB = new QGroupBox(AudioTab);
        AudioSelectorGB->setObjectName(QString::fromUtf8("AudioSelectorGB"));
        AudioSelectorGB->setGeometry(QRect(15, 7, 261, 93));
        AudioSelectorGB->setAlignment(Qt::AlignCenter);
        SelectedAudioLabel = new QLabel(AudioSelectorGB);
        SelectedAudioLabel->setObjectName(QString::fromUtf8("SelectedAudioLabel"));
        SelectedAudioLabel->setGeometry(QRect(14, 59, 84, 16));
        SelectedAudioDD = new QComboBox(AudioSelectorGB);
        SelectedAudioDD->setObjectName(QString::fromUtf8("SelectedAudioDD"));
        SelectedAudioDD->setGeometry(QRect(157, 57, 90, 22));
        AudioSourceLabel = new QLabel(AudioSelectorGB);
        AudioSourceLabel->setObjectName(QString::fromUtf8("AudioSourceLabel"));
        AudioSourceLabel->setGeometry(QRect(14, 25, 42, 16));
        SelectBttn = new QPushButton(AudioSelectorGB);
        SelectBttn->setObjectName(QString::fromUtf8("SelectBttn"));
        SelectBttn->setGeometry(QRect(192, 22, 56, 24));
        AudioSourceTxtBox = new QLineEdit(AudioSelectorGB);
        AudioSourceTxtBox->setObjectName(QString::fromUtf8("AudioSourceTxtBox"));
        AudioSourceTxtBox->setGeometry(QRect(72, 24, 115, 21));
        AudioSourceTxtBox->setReadOnly(true);
        EncodingAudioGB = new QGroupBox(AudioTab);
        EncodingAudioGB->setObjectName(QString::fromUtf8("EncodingAudioGB"));
        EncodingAudioGB->setGeometry(QRect(15, 165, 261, 114));
        EncodingAudioGB->setAlignment(Qt::AlignCenter);
        EncodingAudioGB->setCheckable(true);
        EncodingAudioGB->setChecked(false);
        EncoderAudioLabel = new QLabel(EncodingAudioGB);
        EncoderAudioLabel->setObjectName(QString::fromUtf8("EncoderAudioLabel"));
        EncoderAudioLabel->setGeometry(QRect(14, 21, 58, 29));
        AudioEncoderDD = new QComboBox(EncodingAudioGB);
        AudioEncoderDD->addItem(QString());
        AudioEncoderDD->addItem(QString());
        AudioEncoderDD->addItem(QString());
        AudioEncoderDD->addItem(QString());
        AudioEncoderDD->addItem(QString());
        AudioEncoderDD->addItem(QString());
        AudioEncoderDD->addItem(QString());
        AudioEncoderDD->addItem(QString());
        AudioEncoderDD->setObjectName(QString::fromUtf8("AudioEncoderDD"));
        AudioEncoderDD->setGeometry(QRect(175, 25, 72, 22));
        RealAudioBitrateLabel = new QLabel(EncodingAudioGB);
        RealAudioBitrateLabel->setObjectName(QString::fromUtf8("RealAudioBitrateLabel"));
        RealAudioBitrateLabel->setGeometry(QRect(14, 53, 90, 20));
        AudioBitrateNUD = new QSpinBox(EncodingAudioGB);
        AudioBitrateNUD->setObjectName(QString::fromUtf8("AudioBitrateNUD"));
        AudioBitrateNUD->setGeometry(QRect(187, 53, 60, 22));
        AudioBitrateNUD->setMinimum(32);
        AudioBitrateNUD->setMaximum(1562);
        AudioBitrateNUD->setValue(160);
        DownmixCB = new QCheckBox(EncodingAudioGB);
        DownmixCB->setObjectName(QString::fromUtf8("DownmixCB"));
        DownmixCB->setGeometry(QRect(14, 79, 76, 26));
        DownmixDD = new QComboBox(EncodingAudioGB);
        DownmixDD->addItem(QString());
        DownmixDD->addItem(QString());
        DownmixDD->addItem(QString());
        DownmixDD->setObjectName(QString::fromUtf8("DownmixDD"));
        DownmixDD->setGeometry(QRect(170, 81, 77, 22));
        AudioQualityLabel = new QLabel(EncodingAudioGB);
        AudioQualityLabel->setObjectName(QString::fromUtf8("AudioQualityLabel"));
        AudioQualityLabel->setGeometry(QRect(14, 55, 49, 16));
        AudioQualityNUD = new QSpinBox(EncodingAudioGB);
        AudioQualityNUD->setObjectName(QString::fromUtf8("AudioQualityNUD"));
        AudioQualityNUD->setGeometry(QRect(206, 53, 41, 22));
        AudioQualityNUD->setValue(6);
        AddAudioJobBttn = new QPushButton(AudioTab);
        AddAudioJobBttn->setObjectName(QString::fromUtf8("AddAudioJobBttn"));
        AddAudioJobBttn->setGeometry(QRect(289, 256, 258, 24));
        AudioQueueLabel = new QLabel(AudioTab);
        AudioQueueLabel->setObjectName(QString::fromUtf8("AudioQueueLabel"));
        AudioQueueLabel->setGeometry(QRect(367, 5, 101, 25));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        AudioQueueLabel->setFont(font1);
        AudioTitleCB = new QCheckBox(AudioTab);
        AudioTitleCB->setObjectName(QString::fromUtf8("AudioTitleCB"));
        AudioTitleCB->setGeometry(QRect(15, 106, 50, 27));
        AudioTitleTxtBox = new QLineEdit(AudioTab);
        AudioTitleTxtBox->setObjectName(QString::fromUtf8("AudioTitleTxtBox"));
        AudioTitleTxtBox->setGeometry(QRect(73, 110, 203, 21));
        LangAudioCB = new QCheckBox(AudioTab);
        LangAudioCB->setObjectName(QString::fromUtf8("LangAudioCB"));
        LangAudioCB->setGeometry(QRect(15, 138, 79, 21));
        LangAudioDD = new QComboBox(AudioTab);
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->addItem(QString());
        LangAudioDD->setObjectName(QString::fromUtf8("LangAudioDD"));
        LangAudioDD->setGeometry(QRect(150, 139, 126, 22));
        Tabs->addTab(AudioTab, QString());
        SubtitlesTab = new QWidget();
        SubtitlesTab->setObjectName(QString::fromUtf8("SubtitlesTab"));
        SubtitleTitleCB = new QCheckBox(SubtitlesTab);
        SubtitleTitleCB->setObjectName(QString::fromUtf8("SubtitleTitleCB"));
        SubtitleTitleCB->setGeometry(QRect(15, 159, 50, 27));
        SubtitleQueueLabel = new QLabel(SubtitlesTab);
        SubtitleQueueLabel->setObjectName(QString::fromUtf8("SubtitleQueueLabel"));
        SubtitleQueueLabel->setGeometry(QRect(360, 5, 125, 25));
        SubtitleQueueLabel->setFont(font1);
        SubtitleQueue = new QTableWidget(SubtitlesTab);
        if (SubtitleQueue->columnCount() < 1)
            SubtitleQueue->setColumnCount(1);
        SubtitleQueue->setObjectName(QString::fromUtf8("SubtitleQueue"));
        SubtitleQueue->setGeometry(QRect(290, 35, 256, 212));
        sizePolicy.setHeightForWidth(SubtitleQueue->sizePolicy().hasHeightForWidth());
        SubtitleQueue->setSizePolicy(sizePolicy);
        SubtitleQueue->setFocusPolicy(Qt::NoFocus);
        SubtitleQueue->setContextMenuPolicy(Qt::CustomContextMenu);
        SubtitleQueue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        SubtitleQueue->setEditTriggers(QAbstractItemView::NoEditTriggers);
        SubtitleQueue->setTabKeyNavigation(false);
        SubtitleQueue->setSelectionMode(QAbstractItemView::NoSelection);
        SubtitleQueue->setSelectionBehavior(QAbstractItemView::SelectRows);
        SubtitleQueue->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        SubtitleQueue->setColumnCount(1);
        SubtitleQueue->horizontalHeader()->setVisible(false);
        SubtitleQueue->horizontalHeader()->setHighlightSections(false);
        SubtitleQueue->horizontalHeader()->setStretchLastSection(true);
        SubtitleQueue->verticalHeader()->setVisible(false);
        SubtitleQueue->verticalHeader()->setMinimumSectionSize(25);
        SubtitleQueue->verticalHeader()->setDefaultSectionSize(25);
        SubtitleLangDD = new QComboBox(SubtitlesTab);
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->addItem(QString());
        SubtitleLangDD->setObjectName(QString::fromUtf8("SubtitleLangDD"));
        SubtitleLangDD->setGeometry(QRect(150, 194, 126, 22));
        SubtitleTitleTxtBox = new QLineEdit(SubtitlesTab);
        SubtitleTitleTxtBox->setObjectName(QString::fromUtf8("SubtitleTitleTxtBox"));
        SubtitleTitleTxtBox->setGeometry(QRect(73, 163, 203, 21));
        SubtitleLangCB = new QCheckBox(SubtitlesTab);
        SubtitleLangCB->setObjectName(QString::fromUtf8("SubtitleLangCB"));
        SubtitleLangCB->setGeometry(QRect(15, 193, 79, 21));
        SubtitleSelectorGB = new QGroupBox(SubtitlesTab);
        SubtitleSelectorGB->setObjectName(QString::fromUtf8("SubtitleSelectorGB"));
        SubtitleSelectorGB->setGeometry(QRect(15, 27, 261, 125));
        SubtitleSelectorGB->setAlignment(Qt::AlignCenter);
        SelectedSubtitleLabel = new QLabel(SubtitleSelectorGB);
        SelectedSubtitleLabel->setObjectName(QString::fromUtf8("SelectedSubtitleLabel"));
        SelectedSubtitleLabel->setGeometry(QRect(14, 59, 102, 16));
        SelectedSubtitleDD = new QComboBox(SubtitleSelectorGB);
        SelectedSubtitleDD->setObjectName(QString::fromUtf8("SelectedSubtitleDD"));
        SelectedSubtitleDD->setGeometry(QRect(157, 57, 90, 22));
        SubtitleSourceLabel = new QLabel(SubtitleSelectorGB);
        SubtitleSourceLabel->setObjectName(QString::fromUtf8("SubtitleSourceLabel"));
        SubtitleSourceLabel->setGeometry(QRect(14, 25, 42, 16));
        SubSelectBttn = new QPushButton(SubtitleSelectorGB);
        SubSelectBttn->setObjectName(QString::fromUtf8("SubSelectBttn"));
        SubSelectBttn->setGeometry(QRect(192, 22, 56, 24));
        SubSourceTxtBox = new QLineEdit(SubtitleSelectorGB);
        SubSourceTxtBox->setObjectName(QString::fromUtf8("SubSourceTxtBox"));
        SubSourceTxtBox->setGeometry(QRect(72, 24, 115, 21));
        SubSourceTxtBox->setReadOnly(true);
        SubtitleInfoBttn = new QPushButton(SubtitleSelectorGB);
        SubtitleInfoBttn->setObjectName(QString::fromUtf8("SubtitleInfoBttn"));
        SubtitleInfoBttn->setGeometry(QRect(13, 89, 234, 24));
        SubtitleEncodingGB = new QGroupBox(SubtitlesTab);
        SubtitleEncodingGB->setObjectName(QString::fromUtf8("SubtitleEncodingGB"));
        SubtitleEncodingGB->setGeometry(QRect(15, 223, 261, 56));
        SubtitleEncodingGB->setAlignment(Qt::AlignCenter);
        SubtitleEncodingGB->setCheckable(true);
        SubtitleEncodingGB->setChecked(false);
        SubtitleEncoderLabel = new QLabel(SubtitleEncodingGB);
        SubtitleEncoderLabel->setObjectName(QString::fromUtf8("SubtitleEncoderLabel"));
        SubtitleEncoderLabel->setGeometry(QRect(14, 18, 58, 29));
        SubtitleEncoderDD = new QComboBox(SubtitleEncodingGB);
        SubtitleEncoderDD->addItem(QString());
        SubtitleEncoderDD->addItem(QString());
        SubtitleEncoderDD->addItem(QString());
        SubtitleEncoderDD->addItem(QString());
        SubtitleEncoderDD->setObjectName(QString::fromUtf8("SubtitleEncoderDD"));
        SubtitleEncoderDD->setGeometry(QRect(161, 22, 86, 22));
        AddSubtitleJobBttn = new QPushButton(SubtitlesTab);
        AddSubtitleJobBttn->setObjectName(QString::fromUtf8("AddSubtitleJobBttn"));
        AddSubtitleJobBttn->setGeometry(QRect(289, 256, 258, 24));
        Tabs->addTab(SubtitlesTab, QString());
        PrefTab = new QWidget();
        PrefTab->setObjectName(QString::fromUtf8("PrefTab"));
        SettingsTabs = new QTabWidget(PrefTab);
        SettingsTabs->setObjectName(QString::fromUtf8("SettingsTabs"));
        SettingsTabs->setGeometry(QRect(3, 2, 553, 289));
        EGUITab = new QWidget();
        EGUITab->setObjectName(QString::fromUtf8("EGUITab"));
        EGUISettingsGB = new QGroupBox(EGUITab);
        EGUISettingsGB->setObjectName(QString::fromUtf8("EGUISettingsGB"));
        EGUISettingsGB->setGeometry(QRect(11, 5, 523, 189));
        EGUISettingsGB->setAlignment(Qt::AlignCenter);
        EnablePreviewCB = new QCheckBox(EGUISettingsGB);
        EnablePreviewCB->setObjectName(QString::fromUtf8("EnablePreviewCB"));
        EnablePreviewCB->setEnabled(true);
        EnablePreviewCB->setGeometry(QRect(485, 25, 22, 20));
        EnablePreviewCB->setChecked(false);
        AutoDelSourceCB = new QCheckBox(EGUISettingsGB);
        AutoDelSourceCB->setObjectName(QString::fromUtf8("AutoDelSourceCB"));
        AutoDelSourceCB->setGeometry(QRect(485, 50, 28, 20));
        ErrorMessageCB = new QCheckBox(EGUISettingsGB);
        ErrorMessageCB->setObjectName(QString::fromUtf8("ErrorMessageCB"));
        ErrorMessageCB->setGeometry(QRect(485, 74, 24, 24));
        ErrorMessageCB->setChecked(true);
        ErrorMessageLabel = new QLabel(EGUISettingsGB);
        ErrorMessageLabel->setObjectName(QString::fromUtf8("ErrorMessageLabel"));
        ErrorMessageLabel->setGeometry(QRect(27, 74, 192, 20));
        DeleteSourcesLabel = new QLabel(EGUISettingsGB);
        DeleteSourcesLabel->setObjectName(QString::fromUtf8("DeleteSourcesLabel"));
        DeleteSourcesLabel->setGeometry(QRect(27, 50, 259, 16));
        EnablePreviewLabel = new QLabel(EGUISettingsGB);
        EnablePreviewLabel->setObjectName(QString::fromUtf8("EnablePreviewLabel"));
        EnablePreviewLabel->setGeometry(QRect(27, 25, 329, 16));
        UpdateOptLabel = new QLabel(EGUISettingsGB);
        UpdateOptLabel->setObjectName(QString::fromUtf8("UpdateOptLabel"));
        UpdateOptLabel->setGeometry(QRect(27, 102, 240, 18));
        UpdateOptCB = new QCheckBox(EGUISettingsGB);
        UpdateOptCB->setObjectName(QString::fromUtf8("UpdateOptCB"));
        UpdateOptCB->setGeometry(QRect(485, 102, 20, 20));
        UpdateOptCB->setChecked(true);
        GenerateOutLabel = new QLabel(EGUISettingsGB);
        GenerateOutLabel->setObjectName(QString::fromUtf8("GenerateOutLabel"));
        GenerateOutLabel->setGeometry(QRect(27, 129, 249, 16));
        GenerateOutCB = new QCheckBox(EGUISettingsGB);
        GenerateOutCB->setObjectName(QString::fromUtf8("GenerateOutCB"));
        GenerateOutCB->setGeometry(QRect(485, 129, 21, 20));
        NotificationLabel = new QLabel(EGUISettingsGB);
        NotificationLabel->setObjectName(QString::fromUtf8("NotificationLabel"));
        NotificationLabel->setGeometry(QRect(27, 155, 285, 16));
        NotificationCB = new QCheckBox(EGUISettingsGB);
        NotificationCB->setObjectName(QString::fromUtf8("NotificationCB"));
        NotificationCB->setGeometry(QRect(485, 155, 21, 20));
        NotificationCB->setChecked(true);
        ProgressBarGB = new QGroupBox(EGUITab);
        ProgressBarGB->setObjectName(QString::fromUtf8("ProgressBarGB"));
        ProgressBarGB->setGeometry(QRect(11, 199, 524, 51));
        ProgressBarGB->setAlignment(Qt::AlignCenter);
        JobsCB = new QCheckBox(ProgressBarGB);
        JobsCB->setObjectName(QString::fromUtf8("JobsCB"));
        JobsCB->setGeometry(QRect(27, 19, 52, 20));
        JobsCB->setChecked(true);
        FPSCB = new QCheckBox(ProgressBarGB);
        FPSCB->setObjectName(QString::fromUtf8("FPSCB"));
        FPSCB->setGeometry(QRect(92, 19, 47, 20));
        FPSCB->setChecked(true);
        BitrateCB = new QCheckBox(ProgressBarGB);
        BitrateCB->setObjectName(QString::fromUtf8("BitrateCB"));
        BitrateCB->setGeometry(QRect(151, 19, 70, 20));
        BitrateCB->setChecked(true);
        TimeLeftCB = new QCheckBox(ProgressBarGB);
        TimeLeftCB->setObjectName(QString::fromUtf8("TimeLeftCB"));
        TimeLeftCB->setGeometry(QRect(225, 19, 71, 20));
        TimeLeftCB->setChecked(true);
        TimeElapsedCB = new QCheckBox(ProgressBarGB);
        TimeElapsedCB->setObjectName(QString::fromUtf8("TimeElapsedCB"));
        TimeElapsedCB->setGeometry(QRect(310, 19, 101, 20));
        TimeElapsedCB->setChecked(true);
        PercentageCB = new QCheckBox(ProgressBarGB);
        PercentageCB->setObjectName(QString::fromUtf8("PercentageCB"));
        PercentageCB->setGeometry(QRect(421, 19, 87, 20));
        PercentageCB->setChecked(true);
        SettingsTabs->addTab(EGUITab, QString());
        EncodingTab = new QWidget();
        EncodingTab->setObjectName(QString::fromUtf8("EncodingTab"));
        ProcessSettingsGB = new QGroupBox(EncodingTab);
        ProcessSettingsGB->setObjectName(QString::fromUtf8("ProcessSettingsGB"));
        ProcessSettingsGB->setGeometry(QRect(11, 5, 523, 59));
        ProcessSettingsGB->setAlignment(Qt::AlignCenter);
        LimitThreadsNUD = new QSpinBox(ProcessSettingsGB);
        LimitThreadsNUD->setObjectName(QString::fromUtf8("LimitThreadsNUD"));
        LimitThreadsNUD->setEnabled(false);
        LimitThreadsNUD->setGeometry(QRect(458, 22, 49, 22));
        LimitThreadsCB = new QCheckBox(ProcessSettingsGB);
        LimitThreadsCB->setObjectName(QString::fromUtf8("LimitThreadsCB"));
        LimitThreadsCB->setGeometry(QRect(16, 22, 297, 20));
        MultiGPUGB = new QGroupBox(EncodingTab);
        MultiGPUGB->setObjectName(QString::fromUtf8("MultiGPUGB"));
        MultiGPUGB->setGeometry(QRect(12, 71, 522, 145));
        MultiGPUGB->setAlignment(Qt::AlignCenter);
        MultiGPUGB->setCheckable(true);
        MultiGPUGB->setChecked(false);
        TestGPUBttn = new QPushButton(MultiGPUGB);
        TestGPUBttn->setObjectName(QString::fromUtf8("TestGPUBttn"));
        TestGPUBttn->setGeometry(QRect(14, 110, 492, 24));
        GPU1IDNUD = new QSpinBox(MultiGPUGB);
        GPU1IDNUD->setObjectName(QString::fromUtf8("GPU1IDNUD"));
        GPU1IDNUD->setGeometry(QRect(457, 28, 49, 22));
        GPU1IDNUD->setMaximum(7);
        GPU2IDNUD = new QSpinBox(MultiGPUGB);
        GPU2IDNUD->setObjectName(QString::fromUtf8("GPU2IDNUD"));
        GPU2IDNUD->setGeometry(QRect(457, 68, 49, 22));
        GPU2IDNUD->setMaximum(7);
        GPU1IDLabel = new QLabel(MultiGPUGB);
        GPU1IDLabel->setObjectName(QString::fromUtf8("GPU1IDLabel"));
        GPU1IDLabel->setGeometry(QRect(16, 31, 71, 16));
        GPU1IDLabel2 = new QLabel(MultiGPUGB);
        GPU1IDLabel2->setObjectName(QString::fromUtf8("GPU1IDLabel2"));
        GPU1IDLabel2->setGeometry(QRect(16, 70, 65, 16));
        SettingsTabs->addTab(EncodingTab, QString());
        Tabs->addTab(PrefTab, QString());
        JobTab = new QWidget();
        JobTab->setObjectName(QString::fromUtf8("JobTab"));
        JobQueue = new QTableWidget(JobTab);
        if (JobQueue->columnCount() < 6)
            JobQueue->setColumnCount(6);
        QTableWidgetItem* __qtablewidgetitem = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem* __qtablewidgetitem1 = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem* __qtablewidgetitem2 = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem* __qtablewidgetitem3 = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem* __qtablewidgetitem4 = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem* __qtablewidgetitem5 = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        JobQueue->setObjectName(QString::fromUtf8("JobQueue"));
        JobQueue->setGeometry(QRect(4, 37, 549, 251));
        sizePolicy.setHeightForWidth(JobQueue->sizePolicy().hasHeightForWidth());
        JobQueue->setSizePolicy(sizePolicy);
        JobQueue->setFocusPolicy(Qt::NoFocus);
        JobQueue->setContextMenuPolicy(Qt::CustomContextMenu);
        JobQueue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        JobQueue->setEditTriggers(QAbstractItemView::NoEditTriggers);
        JobQueue->setSelectionMode(QAbstractItemView::NoSelection);
        JobQueue->setSelectionBehavior(QAbstractItemView::SelectRows);
        JobQueue->setCornerButtonEnabled(false);
        JobQueue->setRowCount(0);
        JobQueue->setColumnCount(6);
        JobQueue->horizontalHeader()->setVisible(true);
        JobQueue->horizontalHeader()->setCascadingSectionResizes(false);
        JobQueue->horizontalHeader()->setMinimumSectionSize(50);
        JobQueue->horizontalHeader()->setDefaultSectionSize(100);
        JobQueue->horizontalHeader()->setHighlightSections(false);
        JobQueue->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        JobQueue->horizontalHeader()->setStretchLastSection(true);
        JobQueue->verticalHeader()->setVisible(false);
        JobQueue->verticalHeader()->setCascadingSectionResizes(false);
        JobQueue->verticalHeader()->setMinimumSectionSize(25);
        JobQueue->verticalHeader()->setDefaultSectionSize(25);
        JobQueue->verticalHeader()->setHighlightSections(true);
        JobQueue->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        JobQueue->verticalHeader()->setStretchLastSection(false);
        JobQueueLabel = new QLabel(JobTab);
        JobQueueLabel->setObjectName(QString::fromUtf8("JobQueueLabel"));
        JobQueueLabel->setGeometry(QRect(5, 5, 83, 23));
        JobQueueLabel->setFont(font1);
        ClearJobsBttn = new QPushButton(JobTab);
        ClearJobsBttn->setObjectName(QString::fromUtf8("ClearJobsBttn"));
        ClearJobsBttn->setGeometry(QRect(394, 6, 159, 24));
        CancelQueueBttn = new QPushButton(JobTab);
        CancelQueueBttn->setObjectName(QString::fromUtf8("CancelQueueBttn"));
        CancelQueueBttn->setGeometry(QRect(271, 6, 118, 24));
        Tabs->addTab(JobTab, QString());
        LogsTab = new QWidget();
        LogsTab->setObjectName(QString::fromUtf8("LogsTab"));
        LogsOutGB = new QGroupBox(LogsTab);
        LogsOutGB->setObjectName(QString::fromUtf8("LogsOutGB"));
        LogsOutGB->setGeometry(QRect(14, 8, 528, 239));
        LogsOutGB->setAlignment(Qt::AlignCenter);
        LogsOutRTxtBox = new QTextEdit(LogsOutGB);
        LogsOutRTxtBox->setObjectName(QString::fromUtf8("LogsOutRTxtBox"));
        LogsOutRTxtBox->setGeometry(QRect(7, 18, 515, 214));
        LogsOutRTxtBox->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        LogsOutRTxtBox->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        LogsOutRTxtBox->setReadOnly(true);
        LogsDirBttn = new QPushButton(LogsTab);
        LogsDirBttn->setObjectName(QString::fromUtf8("LogsDirBttn"));
        LogsDirBttn->setGeometry(QRect(12, 258, 531, 24));
        Tabs->addTab(LogsTab, QString());
        AboutTab = new QWidget();
        AboutTab->setObjectName(QString::fromUtf8("AboutTab"));
        AboutGUIGB = new QGroupBox(AboutTab);
        AboutGUIGB->setObjectName(QString::fromUtf8("AboutGUIGB"));
        AboutGUIGB->setGeometry(QRect(14, 8, 528, 101));
        AboutGUIGB->setAlignment(Qt::AlignCenter);
        AboutGuiLabel = new QLabel(AboutGUIGB);
        AboutGuiLabel->setObjectName(QString::fromUtf8("AboutGuiLabel"));
        AboutGuiLabel->setGeometry(QRect(18, 22, 490, 68));
        AboutGuiLabel->setTextFormat(Qt::RichText);
        AboutGuiLabel->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
        AboutGuiLabel->setWordWrap(true);
        AboutGuiLabel->setOpenExternalLinks(true);
        DonateGB = new QGroupBox(AboutTab);
        DonateGB->setObjectName(QString::fromUtf8("DonateGB"));
        DonateGB->setGeometry(QRect(14, 116, 363, 102));
        DonateGB->setAlignment(Qt::AlignCenter);
        DonateToDaGooseLabel = new QLabel(DonateGB);
        DonateToDaGooseLabel->setObjectName(QString::fromUtf8("DonateToDaGooseLabel"));
        DonateToDaGooseLabel->setGeometry(QRect(24, 27, 241, 16));
        DonateToGlitchLabel = new QLabel(DonateGB);
        DonateToGlitchLabel->setObjectName(QString::fromUtf8("DonateToGlitchLabel"));
        DonateToGlitchLabel->setGeometry(QRect(24, 64, 179, 16));
        DonateToDaGooseBttn = new QPushButton(DonateGB);
        DonateToDaGooseBttn->setObjectName(QString::fromUtf8("DonateToDaGooseBttn"));
        DonateToDaGooseBttn->setGeometry(QRect(268, 20, 80, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/EncodeGUI/pp_donate.png"), QSize(), QIcon::Normal, QIcon::Off);
        DonateToDaGooseBttn->setIcon(icon1);
        DonateToDaGooseBttn->setIconSize(QSize(70, 35));
        DonateToGlitchBttn = new QPushButton(DonateGB);
        DonateToGlitchBttn->setObjectName(QString::fromUtf8("DonateToGlitchBttn"));
        DonateToGlitchBttn->setGeometry(QRect(268, 56, 80, 31));
        DonateToGlitchBttn->setIcon(icon1);
        DonateToGlitchBttn->setIconSize(QSize(70, 35));
        LinksGB = new QGroupBox(AboutTab);
        LinksGB->setObjectName(QString::fromUtf8("LinksGB"));
        LinksGB->setGeometry(QRect(394, 116, 148, 162));
        LinksGB->setAlignment(Qt::AlignCenter);
        YoutubeBttn = new QPushButton(LinksGB);
        YoutubeBttn->setObjectName(QString::fromUtf8("YoutubeBttn"));
        YoutubeBttn->setGeometry(QRect(23, 24, 103, 35));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/EncodeGUI/yt_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        YoutubeBttn->setIcon(icon2);
        YoutubeBttn->setIconSize(QSize(90, 35));
        DiscordBttn = new QPushButton(LinksGB);
        DiscordBttn->setObjectName(QString::fromUtf8("DiscordBttn"));
        DiscordBttn->setGeometry(QRect(23, 70, 103, 35));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/EncodeGUI/discord_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        DiscordBttn->setIcon(icon3);
        DiscordBttn->setIconSize(QSize(90, 35));
        InstaBttn = new QPushButton(LinksGB);
        InstaBttn->setObjectName(QString::fromUtf8("InstaBttn"));
        InstaBttn->setGeometry(QRect(23, 116, 103, 35));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/EncodeGUI/ig_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        InstaBttn->setIcon(icon4);
        InstaBttn->setIconSize(QSize(90, 35));
        ClearBttn = new QPushButton(AboutTab);
        ClearBttn->setObjectName(QString::fromUtf8("ClearBttn"));
        ClearBttn->setGeometry(QRect(13, 254, 227, 24));
        LicensesBttn = new QPushButton(AboutTab);
        LicensesBttn->setObjectName(QString::fromUtf8("LicensesBttn"));
        LicensesBttn->setGeometry(QRect(247, 254, 131, 24));
        Tabs->addTab(AboutTab, QString());
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(6, 355, 730, 25));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        VideoInfoGB = new QGroupBox(centralWidget);
        VideoInfoGB->setObjectName(QString::fromUtf8("VideoInfoGB"));
        VideoInfoGB->setGeometry(QRect(574, 4, 162, 188));
        VideoInfoGB->setAlignment(Qt::AlignCenter);
        EncoderLabel = new QLabel(VideoInfoGB);
        EncoderLabel->setObjectName(QString::fromUtf8("EncoderLabel"));
        EncoderLabel->setGeometry(QRect(16, 19, 49, 16));
        DurationLabel = new QLabel(VideoInfoGB);
        DurationLabel->setObjectName(QString::fromUtf8("DurationLabel"));
        DurationLabel->setGeometry(QRect(16, 34, 62, 20));
        ResolutionLabel = new QLabel(VideoInfoGB);
        ResolutionLabel->setObjectName(QString::fromUtf8("ResolutionLabel"));
        ResolutionLabel->setGeometry(QRect(16, 51, 63, 20));
        VidBitrateLabel = new QLabel(VideoInfoGB);
        VidBitrateLabel->setObjectName(QString::fromUtf8("VidBitrateLabel"));
        VidBitrateLabel->setGeometry(QRect(16, 71, 49, 16));
        ColorsLabel = new QLabel(VideoInfoGB);
        ColorsLabel->setObjectName(QString::fromUtf8("ColorsLabel"));
        ColorsLabel->setGeometry(QRect(16, 89, 43, 16));
        FPSLabel = new QLabel(VideoInfoGB);
        FPSLabel->setObjectName(QString::fromUtf8("FPSLabel"));
        FPSLabel->setGeometry(QRect(16, 160, 67, 16));
        MatrixLabel = new QLabel(VideoInfoGB);
        MatrixLabel->setObjectName(QString::fromUtf8("MatrixLabel"));
        MatrixLabel->setGeometry(QRect(16, 107, 75, 16));
        TransferLabel = new QLabel(VideoInfoGB);
        TransferLabel->setObjectName(QString::fromUtf8("TransferLabel"));
        TransferLabel->setGeometry(QRect(16, 125, 49, 16));
        VidformatValueLabel = new QLabel(VideoInfoGB);
        VidformatValueLabel->setObjectName(QString::fromUtf8("VidformatValueLabel"));
        VidformatValueLabel->setGeometry(QRect(65, 19, 82, 16));
        VidformatValueLabel->setFont(font);
        VidformatValueLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
        ResolutionValueLabel = new QLabel(VideoInfoGB);
        ResolutionValueLabel->setObjectName(QString::fromUtf8("ResolutionValueLabel"));
        ResolutionValueLabel->setGeometry(QRect(77, 53, 70, 16));
        ResolutionValueLabel->setFont(font);
        ResolutionValueLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
        BitrateValueLabel = new QLabel(VideoInfoGB);
        BitrateValueLabel->setObjectName(QString::fromUtf8("BitrateValueLabel"));
        BitrateValueLabel->setGeometry(QRect(55, 71, 92, 16));
        BitrateValueLabel->setFont(font);
        BitrateValueLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
        ColorsValueLabel = new QLabel(VideoInfoGB);
        ColorsValueLabel->setObjectName(QString::fromUtf8("ColorsValueLabel"));
        ColorsValueLabel->setGeometry(QRect(53, 84, 94, 25));
        ColorsValueLabel->setFont(font);
        ColorsValueLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
        FPSValueLabel = new QLabel(VideoInfoGB);
        FPSValueLabel->setObjectName(QString::fromUtf8("FPSValueLabel"));
        FPSValueLabel->setGeometry(QRect(78, 160, 69, 16));
        FPSValueLabel->setFont(font);
        FPSValueLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
        DurationValueLabel = new QLabel(VideoInfoGB);
        DurationValueLabel->setObjectName(QString::fromUtf8("DurationValueLabel"));
        DurationValueLabel->setGeometry(QRect(71, 36, 76, 16));
        DurationValueLabel->setFont(font);
        DurationValueLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
        MatrixValueLabel = new QLabel(VideoInfoGB);
        MatrixValueLabel->setObjectName(QString::fromUtf8("MatrixValueLabel"));
        MatrixValueLabel->setGeometry(QRect(55, 107, 92, 16));
        MatrixValueLabel->setFont(font);
        MatrixValueLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
        TransferValueLabel = new QLabel(VideoInfoGB);
        TransferValueLabel->setObjectName(QString::fromUtf8("TransferValueLabel"));
        TransferValueLabel->setGeometry(QRect(65, 125, 82, 16));
        TransferValueLabel->setFont(font);
        TransferValueLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
        PrimariesLabel = new QLabel(VideoInfoGB);
        PrimariesLabel->setObjectName(QString::fromUtf8("PrimariesLabel"));
        PrimariesLabel->setGeometry(QRect(16, 143, 55, 16));
        PrimariesValueLabel = new QLabel(VideoInfoGB);
        PrimariesValueLabel->setObjectName(QString::fromUtf8("PrimariesValueLabel"));
        PrimariesValueLabel->setGeometry(QRect(72, 143, 75, 16));
        PrimariesValueLabel->setFont(font);
        PrimariesValueLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
        SaveOutTxtBox = new QLineEdit(centralWidget);
        SaveOutTxtBox->setObjectName(QString::fromUtf8("SaveOutTxtBox"));
        SaveOutTxtBox->setEnabled(true);
        SaveOutTxtBox->setGeometry(QRect(6, 326, 370, 23));
        SaveOutTxtBox->setReadOnly(true);
        OutContainerx264DD = new QComboBox(centralWidget);
        OutContainerx264DD->addItem(QString());
        OutContainerx264DD->addItem(QString());
        OutContainerx264DD->addItem(QString());
        OutContainerx264DD->addItem(QString());
        OutContainerx264DD->addItem(QString());
        OutContainerx264DD->addItem(QString());
        OutContainerx264DD->addItem(QString());
        OutContainerx264DD->addItem(QString());
        OutContainerx264DD->setObjectName(QString::fromUtf8("OutContainerx264DD"));
        OutContainerx264DD->setGeometry(QRect(382, 326, 58, 23));
        SaveOutBttn = new QPushButton(centralWidget);
        SaveOutBttn->setObjectName(QString::fromUtf8("SaveOutBttn"));
        SaveOutBttn->setGeometry(QRect(446, 326, 87, 24));
        PreviewBttn = new QPushButton(centralWidget);
        PreviewBttn->setObjectName(QString::fromUtf8("PreviewBttn"));
        PreviewBttn->setGeometry(QRect(538, 326, 60, 24));
        AddJobBttn = new QPushButton(centralWidget);
        AddJobBttn->setObjectName(QString::fromUtf8("AddJobBttn"));
        AddJobBttn->setGeometry(QRect(603, 326, 68, 24));
        StartBttn = new QPushButton(centralWidget);
        StartBttn->setObjectName(QString::fromUtf8("StartBttn"));
        StartBttn->setGeometry(QRect(676, 326, 61, 24));
        StartBttn->setFont(font);
        AudioInfoGB = new QGroupBox(centralWidget);
        AudioInfoGB->setObjectName(QString::fromUtf8("AudioInfoGB"));
        AudioInfoGB->setGeometry(QRect(574, 194, 162, 127));
        AudioInfoGB->setAlignment(Qt::AlignCenter);
        SampleRateLabel = new QLabel(AudioInfoGB);
        SampleRateLabel->setObjectName(QString::fromUtf8("SampleRateLabel"));
        SampleRateLabel->setGeometry(QRect(16, 83, 67, 16));
        AudioLanguageLabel = new QLabel(AudioInfoGB);
        AudioLanguageLabel->setObjectName(QString::fromUtf8("AudioLanguageLabel"));
        AudioLanguageLabel->setGeometry(QRect(16, 64, 57, 16));
        SampleRateValueLabel = new QLabel(AudioInfoGB);
        SampleRateValueLabel->setObjectName(QString::fromUtf8("SampleRateValueLabel"));
        SampleRateValueLabel->setGeometry(QRect(78, 83, 69, 16));
        SampleRateValueLabel->setFont(font);
        SampleRateValueLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
        TrackLabel = new QLabel(AudioInfoGB);
        TrackLabel->setObjectName(QString::fromUtf8("TrackLabel"));
        TrackLabel->setGeometry(QRect(16, 22, 75, 16));
        AudioLanguageValueLabel = new QLabel(AudioInfoGB);
        AudioLanguageValueLabel->setObjectName(QString::fromUtf8("AudioLanguageValueLabel"));
        AudioLanguageValueLabel->setGeometry(QRect(72, 64, 75, 16));
        AudioLanguageValueLabel->setFont(font);
        AudioLanguageValueLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
        FormatLabel = new QLabel(AudioInfoGB);
        FormatLabel->setObjectName(QString::fromUtf8("FormatLabel"));
        FormatLabel->setGeometry(QRect(16, 46, 49, 16));
        ChannelsLabel = new QLabel(AudioInfoGB);
        ChannelsLabel->setObjectName(QString::fromUtf8("ChannelsLabel"));
        ChannelsLabel->setGeometry(QRect(16, 100, 49, 16));
        ChannelsValueLabel = new QLabel(AudioInfoGB);
        ChannelsValueLabel->setObjectName(QString::fromUtf8("ChannelsValueLabel"));
        ChannelsValueLabel->setGeometry(QRect(45, 100, 102, 16));
        ChannelsValueLabel->setFont(font);
        ChannelsValueLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
        FormatValueLabel = new QLabel(AudioInfoGB);
        FormatValueLabel->setObjectName(QString::fromUtf8("FormatValueLabel"));
        FormatValueLabel->setGeometry(QRect(65, 46, 82, 16));
        FormatValueLabel->setFont(font);
        FormatValueLabel->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
        AudioTrackDD = new QComboBox(AudioInfoGB);
        AudioTrackDD->setObjectName(QString::fromUtf8("AudioTrackDD"));
        AudioTrackDD->setEnabled(false);
        AudioTrackDD->setGeometry(QRect(111, 21, 37, 21));
        ProgressBarLabel = new QLabel(centralWidget);
        ProgressBarLabel->setObjectName(QString::fromUtf8("ProgressBarLabel"));
        ProgressBarLabel->setGeometry(QRect(8, 356, 726, 22));
        ProgressBarLabel->setFont(font);
        ProgressBarLabel->setAlignment(Qt::AlignCenter);
        OutContainerx265DD = new QComboBox(centralWidget);
        OutContainerx265DD->addItem(QString());
        OutContainerx265DD->addItem(QString());
        OutContainerx265DD->addItem(QString());
        OutContainerx265DD->addItem(QString());
        OutContainerx265DD->setObjectName(QString::fromUtf8("OutContainerx265DD"));
        OutContainerx265DD->setGeometry(QRect(382, 326, 58, 23));
        OutContainerProResDD = new QComboBox(centralWidget);
        OutContainerProResDD->addItem(QString());
        OutContainerProResDD->addItem(QString());
        OutContainerProResDD->addItem(QString());
        OutContainerProResDD->setObjectName(QString::fromUtf8("OutContainerProResDD"));
        OutContainerProResDD->setGeometry(QRect(382, 326, 58, 23));
        OutContainerTheoraDD = new QComboBox(centralWidget);
        OutContainerTheoraDD->addItem(QString());
        OutContainerTheoraDD->addItem(QString());
        OutContainerTheoraDD->addItem(QString());
        OutContainerTheoraDD->setObjectName(QString::fromUtf8("OutContainerTheoraDD"));
        OutContainerTheoraDD->setGeometry(QRect(382, 326, 58, 23));
        OutContainerVPXDD = new QComboBox(centralWidget);
        OutContainerVPXDD->addItem(QString());
        OutContainerVPXDD->addItem(QString());
        OutContainerVPXDD->addItem(QString());
        OutContainerVPXDD->addItem(QString());
        OutContainerVPXDD->addItem(QString());
        OutContainerVPXDD->setObjectName(QString::fromUtf8("OutContainerVPXDD"));
        OutContainerVPXDD->setGeometry(QRect(382, 326, 58, 23));
        OutContainerAV1DD = new QComboBox(centralWidget);
        OutContainerAV1DD->addItem(QString());
        OutContainerAV1DD->addItem(QString());
        OutContainerAV1DD->addItem(QString());
        OutContainerAV1DD->addItem(QString());
        OutContainerAV1DD->addItem(QString());
        OutContainerAV1DD->setObjectName(QString::fromUtf8("OutContainerAV1DD"));
        OutContainerAV1DD->setGeometry(QRect(382, 326, 58, 23));
        OutContainerMuxDD = new QComboBox(centralWidget);
        OutContainerMuxDD->addItem(QString());
        OutContainerMuxDD->addItem(QString());
        OutContainerMuxDD->addItem(QString());
        OutContainerMuxDD->addItem(QString());
        OutContainerMuxDD->addItem(QString());
        OutContainerMuxDD->addItem(QString());
        OutContainerMuxDD->addItem(QString());
        OutContainerMuxDD->addItem(QString());
        OutContainerMuxDD->addItem(QString());
        OutContainerMuxDD->addItem(QString());
        OutContainerMuxDD->setObjectName(QString::fromUtf8("OutContainerMuxDD"));
        OutContainerMuxDD->setGeometry(QRect(382, 326, 58, 23));
        EncodeGUIMV->setCentralWidget(centralWidget);
        QWidget::setTabOrder(SelectInBttn, VideoEncDD);
        QWidget::setTabOrder(VideoEncDD, AudioCB);
        QWidget::setTabOrder(AudioCB, AudioDD);
        QWidget::setTabOrder(AudioDD, SubtitlesCB);
        QWidget::setTabOrder(SubtitlesCB, SubtitlesDD);
        QWidget::setTabOrder(SubtitlesDD, ChaptersCB);
        QWidget::setTabOrder(ChaptersCB, PauseBttn);
        QWidget::setTabOrder(PauseBttn, CancelBttn);
        QWidget::setTabOrder(CancelBttn, WhenEncCompleteDD);
        QWidget::setTabOrder(WhenEncCompleteDD, AudioTrackDD);
        QWidget::setTabOrder(AudioTrackDD, SampleVidCB);
        QWidget::setTabOrder(SampleVidCB, GetVidInfoCB);
        QWidget::setTabOrder(GetVidInfoCB, BatchCB);
        QWidget::setTabOrder(BatchCB, OutContainerx264DD);
        QWidget::setTabOrder(OutContainerx264DD, SaveOutBttn);
        QWidget::setTabOrder(SaveOutBttn, PreviewBttn);
        QWidget::setTabOrder(PreviewBttn, AddJobBttn);
        QWidget::setTabOrder(AddJobBttn, StartBttn);
        QWidget::setTabOrder(StartBttn, Bitrate264NUD);
        QWidget::setTabOrder(Bitrate264NUD, Tune264CB);
        QWidget::setTabOrder(Tune264CB, Tune264DD);
        QWidget::setTabOrder(Tune264DD, Preset264CB);
        QWidget::setTabOrder(Preset264CB, Preset264DD);
        QWidget::setTabOrder(Preset264DD, Quantizer264NUD);
        QWidget::setTabOrder(Quantizer264NUD, CRFValue264NUD);
        QWidget::setTabOrder(CRFValue264NUD, Tabs);
        QWidget::setTabOrder(Tabs, OutContainerx265DD);
        QWidget::setTabOrder(OutContainerx265DD, OutContainerProResDD);
        QWidget::setTabOrder(OutContainerProResDD, OutContainerTheoraDD);
        QWidget::setTabOrder(OutContainerTheoraDD, OutContainerVPXDD);
        QWidget::setTabOrder(OutContainerVPXDD, EncodeMode264DD);
        QWidget::setTabOrder(EncodeMode264DD, ColorSpace264DD);
        QWidget::setTabOrder(ColorSpace264DD, RefFrames264GB);
        QWidget::setTabOrder(RefFrames264GB, Reference264Sldr);
        QWidget::setTabOrder(Reference264Sldr, x264Tabs);
        QWidget::setTabOrder(x264Tabs, BFrames264GB);
        QWidget::setTabOrder(BFrames264GB, BFrame264Sldr);
        QWidget::setTabOrder(BFrame264Sldr, x265Tabs);
        QWidget::setTabOrder(x265Tabs, BitDepth265DD);
        QWidget::setTabOrder(BitDepth265DD, ColorSpace265DD);
        QWidget::setTabOrder(ColorSpace265DD, Profile265GB);
        QWidget::setTabOrder(Profile265GB, Profile265DD);
        QWidget::setTabOrder(Profile265DD, Level265DD);
        QWidget::setTabOrder(Level265DD, Tier265DD);
        QWidget::setTabOrder(Tier265DD, EncodeMode265DD);
        QWidget::setTabOrder(EncodeMode265DD, Hardware265CB);
        QWidget::setTabOrder(Hardware265CB, Hardware265DD);
        QWidget::setTabOrder(Hardware265DD, Bitrate265NUD);
        QWidget::setTabOrder(Bitrate265NUD, Tune265CB);
        QWidget::setTabOrder(Tune265CB, Tune265DD);
        QWidget::setTabOrder(Tune265DD, Preset265CB);
        QWidget::setTabOrder(Preset265CB, Preset265DD);
        QWidget::setTabOrder(Preset265DD, Quantizer265NUD);
        QWidget::setTabOrder(Quantizer265NUD, CRFValue265NUD);
        QWidget::setTabOrder(CRFValue265NUD, EncodeMode265HWDD);
        QWidget::setTabOrder(EncodeMode265HWDD, FastPass265CB);
        QWidget::setTabOrder(FastPass265CB, RefFrames265GB);
        QWidget::setTabOrder(RefFrames265GB, Reference265Sldr);
        QWidget::setTabOrder(Reference265Sldr, BFrames265GB);
        QWidget::setTabOrder(BFrames265GB, BFrame265Sldr);
        QWidget::setTabOrder(BFrame265Sldr, ProfileDD);
        QWidget::setTabOrder(ProfileDD, ColorsGB);
        QWidget::setTabOrder(ColorsGB, MatrixProResDD);
        QWidget::setTabOrder(MatrixProResDD, TransferProResDD);
        QWidget::setTabOrder(TransferProResDD, PrimairesProResDD);
        QWidget::setTabOrder(PrimairesProResDD, QualityNUD);
        QWidget::setTabOrder(QualityNUD, EncodeModeTDD);
        QWidget::setTabOrder(EncodeModeTDD, BitrateThNUD);
        QWidget::setTabOrder(BitrateThNUD, EncodeModeVPXDD);
        QWidget::setTabOrder(EncodeModeVPXDD, BitrateVPXNUD);
        QWidget::setTabOrder(BitrateVPXNUD, crfVPXNUD);
        QWidget::setTabOrder(crfVPXNUD, ProfileVPXDD);
        QWidget::setTabOrder(ProfileVPXDD, SpeedDD);
        QWidget::setTabOrder(SpeedDD, BitDepthVPXDD);
        QWidget::setTabOrder(BitDepthVPXDD, SampleVPXDD);
        QWidget::setTabOrder(SampleVPXDD, VSTabs);
        QWidget::setTabOrder(VSTabs, InterpolationCB);
        QWidget::setTabOrder(InterpolationCB, ToolInterpDD);
        QWidget::setTabOrder(ToolInterpDD, UseGPUCB);
        QWidget::setTabOrder(UseGPUCB, GPUInterpDD);
        QWidget::setTabOrder(GPUInterpDD, GPUThreadDD);
        QWidget::setTabOrder(GPUThreadDD, ModelInterpDD);
        QWidget::setTabOrder(ModelInterpDD, SceneChangeCB);
        QWidget::setTabOrder(SceneChangeCB, OutputFPSNUD);
        QWidget::setTabOrder(OutputFPSNUD, BackendDD);
        QWidget::setTabOrder(BackendDD, RIFEModelVKDD);
        QWidget::setTabOrder(RIFEModelVKDD, RIFEModelCADD);
        QWidget::setTabOrder(RIFEModelCADD, ShaderDD);
        QWidget::setTabOrder(ShaderDD, ParamsCB);
        QWidget::setTabOrder(ParamsCB, InterpModeDD);
        QWidget::setTabOrder(InterpModeDD, ArtefactMaskDD);
        QWidget::setTabOrder(ArtefactMaskDD, SuperTxtBox);
        QWidget::setTabOrder(SuperTxtBox, AnalyseTxtBox);
        QWidget::setTabOrder(AnalyseTxtBox, SmoothTxtBox);
        QWidget::setTabOrder(SmoothTxtBox, UpscalingGB);
        QWidget::setTabOrder(UpscalingGB, ToolUpscaleDD);
        QWidget::setTabOrder(ToolUpscaleDD, GPUThreadUpscaleDD);
        QWidget::setTabOrder(GPUThreadUpscaleDD, GPUUpscaleDD);
        QWidget::setTabOrder(GPUUpscaleDD, ModelUpscaleDD);
        QWidget::setTabOrder(ModelUpscaleDD, NoiseReduc2xDD);
        QWidget::setTabOrder(NoiseReduc2xDD, Precision2xDD);
        QWidget::setTabOrder(Precision2xDD, Width2xNUD);
        QWidget::setTabOrder(Width2xNUD, Height2xNUD);
        QWidget::setTabOrder(Height2xNUD, AutoAdjDD);
        QWidget::setTabOrder(AutoAdjDD, AutoAdjCB);
        QWidget::setTabOrder(AutoAdjCB, TTA2xCB);
        QWidget::setTabOrder(TTA2xCB, ColorPropsGB);
        QWidget::setTabOrder(ColorPropsGB, InputMatrixDD);
        QWidget::setTabOrder(InputMatrixDD, InputTransferDD);
        QWidget::setTabOrder(InputTransferDD, InputPrimsDD);
        QWidget::setTabOrder(InputPrimsDD, OutputMatrixDD);
        QWidget::setTabOrder(OutputMatrixDD, OutputTransferDD);
        QWidget::setTabOrder(OutputTransferDD, OutputPrimsDD);
        QWidget::setTabOrder(OutputPrimsDD, FiltersTabs);
        QWidget::setTabOrder(FiltersTabs, ResizeGB);
        QWidget::setTabOrder(ResizeGB, WidthNUD);
        QWidget::setTabOrder(WidthNUD, HeightNUD);
        QWidget::setTabOrder(HeightNUD, AutoAdjResDD);
        QWidget::setTabOrder(AutoAdjResDD, AutoAdjResCB);
        QWidget::setTabOrder(AutoAdjResCB, ResizeAlgoCB);
        QWidget::setTabOrder(ResizeAlgoCB, ResizeAlgoDD);
        QWidget::setTabOrder(ResizeAlgoDD, RotateGB);
        QWidget::setTabOrder(RotateGB, AngleDD);
        QWidget::setTabOrder(AngleDD, FlipCB);
        QWidget::setTabOrder(FlipCB, FlipDD);
        QWidget::setTabOrder(FlipDD, NoAutoRotateCB);
        QWidget::setTabOrder(NoAutoRotateCB, CropGB);
        QWidget::setTabOrder(CropGB, OutWidthNUD);
        QWidget::setTabOrder(OutWidthNUD, OutHeightNUD);
        QWidget::setTabOrder(OutHeightNUD, EksNUD);
        QWidget::setTabOrder(EksNUD, WhyNUD);
        QWidget::setTabOrder(WhyNUD, SharpenGB);
        QWidget::setTabOrder(SharpenGB, RadiusDD);
        QWidget::setTabOrder(RadiusDD, StrengthDD);
        QWidget::setTabOrder(StrengthDD, SelectedAudioDD);
        QWidget::setTabOrder(SelectedAudioDD, EncodingAudioGB);
        QWidget::setTabOrder(EncodingAudioGB, AudioEncoderDD);
        QWidget::setTabOrder(AudioEncoderDD, AudioBitrateNUD);
        QWidget::setTabOrder(AudioBitrateNUD, DownmixCB);
        QWidget::setTabOrder(DownmixCB, DownmixDD);
        QWidget::setTabOrder(DownmixDD, AudioQualityNUD);
        QWidget::setTabOrder(AudioQualityNUD, AddAudioJobBttn);
        QWidget::setTabOrder(AddAudioJobBttn, AudioTitleCB);
        QWidget::setTabOrder(AudioTitleCB, AudioTitleTxtBox);
        QWidget::setTabOrder(AudioTitleTxtBox, SettingsTabs);
        QWidget::setTabOrder(SettingsTabs, EnablePreviewCB);
        QWidget::setTabOrder(EnablePreviewCB, AutoDelSourceCB);
        QWidget::setTabOrder(AutoDelSourceCB, ErrorMessageCB);
        QWidget::setTabOrder(ErrorMessageCB, JobsCB);
        QWidget::setTabOrder(JobsCB, FPSCB);
        QWidget::setTabOrder(FPSCB, BitrateCB);
        QWidget::setTabOrder(BitrateCB, TimeLeftCB);
        QWidget::setTabOrder(TimeLeftCB, TimeElapsedCB);
        QWidget::setTabOrder(TimeElapsedCB, PercentageCB);
        QWidget::setTabOrder(PercentageCB, LimitThreadsNUD);
        QWidget::setTabOrder(LimitThreadsNUD, LimitThreadsCB);
        QWidget::setTabOrder(LimitThreadsCB, ClearJobsBttn);
        QWidget::setTabOrder(ClearJobsBttn, CancelQueueBttn);
        QWidget::setTabOrder(CancelQueueBttn, LogsOutRTxtBox);
        QWidget::setTabOrder(LogsOutRTxtBox, LogsDirBttn);
        QWidget::setTabOrder(LogsDirBttn, DonateToDaGooseBttn);
        QWidget::setTabOrder(DonateToDaGooseBttn, DonateToGlitchBttn);
        QWidget::setTabOrder(DonateToGlitchBttn, YoutubeBttn);
        QWidget::setTabOrder(YoutubeBttn, DiscordBttn);
        QWidget::setTabOrder(DiscordBttn, InstaBttn);
        QWidget::setTabOrder(InstaBttn, SaveOutTxtBox);
        QWidget::setTabOrder(SaveOutTxtBox, SelectInTxtBox);
        QWidget::setTabOrder(SelectInTxtBox, EntropyCode264DD);
        QWidget::setTabOrder(EntropyCode264DD, BitDepth264DD);
        QWidget::setTabOrder(BitDepth264DD, Hardware264CB);
        QWidget::setTabOrder(Hardware264CB, Hardware264DD);
        QWidget::setTabOrder(Hardware264DD, VideoTabs);
        QWidget::setTabOrder(VideoTabs, EncodeMode264HWDD);
        QWidget::setTabOrder(EncodeMode264HWDD, Profile264GB);
        QWidget::setTabOrder(Profile264GB, Profile264DD);
        QWidget::setTabOrder(Profile264DD, Level264DD);

        retranslateUi(EncodeGUIMV);

        Tabs->setCurrentIndex(0);
        VideoTabs->setCurrentIndex(0);
        x264Tabs->setCurrentIndex(0);
        x265Tabs->setCurrentIndex(0);
        SignalsTabs->setCurrentIndex(0);
        VSTabs->setCurrentIndex(0);
        ToolInterpDD->setCurrentIndex(0);
        GPUThreadDD->setCurrentIndex(1);
        ToolUpscaleDD->setCurrentIndex(0);
        GPUThreadUpscaleDD->setCurrentIndex(1);
        NoiseReduc2xDD->setCurrentIndex(2);
        AutoAdjDD->setCurrentIndex(1);
        FiltersTabs->setCurrentIndex(0);
        AutoAdjResDD->setCurrentIndex(1);
        SettingsTabs->setCurrentIndex(0);
        StartBttn->setDefault(false);


        QMetaObject::connectSlotsByName(EncodeGUIMV);
    } // setupUi

    void retranslateUi(QMainWindow* EncodeGUIMV)
    {
        EncodeGUIMV->setWindowTitle(QCoreApplication::translate("EncodeGUIMV", "EncodeGUI v1.2.3", nullptr));
#if QT_CONFIG(tooltip)
        EGUILogo->setToolTip(QCoreApplication::translate("EncodeGUIMV", "EncodeGUI :)", nullptr));
#endif // QT_CONFIG(tooltip)
        EGUILogo->setText(QString());
        InputGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Input", nullptr));
#if QT_CONFIG(tooltip)
        GetVidInfoCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Gets the media info of the source video.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        GetVidInfoCB->setText(QCoreApplication::translate("EncodeGUIMV", "Get media info", nullptr));
#if QT_CONFIG(tooltip)
        SampleVidCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Imports a sample video to use</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        SampleVidCB->setText(QCoreApplication::translate("EncodeGUIMV", "Sample video", nullptr));
#if QT_CONFIG(tooltip)
        BatchCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Assumes the color spaces for the input if they are unspecified.", nullptr));
#endif // QT_CONFIG(tooltip)
        BatchCB->setText(QCoreApplication::translate("EncodeGUIMV", "Batch (folder)", nullptr));
        EGUIGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "EncodeGUI", nullptr));
        VideoEncDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "AVC", nullptr));
        VideoEncDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "HEVC", nullptr));
        VideoEncDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "ProRes", nullptr));
        VideoEncDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "Theora", nullptr));
        VideoEncDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "VP9", nullptr));
        VideoEncDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "AV1", nullptr));
        VideoEncDD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "Muxing", nullptr));

#if QT_CONFIG(tooltip)
        VideoEncDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The video encoder to use.", nullptr));
#endif // QT_CONFIG(tooltip)
        VidEncLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Video codec:", nullptr));
#if QT_CONFIG(tooltip)
        AudioCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Checked: enable audio</p><p>Unchecked: disable/mute all audio</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        AudioCB->setText(QCoreApplication::translate("EncodeGUIMV", "Audio:", nullptr));
        AudioDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Passthrough", nullptr));
        AudioDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Encode", nullptr));

#if QT_CONFIG(tooltip)
        AudioDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Passthrough: passthrough all audio without any changes</p><p>Encode: allows encoding of the audio and enables &quot;Audio&quot; tab</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        SubtitlesCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Checked: enable all subtitles</p><p>Unchecked: delete all subtitles</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        SubtitlesCB->setText(QCoreApplication::translate("EncodeGUIMV", "Subtitles:", nullptr));
        SubtitlesDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Passthrough", nullptr));
        SubtitlesDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Auto encode", nullptr));
        SubtitlesDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Encode", nullptr));

#if QT_CONFIG(tooltip)
        SubtitlesDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Passthrough: passthrough all subtitles without any changes</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        ChaptersCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables chapters for the video.", nullptr));
#endif // QT_CONFIG(tooltip)
        ChaptersCB->setText(QString());
        ChaptersLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Use chapters:", nullptr));
        CurrenProcGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Current Job", nullptr));
        WhenEncCompleteLabel->setText(QCoreApplication::translate("EncodeGUIMV", "When all jobs are complete:", nullptr));
        WhenEncCompleteDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Do nothing", nullptr));
        WhenEncCompleteDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Close app", nullptr));
        WhenEncCompleteDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Sign out", nullptr));
        WhenEncCompleteDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "Shutdown", nullptr));

#if QT_CONFIG(tooltip)
        WhenEncCompleteDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Sets the system state when all encoding jobs are complete.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        PauseBttn->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Pauses the current running job.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        PauseBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Pause", nullptr));
#if QT_CONFIG(tooltip)
        CancelBttn->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Cancels the current running process.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        CancelBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Cancel", nullptr));
        JobIDLabel->setText(QCoreApplication::translate("EncodeGUIMV", "ID:", nullptr));
        JobStatusLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Status:", nullptr));
        JobStartLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Start date/time:", nullptr));
        JobIDValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700; color:#008000;\">?</span></p></body></html>", nullptr));
        JobStatusValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700; color:#008000;\">?</span></p></body></html>", nullptr));
        JobStartValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700; color:#008000;\">?</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        SelectInTxtBox->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The selected source video file path.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        SelectInBttn->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Opens a file dialog to select a source file.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        SelectInBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Select input", nullptr));
        Tabs->setTabText(Tabs->indexOf(HomeTab), QCoreApplication::translate("EncodeGUIMV", "Main", nullptr));
        EncodingSetting264GB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Encoding", nullptr));
        EncodeMode264Label->setText(QCoreApplication::translate("EncodeGUIMV", "Mode:", nullptr));
        EncodeMode264DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Constant rate factor (1 pass)", nullptr));
        EncodeMode264DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Average bitrate (1 pass)", nullptr));
        EncodeMode264DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Target bitrate (2 pass)", nullptr));
        EncodeMode264DD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "Constant quantizer (1 pass)", nullptr));

#if QT_CONFIG(tooltip)
        EncodeMode264DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The encoding mode to use. Recommended: Constant rate factor.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        Hardware264CB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Enables GPU hardware encoding for faster video encoding.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Hardware264CB->setText(QCoreApplication::translate("EncodeGUIMV", "Hardware:", nullptr));
        Hardware264DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "NVENC", nullptr));
        Hardware264DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "QuickSync", nullptr));
        Hardware264DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "AMF", nullptr));

#if QT_CONFIG(tooltip)
        Hardware264DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The GPU hardware encoder to use.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        Bitrate264NUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The output bitrate of the video.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        Tune264CB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Enables the video tuning selection.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Tune264CB->setText(QCoreApplication::translate("EncodeGUIMV", "Tune:", nullptr));
        Tune264DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Film", nullptr));
        Tune264DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Animation", nullptr));
        Tune264DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Grain", nullptr));
        Tune264DD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "Still Image", nullptr));
        Tune264DD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "Fast Decode", nullptr));
        Tune264DD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "Zero Latency", nullptr));
        Tune264DD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "PSNR", nullptr));
        Tune264DD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "SSIM", nullptr));

#if QT_CONFIG(tooltip)
        Tune264DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The video tuning to use. Set this to the type of source video you have.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        Preset264CB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Enables the CPU preset selection.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Preset264CB->setText(QCoreApplication::translate("EncodeGUIMV", "Preset:", nullptr));
        Preset264DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Ultra Fast", nullptr));
        Preset264DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Super Fast", nullptr));
        Preset264DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Very Fast", nullptr));
        Preset264DD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "Faster", nullptr));
        Preset264DD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "Fast", nullptr));
        Preset264DD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "Medium", nullptr));
        Preset264DD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "Slow", nullptr));
        Preset264DD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "Slower", nullptr));
        Preset264DD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "Very slow", nullptr));
        Preset264DD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "Placebo", nullptr));

#if QT_CONFIG(tooltip)
        Preset264DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The GPU preset to use. Recommended: Slow.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Quantizer264Label->setText(QCoreApplication::translate("EncodeGUIMV", "Quantization strength:", nullptr));
#if QT_CONFIG(tooltip)
        Quantizer264NUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The constant quantizer stregnth to use. Recommended: 17.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        CRFValue264NUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The constant rate factor value to use. Recommended: 17.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        CRFValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "CRF value:", nullptr));
        EncodeMode264HWDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Constant quantizer (1 pass)", nullptr));
        EncodeMode264HWDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Average bitrate (1 pass)", nullptr));
        EncodeMode264HWDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Target bitrate (2 pass)", nullptr));

#if QT_CONFIG(tooltip)
        EncodeMode264HWDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The encoding mode to use. Recommended: Constant quantizer.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Bitrate264Label->setText(QCoreApplication::translate("EncodeGUIMV", "Bitrate:", nullptr));
#if QT_CONFIG(tooltip)
        Profile264GB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Enables the AVC profiling.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Profile264GB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Profiling", nullptr));
        Profile264Label->setText(QCoreApplication::translate("EncodeGUIMV", "Profile:", nullptr));
        Profile264DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Baseline", nullptr));
        Profile264DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Main", nullptr));
        Profile264DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "High", nullptr));
        Profile264DD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "High 10", nullptr));
        Profile264DD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "High 4:2:2", nullptr));

#if QT_CONFIG(tooltip)
        Profile264DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The profile tier to use. Set this according to the resolution/frame rate of the source video.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Level264Label->setText(QCoreApplication::translate("EncodeGUIMV", "Level:", nullptr));
        Level264DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Unlimited", nullptr));
        Level264DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "5.2", nullptr));
        Level264DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "5.1", nullptr));
        Level264DD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "5.0", nullptr));
        Level264DD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "4.2", nullptr));
        Level264DD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "4.1", nullptr));
        Level264DD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "4.0", nullptr));
        Level264DD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "3.2", nullptr));
        Level264DD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "3.1", nullptr));
        Level264DD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "3.0", nullptr));
        Level264DD->setItemText(10, QCoreApplication::translate("EncodeGUIMV", "2.2", nullptr));
        Level264DD->setItemText(11, QCoreApplication::translate("EncodeGUIMV", "2.1", nullptr));
        Level264DD->setItemText(12, QCoreApplication::translate("EncodeGUIMV", "2.0", nullptr));
        Level264DD->setItemText(13, QCoreApplication::translate("EncodeGUIMV", "1.3", nullptr));
        Level264DD->setItemText(14, QCoreApplication::translate("EncodeGUIMV", "1.2", nullptr));
        Level264DD->setItemText(15, QCoreApplication::translate("EncodeGUIMV", "1.1", nullptr));
        Level264DD->setItemText(16, QCoreApplication::translate("EncodeGUIMV", "1b", nullptr));
        Level264DD->setItemText(17, QCoreApplication::translate("EncodeGUIMV", "1.0", nullptr));

#if QT_CONFIG(tooltip)
        Level264DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The level for the AVC profile. Use higher values for high frame rate/resolution videos.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        EntropyCode264Label->setText(QCoreApplication::translate("EncodeGUIMV", "Entropy coder:", nullptr));
        EntropyCode264DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "CABAC", nullptr));
        EntropyCode264DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "CAVLC", nullptr));

#if QT_CONFIG(tooltip)
        EntropyCode264DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Sets the entropy coder to use. Recommended: CABAC.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Colors264GB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Colors", nullptr));
        BitDepth264Label->setText(QCoreApplication::translate("EncodeGUIMV", "Bit depth:", nullptr));
        BitDepth264DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "8-bit", nullptr));
        BitDepth264DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "10-bit", nullptr));

#if QT_CONFIG(tooltip)
        BitDepth264DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Sets the output video color depth.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Space264Label->setText(QCoreApplication::translate("EncodeGUIMV", "Sampling:", nullptr));
        ColorSpace264DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "4:2:0", nullptr));
        ColorSpace264DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "4:2:2", nullptr));

#if QT_CONFIG(tooltip)
        ColorSpace264DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Sets the output video color sampling.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        x264Tabs->setTabText(x264Tabs->indexOf(Main264Tab), QCoreApplication::translate("EncodeGUIMV", "Main", nullptr));
#if QT_CONFIG(tooltip)
        RefFrames264GB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Enables manual reference frames selection.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        RefFrames264GB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Reference Frames", nullptr));
#if QT_CONFIG(tooltip)
        Reference264Sldr->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Adjusts the number of reference frames to use.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        BFrames264GB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Enables manual selection of b frames.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        BFrames264GB->setTitle(QCoreApplication::translate("EncodeGUIMV", "B Frames", nullptr));
#if QT_CONFIG(tooltip)
        BFrame264Sldr->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Sets the number of b frames to use.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        x264Tabs->setTabText(x264Tabs->indexOf(Fames264Tab), QCoreApplication::translate("EncodeGUIMV", "Frames", nullptr));
        VideoTabs->setTabText(VideoTabs->indexOf(x264Tab), QCoreApplication::translate("EncodeGUIMV", "AVC", nullptr));
        Colors265GB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Colors", nullptr));
        BitDepth265Label->setText(QCoreApplication::translate("EncodeGUIMV", "Bit depth:", nullptr));
        BitDepth265DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "8-bit", nullptr));
        BitDepth265DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "10-bit", nullptr));
        BitDepth265DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "12-bit", nullptr));

#if QT_CONFIG(tooltip)
        BitDepth265DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the output color depth for encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
        Sample265Label->setText(QCoreApplication::translate("EncodeGUIMV", "Sampling:", nullptr));
        ColorSpace265DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "4:2:0", nullptr));
        ColorSpace265DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "4:2:2", nullptr));
        ColorSpace265DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "4:4:4", nullptr));

#if QT_CONFIG(tooltip)
        ColorSpace265DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the output color sampling for encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        Profile265GB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables profiling for HEVC.", nullptr));
#endif // QT_CONFIG(tooltip)
        Profile265GB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Profiling", nullptr));
        Profile265Label->setText(QCoreApplication::translate("EncodeGUIMV", "Profile:", nullptr));
        Profile265DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Main", nullptr));
        Profile265DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Main 10", nullptr));
        Profile265DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Main 12", nullptr));
        Profile265DD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "Main 4:4:4", nullptr));

#if QT_CONFIG(tooltip)
        Profile265DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The profile to use.", nullptr));
#endif // QT_CONFIG(tooltip)
        Level265Label->setText(QCoreApplication::translate("EncodeGUIMV", "Level:", nullptr));
        Level265DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Unlimited", nullptr));
        Level265DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "8.5", nullptr));
        Level265DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "6.2", nullptr));
        Level265DD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "6.1", nullptr));
        Level265DD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "6.0", nullptr));
        Level265DD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "5.2", nullptr));
        Level265DD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "5.1", nullptr));
        Level265DD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "5.0", nullptr));
        Level265DD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "4.1", nullptr));
        Level265DD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "4.0", nullptr));
        Level265DD->setItemText(10, QCoreApplication::translate("EncodeGUIMV", "3.1", nullptr));
        Level265DD->setItemText(11, QCoreApplication::translate("EncodeGUIMV", "3.0", nullptr));
        Level265DD->setItemText(12, QCoreApplication::translate("EncodeGUIMV", "2.1", nullptr));
        Level265DD->setItemText(13, QCoreApplication::translate("EncodeGUIMV", "2.0", nullptr));
        Level265DD->setItemText(14, QCoreApplication::translate("EncodeGUIMV", "1.0", nullptr));

#if QT_CONFIG(tooltip)
        Level265DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The level for the profile to use.", nullptr));
#endif // QT_CONFIG(tooltip)
        Tier265Label->setText(QCoreApplication::translate("EncodeGUIMV", "Tier:", nullptr));
        Tier265DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "High", nullptr));
        Tier265DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Main", nullptr));

#if QT_CONFIG(tooltip)
        Tier265DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the tier for HEVC encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
        EncodingSetting265GB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Encoding", nullptr));
        EncodeMode265Label->setText(QCoreApplication::translate("EncodeGUIMV", "Mode:", nullptr));
        EncodeMode265DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Constant rate factor (1 pass)", nullptr));
        EncodeMode265DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Average bitrate (1 pass)", nullptr));
        EncodeMode265DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Target bitrate (2 pass)", nullptr));
        EncodeMode265DD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "Constant quantizer (1 pass)", nullptr));

#if QT_CONFIG(tooltip)
        EncodeMode265DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The encoding mode to use.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        Hardware265CB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables hardware encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
        Hardware265CB->setText(QCoreApplication::translate("EncodeGUIMV", "Hardware:", nullptr));
        Hardware265DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "NVENC", nullptr));
        Hardware265DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "QuickSync", nullptr));
        Hardware265DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "AMF", nullptr));

#if QT_CONFIG(tooltip)
        Hardware265DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Selects the hardware encoder to use.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        Bitrate265NUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The bitrate to encode in.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        Tune265CB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables tuning.", nullptr));
#endif // QT_CONFIG(tooltip)
        Tune265CB->setText(QCoreApplication::translate("EncodeGUIMV", "Tune:", nullptr));
        Tune265DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Animation", nullptr));
        Tune265DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Grain", nullptr));
        Tune265DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Fast Decode", nullptr));
        Tune265DD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "Zero Latency", nullptr));
        Tune265DD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "PSNR", nullptr));
        Tune265DD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "SSIM", nullptr));

#if QT_CONFIG(tooltip)
        Tune265DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Selects the tuning to use for encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        Preset265CB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables CPU presets.", nullptr));
#endif // QT_CONFIG(tooltip)
        Preset265CB->setText(QCoreApplication::translate("EncodeGUIMV", "Preset:", nullptr));
        Preset265DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Ultra Fast", nullptr));
        Preset265DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Super Fast", nullptr));
        Preset265DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Very Fast", nullptr));
        Preset265DD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "Faster", nullptr));
        Preset265DD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "Fast", nullptr));
        Preset265DD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "Medium", nullptr));
        Preset265DD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "Slow", nullptr));
        Preset265DD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "Slower", nullptr));
        Preset265DD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "Very slow", nullptr));
        Preset265DD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "Placebo", nullptr));

#if QT_CONFIG(tooltip)
        Preset265DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Selects the CPU preset to use for encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
        Quantizer265Label->setText(QCoreApplication::translate("EncodeGUIMV", "Quantization strength:", nullptr));
#if QT_CONFIG(tooltip)
        Quantizer265NUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the quantization strength for encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        CRFValue265NUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The CRF strength for encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
        CRFValue265Label->setText(QCoreApplication::translate("EncodeGUIMV", "CRF value:", nullptr));
        EncodeMode265HWDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Constant quantizer (1 pass)", nullptr));
        EncodeMode265HWDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Average bitrate (1 pass)", nullptr));
        EncodeMode265HWDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Target bitrate (2 pass)", nullptr));

#if QT_CONFIG(tooltip)
        EncodeMode265HWDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The hardware encoding mode to use.", nullptr));
#endif // QT_CONFIG(tooltip)
        Bitrate265Label->setText(QCoreApplication::translate("EncodeGUIMV", "Bitrate:", nullptr));
        FastPass265Label->setText(QCoreApplication::translate("EncodeGUIMV", "Fast first pass:", nullptr));
#if QT_CONFIG(tooltip)
        FastPass265CB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables fast first pass for 2 pass encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
        FastPass265CB->setText(QString());
        x265Tabs->setTabText(x265Tabs->indexOf(Main265Tab), QCoreApplication::translate("EncodeGUIMV", "Main", nullptr));
#if QT_CONFIG(tooltip)
        RefFrames265GB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables reference frames manual specification.", nullptr));
#endif // QT_CONFIG(tooltip)
        RefFrames265GB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Reference Frames", nullptr));
#if QT_CONFIG(tooltip)
        Reference265Sldr->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Adjusts the number of reference frames.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        BFrames265GB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables manual b-frames specification", nullptr));
#endif // QT_CONFIG(tooltip)
        BFrames265GB->setTitle(QCoreApplication::translate("EncodeGUIMV", "B Frames", nullptr));
#if QT_CONFIG(tooltip)
        BFrame265Sldr->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Adjusts the number of b-frames to use.", nullptr));
#endif // QT_CONFIG(tooltip)
        x265Tabs->setTabText(x265Tabs->indexOf(Fames265Tab), QCoreApplication::translate("EncodeGUIMV", "Frames", nullptr));
        VideoTabs->setTabText(VideoTabs->indexOf(x265Tab), QCoreApplication::translate("EncodeGUIMV", "HEVC", nullptr));
        EncodingProResGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Encoding", nullptr));
        ProfileLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Profile:", nullptr));
        ProfileDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "422 Proxy", nullptr));
        ProfileDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "422 LT", nullptr));
        ProfileDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "422", nullptr));
        ProfileDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "422 HQ", nullptr));
        ProfileDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "4444", nullptr));
        ProfileDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "4444 XQ", nullptr));

#if QT_CONFIG(tooltip)
        ProfileDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the ProRes profile for encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
        ColorsGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Color Space", nullptr));
        MatrixProResLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Matrix:", nullptr));
        MatrixProResDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Auto", nullptr));
        MatrixProResDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Unknown", nullptr));
        MatrixProResDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "BT709", nullptr));
        MatrixProResDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "SMPTE170m", nullptr));
        MatrixProResDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "BT2020nc", nullptr));

#if QT_CONFIG(tooltip)
        MatrixProResDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the color matrix in metadata.", nullptr));
#endif // QT_CONFIG(tooltip)
        TransferProResLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Transfer:", nullptr));
        TransferProResDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Auto", nullptr));
        TransferProResDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Unknown", nullptr));
        TransferProResDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "BT709", nullptr));
        TransferProResDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "SMPTE170m", nullptr));
        TransferProResDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "SMPTE2084", nullptr));

#if QT_CONFIG(tooltip)
        TransferProResDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the color transfer in metadata.", nullptr));
#endif // QT_CONFIG(tooltip)
        PrimariesProResLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Primaries:", nullptr));
        PrimairesProResDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Auto", nullptr));
        PrimairesProResDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Unknown", nullptr));
        PrimairesProResDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "BT709", nullptr));
        PrimairesProResDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "BT470bg", nullptr));
        PrimairesProResDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "SMPTE170m", nullptr));
        PrimairesProResDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "BT2020", nullptr));

#if QT_CONFIG(tooltip)
        PrimairesProResDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the color primaries in metadata.", nullptr));
#endif // QT_CONFIG(tooltip)
        VideoTabs->setTabText(VideoTabs->indexOf(ProResTab), QCoreApplication::translate("EncodeGUIMV", "ProRes", nullptr));
        EncodeTheoraGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Encoding", nullptr));
        QualityLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Quality:", nullptr));
#if QT_CONFIG(tooltip)
        QualityNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the constant quality value for encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
        EncodeModeTLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Mode:", nullptr));
        EncodeModeTDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Average bitrate (1 pass)", nullptr));
        EncodeModeTDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Constant Quality (1 pass)", nullptr));

#if QT_CONFIG(tooltip)
        EncodeModeTDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The encoding mode to use.", nullptr));
#endif // QT_CONFIG(tooltip)
        BitrateThLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Bitrate (kbits/s):", nullptr));
#if QT_CONFIG(tooltip)
        BitrateThNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The bitrate for encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
        VideoTabs->setTabText(VideoTabs->indexOf(TheoraTab), QCoreApplication::translate("EncodeGUIMV", "Theora", nullptr));
        EncodingSettingVPXGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Encoding", nullptr));
        EncodeModeVPXLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Mode:", nullptr));
        EncodeModeVPXDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Constant rate factor (1 pass)", nullptr));
        EncodeModeVPXDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Average bitrate (1 pass)", nullptr));
        EncodeModeVPXDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Target bitrate (2 pass)", nullptr));

#if QT_CONFIG(tooltip)
        EncodeModeVPXDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The encoding mode to use.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        BitrateVPXNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The bitrate to use for encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        crfVPXNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The CRF strength value to use for encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
        crfVPXLabel->setText(QCoreApplication::translate("EncodeGUIMV", "CRF Value:", nullptr));
        BitrateVPXLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Bitrate:", nullptr));
        ProfileVPXGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Profiling", nullptr));
        Profile264Label_2->setText(QCoreApplication::translate("EncodeGUIMV", "Profile:", nullptr));
        ProfileVPXDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Low", nullptr));
        ProfileVPXDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Simple", nullptr));
        ProfileVPXDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Complex", nullptr));
        ProfileVPXDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "Full", nullptr));

#if QT_CONFIG(tooltip)
        ProfileVPXDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the VP9 profile for encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
        SpeedLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Speed:", nullptr));
        SpeedDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Good", nullptr));
        SpeedDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Best", nullptr));

#if QT_CONFIG(tooltip)
        SpeedDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the speed control for VP9.", nullptr));
#endif // QT_CONFIG(tooltip)
        ColorsVPXGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Colors", nullptr));
        BitDepthVPXLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Bit depth:", nullptr));
        BitDepthVPXDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "10-bit", nullptr));
        BitDepthVPXDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "12-bit", nullptr));

#if QT_CONFIG(tooltip)
        BitDepthVPXDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the output color depth.", nullptr));
#endif // QT_CONFIG(tooltip)
        SampleVPXLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Sampling:", nullptr));
        SampleVPXDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "4:2:2", nullptr));
        SampleVPXDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "4:4:4", nullptr));

#if QT_CONFIG(tooltip)
        SampleVPXDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the output color sampling.", nullptr));
#endif // QT_CONFIG(tooltip)
        VideoTabs->setTabText(VideoTabs->indexOf(VPXTab), QCoreApplication::translate("EncodeGUIMV", "VP9", nullptr));
        EncodingSettingAV1GB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Encoding", nullptr));
        EncodeModeAV1Label->setText(QCoreApplication::translate("EncodeGUIMV", "Mode:", nullptr));
        EncodeModeAV1DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Constant rate factor (1 pass)", nullptr));
        EncodeModeAV1DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Average bitrate (1 pass)", nullptr));

#if QT_CONFIG(tooltip)
        EncodeModeAV1DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The encoding mode to use.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        BitrateAV1NUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The bitrate to use for encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        crfAV1NUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The CRF strength value to use for encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
        crfAV1Label->setText(QCoreApplication::translate("EncodeGUIMV", "CRF Value:", nullptr));
        BitrateAV1Label->setText(QCoreApplication::translate("EncodeGUIMV", "Bitrate:", nullptr));
        ColorsAV1GB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Colors", nullptr));
        BitDepthAV1Label->setText(QCoreApplication::translate("EncodeGUIMV", "Bit depth:", nullptr));
        BitDepthAV1DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "8-bit", nullptr));
        BitDepthAV1DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "10-bit", nullptr));

#if QT_CONFIG(tooltip)
        BitDepthAV1DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the output color depth.", nullptr));
#endif // QT_CONFIG(tooltip)
        VideoTabs->setTabText(VideoTabs->indexOf(av1Tab), QCoreApplication::translate("EncodeGUIMV", "AV1", nullptr));
#if QT_CONFIG(tooltip)
        HDRMetadataGB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables HDR metadata.", nullptr));
#endif // QT_CONFIG(tooltip)
        HDRMetadataGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "HDR10(+) Metadata", nullptr));
        LightLevelLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Light level (max cll/max fall):", nullptr));
        Slash6Label->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700;\">/</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        MaxCllNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Max Cll", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        MaxFallNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Max Fall", nullptr));
#endif // QT_CONFIG(tooltip)
        MasterDisplayLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Master display:", nullptr));
#if QT_CONFIG(tooltip)
        MasterDisplayTxtBox->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the mastering display for x265 HDR10.", nullptr));
#endif // QT_CONFIG(tooltip)
        MasterDisplayTxtBox->setText(QCoreApplication::translate("EncodeGUIMV", "G(13250,34500)B(7500,3000)R(34000,16000)WP(15635,16450)L(10000000,1)", nullptr));
        DynamicMetadataLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Dynamic metadata:", nullptr));
#if QT_CONFIG(tooltip)
        DynamicMetadataBttn->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Opens a dialog to select HDR10+ metadata file.", nullptr));
#endif // QT_CONFIG(tooltip)
        DynamicMetadataBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Select file", nullptr));
#if QT_CONFIG(tooltip)
        DynamicHDRTxtBox->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The path to the HDR10+ metadata file.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        DBVisionGB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables Dolby Vision metadata to import.", nullptr));
#endif // QT_CONFIG(tooltip)
        DBVisionGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Dolby Vision (beta - doesn't always work)", nullptr));
        DBProfileLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Profile:", nullptr));
        RpuLabel->setText(QCoreApplication::translate("EncodeGUIMV", "RPU File:", nullptr));
        DBProfileDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "5", nullptr));
        DBProfileDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "8.1", nullptr));
        DBProfileDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "8.2", nullptr));

#if QT_CONFIG(tooltip)
        DBProfileDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The Dolby Vision profile.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        RpuTxtBox->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The path to the RPU metadata file.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        RpuFileBttn->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Extracts the RPU file from the source video.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        RpuFileBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Extract from source", nullptr));
        SignalsTabs->setTabText(SignalsTabs->indexOf(HDRTab1), QCoreApplication::translate("EncodeGUIMV", "HDR", nullptr));
#if QT_CONFIG(tooltip)
        ColorsHDRGB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables color specification in x265 metadata.", nullptr));
#endif // QT_CONFIG(tooltip)
        ColorsHDRGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Colors", nullptr));
        ColorRangeLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Range:", nullptr));
        ColorMatrixLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Matrix:", nullptr));
        ColorTransferDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Unknown", nullptr));
        ColorTransferDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "BT709", nullptr));
        ColorTransferDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "BT470m", nullptr));
        ColorTransferDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "BT470bg", nullptr));
        ColorTransferDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "Log100", nullptr));
        ColorTransferDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "Log316", nullptr));
        ColorTransferDD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "SMPTE170m", nullptr));
        ColorTransferDD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "SMPTE240m", nullptr));
        ColorTransferDD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "SMPTE2084", nullptr));
        ColorTransferDD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "SMPTE428", nullptr));

#if QT_CONFIG(tooltip)
        ColorTransferDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the color transfer.", nullptr));
#endif // QT_CONFIG(tooltip)
        ColorPrimariesLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Primaries:", nullptr));
        ColorTransferLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Transfer:", nullptr));
        ColorRangeDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Limited", nullptr));
        ColorRangeDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Full", nullptr));

#if QT_CONFIG(tooltip)
        ColorRangeDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the color range.", nullptr));
#endif // QT_CONFIG(tooltip)
        ColorMatrixDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Unknown", nullptr));
        ColorMatrixDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "BT709", nullptr));
        ColorMatrixDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "FCC", nullptr));
        ColorMatrixDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "BT470bg", nullptr));
        ColorMatrixDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "SMPTE170m", nullptr));
        ColorMatrixDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "SMPTE240m", nullptr));
        ColorMatrixDD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "YCgCo", nullptr));
        ColorMatrixDD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "BT2020nc", nullptr));
        ColorMatrixDD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "BT2020c", nullptr));
        ColorMatrixDD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "SMTPE2085", nullptr));

#if QT_CONFIG(tooltip)
        ColorMatrixDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the color matrix.", nullptr));
#endif // QT_CONFIG(tooltip)
        ColorPrimariesDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Unknown", nullptr));
        ColorPrimariesDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "BT709", nullptr));
        ColorPrimariesDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "BT470m", nullptr));
        ColorPrimariesDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "BT470bg", nullptr));
        ColorPrimariesDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "SMPTE170m", nullptr));
        ColorPrimariesDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "SMPTE240m", nullptr));
        ColorPrimariesDD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "BT2020", nullptr));
        ColorPrimariesDD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "SMPTE428", nullptr));
        ColorPrimariesDD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "SMPTE431", nullptr));
        ColorPrimariesDD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "SMPTE432", nullptr));

#if QT_CONFIG(tooltip)
        ColorPrimariesDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the color primaries.", nullptr));
#endif // QT_CONFIG(tooltip)
        SignalsTabs->setTabText(SignalsTabs->indexOf(Colors3Tab), QCoreApplication::translate("EncodeGUIMV", "Colors", nullptr));
        VideoTabs->setTabText(VideoTabs->indexOf(HDRTab), QCoreApplication::translate("EncodeGUIMV", "Signals", nullptr));
#if QT_CONFIG(tooltip)
        InterpolationCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables frame interpolation.", nullptr));
#endif // QT_CONFIG(tooltip)
        InterpolationCB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Frame Interpolation", nullptr));
        ToolInterpDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "EncodeGUI AI", nullptr));
        ToolInterpDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "RIFE", nullptr));
        ToolInterpDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "SVPFlow", nullptr));

#if QT_CONFIG(tooltip)
        ToolInterpDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The tool to use for interpolation. </p><p>Recommended: EncodeGUI AI</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ToolInterpDD->setCurrentText(QCoreApplication::translate("EncodeGUIMV", "EncodeGUI AI", nullptr));
        ToolInterpLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Tool/Graphics backend:", nullptr));
#if QT_CONFIG(tooltip)
        UseGPUCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables using GPU.", nullptr));
#endif // QT_CONFIG(tooltip)
        UseGPUCB->setText(QCoreApplication::translate("EncodeGUIMV", "Use GPU:", nullptr));
#if QT_CONFIG(tooltip)
        GPUInterpDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Selects the GPU for frame rendering.", nullptr));
#endif // QT_CONFIG(tooltip)
        GPUThreadInterpLabel->setText(QCoreApplication::translate("EncodeGUIMV", "GPU threads:", nullptr));
        GPUThreadDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "1", nullptr));
        GPUThreadDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "2", nullptr));
        GPUThreadDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "3", nullptr));
        GPUThreadDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "4", nullptr));

#if QT_CONFIG(tooltip)
        GPUThreadDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the number of GPU threads for NCNN interpolation.", nullptr));
#endif // QT_CONFIG(tooltip)
        ModelInterpLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Model:", nullptr));
        ModelInterpDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Fastest", nullptr));
        ModelInterpDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Fast", nullptr));
        ModelInterpDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Slow", nullptr));

#if QT_CONFIG(tooltip)
        ModelInterpDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the model for EncodeGUI AI", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        SceneChangeCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables scene change detection to reduce interpolation artefacts.", nullptr));
#endif // QT_CONFIG(tooltip)
        SceneChangeCB->setText(QString());
#if QT_CONFIG(tooltip)
        OutputFPSNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The output FPS.", nullptr));
#endif // QT_CONFIG(tooltip)
        OutFPSLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Output FPS:", nullptr));
        SceneChangeLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Use scene change detection:", nullptr));
        BackendDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "CUDA", nullptr));
        BackendDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Vulkan (NCNN)", nullptr));
        BackendDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "CPU", nullptr));

#if QT_CONFIG(tooltip)
        BackendDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Sets the graphics processing backend to use for the specified interpolation tool.</p><p>Recommended: CUDA</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        SlashLabel->setText(QCoreApplication::translate("EncodeGUIMV", "/", nullptr));
        ShaderLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Shader:", nullptr));
        RIFEModelVKDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "v1.8", nullptr));
        RIFEModelVKDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "v2.3", nullptr));
        RIFEModelVKDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "v2.4", nullptr));
        RIFEModelVKDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "v3.1", nullptr));
        RIFEModelVKDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "v4.0", nullptr));
        RIFEModelVKDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "v4.6", nullptr));

#if QT_CONFIG(tooltip)
        RIFEModelVKDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the RIFE model to use for NCNN.", nullptr));
#endif // QT_CONFIG(tooltip)
        RIFEModelCADD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "v4.0", nullptr));
        RIFEModelCADD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "v4.6", nullptr));

#if QT_CONFIG(tooltip)
        RIFEModelCADD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the RIFE model to use for CUDA.", nullptr));
#endif // QT_CONFIG(tooltip)
        ShaderDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "1", nullptr));
        ShaderDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "2", nullptr));
        ShaderDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "11", nullptr));
        ShaderDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "13", nullptr));
        ShaderDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "21", nullptr));
        ShaderDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "23", nullptr));

#if QT_CONFIG(tooltip)
        ShaderDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the SVP shader to use for frame rendering.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        ParamsCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables manual entry for SVPFlow params.", nullptr));
#endif // QT_CONFIG(tooltip)
        ParamsCB->setText(QCoreApplication::translate("EncodeGUIMV", "Overwrite params", nullptr));
        EqualsLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700;\">=</span></p></body></html>", nullptr));
        InterpModeLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Interpolation mode:", nullptr));
        InterpModeDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Uniform", nullptr));
        InterpModeDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "1m", nullptr));
        InterpModeDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "2m", nullptr));
        InterpModeDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "Auto", nullptr));

#if QT_CONFIG(tooltip)
        InterpModeDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the interpolation mode for SVPFlow.", nullptr));
#endif // QT_CONFIG(tooltip)
        ArtefactMaskLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Artefact masking:", nullptr));
        ArtefactMaskDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "High", nullptr));
        ArtefactMaskDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Medium", nullptr));
        ArtefactMaskDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Low", nullptr));
        ArtefactMaskDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "Off", nullptr));

#if QT_CONFIG(tooltip)
        SuperTxtBox->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Allows manual entry for super params in SVPFlow.", nullptr));
#endif // QT_CONFIG(tooltip)
        SuperLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Super:", nullptr));
        AnalyseLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Analyse:", nullptr));
#if QT_CONFIG(tooltip)
        AnalyseTxtBox->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Allows manual entry for analyse params in SVPFlow.", nullptr));
#endif // QT_CONFIG(tooltip)
        SmoothLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Smooth:", nullptr));
#if QT_CONFIG(tooltip)
        SmoothTxtBox->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Allows manual entry for smooth params in SVPFlow.", nullptr));
#endif // QT_CONFIG(tooltip)
        Times2Label->setText(QCoreApplication::translate("EncodeGUIMV", "x2", nullptr));
        SCThresholdLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Scene change threshold:", nullptr));
        VSTabs->setTabText(VSTabs->indexOf(InterpolationTab), QCoreApplication::translate("EncodeGUIMV", "Interpolation", nullptr));
#if QT_CONFIG(tooltip)
        UpscalingGB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables resolution upscaling.", nullptr));
#endif // QT_CONFIG(tooltip)
        UpscalingGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Resolution Upscaling", nullptr));
        GPUThreadUpscaleLabel->setText(QCoreApplication::translate("EncodeGUIMV", "GPU threads:", nullptr));
        ToolUpscaleDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Waifu2x (NCNN)", nullptr));
        ToolUpscaleDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "RealSR (NCNN)", nullptr));

#if QT_CONFIG(tooltip)
        ToolUpscaleDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The upscaling tool to use.", nullptr));
#endif // QT_CONFIG(tooltip)
        ToolUpscaleDD->setCurrentText(QCoreApplication::translate("EncodeGUIMV", "Waifu2x (NCNN)", nullptr));
        ToolUpscaleLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Tool:", nullptr));
        GPUThreadUpscaleDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "1", nullptr));
        GPUThreadUpscaleDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "2", nullptr));
        GPUThreadUpscaleDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "3", nullptr));
        GPUThreadUpscaleDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "4", nullptr));

#if QT_CONFIG(tooltip)
        GPUThreadUpscaleDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the number of GPU threads to use for upscaling.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        GPUUpscaleDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the GPU to use for frame rendering.", nullptr));
#endif // QT_CONFIG(tooltip)
        GPULabel->setText(QCoreApplication::translate("EncodeGUIMV", "GPU device:", nullptr));
        ModelUpscaleDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Upconv 7 Anime", nullptr));
        ModelUpscaleDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Upconv 7 Photo", nullptr));
        ModelUpscaleDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Cunet (2D)", nullptr));
        ModelUpscaleDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "DeNoise Only", nullptr));

#if QT_CONFIG(tooltip)
        ModelUpscaleDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the model to use for Waifu2x.", nullptr));
#endif // QT_CONFIG(tooltip)
        ModelUpscaleLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Model:", nullptr));
        NoiseReduc2xLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Noise reduction level:", nullptr));
        NoiseReduc2xDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "None", nullptr));
        NoiseReduc2xDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Low", nullptr));
        NoiseReduc2xDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Medium", nullptr));
        NoiseReduc2xDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "High", nullptr));
        NoiseReduc2xDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "Highest", nullptr));

#if QT_CONFIG(tooltip)
        NoiseReduc2xDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the noise reduction level for Waifu2x.", nullptr));
#endif // QT_CONFIG(tooltip)
        Precision2xLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Precision:", nullptr));
        Precision2xDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "fp32", nullptr));
        Precision2xDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "fp16", nullptr));

#if QT_CONFIG(tooltip)
        Precision2xDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the color precision for the upscaled video.", nullptr));
#endif // QT_CONFIG(tooltip)
        OutResolutionLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Output resolution:", nullptr));
#if QT_CONFIG(tooltip)
        Width2xNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The output width.", nullptr));
#endif // QT_CONFIG(tooltip)
        Eks2Label->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700;\">X</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        Height2xNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The output height.", nullptr));
#endif // QT_CONFIG(tooltip)
        AutoAdjDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Height", nullptr));
        AutoAdjDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Width", nullptr));

#if QT_CONFIG(tooltip)
        AutoAdjDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the side to auto adjust.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        AutoAdjCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "enables auto adjusting the output resoltion.", nullptr));
#endif // QT_CONFIG(tooltip)
        AutoAdjCB->setText(QCoreApplication::translate("EncodeGUIMV", "Auto adjust:", nullptr));
        TTA2xLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Test time augmentation (TTA):", nullptr));
#if QT_CONFIG(tooltip)
        TTA2xCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets test time augmentation (slow!).", nullptr));
#endif // QT_CONFIG(tooltip)
        TTA2xCB->setText(QString());
        VSTabs->setTabText(VSTabs->indexOf(UpscalingTab), QCoreApplication::translate("EncodeGUIMV", "Upscaling", nullptr));
#if QT_CONFIG(tooltip)
        ColorPropsGB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Converts the video to a different color space.", nullptr));
#endif // QT_CONFIG(tooltip)
        ColorPropsGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Color Space Converter", nullptr));
        InputColorsLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Input (matrix/transfer/prims.):", nullptr));
        OutputColorsLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Output (matrix/transfer/prims.):", nullptr));
        InputMatrixDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "BT709", nullptr));
        InputMatrixDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "FCC", nullptr));
        InputMatrixDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "BT470bg", nullptr));
        InputMatrixDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "170m", nullptr));
        InputMatrixDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "240m", nullptr));
        InputMatrixDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "YCgCo", nullptr));
        InputMatrixDD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "BT2020ncl", nullptr));
        InputMatrixDD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "BT2020cl", nullptr));
        InputMatrixDD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "Chromancl", nullptr));
        InputMatrixDD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "Chromacl", nullptr));
        InputMatrixDD->setItemText(10, QCoreApplication::translate("EncodeGUIMV", "ICtCp", nullptr));

#if QT_CONFIG(tooltip)
        InputMatrixDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The input color matrix.", nullptr));
#endif // QT_CONFIG(tooltip)
        InputTransferDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "BT709", nullptr));
        InputTransferDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "BT470m", nullptr));
        InputTransferDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "BT470bg", nullptr));
        InputTransferDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "BT601", nullptr));
        InputTransferDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "240m", nullptr));
        InputTransferDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "Linear", nullptr));
        InputTransferDD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "Log100", nullptr));
        InputTransferDD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "Log316", nullptr));
        InputTransferDD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "Xvycc", nullptr));
        InputTransferDD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "SRGB", nullptr));
        InputTransferDD->setItemText(10, QCoreApplication::translate("EncodeGUIMV", "2020_10", nullptr));
        InputTransferDD->setItemText(11, QCoreApplication::translate("EncodeGUIMV", "2020_12", nullptr));
        InputTransferDD->setItemText(12, QCoreApplication::translate("EncodeGUIMV", "ST2084", nullptr));
        InputTransferDD->setItemText(13, QCoreApplication::translate("EncodeGUIMV", "STD-B67", nullptr));

#if QT_CONFIG(tooltip)
        InputTransferDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The input color transfer.", nullptr));
#endif // QT_CONFIG(tooltip)
        InputPrimsDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "BT709", nullptr));
        InputPrimsDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "BT470m", nullptr));
        InputPrimsDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "BT470bg", nullptr));
        InputPrimsDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "170m", nullptr));
        InputPrimsDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "240m", nullptr));
        InputPrimsDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "Film", nullptr));
        InputPrimsDD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "BT2020", nullptr));
        InputPrimsDD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "XYZ", nullptr));
        InputPrimsDD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "ST431-2", nullptr));
        InputPrimsDD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "ST432-1", nullptr));
        InputPrimsDD->setItemText(10, QCoreApplication::translate("EncodeGUIMV", "Jedec-p22", nullptr));

#if QT_CONFIG(tooltip)
        InputPrimsDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The input primaries.", nullptr));
#endif // QT_CONFIG(tooltip)
        OutputMatrixDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "BT709", nullptr));
        OutputMatrixDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "FCC", nullptr));
        OutputMatrixDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "BT470bg", nullptr));
        OutputMatrixDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "170m", nullptr));
        OutputMatrixDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "240m", nullptr));
        OutputMatrixDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "YCgCo", nullptr));
        OutputMatrixDD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "BT2020ncl", nullptr));
        OutputMatrixDD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "BT2020cl", nullptr));
        OutputMatrixDD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "Chromancl", nullptr));
        OutputMatrixDD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "Chromacl", nullptr));
        OutputMatrixDD->setItemText(10, QCoreApplication::translate("EncodeGUIMV", "ICtCp", nullptr));

#if QT_CONFIG(tooltip)
        OutputMatrixDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The output matrix.", nullptr));
#endif // QT_CONFIG(tooltip)
        Slash2Label->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700;\">/</span></p></body></html>", nullptr));
        Slash3Label->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700;\">/</span></p></body></html>", nullptr));
        Slash4Label->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700;\">/</span></p></body></html>", nullptr));
        Slash5Label->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700;\">/</span></p></body></html>", nullptr));
        OutputTransferDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "BT709", nullptr));
        OutputTransferDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "BT470m", nullptr));
        OutputTransferDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "BT470bg", nullptr));
        OutputTransferDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "BT601", nullptr));
        OutputTransferDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "240m", nullptr));
        OutputTransferDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "Linear", nullptr));
        OutputTransferDD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "Log100", nullptr));
        OutputTransferDD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "Log316", nullptr));
        OutputTransferDD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "Xvycc", nullptr));
        OutputTransferDD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "SRGB", nullptr));
        OutputTransferDD->setItemText(10, QCoreApplication::translate("EncodeGUIMV", "2020_10", nullptr));
        OutputTransferDD->setItemText(11, QCoreApplication::translate("EncodeGUIMV", "2020_12", nullptr));
        OutputTransferDD->setItemText(12, QCoreApplication::translate("EncodeGUIMV", "ST2084", nullptr));
        OutputTransferDD->setItemText(13, QCoreApplication::translate("EncodeGUIMV", "STD-B67", nullptr));

#if QT_CONFIG(tooltip)
        OutputTransferDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The output transfer.", nullptr));
#endif // QT_CONFIG(tooltip)
        OutputPrimsDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "BT709", nullptr));
        OutputPrimsDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "BT470m", nullptr));
        OutputPrimsDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "BT470bg", nullptr));
        OutputPrimsDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "170m", nullptr));
        OutputPrimsDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "240m", nullptr));
        OutputPrimsDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "Film", nullptr));
        OutputPrimsDD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "BT2020", nullptr));
        OutputPrimsDD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "XYZ", nullptr));
        OutputPrimsDD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "ST431-2", nullptr));
        OutputPrimsDD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "ST432-1", nullptr));
        OutputPrimsDD->setItemText(10, QCoreApplication::translate("EncodeGUIMV", "Jedec-p22", nullptr));

#if QT_CONFIG(tooltip)
        OutputPrimsDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The output primaries.", nullptr));
#endif // QT_CONFIG(tooltip)
        VSTabs->setTabText(VSTabs->indexOf(VSColorsTab), QCoreApplication::translate("EncodeGUIMV", "Colors", nullptr));
#if QT_CONFIG(tooltip)
        AntiAliasingGB->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        AntiAliasingGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Anti-Aliasing", nullptr));
        UseAALabel->setText(QCoreApplication::translate("EncodeGUIMV", "Enable Anti-Aliasing:", nullptr));
#if QT_CONFIG(tooltip)
        UseAACB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables anti-aliasing", nullptr));
#endif // QT_CONFIG(tooltip)
        UseAACB->setText(QString());
        VSTabs->setTabText(VSTabs->indexOf(LineTab), QCoreApplication::translate("EncodeGUIMV", "Line", nullptr));
        VideoTabs->setTabText(VideoTabs->indexOf(VSTab), QCoreApplication::translate("EncodeGUIMV", "VapourSynth", nullptr));
#if QT_CONFIG(tooltip)
        ResizeGB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables resizing of the video.", nullptr));
#endif // QT_CONFIG(tooltip)
        ResizeGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Resize", nullptr));
        ResolutionResLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Resolution (w x h):", nullptr));
        Eks3Label->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700;\">X</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        WidthNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The video width.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        HeightNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The video height.", nullptr));
#endif // QT_CONFIG(tooltip)
        AutoAdjResDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Height", nullptr));
        AutoAdjResDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Width", nullptr));

#if QT_CONFIG(tooltip)
        AutoAdjResDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The side to auto adjust.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        AutoAdjResCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables auto adjustment of the resize.", nullptr));
#endif // QT_CONFIG(tooltip)
        AutoAdjResCB->setText(QCoreApplication::translate("EncodeGUIMV", "Auto adjust:", nullptr));
#if QT_CONFIG(tooltip)
        ResizeAlgoCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables resize algorithms.", nullptr));
#endif // QT_CONFIG(tooltip)
        ResizeAlgoCB->setText(QCoreApplication::translate("EncodeGUIMV", "Algo:", nullptr));
        ResizeAlgoDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Bilinear", nullptr));
        ResizeAlgoDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Bicubic", nullptr));
        ResizeAlgoDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Experimental", nullptr));
        ResizeAlgoDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "Neighbor", nullptr));
        ResizeAlgoDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "Area", nullptr));
        ResizeAlgoDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "Bicublin", nullptr));
        ResizeAlgoDD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "Gauss", nullptr));
        ResizeAlgoDD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "Sinc", nullptr));
        ResizeAlgoDD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "Lanczos", nullptr));
        ResizeAlgoDD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "Spline", nullptr));

#if QT_CONFIG(tooltip)
        ResizeAlgoDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Selects the algorithm for resize.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        RotateGB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables video rotation.", nullptr));
#endif // QT_CONFIG(tooltip)
        RotateGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Rotate", nullptr));
        AngleLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Angle:", nullptr));
        AngleDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "0\302\260", nullptr));
        AngleDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "90\302\260", nullptr));
        AngleDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "180\302\260", nullptr));
        AngleDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "270\302\260", nullptr));

#if QT_CONFIG(tooltip)
        AngleDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The angle at which to rotate at.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        FlipCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables flipping the video.", nullptr));
#endif // QT_CONFIG(tooltip)
        FlipCB->setText(QCoreApplication::translate("EncodeGUIMV", "Flip:", nullptr));
        FlipDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Horizontally", nullptr));
        FlipDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Vertically", nullptr));

#if QT_CONFIG(tooltip)
        FlipDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The direction to flip.", nullptr));
#endif // QT_CONFIG(tooltip)
        NoAutoRotateLabel->setText(QCoreApplication::translate("EncodeGUIMV", "No auto rotate:", nullptr));
#if QT_CONFIG(tooltip)
        NoAutoRotateCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables FFMpeg auto rotation tool. Turn this on for portriat videos.", nullptr));
#endif // QT_CONFIG(tooltip)
        NoAutoRotateCB->setText(QString());
#if QT_CONFIG(tooltip)
        CropGB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables cropping of the video.", nullptr));
#endif // QT_CONFIG(tooltip)
        CropGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Crop", nullptr));
        OutSizeLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Output width/height:", nullptr));
        Eks4Label->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700;\">X</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        OutWidthNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The output video width.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        OutHeightNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The output video height.", nullptr));
#endif // QT_CONFIG(tooltip)
        LocationLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Location (X/Y):", nullptr));
#if QT_CONFIG(tooltip)
        EksNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The x coordinate to crop.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        WhyNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The Y coordinate to crop.", nullptr));
#endif // QT_CONFIG(tooltip)
        Slash4Label_2->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700;\">/</span></p></body></html>", nullptr));
        FiltersTabs->setTabText(FiltersTabs->indexOf(ResizeTab), QCoreApplication::translate("EncodeGUIMV", "Resize", nullptr));
#if QT_CONFIG(tooltip)
        SharpenGB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables sharpening in the video.", nullptr));
#endif // QT_CONFIG(tooltip)
        SharpenGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Sharpening", nullptr));
        RadiusLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Radius:", nullptr));
        RadiusDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "3x3 (Small)", nullptr));
        RadiusDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "5x5 (Medium)", nullptr));
        RadiusDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "7x7 (Large)", nullptr));

#if QT_CONFIG(tooltip)
        RadiusDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The width of the sharpening radius.", nullptr));
#endif // QT_CONFIG(tooltip)
        StrengthLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Strength:", nullptr));
        StrengthDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Very Low", nullptr));
        StrengthDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Low", nullptr));
        StrengthDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Medium", nullptr));
        StrengthDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "High", nullptr));
        StrengthDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "Highest", nullptr));

#if QT_CONFIG(tooltip)
        StrengthDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The sharpening strength.", nullptr));
#endif // QT_CONFIG(tooltip)
        FiltersTabs->setTabText(FiltersTabs->indexOf(ColorsTab), QCoreApplication::translate("EncodeGUIMV", "Colors", nullptr));
        DeinterlaceGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Deinterlace", nullptr));
        EnableDeintLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Enable Deinterlacing:", nullptr));
#if QT_CONFIG(tooltip)
        UseDeintCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Enable deinterlace</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        UseDeintCB->setText(QString());
        FiltersTabs->setTabText(FiltersTabs->indexOf(MiscFFTab), QCoreApplication::translate("EncodeGUIMV", "Misc", nullptr));
        VideoTabs->setTabText(VideoTabs->indexOf(FiltersTab), QCoreApplication::translate("EncodeGUIMV", "FFmpeg", nullptr));
        Tabs->setTabText(Tabs->indexOf(VideoTab), QCoreApplication::translate("EncodeGUIMV", "Video", nullptr));
#if QT_CONFIG(tooltip)
        AudioQueue->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The audio queue.", nullptr));
#endif // QT_CONFIG(tooltip)
        AudioSelectorGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Select Audio", nullptr));
        SelectedAudioLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Selected audio:", nullptr));
#if QT_CONFIG(tooltip)
        SelectedAudioDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The audio in focus.", nullptr));
#endif // QT_CONFIG(tooltip)
        AudioSourceLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Source:", nullptr));
        SelectBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Select", nullptr));
#if QT_CONFIG(tooltip)
        EncodingAudioGB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables audio encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
        EncodingAudioGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Encoding", nullptr));
        EncoderAudioLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Codec:", nullptr));
        AudioEncoderDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "AAC", nullptr));
        AudioEncoderDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "MP3", nullptr));
        AudioEncoderDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "AC3", nullptr));
        AudioEncoderDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "FLAC", nullptr));
        AudioEncoderDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "Vorbis", nullptr));
        AudioEncoderDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "Opus", nullptr));
        AudioEncoderDD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "DTS", nullptr));
        AudioEncoderDD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "TrueHD", nullptr));

#if QT_CONFIG(tooltip)
        AudioEncoderDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The audio codec to use for encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
        RealAudioBitrateLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Bitrate (kbits/s):", nullptr));
#if QT_CONFIG(tooltip)
        AudioBitrateNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the bitrate for the audio.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        DownmixCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enable/disables downmixing of the audio channels.", nullptr));
#endif // QT_CONFIG(tooltip)
        DownmixCB->setText(QCoreApplication::translate("EncodeGUIMV", "Downmix:", nullptr));
        DownmixDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Stereo", nullptr));
        DownmixDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Mono", nullptr));
        DownmixDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "5.1", nullptr));

#if QT_CONFIG(tooltip)
        DownmixDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The number of channels to downmix to.", nullptr));
#endif // QT_CONFIG(tooltip)
        AudioQualityLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Quality:", nullptr));
#if QT_CONFIG(tooltip)
        AudioQualityNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the quality factor for Vorbis audio codec.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        AddAudioJobBttn->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Adds the currently selected audio and it's encoding settings to the audio queue.", nullptr));
#endif // QT_CONFIG(tooltip)
        AddAudioJobBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Add selected audio to queue", nullptr));
        AudioQueueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Audio Queue", nullptr));
#if QT_CONFIG(tooltip)
        AudioTitleCB->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        AudioTitleCB->setText(QCoreApplication::translate("EncodeGUIMV", "Title:", nullptr));
#if QT_CONFIG(tooltip)
        AudioTitleTxtBox->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        LangAudioCB->setText(QCoreApplication::translate("EncodeGUIMV", "Language:", nullptr));
        LangAudioDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Arabic (ARA)", nullptr));
        LangAudioDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Armenian (ARM)", nullptr));
        LangAudioDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Belarusian (BEL)", nullptr));
        LangAudioDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "Bulgarian (BUL)", nullptr));
        LangAudioDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "Chinese (CHI)", nullptr));
        LangAudioDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "Czech (CZE)", nullptr));
        LangAudioDD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "Danish (DAN)", nullptr));
        LangAudioDD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "Dutch (DUT)", nullptr));
        LangAudioDD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "English (ENG)", nullptr));
        LangAudioDD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "Finnish (FIN)", nullptr));
        LangAudioDD->setItemText(10, QCoreApplication::translate("EncodeGUIMV", "French (FRE)", nullptr));
        LangAudioDD->setItemText(11, QCoreApplication::translate("EncodeGUIMV", "Georgian (GEO)", nullptr));
        LangAudioDD->setItemText(12, QCoreApplication::translate("EncodeGUIMV", "German (GER)", nullptr));
        LangAudioDD->setItemText(13, QCoreApplication::translate("EncodeGUIMV", "Greek (GRE)", nullptr));
        LangAudioDD->setItemText(14, QCoreApplication::translate("EncodeGUIMV", "Hebrew (HEB)", nullptr));
        LangAudioDD->setItemText(15, QCoreApplication::translate("EncodeGUIMV", "Hindi (HIN)", nullptr));
        LangAudioDD->setItemText(16, QCoreApplication::translate("EncodeGUIMV", "Hungarian (HUN)", nullptr));
        LangAudioDD->setItemText(17, QCoreApplication::translate("EncodeGUIMV", "Icelandic (ICE)", nullptr));
        LangAudioDD->setItemText(18, QCoreApplication::translate("EncodeGUIMV", "Indonesian (IND)", nullptr));
        LangAudioDD->setItemText(19, QCoreApplication::translate("EncodeGUIMV", "Irish (GLE)", nullptr));
        LangAudioDD->setItemText(20, QCoreApplication::translate("EncodeGUIMV", "Italian (ITA)", nullptr));
        LangAudioDD->setItemText(21, QCoreApplication::translate("EncodeGUIMV", "Japanese (JPN)", nullptr));
        LangAudioDD->setItemText(22, QCoreApplication::translate("EncodeGUIMV", "Korean (KOR)", nullptr));
        LangAudioDD->setItemText(23, QCoreApplication::translate("EncodeGUIMV", "Latin (LAT)", nullptr));
        LangAudioDD->setItemText(24, QCoreApplication::translate("EncodeGUIMV", "Latvian (LAV)", nullptr));
        LangAudioDD->setItemText(25, QCoreApplication::translate("EncodeGUIMV", "Mongolian (MON)", nullptr));
        LangAudioDD->setItemText(26, QCoreApplication::translate("EncodeGUIMV", "Norwegian (NOR)", nullptr));
        LangAudioDD->setItemText(27, QCoreApplication::translate("EncodeGUIMV", "Portuguese (POR)", nullptr));
        LangAudioDD->setItemText(28, QCoreApplication::translate("EncodeGUIMV", "Romanian (RUM)", nullptr));
        LangAudioDD->setItemText(29, QCoreApplication::translate("EncodeGUIMV", "Russian (RUS)", nullptr));
        LangAudioDD->setItemText(30, QCoreApplication::translate("EncodeGUIMV", "Serbian (SRP)", nullptr));
        LangAudioDD->setItemText(31, QCoreApplication::translate("EncodeGUIMV", "Slovenian (SLV)", nullptr));
        LangAudioDD->setItemText(32, QCoreApplication::translate("EncodeGUIMV", "Spanish (SPA)", nullptr));
        LangAudioDD->setItemText(33, QCoreApplication::translate("EncodeGUIMV", "Swedish (SWE)", nullptr));
        LangAudioDD->setItemText(34, QCoreApplication::translate("EncodeGUIMV", "Tamil (TAM)", nullptr));
        LangAudioDD->setItemText(35, QCoreApplication::translate("EncodeGUIMV", "Thai (THA)", nullptr));
        LangAudioDD->setItemText(36, QCoreApplication::translate("EncodeGUIMV", "Turkish (TUR)", nullptr));
        LangAudioDD->setItemText(37, QCoreApplication::translate("EncodeGUIMV", "Ukrainian (UKR)", nullptr));
        LangAudioDD->setItemText(38, QCoreApplication::translate("EncodeGUIMV", "Vietnamese (VIE)", nullptr));

        Tabs->setTabText(Tabs->indexOf(AudioTab), QCoreApplication::translate("EncodeGUIMV", "Audio", nullptr));
#if QT_CONFIG(tooltip)
        SubtitleTitleCB->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        SubtitleTitleCB->setText(QCoreApplication::translate("EncodeGUIMV", "Title:", nullptr));
        SubtitleQueueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Subtitle Queue", nullptr));
#if QT_CONFIG(tooltip)
        SubtitleQueue->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The audio queue.", nullptr));
#endif // QT_CONFIG(tooltip)
        SubtitleLangDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Arabic (ARA)", nullptr));
        SubtitleLangDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Armenian (ARM)", nullptr));
        SubtitleLangDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Belarusian (BEL)", nullptr));
        SubtitleLangDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "Bulgarian (BUL)", nullptr));
        SubtitleLangDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "Chinese (CHI)", nullptr));
        SubtitleLangDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "Czech (CZE)", nullptr));
        SubtitleLangDD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "Danish (DAN)", nullptr));
        SubtitleLangDD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "Dutch (DUT)", nullptr));
        SubtitleLangDD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "English (ENG)", nullptr));
        SubtitleLangDD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "Finnish (FIN)", nullptr));
        SubtitleLangDD->setItemText(10, QCoreApplication::translate("EncodeGUIMV", "French (FRE)", nullptr));
        SubtitleLangDD->setItemText(11, QCoreApplication::translate("EncodeGUIMV", "Georgian (GEO)", nullptr));
        SubtitleLangDD->setItemText(12, QCoreApplication::translate("EncodeGUIMV", "German (GER)", nullptr));
        SubtitleLangDD->setItemText(13, QCoreApplication::translate("EncodeGUIMV", "Greek (GRE)", nullptr));
        SubtitleLangDD->setItemText(14, QCoreApplication::translate("EncodeGUIMV", "Hebrew (HEB)", nullptr));
        SubtitleLangDD->setItemText(15, QCoreApplication::translate("EncodeGUIMV", "Hindi (HIN)", nullptr));
        SubtitleLangDD->setItemText(16, QCoreApplication::translate("EncodeGUIMV", "Hungarian (HUN)", nullptr));
        SubtitleLangDD->setItemText(17, QCoreApplication::translate("EncodeGUIMV", "Icelandic (ICE)", nullptr));
        SubtitleLangDD->setItemText(18, QCoreApplication::translate("EncodeGUIMV", "Indonesian (IND)", nullptr));
        SubtitleLangDD->setItemText(19, QCoreApplication::translate("EncodeGUIMV", "Irish (GLE)", nullptr));
        SubtitleLangDD->setItemText(20, QCoreApplication::translate("EncodeGUIMV", "Italian (ITA)", nullptr));
        SubtitleLangDD->setItemText(21, QCoreApplication::translate("EncodeGUIMV", "Japanese (JPN)", nullptr));
        SubtitleLangDD->setItemText(22, QCoreApplication::translate("EncodeGUIMV", "Korean (KOR)", nullptr));
        SubtitleLangDD->setItemText(23, QCoreApplication::translate("EncodeGUIMV", "Latin (LAT)", nullptr));
        SubtitleLangDD->setItemText(24, QCoreApplication::translate("EncodeGUIMV", "Latvian (LAV)", nullptr));
        SubtitleLangDD->setItemText(25, QCoreApplication::translate("EncodeGUIMV", "Mongolian (MON)", nullptr));
        SubtitleLangDD->setItemText(26, QCoreApplication::translate("EncodeGUIMV", "Norwegian (NOR)", nullptr));
        SubtitleLangDD->setItemText(27, QCoreApplication::translate("EncodeGUIMV", "Portuguese (POR)", nullptr));
        SubtitleLangDD->setItemText(28, QCoreApplication::translate("EncodeGUIMV", "Romanian (RUM)", nullptr));
        SubtitleLangDD->setItemText(29, QCoreApplication::translate("EncodeGUIMV", "Russian (RUS)", nullptr));
        SubtitleLangDD->setItemText(30, QCoreApplication::translate("EncodeGUIMV", "Serbian (SRP)", nullptr));
        SubtitleLangDD->setItemText(31, QCoreApplication::translate("EncodeGUIMV", "Slovenian (SLV)", nullptr));
        SubtitleLangDD->setItemText(32, QCoreApplication::translate("EncodeGUIMV", "Spanish (SPA)", nullptr));
        SubtitleLangDD->setItemText(33, QCoreApplication::translate("EncodeGUIMV", "Swedish (SWE)", nullptr));
        SubtitleLangDD->setItemText(34, QCoreApplication::translate("EncodeGUIMV", "Tamil (TAM)", nullptr));
        SubtitleLangDD->setItemText(35, QCoreApplication::translate("EncodeGUIMV", "Thai (THA)", nullptr));
        SubtitleLangDD->setItemText(36, QCoreApplication::translate("EncodeGUIMV", "Turkish (TUR)", nullptr));
        SubtitleLangDD->setItemText(37, QCoreApplication::translate("EncodeGUIMV", "Ukrainian (UKR)", nullptr));
        SubtitleLangDD->setItemText(38, QCoreApplication::translate("EncodeGUIMV", "Vietnamese (VIE)", nullptr));

#if QT_CONFIG(tooltip)
        SubtitleTitleTxtBox->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        SubtitleLangCB->setText(QCoreApplication::translate("EncodeGUIMV", "Language:", nullptr));
        SubtitleSelectorGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Select Subtitles", nullptr));
        SelectedSubtitleLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Selected subtitles:", nullptr));
#if QT_CONFIG(tooltip)
        SelectedSubtitleDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The audio in focus.", nullptr));
#endif // QT_CONFIG(tooltip)
        SubtitleSourceLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Source:", nullptr));
        SubSelectBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Select", nullptr));
        SubtitleInfoBttn->setText(QCoreApplication::translate("EncodeGUIMV", "View subtitle info", nullptr));
#if QT_CONFIG(tooltip)
        SubtitleEncodingGB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables audio encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
        SubtitleEncodingGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Encoding", nullptr));
        SubtitleEncoderLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Codec:", nullptr));
        SubtitleEncoderDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "SRT", nullptr));
        SubtitleEncoderDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "WebVTT", nullptr));
        SubtitleEncoderDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "ASS", nullptr));
        SubtitleEncoderDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "TXTT", nullptr));

#if QT_CONFIG(tooltip)
        SubtitleEncoderDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The audio codec to use for encoding.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        AddSubtitleJobBttn->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Adds the currently selected audio and it's encoding settings to the audio queue.", nullptr));
#endif // QT_CONFIG(tooltip)
        AddSubtitleJobBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Add selected subtitles to queue", nullptr));
        Tabs->setTabText(Tabs->indexOf(SubtitlesTab), QCoreApplication::translate("EncodeGUIMV", "Subtitles", nullptr));
        EGUISettingsGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "EncodeGUI Settings", nullptr));
        EnablePreviewCB->setText(QString());
        AutoDelSourceCB->setText(QString());
        ErrorMessageCB->setText(QString());
        ErrorMessageLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Show process error message boxes:", nullptr));
        DeleteSourcesLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Automatically delete source video after encode:", nullptr));
        EnablePreviewLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Enable live encoding preview (extracts frames before encode):", nullptr));
        UpdateOptLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Automatically check for EncodeGUI updates:", nullptr));
        UpdateOptCB->setText(QString());
        GenerateOutLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Automatically generate output file name:", nullptr));
        GenerateOutCB->setText(QString());
        NotificationLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Show desktop notification after each completed job:", nullptr));
        NotificationCB->setText(QString());
        ProgressBarGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Progress Bar", nullptr));
        JobsCB->setText(QCoreApplication::translate("EncodeGUIMV", "Jobs", nullptr));
        FPSCB->setText(QCoreApplication::translate("EncodeGUIMV", "FPS", nullptr));
        BitrateCB->setText(QCoreApplication::translate("EncodeGUIMV", "Bitrate", nullptr));
        TimeLeftCB->setText(QCoreApplication::translate("EncodeGUIMV", "Time left", nullptr));
        TimeElapsedCB->setText(QCoreApplication::translate("EncodeGUIMV", "Time elapsed", nullptr));
        PercentageCB->setText(QCoreApplication::translate("EncodeGUIMV", "Percentage", nullptr));
        SettingsTabs->setTabText(SettingsTabs->indexOf(EGUITab), QCoreApplication::translate("EncodeGUIMV", "EncodeGUI", nullptr));
        ProcessSettingsGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Process Settings", nullptr));
        LimitThreadsCB->setText(QCoreApplication::translate("EncodeGUIMV", "Limit CPU encoding threads (can help lower temps):", nullptr));
        MultiGPUGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Dual GPU Processing (for resolution upscaling)", nullptr));
        TestGPUBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Identify GPU device IDs", nullptr));
        GPU1IDLabel->setText(QCoreApplication::translate("EncodeGUIMV", "GPU #1 ID:", nullptr));
        GPU1IDLabel2->setText(QCoreApplication::translate("EncodeGUIMV", "GPU #2 ID:", nullptr));
        SettingsTabs->setTabText(SettingsTabs->indexOf(EncodingTab), QCoreApplication::translate("EncodeGUIMV", "Encoding", nullptr));
        Tabs->setTabText(Tabs->indexOf(PrefTab), QCoreApplication::translate("EncodeGUIMV", "Preferences", nullptr));
        QTableWidgetItem* ___qtablewidgetitem = JobQueue->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("EncodeGUIMV", "ID", nullptr));
        QTableWidgetItem* ___qtablewidgetitem1 = JobQueue->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("EncodeGUIMV", "Status", nullptr));
        QTableWidgetItem* ___qtablewidgetitem2 = JobQueue->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("EncodeGUIMV", "Progress", nullptr));
        QTableWidgetItem* ___qtablewidgetitem3 = JobQueue->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("EncodeGUIMV", "Input", nullptr));
        QTableWidgetItem* ___qtablewidgetitem4 = JobQueue->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("EncodeGUIMV", "Output", nullptr));
        QTableWidgetItem* ___qtablewidgetitem5 = JobQueue->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("EncodeGUIMV", "Logs", nullptr));
        JobQueueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Job Queue", nullptr));
        ClearJobsBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Clear all finished jobs", nullptr));
        CancelQueueBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Cancel all jobs", nullptr));
        Tabs->setTabText(Tabs->indexOf(JobTab), QCoreApplication::translate("EncodeGUIMV", "Jobs", nullptr));
        LogsOutGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "User Logs (for user information ONLY)", nullptr));
#if QT_CONFIG(tooltip)
        LogsOutRTxtBox->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The user logs.", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        LogsDirBttn->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Opens the directory to EncodeGUI's log files.", nullptr));
#endif // QT_CONFIG(tooltip)
        LogsDirBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Open process logs directory", nullptr));
        Tabs->setTabText(Tabs->indexOf(LogsTab), QCoreApplication::translate("EncodeGUIMV", "Logs", nullptr));
        AboutGUIGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "About EncodeGUI", nullptr));
        AboutGuiLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">EncodeGUI (encode-gooey) is the latest and greatest video encoding application. It features 5 different video codecs to use and AI backed filters such as frame interpolation, resolution upscaling, and DeNoise for an unparalleled video encode. Find out more at </span><a href=\"https://encodegui.com\"><span style=\" font-size:10pt; text-decoration: underline; color:#0000ff;\">https://encodegui.com</span></a></p></body></html>", nullptr));
        DonateGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Donate", nullptr));
        DonateToDaGooseLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700; color:#008000;\">Goose</span><span style=\" font-weight:700;\"> (owner &amp; developer v1.0 to v1.2.3):</span></p></body></html>", nullptr));
        DonateToGlitchLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700; color:#008000;\">Glitch</span><span style=\" font-weight:700;\"> (developer after v1.2.3):</span></p></body></html>", nullptr));
        DonateToDaGooseBttn->setText(QString());
        DonateToGlitchBttn->setText(QString());
        LinksGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "DaGoose's Links", nullptr));
        YoutubeBttn->setText(QString());
        DiscordBttn->setText(QString());
        InstaBttn->setText(QString());
        ClearBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Clear saved data", nullptr));
        LicensesBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Licenses", nullptr));
        Tabs->setTabText(Tabs->indexOf(AboutTab), QCoreApplication::translate("EncodeGUIMV", "About / Donate", nullptr));
        VideoInfoGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Video Info", nullptr));
        EncoderLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Codec:", nullptr));
        DurationLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Duration:", nullptr));
        ResolutionLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Resolution:", nullptr));
        VidBitrateLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Bitrate:", nullptr));
        ColorsLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Colors:", nullptr));
        FPSLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Frame rate:", nullptr));
        MatrixLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Matrix:", nullptr));
        TransferLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Transfer:", nullptr));
        VidformatValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" color:#008000;\">?</span></p></body></html>", nullptr));
        ResolutionValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" color:#008000;\">?</span></p></body></html>", nullptr));
        BitrateValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" color:#008000;\">?</span></p></body></html>", nullptr));
        ColorsValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" color:#008000;\">?</span></p></body></html>", nullptr));
        FPSValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" color:#008000;\">?</span></p></body></html>", nullptr));
        DurationValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" color:#008000;\">?</span></p></body></html>", nullptr));
        MatrixValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" color:#008000;\">?</span></p></body></html>", nullptr));
        TransferValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" color:#008000;\">?</span></p></body></html>", nullptr));
        PrimariesLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Primaries:", nullptr));
        PrimariesValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" color:#008000;\">?</span></p></body></html>", nullptr));
#if QT_CONFIG(tooltip)
        SaveOutTxtBox->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The output file destination path.", nullptr));
#endif // QT_CONFIG(tooltip)
        OutContainerx264DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", ".mp4", nullptr));
        OutContainerx264DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", ".mkv", nullptr));
        OutContainerx264DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", ".mov", nullptr));
        OutContainerx264DD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", ".ts", nullptr));
        OutContainerx264DD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", ".avi", nullptr));
        OutContainerx264DD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", ".asf", nullptr));
        OutContainerx264DD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", ".flv", nullptr));
        OutContainerx264DD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", ".3gp", nullptr));

#if QT_CONFIG(tooltip)
        OutContainerx264DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The selected output container </p><p>Note: can auto change based on selected video encoder</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        SaveOutBttn->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Saves the video to an output destination</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        SaveOutBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Save output", nullptr));
#if QT_CONFIG(tooltip)
        PreviewBttn->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Open the live encoding preview menu</p><p>Note: the preview only works while a process is active.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        PreviewBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Preview", nullptr));
#if QT_CONFIG(tooltip)
        AddJobBttn->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Adds the source video and the selected encoding settings to a job in the job queue.</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        AddJobBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Add job", nullptr));
#if QT_CONFIG(tooltip)
        StartBttn->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Starts the jobs in the job queue.", nullptr));
#endif // QT_CONFIG(tooltip)
        StartBttn->setText(QCoreApplication::translate("EncodeGUIMV", "Start", nullptr));
        AudioInfoGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Audio Info", nullptr));
        SampleRateLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Sample rate:", nullptr));
        AudioLanguageLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Language:", nullptr));
        SampleRateValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" color:#008000;\">?</span></p></body></html>", nullptr));
        TrackLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Track:", nullptr));
        AudioLanguageValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" color:#008000;\">?</span></p></body></html>", nullptr));
        FormatLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Codec:", nullptr));
        ChannelsLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Channels:", nullptr));
        ChannelsValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" color:#008000;\">?</span></p></body></html>", nullptr));
        FormatValueLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" color:#008000;\">?</span></p></body></html>", nullptr));
        ProgressBarLabel->setText(QString());
        OutContainerx265DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", ".mp4", nullptr));
        OutContainerx265DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", ".mkv", nullptr));
        OutContainerx265DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", ".mov", nullptr));
        OutContainerx265DD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", ".ts", nullptr));

#if QT_CONFIG(tooltip)
        OutContainerx265DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The selected output container </p><p>Note: can auto change based on selected video encoder</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        OutContainerProResDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", ".mkv", nullptr));
        OutContainerProResDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", ".mov", nullptr));
        OutContainerProResDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", ".avi", nullptr));

#if QT_CONFIG(tooltip)
        OutContainerProResDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The selected output container </p><p>Note: can auto change based on selected video encoder</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        OutContainerTheoraDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", ".ogv", nullptr));
        OutContainerTheoraDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", ".mkv", nullptr));
        OutContainerTheoraDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", ".avi", nullptr));

#if QT_CONFIG(tooltip)
        OutContainerTheoraDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The selected output container </p><p>Note: can auto change based on selected video encoder</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        OutContainerVPXDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", ".webm", nullptr));
        OutContainerVPXDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", ".mp4", nullptr));
        OutContainerVPXDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", ".mkv", nullptr));
        OutContainerVPXDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", ".avi", nullptr));
        OutContainerVPXDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", ".asf", nullptr));

#if QT_CONFIG(tooltip)
        OutContainerVPXDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The selected output container </p><p>Note: can auto change based on selected video encoder</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        OutContainerAV1DD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", ".mp4", nullptr));
        OutContainerAV1DD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", ".mkv", nullptr));
        OutContainerAV1DD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", ".avi", nullptr));
        OutContainerAV1DD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", ".asf", nullptr));
        OutContainerAV1DD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", ".webm", nullptr));

#if QT_CONFIG(tooltip)
        OutContainerAV1DD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The selected output container </p><p>Note: can auto change based on selected video encoder</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        OutContainerMuxDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", ".mp4", nullptr));
        OutContainerMuxDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", ".mkv", nullptr));
        OutContainerMuxDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", ".mov", nullptr));
        OutContainerMuxDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", ".ts", nullptr));
        OutContainerMuxDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", ".avi", nullptr));
        OutContainerMuxDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", ".asf", nullptr));
        OutContainerMuxDD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", ".flv", nullptr));
        OutContainerMuxDD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", ".3gp", nullptr));
        OutContainerMuxDD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", ".ogv", nullptr));
        OutContainerMuxDD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", ".webm", nullptr));

#if QT_CONFIG(tooltip)
        OutContainerMuxDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The selected output container </p><p>Note: can auto change based on selected video encoder</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class EncodeGUIMV : public Ui_EncodeGUIMV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ENCODEGUIJDHGID_H