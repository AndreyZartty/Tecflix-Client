#include "AdminPages.h"
#include "ui_AdminPages.h"
#include <QThread>
#include <iostream>
#include "moviepreview.h"

using namespace std;

AdminPages::AdminPages(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminPages)
{
    ui->setupUi(this);

    loadPages(3);

    loadMovies();


    QThread::msleep(2000);

    if (PAnterior == nullptr){
        ui->PrevPag->hide();
    }


}

AdminPages::~AdminPages()
{
    delete ui;
}

void AdminPages::loadMovies()
{
    QNetworkAccessManager* m_netwManager1 = new QNetworkAccessManager(this);
    connect(m_netwManager1, SIGNAL(finished(QNetworkReply*)),this, SLOT(slot_netwManagerFinished1(QNetworkReply*)));

    QByteArray P1 = PActual->getPelicula1()->getPosterLink().toUtf8();
    QUrl url = QUrl::fromEncoded(P1,QUrl::StrictMode);
    QNetworkRequest request(url);
    m_netwManager1->get(request);

    QNetworkAccessManager* m_netwManager2 = new QNetworkAccessManager(this);
    connect(m_netwManager2, SIGNAL(finished(QNetworkReply*)),this, SLOT(slot_netwManagerFinished2(QNetworkReply*)));

    QByteArray P2 = PActual->getPelicula2()->getPosterLink().toUtf8();
    QUrl url2 = QUrl::fromEncoded(P2,QUrl::StrictMode);
    QNetworkRequest request2(url2);
    m_netwManager2->get(request2);

    QNetworkAccessManager* m_netwManager3 = new QNetworkAccessManager(this);
    connect(m_netwManager3, SIGNAL(finished(QNetworkReply*)),this, SLOT(slot_netwManagerFinished3(QNetworkReply*)));

    QByteArray P3 = PActual->getPelicula3()->getPosterLink().toUtf8();
    QUrl url3 = QUrl::fromEncoded(P3,QUrl::StrictMode);
    QNetworkRequest request3(url3);
    m_netwManager3->get(request3);

    QNetworkAccessManager* m_netwManager4 = new QNetworkAccessManager(this);
    connect(m_netwManager4, SIGNAL(finished(QNetworkReply*)),this, SLOT(slot_netwManagerFinished4(QNetworkReply*)));

    QByteArray P4 = PActual->getPelicula4()->getPosterLink().toUtf8();
    QUrl url4 = QUrl::fromEncoded(P4,QUrl::StrictMode);
    QNetworkRequest request4(url4);
    m_netwManager4->get(request4);

    QNetworkAccessManager* m_netwManager5 = new QNetworkAccessManager(this);
    connect(m_netwManager5, SIGNAL(finished(QNetworkReply*)),this, SLOT(slot_netwManagerFinished5(QNetworkReply*)));

    QByteArray P5 = PActual->getPelicula5()->getPosterLink().toUtf8();
    QUrl url5 = QUrl::fromEncoded(P5,QUrl::StrictMode);
    QNetworkRequest request5(url5);
    m_netwManager5->get(request5);

    QNetworkAccessManager* m_netwManager6 = new QNetworkAccessManager(this);
    connect(m_netwManager6, SIGNAL(finished(QNetworkReply*)),this, SLOT(slot_netwManagerFinished6(QNetworkReply*)));

    QByteArray P6 = PActual->getPelicula6()->getPosterLink().toUtf8();
    QUrl url6 = QUrl::fromEncoded(P6,QUrl::StrictMode);
    QNetworkRequest request6(url6);
    m_netwManager6->get(request6);

    QNetworkAccessManager* m_netwManager7 = new QNetworkAccessManager(this);
    connect(m_netwManager7, SIGNAL(finished(QNetworkReply*)),this, SLOT(slot_netwManagerFinished7(QNetworkReply*)));

    QByteArray P7 = PActual->getPelicula7()->getPosterLink().toUtf8();
    QUrl url7 = QUrl::fromEncoded(P7,QUrl::StrictMode);
    QNetworkRequest request7(url7);
    m_netwManager7->get(request7);

    QNetworkAccessManager* m_netwManager8 = new QNetworkAccessManager(this);
    connect(m_netwManager8, SIGNAL(finished(QNetworkReply*)),this, SLOT(slot_netwManagerFinished8(QNetworkReply*)));

    QByteArray P8 = PActual->getPelicula8()->getPosterLink().toUtf8();
    QUrl url8 = QUrl::fromEncoded(P8,QUrl::StrictMode);
    QNetworkRequest request8(url8);
    m_netwManager8->get(request8);
}

void AdminPages::loadPages(int mode)
{
    dataset.open("/home/andreyzartty/Documentos/Proyectos/TECflix/Tecflix-Client/movie_metadata.csv");
    string notAdd;
    getline(dataset,notAdd, '\n');
    if (lastMovie==0){
        Pagina *newCurrent = new Pagina();
        int c = 8;
        while (lastMovie < c){
            string newMovie;
            getline(dataset, newMovie, '\n');
            Movie *movieN = new Movie(newMovie);
            newCurrent->addMovie(movieN);
            lastMovie++;
        }
        c += 8;
        PActual = newCurrent;
        Pagina *newNext = new Pagina();
        while (lastMovie < c){
            string newMovie;
            getline(dataset, newMovie, '\n');
            Movie *movieN = new Movie(newMovie);
            newNext->addMovie(movieN);
            lastMovie++;
        }
        PSiguiente = newNext;
    }
    else if(mode == 1){  //MODO 1: SIGUIENTE
        PAnterior = PActual;
        PActual = PSiguiente;
        firstMovie += 8;
        int newLimit = lastMovie + 8;
        int c = 0;
        while (c < lastMovie){
            string newMovie;
            getline(dataset, newMovie, '\n');
            c++;
        }
        Pagina *newNext = new Pagina();
        while (lastMovie < newLimit){
            string newMovie;
            getline(dataset, newMovie, '\n');
            Movie *movieN = new Movie(newMovie);
            newNext->addMovie(movieN);
            lastMovie++;
        }
        PSiguiente = newNext;

    }
    else if(mode == 2){  //MODO 2: ANTERIOR
        if(firstMovie == 0){
            PSiguiente = PActual;
            PActual = PAnterior;
            PAnterior = nullptr;
            lastMovie -= 8;
            firstMovie -= 8;
        }
        else{
            PSiguiente = PActual;
            PActual = PAnterior;
            int c = 0;
            lastMovie -= 8;
            firstMovie -= 8;
            while (c < firstMovie){
                string newMovie;
                getline(dataset, newMovie, '\n');
                c++;
            }
            Pagina *newPrev = new Pagina();
            c = 0;
            while (c < 8){
                string newMovie;
                getline(dataset, newMovie, '\n');
                Movie *movieN = new Movie(newMovie);
                newPrev->addMovie(movieN);
                c++;
            }
            PAnterior = newPrev;
        }
    }
    dataset.close();
}

void AdminPages::slot_netwManagerFinished1(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError){
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        return;
    }
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    QIcon ButtonIcon(pixmap);
    ui->peli1->setIcon(ButtonIcon);
    ui->peli1->setIconSize(pixmap.rect().size());
    ui->peli1->setMinimumWidth(pixmap.rect().width());
    ui->peli1->setMinimumHeight(pixmap.rect().height());

}

void AdminPages::slot_netwManagerFinished2(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError){
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        return;
    }
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    QIcon ButtonIcon(pixmap);
    ui->peli2->setIcon(ButtonIcon);
    ui->peli2->setIconSize(pixmap.rect().size());
    ui->peli2->setMinimumWidth(pixmap.rect().width());
    ui->peli2->setMinimumHeight(pixmap.rect().height());
}

void AdminPages::slot_netwManagerFinished3(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError){
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        return;
    }
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    QIcon ButtonIcon(pixmap);
    ui->peli3->setIcon(ButtonIcon);
    ui->peli3->setIconSize(pixmap.rect().size());
    ui->peli3->setMinimumWidth(pixmap.rect().width());
    ui->peli3->setMinimumHeight(pixmap.rect().height());
}

void AdminPages::slot_netwManagerFinished4(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError){
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        return;
    }
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    QIcon ButtonIcon(pixmap);
    ui->peli4->setIcon(ButtonIcon);
    ui->peli4->setIconSize(pixmap.rect().size());
    ui->peli4->setMinimumWidth(pixmap.rect().width());
    ui->peli4->setMinimumHeight(pixmap.rect().height());
}

void AdminPages::slot_netwManagerFinished5(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError){
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        return;
    }
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    QIcon ButtonIcon(pixmap);
    ui->peli5->setIcon(ButtonIcon);
    ui->peli5->setIconSize(pixmap.rect().size());
    ui->peli5->setMinimumWidth(pixmap.rect().width());
    ui->peli5->setMinimumHeight(pixmap.rect().height());
}

void AdminPages::slot_netwManagerFinished6(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError){
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        return;
    }
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    QIcon ButtonIcon(pixmap);
    ui->peli6->setIcon(ButtonIcon);
    ui->peli6->setIconSize(pixmap.rect().size());
    ui->peli6->setMinimumWidth(pixmap.rect().width());
    ui->peli6->setMinimumHeight(pixmap.rect().height());
}

void AdminPages::slot_netwManagerFinished7(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError){
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        return;
    }
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    QIcon ButtonIcon(pixmap);
    ui->peli7->setIcon(ButtonIcon);
    ui->peli7->setIconSize(pixmap.rect().size());
    ui->peli7->setMinimumWidth(pixmap.rect().width());
    ui->peli7->setMinimumHeight(pixmap.rect().height());
}

void AdminPages::slot_netwManagerFinished8(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError){
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        return;
    }
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    QIcon ButtonIcon(pixmap);
    ui->peli8->setIcon(ButtonIcon);
    ui->peli8->setIconSize(pixmap.rect().size());
    ui->peli8->setMinimumWidth(pixmap.rect().width());
    ui->peli8->setMinimumHeight(pixmap.rect().height());
}



void AdminPages::on_peli1_clicked()
{
    MoviePreview eje;
    eje.setModal(true);
    eje.exec();
}

void AdminPages::on_peli2_clicked()
{
    cout << "lol xd 2" << endl;
}

void AdminPages::on_NextPag_clicked()
{
    loadPages(1);
    loadMovies();
    QThread::msleep(700);
    if (PAnterior == nullptr){
        ui->PrevPag->hide();
    }
    else{
        ui->PrevPag->show();
    }
}



void AdminPages::on_PrevPag_clicked()
{
    loadPages(2);
    loadMovies();
    QThread::msleep(700);
    if (PAnterior == nullptr){
        ui->PrevPag->hide();
    }
    else{
        ui->PrevPag->show();
    }
}
