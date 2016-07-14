#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>
#include <QMainWindow>
#include<qtimer.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    void genghuan();


    ~MainWindow();
protected:
    void keyPressEvent( QKeyEvent *event);
    void paintEvent (QPaintEvent *event);

<<<<<<< HEAD
    //void keyReleaseEvent( QKeyEvent *event);
=======
   // void keyReleaseEvent( QKeyEvent *event);
>>>>>>> 2c9ca98d72854e6edee47eacc40c5df8bbbe7f6c



private:
    Ui::MainWindow *ui;
    QPixmap *tu[5];
    QPixmap tu_peo_left;
    QPixmap tu_peo_right;
    QPixmap *tu_peo;
    QRect *tuq[5];
    QRect tuq_peo;
 struct ren{
    int x,y;
    int h,w;
 };
 ren hero;
    int dq;
    QTimer *jishi1,*jishi2,peo_jump_timer,peo_move_timer1,peo_move_timer2;
    bool jip,tdf,rdf,peo_jump,peo_move_pan;
    int tfang,rfang,rtd,ffang,ji;
    public slots:
 void yidong();
  void peo_jump_set();
  void peo_move();
  void ting();
};

#endif // MAINWINDOW_H
