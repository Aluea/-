#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),dq(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tu[0]=new QPixmap(":/A1");
   tu[1]=new QPixmap(":/A2");
   tu[2]=new QPixmap(":/A3");
   tu[3]=new QPixmap(":/A4");
   tu_peo_left=new QPixmap(":/r_l");
   tuq[0]=new QRect(0,0,800,250);
   tuq[1]=new QRect(800,0,800,250);
   tuq[2]=new QRect(0,0,800,250);
   tuq[3]=new QRect(0,0,800,250);
   tuq_peo=new QRect(300,175,50,75);
}
void MainWindow::paintEvent (QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(*tuq[dq],*tu[dq]);
    painter.drawPixmap(*tuq[dq+1],*tu[dq+1]);
    painter.drawPixmap(*tuq_peo,*tu_peo_left);
}
void MainWindow::keyPressEvent( QKeyEvent *event){
    char ch;
    ch=event->key();
    int bu=5;//每键位移量
    int width1,height1;
    int width = tuq[dq]->width ();
    int height=tuq[dq]->height();
    if(dq<4){ width1 = tuq[dq+1]->width ();
     height1=tuq[dq+1]->height();}
    switch(ch){
    case 'a':
    case 'A':
        tuq[dq]->setX(tuq[dq]->x()+bu);
        tuq[dq+1]->setX(tuq[dq+1]->x()+bu);
        break;
    case 'd':
    case 'D':
        tuq[dq]->setX(tuq[dq]->x()-bu);
        tuq[dq+1]->setX(tuq[dq+1]->x()-bu);
        break;
    }

    if(event->key()=='A'||event->key()=='a'){
        if(tuq[dq]->x()>=0&&dq>0){
            dq--;
            tuq[dq]->setX(-796);
            //~
        }
    }
    if(event->key()=='D'||event->key()=='d'){
        if(tuq[dq]->x()+800<=0&&dq<4){
            dq++;
            tuq[dq+1]->setX(796);
        }
    }
    tuq[dq]->setWidth (width);
     tuq[dq]->setHeight(height);
    if(dq<4){ tuq[dq+1]->setWidth (width1);
      tuq[dq+1]->setHeight(height1);}
    move_peo(ch);
    update();
}

void MainWindow::move_peo(char ch){
    int width=tu_peo_left->width();
    int height=tu_peo_left->height();
    if(ch=='d'||ch=='D'){

    }else if(ch=='a'||ch=='A'){

    }else if(ch=='w'||ch=='W'){

    }
    tuq_peo->setX(400);
    tuq_peo->setWidth(width);
    tuq_peo->setHeight(height);
    //update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
