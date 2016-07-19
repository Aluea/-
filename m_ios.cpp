#include<m_ios.h>
#define FUN_JUMP(x) (1.8*(x)*(x)-36*(x)+250)
my_ios::my_ios(QWidget *parent):QWidget(parent){
    tu[0]=new QPixmap(":/A1");
    tu[1]=new QPixmap(":/A2");
    tu[2]=new QPixmap(":/A3");
    tu[3]=new QPixmap(":/A4");
    tu[100]=new QPixmap(":/R1");
    tu[101]=new QPixmap(":/R2");
    tuq[0]=new QRect(0,0,800,350);
    tuq[1]=new QRect(800,0,800,350);
    tuq[2]=new QRect(0,0,800,350);
    tuq[3]=new QRect(0,0,800,350);
    tuq[100]=new QRect(335,250,67,67);
    tuq[101]=new QRect(335,250,67,67);
    //dq=0;peo_jump=false;
      sys=new System;
    count=2;yan=0;
    st[0].id=0;st[1].id=1;st[0].pic=0;st[1].pic=1;
    //connect(&peo_jump_timer,SIGNAL(timeout()),this,SLOT(peo_jump_set()));
    connect(&peo_move_timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(&key_mouse_timer,SIGNAL(timeout()),this,SLOT(face_to()));
    connect(&key_mouse_timer,SIGNAL(timeout()),this,SLOT(key_bourd_fun()));
    connect(&show_time,SIGNAL(timeout()),this,SLOT(m_show()));
        show_time.start(10);
        key_mouse_timer.start(30);
}
void my_ios::paintEvent (QPaintEvent *event){
    QPainter painter(this);
   // painter.drawPixmap(*dtuq[dq],*dtu[dq]);
    //painter.drawPixmap(*dtuq[dq+1],*dtu[dq+1]);
    for(int i=0;i<count;i++){
      painter.drawPixmap(*tuq[st[i].id],*tu[st[i].pic]);
    }

}
void my_ios::m_show(){
    pic lin;count=0;
    sys->input_stack();
    while(!sys->picture.empty()){
        lin=sys->picture.top();
        sys->picture.pop();
        st[count].id=lin.idarea;
        tuq[st[count].id]->setRect(lin.x,lin.y,lin.w,lin.h);
        st[count].pic=lin.id_pic;
        st[count++].z=lin.z;
    }
    //sort(st,st+count,cmp);
    update();
}
void my_ios::move(){
     sys->move(fang,hfang);
}

my_ios::~my_ios(){

}
void my_ios::face_to(){
    //yan++;
    //if(yan==3){
       // yan=0;
    QPoint aaa = cursor().pos();
    aaa=mapFromGlobal(aaa);
    if(aaa.x()>=sys->data.hero.x-sys->show_zb)sys->face_to(1);
    else sys->face_to(0);

   // }
}
void my_ios::key_bourd_fun(){
    bool key[256]={false},flag=true;
    key['A']=GetKeyState('A')<0?true:false;
    key['S']=GetKeyState('S')<0?true:false;
    key['D']=GetKeyState('D')<0?true:false;
    key['W']=GetKeyState('W')<0?true:false;
    key[VK_SPACE]=GetKeyState(VK_SPACE);

            flag=false;fang=0;hfang=0;

    if(key['A']){
        fang=-1;flag=true;
    }else if(key['D']){
        fang=1;flag=true;
    }
    if(key['W']){
        hfang=-1;flag=true;
    }else if(key['S']){
        hfang=1;flag=true;
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

            //if(peo_jump==false){
           //     peo_jump=true;
           //    peo_jump_timer.start(3*TI);

            break;
    }
}

/*void my_ios::peo_jump_set(){
    const int all=20;
    static int cut=0;
    int y;
    cut++;
    //qDebug("%d",cut);
    y=FUN_JUMP(cut);
    if(wsf[0]>0)tuq[0]->setRect(tuq[0]->x(),y,67,67);
    if(wsf[1]>0)tuq[1]->setRect(tuq[1]->x(),y,67,67);
    if(cut==all){
        peo_jump_timer.stop();
        peo_jump=false;
        cut=0;
    }
    update();
}
void my_ios::move(){
     sys.move(fang,hfang);
             pic lin;

             int l_c,jianshu=0,jiashu=0;
     lin=sys.picture.top();
     if(lin.type==0){l_c=0;
     while(!sys.picture.empty()){

         lin=sys.picture.top();
         sys.picture.pop();
         if(lin.m_exit==0){

         }
         st[l_c].id=lin.idarea;
         st[l_c++].pic=lin.id_pic;
         tuq[lin.idarea]->setRect(lin.x,lin.y,lin.w,lin.h);//未尽全功



     }
     else{
        sys.data.picture.pop();
        dq=lin.idarea;
        dtuq[dq]->setRect(lin.x,lin.y,lin.w,lin.h);
        lin=sys.data.picture.top();
        dtuq[dq+1]->setRect(lin.x,lin.y,lin.w,lin.h);
        while(!sys.data.picture.empty())sys.data.picture.pop();
     }
     update();

}*/

