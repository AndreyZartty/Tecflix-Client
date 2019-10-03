#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QWebEngineView>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstdlib>
#include <netinet/in.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void slot_netwManagerFinished(QNetworkReply *reply);

private slots:
    void on_BotonPrueba_clicked();
    void on_InfiniteScroll_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QWebEngineView* vw;
};
#endif // MAINWINDOW_H
