#include<system.h>

System::System():
    pic_now(0),rtd(0)
    {
        data.hero.set(2,0,335,250,0,67,67);
        data.area_id[0]=0;
        data.area_id_use[0]=true;
        data.hero.setid(0,0);
        data.hero.setid(1,1);

        data.new_prject('m',0,0,0,0,700,350,1,0);
        data.new_prject('m',1,696,0,0,700,350,1,1);
        data.new_prject('m',2,696,0,0,700,350,1,2);
        data.new_prject('m',3,696,0,0,700,350,1,3);
        ft=1;
    }

System::~System(){

}

void System::key_in(const char key_val,int key_now/*-1*/){

}

void System::mouse_in(int mouse_x,int mouse_y,int mouse_now){
}

//stack<pic_new>* System::get_new_project(){

//}

void System::calculate(){

}

void System::face_to(int fang){
    ft=fang;
    pic lin;
    lin.is_new=false;
    lin.type=0;//人
    lin.m_exit=true;
    lin.id_pic=data.hero.getpic_id(ft);
    lin.idarea=data.hero.getarea_id();
    lin.x=data.hero.x;
    lin.y=data.hero.y;
    lin.h=data.hero.height;
    lin.w=data.hero.width;
    data.picture.push(lin);
}

void System::move(int fang,int hfang){
    if(fang==-1){
        if(rtd==0){
            if(data.hero.x<=140){
                rtd=1;
                tu_move(fang);
            }
            else{
                peo_move(fang,0);
            }
        }
        if(rtd==1){
            if(data.hero.x>=450){
                rtd=0;
                peo_move(fang,0);
            }
            else{
                tu_move(fang);
            }
        }
    }
    if(fang==1){
        if(rtd==0){
            if(data.hero.x>=500){
                rtd=1;
                tu_move(fang);
            }
            else{
                peo_move(fang,0);
            }
         }
         if(rtd==1){
            if(data.hero.x<=300){
                rtd=0;
                peo_move(fang,0);
            }
            else{
                tu_move(fang);
            }
        }
    }
    if(hfang==-1){
        peo_move(0,hfang);
    }
    if(hfang==1){
        peo_move(0,hfang);
    }

}
<<<<<<< HEAD
void System::peo_move(int fang,int hfang){
    hero.x+=fang*2;
    hero.y+=hfang*2;
=======
void System::peo_move(int fang){
    data.hero.x+=fang*2;
>>>>>>> 48d4e096ecdb3b267a07525a6de53014a0bed128
    pic lin;
    lin.is_new=false;
    lin.type=0;//人
    lin.m_exit=true;
    lin.id_pic=data.hero.getpic_id(ft);
    lin.idarea=data.hero.getarea_id();
    lin.x=data.hero.x;
    lin.y=data.hero.y;
    lin.h=data.hero.height;
    lin.w=data.hero.width;
    data.picture.push(lin);
}

void System::tu_move(int fang){
    fang*=-1;
    data.background[pic_now].x+=fang*2;
    data.background[pic_now+1].x+=fang*2;
    //if(fang==-1){
        if(data.background[pic_now].x>=0&&pic_now>0){
            pic_now--;
            data.background[pic_now].x=-696;
            //~
        }
    //}
    //if(fang==1){
        if(data.background[pic_now].x+700<=0&&pic_now<4){
            pic_now++;
            data.background[pic_now+1].x=696;
        }
   // }
    //qDebug("pic_now=%d fang=%d",pic_now,fang);
    pic lin;
    lin.is_new=false;
    lin.type=1;//图
    lin.m_exit=true;
    lin.id_pic=data.background[pic_now+1].get_id_pic();
    lin.idarea=data.background[pic_now+1].get_idarea();
    lin.x=data.background[pic_now+1].x;
    lin.y=data.background[pic_now+1].y;
    lin.h=data.background[pic_now+1].h;
    lin.w=data.background[pic_now+1].w;
    data.picture.push(lin);

    lin.is_new=false;
    lin.type=1;//图
    lin.m_exit=true;
    lin.id_pic=data.background[pic_now].get_id_pic();
    lin.idarea=data.background[pic_now].get_idarea();
    lin.x=data.background[pic_now].x;
    lin.y=data.background[pic_now].y;
    lin.h=data.background[pic_now].h;
    lin.w=data.background[pic_now].w;
    data.picture.push(lin);
}
