#include<database.h>
//data_in::data_in(){
//    for(int i=0;i<200;i++){
//        map_count[i]=0;
//    }
//}

Database::Database(){
    hear=0;
    //data_f=new data_in;
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
                if(!data_f[hear].area_id_use[i]){
                    idarea_n=i;
                    break;
                }
            }
            for(i=0;i<BACKGROUND_ALL;i++){
                if(!data_f[hear].background_use[i]){
                    break;
                }
            }
            data_f[hear].background[i].set(idarea,id_pic,x,y,w,h);
            data_f[hear].background_use[i]=true;
            data_f[hear].area_id[idarea_n]=idarea;
            data_f[hear].area_id_use[idarea_n]=true;
            lin_a.type='m';
            lin_a.id=i;
            data_f[hear].map[id_map][data_f[hear].map_count[id_map]]=lin_a;
            data_f[hear].area_to_map[idarea].x=id_map;
            data_f[hear].area_to_map[idarea].y=data_f[hear].map_count[id_map]++;
            break;
        case 'p'://人物与怪物

            for(i=0;i<AREA_ID_ALL;i++){
                if(!data_f[hear].area_id_use[i]){
                    idarea_n=i;
                    break;
                }
            }
            for(i=0;i<PEOPLE_ALL;i++){
                if(!data_f[hear].background_use[i]){
                    break;
                }
            }
            data_f[hear].people[i].set(id_count,idarea,x,y,z,w,h);
            for(int j=0;i<id_count;j++){
                id_pic=va_arg(arg_ptr,int);
                data_f[hear].people[i].setid(id_pic,j);
            }
            data_f[hear].people_use[i]=true;
            data_f[hear].area_id[idarea_n]=idarea;
            data_f[hear].area_id_use[idarea_n]=true;
            lin_a.type='p';
            lin_a.id=i;
            data_f[hear].map[id_map][data_f[hear].map_count[id_map]]=lin_a;
            data_f[hear].area_to_map[idarea].x=id_map;
            data_f[hear].area_to_map[idarea].y=data_f[hear].map_count[id_map]++;
            break;
        case 'l'://粒子
            break;
    }
}
void Database::del_prject(const pic_all& obj){
    pic_point lin;
    switch (obj.type){
        case 'm':
            data_f[hear].background_use[obj.id]=false;
            lin=data_f[hear].area_to_map[data_f[hear].background[obj.id].get_idarea()];
            swap( data_f[hear].map[lin.x][lin.y] , data_f[hear].map[lin.x][ data_f[hear].map_count[lin.x]-- ] );

            break;
        case 'p':
            data_f[hear].people_use[obj.id]=false;
            lin=data_f[hear].area_to_map[data_f[hear].people[obj.id].getarea_id()];
            swap( data_f[hear].map[lin.x][lin.y] , data_f[hear].map[lin.x][ data_f[hear].map_count[lin.x]-- ] );
            break;
    }
}
