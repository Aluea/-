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
