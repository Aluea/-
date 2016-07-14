#ifndef __CASTER__
#define __CASTER__
#include<algorithm>
#include<stack>
#include<map>
#include<life.h>
#include<m_map.h>
#define EMPTY -1
struct pic{
    bool show;
    char type;
    int id_pic,id_area,x,y,z,width,height;
};
struct pic_new{
    char name;//m为背景 p为人
    int x,y,width,height,id_pic;
};


enum FANG{
    SHANG=0,XIA,ZUO,YOU
};
struct showturn{
    int z;
    int id;
    int pic;
};
bool cmp(showturn a,showturn b);

#endif
