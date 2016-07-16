#ifndef __SYSTEM__
#define __SYSTEM__
#include<iostream>
#include<caster.h>
#include<vector>
#include<stdarg.h>
#define PEOPLE_ALL 1000
#define BACKGROUND_ALL 20
#define AREA_ID_ALL 3000
using namespace std;
class System{
    public:
        System();
        ~System();
        //键盘计时器绑定
        void key_in(const char key_val,int key_now=-1);
        //鼠标绑定
        void mouse_in(int mouse_x,int mouse_y,int mouse_now);
        //stack<pic_new>* get_new_project();
        void calculate();
        //移动有关
        void peo_move(int fang);
        void move(int fang);
        void tu_move(int fang);
        //返回堆栈
        stack<pic> picture;
    private:
        //类型 图区id x y z w h 图片id数 ...为图片id
        void new_prject(char type,int idarea,int x,int y,int z,int w,int h,int id_count,...);//新建对象
        int get_id();//取得空id


        //图区id
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

        //当前图片
        int pic_now;
        //人图动 标志
        int rtd;
        //主人物
        Life hero;
};

#endif
//
