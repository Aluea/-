#ifndef __SYSTEM__
#define __SYSTEM__
#include<iostream>
#include<caster.h>
//#include<vector>
#include<map>
#include<life.h>
#include<stack>
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
        void move(int fang);//绑定函数
        void tu_move(int fang);
    private:
        void new_prject(char type,int id,int x,int y,int z,int w,int h,int id_count,...){//新建对象
        int get_id();//取得空id
        void use_id(int n,int id);
        //返回堆栈
        stack<pic> picture;

        //图区id
        //此处有id
        int area_id[3000];
        bool area_id_use[3000]={false};

        List_id <M_map> background;
        //M_map background[20];
        List_id <Life> people;
        //Life people[1000];

        int pic_now;
        int rtd;//人图动
        Life hero;
};


template <class T>
class List_id{
    public:
        List_id();
        ~List_id();
        void set(int size);
        void inster(T& hear);
        void del(int n);
        T& operator [] (int n);
        T *data;
        int cut;
};
#endif
//
