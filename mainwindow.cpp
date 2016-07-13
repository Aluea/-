#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),dq(0),fang(0),jip(false),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tu[0]=new QPixmap(":/A1");
   tu[1]=new QPixmap(":/A2");
   tu[2]=new QPixmap(":/A3");
   tu[3]=new QPixmap(":/A4");
   tuq[0]=new QRect(0,0,800,250);
   tuq[1]=new QRect(800,0,800,250);
   tuq[2]=new QRect(0,0,800,250);
   tuq[3]=new QRect(0,0,800,250);
    jishi =new QTimer(this);
     connect( jishi,SIGNAL(timeout()),this,SLOT(yidong()));

}
void MainWindow::paintEvent (QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(*tuq[dq],*tu[dq]);
    painter.drawPixmap(*tuq[dq+1],*tu[dq+1]);
}
void MainWindow::keyPressEvent( QKeyEvent *event){
    char ch;
    ch=event->key();
    if(ch=='A'||ch=='a'){
        if(jip==false){
            fang=-1;
            jishi->start(10);
            jip=true;
        }
    }
    if(ch=='d'||ch=='D'){
        if(jip==false){
            fang=1;
            jishi->start(10);
            jip=true;
        }
    }


}
 void MainWindow::keyReleaseEvent( QKeyEvent *event){
    jishi->stop();
    fang=0;
    jip=false;
}

void MainWindow::yidong(){

    int width1,height1;
    int width = tuq[dq]->width ();
    int height=tuq[dq]->height();
    if(dq<4){ width1 = tuq[dq+1]->width ();
     height1=tuq[dq+1]->height();}
    switch(fang){
    case -1:tuq[dq]->setX(tuq[dq]->x()+3);tuq[dq+1]->setX(tuq[dq+1]->x()+3);break;
    case 1:tuq[dq]->setX(tuq[dq]->x()-3);tuq[dq+1]->setX(tuq[dq+1]->x()-3);break;
    }

    if(fang==-1){
        if(tuq[dq]->x()>=0&&dq>0){
            dq--;
            tuq[dq]->setX(-796);
            //~
        }
    }
    if(fang==1){
        if(tuq[dq]->x()+800<=0&&dq<4){
            dq++;
            tuq[dq+1]->setX(796);
        }
    }
    tuq[dq]->setWidth (width);
     tuq[dq]->setHeight(height);
    if(dq<4){ tuq[dq+1]->setWidth (width1);
      tuq[dq+1]->setHeight(height1);}
    update();
}

MainWindow::~MainWindow()
{
    delete ui;
}
