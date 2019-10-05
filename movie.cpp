#include "movie.h"
#include <QThread>

/// Constructor

Movie::Movie(QString Color, QString Director, QString Criticos, QString Duracion, QString LikesDirector, QString LikesActor3, QString Actor2, QString LikesActor1, QString Taquilla, QString Generos, QString Actor1, string Titulo, QString VotosUsuarios, QString LikesCast, QString Actor3, QString Facenumber, QString Keywords, QString LinkImdb, QString Usuarios, QString Idioma, QString Pais, QString Clasificacion, QString Presupuesto, QString Year, QString LikesActor2, QString Puntuacion, QString AspectRatio, QString LikesPelicula)
{
    setColor(Color);
    setDirector(Director);
    setCriticosQueRevisaron(Criticos);
    setDuracion(Duracion);
    setFB_likes_director(LikesDirector);
    setFB_likes_actor3(LikesActor3);
    setActor2(Actor2);
    setFB_likes_actor1(LikesActor1);
    setTaquilla(Taquilla);
    setGeneros(Generos);
    setActor1(Actor1);
    setTitulo(Titulo);
    setVotosDeUsuarios(VotosUsuarios);
    setFB_likes_cast(LikesCast);
    setActor3(Actor3);
    setFacenumberEnPoster(Facenumber);
    setKeywords(Keywords);
    setImdbLink(LinkImdb);
    setUsersQueRevisaron(Usuarios);
    setIdioma(Idioma);
    setPais(Pais);
    setClasificacion(Clasificacion);
    setPresupuesto(Presupuesto);
    setYear(Year);
    setFB_likes_actor2(LikesActor2);
    setPuntuacion_imdb(Puntuacion);
    setAspectRatio(AspectRatio);
    setFB_likes_pelicula(LikesPelicula);
}

Movie::Movie(string Line)
{
    string coma = ",";
    size_t index = Line.find(coma);
    setColor(QString::fromStdString(Line.substr(0,index)));

    string temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setDirector(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setCriticosQueRevisaron(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setDuracion(QString::fromStdString(Line.substr(0,index) + " min"));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setFB_likes_director(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setFB_likes_actor3(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setActor2(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setFB_likes_actor1(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setTaquilla(QString::fromStdString("$ " + Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setGeneros(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setActor1(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setTitulo(Line.substr(0,index));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setVotosDeUsuarios(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setFB_likes_cast(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setActor3(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setFacenumberEnPoster(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setKeywords(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setImdbLink(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setUsersQueRevisaron(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setIdioma(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setPais(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setClasificacion(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setPresupuesto(QString::fromStdString("$ " + Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setYear(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setFB_likes_actor2(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setPuntuacion_imdb(QString::fromStdString(Line.substr(0,index) + "/10"));

    temporal = Line.substr(index+1);
    Line = temporal;
    index = Line.find(coma);
    setAspectRatio(QString::fromStdString(Line.substr(0,index)));

    temporal = Line.substr(index+1);
    Line = temporal;
    setFB_likes_pelicula(QString::fromStdString(Line.substr(0,index)));
}

/// Getters y Setters

QString Movie::getColor()
{
    return color;
}

void Movie::setColor(QString Color)
{
    color = Color;
}

QString Movie::getDirector()
{
    return director;
}

void Movie::setDirector(QString Director)
{
    director = Director;
}

QString Movie::getCriticosQueRevisaron()
{
    return criticosQueRevisaron;
}

void Movie::setCriticosQueRevisaron(QString Criticos)
{
    criticosQueRevisaron = Criticos;
}

QString Movie::getDuracion()
{
    return duracion;
}

void Movie::setDuracion(QString Duracion)
{
    duracion = Duracion;
}

QString Movie::getFB_likes_director()
{
    return FB_likes_director;
}

void Movie::setFB_likes_director(QString LikesDirector)
{
    FB_likes_director = LikesDirector;
}

QString Movie::getFB_likes_actor3()
{
    return FB_likes_actor3;
}

void Movie::setFB_likes_actor3(QString LikesActor3)
{
    FB_likes_actor3 = LikesActor3;
}

QString Movie::getActor2()
{
    return actor2;
}

void Movie::setActor2(QString Actor2)
{
    actor2 = Actor2;
}

QString Movie::getFB_likes_actor1()
{
    return FB_likes_actor1;
}

void Movie::setFB_likes_actor1(QString LikesActor1)
{
    FB_likes_actor1 = LikesActor1;
}

QString Movie::getTaquilla()
{
    return taquilla;
}

void Movie::setTaquilla(QString Taquilla)
{
    taquilla = Taquilla;
}

QString Movie::getGeneros()
{
    return generos;
}

void Movie::setGeneros(QString Generos)
{
    generos = Generos;
}

QString Movie::getActor1()
{
    return actor1;
}

void Movie::setActor1(QString Actor1)
{
    actor1 = Actor1;
}

QString Movie::getTitulo()
{
    return titulo;
}

void Movie::setTitulo(string Titulo)
{
    size_t Title = Titulo.find("|");
    while(Title < Titulo.length()){
        Titulo.replace(Title,1,",");
        Title = Titulo.find("|");
    }
    titulo = QString::fromStdString(Titulo);
}

QString Movie::getVotosDeUsuarios()
{
    return votosDeUsuarios;
}

void Movie::setVotosDeUsuarios(QString VotosUsuarios)
{
    votosDeUsuarios = VotosUsuarios;
}

QString Movie::getFB_likes_cast()
{
    return FB_likes_cast;
}

void Movie::setFB_likes_cast(QString LikesCast)
{
    FB_likes_cast = LikesCast;
}

QString Movie::getActor3()
{
    return actor3;
}

void Movie::setActor3(QString Actor3)
{
    actor3 = Actor3;
}

QString Movie::getFacenumberEnPoster()
{
    return FacenumberEnPoster;
}

void Movie::setFacenumberEnPoster(QString Facenumber)
{
    FacenumberEnPoster = Facenumber;
}

QString Movie::getKeywords()
{
    return keywords;
}

void Movie::setKeywords(QString Keywords)
{
    keywords = Keywords;
}

QString Movie::getImdbLink()
{
    return imdbLink;
}

void Movie::setImdbLink(QString LinkImdb)
{
    imdbLink = LinkImdb;
    setPoster_Trailer(imdbLink);
}

QString Movie::getUsersQueRevisaron()
{
    return usersQueRevisaron;
}

void Movie::setUsersQueRevisaron(QString Usuarios)
{
    usersQueRevisaron = Usuarios;
}

QString Movie::getIdioma()
{
    return idioma;
}

void Movie::setIdioma(QString Idioma)
{
    idioma = Idioma;
}

QString Movie::getPais()
{
    return pais;
}

void Movie::setPais(QString Pais)
{
    pais = Pais;
}

QString Movie::getClasificacion()
{
    return clasificacion;
}

void Movie::setClasificacion(QString Clasificacion)
{
    clasificacion = Clasificacion;
}

QString Movie::getPresupuesto()
{
    return presupuesto;
}

void Movie::setPresupuesto(QString Presupuesto)
{
    presupuesto = Presupuesto;
}

QString Movie::getYear()
{
    return year;
}

void Movie::setYear(QString Year)
{
    year = Year;
}

QString Movie::getFB_likes_actor2()
{
    return FB_likes_actor2;
}

void Movie::setFB_likes_actor2(QString LikesActor2)
{
    FB_likes_actor2 = LikesActor2;
}

QString Movie::getPuntuacion_imdb()
{
    return puntuacion_imdb;
}

void Movie::setPuntuacion_imdb(QString Puntuacion)
{
    puntuacion_imdb = Puntuacion;
}

QString Movie::getAspectRatio()
{
    return aspectRatio;
}

void Movie::setAspectRatio(QString AspectRatio)
{
    aspectRatio = AspectRatio;
}

QString Movie::getFB_likes_pelicula()
{
    return FB_likes_pelicula;
}

void Movie::setFB_likes_pelicula(QString LikesPelicula)
{
    FB_likes_pelicula = LikesPelicula;
}

QString Movie::getTrailerLink()
{
    return trailerLink;
}

void Movie::setTrailerLink(QString Trailer)
{
    trailerLink = Trailer;
}

QString Movie::getPosterLink()
{
    return posterLink;
}

void Movie::setPosterLink(QString Poster)
{
    posterLink = Poster;
}

/// Metodo para extraer los links del poster y el trailer del HTML

void Movie::setPoster_Trailer(QString link)
{
    QThread::msleep(350);
    dataHTML.setUrl(link.toStdString());
    dataHTML.DoRequest();
    string html = dataHTML.getData();


    string search = "embedUrl";
    size_t index = html.find(search);

    if(index > html.size()){
        setTrailerLink("No hay trailer por mostrar");
    }
    else{
        html = html.substr(index);

        search = "/";
        index = html.find(search);
        html = html.substr(index);

        search = ",";
        index = html.find(search);

        string tlink = "https://www.imdb.com" + html.substr(0,index-1);
        setTrailerLink(QString::fromStdString(tlink));


        html = html.substr(index);
    }

    search = "<img alt=";
    index = html.find(search);

    if(index > html.size()){
        string Plink = "https://i.imgur.com/VbvVAOy.jpg?2";
        setPosterLink(QString::fromStdString(Plink));
    }
    else{
        html = html.substr(index);

        search = "poster";
        index = html.find(search);

        if(index > html.size()){
            string Plink = "https://i.imgur.com/VbvVAOy.jpg?2";
            setPosterLink(QString::fromStdString(Plink));
        }
        else{
            html = html.substr(index);

            search = "src=";
            index = html.find(search);

            if(index > html.size()){
                string Plink = "https://i.imgur.com/VbvVAOy.jpg?2";
                setPosterLink(QString::fromStdString(Plink));
            }
            else{
                html = html.substr(index+5);

                search = " />";
                index = html.find(search);
                html = html.substr(0, index-1);
                setPosterLink(QString::fromStdString(html));

            }


        }
    }

}
