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
    ui->centralwidget->setStyleSheet("QWidget { background-color: rgb(30, 33, 30); }");


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

    if(PagActual != 631){

        ui->peli4->show();
        ui->peli5->show();
        ui->peli6->show();
        ui->peli7->show();
        ui->peli8->show();


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
    else{
        ui->peli4->hide();
        ui->peli5->hide();
        ui->peli6->hide();
        ui->peli7->hide();
        ui->peli8->hide();
    }
}

void AdminPages::loadPages(int mode)
{
    dataset.open("/home/andreyzartty/Documentos/Proyectos/TECflix/Tecflix-Client/movie_metadata.csv");
    string notAdd;
    getline(dataset,notAdd, '\n');
    if (lastMovie==0){
        Pagina *newCurrent = new Pagina();
        int c = 8;
        for (int i = lastMovie; i < c; i++){
            string newMovie;
            getline(dataset, newMovie, '\n');
            Movie *movieN = new Movie(newMovie);
            newCurrent->addMovie(movieN);
            lastMovie++;
        }
        c += 8;
        PActual = newCurrent;
        Pagina *newNext = new Pagina();
        for (int i = lastMovie; i < c; i++){
            string newMovie;
            getline(dataset, newMovie, '\n');
            Movie *movieN = new Movie(newMovie);
            newNext->addMovie(movieN);
            lastMovie++;
        }
        PSiguiente = newNext;
        ui->Pagina->setText(QString::fromStdString("Página " + std::to_string(PagActual)));
    }
    else if(mode == 1){  //MODO 1: SIGUIENTE
        if (PagActual+1 == 630){
            PAnterior = PActual;
            PActual = PSiguiente;
            firstMovie += 8;
            int newLimit = lastMovie + 3;
            int c = 0;
            for(int i = 0; i < lastMovie; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                c++;
            }
            Pagina *newNext = new Pagina();
            for(int i = lastMovie; i < newLimit; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                Movie *movieN = new Movie(newMovie);
                newNext->addMovie(movieN);
                lastMovie++;
            }
            PSiguiente = newNext;
            PagActual++;
            ui->Pagina->setText(QString::fromStdString("Página " + std::to_string(PagActual)));
        }
        else if(PagActual+1 == 631){
            PAnterior = PActual;
            PActual = PSiguiente;
            PSiguiente = nullptr;
            firstMovie += 8;
            PagActual++;
            ui->Pagina->setText(QString::fromStdString("Página " + std::to_string(PagActual)));
        }
        else{
            PAnterior = PActual;
            PActual = PSiguiente;
            firstMovie += 8;
            int newLimit = lastMovie + 8;
            int c = 0;
            for(int i = 0; i < lastMovie; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                c++;
            }
            Pagina *newNext = new Pagina();
            for(int i = lastMovie; i < newLimit; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                Movie *movieN = new Movie(newMovie);
                newNext->addMovie(movieN);
                lastMovie++;
            }
            PSiguiente = newNext;
            PagActual++;
            ui->Pagina->setText(QString::fromStdString("Página " + std::to_string(PagActual)));
        }


    }
    else if(mode == 2){  //MODO 2: ANTERIOR
        if(PagActual-1 == 1){
            PSiguiente = PActual;
            PActual = PAnterior;
            PAnterior = nullptr;
            lastMovie -= 8;
            firstMovie -= 8;
            PagActual--;
            ui->Pagina->setText(QString::fromStdString("Página " + std::to_string(PagActual)));
        }
        else if(PagActual == 631){
            PSiguiente = PActual;
            PActual = PAnterior;
            int c = 0;
            firstMovie -= 8;
            for(int i= 0; i < firstMovie; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                c++;
            }
            Pagina *newPrev = new Pagina();
            for(int i = 0; i < 8; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                Movie *movieN = new Movie(newMovie);
                newPrev->addMovie(movieN);
            }
            PAnterior = newPrev;
            PagActual--;
            ui->Pagina->setText(QString::fromStdString("Página " + std::to_string(PagActual)));
        }
        else if(PagActual == 630){
            PSiguiente = PActual;
            PActual = PAnterior;
            int c = 0;
            lastMovie -= 3;
            firstMovie -= 8;
            for(int i= 0; i < firstMovie; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                c++;
            }
            Pagina *newPrev = new Pagina();
            for(int i = 0; i < 8; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                Movie *movieN = new Movie(newMovie);
                newPrev->addMovie(movieN);
            }
            PAnterior = newPrev;
            PagActual--;
            ui->Pagina->setText(QString::fromStdString("Página " + std::to_string(PagActual)));
        }
        else{
            PSiguiente = PActual;
            PActual = PAnterior;
            int c = 0;
            lastMovie -= 8;
            firstMovie -= 8;
            for(int i= 0; i < firstMovie; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                c++;
            }
            Pagina *newPrev = new Pagina();
            for(int i = 0; i < 8; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                Movie *movieN = new Movie(newMovie);
                newPrev->addMovie(movieN);
            }
            PAnterior = newPrev;
            PagActual--;
            ui->Pagina->setText(QString::fromStdString("Página " + std::to_string(PagActual)));
        }
    }
    else if(mode == 3){ ///MODO: SALTO
        int newPagNum = ui->SpinPag->value();
        PagActual = newPagNum;
        ui->SpinPag->setValue(1);


        if(PagActual == 1){
            firstMovie = ((newPagNum-1)*8) -8;
            lastMovie = ((newPagNum+1)*8);

            PAnterior = nullptr;

            Pagina *newPrev2 = new Pagina();
            for(int i= 0; i < 8; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                Movie *movieN = new Movie(newMovie);
                newPrev2->addMovie(movieN);
            }
            PActual = newPrev2;

            Pagina *newPrev3 = new Pagina();
            for(int i= 0; i < 8; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                Movie *movieN = new Movie(newMovie);
                newPrev3->addMovie(movieN);
            }
            PSiguiente = newPrev3;

            ui->Pagina->setText(QString::fromStdString("Página " + std::to_string(PagActual)));
        }
        else if(PagActual == 630){
            firstMovie = ((newPagNum-1)*8) -8;
            lastMovie = ((newPagNum*8)+3);
            for(int i= 0; i < firstMovie; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
            }
            Pagina *newPrev1 = new Pagina();
            for(int i= 0; i < 8; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                Movie *movieN = new Movie(newMovie);
                newPrev1->addMovie(movieN);
            }
            PAnterior = newPrev1;

            Pagina *newPrev2 = new Pagina();
            for(int i= 0; i < 8; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                Movie *movieN = new Movie(newMovie);
                newPrev2->addMovie(movieN);
            }
            PActual = newPrev2;

            Pagina *newPrev3 = new Pagina();
            for(int i= 0; i < 3; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                Movie *movieN = new Movie(newMovie);
                newPrev3->addMovie(movieN);
            }
            PSiguiente = newPrev3;

            ui->Pagina->setText(QString::fromStdString("Página " + std::to_string(PagActual)));
        }
        else if(PagActual == 631){
            firstMovie = ((newPagNum-1)*8) -8;
            lastMovie = ((newPagNum*8)-5);
            for(int i= 0; i < firstMovie; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
            }
            Pagina *newPrev1 = new Pagina();
            for(int i= 0; i < 8; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                Movie *movieN = new Movie(newMovie);
                newPrev1->addMovie(movieN);
            }
            PAnterior = newPrev1;

            Pagina *newPrev2 = new Pagina();
            for(int i= 0; i < 3; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                Movie *movieN = new Movie(newMovie);
                newPrev2->addMovie(movieN);
            }
            PActual = newPrev2;

            PSiguiente = nullptr;

            ui->Pagina->setText(QString::fromStdString("Página " + std::to_string(PagActual)));
        }
        else{
            firstMovie = ((newPagNum-1)*8) -8;
            lastMovie = ((newPagNum+1)*8);
            for(int i= 0; i < firstMovie; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
            }
            Pagina *newPrev1 = new Pagina();
            for(int i= 0; i < 8; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                Movie *movieN = new Movie(newMovie);
                newPrev1->addMovie(movieN);
            }
            PAnterior = newPrev1;

            Pagina *newPrev2 = new Pagina();
            for(int i= 0; i < 8; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                Movie *movieN = new Movie(newMovie);
                newPrev2->addMovie(movieN);
            }
            PActual = newPrev2;

            Pagina *newPrev3 = new Pagina();
            for(int i= 0; i < 8; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');
                Movie *movieN = new Movie(newMovie);
                newPrev3->addMovie(movieN);
            }
            PSiguiente = newPrev3;

            ui->Pagina->setText(QString::fromStdString("Página " + std::to_string(PagActual)));
        }

    }
    else if(mode == 4){ ///MODO: SCROLL INFINITO "N"

        firstMovie += 4;

        if(PAnterior == nullptr){
            Pagina* newAnterior = new Pagina();
            PAnterior = newAnterior;
        }

        PAnterior->setPelicula1(PAnterior->getPelicula5());
        PAnterior->setPelicula2(PAnterior->getPelicula6());
        PAnterior->setPelicula3(PAnterior->getPelicula7());
        PAnterior->setPelicula4(PAnterior->getPelicula8());

        PAnterior->setPelicula5(PActual->getPelicula1());
        PAnterior->setPelicula6(PActual->getPelicula2());
        PAnterior->setPelicula7(PActual->getPelicula3());
        PAnterior->setPelicula8(PActual->getPelicula4());

        PActual->setPelicula1(PActual->getPelicula5());
        PActual->setPelicula2(PActual->getPelicula6());
        PActual->setPelicula3(PActual->getPelicula7());
        PActual->setPelicula4(PActual->getPelicula8());
        PActual->setPelicula5(PSiguiente->getPelicula1());
        PActual->setPelicula6(PSiguiente->getPelicula2());
        PActual->setPelicula7(PSiguiente->getPelicula3());
        PActual->setPelicula8(PSiguiente->getPelicula4());

        PSiguiente->setPelicula1(PSiguiente->getPelicula5());
        PSiguiente->setPelicula2(PSiguiente->getPelicula6());
        PSiguiente->setPelicula3(PSiguiente->getPelicula7());
        PSiguiente->setPelicula4(PSiguiente->getPelicula8());



        for(int i = 0; i < lastMovie; i++){
            string newMovie;
            getline(dataset, newMovie, '\n');

        }
        string newMovie;
        getline(dataset, newMovie, '\n');
        Movie *movie1 = new Movie(newMovie);
        PSiguiente->setPelicula5(movie1);

        getline(dataset, newMovie, '\n');
        Movie *movie2 = new Movie(newMovie);
        PSiguiente->setPelicula6(movie2);

        getline(dataset, newMovie, '\n');
        Movie *movie3 = new Movie(newMovie);
        PSiguiente->setPelicula7(movie3);

        getline(dataset, newMovie, '\n');
        Movie *movie4 = new Movie(newMovie);
        PSiguiente->setPelicula8(movie4);

        lastMovie += 4;

    }
    else if(mode == 5){ ///MODO: SCROLL INFINITO "B"
        if(PAnterior == nullptr){
            Pagina* newAnterior = new Pagina();
            PAnterior = newAnterior;
        }
        else if(PAnterior->getPelicula5() == nullptr){
            cout << "No pasa " << endl;
        }
        else if(PAnterior->getPelicula1() == nullptr){
            firstMovie -= 4;
            lastMovie -= 4;
            PSiguiente->setPelicula8(PSiguiente->getPelicula4());
            PSiguiente->setPelicula7(PSiguiente->getPelicula3());
            PSiguiente->setPelicula6(PSiguiente->getPelicula2());
            PSiguiente->setPelicula5(PSiguiente->getPelicula1());
            PSiguiente->setPelicula4(PActual->getPelicula8());
            PSiguiente->setPelicula3(PActual->getPelicula7());
            PSiguiente->setPelicula2(PActual->getPelicula6());
            PSiguiente->setPelicula1(PActual->getPelicula5());

            PActual->setPelicula8(PActual->getPelicula4());
            PActual->setPelicula7(PActual->getPelicula3());
            PActual->setPelicula6(PActual->getPelicula2());
            PActual->setPelicula5(PActual->getPelicula1());
            PActual->setPelicula4(PAnterior->getPelicula8());
            PActual->setPelicula3(PAnterior->getPelicula7());
            PActual->setPelicula2(PAnterior->getPelicula6());
            PActual->setPelicula1(PAnterior->getPelicula5());


            PAnterior->setPelicula8(nullptr);
            PAnterior->setPelicula7(nullptr);
            PAnterior->setPelicula6(nullptr);
            PAnterior->setPelicula5(nullptr);
        }
        else if(firstMovie == 0){
            firstMovie -= 4;
            lastMovie -= 4;
            PSiguiente->setPelicula8(PSiguiente->getPelicula4());
            PSiguiente->setPelicula7(PSiguiente->getPelicula3());
            PSiguiente->setPelicula6(PSiguiente->getPelicula2());
            PSiguiente->setPelicula5(PSiguiente->getPelicula1());
            PSiguiente->setPelicula4(PActual->getPelicula8());
            PSiguiente->setPelicula3(PActual->getPelicula7());
            PSiguiente->setPelicula2(PActual->getPelicula6());
            PSiguiente->setPelicula1(PActual->getPelicula5());

            PActual->setPelicula8(PActual->getPelicula4());
            PActual->setPelicula7(PActual->getPelicula3());
            PActual->setPelicula6(PActual->getPelicula2());
            PActual->setPelicula5(PActual->getPelicula1());
            PActual->setPelicula4(PAnterior->getPelicula8());
            PActual->setPelicula3(PAnterior->getPelicula7());
            PActual->setPelicula2(PAnterior->getPelicula6());
            PActual->setPelicula1(PAnterior->getPelicula5());

            PAnterior->setPelicula8(PAnterior->getPelicula4());
            PAnterior->setPelicula7(PAnterior->getPelicula3());
            PAnterior->setPelicula6(PAnterior->getPelicula2());
            PAnterior->setPelicula5(PAnterior->getPelicula1());
            PAnterior->setPelicula4(nullptr);
            PAnterior->setPelicula3(nullptr);
            PAnterior->setPelicula2(nullptr);
            PAnterior->setPelicula1(nullptr);
        }
        else{
            firstMovie -= 4;
            lastMovie -= 4;
            PSiguiente->setPelicula8(PSiguiente->getPelicula4());
            PSiguiente->setPelicula7(PSiguiente->getPelicula3());
            PSiguiente->setPelicula6(PSiguiente->getPelicula2());
            PSiguiente->setPelicula5(PSiguiente->getPelicula1());
            PSiguiente->setPelicula4(PActual->getPelicula8());
            PSiguiente->setPelicula3(PActual->getPelicula7());
            PSiguiente->setPelicula2(PActual->getPelicula6());
            PSiguiente->setPelicula1(PActual->getPelicula5());

            PActual->setPelicula8(PActual->getPelicula4());
            PActual->setPelicula7(PActual->getPelicula3());
            PActual->setPelicula6(PActual->getPelicula2());
            PActual->setPelicula5(PActual->getPelicula1());
            PActual->setPelicula4(PAnterior->getPelicula8());
            PActual->setPelicula3(PAnterior->getPelicula7());
            PActual->setPelicula2(PAnterior->getPelicula6());
            PActual->setPelicula1(PAnterior->getPelicula5());

            PAnterior->setPelicula8(PAnterior->getPelicula4());
            PAnterior->setPelicula7(PAnterior->getPelicula3());
            PAnterior->setPelicula6(PAnterior->getPelicula2());
            PAnterior->setPelicula5(PAnterior->getPelicula1());

            for(int i = 0; i < firstMovie; i++){
                string newMovie;
                getline(dataset, newMovie, '\n');

            }
            string newMovie;
            getline(dataset, newMovie, '\n');
            Movie *movie1 = new Movie(newMovie);
            PAnterior->setPelicula1(movie1);

            getline(dataset, newMovie, '\n');
            Movie *movie2 = new Movie(newMovie);
            PAnterior->setPelicula2(movie2);

            getline(dataset, newMovie, '\n');
            Movie *movie3 = new Movie(newMovie);
            PAnterior->setPelicula3(movie3);

            getline(dataset, newMovie, '\n');
            Movie *movie4 = new Movie(newMovie);
            PAnterior->setPelicula4(movie4);
        }

    }
    dataset.close();
}

void AdminPages::prepareGUI()
{
    if(getInfiniteScroll() == false){
        ui->NextPag->show();
        ui->Pagina->setVisible(true);
        ui->SpinPag->show();
        ui->SaltarPag->show();

    }
    else{
        ui->PrevPag->hide();
        ui->NextPag->hide();
        ui->Pagina->setVisible(false);
        ui->SpinPag->hide();
        ui->SaltarPag->hide();
    }
}

void AdminPages::setInfiniteScroll(bool status)
{
    InfiniteScroll = status;
}

bool AdminPages::getInfiniteScroll()
{
    return InfiniteScroll;
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
    eje.setPelicula(PActual->getPelicula1());
    eje.loadData();
    eje.exec();
}

void AdminPages::on_peli2_clicked()
{
    MoviePreview eje;
    eje.setModal(true);
    eje.setPelicula(PActual->getPelicula2());
    eje.loadData();
    eje.exec();
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
    if (PSiguiente == nullptr){
        ui->NextPag->hide();
    }
    else{
        ui->NextPag->show();
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
    if (PSiguiente == nullptr){
        ui->NextPag->hide();
    }
    else{
        ui->NextPag->show();
    }
}

void AdminPages::on_peli3_clicked()
{
    MoviePreview eje;
    eje.setModal(true);
    eje.setPelicula(PActual->getPelicula3());
    eje.loadData();
    eje.exec();
}

void AdminPages::on_peli4_clicked()
{
    MoviePreview eje;
    eje.setModal(true);
    eje.setPelicula(PActual->getPelicula4());
    eje.loadData();
    eje.exec();
}

void AdminPages::on_peli5_clicked()
{
    MoviePreview eje;
    eje.setModal(true);
    eje.setPelicula(PActual->getPelicula5());
    eje.loadData();
    eje.exec();
}

void AdminPages::on_peli6_clicked()
{
    MoviePreview eje;
    eje.setModal(true);
    eje.setPelicula(PActual->getPelicula6());
    eje.loadData();
    eje.exec();
}

void AdminPages::on_peli7_clicked()
{
    MoviePreview eje;
    eje.setModal(true);
    eje.setPelicula(PActual->getPelicula7());
    eje.loadData();
    eje.exec();
}

void AdminPages::on_peli8_clicked()
{
    MoviePreview eje;
    eje.setModal(true);
    eje.setPelicula(PActual->getPelicula8());
    eje.loadData();
    eje.exec();
}

void AdminPages::on_SaltarPag_clicked()
{
    loadPages(3);
    loadMovies();
    QThread::msleep(700);
    if (PAnterior == nullptr){
        ui->PrevPag->hide();
    }
    else{
        ui->PrevPag->show();
    }
    if (PSiguiente == nullptr){
        ui->NextPag->hide();
    }
    else{
        ui->NextPag->show();
    }
}

void AdminPages::keyPressEvent(QKeyEvent *event)
{
    if (getInfiniteScroll()){
        if(event->key() == 0x42){
            loadPages(5);
            loadMovies();
            QThread::msleep(700);
        }
        else if(event->key() == 0x4e){
            loadPages(4);
            loadMovies();
            QThread::msleep(700);
        }

    }

}
