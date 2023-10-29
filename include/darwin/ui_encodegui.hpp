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

#ifndef ENCODEGUIQUBDDF_H
#define ENCODEGUIQUBDDF_H

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
    QWidget *centralWidget;
    QTabWidget *Tabs;
    QWidget *HomeTab;
    QLabel *EGUILogo;
    QGroupBox *InputGB;
    QCheckBox *GetVidInfoCB;
    QCheckBox *SampleVidCB;
    QCheckBox *BatchCB;
    QGroupBox *EGUIGB;
    QComboBox *VideoEncDD;
    QLabel *VidEncLabel;
    QCheckBox *AudioCB;
    QComboBox *AudioDD;
    QCheckBox *SubtitlesCB;
    QComboBox *SubtitlesDD;
    QCheckBox *ChaptersCB;
    QLabel *ChaptersLabel;
    QGroupBox *CurrenProcGB;
    QLabel *WhenEncCompleteLabel;
    QComboBox *WhenEncCompleteDD;
    QPushButton *PauseBttn;
    QPushButton *CancelBttn;
    QLabel *JobIDLabel;
    QLabel *JobStatusLabel;
    QLabel *JobStartLabel;
    QLabel *JobIDValueLabel;
    QLabel *JobStatusValueLabel;
    QLabel *JobStartValueLabel;
    QLineEdit *SelectInTxtBox;
    QPushButton *SelectInBttn;
    QWidget *VideoTab;
    QTabWidget *VideoTabs;
    QWidget *x264Tab;
    QTabWidget *x264Tabs;
    QWidget *Main264Tab;
    QGroupBox *EncodingSetting264GB;
    QLabel *EncodeMode264Label;
    QComboBox *EncodeMode264DD;
    QDoubleSpinBox *Bitrate264NUD;
    QCheckBox *Tune264CB;
    QComboBox *Tune264DD;
    QCheckBox *Preset264CB;
    QComboBox *Preset264DD;
    QLabel *Quantizer264Label;
    QSpinBox *Quantizer264NUD;
    QSpinBox *CRFValue264NUD;
    QLabel *CRFValueLabel;
    QLabel *Bitrate264Label;
    QGroupBox *Profile264GB;
    QLabel *Profile264Label;
    QComboBox *Profile264DD;
    QLabel *Level264Label;
    QComboBox *Level264DD;
    QLabel *EntropyCode264Label;
    QComboBox *EntropyCode264DD;
    QGroupBox *Colors264GB;
    QLabel *BitDepth264Label;
    QComboBox *BitDepth264DD;
    QLabel *Space264Label;
    QComboBox *ColorSpace264DD;
    QWidget *Fames264Tab;
    QGroupBox *RefFrames264GB;
    QSlider *Reference264Sldr;
    QLCDNumber *Reference264LED;
    QGroupBox *BFrames264GB;
    QSlider *BFrame264Sldr;
    QLCDNumber *Bframe264LED;
    QWidget *x265Tab;
    QTabWidget *x265Tabs;
    QWidget *Main265Tab;
    QGroupBox *Colors265GB;
    QLabel *BitDepth265Label;
    QComboBox *BitDepth265DD;
    QLabel *Sample265Label;
    QComboBox *ColorSpace265DD;
    QGroupBox *Profile265GB;
    QLabel *Profile265Label;
    QComboBox *Profile265DD;
    QLabel *Level265Label;
    QComboBox *Level265DD;
    QLabel *Tier265Label;
    QComboBox *Tier265DD;
    QGroupBox *EncodingSetting265GB;
    QLabel *EncodeMode265Label;
    QComboBox *EncodeMode265DD;
    QDoubleSpinBox *Bitrate265NUD;
    QCheckBox *Tune265CB;
    QComboBox *Tune265DD;
    QCheckBox *Preset265CB;
    QComboBox *Preset265DD;
    QLabel *Quantizer265Label;
    QSpinBox *Quantizer265NUD;
    QSpinBox *CRFValue265NUD;
    QLabel *CRFValue265Label;
    QLabel *Bitrate265Label;
    QWidget *Fames265Tab;
    QGroupBox *RefFrames265GB;
    QSlider *Reference265Sldr;
    QLCDNumber *Reference265LED;
    QGroupBox *BFrames265GB;
    QSlider *BFrame265Sldr;
    QLCDNumber *Bframe265LED;
    QWidget *ProResTab;
    QGroupBox *EncodingProResGB;
    QLabel *ProfileLabel;
    QComboBox *ProfileDD;
    QGroupBox *ColorsGB;
    QLabel *MatrixProResLabel;
    QComboBox *MatrixProResDD;
    QLabel *TransferProResLabel;
    QComboBox *TransferProResDD;
    QLabel *PrimariesProResLabel;
    QComboBox *PrimairesProResDD;
    QWidget *TheoraTab;
    QGroupBox *EncodeTheoraGB;
    QLabel *QualityLabel;
    QSpinBox *QualityNUD;
    QLabel *EncodeModeTLabel;
    QComboBox *EncodeModeTDD;
    QLabel *BitrateThLabel;
    QSpinBox *BitrateThNUD;
    QWidget *VPXTab;
    QGroupBox *EncodingSettingVPXGB;
    QLabel *EncodeModeVPXLabel;
    QComboBox *EncodeModeVPXDD;
    QDoubleSpinBox *BitrateVPXNUD;
    QSpinBox *crfVPXNUD;
    QLabel *crfVPXLabel;
    QLabel *BitrateVPXLabel;
    QGroupBox *ProfileVPXGB;
    QLabel *Profile264Label_2;
    QComboBox *ProfileVPXDD;
    QLabel *SpeedLabel;
    QComboBox *SpeedDD;
    QGroupBox *ColorsVPXGB;
    QLabel *BitDepthVPXLabel;
    QComboBox *BitDepthVPXDD;
    QLabel *SampleVPXLabel;
    QComboBox *SampleVPXDD;
    QWidget *av1Tab;
    QGroupBox *EncodingSettingAV1GB;
    QLabel *EncodeModeAV1Label;
    QComboBox *EncodeModeAV1DD;
    QDoubleSpinBox *BitrateAV1NUD;
    QSpinBox *crfAV1NUD;
    QLabel *crfAV1Label;
    QLabel *BitrateAV1Label;
    QGroupBox *ColorsAV1GB;
    QLabel *BitDepthAV1Label;
    QComboBox *BitDepthAV1DD;
    QWidget *HDRTab;
    QTabWidget *SignalsTabs;
    QWidget *HDRTab1;
    QGroupBox *HDRMetadataGB;
    QLabel *LightLevelLabel;
    QLabel *Slash6Label;
    QSpinBox *MaxCllNUD;
    QSpinBox *MaxFallNUD;
    QLabel *MasterDisplayLabel;
    QLineEdit *MasterDisplayTxtBox;
    QLabel *DynamicMetadataLabel;
    QPushButton *DynamicMetadataBttn;
    QLineEdit *DynamicHDRTxtBox;
    QGroupBox *DBVisionGB;
    QLabel *DBProfileLabel;
    QLabel *RpuLabel;
    QComboBox *DBProfileDD;
    QLineEdit *RpuTxtBox;
    QPushButton *RpuFileBttn;
    QWidget *Colors3Tab;
    QGroupBox *ColorsHDRGB;
    QLabel *ColorRangeLabel;
    QLabel *ColorMatrixLabel;
    QComboBox *ColorTransferDD;
    QLabel *ColorPrimariesLabel;
    QLabel *ColorTransferLabel;
    QComboBox *ColorRangeDD;
    QComboBox *ColorMatrixDD;
    QComboBox *ColorPrimariesDD;
    QWidget *VSTab;
    QTabWidget *VSTabs;
    QWidget *InterpolationTab;
    QGroupBox *InterpolationCB;
    QComboBox *ToolInterpDD;
    QLabel *ToolInterpLabel;
    QCheckBox *UseGPUCB;
    QComboBox *GPUInterpDD;
    QLabel *GPUThreadInterpLabel;
    QComboBox *GPUThreadDD;
    QLabel *ModelInterpLabel;
    QCheckBox *SceneChangeCB;
    QDoubleSpinBox *OutputFPSNUD;
    QLabel *OutFPSLabel;
    QLabel *SceneChangeLabel;
    QComboBox *BackendDD;
    QLabel *SlashLabel;
    QComboBox *RIFEModelVKDD;
    QLabel *Times2Label;
    QDoubleSpinBox *SCThresholdNUD;
    QLabel *SCThresholdLabel;
    QWidget *UpscalingTab;
    QGroupBox *UpscalingGB;
    QLabel *GPUThreadUpscaleLabel;
    QComboBox *ToolUpscaleDD;
    QLabel *ToolUpscaleLabel;
    QComboBox *GPUThreadUpscaleDD;
    QComboBox *GPUUpscaleDD;
    QLabel *GPULabel;
    QComboBox *ModelUpscaleDD;
    QLabel *ModelUpscaleLabel;
    QLabel *NoiseReduc2xLabel;
    QComboBox *NoiseReduc2xDD;
    QLabel *Precision2xLabel;
    QComboBox *Precision2xDD;
    QLabel *OutResolutionLabel;
    QSpinBox *Width2xNUD;
    QLabel *Eks2Label;
    QSpinBox *Height2xNUD;
    QComboBox *AutoAdjDD;
    QCheckBox *AutoAdjCB;
    QLabel *TTA2xLabel;
    QCheckBox *TTA2xCB;
    QComboBox *NoiseLabelSDDD;
    QWidget *VSColorsTab;
    QGroupBox *ColorPropsGB;
    QLabel *InputColorsLabel;
    QLabel *OutputColorsLabel;
    QComboBox *InputMatrixDD;
    QComboBox *InputTransferDD;
    QComboBox *InputPrimsDD;
    QComboBox *OutputMatrixDD;
    QLabel *Slash2Label;
    QLabel *Slash3Label;
    QLabel *Slash4Label;
    QLabel *Slash5Label;
    QComboBox *OutputTransferDD;
    QComboBox *OutputPrimsDD;
    QWidget *LineTab;
    QGroupBox *AntiAliasingGB;
    QLabel *UseAALabel;
    QCheckBox *UseAACB;
    QWidget *FiltersTab;
    QTabWidget *FiltersTabs;
    QWidget *ResizeTab;
    QGroupBox *ResizeGB;
    QLabel *ResolutionResLabel;
    QLabel *Eks3Label;
    QSpinBox *WidthNUD;
    QSpinBox *HeightNUD;
    QComboBox *AutoAdjResDD;
    QCheckBox *AutoAdjResCB;
    QCheckBox *ResizeAlgoCB;
    QComboBox *ResizeAlgoDD;
    QGroupBox *RotateGB;
    QLabel *AngleLabel;
    QComboBox *AngleDD;
    QCheckBox *FlipCB;
    QComboBox *FlipDD;
    QLabel *NoAutoRotateLabel;
    QCheckBox *NoAutoRotateCB;
    QGroupBox *CropGB;
    QLabel *OutSizeLabel;
    QLabel *Eks4Label;
    QSpinBox *OutWidthNUD;
    QSpinBox *OutHeightNUD;
    QLabel *LocationLabel;
    QSpinBox *EksNUD;
    QSpinBox *WhyNUD;
    QLabel *Slash4Label_2;
    QWidget *ColorsTab;
    QGroupBox *SharpenGB;
    QLabel *RadiusLabel;
    QComboBox *RadiusDD;
    QLabel *StrengthLabel;
    QComboBox *StrengthDD;
    QWidget *MiscFFTab;
    QGroupBox *DeinterlaceGB;
    QLabel *EnableDeintLabel;
    QCheckBox *UseDeintCB;
    QWidget *AudioTab;
    QTableWidget *AudioQueue;
    QGroupBox *AudioSelectorGB;
    QLabel *SelectedAudioLabel;
    QComboBox *SelectedAudioDD;
    QLabel *AudioSourceLabel;
    QPushButton *SelectBttn;
    QLineEdit *AudioSourceTxtBox;
    QGroupBox *EncodingAudioGB;
    QLabel *EncoderAudioLabel;
    QComboBox *AudioEncoderDD;
    QLabel *RealAudioBitrateLabel;
    QSpinBox *AudioBitrateNUD;
    QCheckBox *DownmixCB;
    QComboBox *DownmixDD;
    QLabel *AudioQualityLabel;
    QSpinBox *AudioQualityNUD;
    QPushButton *AddAudioJobBttn;
    QLabel *AudioQueueLabel;
    QCheckBox *AudioTitleCB;
    QLineEdit *AudioTitleTxtBox;
    QCheckBox *LangAudioCB;
    QComboBox *LangAudioDD;
    QWidget *SubtitlesTab;
    QCheckBox *SubtitleTitleCB;
    QLabel *SubtitleQueueLabel;
    QTableWidget *SubtitleQueue;
    QComboBox *SubtitleLangDD;
    QLineEdit *SubtitleTitleTxtBox;
    QCheckBox *SubtitleLangCB;
    QGroupBox *SubtitleSelectorGB;
    QLabel *SelectedSubtitleLabel;
    QComboBox *SelectedSubtitleDD;
    QLabel *SubtitleSourceLabel;
    QPushButton *SubSelectBttn;
    QLineEdit *SubSourceTxtBox;
    QPushButton *SubtitleInfoBttn;
    QGroupBox *SubtitleEncodingGB;
    QLabel *SubtitleEncoderLabel;
    QComboBox *SubtitleEncoderDD;
    QPushButton *AddSubtitleJobBttn;
    QWidget *PrefTab;
    QGroupBox *EGUISettingsGB;
    QCheckBox *EnablePreviewCB;
    QCheckBox *AutoDelSourceCB;
    QCheckBox *ErrorMessageCB;
    QLabel *ErrorMessageLabel;
    QLabel *DeleteSourcesLabel;
    QLabel *EnablePreviewLabel;
    QLabel *UpdateOptLabel;
    QCheckBox *UpdateOptCB;
    QLabel *GenerateOutLabel;
    QCheckBox *GenerateOutCB;
    QLabel *NotificationLabel;
    QCheckBox *NotificationCB;
    QGroupBox *ProgressBarGB;
    QCheckBox *JobsCB;
    QCheckBox *FPSCB;
    QCheckBox *BitrateCB;
    QCheckBox *TimeLeftCB;
    QCheckBox *TimeElapsedCB;
    QCheckBox *PercentageCB;
    QWidget *JobTab;
    QTableWidget *JobQueue;
    QLabel *JobQueueLabel;
    QPushButton *ClearJobsBttn;
    QPushButton *CancelQueueBttn;
    QWidget *LogsTab;
    QGroupBox *LogsOutGB;
    QTextEdit *LogsOutRTxtBox;
    QPushButton *LogsDirBttn;
    QWidget *AboutTab;
    QGroupBox *AboutGUIGB;
    QLabel *AboutGuiLabel;
    QGroupBox *DonateGB;
    QLabel *DonateToDaGooseLabel;
    QLabel *DonateToGlitchLabel;
    QPushButton *DonateToDaGooseBttn;
    QPushButton *DonateToGlitchBttn;
    QGroupBox *LinksGB;
    QPushButton *YoutubeBttn;
    QPushButton *DiscordBttn;
    QPushButton *InstaBttn;
    QPushButton *ClearBttn;
    QPushButton *LicensesBttn;
    QProgressBar *progressBar;
    QGroupBox *VideoInfoGB;
    QLabel *EncoderLabel;
    QLabel *DurationLabel;
    QLabel *ResolutionLabel;
    QLabel *VidBitrateLabel;
    QLabel *ColorsLabel;
    QLabel *FPSLabel;
    QLabel *MatrixLabel;
    QLabel *TransferLabel;
    QLabel *VidformatValueLabel;
    QLabel *ResolutionValueLabel;
    QLabel *BitrateValueLabel;
    QLabel *ColorsValueLabel;
    QLabel *FPSValueLabel;
    QLabel *DurationValueLabel;
    QLabel *MatrixValueLabel;
    QLabel *TransferValueLabel;
    QLabel *PrimariesLabel;
    QLabel *PrimariesValueLabel;
    QLineEdit *SaveOutTxtBox;
    QComboBox *OutContainerx264DD;
    QPushButton *SaveOutBttn;
    QPushButton *PreviewBttn;
    QPushButton *AddJobBttn;
    QPushButton *StartBttn;
    QGroupBox *AudioInfoGB;
    QLabel *SampleRateLabel;
    QLabel *AudioLanguageLabel;
    QLabel *SampleRateValueLabel;
    QLabel *TrackLabel;
    QLabel *AudioLanguageValueLabel;
    QLabel *FormatLabel;
    QLabel *ChannelsLabel;
    QLabel *ChannelsValueLabel;
    QLabel *FormatValueLabel;
    QComboBox *AudioTrackDD;
    QLabel *ProgressBarLabel;
    QComboBox *OutContainerx265DD;
    QComboBox *OutContainerProResDD;
    QComboBox *OutContainerTheoraDD;
    QComboBox *OutContainerVPXDD;
    QComboBox *OutContainerAV1DD;
    QComboBox *OutContainerMuxDD;

    void setupUi(QMainWindow *EncodeGUIMV)
    {
        if (EncodeGUIMV->objectName().isEmpty())
            EncodeGUIMV->setObjectName(QString::fromUtf8("EncodeGUIMV"));
        EncodeGUIMV->resize(770, 397);
        EncodeGUIMV->setMinimumSize(QSize(770, 397));
        EncodeGUIMV->setMaximumSize(QSize(770, 397));
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
        Tabs->setGeometry(QRect(6, 5, 572, 323));
        Tabs->setFocusPolicy(Qt::NoFocus);
        HomeTab = new QWidget();
        HomeTab->setObjectName(QString::fromUtf8("HomeTab"));
        EGUILogo = new QLabel(HomeTab);
        EGUILogo->setObjectName(QString::fromUtf8("EGUILogo"));
        EGUILogo->setGeometry(QRect(27, 210, 356, 57));
        EGUILogo->setFocusPolicy(Qt::NoFocus);
        EGUILogo->setTextFormat(Qt::RichText);
        EGUILogo->setPixmap(QPixmap(QString::fromUtf8(":/EncodeGUI/EGUI_logo.png")));
        EGUILogo->setScaledContents(true);
        InputGB = new QGroupBox(HomeTab);
        InputGB->setObjectName(QString::fromUtf8("InputGB"));
        InputGB->setGeometry(QRect(416, 184, 135, 95));
        InputGB->setFocusPolicy(Qt::NoFocus);
        InputGB->setAlignment(Qt::AlignCenter);
        GetVidInfoCB = new QCheckBox(InputGB);
        GetVidInfoCB->setObjectName(QString::fromUtf8("GetVidInfoCB"));
        GetVidInfoCB->setGeometry(QRect(13, 46, 111, 20));
        GetVidInfoCB->setFocusPolicy(Qt::NoFocus);
        GetVidInfoCB->setChecked(true);
        SampleVidCB = new QCheckBox(InputGB);
        SampleVidCB->setObjectName(QString::fromUtf8("SampleVidCB"));
        SampleVidCB->setGeometry(QRect(13, 24, 111, 20));
        SampleVidCB->setFocusPolicy(Qt::NoFocus);
        SampleVidCB->setChecked(false);
        BatchCB = new QCheckBox(InputGB);
        BatchCB->setObjectName(QString::fromUtf8("BatchCB"));
        BatchCB->setGeometry(QRect(13, 68, 111, 21));
        BatchCB->setFocusPolicy(Qt::NoFocus);
        EGUIGB = new QGroupBox(HomeTab);
        EGUIGB->setObjectName(QString::fromUtf8("EGUIGB"));
        EGUIGB->setGeometry(QRect(15, 30, 232, 154));
        EGUIGB->setFocusPolicy(Qt::NoFocus);
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
        VideoEncDD->setGeometry(QRect(104, 27, 121, 22));
        VideoEncDD->setFocusPolicy(Qt::NoFocus);
        VidEncLabel = new QLabel(EGUIGB);
        VidEncLabel->setObjectName(QString::fromUtf8("VidEncLabel"));
        VidEncLabel->setGeometry(QRect(16, 27, 83, 18));
        VidEncLabel->setFocusPolicy(Qt::NoFocus);
        AudioCB = new QCheckBox(EGUIGB);
        AudioCB->setObjectName(QString::fromUtf8("AudioCB"));
        AudioCB->setEnabled(true);
        AudioCB->setGeometry(QRect(13, 58, 75, 20));
        AudioCB->setFocusPolicy(Qt::NoFocus);
        AudioDD = new QComboBox(EGUIGB);
        AudioDD->addItem(QString());
        AudioDD->addItem(QString());
        AudioDD->setObjectName(QString::fromUtf8("AudioDD"));
        AudioDD->setGeometry(QRect(104, 59, 121, 22));
        AudioDD->setFocusPolicy(Qt::NoFocus);
        SubtitlesCB = new QCheckBox(EGUIGB);
        SubtitlesCB->setObjectName(QString::fromUtf8("SubtitlesCB"));
        SubtitlesCB->setEnabled(true);
        SubtitlesCB->setGeometry(QRect(13, 90, 80, 20));
        SubtitlesCB->setFocusPolicy(Qt::NoFocus);
        SubtitlesCB->setCheckable(true);
        SubtitlesDD = new QComboBox(EGUIGB);
        SubtitlesDD->addItem(QString());
        SubtitlesDD->addItem(QString());
        SubtitlesDD->addItem(QString());
        SubtitlesDD->setObjectName(QString::fromUtf8("SubtitlesDD"));
        SubtitlesDD->setGeometry(QRect(104, 91, 121, 22));
        SubtitlesDD->setFocusPolicy(Qt::NoFocus);
        ChaptersCB = new QCheckBox(EGUIGB);
        ChaptersCB->setObjectName(QString::fromUtf8("ChaptersCB"));
        ChaptersCB->setEnabled(false);
        ChaptersCB->setGeometry(QRect(202, 121, 22, 22));
        ChaptersCB->setFocusPolicy(Qt::NoFocus);
        ChaptersLabel = new QLabel(EGUIGB);
        ChaptersLabel->setObjectName(QString::fromUtf8("ChaptersLabel"));
        ChaptersLabel->setGeometry(QRect(16, 119, 91, 23));
        ChaptersLabel->setFocusPolicy(Qt::NoFocus);
        CurrenProcGB = new QGroupBox(HomeTab);
        CurrenProcGB->setObjectName(QString::fromUtf8("CurrenProcGB"));
        CurrenProcGB->setGeometry(QRect(264, 30, 287, 154));
        CurrenProcGB->setMaximumSize(QSize(16777215, 16777215));
        CurrenProcGB->setFocusPolicy(Qt::NoFocus);
        CurrenProcGB->setAlignment(Qt::AlignCenter);
        WhenEncCompleteLabel = new QLabel(CurrenProcGB);
        WhenEncCompleteLabel->setObjectName(QString::fromUtf8("WhenEncCompleteLabel"));
        WhenEncCompleteLabel->setGeometry(QRect(15, 123, 121, 16));
        WhenEncCompleteLabel->setFocusPolicy(Qt::NoFocus);
        WhenEncCompleteLabel->setTextFormat(Qt::AutoText);
        WhenEncCompleteDD = new QComboBox(CurrenProcGB);
        WhenEncCompleteDD->addItem(QString());
        WhenEncCompleteDD->addItem(QString());
        WhenEncCompleteDD->addItem(QString());
        WhenEncCompleteDD->addItem(QString());
        WhenEncCompleteDD->setObjectName(QString::fromUtf8("WhenEncCompleteDD"));
        WhenEncCompleteDD->setGeometry(QRect(158, 122, 121, 22));
        WhenEncCompleteDD->setFocusPolicy(Qt::NoFocus);
        PauseBttn = new QPushButton(CurrenProcGB);
        PauseBttn->setObjectName(QString::fromUtf8("PauseBttn"));
        PauseBttn->setEnabled(false);
        PauseBttn->setGeometry(QRect(13, 86, 125, 32));
        QFont font;
        font.setBold(true);
        PauseBttn->setFont(font);
        PauseBttn->setFocusPolicy(Qt::NoFocus);
        CancelBttn = new QPushButton(CurrenProcGB);
        CancelBttn->setObjectName(QString::fromUtf8("CancelBttn"));
        CancelBttn->setEnabled(false);
        CancelBttn->setGeometry(QRect(147, 86, 127, 32));
        CancelBttn->setFont(font);
        CancelBttn->setFocusPolicy(Qt::NoFocus);
        JobIDLabel = new QLabel(CurrenProcGB);
        JobIDLabel->setObjectName(QString::fromUtf8("JobIDLabel"));
        JobIDLabel->setGeometry(QRect(15, 60, 35, 16));
        JobIDLabel->setFocusPolicy(Qt::NoFocus);
        JobStatusLabel = new QLabel(CurrenProcGB);
        JobStatusLabel->setObjectName(QString::fromUtf8("JobStatusLabel"));
        JobStatusLabel->setGeometry(QRect(147, 58, 39, 20));
        JobStatusLabel->setFocusPolicy(Qt::NoFocus);
        JobStartLabel = new QLabel(CurrenProcGB);
        JobStartLabel->setObjectName(QString::fromUtf8("JobStartLabel"));
        JobStartLabel->setGeometry(QRect(15, 29, 101, 16));
        JobStartLabel->setFocusPolicy(Qt::NoFocus);
        JobIDValueLabel = new QLabel(CurrenProcGB);
        JobIDValueLabel->setObjectName(QString::fromUtf8("JobIDValueLabel"));
        JobIDValueLabel->setGeometry(QRect(52, 58, 80, 20));
        JobIDValueLabel->setFont(font);
        JobIDValueLabel->setFocusPolicy(Qt::NoFocus);
        JobIDValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        JobStatusValueLabel = new QLabel(CurrenProcGB);
        JobStatusValueLabel->setObjectName(QString::fromUtf8("JobStatusValueLabel"));
        JobStatusValueLabel->setGeometry(QRect(191, 58, 82, 20));
        JobStatusValueLabel->setFont(font);
        JobStatusValueLabel->setFocusPolicy(Qt::NoFocus);
        JobStatusValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        JobStartValueLabel = new QLabel(CurrenProcGB);
        JobStartValueLabel->setObjectName(QString::fromUtf8("JobStartValueLabel"));
        JobStartValueLabel->setGeometry(QRect(112, 26, 161, 24));
        JobStartValueLabel->setFont(font);
        JobStartValueLabel->setFocusPolicy(Qt::NoFocus);
        JobStartValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SelectInTxtBox = new QLineEdit(HomeTab);
        SelectInTxtBox->setObjectName(QString::fromUtf8("SelectInTxtBox"));
        SelectInTxtBox->setEnabled(true);
        SelectInTxtBox->setGeometry(QRect(14, 7, 431, 22));
        SelectInTxtBox->setFocusPolicy(Qt::NoFocus);
        SelectInTxtBox->setReadOnly(true);
        SelectInBttn = new QPushButton(HomeTab);
        SelectInBttn->setObjectName(QString::fromUtf8("SelectInBttn"));
        SelectInBttn->setGeometry(QRect(450, 3, 103, 32));
        SelectInBttn->setFocusPolicy(Qt::NoFocus);
        Tabs->addTab(HomeTab, QString());
        VideoTab = new QWidget();
        VideoTab->setObjectName(QString::fromUtf8("VideoTab"));
        VideoTabs = new QTabWidget(VideoTab);
        VideoTabs->setObjectName(QString::fromUtf8("VideoTabs"));
        VideoTabs->setGeometry(QRect(3, 2, 560, 289));
        VideoTabs->setFocusPolicy(Qt::NoFocus);
        x264Tab = new QWidget();
        x264Tab->setObjectName(QString::fromUtf8("x264Tab"));
        x264Tabs = new QTabWidget(x264Tab);
        x264Tabs->setObjectName(QString::fromUtf8("x264Tabs"));
        x264Tabs->setGeometry(QRect(3, 2, 548, 257));
        Main264Tab = new QWidget();
        Main264Tab->setObjectName(QString::fromUtf8("Main264Tab"));
        EncodingSetting264GB = new QGroupBox(Main264Tab);
        EncodingSetting264GB->setObjectName(QString::fromUtf8("EncodingSetting264GB"));
        EncodingSetting264GB->setGeometry(QRect(12, -2, 264, 191));
        EncodingSetting264GB->setAlignment(Qt::AlignCenter);
        EncodeMode264Label = new QLabel(EncodingSetting264GB);
        EncodeMode264Label->setObjectName(QString::fromUtf8("EncodeMode264Label"));
        EncodeMode264Label->setGeometry(QRect(20, 35, 39, 16));
        EncodeMode264DD = new QComboBox(EncodingSetting264GB);
        EncodeMode264DD->addItem(QString());
        EncodeMode264DD->addItem(QString());
        EncodeMode264DD->addItem(QString());
        EncodeMode264DD->addItem(QString());
        EncodeMode264DD->setObjectName(QString::fromUtf8("EncodeMode264DD"));
        EncodeMode264DD->setGeometry(QRect(60, 35, 194, 22));
        EncodeMode264DD->setFocusPolicy(Qt::NoFocus);
        Bitrate264NUD = new QDoubleSpinBox(EncodingSetting264GB);
        Bitrate264NUD->setObjectName(QString::fromUtf8("Bitrate264NUD"));
        Bitrate264NUD->setGeometry(QRect(173, 90, 74, 24));
        Bitrate264NUD->setFocusPolicy(Qt::WheelFocus);
        Bitrate264NUD->setDecimals(0);
        Bitrate264NUD->setMaximum(80000.000000000000000);
        Bitrate264NUD->setValue(2000.000000000000000);
        Tune264CB = new QCheckBox(EncodingSetting264GB);
        Tune264CB->setObjectName(QString::fromUtf8("Tune264CB"));
        Tune264CB->setGeometry(QRect(18, 123, 59, 20));
        Tune264CB->setFocusPolicy(Qt::NoFocus);
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
        Tune264DD->setGeometry(QRect(132, 123, 121, 22));
        Tune264DD->setFocusPolicy(Qt::NoFocus);
        Preset264CB = new QCheckBox(EncodingSetting264GB);
        Preset264CB->setObjectName(QString::fromUtf8("Preset264CB"));
        Preset264CB->setGeometry(QRect(18, 153, 71, 20));
        Preset264CB->setFocusPolicy(Qt::NoFocus);
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
        Preset264DD->setGeometry(QRect(132, 154, 121, 22));
        Preset264DD->setFocusPolicy(Qt::NoFocus);
        Quantizer264Label = new QLabel(EncodingSetting264GB);
        Quantizer264Label->setObjectName(QString::fromUtf8("Quantizer264Label"));
        Quantizer264Label->setGeometry(QRect(20, 92, 141, 16));
        Quantizer264NUD = new QSpinBox(EncodingSetting264GB);
        Quantizer264NUD->setObjectName(QString::fromUtf8("Quantizer264NUD"));
        Quantizer264NUD->setGeometry(QRect(204, 90, 43, 24));
        Quantizer264NUD->setFocusPolicy(Qt::WheelFocus);
        Quantizer264NUD->setMaximum(51);
        Quantizer264NUD->setValue(22);
        CRFValue264NUD = new QSpinBox(EncodingSetting264GB);
        CRFValue264NUD->setObjectName(QString::fromUtf8("CRFValue264NUD"));
        CRFValue264NUD->setGeometry(QRect(204, 90, 43, 24));
        CRFValue264NUD->setMaximum(51);
        CRFValue264NUD->setValue(22);
        CRFValueLabel = new QLabel(EncodingSetting264GB);
        CRFValueLabel->setObjectName(QString::fromUtf8("CRFValueLabel"));
        CRFValueLabel->setGeometry(QRect(20, 92, 79, 16));
        Bitrate264Label = new QLabel(EncodingSetting264GB);
        Bitrate264Label->setObjectName(QString::fromUtf8("Bitrate264Label"));
        Bitrate264Label->setGeometry(QRect(20, 92, 68, 16));
        Profile264GB = new QGroupBox(Main264Tab);
        Profile264GB->setObjectName(QString::fromUtf8("Profile264GB"));
        Profile264GB->setGeometry(QRect(291, -2, 241, 125));
        Profile264GB->setFocusPolicy(Qt::StrongFocus);
        Profile264GB->setAlignment(Qt::AlignCenter);
        Profile264GB->setCheckable(true);
        Profile264GB->setChecked(false);
        Profile264Label = new QLabel(Profile264GB);
        Profile264Label->setObjectName(QString::fromUtf8("Profile264Label"));
        Profile264Label->setGeometry(QRect(17, 31, 45, 20));
        Profile264DD = new QComboBox(Profile264GB);
        Profile264DD->addItem(QString());
        Profile264DD->addItem(QString());
        Profile264DD->addItem(QString());
        Profile264DD->addItem(QString());
        Profile264DD->addItem(QString());
        Profile264DD->setObjectName(QString::fromUtf8("Profile264DD"));
        Profile264DD->setGeometry(QRect(130, 31, 101, 22));
        Profile264DD->setFocusPolicy(Qt::NoFocus);
        Level264Label = new QLabel(Profile264GB);
        Level264Label->setObjectName(QString::fromUtf8("Level264Label"));
        Level264Label->setGeometry(QRect(17, 61, 50, 20));
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
        Level264DD->setGeometry(QRect(130, 62, 101, 22));
        Level264DD->setFocusPolicy(Qt::NoFocus);
        EntropyCode264Label = new QLabel(Profile264GB);
        EntropyCode264Label->setObjectName(QString::fromUtf8("EntropyCode264Label"));
        EntropyCode264Label->setGeometry(QRect(17, 92, 86, 20));
        EntropyCode264DD = new QComboBox(Profile264GB);
        EntropyCode264DD->addItem(QString());
        EntropyCode264DD->addItem(QString());
        EntropyCode264DD->setObjectName(QString::fromUtf8("EntropyCode264DD"));
        EntropyCode264DD->setGeometry(QRect(130, 93, 101, 22));
        EntropyCode264DD->setFocusPolicy(Qt::NoFocus);
        Colors264GB = new QGroupBox(Main264Tab);
        Colors264GB->setObjectName(QString::fromUtf8("Colors264GB"));
        Colors264GB->setGeometry(QRect(291, 128, 241, 89));
        Colors264GB->setAlignment(Qt::AlignCenter);
        Colors264GB->setCheckable(false);
        Colors264GB->setChecked(false);
        BitDepth264Label = new QLabel(Colors264GB);
        BitDepth264Label->setObjectName(QString::fromUtf8("BitDepth264Label"));
        BitDepth264Label->setGeometry(QRect(17, 29, 61, 20));
        BitDepth264DD = new QComboBox(Colors264GB);
        BitDepth264DD->addItem(QString());
        BitDepth264DD->addItem(QString());
        BitDepth264DD->setObjectName(QString::fromUtf8("BitDepth264DD"));
        BitDepth264DD->setGeometry(QRect(149, 29, 81, 22));
        BitDepth264DD->setFocusPolicy(Qt::NoFocus);
        Space264Label = new QLabel(Colors264GB);
        Space264Label->setObjectName(QString::fromUtf8("Space264Label"));
        Space264Label->setGeometry(QRect(17, 56, 94, 20));
        ColorSpace264DD = new QComboBox(Colors264GB);
        ColorSpace264DD->addItem(QString());
        ColorSpace264DD->addItem(QString());
        ColorSpace264DD->setObjectName(QString::fromUtf8("ColorSpace264DD"));
        ColorSpace264DD->setGeometry(QRect(149, 58, 81, 22));
        ColorSpace264DD->setFocusPolicy(Qt::NoFocus);
        x264Tabs->addTab(Main264Tab, QString());
        Fames264Tab = new QWidget();
        Fames264Tab->setObjectName(QString::fromUtf8("Fames264Tab"));
        RefFrames264GB = new QGroupBox(Fames264Tab);
        RefFrames264GB->setObjectName(QString::fromUtf8("RefFrames264GB"));
        RefFrames264GB->setGeometry(QRect(15, -2, 260, 80));
        RefFrames264GB->setAlignment(Qt::AlignCenter);
        RefFrames264GB->setCheckable(true);
        RefFrames264GB->setChecked(false);
        Reference264Sldr = new QSlider(RefFrames264GB);
        Reference264Sldr->setObjectName(QString::fromUtf8("Reference264Sldr"));
        Reference264Sldr->setGeometry(QRect(15, 38, 178, 24));
        Reference264Sldr->setFocusPolicy(Qt::NoFocus);
        Reference264Sldr->setMaximum(16);
        Reference264Sldr->setValue(2);
        Reference264Sldr->setOrientation(Qt::Horizontal);
        Reference264LED = new QLCDNumber(RefFrames264GB);
        Reference264LED->setObjectName(QString::fromUtf8("Reference264LED"));
        Reference264LED->setGeometry(QRect(205, 30, 42, 36));
        Reference264LED->setDigitCount(2);
        Reference264LED->setMode(QLCDNumber::Dec);
        Reference264LED->setSegmentStyle(QLCDNumber::Flat);
        Reference264LED->setProperty("value", QVariant(2.000000000000000));
        BFrames264GB = new QGroupBox(Fames264Tab);
        BFrames264GB->setObjectName(QString::fromUtf8("BFrames264GB"));
        BFrames264GB->setGeometry(QRect(290, -2, 242, 80));
        BFrames264GB->setAlignment(Qt::AlignCenter);
        BFrames264GB->setCheckable(true);
        BFrames264GB->setChecked(false);
        BFrame264Sldr = new QSlider(BFrames264GB);
        BFrame264Sldr->setObjectName(QString::fromUtf8("BFrame264Sldr"));
        BFrame264Sldr->setGeometry(QRect(16, 38, 155, 24));
        BFrame264Sldr->setFocusPolicy(Qt::NoFocus);
        BFrame264Sldr->setMaximum(16);
        BFrame264Sldr->setValue(4);
        BFrame264Sldr->setOrientation(Qt::Horizontal);
        Bframe264LED = new QLCDNumber(BFrames264GB);
        Bframe264LED->setObjectName(QString::fromUtf8("Bframe264LED"));
        Bframe264LED->setGeometry(QRect(183, 30, 41, 36));
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
        x265Tabs->setGeometry(QRect(3, 2, 548, 257));
        Main265Tab = new QWidget();
        Main265Tab->setObjectName(QString::fromUtf8("Main265Tab"));
        Colors265GB = new QGroupBox(Main265Tab);
        Colors265GB->setObjectName(QString::fromUtf8("Colors265GB"));
        Colors265GB->setGeometry(QRect(291, 128, 241, 89));
        Colors265GB->setAlignment(Qt::AlignCenter);
        Colors265GB->setCheckable(false);
        Colors265GB->setChecked(false);
        BitDepth265Label = new QLabel(Colors265GB);
        BitDepth265Label->setObjectName(QString::fromUtf8("BitDepth265Label"));
        BitDepth265Label->setGeometry(QRect(17, 29, 61, 20));
        BitDepth265DD = new QComboBox(Colors265GB);
        BitDepth265DD->addItem(QString());
        BitDepth265DD->addItem(QString());
        BitDepth265DD->addItem(QString());
        BitDepth265DD->setObjectName(QString::fromUtf8("BitDepth265DD"));
        BitDepth265DD->setGeometry(QRect(149, 29, 81, 22));
        BitDepth265DD->setFocusPolicy(Qt::NoFocus);
        Sample265Label = new QLabel(Colors265GB);
        Sample265Label->setObjectName(QString::fromUtf8("Sample265Label"));
        Sample265Label->setGeometry(QRect(17, 56, 74, 20));
        ColorSpace265DD = new QComboBox(Colors265GB);
        ColorSpace265DD->addItem(QString());
        ColorSpace265DD->addItem(QString());
        ColorSpace265DD->addItem(QString());
        ColorSpace265DD->setObjectName(QString::fromUtf8("ColorSpace265DD"));
        ColorSpace265DD->setGeometry(QRect(149, 58, 81, 22));
        ColorSpace265DD->setFocusPolicy(Qt::NoFocus);
        Profile265GB = new QGroupBox(Main265Tab);
        Profile265GB->setObjectName(QString::fromUtf8("Profile265GB"));
        Profile265GB->setGeometry(QRect(291, -2, 241, 125));
        Profile265GB->setAlignment(Qt::AlignCenter);
        Profile265GB->setCheckable(true);
        Profile265GB->setChecked(false);
        Profile265Label = new QLabel(Profile265GB);
        Profile265Label->setObjectName(QString::fromUtf8("Profile265Label"));
        Profile265Label->setGeometry(QRect(17, 31, 45, 20));
        Profile265DD = new QComboBox(Profile265GB);
        Profile265DD->addItem(QString());
        Profile265DD->addItem(QString());
        Profile265DD->addItem(QString());
        Profile265DD->addItem(QString());
        Profile265DD->setObjectName(QString::fromUtf8("Profile265DD"));
        Profile265DD->setGeometry(QRect(130, 31, 101, 22));
        Profile265DD->setFocusPolicy(Qt::NoFocus);
        Level265Label = new QLabel(Profile265GB);
        Level265Label->setObjectName(QString::fromUtf8("Level265Label"));
        Level265Label->setGeometry(QRect(17, 61, 50, 20));
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
        Level265DD->setGeometry(QRect(130, 62, 101, 22));
        Level265DD->setFocusPolicy(Qt::NoFocus);
        Tier265Label = new QLabel(Profile265GB);
        Tier265Label->setObjectName(QString::fromUtf8("Tier265Label"));
        Tier265Label->setGeometry(QRect(17, 92, 38, 20));
        Tier265DD = new QComboBox(Profile265GB);
        Tier265DD->addItem(QString());
        Tier265DD->addItem(QString());
        Tier265DD->setObjectName(QString::fromUtf8("Tier265DD"));
        Tier265DD->setGeometry(QRect(130, 93, 101, 22));
        Tier265DD->setFocusPolicy(Qt::NoFocus);
        EncodingSetting265GB = new QGroupBox(Main265Tab);
        EncodingSetting265GB->setObjectName(QString::fromUtf8("EncodingSetting265GB"));
        EncodingSetting265GB->setGeometry(QRect(12, -2, 264, 191));
        EncodingSetting265GB->setAlignment(Qt::AlignCenter);
        EncodeMode265Label = new QLabel(EncodingSetting265GB);
        EncodeMode265Label->setObjectName(QString::fromUtf8("EncodeMode265Label"));
        EncodeMode265Label->setGeometry(QRect(20, 35, 39, 16));
        EncodeMode265DD = new QComboBox(EncodingSetting265GB);
        EncodeMode265DD->addItem(QString());
        EncodeMode265DD->addItem(QString());
        EncodeMode265DD->addItem(QString());
        EncodeMode265DD->addItem(QString());
        EncodeMode265DD->setObjectName(QString::fromUtf8("EncodeMode265DD"));
        EncodeMode265DD->setGeometry(QRect(60, 35, 194, 22));
        EncodeMode265DD->setFocusPolicy(Qt::NoFocus);
        Bitrate265NUD = new QDoubleSpinBox(EncodingSetting265GB);
        Bitrate265NUD->setObjectName(QString::fromUtf8("Bitrate265NUD"));
        Bitrate265NUD->setGeometry(QRect(173, 90, 74, 24));
        Bitrate265NUD->setFocusPolicy(Qt::WheelFocus);
        Bitrate265NUD->setDecimals(0);
        Bitrate265NUD->setMaximum(80000.000000000000000);
        Bitrate265NUD->setValue(2000.000000000000000);
        Tune265CB = new QCheckBox(EncodingSetting265GB);
        Tune265CB->setObjectName(QString::fromUtf8("Tune265CB"));
        Tune265CB->setGeometry(QRect(18, 123, 59, 20));
        Tune265CB->setFocusPolicy(Qt::NoFocus);
        Tune265DD = new QComboBox(EncodingSetting265GB);
        Tune265DD->addItem(QString());
        Tune265DD->addItem(QString());
        Tune265DD->addItem(QString());
        Tune265DD->addItem(QString());
        Tune265DD->addItem(QString());
        Tune265DD->addItem(QString());
        Tune265DD->setObjectName(QString::fromUtf8("Tune265DD"));
        Tune265DD->setGeometry(QRect(132, 123, 121, 22));
        Tune265DD->setFocusPolicy(Qt::NoFocus);
        Preset265CB = new QCheckBox(EncodingSetting265GB);
        Preset265CB->setObjectName(QString::fromUtf8("Preset265CB"));
        Preset265CB->setGeometry(QRect(18, 153, 71, 20));
        Preset265CB->setFocusPolicy(Qt::NoFocus);
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
        Preset265DD->setGeometry(QRect(132, 154, 121, 22));
        Preset265DD->setFocusPolicy(Qt::NoFocus);
        Quantizer265Label = new QLabel(EncodingSetting265GB);
        Quantizer265Label->setObjectName(QString::fromUtf8("Quantizer265Label"));
        Quantizer265Label->setGeometry(QRect(20, 92, 141, 16));
        Quantizer265NUD = new QSpinBox(EncodingSetting265GB);
        Quantizer265NUD->setObjectName(QString::fromUtf8("Quantizer265NUD"));
        Quantizer265NUD->setGeometry(QRect(204, 90, 43, 24));
        Quantizer265NUD->setFocusPolicy(Qt::WheelFocus);
        Quantizer265NUD->setMaximum(51);
        Quantizer265NUD->setValue(22);
        CRFValue265NUD = new QSpinBox(EncodingSetting265GB);
        CRFValue265NUD->setObjectName(QString::fromUtf8("CRFValue265NUD"));
        CRFValue265NUD->setGeometry(QRect(204, 90, 43, 24));
        CRFValue265NUD->setFocusPolicy(Qt::WheelFocus);
        CRFValue265NUD->setMaximum(51);
        CRFValue265NUD->setValue(22);
        CRFValue265Label = new QLabel(EncodingSetting265GB);
        CRFValue265Label->setObjectName(QString::fromUtf8("CRFValue265Label"));
        CRFValue265Label->setGeometry(QRect(20, 92, 79, 16));
        Bitrate265Label = new QLabel(EncodingSetting265GB);
        Bitrate265Label->setObjectName(QString::fromUtf8("Bitrate265Label"));
        Bitrate265Label->setGeometry(QRect(20, 92, 79, 16));
        x265Tabs->addTab(Main265Tab, QString());
        Fames265Tab = new QWidget();
        Fames265Tab->setObjectName(QString::fromUtf8("Fames265Tab"));
        RefFrames265GB = new QGroupBox(Fames265Tab);
        RefFrames265GB->setObjectName(QString::fromUtf8("RefFrames265GB"));
        RefFrames265GB->setGeometry(QRect(15, -2, 260, 80));
        RefFrames265GB->setAlignment(Qt::AlignCenter);
        RefFrames265GB->setCheckable(true);
        RefFrames265GB->setChecked(false);
        Reference265Sldr = new QSlider(RefFrames265GB);
        Reference265Sldr->setObjectName(QString::fromUtf8("Reference265Sldr"));
        Reference265Sldr->setGeometry(QRect(15, 38, 178, 24));
        Reference265Sldr->setFocusPolicy(Qt::NoFocus);
        Reference265Sldr->setMaximum(8);
        Reference265Sldr->setValue(2);
        Reference265Sldr->setOrientation(Qt::Horizontal);
        Reference265LED = new QLCDNumber(RefFrames265GB);
        Reference265LED->setObjectName(QString::fromUtf8("Reference265LED"));
        Reference265LED->setGeometry(QRect(205, 30, 42, 36));
        Reference265LED->setDigitCount(2);
        Reference265LED->setMode(QLCDNumber::Dec);
        Reference265LED->setSegmentStyle(QLCDNumber::Flat);
        Reference265LED->setProperty("value", QVariant(2.000000000000000));
        BFrames265GB = new QGroupBox(Fames265Tab);
        BFrames265GB->setObjectName(QString::fromUtf8("BFrames265GB"));
        BFrames265GB->setGeometry(QRect(290, -2, 242, 80));
        BFrames265GB->setAlignment(Qt::AlignCenter);
        BFrames265GB->setCheckable(true);
        BFrames265GB->setChecked(false);
        BFrame265Sldr = new QSlider(BFrames265GB);
        BFrame265Sldr->setObjectName(QString::fromUtf8("BFrame265Sldr"));
        BFrame265Sldr->setGeometry(QRect(16, 38, 155, 24));
        BFrame265Sldr->setFocusPolicy(Qt::NoFocus);
        BFrame265Sldr->setMaximum(16);
        BFrame265Sldr->setValue(4);
        BFrame265Sldr->setOrientation(Qt::Horizontal);
        Bframe265LED = new QLCDNumber(BFrames265GB);
        Bframe265LED->setObjectName(QString::fromUtf8("Bframe265LED"));
        Bframe265LED->setGeometry(QRect(183, 30, 41, 36));
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
        EncodingProResGB->setGeometry(QRect(15, -2, 523, 70));
        EncodingProResGB->setAlignment(Qt::AlignCenter);
        ProfileLabel = new QLabel(EncodingProResGB);
        ProfileLabel->setObjectName(QString::fromUtf8("ProfileLabel"));
        ProfileLabel->setGeometry(QRect(18, 34, 49, 18));
        ProfileDD = new QComboBox(EncodingProResGB);
        ProfileDD->addItem(QString());
        ProfileDD->addItem(QString());
        ProfileDD->addItem(QString());
        ProfileDD->addItem(QString());
        ProfileDD->addItem(QString());
        ProfileDD->addItem(QString());
        ProfileDD->setObjectName(QString::fromUtf8("ProfileDD"));
        ProfileDD->setGeometry(QRect(370, 34, 141, 22));
        ProfileDD->setFocusPolicy(Qt::NoFocus);
        ColorsGB = new QGroupBox(ProResTab);
        ColorsGB->setObjectName(QString::fromUtf8("ColorsGB"));
        ColorsGB->setGeometry(QRect(15, 72, 523, 125));
        ColorsGB->setAlignment(Qt::AlignCenter);
        ColorsGB->setCheckable(true);
        ColorsGB->setChecked(false);
        MatrixProResLabel = new QLabel(ColorsGB);
        MatrixProResLabel->setObjectName(QString::fromUtf8("MatrixProResLabel"));
        MatrixProResLabel->setGeometry(QRect(18, 29, 43, 27));
        MatrixProResDD = new QComboBox(ColorsGB);
        MatrixProResDD->addItem(QString());
        MatrixProResDD->addItem(QString());
        MatrixProResDD->addItem(QString());
        MatrixProResDD->addItem(QString());
        MatrixProResDD->addItem(QString());
        MatrixProResDD->setObjectName(QString::fromUtf8("MatrixProResDD"));
        MatrixProResDD->setGeometry(QRect(370, 32, 141, 22));
        MatrixProResDD->setFocusPolicy(Qt::NoFocus);
        TransferProResLabel = new QLabel(ColorsGB);
        TransferProResLabel->setObjectName(QString::fromUtf8("TransferProResLabel"));
        TransferProResLabel->setGeometry(QRect(18, 60, 61, 22));
        TransferProResDD = new QComboBox(ColorsGB);
        TransferProResDD->addItem(QString());
        TransferProResDD->addItem(QString());
        TransferProResDD->addItem(QString());
        TransferProResDD->addItem(QString());
        TransferProResDD->addItem(QString());
        TransferProResDD->setObjectName(QString::fromUtf8("TransferProResDD"));
        TransferProResDD->setGeometry(QRect(370, 61, 141, 22));
        TransferProResDD->setFocusPolicy(Qt::NoFocus);
        PrimariesProResLabel = new QLabel(ColorsGB);
        PrimariesProResLabel->setObjectName(QString::fromUtf8("PrimariesProResLabel"));
        PrimariesProResLabel->setGeometry(QRect(18, 89, 71, 20));
        PrimairesProResDD = new QComboBox(ColorsGB);
        PrimairesProResDD->addItem(QString());
        PrimairesProResDD->addItem(QString());
        PrimairesProResDD->addItem(QString());
        PrimairesProResDD->addItem(QString());
        PrimairesProResDD->addItem(QString());
        PrimairesProResDD->addItem(QString());
        PrimairesProResDD->setObjectName(QString::fromUtf8("PrimairesProResDD"));
        PrimairesProResDD->setGeometry(QRect(370, 90, 141, 22));
        PrimairesProResDD->setFocusPolicy(Qt::NoFocus);
        VideoTabs->addTab(ProResTab, QString());
        TheoraTab = new QWidget();
        TheoraTab->setObjectName(QString::fromUtf8("TheoraTab"));
        EncodeTheoraGB = new QGroupBox(TheoraTab);
        EncodeTheoraGB->setObjectName(QString::fromUtf8("EncodeTheoraGB"));
        EncodeTheoraGB->setGeometry(QRect(15, -2, 523, 101));
        EncodeTheoraGB->setAlignment(Qt::AlignCenter);
        QualityLabel = new QLabel(EncodeTheoraGB);
        QualityLabel->setObjectName(QString::fromUtf8("QualityLabel"));
        QualityLabel->setGeometry(QRect(18, 61, 61, 23));
        QualityNUD = new QSpinBox(EncodeTheoraGB);
        QualityNUD->setObjectName(QString::fromUtf8("QualityNUD"));
        QualityNUD->setGeometry(QRect(462, 63, 43, 24));
        QualityNUD->setFocusPolicy(Qt::NoFocus);
        QualityNUD->setMaximum(10);
        QualityNUD->setValue(6);
        EncodeModeTLabel = new QLabel(EncodeTheoraGB);
        EncodeModeTLabel->setObjectName(QString::fromUtf8("EncodeModeTLabel"));
        EncodeModeTLabel->setGeometry(QRect(18, 33, 38, 16));
        EncodeModeTDD = new QComboBox(EncodeTheoraGB);
        EncodeModeTDD->addItem(QString());
        EncodeModeTDD->addItem(QString());
        EncodeModeTDD->setObjectName(QString::fromUtf8("EncodeModeTDD"));
        EncodeModeTDD->setGeometry(QRect(321, 33, 191, 22));
        EncodeModeTDD->setFocusPolicy(Qt::NoFocus);
        BitrateThLabel = new QLabel(EncodeTheoraGB);
        BitrateThLabel->setObjectName(QString::fromUtf8("BitrateThLabel"));
        BitrateThLabel->setGeometry(QRect(18, 65, 111, 16));
        BitrateThNUD = new QSpinBox(EncodeTheoraGB);
        BitrateThNUD->setObjectName(QString::fromUtf8("BitrateThNUD"));
        BitrateThNUD->setGeometry(QRect(441, 63, 64, 24));
        BitrateThNUD->setFocusPolicy(Qt::WheelFocus);
        BitrateThNUD->setMinimum(500);
        BitrateThNUD->setMaximum(60000);
        BitrateThNUD->setValue(1500);
        VideoTabs->addTab(TheoraTab, QString());
        VPXTab = new QWidget();
        VPXTab->setObjectName(QString::fromUtf8("VPXTab"));
        EncodingSettingVPXGB = new QGroupBox(VPXTab);
        EncodingSettingVPXGB->setObjectName(QString::fromUtf8("EncodingSettingVPXGB"));
        EncodingSettingVPXGB->setGeometry(QRect(15, -2, 266, 108));
        EncodingSettingVPXGB->setAlignment(Qt::AlignCenter);
        EncodeModeVPXLabel = new QLabel(EncodingSettingVPXGB);
        EncodeModeVPXLabel->setObjectName(QString::fromUtf8("EncodeModeVPXLabel"));
        EncodeModeVPXLabel->setGeometry(QRect(18, 34, 39, 16));
        EncodeModeVPXDD = new QComboBox(EncodingSettingVPXGB);
        EncodeModeVPXDD->addItem(QString());
        EncodeModeVPXDD->addItem(QString());
        EncodeModeVPXDD->addItem(QString());
        EncodeModeVPXDD->setObjectName(QString::fromUtf8("EncodeModeVPXDD"));
        EncodeModeVPXDD->setGeometry(QRect(64, 34, 191, 22));
        EncodeModeVPXDD->setFocusPolicy(Qt::NoFocus);
        BitrateVPXNUD = new QDoubleSpinBox(EncodingSettingVPXGB);
        BitrateVPXNUD->setObjectName(QString::fromUtf8("BitrateVPXNUD"));
        BitrateVPXNUD->setGeometry(QRect(176, 70, 72, 24));
        BitrateVPXNUD->setFocusPolicy(Qt::WheelFocus);
        BitrateVPXNUD->setDecimals(0);
        BitrateVPXNUD->setMaximum(80000.000000000000000);
        BitrateVPXNUD->setValue(2000.000000000000000);
        crfVPXNUD = new QSpinBox(EncodingSettingVPXGB);
        crfVPXNUD->setObjectName(QString::fromUtf8("crfVPXNUD"));
        crfVPXNUD->setGeometry(QRect(205, 70, 43, 24));
        crfVPXNUD->setFocusPolicy(Qt::WheelFocus);
        crfVPXNUD->setMaximum(63);
        crfVPXNUD->setValue(22);
        crfVPXLabel = new QLabel(EncodingSettingVPXGB);
        crfVPXLabel->setObjectName(QString::fromUtf8("crfVPXLabel"));
        crfVPXLabel->setGeometry(QRect(18, 72, 73, 16));
        BitrateVPXLabel = new QLabel(EncodingSettingVPXGB);
        BitrateVPXLabel->setObjectName(QString::fromUtf8("BitrateVPXLabel"));
        BitrateVPXLabel->setGeometry(QRect(19, 72, 61, 16));
        ProfileVPXGB = new QGroupBox(VPXTab);
        ProfileVPXGB->setObjectName(QString::fromUtf8("ProfileVPXGB"));
        ProfileVPXGB->setGeometry(QRect(295, -2, 243, 101));
        ProfileVPXGB->setAlignment(Qt::AlignCenter);
        ProfileVPXGB->setCheckable(false);
        ProfileVPXGB->setChecked(false);
        Profile264Label_2 = new QLabel(ProfileVPXGB);
        Profile264Label_2->setObjectName(QString::fromUtf8("Profile264Label_2"));
        Profile264Label_2->setGeometry(QRect(17, 32, 45, 20));
        ProfileVPXDD = new QComboBox(ProfileVPXGB);
        ProfileVPXDD->addItem(QString());
        ProfileVPXDD->addItem(QString());
        ProfileVPXDD->addItem(QString());
        ProfileVPXDD->addItem(QString());
        ProfileVPXDD->setObjectName(QString::fromUtf8("ProfileVPXDD"));
        ProfileVPXDD->setGeometry(QRect(132, 33, 101, 22));
        ProfileVPXDD->setFocusPolicy(Qt::NoFocus);
        SpeedLabel = new QLabel(ProfileVPXGB);
        SpeedLabel->setObjectName(QString::fromUtf8("SpeedLabel"));
        SpeedLabel->setGeometry(QRect(17, 65, 50, 20));
        SpeedDD = new QComboBox(ProfileVPXGB);
        SpeedDD->addItem(QString());
        SpeedDD->addItem(QString());
        SpeedDD->setObjectName(QString::fromUtf8("SpeedDD"));
        SpeedDD->setGeometry(QRect(132, 66, 101, 22));
        SpeedDD->setFocusPolicy(Qt::NoFocus);
        ColorsVPXGB = new QGroupBox(VPXTab);
        ColorsVPXGB->setObjectName(QString::fromUtf8("ColorsVPXGB"));
        ColorsVPXGB->setGeometry(QRect(295, 102, 243, 99));
        ColorsVPXGB->setAlignment(Qt::AlignCenter);
        ColorsVPXGB->setCheckable(false);
        ColorsVPXGB->setChecked(false);
        BitDepthVPXLabel = new QLabel(ColorsVPXGB);
        BitDepthVPXLabel->setObjectName(QString::fromUtf8("BitDepthVPXLabel"));
        BitDepthVPXLabel->setGeometry(QRect(17, 32, 61, 20));
        BitDepthVPXDD = new QComboBox(ColorsVPXGB);
        BitDepthVPXDD->addItem(QString());
        BitDepthVPXDD->addItem(QString());
        BitDepthVPXDD->setObjectName(QString::fromUtf8("BitDepthVPXDD"));
        BitDepthVPXDD->setGeometry(QRect(152, 32, 81, 22));
        BitDepthVPXDD->setFocusPolicy(Qt::NoFocus);
        SampleVPXLabel = new QLabel(ColorsVPXGB);
        SampleVPXLabel->setObjectName(QString::fromUtf8("SampleVPXLabel"));
        SampleVPXLabel->setGeometry(QRect(17, 61, 92, 26));
        SampleVPXDD = new QComboBox(ColorsVPXGB);
        SampleVPXDD->addItem(QString());
        SampleVPXDD->addItem(QString());
        SampleVPXDD->setObjectName(QString::fromUtf8("SampleVPXDD"));
        SampleVPXDD->setGeometry(QRect(152, 65, 81, 22));
        SampleVPXDD->setFocusPolicy(Qt::NoFocus);
        VideoTabs->addTab(VPXTab, QString());
        av1Tab = new QWidget();
        av1Tab->setObjectName(QString::fromUtf8("av1Tab"));
        EncodingSettingAV1GB = new QGroupBox(av1Tab);
        EncodingSettingAV1GB->setObjectName(QString::fromUtf8("EncodingSettingAV1GB"));
        EncodingSettingAV1GB->setGeometry(QRect(15, -2, 266, 108));
        EncodingSettingAV1GB->setAlignment(Qt::AlignCenter);
        EncodeModeAV1Label = new QLabel(EncodingSettingAV1GB);
        EncodeModeAV1Label->setObjectName(QString::fromUtf8("EncodeModeAV1Label"));
        EncodeModeAV1Label->setGeometry(QRect(18, 34, 39, 16));
        EncodeModeAV1DD = new QComboBox(EncodingSettingAV1GB);
        EncodeModeAV1DD->addItem(QString());
        EncodeModeAV1DD->addItem(QString());
        EncodeModeAV1DD->setObjectName(QString::fromUtf8("EncodeModeAV1DD"));
        EncodeModeAV1DD->setGeometry(QRect(64, 34, 191, 22));
        EncodeModeAV1DD->setFocusPolicy(Qt::NoFocus);
        BitrateAV1NUD = new QDoubleSpinBox(EncodingSettingAV1GB);
        BitrateAV1NUD->setObjectName(QString::fromUtf8("BitrateAV1NUD"));
        BitrateAV1NUD->setGeometry(QRect(167, 70, 81, 24));
        BitrateAV1NUD->setFocusPolicy(Qt::WheelFocus);
        BitrateAV1NUD->setDecimals(0);
        BitrateAV1NUD->setMaximum(80000.000000000000000);
        BitrateAV1NUD->setValue(2000.000000000000000);
        crfAV1NUD = new QSpinBox(EncodingSettingAV1GB);
        crfAV1NUD->setObjectName(QString::fromUtf8("crfAV1NUD"));
        crfAV1NUD->setGeometry(QRect(205, 70, 43, 24));
        crfAV1NUD->setFocusPolicy(Qt::WheelFocus);
        crfAV1NUD->setMaximum(63);
        crfAV1NUD->setValue(22);
        crfAV1Label = new QLabel(EncodingSettingAV1GB);
        crfAV1Label->setObjectName(QString::fromUtf8("crfAV1Label"));
        crfAV1Label->setGeometry(QRect(18, 72, 73, 16));
        BitrateAV1Label = new QLabel(EncodingSettingAV1GB);
        BitrateAV1Label->setObjectName(QString::fromUtf8("BitrateAV1Label"));
        BitrateAV1Label->setGeometry(QRect(19, 72, 61, 16));
        ColorsAV1GB = new QGroupBox(av1Tab);
        ColorsAV1GB->setObjectName(QString::fromUtf8("ColorsAV1GB"));
        ColorsAV1GB->setGeometry(QRect(295, -2, 243, 71));
        ColorsAV1GB->setAlignment(Qt::AlignCenter);
        ColorsAV1GB->setCheckable(false);
        ColorsAV1GB->setChecked(false);
        BitDepthAV1Label = new QLabel(ColorsAV1GB);
        BitDepthAV1Label->setObjectName(QString::fromUtf8("BitDepthAV1Label"));
        BitDepthAV1Label->setGeometry(QRect(17, 33, 61, 20));
        BitDepthAV1DD = new QComboBox(ColorsAV1GB);
        BitDepthAV1DD->addItem(QString());
        BitDepthAV1DD->addItem(QString());
        BitDepthAV1DD->setObjectName(QString::fromUtf8("BitDepthAV1DD"));
        BitDepthAV1DD->setGeometry(QRect(140, 34, 91, 22));
        BitDepthAV1DD->setFocusPolicy(Qt::NoFocus);
        VideoTabs->addTab(av1Tab, QString());
        HDRTab = new QWidget();
        HDRTab->setObjectName(QString::fromUtf8("HDRTab"));
        SignalsTabs = new QTabWidget(HDRTab);
        SignalsTabs->setObjectName(QString::fromUtf8("SignalsTabs"));
        SignalsTabs->setGeometry(QRect(3, 2, 547, 256));
        HDRTab1 = new QWidget();
        HDRTab1->setObjectName(QString::fromUtf8("HDRTab1"));
        HDRMetadataGB = new QGroupBox(HDRTab1);
        HDRMetadataGB->setObjectName(QString::fromUtf8("HDRMetadataGB"));
        HDRMetadataGB->setGeometry(QRect(12, -2, 517, 121));
        HDRMetadataGB->setAlignment(Qt::AlignCenter);
        HDRMetadataGB->setCheckable(true);
        HDRMetadataGB->setChecked(false);
        LightLevelLabel = new QLabel(HDRMetadataGB);
        LightLevelLabel->setObjectName(QString::fromUtf8("LightLevelLabel"));
        LightLevelLabel->setGeometry(QRect(17, 30, 171, 16));
        Slash6Label = new QLabel(HDRMetadataGB);
        Slash6Label->setObjectName(QString::fromUtf8("Slash6Label"));
        Slash6Label->setGeometry(QRect(432, 31, 16, 16));
        MaxCllNUD = new QSpinBox(HDRMetadataGB);
        MaxCllNUD->setObjectName(QString::fromUtf8("MaxCllNUD"));
        MaxCllNUD->setGeometry(QRect(363, 28, 62, 24));
        MaxCllNUD->setFocusPolicy(Qt::WheelFocus);
        MaxCllNUD->setMinimum(0);
        MaxCllNUD->setMaximum(65535);
        MaxCllNUD->setValue(1000);
        MaxFallNUD = new QSpinBox(HDRMetadataGB);
        MaxFallNUD->setObjectName(QString::fromUtf8("MaxFallNUD"));
        MaxFallNUD->setGeometry(QRect(441, 28, 62, 24));
        MaxFallNUD->setFocusPolicy(Qt::WheelFocus);
        MaxFallNUD->setMinimum(0);
        MaxFallNUD->setMaximum(65535);
        MaxFallNUD->setValue(1);
        MasterDisplayLabel = new QLabel(HDRMetadataGB);
        MasterDisplayLabel->setObjectName(QString::fromUtf8("MasterDisplayLabel"));
        MasterDisplayLabel->setGeometry(QRect(17, 59, 101, 16));
        MasterDisplayTxtBox = new QLineEdit(HDRMetadataGB);
        MasterDisplayTxtBox->setObjectName(QString::fromUtf8("MasterDisplayTxtBox"));
        MasterDisplayTxtBox->setGeometry(QRect(115, 58, 388, 21));
        MasterDisplayTxtBox->setFocusPolicy(Qt::NoFocus);
        DynamicMetadataLabel = new QLabel(HDRMetadataGB);
        DynamicMetadataLabel->setObjectName(QString::fromUtf8("DynamicMetadataLabel"));
        DynamicMetadataLabel->setGeometry(QRect(17, 84, 121, 24));
        DynamicMetadataBttn = new QPushButton(HDRMetadataGB);
        DynamicMetadataBttn->setObjectName(QString::fromUtf8("DynamicMetadataBttn"));
        DynamicMetadataBttn->setGeometry(QRect(417, 82, 86, 32));
        DynamicMetadataBttn->setFocusPolicy(Qt::NoFocus);
        DynamicHDRTxtBox = new QLineEdit(HDRMetadataGB);
        DynamicHDRTxtBox->setObjectName(QString::fromUtf8("DynamicHDRTxtBox"));
        DynamicHDRTxtBox->setGeometry(QRect(136, 87, 275, 21));
        DynamicHDRTxtBox->setFocusPolicy(Qt::NoFocus);
        DynamicHDRTxtBox->setReadOnly(true);
        DBVisionGB = new QGroupBox(HDRTab1);
        DBVisionGB->setObjectName(QString::fromUtf8("DBVisionGB"));
        DBVisionGB->setGeometry(QRect(12, 124, 517, 91));
        DBVisionGB->setAlignment(Qt::AlignCenter);
        DBVisionGB->setCheckable(true);
        DBVisionGB->setChecked(false);
        DBProfileLabel = new QLabel(DBVisionGB);
        DBProfileLabel->setObjectName(QString::fromUtf8("DBProfileLabel"));
        DBProfileLabel->setGeometry(QRect(18, 32, 49, 16));
        RpuLabel = new QLabel(DBVisionGB);
        RpuLabel->setObjectName(QString::fromUtf8("RpuLabel"));
        RpuLabel->setGeometry(QRect(18, 60, 61, 16));
        DBProfileDD = new QComboBox(DBVisionGB);
        DBProfileDD->addItem(QString());
        DBProfileDD->addItem(QString());
        DBProfileDD->addItem(QString());
        DBProfileDD->setObjectName(QString::fromUtf8("DBProfileDD"));
        DBProfileDD->setGeometry(QRect(448, 30, 61, 22));
        RpuTxtBox = new QLineEdit(DBVisionGB);
        RpuTxtBox->setObjectName(QString::fromUtf8("RpuTxtBox"));
        RpuTxtBox->setGeometry(QRect(76, 59, 281, 21));
        RpuTxtBox->setFocusPolicy(Qt::NoFocus);
        RpuTxtBox->setReadOnly(true);
        RpuFileBttn = new QPushButton(DBVisionGB);
        RpuFileBttn->setObjectName(QString::fromUtf8("RpuFileBttn"));
        RpuFileBttn->setGeometry(QRect(362, 54, 141, 32));
        RpuFileBttn->setFocusPolicy(Qt::NoFocus);
        SignalsTabs->addTab(HDRTab1, QString());
        Colors3Tab = new QWidget();
        Colors3Tab->setObjectName(QString::fromUtf8("Colors3Tab"));
        ColorsHDRGB = new QGroupBox(Colors3Tab);
        ColorsHDRGB->setObjectName(QString::fromUtf8("ColorsHDRGB"));
        ColorsHDRGB->setGeometry(QRect(12, -2, 517, 171));
        ColorsHDRGB->setAlignment(Qt::AlignCenter);
        ColorsHDRGB->setCheckable(true);
        ColorsHDRGB->setChecked(false);
        ColorRangeLabel = new QLabel(ColorsHDRGB);
        ColorRangeLabel->setObjectName(QString::fromUtf8("ColorRangeLabel"));
        ColorRangeLabel->setGeometry(QRect(19, 33, 69, 24));
        ColorMatrixLabel = new QLabel(ColorsHDRGB);
        ColorMatrixLabel->setObjectName(QString::fromUtf8("ColorMatrixLabel"));
        ColorMatrixLabel->setGeometry(QRect(19, 69, 72, 16));
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
        ColorTransferDD->setGeometry(QRect(374, 100, 131, 22));
        ColorTransferDD->setFocusPolicy(Qt::NoFocus);
        ColorPrimariesLabel = new QLabel(ColorsHDRGB);
        ColorPrimariesLabel->setObjectName(QString::fromUtf8("ColorPrimariesLabel"));
        ColorPrimariesLabel->setGeometry(QRect(19, 132, 89, 20));
        ColorTransferLabel = new QLabel(ColorsHDRGB);
        ColorTransferLabel->setObjectName(QString::fromUtf8("ColorTransferLabel"));
        ColorTransferLabel->setGeometry(QRect(19, 98, 85, 22));
        ColorRangeDD = new QComboBox(ColorsHDRGB);
        ColorRangeDD->addItem(QString());
        ColorRangeDD->addItem(QString());
        ColorRangeDD->setObjectName(QString::fromUtf8("ColorRangeDD"));
        ColorRangeDD->setGeometry(QRect(374, 35, 131, 22));
        ColorRangeDD->setFocusPolicy(Qt::NoFocus);
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
        ColorMatrixDD->setGeometry(QRect(374, 67, 131, 22));
        ColorMatrixDD->setFocusPolicy(Qt::NoFocus);
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
        ColorPrimariesDD->setGeometry(QRect(374, 133, 131, 22));
        ColorPrimariesDD->setFocusPolicy(Qt::NoFocus);
        SignalsTabs->addTab(Colors3Tab, QString());
        VideoTabs->addTab(HDRTab, QString());
        VSTab = new QWidget();
        VSTab->setObjectName(QString::fromUtf8("VSTab"));
        VSTabs = new QTabWidget(VSTab);
        VSTabs->setObjectName(QString::fromUtf8("VSTabs"));
        VSTabs->setGeometry(QRect(3, 2, 547, 257));
        VSTabs->setFocusPolicy(Qt::NoFocus);
        InterpolationTab = new QWidget();
        InterpolationTab->setObjectName(QString::fromUtf8("InterpolationTab"));
        InterpolationCB = new QGroupBox(InterpolationTab);
        InterpolationCB->setObjectName(QString::fromUtf8("InterpolationCB"));
        InterpolationCB->setGeometry(QRect(12, -2, 517, 221));
        InterpolationCB->setAlignment(Qt::AlignCenter);
        InterpolationCB->setCheckable(true);
        InterpolationCB->setChecked(false);
        ToolInterpDD = new QComboBox(InterpolationCB);
        ToolInterpDD->addItem(QString());
        ToolInterpDD->setObjectName(QString::fromUtf8("ToolInterpDD"));
        ToolInterpDD->setGeometry(QRect(273, 33, 71, 22));
        ToolInterpDD->setFocusPolicy(Qt::NoFocus);
        ToolInterpLabel = new QLabel(InterpolationCB);
        ToolInterpLabel->setObjectName(QString::fromUtf8("ToolInterpLabel"));
        ToolInterpLabel->setGeometry(QRect(23, 34, 141, 16));
        UseGPUCB = new QCheckBox(InterpolationCB);
        UseGPUCB->setObjectName(QString::fromUtf8("UseGPUCB"));
        UseGPUCB->setGeometry(QRect(21, 64, 81, 20));
        UseGPUCB->setFocusPolicy(Qt::NoFocus);
        UseGPUCB->setChecked(true);
        GPUInterpDD = new QComboBox(InterpolationCB);
        GPUInterpDD->setObjectName(QString::fromUtf8("GPUInterpDD"));
        GPUInterpDD->setEnabled(false);
        GPUInterpDD->setGeometry(QRect(104, 65, 191, 22));
        GPUInterpDD->setFocusPolicy(Qt::NoFocus);
        GPUThreadInterpLabel = new QLabel(InterpolationCB);
        GPUThreadInterpLabel->setObjectName(QString::fromUtf8("GPUThreadInterpLabel"));
        GPUThreadInterpLabel->setEnabled(false);
        GPUThreadInterpLabel->setGeometry(QRect(365, 63, 91, 20));
        GPUThreadDD = new QComboBox(InterpolationCB);
        GPUThreadDD->addItem(QString());
        GPUThreadDD->setObjectName(QString::fromUtf8("GPUThreadDD"));
        GPUThreadDD->setEnabled(false);
        GPUThreadDD->setGeometry(QRect(450, 64, 51, 22));
        GPUThreadDD->setFocusPolicy(Qt::NoFocus);
        ModelInterpLabel = new QLabel(InterpolationCB);
        ModelInterpLabel->setObjectName(QString::fromUtf8("ModelInterpLabel"));
        ModelInterpLabel->setGeometry(QRect(23, 96, 52, 16));
        SceneChangeCB = new QCheckBox(InterpolationCB);
        SceneChangeCB->setObjectName(QString::fromUtf8("SceneChangeCB"));
        SceneChangeCB->setGeometry(QRect(478, 125, 25, 20));
        SceneChangeCB->setFocusPolicy(Qt::NoFocus);
        SceneChangeCB->setChecked(true);
        OutputFPSNUD = new QDoubleSpinBox(InterpolationCB);
        OutputFPSNUD->setObjectName(QString::fromUtf8("OutputFPSNUD"));
        OutputFPSNUD->setGeometry(QRect(423, 184, 71, 24));
        OutputFPSNUD->setFocusPolicy(Qt::WheelFocus);
        OutputFPSNUD->setDecimals(3);
        OutputFPSNUD->setMinimum(10.000000000000000);
        OutputFPSNUD->setMaximum(780.000000000000000);
        OutputFPSNUD->setValue(60.000000000000000);
        OutFPSLabel = new QLabel(InterpolationCB);
        OutFPSLabel->setObjectName(QString::fromUtf8("OutFPSLabel"));
        OutFPSLabel->setGeometry(QRect(23, 188, 81, 16));
        SceneChangeLabel = new QLabel(InterpolationCB);
        SceneChangeLabel->setObjectName(QString::fromUtf8("SceneChangeLabel"));
        SceneChangeLabel->setGeometry(QRect(23, 127, 195, 16));
        BackendDD = new QComboBox(InterpolationCB);
        BackendDD->addItem(QString());
        BackendDD->setObjectName(QString::fromUtf8("BackendDD"));
        BackendDD->setGeometry(QRect(350, 33, 151, 22));
        BackendDD->setFocusPolicy(Qt::NoFocus);
        SlashLabel = new QLabel(InterpolationCB);
        SlashLabel->setObjectName(QString::fromUtf8("SlashLabel"));
        SlashLabel->setGeometry(QRect(345, 34, 19, 16));
        SlashLabel->setFont(font);
        RIFEModelVKDD = new QComboBox(InterpolationCB);
        RIFEModelVKDD->addItem(QString());
        RIFEModelVKDD->addItem(QString());
        RIFEModelVKDD->addItem(QString());
        RIFEModelVKDD->addItem(QString());
        RIFEModelVKDD->addItem(QString());
        RIFEModelVKDD->addItem(QString());
        RIFEModelVKDD->setObjectName(QString::fromUtf8("RIFEModelVKDD"));
        RIFEModelVKDD->setGeometry(QRect(430, 95, 71, 22));
        RIFEModelVKDD->setFocusPolicy(Qt::NoFocus);
        Times2Label = new QLabel(InterpolationCB);
        Times2Label->setObjectName(QString::fromUtf8("Times2Label"));
        Times2Label->setGeometry(QRect(393, 187, 31, 16));
        SCThresholdNUD = new QDoubleSpinBox(InterpolationCB);
        SCThresholdNUD->setObjectName(QString::fromUtf8("SCThresholdNUD"));
        SCThresholdNUD->setEnabled(false);
        SCThresholdNUD->setGeometry(QRect(443, 155, 51, 24));
        SCThresholdNUD->setFocusPolicy(Qt::WheelFocus);
        SCThresholdNUD->setMaximum(1.000000000000000);
        SCThresholdNUD->setSingleStep(0.010000000000000);
        SCThresholdNUD->setValue(0.120000000000000);
        SCThresholdLabel = new QLabel(InterpolationCB);
        SCThresholdLabel->setObjectName(QString::fromUtf8("SCThresholdLabel"));
        SCThresholdLabel->setGeometry(QRect(23, 158, 161, 16));
        VSTabs->addTab(InterpolationTab, QString());
        UpscalingTab = new QWidget();
        UpscalingTab->setObjectName(QString::fromUtf8("UpscalingTab"));
        UpscalingGB = new QGroupBox(UpscalingTab);
        UpscalingGB->setObjectName(QString::fromUtf8("UpscalingGB"));
        UpscalingGB->setGeometry(QRect(12, -2, 517, 221));
        UpscalingGB->setAlignment(Qt::AlignCenter);
        UpscalingGB->setCheckable(true);
        UpscalingGB->setChecked(false);
        GPUThreadUpscaleLabel = new QLabel(UpscalingGB);
        GPUThreadUpscaleLabel->setObjectName(QString::fromUtf8("GPUThreadUpscaleLabel"));
        GPUThreadUpscaleLabel->setGeometry(QRect(365, 63, 81, 20));
        ToolUpscaleDD = new QComboBox(UpscalingGB);
        ToolUpscaleDD->addItem(QString());
        ToolUpscaleDD->addItem(QString());
        ToolUpscaleDD->setObjectName(QString::fromUtf8("ToolUpscaleDD"));
        ToolUpscaleDD->setGeometry(QRect(360, 33, 141, 22));
        ToolUpscaleDD->setFocusPolicy(Qt::NoFocus);
        ToolUpscaleLabel = new QLabel(UpscalingGB);
        ToolUpscaleLabel->setObjectName(QString::fromUtf8("ToolUpscaleLabel"));
        ToolUpscaleLabel->setGeometry(QRect(23, 34, 49, 16));
        GPUThreadUpscaleDD = new QComboBox(UpscalingGB);
        GPUThreadUpscaleDD->addItem(QString());
        GPUThreadUpscaleDD->setObjectName(QString::fromUtf8("GPUThreadUpscaleDD"));
        GPUThreadUpscaleDD->setGeometry(QRect(450, 64, 51, 22));
        GPUThreadUpscaleDD->setFocusPolicy(Qt::NoFocus);
        GPUUpscaleDD = new QComboBox(UpscalingGB);
        GPUUpscaleDD->setObjectName(QString::fromUtf8("GPUUpscaleDD"));
        GPUUpscaleDD->setGeometry(QRect(104, 65, 191, 22));
        GPUUpscaleDD->setFocusPolicy(Qt::NoFocus);
        GPULabel = new QLabel(UpscalingGB);
        GPULabel->setObjectName(QString::fromUtf8("GPULabel"));
        GPULabel->setGeometry(QRect(23, 65, 81, 16));
        ModelUpscaleDD = new QComboBox(UpscalingGB);
        ModelUpscaleDD->addItem(QString());
        ModelUpscaleDD->addItem(QString());
        ModelUpscaleDD->addItem(QString());
        ModelUpscaleDD->addItem(QString());
        ModelUpscaleDD->setObjectName(QString::fromUtf8("ModelUpscaleDD"));
        ModelUpscaleDD->setGeometry(QRect(360, 95, 141, 22));
        ModelUpscaleDD->setFocusPolicy(Qt::NoFocus);
        ModelUpscaleLabel = new QLabel(UpscalingGB);
        ModelUpscaleLabel->setObjectName(QString::fromUtf8("ModelUpscaleLabel"));
        ModelUpscaleLabel->setGeometry(QRect(23, 96, 52, 16));
        NoiseReduc2xLabel = new QLabel(UpscalingGB);
        NoiseReduc2xLabel->setObjectName(QString::fromUtf8("NoiseReduc2xLabel"));
        NoiseReduc2xLabel->setGeometry(QRect(23, 127, 131, 16));
        NoiseReduc2xDD = new QComboBox(UpscalingGB);
        NoiseReduc2xDD->addItem(QString());
        NoiseReduc2xDD->addItem(QString());
        NoiseReduc2xDD->addItem(QString());
        NoiseReduc2xDD->addItem(QString());
        NoiseReduc2xDD->addItem(QString());
        NoiseReduc2xDD->setObjectName(QString::fromUtf8("NoiseReduc2xDD"));
        NoiseReduc2xDD->setGeometry(QRect(410, 126, 91, 22));
        NoiseReduc2xDD->setFocusPolicy(Qt::NoFocus);
        Precision2xLabel = new QLabel(UpscalingGB);
        Precision2xLabel->setObjectName(QString::fromUtf8("Precision2xLabel"));
        Precision2xLabel->setGeometry(QRect(23, 158, 58, 16));
        Precision2xDD = new QComboBox(UpscalingGB);
        Precision2xDD->addItem(QString());
        Precision2xDD->addItem(QString());
        Precision2xDD->setObjectName(QString::fromUtf8("Precision2xDD"));
        Precision2xDD->setGeometry(QRect(430, 156, 71, 22));
        Precision2xDD->setFocusPolicy(Qt::NoFocus);
        OutResolutionLabel = new QLabel(UpscalingGB);
        OutResolutionLabel->setObjectName(QString::fromUtf8("OutResolutionLabel"));
        OutResolutionLabel->setGeometry(QRect(23, 188, 111, 16));
        Width2xNUD = new QSpinBox(UpscalingGB);
        Width2xNUD->setObjectName(QString::fromUtf8("Width2xNUD"));
        Width2xNUD->setGeometry(QRect(172, 185, 61, 24));
        Width2xNUD->setFocusPolicy(Qt::WheelFocus);
        Width2xNUD->setMinimum(640);
        Width2xNUD->setMaximum(7680);
        Width2xNUD->setValue(1920);
        Eks2Label = new QLabel(UpscalingGB);
        Eks2Label->setObjectName(QString::fromUtf8("Eks2Label"));
        Eks2Label->setGeometry(QRect(239, 189, 19, 16));
        Height2xNUD = new QSpinBox(UpscalingGB);
        Height2xNUD->setObjectName(QString::fromUtf8("Height2xNUD"));
        Height2xNUD->setGeometry(QRect(253, 185, 59, 24));
        Height2xNUD->setFocusPolicy(Qt::WheelFocus);
        Height2xNUD->setMinimum(360);
        Height2xNUD->setMaximum(4320);
        Height2xNUD->setValue(1080);
        AutoAdjDD = new QComboBox(UpscalingGB);
        AutoAdjDD->addItem(QString());
        AutoAdjDD->addItem(QString());
        AutoAdjDD->setObjectName(QString::fromUtf8("AutoAdjDD"));
        AutoAdjDD->setGeometry(QRect(416, 186, 85, 22));
        AutoAdjDD->setFocusPolicy(Qt::NoFocus);
        AutoAdjCB = new QCheckBox(UpscalingGB);
        AutoAdjCB->setObjectName(QString::fromUtf8("AutoAdjCB"));
        AutoAdjCB->setGeometry(QRect(324, 185, 91, 20));
        AutoAdjCB->setFocusPolicy(Qt::NoFocus);
        AutoAdjCB->setChecked(true);
        TTA2xLabel = new QLabel(UpscalingGB);
        TTA2xLabel->setObjectName(QString::fromUtf8("TTA2xLabel"));
        TTA2xLabel->setGeometry(QRect(23, 158, 181, 16));
        TTA2xCB = new QCheckBox(UpscalingGB);
        TTA2xCB->setObjectName(QString::fromUtf8("TTA2xCB"));
        TTA2xCB->setGeometry(QRect(478, 155, 19, 20));
        NoiseLabelSDDD = new QComboBox(UpscalingGB);
        NoiseLabelSDDD->addItem(QString());
        NoiseLabelSDDD->addItem(QString());
        NoiseLabelSDDD->addItem(QString());
        NoiseLabelSDDD->addItem(QString());
        NoiseLabelSDDD->addItem(QString());
        NoiseLabelSDDD->addItem(QString());
        NoiseLabelSDDD->addItem(QString());
        NoiseLabelSDDD->addItem(QString());
        NoiseLabelSDDD->addItem(QString());
        NoiseLabelSDDD->addItem(QString());
        NoiseLabelSDDD->addItem(QString());
        NoiseLabelSDDD->setObjectName(QString::fromUtf8("NoiseLabelSDDD"));
        NoiseLabelSDDD->setGeometry(QRect(440, 126, 61, 22));
        NoiseLabelSDDD->setFocusPolicy(Qt::NoFocus);
        VSTabs->addTab(UpscalingTab, QString());
        VSColorsTab = new QWidget();
        VSColorsTab->setObjectName(QString::fromUtf8("VSColorsTab"));
        ColorPropsGB = new QGroupBox(VSColorsTab);
        ColorPropsGB->setObjectName(QString::fromUtf8("ColorPropsGB"));
        ColorPropsGB->setGeometry(QRect(12, -2, 517, 121));
        ColorPropsGB->setAlignment(Qt::AlignCenter);
        ColorPropsGB->setCheckable(true);
        ColorPropsGB->setChecked(false);
        InputColorsLabel = new QLabel(ColorPropsGB);
        InputColorsLabel->setObjectName(QString::fromUtf8("InputColorsLabel"));
        InputColorsLabel->setGeometry(QRect(15, 39, 181, 16));
        OutputColorsLabel = new QLabel(ColorPropsGB);
        OutputColorsLabel->setObjectName(QString::fromUtf8("OutputColorsLabel"));
        OutputColorsLabel->setGeometry(QRect(15, 81, 191, 16));
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
        InputMatrixDD->setGeometry(QRect(200, 38, 101, 22));
        InputMatrixDD->setFocusPolicy(Qt::NoFocus);
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
        InputTransferDD->setGeometry(QRect(304, 38, 101, 22));
        InputTransferDD->setFocusPolicy(Qt::NoFocus);
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
        InputPrimsDD->setGeometry(QRect(407, 38, 101, 22));
        InputPrimsDD->setFocusPolicy(Qt::NoFocus);
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
        OutputMatrixDD->setGeometry(QRect(200, 80, 101, 22));
        OutputMatrixDD->setFocusPolicy(Qt::NoFocus);
        Slash2Label = new QLabel(ColorPropsGB);
        Slash2Label->setObjectName(QString::fromUtf8("Slash2Label"));
        Slash2Label->setGeometry(QRect(300, 39, 16, 16));
        Slash3Label = new QLabel(ColorPropsGB);
        Slash3Label->setObjectName(QString::fromUtf8("Slash3Label"));
        Slash3Label->setGeometry(QRect(403, 39, 16, 16));
        Slash4Label = new QLabel(ColorPropsGB);
        Slash4Label->setObjectName(QString::fromUtf8("Slash4Label"));
        Slash4Label->setGeometry(QRect(300, 81, 16, 16));
        Slash5Label = new QLabel(ColorPropsGB);
        Slash5Label->setObjectName(QString::fromUtf8("Slash5Label"));
        Slash5Label->setGeometry(QRect(403, 81, 16, 16));
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
        OutputTransferDD->setGeometry(QRect(304, 80, 101, 22));
        OutputTransferDD->setFocusPolicy(Qt::NoFocus);
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
        OutputPrimsDD->setGeometry(QRect(407, 80, 101, 22));
        OutputPrimsDD->setFocusPolicy(Qt::NoFocus);
        VSTabs->addTab(VSColorsTab, QString());
        LineTab = new QWidget();
        LineTab->setObjectName(QString::fromUtf8("LineTab"));
        AntiAliasingGB = new QGroupBox(LineTab);
        AntiAliasingGB->setObjectName(QString::fromUtf8("AntiAliasingGB"));
        AntiAliasingGB->setGeometry(QRect(12, -2, 517, 71));
        AntiAliasingGB->setAlignment(Qt::AlignCenter);
        AntiAliasingGB->setCheckable(false);
        AntiAliasingGB->setChecked(false);
        UseAALabel = new QLabel(AntiAliasingGB);
        UseAALabel->setObjectName(QString::fromUtf8("UseAALabel"));
        UseAALabel->setGeometry(QRect(19, 33, 131, 21));
        UseAACB = new QCheckBox(AntiAliasingGB);
        UseAACB->setObjectName(QString::fromUtf8("UseAACB"));
        UseAACB->setGeometry(QRect(480, 34, 17, 20));
        UseAACB->setFocusPolicy(Qt::NoFocus);
        VSTabs->addTab(LineTab, QString());
        VideoTabs->addTab(VSTab, QString());
        FiltersTab = new QWidget();
        FiltersTab->setObjectName(QString::fromUtf8("FiltersTab"));
        FiltersTabs = new QTabWidget(FiltersTab);
        FiltersTabs->setObjectName(QString::fromUtf8("FiltersTabs"));
        FiltersTabs->setGeometry(QRect(3, 2, 547, 257));
        ResizeTab = new QWidget();
        ResizeTab->setObjectName(QString::fromUtf8("ResizeTab"));
        ResizeGB = new QGroupBox(ResizeTab);
        ResizeGB->setObjectName(QString::fromUtf8("ResizeGB"));
        ResizeGB->setGeometry(QRect(12, -2, 298, 123));
        ResizeGB->setAlignment(Qt::AlignCenter);
        ResizeGB->setCheckable(true);
        ResizeGB->setChecked(false);
        ResolutionResLabel = new QLabel(ResizeGB);
        ResolutionResLabel->setObjectName(QString::fromUtf8("ResolutionResLabel"));
        ResolutionResLabel->setGeometry(QRect(18, 32, 111, 16));
        Eks3Label = new QLabel(ResizeGB);
        Eks3Label->setObjectName(QString::fromUtf8("Eks3Label"));
        Eks3Label->setGeometry(QRect(208, 33, 19, 16));
        WidthNUD = new QSpinBox(ResizeGB);
        WidthNUD->setObjectName(QString::fromUtf8("WidthNUD"));
        WidthNUD->setGeometry(QRect(142, 29, 61, 24));
        WidthNUD->setFocusPolicy(Qt::WheelFocus);
        WidthNUD->setMinimum(640);
        WidthNUD->setMaximum(7680);
        WidthNUD->setValue(1920);
        HeightNUD = new QSpinBox(ResizeGB);
        HeightNUD->setObjectName(QString::fromUtf8("HeightNUD"));
        HeightNUD->setGeometry(QRect(221, 29, 61, 24));
        HeightNUD->setFocusPolicy(Qt::WheelFocus);
        HeightNUD->setMinimum(360);
        HeightNUD->setMaximum(4320);
        HeightNUD->setValue(1080);
        AutoAdjResDD = new QComboBox(ResizeGB);
        AutoAdjResDD->addItem(QString());
        AutoAdjResDD->addItem(QString());
        AutoAdjResDD->setObjectName(QString::fromUtf8("AutoAdjResDD"));
        AutoAdjResDD->setGeometry(QRect(197, 60, 91, 22));
        AutoAdjResDD->setFocusPolicy(Qt::NoFocus);
        AutoAdjResCB = new QCheckBox(ResizeGB);
        AutoAdjResCB->setObjectName(QString::fromUtf8("AutoAdjResCB"));
        AutoAdjResCB->setGeometry(QRect(16, 57, 101, 22));
        AutoAdjResCB->setFocusPolicy(Qt::NoFocus);
        AutoAdjResCB->setChecked(true);
        ResizeAlgoCB = new QCheckBox(ResizeGB);
        ResizeAlgoCB->setObjectName(QString::fromUtf8("ResizeAlgoCB"));
        ResizeAlgoCB->setGeometry(QRect(16, 89, 52, 20));
        ResizeAlgoCB->setFocusPolicy(Qt::NoFocus);
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
        ResizeAlgoDD->setGeometry(QRect(177, 90, 111, 22));
        ResizeAlgoDD->setFocusPolicy(Qt::NoFocus);
        RotateGB = new QGroupBox(ResizeTab);
        RotateGB->setObjectName(QString::fromUtf8("RotateGB"));
        RotateGB->setGeometry(QRect(323, -2, 206, 123));
        RotateGB->setAlignment(Qt::AlignCenter);
        RotateGB->setCheckable(true);
        RotateGB->setChecked(false);
        AngleLabel = new QLabel(RotateGB);
        AngleLabel->setObjectName(QString::fromUtf8("AngleLabel"));
        AngleLabel->setGeometry(QRect(18, 30, 47, 20));
        AngleDD = new QComboBox(RotateGB);
        AngleDD->addItem(QString());
        AngleDD->addItem(QString());
        AngleDD->addItem(QString());
        AngleDD->addItem(QString());
        AngleDD->setObjectName(QString::fromUtf8("AngleDD"));
        AngleDD->setGeometry(QRect(125, 30, 71, 22));
        AngleDD->setFocusPolicy(Qt::NoFocus);
        FlipCB = new QCheckBox(RotateGB);
        FlipCB->setObjectName(QString::fromUtf8("FlipCB"));
        FlipCB->setGeometry(QRect(16, 58, 47, 23));
        FlipCB->setFocusPolicy(Qt::NoFocus);
        FlipDD = new QComboBox(RotateGB);
        FlipDD->addItem(QString());
        FlipDD->addItem(QString());
        FlipDD->setObjectName(QString::fromUtf8("FlipDD"));
        FlipDD->setGeometry(QRect(79, 60, 117, 22));
        FlipDD->setFocusPolicy(Qt::NoFocus);
        NoAutoRotateLabel = new QLabel(RotateGB);
        NoAutoRotateLabel->setObjectName(QString::fromUtf8("NoAutoRotateLabel"));
        NoAutoRotateLabel->setGeometry(QRect(18, 90, 91, 20));
        NoAutoRotateCB = new QCheckBox(RotateGB);
        NoAutoRotateCB->setObjectName(QString::fromUtf8("NoAutoRotateCB"));
        NoAutoRotateCB->setGeometry(QRect(173, 91, 21, 20));
        NoAutoRotateCB->setFocusPolicy(Qt::NoFocus);
        NoAutoRotateCB->setChecked(true);
        CropGB = new QGroupBox(ResizeTab);
        CropGB->setObjectName(QString::fromUtf8("CropGB"));
        CropGB->setGeometry(QRect(12, 125, 518, 94));
        CropGB->setAlignment(Qt::AlignCenter);
        CropGB->setCheckable(true);
        CropGB->setChecked(false);
        OutSizeLabel = new QLabel(CropGB);
        OutSizeLabel->setObjectName(QString::fromUtf8("OutSizeLabel"));
        OutSizeLabel->setGeometry(QRect(18, 30, 131, 16));
        Eks4Label = new QLabel(CropGB);
        Eks4Label->setObjectName(QString::fromUtf8("Eks4Label"));
        Eks4Label->setGeometry(QRect(428, 31, 19, 16));
        OutWidthNUD = new QSpinBox(CropGB);
        OutWidthNUD->setObjectName(QString::fromUtf8("OutWidthNUD"));
        OutWidthNUD->setGeometry(QRect(361, 27, 61, 24));
        OutWidthNUD->setFocusPolicy(Qt::WheelFocus);
        OutWidthNUD->setMinimum(640);
        OutWidthNUD->setMaximum(7680);
        OutWidthNUD->setValue(1920);
        OutHeightNUD = new QSpinBox(CropGB);
        OutHeightNUD->setObjectName(QString::fromUtf8("OutHeightNUD"));
        OutHeightNUD->setGeometry(QRect(440, 27, 61, 24));
        OutHeightNUD->setFocusPolicy(Qt::WheelFocus);
        OutHeightNUD->setMinimum(360);
        OutHeightNUD->setMaximum(4320);
        OutHeightNUD->setValue(1080);
        LocationLabel = new QLabel(CropGB);
        LocationLabel->setObjectName(QString::fromUtf8("LocationLabel"));
        LocationLabel->setGeometry(QRect(19, 63, 101, 16));
        EksNUD = new QSpinBox(CropGB);
        EksNUD->setObjectName(QString::fromUtf8("EksNUD"));
        EksNUD->setGeometry(QRect(361, 60, 61, 24));
        EksNUD->setFocusPolicy(Qt::WheelFocus);
        EksNUD->setMinimum(0);
        EksNUD->setMaximum(7680);
        EksNUD->setValue(0);
        WhyNUD = new QSpinBox(CropGB);
        WhyNUD->setObjectName(QString::fromUtf8("WhyNUD"));
        WhyNUD->setGeometry(QRect(440, 60, 61, 24));
        WhyNUD->setFocusPolicy(Qt::WheelFocus);
        WhyNUD->setMinimum(0);
        WhyNUD->setMaximum(4320);
        WhyNUD->setValue(0);
        Slash4Label_2 = new QLabel(CropGB);
        Slash4Label_2->setObjectName(QString::fromUtf8("Slash4Label_2"));
        Slash4Label_2->setGeometry(QRect(431, 61, 20, 20));
        FiltersTabs->addTab(ResizeTab, QString());
        ColorsTab = new QWidget();
        ColorsTab->setObjectName(QString::fromUtf8("ColorsTab"));
        SharpenGB = new QGroupBox(ColorsTab);
        SharpenGB->setObjectName(QString::fromUtf8("SharpenGB"));
        SharpenGB->setGeometry(QRect(12, -2, 517, 101));
        SharpenGB->setAlignment(Qt::AlignCenter);
        SharpenGB->setCheckable(true);
        SharpenGB->setChecked(false);
        RadiusLabel = new QLabel(SharpenGB);
        RadiusLabel->setObjectName(QString::fromUtf8("RadiusLabel"));
        RadiusLabel->setGeometry(QRect(18, 30, 47, 21));
        RadiusDD = new QComboBox(SharpenGB);
        RadiusDD->addItem(QString());
        RadiusDD->addItem(QString());
        RadiusDD->addItem(QString());
        RadiusDD->setObjectName(QString::fromUtf8("RadiusDD"));
        RadiusDD->setGeometry(QRect(385, 32, 121, 22));
        StrengthLabel = new QLabel(SharpenGB);
        StrengthLabel->setObjectName(QString::fromUtf8("StrengthLabel"));
        StrengthLabel->setGeometry(QRect(18, 68, 61, 16));
        StrengthDD = new QComboBox(SharpenGB);
        StrengthDD->addItem(QString());
        StrengthDD->addItem(QString());
        StrengthDD->addItem(QString());
        StrengthDD->addItem(QString());
        StrengthDD->addItem(QString());
        StrengthDD->setObjectName(QString::fromUtf8("StrengthDD"));
        StrengthDD->setGeometry(QRect(385, 67, 121, 22));
        FiltersTabs->addTab(ColorsTab, QString());
        MiscFFTab = new QWidget();
        MiscFFTab->setObjectName(QString::fromUtf8("MiscFFTab"));
        DeinterlaceGB = new QGroupBox(MiscFFTab);
        DeinterlaceGB->setObjectName(QString::fromUtf8("DeinterlaceGB"));
        DeinterlaceGB->setGeometry(QRect(12, -2, 517, 71));
        DeinterlaceGB->setAlignment(Qt::AlignCenter);
        DeinterlaceGB->setCheckable(false);
        DeinterlaceGB->setChecked(false);
        EnableDeintLabel = new QLabel(DeinterlaceGB);
        EnableDeintLabel->setObjectName(QString::fromUtf8("EnableDeintLabel"));
        EnableDeintLabel->setGeometry(QRect(19, 33, 131, 21));
        UseDeintCB = new QCheckBox(DeinterlaceGB);
        UseDeintCB->setObjectName(QString::fromUtf8("UseDeintCB"));
        UseDeintCB->setGeometry(QRect(480, 34, 17, 20));
        UseDeintCB->setFocusPolicy(Qt::NoFocus);
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
        AudioSelectorGB->setGeometry(QRect(15, -2, 261, 97));
        AudioSelectorGB->setAlignment(Qt::AlignCenter);
        SelectedAudioLabel = new QLabel(AudioSelectorGB);
        SelectedAudioLabel->setObjectName(QString::fromUtf8("SelectedAudioLabel"));
        SelectedAudioLabel->setGeometry(QRect(14, 64, 101, 16));
        SelectedAudioDD = new QComboBox(AudioSelectorGB);
        SelectedAudioDD->setObjectName(QString::fromUtf8("SelectedAudioDD"));
        SelectedAudioDD->setGeometry(QRect(133, 64, 121, 22));
        SelectedAudioDD->setFocusPolicy(Qt::NoFocus);
        AudioSourceLabel = new QLabel(AudioSelectorGB);
        AudioSourceLabel->setObjectName(QString::fromUtf8("AudioSourceLabel"));
        AudioSourceLabel->setGeometry(QRect(14, 32, 51, 16));
        SelectBttn = new QPushButton(AudioSelectorGB);
        SelectBttn->setObjectName(QString::fromUtf8("SelectBttn"));
        SelectBttn->setGeometry(QRect(192, 26, 56, 32));
        SelectBttn->setFocusPolicy(Qt::NoFocus);
        AudioSourceTxtBox = new QLineEdit(AudioSelectorGB);
        AudioSourceTxtBox->setObjectName(QString::fromUtf8("AudioSourceTxtBox"));
        AudioSourceTxtBox->setGeometry(QRect(68, 31, 119, 21));
        AudioSourceTxtBox->setReadOnly(true);
        EncodingAudioGB = new QGroupBox(AudioTab);
        EncodingAudioGB->setObjectName(QString::fromUtf8("EncodingAudioGB"));
        EncodingAudioGB->setGeometry(QRect(15, 160, 261, 119));
        EncodingAudioGB->setAlignment(Qt::AlignCenter);
        EncodingAudioGB->setCheckable(true);
        EncodingAudioGB->setChecked(false);
        EncoderAudioLabel = new QLabel(EncodingAudioGB);
        EncoderAudioLabel->setObjectName(QString::fromUtf8("EncoderAudioLabel"));
        EncoderAudioLabel->setGeometry(QRect(14, 24, 58, 29));
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
        AudioEncoderDD->setGeometry(QRect(163, 30, 91, 22));
        AudioEncoderDD->setFocusPolicy(Qt::NoFocus);
        RealAudioBitrateLabel = new QLabel(EncodingAudioGB);
        RealAudioBitrateLabel->setObjectName(QString::fromUtf8("RealAudioBitrateLabel"));
        RealAudioBitrateLabel->setGeometry(QRect(14, 56, 101, 20));
        AudioBitrateNUD = new QSpinBox(EncodingAudioGB);
        AudioBitrateNUD->setObjectName(QString::fromUtf8("AudioBitrateNUD"));
        AudioBitrateNUD->setGeometry(QRect(187, 56, 60, 24));
        AudioBitrateNUD->setFocusPolicy(Qt::WheelFocus);
        AudioBitrateNUD->setMinimum(32);
        AudioBitrateNUD->setMaximum(1562);
        AudioBitrateNUD->setValue(160);
        DownmixCB = new QCheckBox(EncodingAudioGB);
        DownmixCB->setObjectName(QString::fromUtf8("DownmixCB"));
        DownmixCB->setGeometry(QRect(12, 82, 91, 26));
        DownmixDD = new QComboBox(EncodingAudioGB);
        DownmixDD->addItem(QString());
        DownmixDD->addItem(QString());
        DownmixDD->addItem(QString());
        DownmixDD->setObjectName(QString::fromUtf8("DownmixDD"));
        DownmixDD->setGeometry(QRect(163, 87, 91, 22));
        DownmixDD->setFocusPolicy(Qt::NoFocus);
        AudioQualityLabel = new QLabel(EncodingAudioGB);
        AudioQualityLabel->setObjectName(QString::fromUtf8("AudioQualityLabel"));
        AudioQualityLabel->setGeometry(QRect(14, 58, 49, 16));
        AudioQualityNUD = new QSpinBox(EncodingAudioGB);
        AudioQualityNUD->setObjectName(QString::fromUtf8("AudioQualityNUD"));
        AudioQualityNUD->setGeometry(QRect(206, 56, 41, 24));
        AudioQualityNUD->setFocusPolicy(Qt::WheelFocus);
        AudioQualityNUD->setValue(6);
        AddAudioJobBttn = new QPushButton(AudioTab);
        AddAudioJobBttn->setObjectName(QString::fromUtf8("AddAudioJobBttn"));
        AddAudioJobBttn->setGeometry(QRect(289, 255, 258, 32));
        AddAudioJobBttn->setFocusPolicy(Qt::NoFocus);
        AudioQueueLabel = new QLabel(AudioTab);
        AudioQueueLabel->setObjectName(QString::fromUtf8("AudioQueueLabel"));
        AudioQueueLabel->setGeometry(QRect(370, 5, 101, 25));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        AudioQueueLabel->setFont(font1);
        AudioTitleCB = new QCheckBox(AudioTab);
        AudioTitleCB->setObjectName(QString::fromUtf8("AudioTitleCB"));
        AudioTitleCB->setGeometry(QRect(13, 102, 50, 27));
        AudioTitleCB->setFocusPolicy(Qt::NoFocus);
        AudioTitleTxtBox = new QLineEdit(AudioTab);
        AudioTitleTxtBox->setObjectName(QString::fromUtf8("AudioTitleTxtBox"));
        AudioTitleTxtBox->setGeometry(QRect(73, 106, 204, 21));
        LangAudioCB = new QCheckBox(AudioTab);
        LangAudioCB->setObjectName(QString::fromUtf8("LangAudioCB"));
        LangAudioCB->setGeometry(QRect(13, 134, 91, 21));
        LangAudioCB->setFocusPolicy(Qt::NoFocus);
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
        LangAudioDD->setGeometry(QRect(130, 136, 153, 22));
        LangAudioDD->setFocusPolicy(Qt::NoFocus);
        Tabs->addTab(AudioTab, QString());
        SubtitlesTab = new QWidget();
        SubtitlesTab->setObjectName(QString::fromUtf8("SubtitlesTab"));
        SubtitleTitleCB = new QCheckBox(SubtitlesTab);
        SubtitleTitleCB->setObjectName(QString::fromUtf8("SubtitleTitleCB"));
        SubtitleTitleCB->setGeometry(QRect(13, 154, 50, 27));
        SubtitleTitleCB->setFocusPolicy(Qt::NoFocus);
        SubtitleQueueLabel = new QLabel(SubtitlesTab);
        SubtitleQueueLabel->setObjectName(QString::fromUtf8("SubtitleQueueLabel"));
        SubtitleQueueLabel->setGeometry(QRect(365, 5, 125, 25));
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
        SubtitleLangDD->setGeometry(QRect(125, 189, 157, 22));
        SubtitleLangDD->setFocusPolicy(Qt::NoFocus);
        SubtitleTitleTxtBox = new QLineEdit(SubtitlesTab);
        SubtitleTitleTxtBox->setObjectName(QString::fromUtf8("SubtitleTitleTxtBox"));
        SubtitleTitleTxtBox->setGeometry(QRect(73, 158, 203, 21));
        SubtitleLangCB = new QCheckBox(SubtitlesTab);
        SubtitleLangCB->setObjectName(QString::fromUtf8("SubtitleLangCB"));
        SubtitleLangCB->setGeometry(QRect(13, 188, 91, 21));
        SubtitleLangCB->setFocusPolicy(Qt::NoFocus);
        SubtitleSelectorGB = new QGroupBox(SubtitlesTab);
        SubtitleSelectorGB->setObjectName(QString::fromUtf8("SubtitleSelectorGB"));
        SubtitleSelectorGB->setGeometry(QRect(15, 17, 261, 130));
        SubtitleSelectorGB->setAlignment(Qt::AlignCenter);
        SelectedSubtitleLabel = new QLabel(SubtitleSelectorGB);
        SelectedSubtitleLabel->setObjectName(QString::fromUtf8("SelectedSubtitleLabel"));
        SelectedSubtitleLabel->setGeometry(QRect(14, 64, 121, 16));
        SelectedSubtitleDD = new QComboBox(SubtitleSelectorGB);
        SelectedSubtitleDD->setObjectName(QString::fromUtf8("SelectedSubtitleDD"));
        SelectedSubtitleDD->setGeometry(QRect(142, 64, 111, 22));
        SelectedSubtitleDD->setFocusPolicy(Qt::NoFocus);
        SubtitleSourceLabel = new QLabel(SubtitleSelectorGB);
        SubtitleSourceLabel->setObjectName(QString::fromUtf8("SubtitleSourceLabel"));
        SubtitleSourceLabel->setGeometry(QRect(14, 32, 51, 16));
        SubSelectBttn = new QPushButton(SubtitleSelectorGB);
        SubSelectBttn->setObjectName(QString::fromUtf8("SubSelectBttn"));
        SubSelectBttn->setGeometry(QRect(192, 27, 56, 32));
        SubSelectBttn->setFocusPolicy(Qt::NoFocus);
        SubSourceTxtBox = new QLineEdit(SubtitleSelectorGB);
        SubSourceTxtBox->setObjectName(QString::fromUtf8("SubSourceTxtBox"));
        SubSourceTxtBox->setGeometry(QRect(66, 32, 122, 21));
        SubSourceTxtBox->setReadOnly(true);
        SubtitleInfoBttn = new QPushButton(SubtitleSelectorGB);
        SubtitleInfoBttn->setObjectName(QString::fromUtf8("SubtitleInfoBttn"));
        SubtitleInfoBttn->setGeometry(QRect(13, 91, 234, 32));
        SubtitleInfoBttn->setFocusPolicy(Qt::NoFocus);
        SubtitleEncodingGB = new QGroupBox(SubtitlesTab);
        SubtitleEncodingGB->setObjectName(QString::fromUtf8("SubtitleEncodingGB"));
        SubtitleEncodingGB->setGeometry(QRect(15, 213, 261, 66));
        SubtitleEncodingGB->setAlignment(Qt::AlignCenter);
        SubtitleEncodingGB->setCheckable(true);
        SubtitleEncodingGB->setChecked(false);
        SubtitleEncoderLabel = new QLabel(SubtitleEncodingGB);
        SubtitleEncoderLabel->setObjectName(QString::fromUtf8("SubtitleEncoderLabel"));
        SubtitleEncoderLabel->setGeometry(QRect(14, 26, 58, 29));
        SubtitleEncoderDD = new QComboBox(SubtitleEncodingGB);
        SubtitleEncoderDD->addItem(QString());
        SubtitleEncoderDD->addItem(QString());
        SubtitleEncoderDD->addItem(QString());
        SubtitleEncoderDD->addItem(QString());
        SubtitleEncoderDD->setObjectName(QString::fromUtf8("SubtitleEncoderDD"));
        SubtitleEncoderDD->setGeometry(QRect(161, 32, 92, 22));
        SubtitleEncoderDD->setFocusPolicy(Qt::NoFocus);
        AddSubtitleJobBttn = new QPushButton(SubtitlesTab);
        AddSubtitleJobBttn->setObjectName(QString::fromUtf8("AddSubtitleJobBttn"));
        AddSubtitleJobBttn->setGeometry(QRect(289, 255, 258, 32));
        AddSubtitleJobBttn->setFocusPolicy(Qt::NoFocus);
        Tabs->addTab(SubtitlesTab, QString());
        PrefTab = new QWidget();
        PrefTab->setObjectName(QString::fromUtf8("PrefTab"));
        EGUISettingsGB = new QGroupBox(PrefTab);
        EGUISettingsGB->setObjectName(QString::fromUtf8("EGUISettingsGB"));
        EGUISettingsGB->setGeometry(QRect(17, -2, 530, 195));
        EGUISettingsGB->setAlignment(Qt::AlignCenter);
        EnablePreviewCB = new QCheckBox(EGUISettingsGB);
        EnablePreviewCB->setObjectName(QString::fromUtf8("EnablePreviewCB"));
        EnablePreviewCB->setEnabled(true);
        EnablePreviewCB->setGeometry(QRect(490, 30, 22, 20));
        EnablePreviewCB->setFocusPolicy(Qt::NoFocus);
        EnablePreviewCB->setChecked(false);
        AutoDelSourceCB = new QCheckBox(EGUISettingsGB);
        AutoDelSourceCB->setObjectName(QString::fromUtf8("AutoDelSourceCB"));
        AutoDelSourceCB->setGeometry(QRect(490, 55, 28, 20));
        AutoDelSourceCB->setFocusPolicy(Qt::NoFocus);
        ErrorMessageCB = new QCheckBox(EGUISettingsGB);
        ErrorMessageCB->setObjectName(QString::fromUtf8("ErrorMessageCB"));
        ErrorMessageCB->setGeometry(QRect(490, 79, 24, 24));
        ErrorMessageCB->setFocusPolicy(Qt::NoFocus);
        ErrorMessageCB->setChecked(true);
        ErrorMessageLabel = new QLabel(EGUISettingsGB);
        ErrorMessageLabel->setObjectName(QString::fromUtf8("ErrorMessageLabel"));
        ErrorMessageLabel->setGeometry(QRect(25, 79, 221, 20));
        DeleteSourcesLabel = new QLabel(EGUISettingsGB);
        DeleteSourcesLabel->setObjectName(QString::fromUtf8("DeleteSourcesLabel"));
        DeleteSourcesLabel->setGeometry(QRect(25, 55, 291, 16));
        EnablePreviewLabel = new QLabel(EGUISettingsGB);
        EnablePreviewLabel->setObjectName(QString::fromUtf8("EnablePreviewLabel"));
        EnablePreviewLabel->setGeometry(QRect(25, 30, 381, 16));
        UpdateOptLabel = new QLabel(EGUISettingsGB);
        UpdateOptLabel->setObjectName(QString::fromUtf8("UpdateOptLabel"));
        UpdateOptLabel->setGeometry(QRect(25, 107, 271, 18));
        UpdateOptCB = new QCheckBox(EGUISettingsGB);
        UpdateOptCB->setObjectName(QString::fromUtf8("UpdateOptCB"));
        UpdateOptCB->setGeometry(QRect(490, 107, 20, 20));
        UpdateOptCB->setFocusPolicy(Qt::NoFocus);
        UpdateOptCB->setChecked(true);
        GenerateOutLabel = new QLabel(EGUISettingsGB);
        GenerateOutLabel->setObjectName(QString::fromUtf8("GenerateOutLabel"));
        GenerateOutLabel->setGeometry(QRect(25, 134, 249, 16));
        GenerateOutCB = new QCheckBox(EGUISettingsGB);
        GenerateOutCB->setObjectName(QString::fromUtf8("GenerateOutCB"));
        GenerateOutCB->setGeometry(QRect(490, 134, 21, 20));
        GenerateOutCB->setFocusPolicy(Qt::NoFocus);
        NotificationLabel = new QLabel(EGUISettingsGB);
        NotificationLabel->setObjectName(QString::fromUtf8("NotificationLabel"));
        NotificationLabel->setGeometry(QRect(25, 161, 321, 16));
        NotificationCB = new QCheckBox(EGUISettingsGB);
        NotificationCB->setObjectName(QString::fromUtf8("NotificationCB"));
        NotificationCB->setGeometry(QRect(490, 160, 21, 20));
        NotificationCB->setFocusPolicy(Qt::NoFocus);
        NotificationCB->setChecked(true);
        ProgressBarGB = new QGroupBox(PrefTab);
        ProgressBarGB->setObjectName(QString::fromUtf8("ProgressBarGB"));
        ProgressBarGB->setGeometry(QRect(17, 195, 530, 71));
        ProgressBarGB->setAlignment(Qt::AlignCenter);
        JobsCB = new QCheckBox(ProgressBarGB);
        JobsCB->setObjectName(QString::fromUtf8("JobsCB"));
        JobsCB->setGeometry(QRect(23, 34, 52, 20));
        JobsCB->setFocusPolicy(Qt::NoFocus);
        JobsCB->setChecked(true);
        FPSCB = new QCheckBox(ProgressBarGB);
        FPSCB->setObjectName(QString::fromUtf8("FPSCB"));
        FPSCB->setGeometry(QRect(88, 34, 47, 20));
        FPSCB->setFocusPolicy(Qt::NoFocus);
        FPSCB->setChecked(true);
        BitrateCB = new QCheckBox(ProgressBarGB);
        BitrateCB->setObjectName(QString::fromUtf8("BitrateCB"));
        BitrateCB->setGeometry(QRect(148, 34, 70, 20));
        BitrateCB->setFocusPolicy(Qt::NoFocus);
        BitrateCB->setChecked(true);
        TimeLeftCB = new QCheckBox(ProgressBarGB);
        TimeLeftCB->setObjectName(QString::fromUtf8("TimeLeftCB"));
        TimeLeftCB->setGeometry(QRect(222, 34, 81, 20));
        TimeLeftCB->setFocusPolicy(Qt::NoFocus);
        TimeLeftCB->setChecked(true);
        TimeElapsedCB = new QCheckBox(ProgressBarGB);
        TimeElapsedCB->setObjectName(QString::fromUtf8("TimeElapsedCB"));
        TimeElapsedCB->setGeometry(QRect(307, 34, 101, 20));
        TimeElapsedCB->setFocusPolicy(Qt::NoFocus);
        TimeElapsedCB->setChecked(true);
        PercentageCB = new QCheckBox(ProgressBarGB);
        PercentageCB->setObjectName(QString::fromUtf8("PercentageCB"));
        PercentageCB->setGeometry(QRect(418, 34, 91, 20));
        PercentageCB->setFocusPolicy(Qt::NoFocus);
        PercentageCB->setChecked(true);
        Tabs->addTab(PrefTab, QString());
        JobTab = new QWidget();
        JobTab->setObjectName(QString::fromUtf8("JobTab"));
        JobQueue = new QTableWidget(JobTab);
        if (JobQueue->columnCount() < 6)
            JobQueue->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        JobQueue->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        JobQueue->setObjectName(QString::fromUtf8("JobQueue"));
        JobQueue->setGeometry(QRect(4, 37, 557, 252));
        sizePolicy.setHeightForWidth(JobQueue->sizePolicy().hasHeightForWidth());
        JobQueue->setSizePolicy(sizePolicy);
        JobQueue->setFocusPolicy(Qt::StrongFocus);
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
        JobQueueLabel->setGeometry(QRect(6, 4, 83, 23));
        JobQueueLabel->setFont(font1);
        ClearJobsBttn = new QPushButton(JobTab);
        ClearJobsBttn->setObjectName(QString::fromUtf8("ClearJobsBttn"));
        ClearJobsBttn->setGeometry(QRect(397, 1, 165, 32));
        ClearJobsBttn->setFocusPolicy(Qt::NoFocus);
        CancelQueueBttn = new QPushButton(JobTab);
        CancelQueueBttn->setObjectName(QString::fromUtf8("CancelQueueBttn"));
        CancelQueueBttn->setGeometry(QRect(271, 1, 118, 32));
        CancelQueueBttn->setFocusPolicy(Qt::NoFocus);
        Tabs->addTab(JobTab, QString());
        LogsTab = new QWidget();
        LogsTab->setObjectName(QString::fromUtf8("LogsTab"));
        LogsOutGB = new QGroupBox(LogsTab);
        LogsOutGB->setObjectName(QString::fromUtf8("LogsOutGB"));
        LogsOutGB->setGeometry(QRect(14, -2, 536, 251));
        LogsOutGB->setAlignment(Qt::AlignCenter);
        LogsOutRTxtBox = new QTextEdit(LogsOutGB);
        LogsOutRTxtBox->setObjectName(QString::fromUtf8("LogsOutRTxtBox"));
        LogsOutRTxtBox->setGeometry(QRect(6, 24, 523, 221));
        LogsOutRTxtBox->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        LogsOutRTxtBox->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        LogsOutRTxtBox->setReadOnly(true);
        LogsDirBttn = new QPushButton(LogsTab);
        LogsDirBttn->setObjectName(QString::fromUtf8("LogsDirBttn"));
        LogsDirBttn->setGeometry(QRect(12, 257, 539, 32));
        LogsDirBttn->setFocusPolicy(Qt::NoFocus);
        Tabs->addTab(LogsTab, QString());
        AboutTab = new QWidget();
        AboutTab->setObjectName(QString::fromUtf8("AboutTab"));
        AboutGUIGB = new QGroupBox(AboutTab);
        AboutGUIGB->setObjectName(QString::fromUtf8("AboutGUIGB"));
        AboutGUIGB->setGeometry(QRect(14, -2, 537, 111));
        AboutGUIGB->setAlignment(Qt::AlignCenter);
        AboutGuiLabel = new QLabel(AboutGUIGB);
        AboutGuiLabel->setObjectName(QString::fromUtf8("AboutGuiLabel"));
        AboutGuiLabel->setGeometry(QRect(22, 30, 490, 68));
        AboutGuiLabel->setTextFormat(Qt::RichText);
        AboutGuiLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        AboutGuiLabel->setWordWrap(true);
        AboutGuiLabel->setOpenExternalLinks(true);
        DonateGB = new QGroupBox(AboutTab);
        DonateGB->setObjectName(QString::fromUtf8("DonateGB"));
        DonateGB->setGeometry(QRect(14, 114, 367, 101));
        DonateGB->setAlignment(Qt::AlignCenter);
        DonateToDaGooseLabel = new QLabel(DonateGB);
        DonateToDaGooseLabel->setObjectName(QString::fromUtf8("DonateToDaGooseLabel"));
        DonateToDaGooseLabel->setGeometry(QRect(24, 31, 221, 16));
        DonateToGlitchLabel = new QLabel(DonateGB);
        DonateToGlitchLabel->setObjectName(QString::fromUtf8("DonateToGlitchLabel"));
        DonateToGlitchLabel->setGeometry(QRect(24, 67, 161, 16));
        DonateToDaGooseBttn = new QPushButton(DonateGB);
        DonateToDaGooseBttn->setObjectName(QString::fromUtf8("DonateToDaGooseBttn"));
        DonateToDaGooseBttn->setGeometry(QRect(262, 22, 81, 34));
        DonateToDaGooseBttn->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/EncodeGUI/pp_donate.png"), QSize(), QIcon::Normal, QIcon::Off);
        DonateToDaGooseBttn->setIcon(icon1);
        DonateToDaGooseBttn->setIconSize(QSize(70, 35));
        DonateToGlitchBttn = new QPushButton(DonateGB);
        DonateToGlitchBttn->setObjectName(QString::fromUtf8("DonateToGlitchBttn"));
        DonateToGlitchBttn->setGeometry(QRect(262, 58, 81, 34));
        DonateToGlitchBttn->setFocusPolicy(Qt::NoFocus);
        DonateToGlitchBttn->setIcon(icon1);
        DonateToGlitchBttn->setIconSize(QSize(70, 35));
        LinksGB = new QGroupBox(AboutTab);
        LinksGB->setObjectName(QString::fromUtf8("LinksGB"));
        LinksGB->setGeometry(QRect(402, 114, 148, 165));
        LinksGB->setAlignment(Qt::AlignCenter);
        YoutubeBttn = new QPushButton(LinksGB);
        YoutubeBttn->setObjectName(QString::fromUtf8("YoutubeBttn"));
        YoutubeBttn->setGeometry(QRect(23, 27, 103, 35));
        YoutubeBttn->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/EncodeGUI/yt_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        YoutubeBttn->setIcon(icon2);
        YoutubeBttn->setIconSize(QSize(90, 35));
        DiscordBttn = new QPushButton(LinksGB);
        DiscordBttn->setObjectName(QString::fromUtf8("DiscordBttn"));
        DiscordBttn->setGeometry(QRect(23, 73, 103, 35));
        DiscordBttn->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/EncodeGUI/discord_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        DiscordBttn->setIcon(icon3);
        DiscordBttn->setIconSize(QSize(90, 35));
        InstaBttn = new QPushButton(LinksGB);
        InstaBttn->setObjectName(QString::fromUtf8("InstaBttn"));
        InstaBttn->setGeometry(QRect(23, 119, 103, 35));
        InstaBttn->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/EncodeGUI/ig_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        InstaBttn->setIcon(icon4);
        InstaBttn->setIconSize(QSize(90, 35));
        ClearBttn = new QPushButton(AboutTab);
        ClearBttn->setObjectName(QString::fromUtf8("ClearBttn"));
        ClearBttn->setGeometry(QRect(12, 254, 261, 32));
        ClearBttn->setFocusPolicy(Qt::NoFocus);
        LicensesBttn = new QPushButton(AboutTab);
        LicensesBttn->setObjectName(QString::fromUtf8("LicensesBttn"));
        LicensesBttn->setGeometry(QRect(282, 254, 100, 32));
        LicensesBttn->setFocusPolicy(Qt::NoFocus);
        Tabs->addTab(AboutTab, QString());
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(7, 375, 756, 25));
        progressBar->setFocusPolicy(Qt::NoFocus);
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        VideoInfoGB = new QGroupBox(centralWidget);
        VideoInfoGB->setObjectName(QString::fromUtf8("VideoInfoGB"));
        VideoInfoGB->setGeometry(QRect(584, 4, 180, 193));
        VideoInfoGB->setFocusPolicy(Qt::NoFocus);
        VideoInfoGB->setAlignment(Qt::AlignCenter);
        EncoderLabel = new QLabel(VideoInfoGB);
        EncoderLabel->setObjectName(QString::fromUtf8("EncoderLabel"));
        EncoderLabel->setGeometry(QRect(16, 25, 49, 16));
        EncoderLabel->setFocusPolicy(Qt::NoFocus);
        DurationLabel = new QLabel(VideoInfoGB);
        DurationLabel->setObjectName(QString::fromUtf8("DurationLabel"));
        DurationLabel->setGeometry(QRect(16, 40, 62, 20));
        DurationLabel->setFocusPolicy(Qt::NoFocus);
        ResolutionLabel = new QLabel(VideoInfoGB);
        ResolutionLabel->setObjectName(QString::fromUtf8("ResolutionLabel"));
        ResolutionLabel->setGeometry(QRect(16, 58, 71, 20));
        ResolutionLabel->setFocusPolicy(Qt::NoFocus);
        VidBitrateLabel = new QLabel(VideoInfoGB);
        VidBitrateLabel->setObjectName(QString::fromUtf8("VidBitrateLabel"));
        VidBitrateLabel->setGeometry(QRect(16, 78, 49, 16));
        VidBitrateLabel->setFocusPolicy(Qt::NoFocus);
        ColorsLabel = new QLabel(VideoInfoGB);
        ColorsLabel->setObjectName(QString::fromUtf8("ColorsLabel"));
        ColorsLabel->setGeometry(QRect(16, 96, 43, 16));
        ColorsLabel->setFocusPolicy(Qt::NoFocus);
        FPSLabel = new QLabel(VideoInfoGB);
        FPSLabel->setObjectName(QString::fromUtf8("FPSLabel"));
        FPSLabel->setGeometry(QRect(16, 168, 67, 16));
        FPSLabel->setFocusPolicy(Qt::NoFocus);
        MatrixLabel = new QLabel(VideoInfoGB);
        MatrixLabel->setObjectName(QString::fromUtf8("MatrixLabel"));
        MatrixLabel->setGeometry(QRect(16, 114, 75, 16));
        MatrixLabel->setFocusPolicy(Qt::NoFocus);
        TransferLabel = new QLabel(VideoInfoGB);
        TransferLabel->setObjectName(QString::fromUtf8("TransferLabel"));
        TransferLabel->setGeometry(QRect(16, 132, 49, 16));
        TransferLabel->setFocusPolicy(Qt::NoFocus);
        VidformatValueLabel = new QLabel(VideoInfoGB);
        VidformatValueLabel->setObjectName(QString::fromUtf8("VidformatValueLabel"));
        VidformatValueLabel->setGeometry(QRect(73, 26, 92, 16));
        VidformatValueLabel->setFont(font);
        VidformatValueLabel->setFocusPolicy(Qt::NoFocus);
        VidformatValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ResolutionValueLabel = new QLabel(VideoInfoGB);
        ResolutionValueLabel->setObjectName(QString::fromUtf8("ResolutionValueLabel"));
        ResolutionValueLabel->setGeometry(QRect(85, 60, 80, 16));
        ResolutionValueLabel->setFont(font);
        ResolutionValueLabel->setFocusPolicy(Qt::NoFocus);
        ResolutionValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        BitrateValueLabel = new QLabel(VideoInfoGB);
        BitrateValueLabel->setObjectName(QString::fromUtf8("BitrateValueLabel"));
        BitrateValueLabel->setGeometry(QRect(63, 78, 102, 16));
        BitrateValueLabel->setFont(font);
        BitrateValueLabel->setFocusPolicy(Qt::NoFocus);
        BitrateValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ColorsValueLabel = new QLabel(VideoInfoGB);
        ColorsValueLabel->setObjectName(QString::fromUtf8("ColorsValueLabel"));
        ColorsValueLabel->setGeometry(QRect(61, 91, 104, 25));
        ColorsValueLabel->setFont(font);
        ColorsValueLabel->setFocusPolicy(Qt::NoFocus);
        ColorsValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FPSValueLabel = new QLabel(VideoInfoGB);
        FPSValueLabel->setObjectName(QString::fromUtf8("FPSValueLabel"));
        FPSValueLabel->setGeometry(QRect(86, 168, 79, 16));
        FPSValueLabel->setFont(font);
        FPSValueLabel->setFocusPolicy(Qt::NoFocus);
        FPSValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        DurationValueLabel = new QLabel(VideoInfoGB);
        DurationValueLabel->setObjectName(QString::fromUtf8("DurationValueLabel"));
        DurationValueLabel->setGeometry(QRect(75, 43, 90, 16));
        DurationValueLabel->setFont(font);
        DurationValueLabel->setFocusPolicy(Qt::NoFocus);
        DurationValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MatrixValueLabel = new QLabel(VideoInfoGB);
        MatrixValueLabel->setObjectName(QString::fromUtf8("MatrixValueLabel"));
        MatrixValueLabel->setGeometry(QRect(63, 114, 102, 16));
        MatrixValueLabel->setFont(font);
        MatrixValueLabel->setFocusPolicy(Qt::NoFocus);
        MatrixValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TransferValueLabel = new QLabel(VideoInfoGB);
        TransferValueLabel->setObjectName(QString::fromUtf8("TransferValueLabel"));
        TransferValueLabel->setGeometry(QRect(73, 132, 92, 16));
        TransferValueLabel->setFont(font);
        TransferValueLabel->setFocusPolicy(Qt::NoFocus);
        TransferValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        PrimariesLabel = new QLabel(VideoInfoGB);
        PrimariesLabel->setObjectName(QString::fromUtf8("PrimariesLabel"));
        PrimariesLabel->setGeometry(QRect(16, 150, 55, 16));
        PrimariesLabel->setFocusPolicy(Qt::NoFocus);
        PrimariesValueLabel = new QLabel(VideoInfoGB);
        PrimariesValueLabel->setObjectName(QString::fromUtf8("PrimariesValueLabel"));
        PrimariesValueLabel->setGeometry(QRect(80, 150, 85, 16));
        PrimariesValueLabel->setFont(font);
        PrimariesValueLabel->setFocusPolicy(Qt::NoFocus);
        PrimariesValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SaveOutTxtBox = new QLineEdit(centralWidget);
        SaveOutTxtBox->setObjectName(QString::fromUtf8("SaveOutTxtBox"));
        SaveOutTxtBox->setEnabled(true);
        SaveOutTxtBox->setGeometry(QRect(7, 336, 363, 23));
        SaveOutTxtBox->setFocusPolicy(Qt::NoFocus);
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
        OutContainerx264DD->setGeometry(QRect(371, 337, 82, 23));
        OutContainerx264DD->setFocusPolicy(Qt::NoFocus);
        SaveOutBttn = new QPushButton(centralWidget);
        SaveOutBttn->setObjectName(QString::fromUtf8("SaveOutBttn"));
        SaveOutBttn->setGeometry(QRect(453, 332, 94, 32));
        SaveOutBttn->setFocusPolicy(Qt::NoFocus);
        PreviewBttn = new QPushButton(centralWidget);
        PreviewBttn->setObjectName(QString::fromUtf8("PreviewBttn"));
        PreviewBttn->setGeometry(QRect(553, 332, 68, 32));
        PreviewBttn->setFocusPolicy(Qt::NoFocus);
        AddJobBttn = new QPushButton(centralWidget);
        AddJobBttn->setObjectName(QString::fromUtf8("AddJobBttn"));
        AddJobBttn->setGeometry(QRect(627, 332, 70, 32));
        AddJobBttn->setFocusPolicy(Qt::NoFocus);
        StartBttn = new QPushButton(centralWidget);
        StartBttn->setObjectName(QString::fromUtf8("StartBttn"));
        StartBttn->setGeometry(QRect(703, 332, 61, 32));
        StartBttn->setFont(font);
        StartBttn->setFocusPolicy(Qt::NoFocus);
        AudioInfoGB = new QGroupBox(centralWidget);
        AudioInfoGB->setObjectName(QString::fromUtf8("AudioInfoGB"));
        AudioInfoGB->setGeometry(QRect(584, 198, 180, 130));
        AudioInfoGB->setFocusPolicy(Qt::NoFocus);
        AudioInfoGB->setAlignment(Qt::AlignCenter);
        SampleRateLabel = new QLabel(AudioInfoGB);
        SampleRateLabel->setObjectName(QString::fromUtf8("SampleRateLabel"));
        SampleRateLabel->setGeometry(QRect(16, 88, 81, 16));
        SampleRateLabel->setFocusPolicy(Qt::NoFocus);
        AudioLanguageLabel = new QLabel(AudioInfoGB);
        AudioLanguageLabel->setObjectName(QString::fromUtf8("AudioLanguageLabel"));
        AudioLanguageLabel->setGeometry(QRect(16, 69, 71, 16));
        AudioLanguageLabel->setFocusPolicy(Qt::NoFocus);
        SampleRateValueLabel = new QLabel(AudioInfoGB);
        SampleRateValueLabel->setObjectName(QString::fromUtf8("SampleRateValueLabel"));
        SampleRateValueLabel->setGeometry(QRect(86, 88, 79, 16));
        SampleRateValueLabel->setFont(font);
        SampleRateValueLabel->setFocusPolicy(Qt::NoFocus);
        SampleRateValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        TrackLabel = new QLabel(AudioInfoGB);
        TrackLabel->setObjectName(QString::fromUtf8("TrackLabel"));
        TrackLabel->setGeometry(QRect(16, 27, 75, 16));
        TrackLabel->setFocusPolicy(Qt::NoFocus);
        AudioLanguageValueLabel = new QLabel(AudioInfoGB);
        AudioLanguageValueLabel->setObjectName(QString::fromUtf8("AudioLanguageValueLabel"));
        AudioLanguageValueLabel->setGeometry(QRect(80, 69, 85, 16));
        AudioLanguageValueLabel->setFont(font);
        AudioLanguageValueLabel->setFocusPolicy(Qt::NoFocus);
        AudioLanguageValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FormatLabel = new QLabel(AudioInfoGB);
        FormatLabel->setObjectName(QString::fromUtf8("FormatLabel"));
        FormatLabel->setGeometry(QRect(16, 51, 49, 16));
        FormatLabel->setFocusPolicy(Qt::NoFocus);
        ChannelsLabel = new QLabel(AudioInfoGB);
        ChannelsLabel->setObjectName(QString::fromUtf8("ChannelsLabel"));
        ChannelsLabel->setGeometry(QRect(16, 105, 61, 16));
        ChannelsLabel->setFocusPolicy(Qt::NoFocus);
        ChannelsValueLabel = new QLabel(AudioInfoGB);
        ChannelsValueLabel->setObjectName(QString::fromUtf8("ChannelsValueLabel"));
        ChannelsValueLabel->setGeometry(QRect(53, 105, 112, 16));
        ChannelsValueLabel->setFont(font);
        ChannelsValueLabel->setFocusPolicy(Qt::NoFocus);
        ChannelsValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        FormatValueLabel = new QLabel(AudioInfoGB);
        FormatValueLabel->setObjectName(QString::fromUtf8("FormatValueLabel"));
        FormatValueLabel->setGeometry(QRect(73, 51, 92, 16));
        FormatValueLabel->setFont(font);
        FormatValueLabel->setFocusPolicy(Qt::NoFocus);
        FormatValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        AudioTrackDD = new QComboBox(AudioInfoGB);
        AudioTrackDD->setObjectName(QString::fromUtf8("AudioTrackDD"));
        AudioTrackDD->setEnabled(false);
        AudioTrackDD->setGeometry(QRect(118, 27, 55, 21));
        AudioTrackDD->setFocusPolicy(Qt::NoFocus);
        ProgressBarLabel = new QLabel(centralWidget);
        ProgressBarLabel->setObjectName(QString::fromUtf8("ProgressBarLabel"));
        ProgressBarLabel->setGeometry(QRect(9, 362, 751, 22));
        ProgressBarLabel->setFont(font);
        ProgressBarLabel->setFocusPolicy(Qt::NoFocus);
        ProgressBarLabel->setAlignment(Qt::AlignCenter);
        OutContainerx265DD = new QComboBox(centralWidget);
        OutContainerx265DD->addItem(QString());
        OutContainerx265DD->addItem(QString());
        OutContainerx265DD->addItem(QString());
        OutContainerx265DD->addItem(QString());
        OutContainerx265DD->setObjectName(QString::fromUtf8("OutContainerx265DD"));
        OutContainerx265DD->setGeometry(QRect(371, 337, 82, 23));
        OutContainerx265DD->setFocusPolicy(Qt::NoFocus);
        OutContainerProResDD = new QComboBox(centralWidget);
        OutContainerProResDD->addItem(QString());
        OutContainerProResDD->addItem(QString());
        OutContainerProResDD->addItem(QString());
        OutContainerProResDD->setObjectName(QString::fromUtf8("OutContainerProResDD"));
        OutContainerProResDD->setGeometry(QRect(371, 337, 82, 23));
        OutContainerProResDD->setFocusPolicy(Qt::NoFocus);
        OutContainerTheoraDD = new QComboBox(centralWidget);
        OutContainerTheoraDD->addItem(QString());
        OutContainerTheoraDD->addItem(QString());
        OutContainerTheoraDD->addItem(QString());
        OutContainerTheoraDD->setObjectName(QString::fromUtf8("OutContainerTheoraDD"));
        OutContainerTheoraDD->setGeometry(QRect(371, 337, 82, 23));
        OutContainerTheoraDD->setFocusPolicy(Qt::NoFocus);
        OutContainerVPXDD = new QComboBox(centralWidget);
        OutContainerVPXDD->addItem(QString());
        OutContainerVPXDD->addItem(QString());
        OutContainerVPXDD->addItem(QString());
        OutContainerVPXDD->addItem(QString());
        OutContainerVPXDD->addItem(QString());
        OutContainerVPXDD->setObjectName(QString::fromUtf8("OutContainerVPXDD"));
        OutContainerVPXDD->setGeometry(QRect(371, 337, 82, 23));
        OutContainerVPXDD->setFocusPolicy(Qt::NoFocus);
        OutContainerAV1DD = new QComboBox(centralWidget);
        OutContainerAV1DD->addItem(QString());
        OutContainerAV1DD->addItem(QString());
        OutContainerAV1DD->addItem(QString());
        OutContainerAV1DD->addItem(QString());
        OutContainerAV1DD->addItem(QString());
        OutContainerAV1DD->setObjectName(QString::fromUtf8("OutContainerAV1DD"));
        OutContainerAV1DD->setGeometry(QRect(371, 337, 82, 23));
        OutContainerAV1DD->setFocusPolicy(Qt::NoFocus);
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
        OutContainerMuxDD->setGeometry(QRect(371, 337, 82, 23));
        OutContainerMuxDD->setFocusPolicy(Qt::NoFocus);
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
        QWidget::setTabOrder(EncodeMode265DD, Bitrate265NUD);
        QWidget::setTabOrder(Bitrate265NUD, Tune265CB);
        QWidget::setTabOrder(Tune265CB, Tune265DD);
        QWidget::setTabOrder(Tune265DD, Preset265CB);
        QWidget::setTabOrder(Preset265CB, Preset265DD);
        QWidget::setTabOrder(Preset265DD, Quantizer265NUD);
        QWidget::setTabOrder(Quantizer265NUD, CRFValue265NUD);
        QWidget::setTabOrder(CRFValue265NUD, RefFrames265GB);
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
        QWidget::setTabOrder(GPUThreadDD, SceneChangeCB);
        QWidget::setTabOrder(SceneChangeCB, OutputFPSNUD);
        QWidget::setTabOrder(OutputFPSNUD, BackendDD);
        QWidget::setTabOrder(BackendDD, RIFEModelVKDD);
        QWidget::setTabOrder(RIFEModelVKDD, UpscalingGB);
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
        QWidget::setTabOrder(TTA2xCB, NoiseLabelSDDD);
        QWidget::setTabOrder(NoiseLabelSDDD, ColorPropsGB);
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
        QWidget::setTabOrder(AudioTitleTxtBox, ClearJobsBttn);
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
        QWidget::setTabOrder(BitDepth264DD, VideoTabs);
        QWidget::setTabOrder(VideoTabs, Profile264GB);
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
        GPUThreadDD->setCurrentIndex(0);
        ToolUpscaleDD->setCurrentIndex(0);
        GPUThreadUpscaleDD->setCurrentIndex(0);
        NoiseReduc2xDD->setCurrentIndex(2);
        AutoAdjDD->setCurrentIndex(1);
        NoiseLabelSDDD->setCurrentIndex(3);
        FiltersTabs->setCurrentIndex(0);
        AutoAdjResDD->setCurrentIndex(1);
        StartBttn->setDefault(false);


        QMetaObject::connectSlotsByName(EncodeGUIMV);
    } // setupUi

    void retranslateUi(QMainWindow *EncodeGUIMV)
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
        WhenEncCompleteLabel->setText(QCoreApplication::translate("EncodeGUIMV", "When all jobs finish:", nullptr));
        WhenEncCompleteDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Do nothing", nullptr));
        WhenEncCompleteDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "Close app", nullptr));
        WhenEncCompleteDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "Sleep", nullptr));
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
        Bitrate265Label->setText(QCoreApplication::translate("EncodeGUIMV", "Bitrate:", nullptr));
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
        ToolInterpDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "RIFE", nullptr));

#if QT_CONFIG(tooltip)
        ToolInterpDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>The tool to use for interpolation. </p><p>Recommended: EncodeGUI AI</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ToolInterpDD->setCurrentText(QCoreApplication::translate("EncodeGUIMV", "RIFE", nullptr));
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

#if QT_CONFIG(tooltip)
        GPUThreadDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the number of GPU threads for NCNN interpolation.", nullptr));
#endif // QT_CONFIG(tooltip)
        ModelInterpLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Model:", nullptr));
#if QT_CONFIG(tooltip)
        SceneChangeCB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables scene change detection to reduce interpolation artefacts.", nullptr));
#endif // QT_CONFIG(tooltip)
        SceneChangeCB->setText(QString());
#if QT_CONFIG(tooltip)
        OutputFPSNUD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The output FPS.", nullptr));
#endif // QT_CONFIG(tooltip)
        OutFPSLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Output FPS:", nullptr));
        SceneChangeLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Use scene change detection:", nullptr));
        BackendDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "MoltenVK (NCNN)", nullptr));

#if QT_CONFIG(tooltip)
        BackendDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p>Sets the graphics processing backend to use for the specified interpolation tool.</p><p>Recommended: CUDA</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        SlashLabel->setText(QCoreApplication::translate("EncodeGUIMV", "/", nullptr));
        RIFEModelVKDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "v1.8", nullptr));
        RIFEModelVKDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "v2.3", nullptr));
        RIFEModelVKDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "v2.4", nullptr));
        RIFEModelVKDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "v3.1", nullptr));
        RIFEModelVKDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "v4.0", nullptr));
        RIFEModelVKDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "v4.6", nullptr));

#if QT_CONFIG(tooltip)
        RIFEModelVKDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the RIFE model to use for NCNN.", nullptr));
#endif // QT_CONFIG(tooltip)
        Times2Label->setText(QCoreApplication::translate("EncodeGUIMV", "x2 =", nullptr));
        SCThresholdLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Scene change threshold:", nullptr));
        VSTabs->setTabText(VSTabs->indexOf(InterpolationTab), QCoreApplication::translate("EncodeGUIMV", "Interpolation", nullptr));
#if QT_CONFIG(tooltip)
        UpscalingGB->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Enables/disables resolution upscaling.", nullptr));
#endif // QT_CONFIG(tooltip)
        UpscalingGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Resolution Upscaling", nullptr));
        GPUThreadUpscaleLabel->setText(QCoreApplication::translate("EncodeGUIMV", "GPU threads:", nullptr));
        ToolUpscaleDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "Waifu2x (NCNN)", nullptr));
        ToolUpscaleDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "SRMD (NCNN)", nullptr));

#if QT_CONFIG(tooltip)
        ToolUpscaleDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "The upscaling tool to use.", nullptr));
#endif // QT_CONFIG(tooltip)
        ToolUpscaleDD->setCurrentText(QCoreApplication::translate("EncodeGUIMV", "Waifu2x (NCNN)", nullptr));
        ToolUpscaleLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Tool:", nullptr));
        GPUThreadUpscaleDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "1", nullptr));

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
        NoiseLabelSDDD->setItemText(0, QCoreApplication::translate("EncodeGUIMV", "0", nullptr));
        NoiseLabelSDDD->setItemText(1, QCoreApplication::translate("EncodeGUIMV", "1", nullptr));
        NoiseLabelSDDD->setItemText(2, QCoreApplication::translate("EncodeGUIMV", "2", nullptr));
        NoiseLabelSDDD->setItemText(3, QCoreApplication::translate("EncodeGUIMV", "3", nullptr));
        NoiseLabelSDDD->setItemText(4, QCoreApplication::translate("EncodeGUIMV", "4", nullptr));
        NoiseLabelSDDD->setItemText(5, QCoreApplication::translate("EncodeGUIMV", "5", nullptr));
        NoiseLabelSDDD->setItemText(6, QCoreApplication::translate("EncodeGUIMV", "6", nullptr));
        NoiseLabelSDDD->setItemText(7, QCoreApplication::translate("EncodeGUIMV", "7", nullptr));
        NoiseLabelSDDD->setItemText(8, QCoreApplication::translate("EncodeGUIMV", "8", nullptr));
        NoiseLabelSDDD->setItemText(9, QCoreApplication::translate("EncodeGUIMV", "9", nullptr));
        NoiseLabelSDDD->setItemText(10, QCoreApplication::translate("EncodeGUIMV", "10", nullptr));

#if QT_CONFIG(tooltip)
        NoiseLabelSDDD->setToolTip(QCoreApplication::translate("EncodeGUIMV", "Sets the noise reduction level for SRMD.", nullptr));
#endif // QT_CONFIG(tooltip)
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
        EnableDeintLabel->setText(QCoreApplication::translate("EncodeGUIMV", "Enable deinterlacing:", nullptr));
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
        Tabs->setTabText(Tabs->indexOf(PrefTab), QCoreApplication::translate("EncodeGUIMV", "Preferences", nullptr));
        QTableWidgetItem *___qtablewidgetitem = JobQueue->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("EncodeGUIMV", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = JobQueue->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("EncodeGUIMV", "Status", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = JobQueue->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("EncodeGUIMV", "Progress", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = JobQueue->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("EncodeGUIMV", "Input", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = JobQueue->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("EncodeGUIMV", "Output", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = JobQueue->horizontalHeaderItem(5);
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
        AboutGuiLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700;\">EncodeGUI (encode-gooey) is the latest and greatest video encoding application. It features 5 different video codecs to use and AI backed filters such as frame interpolation, resolution upscaling, and DeNoise for an unparalleled experience. Find out more at </span><a href=\"https://encodegui.com\"><span style=\" font-size:10pt; text-decoration: underline; color:#0000ff;\">https://encodegui.com</span></a></p></body></html>", nullptr));
        DonateGB->setTitle(QCoreApplication::translate("EncodeGUIMV", "Donate", nullptr));
        DonateToDaGooseLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700; color:#008000;\">Goose</span><span style=\" font-weight:700;\"> (owner &amp; dev. up to v1.2.3):</span></p></body></html>", nullptr));
        DonateToGlitchLabel->setText(QCoreApplication::translate("EncodeGUIMV", "<html><head/><body><p><span style=\" font-weight:700; color:#008000;\">Glitch</span><span style=\" font-weight:700;\"> (dev. after v1.2.3):</span></p></body></html>", nullptr));
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
    class EncodeGUIMV: public Ui_EncodeGUIMV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ENCODEGUIQUBDDF_H