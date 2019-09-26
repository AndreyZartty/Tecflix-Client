#include "pagina.h"

// Getters y Setters

Pagina::Pagina()
{
}

Movie *Pagina::getPelicula1()
{
    return pelicula1;
}

void Pagina::setPelicula1(Movie *Pelicula)
{
    pelicula1 = Pelicula;
}

Movie *Pagina::getPelicula2()
{
    return pelicula2;
}

void Pagina::setPelicula2(Movie *Pelicula)
{
    pelicula2 = Pelicula;
}

Movie *Pagina::getPelicula3()
{
    return pelicula3;
}

void Pagina::setPelicula3(Movie *Pelicula)
{
    pelicula3 = Pelicula;
}

Movie *Pagina::getPelicula4()
{
    return pelicula4;
}

void Pagina::setPelicula4(Movie *Pelicula)
{
    pelicula4 = Pelicula;
}

Movie *Pagina::getPelicula5()
{
    return pelicula5;
}

void Pagina::setPelicula5(Movie *Pelicula)
{
    pelicula5 = Pelicula;
}

Movie *Pagina::getPelicula6()
{
    return pelicula6;
}

void Pagina::setPelicula6(Movie *Pelicula)
{
    pelicula6 = Pelicula;
}

Movie *Pagina::getPelicula7()
{
    return pelicula7;
}

void Pagina::setPelicula7(Movie *Pelicula)
{
    pelicula7 = Pelicula;
}

Movie *Pagina::getPelicula8()
{
    return pelicula8;
}

void Pagina::setPelicula8(Movie *Pelicula)
{
    pelicula8 = Pelicula;
}



/// Metodo para agregar una pelicula por orden

void Pagina::addMovie(Movie *movie)
{
    if(pelicula1 == nullptr){
        setPelicula1(movie);
    }
    else if(pelicula2 == nullptr){
        setPelicula2(movie);
    }
    else if(pelicula3 == nullptr){
        setPelicula3(movie);
    }
    else if(pelicula4 == nullptr){
        setPelicula4(movie);
    }
    else if(pelicula5 == nullptr){
        setPelicula5(movie);
    }
    else if(pelicula6 == nullptr){
        setPelicula6(movie);
    }
    else if(pelicula7 == nullptr){
        setPelicula7(movie);
    }
    else if(pelicula8 == nullptr){
        setPelicula8(movie);
    }
    else{
        cout << "No se pueden agregar mas peliculas" << endl;
    }
}
