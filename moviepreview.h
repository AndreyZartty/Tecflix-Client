#ifndef MOVIEPREVIEW_H
#define MOVIEPREVIEW_H

#include <QDialog>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdlib>
#include <netinet/in.h>
#include "movie.h"
#include "trailer.h"

namespace Ui {
class MoviePreview;
}

class MoviePreview : public QDialog
{
    Q_OBJECT

public:
    explicit MoviePreview(QWidget *parent = nullptr);
    ~MoviePreview();

    Movie *getPelicula();
    void setPelicula(Movie *movie);
    void loadData();

public slots:
    void slot_netwManagerFinished(QNetworkReply *reply);

private slots:
    void on_Trailer_clicked();

private:
    Ui::MoviePreview *ui;
    Movie *Pelicula;
};

#endif // MOVIEPREVIEW_H
