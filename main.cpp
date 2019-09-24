#include "mainwindow.h"

#include <QApplication>
#include "movie.h"
#include <iostream>
#include <fstream>


using namespace std;

int main(int argc, char *argv[])
{
    /*ifstream dataset;
    dataset.open("/home/andreyzartty/Documentos/Proyectos/TECflix/Tecflix-Client/movie_metadata.csv");
    int c=0;
    string lol;
    getline(dataset,lol, '\n');
    cout << "ESTE NO " << lol << endl;
    while (c<3){
        getline(dataset,lol, '\n');      /// Agregar al creador de paginas
        cout << "xd " << lol << endl;
        c++;
    }
    dataset.close();*/

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
