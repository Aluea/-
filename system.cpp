#include<system.h>
#include<caster.h>
#include<m_map.h>

//typedef struct{
//    char name;//m为背景 p为人物
//    int x,y,width,height;
//}pic_new;
System::System(){
    pic_new lin;
    lin.name='m';
    lin.x=0;
    lin.y=0;
    lin.width=700;
    lin.height=350;
    lin.id_pic=0;
    new_prject(lin);
    lin.x=696;
    lin.id_pic=1;
    new_prject(lin);
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
            id=get_id('m');
            pic lin;
            lin.id=id;
            lin.x=obj.x;
            lin.y=obj.y;
            lin.width=obj.width;
            lin.height=obj.height;
            lin.show=true;
            id_map.insert(pair<int,pic>(id,lin));
            backgroubd.push_back(M_map(lin.id,obj.id_pic,lin.x,lin.y));
            break;
        case 'p'://人物
            id=get_id('p');

            break;
    }
}
int System::get_id(const char ch){
    switch(ch){
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
