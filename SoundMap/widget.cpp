#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    button->setGeometry(100, 100, 100, 100);
    QObject::connect(button, SIGNAL(clicked()),this, SLOT(Start_record()));
    button->show();
}


Widget::~Widget()
{
    delete ui;
}

void Widget::Start_record()
{
QFile MyFile;

MyFile.setFileName("/sound/test.raw");
MyFile.open( QIODevice::WriteOnly | QIODevice::Truncate);

QAudioFormat format;
format.setSampleRate(8000);
    format.setChannelCount(1);
    format.setSampleSize(8);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
        if (!info.isFormatSupported(format)) {
            qWarning() << "Default format not supported, trying to use the nearest.";
            format = info.nearestFormat(format);
        }



        audio = new QAudioInput(format, this);
            connect(audio, SIGNAL(stateChanged(QAudio::State)), this, SLOT(handleStateChanged(QAudio::State)));

            QTimer::singleShot(3000, this, SLOT(stopRecording()));
            audio->start(&MyFile);
            // Records audio for 3000ms
}

