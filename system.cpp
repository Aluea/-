#include<system.h>
#include<caster.h>
#include<m_map.h>
#include<life.h>

//typedef struct{
//    char name;//m为背景 p为人物
//    int x,y,width,height;
//}pic_new;

System::System():
    pic_now(0),rtd(0)
    {
        hero.set(2,0,335,270,0,67,67);
        area_id[0]=0;
        area_id_use[0]=true;
        hero.setid(0,0);
        hero.setid(1,1);

        area_id[1]=0;
        area_id_use[1]=true;
        background[0].set(0,0,0,0,700,350);

        area_id[2]=1;
        area_id_use[2]=true;
        background[1].set(1,1,696,0,700,350);
    }

System::~System(){

}

void System::key_in(const char key_val,int key_now/*-1*/){

}

void System::mouse_in(int mouse_x,int mouse_y,int mouse_now){

}
stack<pic>* System::redrew_background(){

}

stack<pic>* System::redrew(){

}

//stack<pic_new>* System::get_new_project(){

//}

void System::calculate(){

}


void System::new_prject(){

}
int System::get_id(){
    for(int i=0;i<3000;i++){
        if(!area_id_use){
            return i;
        }
    }
}

void System::move(int fang){
    if(fang==-1){
        if(rtd==0){
            if(hero.x<=140){
                rtd=1;
                tu_move(fang);
            }
            else{
                peo_move(fang);
            }
        }
        if(rtd==1){
            if(hero.x>=450){
                rtd=0;
                peo_move(fang);
            }
            else{
                tu_move(fang);
            }
        }
    }
    if(fang==1){
        if(rtd==0){
            if(hero.x>=500){
                rtd=1;
                tu_move(fang);
            }
            else{
                peo_move(fang);
            }
         }
         if(rtd==1){
            if(hero.x<=300){
                rtd=0;
                peo_move(fang);
            }
            else{
                tu_move(fang);
            }
        }
    }
}
void System::peo_move(int fang){
    hero.x+=fang;
    pic lin;
    lin.is_new=false;
    lin.type=0;//人
    lin.m_exit=true;
    lin.id_pic=hero.getpic_id(fang);
    lin.idarea=hero.getarea_id();
    lin.x=hero.x;
    lin.y=hero.y;
    lin.h=hero.height;
    lin.w=hero.width;
    picture.push(lin);
}

void System::tu_move(int fang){
    background[pic_now].x+=fang*2;
    background[pic_now+1].x+=fang*2;
    if(fang==-1){
        if(background[pic_now].x>=0&&pic_now>0){
            pic_now--;
            background[pic_now].x=-696;
            //~
        }
    }
    if(fang==1){
        if(background[pic_now].x+700<=0&&pic_now<4){
            pic_now--;
            background[pic_now+1].x=696;
        }
    }
    pic lin;
    lin.is_new=false;
    lin.type=1;//图
    lin.m_exit=true;
    lin.id_pic=background[pic_now+1].get_id_pic();
    lin.idarea=background[pic_now+1].get_idarea();
    lin.x=background[pic_now+1].x;
    lin.y=background[pic_now+1].y;
    lin.h=background[pic_now+1].h;
    lin.w=background[pic_now+1].w;
    picture.push(lin);

    lin.is_new=false;
    lin.type=1;//图
    lin.m_exit=true;
    lin.id_pic=background[pic_now].get_id_pic();
    lin.idarea=background[pic_now].get_idarea();
    lin.x=background[pic_now].x;
    lin.y=background[pic_now].y;
    lin.h=background[pic_now].h;
    lin.w=background[pic_now].w;
    picture.push(lin);
}
