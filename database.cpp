#include<database.h>
data_in::data_in(){
    for(int i=0;i<200;i++){
        for(int j=0;j<18;j++){
            map_count[i][j]=0;
        }
    }
}
bool pic_all::operator ==(const pic_all &lin){
    if((this->id==lin.id) && (this->type==lin.type)){
        return true;
    }
    return false;
}

Database::Database(){
    hear=0;
    //hero=new Hero();
    data_f[hear].people[0]=&hero;
    data_f[hear].people_use[0]=true;
    /*data_f[hear].map[int(hero.x/DIS)][int(hero.y/DIS)][0].type=-1;
    data_f[hear].map[int(hero.x/DIS)][int(hero.y/DIS)][0].id=0;
    data_f[hear].map_count[int(hero.x/DIS)][int(hero.y/DIS)]++;*/
    //data_f=new data_in;
}
Database::~Database(){
    //delete hero;
}

void swap(pic_all& a,pic_all& b){
    pic_all c;
    c=a;
    a=b;
    b=c;
}

void Database::new_project(int type,int x,int y,int z,int v){
    int id;
    Life* lin;
    Arton_base* lin_a;
    switch (type){
//      case (-1)://英雄
        case(0)://怪物_0
            for(int i=0;i<PEOPLE_ALL;i++){
                if(!data_f[hear].people_use[i]){
                    id=i;
                     data_f[hear].people_use[id]=true;
                     break;
                }
            }

            lin=data_f[hear].people[id]=new Monster_0();
            x=lin->x/DIS;
            y=lin->y/DIS;
            data_f[hear].map[x][y][data_f[hear].map_count[x][y]++];
            break;
        case (100)://粒子 green
            for(int i=0;i<ARTON_ALL;i++){
                if(!data_f[hear].arton_use[i]){
                    id=i;
                    data_f[hear].arton_use[id]=true;
                    break;
                }
            }

            lin_a=data_f[hear].arton[id]=new Arton_green(x,y,z);
            lin_a->v_x=v;
            x=lin_a->x/DIS;
            y=lin_a->y/DIS;
           // qDebug("%d %d",x,y);
            data_f[hear].map[x][y][data_f[hear].map_count[x][y]].id=id; //dns
            data_f[hear].map[x][y][data_f[hear].map_count[x][y]].type=type;
            data_f[hear].map_count[x][y]++;
            //qDebug("%d",data_f[hear].map_count[x][y]);
            break;

    }
}
void Database::new_background(int hear,int x,int y,int w,int h,int pic_id){
    for(int i=0;i<BACKGROUND_ALL;i++){
        if(data_f[hear].background_use[i]==false){
            data_f[hear].background[i]=new M_map(x,y,w,h,pic_id);
            data_f[hear].background_use[i]=true;
            break;
        }
    }
}

void Database::del_project(const pic_all& obj){
    int x,y;
    switch (obj.type){
        case (-1)://英雄
        case (0)://怪物
            data_f[hear].people_use[obj.id]=false;
            x=data_f[hear].people[obj.id]->x/DIS;
            y=data_f[hear].people[obj.id]->y/DIS;
            for(int i=0;i<data_f[hear].map_count[x][y];i++){
                if(data_f[hear].map[x][y][i]==obj){
                    swap(data_f[hear].map[x][y][i],data_f[hear].map[x][y][ --data_f[hear].map_count[x][y] ]);
                    break;
                }
            }
            break;

    }
}
void Database::move_project(const pic_all& obj,int x_old,int y_old){
    int x,y;
    x_old/=DIS;
    y_old/=DIS;
    switch(obj.type){
        case (-1)://英雄
        case (0)://怪物
            x=data_f[hear].people[obj.id]->x/DIS;
            y=data_f[hear].people[obj.id]->y/DIS;
            for(int i=0;i<data_f[hear].map_count[x][y];i++){
                if(data_f[hear].map[x_old][y_old][i]==obj){
                    swap(data_f[hear].map[x_old][y_old][i],data_f[hear].map[x_old][y_old][ --data_f[hear].map_count[x_old][y_old] ]);
                    break;
                }
            }
            swap(data_f[hear].map[x_old][y_old][ data_f[hear].map_count[x_old][y_old] ],data_f[hear].map[x][y][ data_f[hear].map_count[x][y]++ ]);
            break;
    }

}

void Database::move_project(int type,int id,int x_old,int y_old){
    pic_all lin;
    lin.type=type;
    lin.id=id;
    move_project(lin,x_old,y_old);
}
void* Database::find_type(const pic_all& lin,int* type,int* type_base){
    void* ret;
    *type_base=lin.type;
    switch(lin.type){
        case (-1)://英雄
        case (0)://怪物
            ret=data_f[hear].people[lin.id];
            *type=2;
            break;
        case (100)://粒子
            ret=data_f[hear].arton[lin.id];
            *type=3;
            break;
        default:
            *type=*type_base=-10;
            ret=NULL;
            break;
    }
    return ret;
}
void* Database::find_type(const pic_all& lin,int* type){
    void* ret;
    switch(lin.type){
        case (-1)://英雄
        case (0)://怪物
            ret=data_f[hear].people[lin.id];
            *type=2;
            break;
        case (100)://粒子
            ret=data_f[hear].arton[lin.id];
            *type=3;
            break;
        default:
            *type=-10;
            ret=NULL;
            break;
    }
    return ret;
}
void* Database::find_type(const pic_all& lin){
    void* ret;

    switch(lin.type){
        case (-1)://英雄
        case (0)://怪物
            ret=data_f[hear].people[lin.id];
            break;
        case (100)://粒子
            ret=data_f[hear].arton[lin.id];
            break;
        default:
            ret=NULL;
            break;
    }
    return ret;
}
