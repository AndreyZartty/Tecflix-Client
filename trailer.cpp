#include "trailer.h"
#include "ui_trailer.h"
#include <iostream>

using namespace std;

Trailer::Trailer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Trailer)
{
    ui->setupUi(this);

    /*ui->Message->setMinimumWidth(this->width());
    ui->Message->setMinimumHeight(this->height());
    ui->Message->hide();
    vw->hide();*/

}

Trailer::~Trailer()
{
    delete ui;
}

void Trailer::setTrailer(QString H_Trailer)
{
    iftrailer = H_Trailer;
}

void Trailer::makeTrailer(){
    size_t look = iftrailer.toStdString().find("www.imdb.com");
    if (look < iftrailer.toStdString().size()){
        player = new QMediaPlayer(this);
        vw = new QWebEngineView(this);
        vw->setMinimumWidth(this->width());
        vw->setMinimumHeight(this->height());

        QByteArray trailer = iftrailer.toUtf8();
        QUrl url = QUrl::fromEncoded(trailer,QUrl::StrictMode);
        vw->load(url);
        vw->show();
        ui->Message->setVisible(false);
    }
    else{
        ui->Message->setVisible(true);
    }
}
