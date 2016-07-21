//#include<caster.h>
#include<arton.h>
Arton_base::Arton_base(){

}

Arton_base::~Arton_base(){

}
Arton_green::Arton_green(int x,int y,int z){
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
Arton_green::Arton_green(int x,int y,int z,int v_x=0,int v_y=0,int v_z=0){
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

void Arton_base::set_a(int a_x,int a_y,int a_z){
    this->a_x=a_x;
    this->a_y=a_y;
    this->a_z=a_z;
}
void Arton_base::set_v(int x,int y,int z){
    this->v_x=x;
    this->a_y=y;
    this->a_z=z;
}
 void Arton_base::set_xy(int x,int y,int z){
    this->x=x;
     this->y=y;
     this->z=z;
}

void Arton_base::cal_v(){
    v_x+=a_x;
    if(y>0){
        v_y+=a_y;
    }else{
        v_y=0;
    }
    v_z+=a_z;
}

void Arton_base::cal_s(){
    x+=v_x;
    if(y>0){
        y+=v_y;
    }else{
        y=0;
    }
    z+=v_z;
}
