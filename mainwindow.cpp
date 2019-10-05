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
    auto start = std::chrono::system_clock::now();
    hide();
    AdminPages *PagPrincipal = new AdminPages();
    PagPrincipal->setInfiniteScroll(false);
    PagPrincipal->prepareGUI();
    PagPrincipal->loadPages(0);
    PagPrincipal->loadMovies();
    PagPrincipal->show();
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<float,std::milli> duration =end - start;

    cout << "Duracion(Paginacion): " << duration.count() <<endl;

}


void MainWindow::on_InfiniteScroll_clicked()
{
    hide();
    AdminPages *PagPrincipal = new AdminPages();
    PagPrincipal->setInfiniteScroll(true);
    PagPrincipal->prepareGUI();
    PagPrincipal->loadPages(0);
    PagPrincipal->loadMovies();
    PagPrincipal->show();
}

void MainWindow::on_toolButton_clicked()
{
    auto start = std::chrono::system_clock::now();
    hide();
    AdminPages *PagPrincipal = new AdminPages();
    PagPrincipal->setInfiniteScroll(false);
    PagPrincipal->setCompleteDataset(true);
    PagPrincipal->prepareGUI();
    PagPrincipal->loadPages(6);
    PagPrincipal->loadMovies();
    PagPrincipal->show();
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<float,std::milli> duration =end - start;

    cout << "Duracion(Cargar todo el dataset): " << duration.count() <<endl;
}
