#include "moviepreview.h"
#include "ui_moviepreview.h"

MoviePreview::MoviePreview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoviePreview)
{
    ui->setupUi(this);
}

MoviePreview::~MoviePreview()
{
    delete ui;
}
