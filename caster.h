#ifndef __CASTER__
#define __CASTER__
#include<algorithm>
#include<stack>
#include<map>
#include<life.h>
#include<m_map.h>
#define EMPTY -1
struct pic{
    int x,y,w,h;
    int id_pic,idarea;
    int type;
    bool m_exit,is_new;
};

struct showturn{
    int z;
    int id;
    int pic;
};
bool cmp(showturn a,showturn b);

#endif
