#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include "curlobj.h"
#include <QString>

using namespace std;

class Movie
{
public:
    Movie(QString Color, QString Director, QString Criticos, QString Duracion, QString LikesDirector, QString LikesActor3, QString Actor2, QString LikesActor1, QString Taquilla, QString Generos, QString Actor1, string Titulo, QString VotosUsuarios, QString LikesCast, QString Actor3, QString Facenumber, QString Keywords, QString LinkImdb, QString Usuarios, QString Idioma, QString Pais, QString Clasificacion, QString Presupuesto, QString Year, QString LikesActor2, QString Puntuacion, QString AspectRatio, QString LikesPelicula);
    Movie(string Line);

    QString getColor() ;
    void setColor(QString Color);

    QString getDirector() ;
    void setDirector(QString Director);

    QString getCriticosQueRevisaron();
    void setCriticosQueRevisaron(QString Criticos);

    QString getDuracion();
    void setDuracion(QString Duracion);

    QString getFB_likes_director();
    void setFB_likes_director(QString LikesDirector);

    QString getFB_likes_actor3();
    void setFB_likes_actor3(QString LikesActor3);

    QString getActor2();
    void setActor2(QString Actor2);

    QString getFB_likes_actor1();
    void setFB_likes_actor1(QString LikesActor1);

    QString getTaquilla();
    void setTaquilla(QString Taquilla);

    QString getGeneros();
    void setGeneros(QString Generos);

    QString getActor1();
    void setActor1(QString Actor1);

    QString getTitulo();
    void setTitulo(string Titulo);

    QString getVotosDeUsuarios();
    void setVotosDeUsuarios(QString VotosUsuarios);

    QString getFB_likes_cast();
    void setFB_likes_cast(QString LikesCast);

    QString getActor3();
    void setActor3(QString Actor3);

    QString getFacenumberEnPoster();
    void setFacenumberEnPoster(QString Facenumber);

    QString getKeywords();
    void setKeywords(QString Keywords);

    QString getImdbLink();
    void setImdbLink(QString LinkImdb);

    QString getUsersQueRevisaron();
    void setUsersQueRevisaron(QString Usuarios);

    QString getIdioma();
    void setIdioma(QString Idioma);

    QString getPais();
    void setPais(QString Pais);

    QString getClasificacion();
    void setClasificacion(QString Clasificacion);

    QString getPresupuesto();
    void setPresupuesto(QString Presupuesto);

    QString getYear();
    void setYear(QString Year);

    QString getFB_likes_actor2();
    void setFB_likes_actor2(QString LikesActor2);

    QString getPuntuacion_imdb();
    void setPuntuacion_imdb(QString Puntuacion);

    QString getAspectRatio();
    void setAspectRatio(QString AspectRatio);

    QString getFB_likes_pelicula();
    void setFB_likes_pelicula(QString LikesPelicula);

    QString getTrailerLink();
    void setTrailerLink(QString Trailer);

    QString getPosterLink();
    void setPosterLink(QString Poster);

    void setPoster_Trailer(QString link);

private:
    QString color;
    QString director;
    QString criticosQueRevisaron;
    QString duracion;
    QString FB_likes_director;
    QString FB_likes_actor3;
    QString actor2;
    QString FB_likes_actor1;
    QString taquilla;
    QString generos;
    QString actor1;
    QString titulo;
    QString votosDeUsuarios;
    QString FB_likes_cast;
    QString actor3;
    QString FacenumberEnPoster;
    QString keywords;
    QString imdbLink;
    QString usersQueRevisaron;
    QString idioma;
    QString pais;
    QString clasificacion;
    QString presupuesto;
    QString year;
    QString FB_likes_actor2;
    QString puntuacion_imdb;
    QString aspectRatio;
    QString FB_likes_pelicula;
    QString trailerLink;
    QString posterLink;
};

#endif // MOVIE_H
