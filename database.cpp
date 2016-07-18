#include<database.h>
void Database::new_prject(char type,int idarea,int x,int y,int z,int w,int h,int id_count,...){
    va_list arg_ptr;
    va_start(arg_ptr,id_count);
    int id_pic,i,idarea_n;
    switch(type){
        case 'm'://背景
            id_pic=va_arg(arg_ptr,int);
            for(i=0;i<AREA_ID_ALL;i++){
                if(!area_id_use[i]){
                    idarea_n=i;
                    break;
                }
            }
            for(i=0;i<BACKGROUND_ALL;i++){
                if(!background_use[i]){
                    break;
                }
            }
            background[i].set(idarea,id_pic,x,y,w,h);
            background_use[i]=true;
            area_id[idarea_n]=idarea;
            area_id_use[idarea_n]=true;
            break;
        case 'p'://人物与怪物

            for(i=0;i<AREA_ID_ALL;i++){
                if(!area_id_use[i]){
                    idarea_n=i;
                    break;
                }
            }
            for(i=0;i<PEOPLE_ALL;i++){
                if(!background_use[i]){
                    break;
                }
            }
            people[i].set(id_count,idarea,x,y,z,w,h);
            for(int j=0;i<id_count;j++){
                id_pic=va_arg(arg_ptr,int);
                people[i].setid(id_pic,j);
            }
            people_use[i]=true;
            area_id[idarea_n]=idarea;
            area_id_use[idarea_n]=true;
            break;
        case 'l'://粒子
            break;
    }
}
