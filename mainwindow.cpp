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
