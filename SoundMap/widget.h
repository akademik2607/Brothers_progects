#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QtMultimedia/QAudioInput>
#include <QFile>
#include <QTimer>
#include <QDebug>
#include <QtMultimedia/QAudioFormat>
#include <QIODevice>
#include <QtMultimedia/QAudioDeviceInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    QPushButton *button = new QPushButton(this);
    QAudioInput *audio;


private:
    Ui::Widget *ui;


 public slots:
   void Start_record();

};
#endif // WIDGET_H
