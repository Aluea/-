#include<system.h>

System::System():
    pic_now(0),rtd(0){   
        show_zb=0;

        data.new_background(0,0,0,700,350,0);
        data.new_background(0,696,0,700,350,1);
        data.new_background(0,2*696,0,700,350,2);
        data.new_background(0,3*696,0,700,350,3);
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
     pic lin;int dq;
      dq=show_zb/696;
     lin.id_pic=data.hero.getpic_id(ft);
     lin.idarea=data.hero.getarea_id();
     lin.x=data.hero.x-show_zb;
     lin.y=data.hero.y;
     lin.h=data.hero.height;
     lin.w=data.hero.width;
     picture.push(lin);


     lin.idarea=data.data_f[0].background[dq].get_idarea();
     lin.id_pic=data.data_f[0].background[dq].get_id_pic();
     lin.x=data.data_f[0].background[dq].x-show_zb;
     lin.y=data.data_f[0].background[dq].y;
     lin.z=0;
     lin.w=700;
     lin.h=350;
     picture.push(lin);

     lin.idarea=data.data_f[0].background[dq+1].get_idarea();
     lin.id_pic=data.data_f[0].background[dq+1].get_id_pic();
     lin.x=data.data_f[0].background[dq+1].x-show_zb;
     lin.y=data.data_f[0].background[dq+1].y;
     lin.z=0;
     lin.w=700;
     lin.h=350;
     picture.push(lin);



}

void System::move(int fang,int hfang){
    if(fang==-1){
        if(rtd==0){
            if(data.hero.x-show_zb<=140){
                rtd=1;
                tu_move(fang);
            }
            else{
                peo_move(fang,0);
            }
        }
        if(rtd==1){
            if(data.hero.x-show_zb>=450){
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
            if(data.hero.x-show_zb>=500){
                rtd=1;
                tu_move(fang);
            }
            else{
                peo_move(fang,0);
            }
         }
         if(rtd==1){
            if(data.hero.x-show_zb<=300){
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
    data.hero.y+=hfang*2;


}

void System::tu_move(int fang){
    data.hero.x+=fang*2;
    show_zb+=fang*2;
}
