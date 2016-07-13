#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void genghuan();
    void move_peo();
    void peo_jump_set();
    ~MainWindow();
protected:
    void keyPressEvent( QKeyEvent *event);
    void paintEvent (QPaintEvent *event);

    void keyReleaseEvent( QKeyEvent *event);



private:
    Ui::MainWindow *ui;
    QPixmap *tu[4];
    QPixmap tu_peo_left;
    QPixmap tu_peo_right;
    QPixmap *tu_peo;
    QRect *tuq[4];
    QRect tuq_peo;

    int dq;
    QTimer *jishi,peo_jump_timer;
    bool jip,tdf,rdf,peo_jump;
    int tfang,rfang;
    public slots:
 void yidong();
};

#endif // MAINWINDOW_H
