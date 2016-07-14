#ifndef __SYSTEM__
#define __SYSTEM__
#include<iostream>
#include<algorithm>
#include<stack>
#include<life.h>
#include<m_map.h>
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
    private:
        stack<pic> picture;
};

#endif
