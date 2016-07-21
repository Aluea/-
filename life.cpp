#include<life.h>
Life::Life(){
}
Life::~Life(){
}
int Life::getpic_id(int n) const{
    return id_pic[n];
}
int Life::get_id_count() const{
    return id_count;
}
void Life::set_a(int a_x,int a_y,int a_z){
    ax=a_x;
    ay=a_y;
    az=a_z;
}

void Life::cal_v(){
    vx+=ax;
    if(y>0){
        vy+=ay;
    }else{
        vy=0;
    }
    vz+=az;
}

void Life::cal_s(){
    x+=vx;
    if(y>0){
        y+=vy;
    }else{
        y=0;
    }
    z+=vz;
}
