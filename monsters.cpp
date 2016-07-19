#include<monsters.h>

Hero::Hero(){
    x=335;
    y=0;
    z=230;
    width=67;
    height=67;
    id_pic=new int[2];
    id_pic[0]=100;
    id_pic[1]=101;
}
Hero::Hero(int x,int y,int z,int w,int h){
    this->x=x;
    this->y=y;
    this->z=z;
    this->width=w;
    this->height=h;
    id_pic=new int[2];
    id_pic[0]=100;
    id_pic[1]=101;
}
Hero::~Hero(){
    delete[] id_pic;
}

Monster_0::Monster_0(){

}

Monster_0::~Monster_0(){

}


