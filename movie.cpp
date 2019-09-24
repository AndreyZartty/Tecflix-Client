#include "movie.h"

/// Constructor

Movie::Movie(string Color, string Director, string Criticos, string Duracion, string LikesDirector, string LikesActor3, string Actor2, string LikesActor1, string Taquilla, string Generos, string Actor1, string Titulo, string VotosUsuarios, string LikesCast, string Actor3, string Facenumber, string Keywords, string LinkImdb, string Usuarios, string Idioma, string Pais, string Clasificacion, string Presupuesto, string Year, string LikesActor2, string Puntuacion, string AspectRatio, string LikesPelicula)
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

/// Getters y Setters

string Movie::getColor()
{
    return color;
}

void Movie::setColor(string Color)
{
    color = Color;
}

string Movie::getDirector()
{
    return director;
}

void Movie::setDirector(string Director)
{
    director = Director;
}

string Movie::getCriticosQueRevisaron()
{
    return criticosQueRevisaron;
}

void Movie::setCriticosQueRevisaron(string Criticos)
{
    criticosQueRevisaron = Criticos;
}

string Movie::getDuracion()
{
    return duracion;
}

void Movie::setDuracion(string Duracion)
{
    duracion = Duracion;
}

string Movie::getFB_likes_director()
{
    return FB_likes_director;
}

void Movie::setFB_likes_director(string LikesDirector)
{
    FB_likes_director = LikesDirector;
}

string Movie::getFB_likes_actor3()
{
    return FB_likes_actor3;
}

void Movie::setFB_likes_actor3(string LikesActor3)
{
    FB_likes_actor3 = LikesActor3;
}

string Movie::getActor2()
{
    return actor2;
}

void Movie::setActor2(string Actor2)
{
    actor2 = Actor2;
}

string Movie::getFB_likes_actor1()
{
    return FB_likes_actor1;
}

void Movie::setFB_likes_actor1(string LikesActor1)
{
    FB_likes_actor1 = LikesActor1;
}

string Movie::getTaquilla()
{
    return taquilla;
}

void Movie::setTaquilla(string Taquilla)
{
    taquilla = Taquilla;
}

string Movie::getGeneros()
{
    return generos;
}

void Movie::setGeneros(string Generos)
{
    generos = Generos;
}

string Movie::getActor1()
{
    return actor1;
}

void Movie::setActor1(string Actor1)
{
    actor1 = Actor1;
}

string Movie::getTitulo()
{
    return titulo;
}

void Movie::setTitulo(string Titulo)
{
    titulo = Titulo;
}

string Movie::getVotosDeUsuarios()
{
    return votosDeUsuarios;
}

void Movie::setVotosDeUsuarios(string VotosUsuarios)
{
    votosDeUsuarios = VotosUsuarios;
}

string Movie::getFB_likes_cast()
{
    return FB_likes_cast;
}

void Movie::setFB_likes_cast(string LikesCast)
{
    FB_likes_cast = LikesCast;
}

string Movie::getActor3()
{
    return actor3;
}

void Movie::setActor3(string Actor3)
{
    actor3 = Actor3;
}

string Movie::getFacenumberEnPoster()
{
    return FacenumberEnPoster;
}

void Movie::setFacenumberEnPoster(string Facenumber)
{
    FacenumberEnPoster = Facenumber;
}

string Movie::getKeywords()
{
    return keywords;
}

void Movie::setKeywords(string Keywords)
{
    keywords = Keywords;
}

string Movie::getImdbLink()
{
    return imdbLink;
}

void Movie::setImdbLink(string LinkImdb)
{
    imdbLink = LinkImdb;
    setPoster_Trailer(imdbLink);
}

string Movie::getUsersQueRevisaron()
{
    return usersQueRevisaron;
}

void Movie::setUsersQueRevisaron(string Usuarios)
{
    usersQueRevisaron = Usuarios;
}

string Movie::getIdioma()
{
    return idioma;
}

void Movie::setIdioma(string Idioma)
{
    idioma = Idioma;
}

string Movie::getPais()
{
    return pais;
}

void Movie::setPais(string Pais)
{
    pais = Pais;
}

string Movie::getClasificacion()
{
    return clasificacion;
}

void Movie::setClasificacion(string Clasificacion)
{
    clasificacion = Clasificacion;
}

string Movie::getPresupuesto()
{
    return presupuesto;
}

void Movie::setPresupuesto(string Presupuesto)
{
    presupuesto = Presupuesto;
}

string Movie::getYear()
{
    return year;
}

void Movie::setYear(string Year)
{
    year = Year;
}

string Movie::getFB_likes_actor2()
{
    return FB_likes_actor2;
}

void Movie::setFB_likes_actor2(string LikesActor2)
{
    FB_likes_actor2 = LikesActor2;
}

string Movie::getPuntuacion_imdb()
{
    return puntuacion_imdb;
}

void Movie::setPuntuacion_imdb(string Puntuacion)
{
    puntuacion_imdb = Puntuacion;
}

string Movie::getAspectRatio()
{
    return aspectRatio;
}

void Movie::setAspectRatio(string AspectRatio)
{
    aspectRatio = AspectRatio;
}

string Movie::getFB_likes_pelicula()
{
    return FB_likes_pelicula;
}

void Movie::setFB_likes_pelicula(string LikesPelicula)
{
    FB_likes_pelicula = LikesPelicula;
}

string Movie::getTrailerLink()
{
    return trailerLink;
}

void Movie::setTrailerLink(string Trailer)
{
    trailerLink = Trailer;
}

string Movie::getPosterLink()
{
    return posterLink;
}

void Movie::setPosterLink(string Poster)
{
    posterLink = Poster;
}

/// Metodo para extraer los links del poster y el trailer del HTML

void Movie::setPoster_Trailer(string link)
{
    CurlObj dataHTML(link);
    string html = dataHTML.getData();

    string search = "embedUrl";
    size_t index = html.find(search);
    html = html.substr(index);

    search = "/";
    index = html.find(search);
    html = html.substr(index);

    search = ",";
    index = html.find(search);

    string tlink = "https://www.imdb.com" + html.substr(0,index-1);
    setTrailerLink(tlink);

    html = html.substr(index);

    search = "<img alt=";
    index = html.find(search);
    html = html.substr(index);

    search = "poster";
    index = html.find(search);
    html = html.substr(index);

    search = "src=";
    index = html.find(search);
    html = html.substr(index+5);

    search = " />";
    index = html.find(search);
    html = html.substr(0, index-1);
    setPosterLink(html);
}
