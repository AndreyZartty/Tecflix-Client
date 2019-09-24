#ifndef PAGINA_H
#define PAGINA_H

#include "movie.h"

class Pagina
{
public:
    Movie *getPelicula1() ;
    void setPelicula1(Movie *Pelicula);

    Movie *getPelicula2();
    void setPelicula2(Movie *Pelicula);

    Movie *getPelicula3();
    void setPelicula3(Movie *Pelicula);

    Movie *getPelicula4();
    void setPelicula4(Movie *Pelicula);

    Movie *getPelicula5();
    void setPelicula5(Movie *Pelicula);

    Movie *getPelicula6();
    void setPelicula6(Movie *Pelicula);

    Movie *getPelicula7();
    void setPelicula7(Movie *Pelicula);

    Movie *getPelicula8();
    void setPelicula8(Movie *Pelicula);

    Movie *getPelicula9();
    void setPelicula9(Movie *Pelicula);

    void addMovie(Movie* movie);

private:
    Movie* pelicula1 = nullptr;
    Movie* pelicula2 = nullptr;
    Movie* pelicula3 = nullptr;
    Movie* pelicula4 = nullptr;
    Movie* pelicula5 = nullptr;
    Movie* pelicula6 = nullptr;
    Movie* pelicula7 = nullptr;
    Movie* pelicula8 = nullptr;
    Movie* pelicula9 = nullptr;

};

#endif // PAGINA_H
