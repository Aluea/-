#include<calculate.h>
void cal::m_search(){

}

void cal::shouli(){
    if(datas->hero.y>0)datas->hero.ay=-2;
    if(datas->hero.y<0){
        datas->hero.ay=0;
        datas->hero.vy=0;
        datas->hero.y=0;
    }
}

void cal::sudujs(){
    datas->hero.vy+=datas->hero.ay;
}

void cal::weizhijs(){
    if(datas->hero.y+datas->hero.vy<0){
        datas->hero.y=0;
    }
    else datas->hero.y+=datas->hero.vy;
}
