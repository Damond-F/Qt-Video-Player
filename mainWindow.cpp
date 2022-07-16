#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    VideoWidget = new QVideoWidget(this);

    player -> setVideoOutput(VideoWidget);
    this -> setCentralWidget(VideoWidget);

    QSlider* videoSlider;
    videoSlider = new QSlider(Qt::Horizontal);
    ui->toolBar->addWidget(videoSlider);

    ui->toolBar->QToolBar::addSeparator();

    connect(player, &QMediaPlayer::positionChanged, videoSlider, &QSlider::setValue);
    connect(player, &QMediaPlayer::durationChanged, videoSlider, &QSlider::setMaximum);
    connect(videoSlider, &QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

    ui->toolBar->QToolBar::addSeparator();
    ui->toolBar->QToolBar::addSeparator();

    //Volume Slider
    QSlider *volumeSlider;
    volumeSlider = new QSlider(Qt::Horizontal);

    ui->toolBar->addWidget(volumeSlider);
    videoSlider->QWidget::setMinimumWidth(500);


    connect(volumeSlider, &QSlider::valueChanged,player,&QMediaPlayer::setVolume);

    VideoWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionOpen_File_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select an mp4 file.", "C://", "(*.mp4)");

    if (fileName.isEmpty())
    {
        QMessageBox::information(this, "Warning", "No file was selected.", fileName);
    }
    else
    {
        player -> setMedia(QUrl::fromLocalFile(fileName));
        player -> play();
    }
}


void MainWindow::on_actionPlayButton_triggered()
{
    player -> play();
}


void MainWindow::on_actionPauseButton_triggered()
{
    player -> pause();
}


void MainWindow::on_actionVolume_triggered()
{
    if (player->isMuted())
    {
        player->setMuted(false);
    }
    else
    {
        player->setMuted(true);
    }
}


void MainWindow::on_actionFullscreen_triggered()
{
    if(isFullScreen())
    {
        showNormal();
    }
    else
    {
        showFullScreen();
    }
}


void MainWindow::on_action0_5x_2_triggered()
{
    player->setPlaybackRate(0.5);
}


void MainWindow::on_action1_0x_triggered()
{
    player->setPlaybackRate(1.0);
}


void MainWindow::on_action1_5x_2_triggered()
{
    player->setPlaybackRate(1.5);
}


void MainWindow::on_action2_0x_triggered()
{
    player->setPlaybackRate(2.0);
}

