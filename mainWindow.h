#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QProgressBar>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QSlider>
#include <QMediaObject>
#include <QToolButton>
#include <QWidget>
#include <QGridLayout>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_File_triggered();
    void on_actionPlayButton_triggered();
    void on_actionPauseButton_triggered();

    void on_actionVolume_triggered();

    void on_actionFullscreen_triggered();

    void on_action0_5x_2_triggered();

    void on_action1_0x_triggered();

    void on_action1_5x_2_triggered();

    void on_action2_0x_triggered();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QVideoWidget *VideoWidget;

};
#endif // MAINWINDOW_H
