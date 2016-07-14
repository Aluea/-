#include<system.h>
#include<caster.h>
#include<m_map.h>

System::System(){

}

System::~System(){

}

void System::key_in(const char key_val,int key_now/*-1*/){

}

void System::mouse_in(int mouse_x,int mouse_y,int mouse_now){

}

stack<pic>& System::redrew(){

}
stack<pic_new>& System::get_new_project(){

}

void System::calculate(){

}
void System::peo_move(FANG fang){

}

void System::new_prject(pic_new& obj){
    int id;
    switch(obj.name){
        case 'm'://背景
            id=get_id_empty('m');
            pic lin;
            lin.id=id;
            lin.x=0;
            lin.y=0;
            lin.width=1080;
            lin.height=720;
            lin.show=true;
            id_map.insert(pair<int,pic>(id,lin));
            break;
        case 'p'://人物
            id=get_id_empty('p');
            break;
    }
}
int System::get_id_empty(const char ch){
    switch(obj.name){
        case 'm'://背景
            if(id_map_empty.empty()){
                return id_map_max++;
            }else{
                int ret=id_map_empty.top();
                id_map_empty.pop();
                return ret;
            }
            break;
        case 'p'://人物
            if(id_peo_empty.empty()){
                return id_peo_max++;
            }else{
                int ret=id_peo_empty.top();
                id_peo_empty.pop();
                return ret;
            }
            break;
    }
}
