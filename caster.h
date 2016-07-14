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
    int id,x,y,width,height;
};
struct pic_new{
    char name;//m为背景 p为人物
<<<<<<< HEAD
    int x,y,width,height;
}pic_new;
=======
    int id,x,y,width,height;
};
>>>>>>> 12c1250019679e5dc3b63498e96f9b28611ae9ba
enum FANG{
    SHANG=0,XIA,ZUO,YOU
};
struct showturn{
    int z;
    int id;
};
bool cmp(showturn a,showturn b){
    return a.z>b.z;
}

#endif
