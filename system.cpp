#include<system.h>

System::System():
    pic_now(0),rtd(0)
    {
        hero.set(2,0,335,270,0,67,67);
        area_id[0]=0;
        area_id_use[0]=true;
        hero.setid(0,0);
        hero.setid(1,1);

        new_prject('m',0,0,0,0,700,350,1,0);
        //area_id[1]=0;
        //area_id_use[1]=true;
        //background[0].set(0,0,0,0,700,350);

        new_prject('m',1,696,0,0,700,350,1,1);
        //area_id[2]=1;
        //area_id_use[2]=true;
        //background[1].set(1,1,696,0,700,350);
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


void System::new_prject(char type,int idarea,int x,int y,int z,int w,int h,int id_count,...){
    va_list arg_ptr;
    va_start(arg_ptr,id_count);
    int id_pic,i,idarea_n;
    switch(type){
        case 'm'://背景
            id_pic=va_arg(arg_ptr,int);
            for(i=0;i<AREA_ID_ALL;i++){
                if(!area_id_use[i]){
                    idarea_n=i;
                    break;
                }
            }
            for(i=0;i<BACKGROUND_ALL;i++){
                if(!background_use[i]){
                    break;
                }
            }
            background[i].set(idarea,id_pic,x,y,w,h);
            background_use[i]=true;
            area_id[idarea_n]=idarea;
            area_id_use[idarea_n]=true;
            break;
        case 'p'://人物与怪物

            for(i=0;i<AREA_ID_ALL;i++){
                if(!area_id_use[i]){
                    idarea_n=i;
                    break;
                }
            }
            for(i=0;i<PEOPLE_ALL;i++){
                if(!background_use[i]){
                    break;
                }
            }
            people[i].set(id_count,idarea,x,y,z,w,h);
            for(int j=0;i<id_count;j++){
                id_pic=va_arg(arg_ptr,int);
                people[i].setid(id_pic,j);
            }
            people_use[i]=true;
            area_id[idarea_n]=idarea;
            area_id_use[idarea_n]=true;
            break;
        case 'l'://粒子
            break;
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
    //lin.id_pic=0;//hero.getpic_id(fang);
    //lin.idarea=0;//hero.getarea_id();
    if(fang==-1){//定义面向左为0//右为1
        lin.id_pic=hero.getpic_id(0);
    }else if(fang==1){
        lin.id_pic=hero.getpic_id(1);
    }
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
