#include<m_map.h>
M_map::M_map(){

}

void M_map::set(int idarea,int id_pic,int x,int y,int w,int h){
    this->idarea=(idarea);
    this->id_pic=(id_pic);
    this->x=(x);
    this->y=(y);
    this->w=(w);
    this->h=(h);
}

M_map::~M_map(){

}
int M_map::get_idarea() const{
    return idarea;
}
int M_map::get_id_pic() const{
    return id_pic;
}
