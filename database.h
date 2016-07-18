#ifndef __DATABASE__
#define __DATABASE__
#include<caster.h>
#include<stdarg.h>
using namespace std;
#define PEOPLE_ALL 1000
#define BACKGROUND_ALL 20
#define AREA_ID_ALL 3000
#define EMPTY -1
class Database{
    public:
        //返回堆栈
        stack<pic> picture;
        Life hero;
        friend class System;
        //类型 图区id x y z w h 图片id数 ...为图片id
        void new_prject(char type,int idarea,int x,int y,int z,int w,int h,int id_count,...);//新建对象
    private:
        int area_id[AREA_ID_ALL];
        bool area_id_use[AREA_ID_ALL]={false};

        //地图线性表
        M_map background[BACKGROUND_ALL];
        bool background_use[BACKGROUND_ALL];
        //人物线性表
        Life people[PEOPLE_ALL];
        bool people_use[PEOPLE_ALL];
        //粒子线性表
        //~

};

#endif
