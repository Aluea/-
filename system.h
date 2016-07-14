#ifndef __SYSTEM__
#define __SYSTEM__
#include<iostream>
#include<caster.h>
using namespace std;
class System{
    public:
        System();
        ~System();
        void key_in(const char key_val,int key_now=-1);
        void mouse_in(int mouse_x,int mouse_y,int mouse_now);
        stack<pic>& redrew();
        void calculate();
        void peo_move(FANG fang);
    private:
        stack<pic> picture;

        map<int,Life> id_map;
        stact<int> id_map_empty;
        int id_map_max;

        map<int,M_map> id_peo;
        stact<int> id_peo_empty;
        int id_peo_max;
};

#endif
//
