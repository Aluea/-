#include<m_ios.h>
#define FUN_JUMP(x) (1.8*(x)*(x)-36*(x)+175)
my_ios::my_ios(QWidget *parent):QWidget(parent){
    dtu[0]=new QPixmap(":/A1");
    dtu[1]=new QPixmap(":/A2");
    dtu[2]=new QPixmap(":/A3");
    dtu[3]=new QPixmap(":/A4");
    tu[0]=new QPixmap(":/R1");
    tu[1]=new QPixmap(":/R2");
    dtuq[0]=new QRect(0,0,800,250);
    dtuq[1]=new QRect(800,0,800,250);
    dtuq[2]=new QRect(0,0,800,250);
    dtuq[3]=new QRect(0,0,800,250);
    tuq[0]=new QRect(300,175,67,67);
    tuq[1]=new QRect(300,175,67,67);
    dq=0;peo_jump=false;
    for(int i=0;i<100;i++){
        if(i<=3)dsf[i]=1;
        else dsf[i]=0;
    }
    for(int i=0;i<3000;i++){
        if(i<=2)wsf[i]=i;   //值为载入那张图
        else wsf[i]=-1;
    }
    count=2;
    st[0].id=0;st[1].id=1;
}
void my_ios::paintEvent (QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(*dtuq[dq],*dtu[dq]);
    painter.drawPixmap(*dtuq[dq+1],*dtu[dq+1]);
    for(int i=0;i<count;i++){
        painter.drawPixmap(*tuq[st[i].id],*tu[wsf[st[i].id]]);
    }

}
my_ios::~my_ios(){

}
void my_ios::face_to(){
    QPoint aaa = cursor().pos();
    aaa=mapFromGlobal(aaa);

    update();
}
void my_ios::key_bourd_fun(){
    bool key[256]={false},flag=true;
    key['A']=GetKeyState('A')<0?true:false;
    key['S']=GetKeyState('S')<0?true:false;
    key['D']=GetKeyState('D')<0?true:false;
    key['W']=GetKeyState('A')<0?true:false;
    key[VK_SPACE]=GetKeyState(VK_SPACE);
    if(key['A']){
        fang=-1;
    }else if(key['D']){
        fang=1;
    }else if(key['S']){
        fang=-2;
    }else if(key['w']){
        fang=2;
    }else{
        flag=false;
    }
    if(flag){
        if(!peo_move_timer.isActive()){
            peo_move_timer.start(TI);
            //qDebug("hear\n");
        }
    }else{
        if(peo_move_timer.isActive()){
            peo_move_timer.stop();
        }
    }
}

void my_ios::keyPressEvent( QKeyEvent *event){

    char ch;
    ch=event->key();
    //qDebug("%d",rfang);

        switch(ch){
        case ' ':
        case 'w':
            if(peo_jump==false){
                peo_jump=true;
                peo_jump_timer.start(3*TI);
            }
            break;
    }
}
void my_ios::peo_jump_set(){
    const int all=20;
    static int cut=0;
    int y;
    cut++;
    //qDebug("%d",cut);
    y=FUN_JUMP(cut);
    if(wsf[0]>-1)tuq[0]->setRect(tuq[0]->x(),y,67,67);
    if(wsf[1]>-1)tuq[1]->setRect(tuq[1]->x(),y,67,67);
    if(cut==all){
        peo_jump_timer.stop();
        peo_jump=false;
        cut=0;
    }
    update();
}
/*void MainWindow::move(){
    while(){

    }
    update();
}*/

