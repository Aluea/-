#ifndef __SYSTEM__
#define __SYSTEM__
#include<iostream>
#include<caster.h>
#include<vector>
using namespace std;
class System{
    public:
        System();
        ~System();
        void key_in(const char key_val,int key_now=-1);
        void mouse_in(int mouse_x,int mouse_y,int mouse_now);
        stack<pic>* redrew_background();
        stack<pic>* redrew();

        //stack<pic_new>* get_new_project();
        void calculate();
        void peo_move(int fang);
        void move(int fang);
        void tu_move(int fang);
    private:
        void new_prject();//新建对象
        int get_id();//取得空id
        //返回堆栈
        stack<pic> picture;

        //图区id
        //此处有id
        int area_id[3000];
        bool area_id_use[3000]={false};

        M_map background[20];
        Life people[1000];

        int pic_now;
        int rtd;
        Life hero;
};

#endif
//
