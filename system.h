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
        stack<pic>& redrew();
        stack<pic_new>& get_new_project();
        void calculate();
        void peo_move(FANG fang);
    private:
        void new_prject(pic_new& obj);//新建对象
        int get_id(const char ch);//取得空id
        //返回堆栈
        stack<pic> picture;
        stack<pic_new> picture_new;


        //图区id
        map<int,pic> id_map;
        stack<int> id_map_empty;
        int id_map_max;

        map<int,pic> id_peo;
        stack<int> id_peo_empty;
        int id_peo_max;

        vector<M_map> backgroubd;
};

#endif
//
