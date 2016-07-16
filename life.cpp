#include<life.h>
 void Life::set(int state,int id,int x,int y,int z,int width,int height)   {
    id_pic=new int[state];
    id_count=(state);
    this->x=(x);
    this->y=(y);
    this->idarea=(id);
    this->z=(z);
    this->width=(width);
    this->height=(height);
}

Life::~Life(){
    delete[] id_pic;
}
void Life::setid(int id,int n){
    id_pic[n]=id;
}

int Life::getpic_id(int x){
    return id_pic[x];
}

int Life::getarea_id(){
    return idarea;
}

int Life::get_id_count(){
    return id_count;
}
