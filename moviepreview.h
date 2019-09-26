#ifndef MOVIEPREVIEW_H
#define MOVIEPREVIEW_H

#include <QDialog>

namespace Ui {
class MoviePreview;
}

class MoviePreview : public QDialog
{
    Q_OBJECT

public:
    explicit MoviePreview(QWidget *parent = nullptr);
    ~MoviePreview();

private:
    Ui::MoviePreview *ui;
};

#endif // MOVIEPREVIEW_H
