#include<database.h>
data_in::data_in(){
    for(int i=0;i<200;i++){
        data_count[i]=0;
    }
}

Database::Database(){
    hear=0;
}
void swap(pic_all& a,pic_all& b){
    pic_all c;
    c=a;
    a=b;
    b=c;
}

void Database::new_prject(char type,int idarea,int x,int y,int z,int w,int h,int id_count,...){
    int id_map=x/DIS;
    va_list arg_ptr;
    va_start(arg_ptr,id_count);
    int id_pic,i,idarea_n;
    pic_all lin_a;
    switch(type){
        case 'm'://背景
            id_pic=va_arg(arg_ptr,int);
            for(i=0;i<AREA_ID_ALL;i++){
                if(!data[hear].area_id_use[i]){
                    idarea_n=i;
                    break;
                }
            }
            for(i=0;i<BACKGROUND_ALL;i++){
                if(!data[hear].background_use[i]){
                    break;
                }
            }
            data[hear].background[i].set(idarea,id_pic,x,y,w,h);
            data[hear].background_use[i]=true;
            data[hear].area_id[idarea_n]=idarea;
            data[hear].area_id_use[idarea_n]=true;
            lin_a.type='m';
            lin_a.id=i;
            data[hear].map[id_map][data[hear].map_count[id_map]]=lin_a;
            data[hear].area_to_map[idarea].x=id_map;
            data[hear].area_to_map[idarea].y=data[hear].map_count[id_map]++;
            break;
        case 'p'://人物与怪物

            for(i=0;i<AREA_ID_ALL;i++){
                if(!data[hear].area_id_use[i]){
                    data[hear].idarea_n=i;
                    break;
                }
            }
            for(i=0;i<PEOPLE_ALL;i++){
                if(!data[hear].background_use[i]){
                    break;
                }
            }
            data[hear].people[i].set(id_count,idarea,x,y,z,w,h);
            for(int j=0;i<id_count;j++){
                id_pic=va_arg(arg_ptr,int);
                data[hear].people[i].setid(id_pic,j);
            }
            data[hear].people_use[i]=true;
            data[hear].area_id[idarea_n]=idarea;
            data[hear].area_id_use[idarea_n]=true;
            lin_a.type='p';
            lin_a.id=i;
            data[hear].map[id_map][data[hear].map_count[id_map]]=lin_a;
            data[hear].area_to_map[idarea].x=id_map;
            data[hear].area_to_map[idarea].y=data[hear].map_count[id_map]++;
            break;
        case 'l'://粒子
            break;
    }
}
void Database::del_prject(const pic_all& obj){
    pic_point lin;
    switch (obj.type){
        case 'm':
            data[hear].background_use[obj.id]=false;
            lin=data[hear].area_to_map[data[hear].background[obj.id].get_idarea()];
            swap( data[hear].map[lin.x][lin.y] , data[hear].map[lin.x][ data[hear].map_count[lin.x]-- ] );

            break;
        case 'p':
            data[hear].people_use[obj.id]=false;
            lin=data[hear].area_to_map[data[hear].people[obj.id].getarea_id()];
            swap( data[hear].map[lin.x][lin.y] , data[hear].map[lin.x][ data[hear].map_count[lin.x]-- ] );
            break;
    }
}
