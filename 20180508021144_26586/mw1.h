#ifndef MW1_H
#define MW1_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>
#include <QTime>
#include <QTimer>
#include "rpgobj.h"
#include "world.h"

namespace Ui {
class MW1;
}

class MW1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MW1(QWidget *parent = 0);
    ~MW1();
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *);
protected slots:
    void randomMove();

private:
    Ui::MW1 *ui;
    World _game;
    QTimer *timer;
};

#endif // MW1_H
