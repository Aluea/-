#include<m_map.h>
M_map::M_map(int x,int y,int w,int h,int id):
    x(x),y(y),w(w),h(h),id_pic(id){

    }
M_map::~M_map(){

}
int M_map::get_id_pic() const{
    return id_pic;
}
