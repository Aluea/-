#ifndef M_IOS_H
#define M_IOS_H
#include <QtGui>
#include<QWidget>
#include<caster.h>
#define TI 10
class my_ios:public QWidget{
    Q_OBJECT
public:
    explicit my_ios(QWidget *parent = 0);

    ~my_ios();
protected:
    void keyPressEvent( QKeyEvent *event);
    void paintEvent (QPaintEvent *event);
// 读取事件
private:
    QPixmap *tu[15],*dtu[9];
    QRect *tuq[15],*dtuq[15];
     QTimer *jishi1,*jishi2,peo_jump_timer,peo_move_timer,key_mouse_timer;
     int fang;
     int dsf[100],wsf[3000];
   // 此处有图片
    //定时器和线程
    showturn st[3000];
    int count;
    int dq;
    bool peo_jump;

public slots:
     void peo_jump_set();
     void move();
     void key_bourd_fun();
     void face_to();

};
#endif
