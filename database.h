#ifndef __DATABASE__
#define __DATABASE__
#include<caster.h>
#include<stdarg.h>
using namespace std;
#define PEOPLE_ALL 1000
#define BACKGROUND_ALL 20
#define ARTON_ALL 3000
#define AREA_ID_ALL 3000
#define MAP_ALL 10
#define AFFAIRS_ALL 3000
#define EMPTY -1
#define DIS 20
struct pic_all{
    bool operator ==(const pic_all& lin);
    int type;
    int id;
};
void swap(pic_all& a,pic_all& b);
struct data_in{
    data_in();

    //背景线性表1
    M_map* background[BACKGROUND_ALL];
    bool background_use[BACKGROUND_ALL];
    //怪物线性表2
    Life* people[PEOPLE_ALL];
    bool people_use[PEOPLE_ALL];
    //粒子线性表3
    Arton_base* arton[ARTON_ALL];
    bool arton_use[ARTON_ALL];
    //事物线性表4
    Affairs* affairs[AFFAIRS_ALL];
    bool affairs_use[AFFAIRS_ALL];

    //地图
    //间距=20px
    pic_all map[200][18][200];
    int map_count[200][18];
};
class Database{
    public:
        Database();
        ~Database();
        Hero hero;
        friend class System;
        friend class m_system;
        friend class cal;
        void new_project(int type,int x,int y,int z,int v);//新建对象
        void new_background(int hear, int x, int y, int w, int h, int pic_id);
        void del_project(const pic_all& obj);//删除
        void move_project(const pic_all& obj,int x_old,int y_old);
        void move_project(int type,int id,int x_old,int y_old);
        void* find_type(const pic_all& lin,int* type,int* type_base);//类型查找 返回viod* 指针 type 说明类型 type说基类类类型
        void* find_type(const pic_all& lin,int* type);
        void* find_type(const pic_all& lin);
        int hear;
    private:        
        data_in data_f[MAP_ALL];





};

#endif
