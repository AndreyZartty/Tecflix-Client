#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include "curlobj.h"

using namespace std;

class Movie
{
public:
    Movie(string Color, string Director, string Criticos, string Duracion, string LikesDirector, string LikesActor3, string Actor2, string LikesActor1, string Taquilla, string Generos, string Actor1, string Titulo, string VotosUsuarios, string LikesCast, string Actor3, string Facenumber, string Keywords, string LinkImdb, string Usuarios, string Idioma, string Pais, string Clasificacion, string Presupuesto, string Year, string LikesActor2, string Puntuacion, string AspectRatio, string LikesPelicula);

    string getColor() ;
    void setColor(string Color);

    string getDirector() ;
    void setDirector(string Director);

    string getCriticosQueRevisaron();
    void setCriticosQueRevisaron(string Criticos);

    string getDuracion();
    void setDuracion(string Duracion);

    string getFB_likes_director();
    void setFB_likes_director(string LikesDirector);

    string getFB_likes_actor3();
    void setFB_likes_actor3(string LikesActor3);

    string getActor2();
    void setActor2(string Actor2);

    string getFB_likes_actor1();
    void setFB_likes_actor1(string LikesActor1);

    string getTaquilla();
    void setTaquilla(string Taquilla);

    string getGeneros();
    void setGeneros(string Generos);

    string getActor1();
    void setActor1(string Actor1);

    string getTitulo();
    void setTitulo(string Titulo);

    string getVotosDeUsuarios();
    void setVotosDeUsuarios(string VotosUsuarios);

    string getFB_likes_cast();
    void setFB_likes_cast(string LikesCast);

    string getActor3();
    void setActor3(string Actor3);

    string getFacenumberEnPoster();
    void setFacenumberEnPoster(string Facenumber);

    string getKeywords();
    void setKeywords(string Keywords);

    string getImdbLink();
    void setImdbLink(string LinkImdb);

    string getUsersQueRevisaron();
    void setUsersQueRevisaron(string Usuarios);

    string getIdioma();
    void setIdioma(string Idioma);

    string getPais();
    void setPais(string Pais);

    string getClasificacion();
    void setClasificacion(string Clasificacion);

    string getPresupuesto();
    void setPresupuesto(string Presupuesto);

    string getYear();
    void setYear(string Year);

    string getFB_likes_actor2();
    void setFB_likes_actor2(string LikesActor2);

    string getPuntuacion_imdb();
    void setPuntuacion_imdb(string Puntuacion);

    string getAspectRatio();
    void setAspectRatio(string AspectRatio);

    string getFB_likes_pelicula();
    void setFB_likes_pelicula(string LikesPelicula);

    string getTrailerLink();
    void setTrailerLink(string Trailer);

    string getPosterLink();
    void setPosterLink(string Poster);

    void setPoster_Trailer(string link);

private:
    string color;
    string director;
    string criticosQueRevisaron;
    string duracion;
    string FB_likes_director;
    string FB_likes_actor3;
    string actor2;
    string FB_likes_actor1;
    string taquilla;
    string generos;
    string actor1;
    string titulo;
    string votosDeUsuarios;
    string FB_likes_cast;
    string actor3;
    string FacenumberEnPoster;
    string keywords;
    string imdbLink;
    string usersQueRevisaron;
    string idioma;
    string pais;
    string clasificacion;
    string presupuesto;
    string year;
    string FB_likes_actor2;
    string puntuacion_imdb;
    string aspectRatio;
    string FB_likes_pelicula;
    string trailerLink;
    string posterLink;
};

#endif // MOVIE_H
