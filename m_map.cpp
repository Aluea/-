#include<m_map.h>
M_map::M_map(int id_pic_chuang,int id_pic,int x_win,int y_win):
    x_win(x_win),y_win(y_win),id_pic(id_pic),id_pic_chuang(id_pic_chuang)
    {

    }

M_map::~M_map(){

}
int M_map::get_id_pic_chuang() const{
    return id_pic_chuang;
}
int M_map::get_id_pic() const{
    return id_pic;
}
