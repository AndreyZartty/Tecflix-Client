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

private:
    Ui::AdminPages *ui;
    Pagina* PAnterior = nullptr;
    Pagina* PActual = nullptr;
    Pagina* PSiguiente = nullptr;
    ifstream dataset;
    int firstMovie = -8;
    int lastMovie = 0;

};

#endif // AdminPages_H
