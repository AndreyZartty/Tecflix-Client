#ifndef AdminPages_H
#define AdminPages_H

#include <QMainWindow>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdlib>
#include <netinet/in.h>
#include "pagina.h"
#include "movie.h"
#include <iostream>
#include <fstream>
#include <QKeyEvent>


namespace Ui {
class AdminPages;
}

class AdminPages : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminPages(QWidget *parent = nullptr);
    ~AdminPages();
    void loadMovies();
    void loadPages(int mode);
    void prepareGUI();
    void setInfiniteScroll(bool status);
    bool getInfiniteScroll();


    bool getCompleteDataset();
    void setCompleteDataset(bool state);

public slots:
    void slot_netwManagerFinished1(QNetworkReply *reply);
    void slot_netwManagerFinished2(QNetworkReply *reply);
    void slot_netwManagerFinished3(QNetworkReply *reply);
    void slot_netwManagerFinished4(QNetworkReply *reply);
    void slot_netwManagerFinished5(QNetworkReply *reply);
    void slot_netwManagerFinished6(QNetworkReply *reply);
    void slot_netwManagerFinished7(QNetworkReply *reply);
    void slot_netwManagerFinished8(QNetworkReply *reply);

private slots:
    void on_peli1_clicked();

    void on_NextPag_clicked();

    void on_peli2_clicked();

    void on_PrevPag_clicked();

    void on_peli3_clicked();

    void on_peli4_clicked();

    void on_peli5_clicked();

    void on_peli6_clicked();

    void on_peli7_clicked();

    void on_peli8_clicked();

    void on_SaltarPag_clicked();

    void keyPressEvent(QKeyEvent * event );


private:
    Ui::AdminPages *ui;
    Pagina* PAnterior = nullptr;
    Pagina* PActual = nullptr;
    Pagina* PSiguiente = nullptr;
    ifstream dataset;
    int firstMovie = -8;
    int lastMovie = 0;
    int PagActual = 1;
    bool InfiniteScroll = false;
    bool CompleteDataset = false;
    vector<Pagina*> CompleteDatasetP;
    vector<Movie*> CompleteDatasetM;


};

#endif // AdminPages_H
