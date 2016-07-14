#include<m_map.h>
M_map::M_map(){

}

void M_map::set(int idarea,int id_pic,int x,int y,int w,int h):
    idarea(idarea),id_pic(id_pic),x(x),y(y),w(w),h(h)
    {

    }

M_map::~M_map(){

}
int M_map::get_idarea() const{
    return idarea;
}
int M_map::get_id_pic() const{
    return id_pic;
}
