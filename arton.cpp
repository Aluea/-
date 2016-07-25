//#include<caster.h>
#include<arton.h>
Arton_base::Arton_base(){
    x=y=z=0;
    v_x=v_y=v_z=0;
    a_x=a_y=a_z=0;
}

Arton_base::~Arton_base(){

}
void Arton_base::smail_v(){
    v_x*=0.71;
    v_y*=0.71;
    v_z*=0.71;
}
void Arton_base::smail_v(double c){
    int x,y,z;
    if(v_x>0)x=1;
    else x=-1;
    if(abs(v_x)-c>0)v_x=(abs(v_x)-c)*x;
    else v_x=0;
    if(v_y>0)y=1;
    else y=-1;
    if(abs(v_y)-c>0)v_y=(abs(v_y)-c)*y;
    else v_y=0;
    if(v_z>0)z=1;
    else z=-1;
    if(abs(v_z)-c>0)v_z=(abs(v_z)-c)*z;
    else v_z=0;
}

Arton_green::Arton_green(double x, double y, double z){
    id_count=1;
    id_pic=new int[id_count];
    id_pic[0]=200;
    size=15;
    state=0;
    this->x=x;
    this->y=y;
    this->z=z;
    v_x=v_y=v_z=0;
    a_x=a_y=a_z=0;
}
Arton_green::Arton_green(double x, double y, double z, double v_x=0, double v_y=0, double v_z=0){
    id_count=1;
    id_pic=new int[id_count];
    id_pic[0]=200;
     size=50;
     state=0;
    this->x=x;
    this->y=y;
    this->z=z;
    this->v_x=v_x;
    this->v_y=v_y;
    this->v_z=v_z;
    a_x=a_y=a_z=0;
}

Arton_green::~Arton_green(){
    delete[] id_pic;
}
int Arton_base::get_id_pic(){
    return id_pic[state];
}

void Arton_base::set_a(double a_x, double a_y, double a_z){
    this->a_x=a_x;
    this->a_y=a_y;
    this->a_z=a_z;
}
void Arton_base::set_v(double x, double y, double z){
    this->v_x=x;
    this->a_y=y;
    this->a_z=z;
}
 void Arton_base::set_xy(double x, double y, double z){
    this->x=x;
     this->y=y;
     this->z=z;
}

void Arton_base::cal_v(){
    v_x+=a_x*0.3;
    v_y+=a_y*0.3;
    v_z+=a_z*0.3;
}

void Arton_base::cal_s(){
    x+=v_x;
    y+=v_y;
    z+=v_z;
    if(z<0){
        z=0;
    }
    if(y<0){
        y=0;
    }



}
