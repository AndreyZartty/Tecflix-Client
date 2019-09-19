#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    vw = new QWebEngineView(this);
    //player->setVideoOutput(vw);
    this->setCentralWidget(vw);

    vw->load(QUrl("https://www.imdb.com/video/imdb/vi1497349145/imdb/inline?ratio=1.77&rid=59N6RHKEJ2EMPFR9JFZA"));

    //player->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

