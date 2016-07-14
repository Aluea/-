#ifndef __CASTER__
#define __CASTER__
#include<algorithm>
#include<stack>
#include<map>
#include<life.h>
#include<m_map.h>
#define EMPTY -1
typedef struct{
    bool show;
    int id,x,y,width,height;
}pic;
typedef struct{
    char name;//m为背景 p为人物
    int id,x,y,width,height;
}pic_new;
enum FANG{
    SHANG=0,XIA,ZUO,YOU
};


#endif
