#include<system.h>

System::System():
    pic_now(0),rtd(0)
    {
        data.hero.set(2,0,335,250,0,67,67);
        data.data_f[0].area_id[0]=0;
        data.data_f[0].area_id_use[0]=true;
        data.hero.setid(100,0);
        data.hero.setid(101,1);

        data.new_prject('m',0,0,0,0,700,350,1,0);
        data.new_prject('m',1,696,0,0,700,350,1,1);
        data.new_prject('m',2,2*696,0,0,700,350,1,2);
        data.new_prject('m',3,3*696,0,0,700,350,1,3);
        ft=1;
    }

System::~System(){

}

void System::picture_push_one(char type,void * val){
    
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

    //lin.is_new=false;
    //lin.type=0;//人
   // lin.m_exit=true;

}
void System::input_stack(){
     pic lin;
    lin.id_pic=data.hero.getpic_id(ft);
    lin.idarea=data.hero.getarea_id();
    lin.x=data.hero.x;
    lin.y=data.hero.y;
    lin.h=data.hero.height;
    lin.w=data.hero.width;
    picture.push(lin);
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



void System::peo_move(int fang,int hfang){
    data.hero.x+=fang*2;

}

void System::tu_move(int fang){
    fang*=-1;

}
