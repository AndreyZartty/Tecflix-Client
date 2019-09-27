#ifndef TRAILER_H
#define TRAILER_H

#include <QDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QWebEngineView>
#include <QUrl>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdlib>
#include <netinet/in.h>

namespace Ui {
class Trailer;
}

class Trailer : public QDialog
{
    Q_OBJECT

public:
    explicit Trailer(QWidget *parent = nullptr);
    ~Trailer();
    void setTrailer(QString H_Trailer);
    void makeTrailer();

private:
    Ui::Trailer *ui;
    QMediaPlayer* player;
    QWebEngineView* vw;
    QString iftrailer;
};

#endif // TRAILER_H
