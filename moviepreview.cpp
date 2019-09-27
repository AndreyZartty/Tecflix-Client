#include "moviepreview.h"
#include "ui_moviepreview.h"

MoviePreview::MoviePreview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoviePreview)
{
    ui->setupUi(this);
    setStyleSheet("QWidget { background-color: rgb(30, 33, 30); }");
}

MoviePreview::~MoviePreview()
{
    delete ui;
}

Movie *MoviePreview::getPelicula()
{
    return Pelicula;
}

void MoviePreview::setPelicula(Movie *movie)
{
    Pelicula = movie;
}

void MoviePreview::loadData()
{
    QNetworkAccessManager* m_netwManager1 = new QNetworkAccessManager(this);
    connect(m_netwManager1, SIGNAL(finished(QNetworkReply*)),this, SLOT(slot_netwManagerFinished(QNetworkReply*)));

    QByteArray P1 = Pelicula->getPosterLink().toUtf8();
    QUrl url = QUrl::fromEncoded(P1,QUrl::StrictMode);
    QNetworkRequest request(url);
    m_netwManager1->get(request);

    setWindowTitle(Pelicula->getTitulo());

    ui->Link->setText(Pelicula->getImdbLink());
    ui->Link->text().resize(ui->Link->width());


    ui->Pais->setText(Pelicula->getPais());
    ui->Year->setText(Pelicula->getYear());
    ui->Color->setText(Pelicula->getColor());
    ui->Actor1->setText(Pelicula->getActor1());
    ui->Actor2->setText(Pelicula->getActor2());
    ui->Actor3->setText(Pelicula->getActor3());
    ui->Idioma->setText(Pelicula->getIdioma());
    ui->Titulo->setText(Pelicula->getTitulo());

    ui->Generos->setText(Pelicula->getGeneros());
    ui->Generos->text().resize(ui->Generos->width());


    ui->Duracion->setText(Pelicula->getDuracion());
    ui->Director->setText(Pelicula->getDirector());
    ui->Taquilla->setText(Pelicula->getTaquilla());
    ui->Facenumber->setText(Pelicula->getFacenumberEnPoster());
    ui->Likes_Cast->setText(Pelicula->getFB_likes_cast());
    ui->AspectRatio->setText(Pelicula->getAspectRatio());
    ui->Presupuesto->setText(Pelicula->getPresupuesto());
    ui->Calificacion->setText(Pelicula->getPuntuacion_imdb());
    ui->Likes_actor1->setText(Pelicula->getFB_likes_actor1());
    ui->Likes_actor2->setText(Pelicula->getFB_likes_actor2());
    ui->Likes_actor3->setText(Pelicula->getFB_likes_actor3());
    ui->UsersReviews->setText(Pelicula->getUsersQueRevisaron());
    ui->Clasificacion->setText(Pelicula->getClasificacion());
    ui->LikesPelicula->setText(Pelicula->getFB_likes_pelicula());

    ui->PalabrasClave->setText(Pelicula->getKeywords());
    ui->PalabrasClave->text().resize(ui->PalabrasClave->width());

    ui->VotosUsuarios->setText(Pelicula->getVotosDeUsuarios());
    ui->FB_Like_director->setText(Pelicula->getFB_likes_director());
    ui->CriticosRevisaron->setText(Pelicula->getCriticosQueRevisaron());




}

void MoviePreview::slot_netwManagerFinished(QNetworkReply *reply)
{
    if(reply->error() != QNetworkReply::NoError){
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        return;
    }
    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    QIcon ButtonIcon(pixmap);
    ui->Poster->setIcon(ButtonIcon);
    ui->Poster->setIconSize(pixmap.rect().size());
    ui->Poster->setMinimumWidth(pixmap.rect().width());
    ui->Poster->setMinimumHeight(pixmap.rect().height());
    ui->Poster->setCheckable(false);
}

void MoviePreview::on_Trailer_clicked()
{

    Trailer eje;
    eje.setModal(true);
    eje.setTrailer(Pelicula->getTrailerLink());
    eje.makeTrailer();
    eje.exec();
}
