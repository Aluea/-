#include<system.h>
#include<caster.h>
#include<m_map.h>
#include<life.h>

//typedef struct{
//    char name;//m为背景 p为人物
//    int x,y,width,height;
//}pic_new;

System::System():
    hera(2,0,335,370,0,67,67)
    {
    pic_now=0;
    pic_new lin;
    lin.name='m';
    lin.x=0;
    lin.y=0;
    lin.width=700;
    lin.height=350;
    lin.x=696;
    new_prject(lin);

    lin.x=696;
    lin.id_pic=1;
    new_prject(lin);

    lin.x=696;
    lin.id_pic=2;
    new_prject(lin);

    lin.width=67;
    lin.height=67;
    lin.x=335;
    lin.y=270;
    lin.name='p';
//    new_prject(lin);

    int id=get_id('p');
    pic lin_pic;
    lin_pic.id_area=id;
    lin_pic.x=lin.x;
    lin_pic.y=lin.y;
    lin_pic.width=lin.width;
    lin_pic.height=lin.height;
    lin_pic.show=true;
    lin_pic.type='p';
    lin_pic.z=0;
    id_peo.insert(pair<int,pic>(id,lin_pic));
    Life peo(2,lin_pic.id_area,lin_pic.x,lin_pic.y,0,lin_pic.width,lin_pic.height);
    hero=peo;
    for(int i=0;i<peo.get_id_count();i++){
        peo.setid(i,i);
    }
    people.push_back(hero);

}

System::~System(){

}

void System::key_in(const char key_val,int key_now/*-1*/){

}

void System::mouse_in(int mouse_x,int mouse_y,int mouse_now){

}
stack<pic>* System::redrew_background(){
    int id=background[pic_now].get_id_pic_chuang();
    picture.push((id_map.find(id))->second);
    id=background[pic_now+1].get_id_pic_chuang();
    picture.push(id_map.find(id)->second);
    return &picture;
}

stack<pic>* System::redrew(){

}

stack<pic_new>* System::get_new_project(){

}

void System::calculate(){

}
void System::peo_move(FANG fang){

}

void System::new_prject(pic_new& obj){
    int id;
    pic lin;
    switch(obj.name){
        case 'm'://背景
            id=get_id('m');
            lin.id_area=id;
            lin.x=obj.x;
            lin.y=obj.y;
            lin.width=obj.width;
            lin.height=obj.height;
            lin.show=true;
            lin.type='m';
            lin.z=100;
            id_map.insert(pair<int,pic>(id,lin));
            background.push_back(M_map(lin.id_area,obj.id_pic,lin.x,lin.y));
            break;
        case 'p'://人物
            id=get_id('p');
            lin.id_area=id;
            lin.x=obj.x;
            lin.y=obj.y;
            lin.width=obj.width;
            lin.height=obj.height;
            lin.show=true;
            lin.type='p';
            lin.z=0;
            id_peo.insert(pair<int,pic>(id,lin));
            Life peo(2,lin.id_area,lin.x,lin.y,0,lin.width,lin.height);
            for(int i=0;i<peo.get_id_count();i++){
                peo.setid(i,i);
            }
            people.push_back(peo);
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

void System::move(int fang){
if(fang==-1){
if(rtd==0){
if(hero.x<=140){
    rtd=1;
    tu_move(fang);
}
else{
    peo_move(fang);
}

}
if(rtd==1){
if(hero.x>=450){
    rtd=0;
    peo_move(fang);
}
else{
    tu_move(fang);
}
}
}
if(fang==1){
if(rtd==0){
if(hero.x>=500){
    rtd=1;
    tu_move(fang);
}
else{
    peo_move(fang);
}
}
if(rtd==1){
if(hero.x<=300){
    rtd=0;
    peo_move(fang);
}
else{
    tu_move(fang);
}
}
}
}
void System::peo_move(int fang){
hero.x+=fang;
}

void System::tu_move(int fang){
if(fang==-1){
if(backgroubd[picnow].x>=0&&picnow>0){
picnow--;
backgroubd[picnow].x=-696;
//~
}
}
if(fang==1){
if(backgroubd[picnow].x+700<=0&&picnow<4){
picnow--;
backgroubd[picnow+1].x=696;
}
}
}
