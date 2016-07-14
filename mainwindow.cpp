#include "mainwindow.h"
#include <QDebug>
#include<qtimer.h>
#include<QKeyEvent>
#include "ui_mainwindow.h"
#include<iostream>
using namespace std;
#define TI 5
#define FUN_JUMP(x) (1.8*(x)*(x)-36*(x)+175)
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),dq(0),tfang(0),jip(false),tdf(false),rfang(1),tu_peo_left(":/r_l"),tu_peo_right(":/r_r"),
    tuq_peo(300,175,67,67),peo_jump(false),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tu[0]=new QPixmap(":/A1");
   tu[1]=new QPixmap(":/A2");
   tu[2]=new QPixmap(":/A3");
   tu[3]=new QPixmap(":/A4");
   tu_peo=&tu_peo_right;
   tuq[0]=new QRect(0,0,800,250);
   tuq[1]=new QRect(800,0,800,250);
   tuq[2]=new QRect(0,0,800,250);
   tuq[3]=new QRect(0,0,800,250);
    jishi =new QTimer(this);
     connect( jishi,SIGNAL(timeout()),this,SLOT(yidong()));
     connect(&peo_jump_timer,SIGNAL(timeout()),this,SLOT(peo_jump_set()));
}
void MainWindow::paintEvent (QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(*tuq[dq],*tu[dq]);
    painter.drawPixmap(*tuq[dq+1],*tu[dq+1]);
    painter.drawPixmap(tuq_peo,*tu_peo);

}
void MainWindow::keyPressEvent( QKeyEvent *event){
    char ch;
    ch=event->key();
      switch(ch){
      case 'a':
      case 'A':
          if(jip==false){
              rfang=tfang=-1;
              jishi->start(TI);
              jip=true;
          }break;
      case 'W':
      case 'w':
          if(peo_jump==false){
              peo_jump=true;
              peo_jump_timer.start(5*TI);
          }
          break;
      case 'd':
      case 'D':
          if(jip==false){
              rfang=tfang=1;
              jishi->start(TI);
              jip=true;
          }break;

      }
}
// void MainWindow::keyReleaseEvent( QKeyEvent *event){
//     if(event->isAutoRepeat()==false){
//         if(event->key()=='A'||event->key()=='a'||event->key()=='d'||event->key()=='D'){
//            //jishi->stop();
//            //tfang=0;
//             tfang=-2;
//             jip=false;
//         }
//     }

//}
void MainWindow::peo_jump_set(){
    const int all=20;
    static int cut=0;
    cut++;
    //qDebug("%d",cut);
    tuq_peo.setRect(tuq_peo.x(),FUN_JUMP(cut),67,67);
    if(cut==all){
        peo_jump_timer.stop();
        peo_jump=false;
        cut=0;
    }
    update();
}

void MainWindow::yidong(){
    int bu=5;//每键位移量
    const int all=100;
    static int cut=0;
    cut++;
    int width1,height1;
    int width = tuq[dq]->width ();
    int height=tuq[dq]->height();
    if(dq<4){ width1 = tuq[dq+1]->width ();
     height1=tuq[dq+1]->height();}

    switch(tfang){
        case -1:tuq[dq]->setX(tuq[dq]->x()+2);tuq[dq+1]->setX(tuq[dq+1]->x()+2);break;
        case 1:tuq[dq]->setX(tuq[dq]->x()-2);tuq[dq+1]->setX(tuq[dq+1]->x()-2);break;
    }

    if(tfang==-1){
        if(tuq[dq]->x()>=0&&dq>0){
            dq--;
            tuq[dq]->setX(-796);
            //~
        }
    }
    if(tfang==1){
        if(tuq[dq]->x()+800<=0&&dq<4){
            dq++;
            tuq[dq+1]->setX(796);
        }
    }
    tuq[dq]->setWidth (width);
     tuq[dq]->setHeight(height);
    if(dq<4){ tuq[dq+1]->setWidth (width1);
      tuq[dq+1]->setHeight(height1);}
    move_peo();
    if(cut==all){
        //jishi->stop();
        tfang=-2;
        jishi->changeInterval(10);
        jip=false;
        cut=0;
    }
    update();
}

void MainWindow::move_peo(){
    if(rfang==-1){//
        tuq_peo.setRect(300,tuq_peo.y(),67,67);
        tu_peo=&tu_peo_left;
    }else if(rfang==1){//右
        tuq_peo.setRect(300,tuq_peo.y(),67,67);
        tu_peo=&tu_peo_right;
    }else if(rfang==0){

    }

    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
