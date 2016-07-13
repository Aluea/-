#include "mainwindow.h"
#include<iostream>
#include <QDebug>

#include "ui_mainwindow.h"
using namespace std;
#define TI 10
#define FUN_JUMP(x) (1.8*(x)*(x)-36*(x)+175)
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),dq(0),tfang(0),jip(false),tdf(false),rfang(1),tu_peo_left(":/r_l"),tu_peo_right(":/r_r"),
    tuq_peo(300,175,67,67),peo_jump(false),rtd(0),peo_move_pan(false),ffang(1),ji(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tu[0]=new QPixmap(":/A1");
   tu[1]=new QPixmap(":/A2");
   tu[2]=new QPixmap(":/A3");
   tu[3]=new QPixmap(":/A4");
   tu[4]=new QPixmap(":/A4");
   tu_peo=&tu_peo_right;
   tuq[0]=new QRect(0,0,800,250);
   tuq[1]=new QRect(800,0,800,250);
   tuq[2]=new QRect(0,0,800,250);
   tuq[3]=new QRect(0,0,800,250);
   tuq[4]=new QRect(0,0,800,250);
    jishi1 =new QTimer(this);
    jishi2 =new QTimer(this);
     connect( jishi1,SIGNAL(timeout()),this,SLOT(yidong()));
      connect( jishi2,SIGNAL(timeout()),this,SLOT(yidong()));
     connect(&peo_jump_timer,SIGNAL(timeout()),this,SLOT(peo_jump_set()));
      connect(&peo_move_timer1,SIGNAL(timeout()),this,SLOT(peo_move()));
      connect(&peo_move_timer2,SIGNAL(timeout()),this,SLOT(ting()));
    hero.x=300;
    hero.y=175;

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
    qDebug("%d",rfang);
    if(rtd==1){
      switch(ch){
      case 'a':
      case 'A':
          if(jip==false){
              rfang=tfang=-1;
              jishi1->start(TI);

              jip=true;
          }break;
      case 'W':
      case 'w':
          if(peo_jump==false){
              peo_jump=true;
              peo_jump_timer.start(0.5*TI);
          }
          break;
      case 'd':
      case 'D':
          if(jip==false){
              rfang=tfang=1;
              jishi2->start(TI);
              jip=true;
          }break;

      }
    }
    if(rtd==0){
        switch(ch){
        case 'a':
        case 'A':

           peo_move_timer2.start(485);
            rfang=-1;
            if(peo_move_pan==false){

               peo_move_timer1.start(TI);

                peo_move_pan=true;
            }break;
        case 'W':
        case 'w':

              peo_move_timer2.start(4000);
            if(peo_jump==false){
                peo_jump=true;
                peo_jump_timer.start(3*TI);
            }
            break;
        case 'd':
        case 'D':

               peo_move_timer2.start(485);
              rfang=1;
            if(peo_move_pan==false){

               peo_move_timer1.start(TI);

                peo_move_pan=true;

            }break;

        }
    }
    }

void MainWindow::ting(){
    qDebug("%d",rfang);
    peo_move_timer1.stop();
     peo_move_timer2.stop();
    peo_move_pan=false;
}
 /*void MainWindow::keyReleaseEvent( QKeyEvent *event){
   if(event->isAutoRepeat()==false){
         if(event->key()=='A'||event->key()=='a'||event->key()=='d'||event->key()=='D'){
          //qDebug("%c\n",event->key());
            if(rtd==1){
                if(event->key()=='A'||event->key()=='a')jishi1->stop();
               else jishi2->stop();
            tfang=0;
            jip=false;}
            if(rtd==0){
               if(event->key()=='A'||event->key()=='a')peo_move_timer1.stop();
                else peo_move_timer2.stop();

                peo_move_pan=false;
                qDebug("%d",rfang);
            }

         //qDebug("%d\n",23);
         //event->ignore();
        // Sleep(30);
            ji=0;
            keyPressEvent(event);

     }

}
}*/
void MainWindow::peo_jump_set(){
    const int all=20;
    static int cut=0;
    cut++;
    //qDebug("%d",cut);
    hero.y=FUN_JUMP(cut);
    tuq_peo.setRect(hero.x,hero.y,67,67);
    if(cut==all){
        peo_jump_timer.stop();
        peo_jump=false;
        cut=0;
    }
    update();
}

void MainWindow::yidong(){


    int bu=5;

   if((dq==0&&tuq[dq]->x()>0)||dq==4&&(tuq[dq]->x()+800<=604)){
       rtd=0;
   }
   else{


    switch(tfang){
    case -1:tuq[dq]->setRect(tuq[dq]->x()+2,0,800,250); tuq[dq+1]->setRect(tuq[dq+1]->x()+2,0,800,250);break;
    case 1:tuq[dq]->setRect(tuq[dq]->x()-2,0,800,250);tuq[dq+1]->setRect(tuq[dq+1]->x()-2,0,800,250);break;
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

    //move_peo();

    update();
}
}

void MainWindow::peo_move(){
   /* if(rfang==-1){//
        tuq_peo.setRect(hero.x,hero.y,67,67);
        tu_peo=&tu_peo_left;
    }else if(rfang==1){//右
        tuq_peo.setRect(hero.x,hero.y,67,67);
        tu_peo=&tu_peo_right;
    }*/

    switch(rfang){
    case 1:hero.x+=2;tuq_peo.setRect(hero.x,hero.y,67,67);tu_peo=&tu_peo_right;break;
    case -1:hero.x-=2;tuq_peo.setRect(hero.x,hero.y,67,67);tu_peo=&tu_peo_left;break;
}

     repaint();
}
MainWindow::~MainWindow()
{
    delete ui;
}
