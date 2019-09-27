#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AdminPages.h"
#include "ui_prueba.h"
#include <iostream>
#include <QThread>

using namespace std;

void MainWindow::slot_netwManagerFinished(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError){
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        return;
    }
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);    
    QIcon ButtonIcon(pixmap);
    ui->BotonPrueba->setIcon(ButtonIcon);
    ui->BotonPrueba->setIconSize(pixmap.rect().size());
    ui->BotonPrueba->setMinimumWidth(pixmap.rect().width());
    ui->BotonPrueba->setMinimumHeight(pixmap.rect().height());
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->centralwidget->setStyleSheet("QWidget { background-color: rgb(30, 33, 30); }");

    /*player = new QMediaPlayer(this);
    vw = new QWebEngineView(this);
    this->setCentralWidget(vw);

    vw->load(QUrl("https://www.imdb.com/video/imdb/vi1497349145/imdb/inline?ratio=1.77&rid=59N6RHKEJ2EMPFR9JFZA"));*/

    QNetworkAccessManager* m_netwManager = new QNetworkAccessManager(this);
    connect(m_netwManager, SIGNAL(finished(QNetworkReply*)),this, SLOT(slot_netwManagerFinished(QNetworkReply*)));

    QUrl url("https://m.media-amazon.com/images/M/MV5BYWQ3NGM0NzQtZTNhOC00MDZjLTkyZGItZjViZTEzZmFlNDhhXkEyXkFqcGdeQXVyMjQzMzQzODY@._V1_UY268_CR9,0,182,268_AL_.jpg");
    QNetworkRequest request(url);
    m_netwManager->get(request);
    QThread::msleep(500);
}



MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BotonPrueba_clicked()
{
    hide();
    AdminPages *PagPrincipal = new AdminPages();
    PagPrincipal->show();
}
