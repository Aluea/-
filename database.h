#ifndef __DATABASE__
#define __DATABASE__
#include<caster.h>
#include<stdarg.h>
using namespace std;
#define PEOPLE_ALL 1000
#define BACKGROUND_ALL 20
#define AREA_ID_ALL 3000
#define MAP_ALL 10
#define AFFAIRS_ALL 3000
#define EMPTY -1
#define DIS 20
struct pic_all{
    char type;
    int id;
};
void swap(pic_all& a,pic_all& b);
struct pic_point{
    int x,y;
};

struct data_in{
    //data_in();

    int area_id[AREA_ID_ALL];
    bool area_id_use[AREA_ID_ALL]={false};
    pic_point area_to_map[AREA_ID_ALL];

    //背景线性表
    M_map background[BACKGROUND_ALL];
    bool background_use[BACKGROUND_ALL];
    //人物线性表
    Life people[PEOPLE_ALL];
    bool people_use[PEOPLE_ALL];
    //粒子线性表
    //~
    //事物线性表
    Affairs affairs[AFFAIRS_ALL];
    bool affairs_use[AFFAIRS_ALL];

    //地图
    //间距=20px
    pic_all map[200][20];
    int map_count[200];
};

class Database{
    public:
        Database();
        Life hero;
        friend class System;
        //类型 图区id x y z w h 图片id数 ...为图片id
        void new_prject(char type,int idarea,int x,int y,int z,int w,int h,int id_count,...);//新建对象
        void del_prject(const pic_all& obj);//删除
        int hear;
    private:        
        data_in data_f[MAP_ALL];





};

#endif
