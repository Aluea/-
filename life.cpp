#include<life.h>
 Life::Life(int state,int id,int x,int y,int z,int width,int height):
    id_count(state),x(x),y(y),idarea(id),z(z),width(width),height(height)
    {
        id_pic=new int[state];
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
