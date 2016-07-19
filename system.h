#ifndef __SYSTEM__
#define __SYSTEM__
#include<iostream>
#include<caster.h>
#include<database.h>
#include<QDebug>

using namespace std;
class System{
    public:
        System();
        ~System();
        //返回堆栈
        stack<pic> picture;
        //脸朝向
        int ft;
        //键盘计时器绑定
        void key_in(const char key_val,int key_now=-1);
        //鼠标绑定
        void mouse_in(int mouse_x,int mouse_y,int mouse_now);
        //stack<pic_new>* get_new_project();
        void calculate();
        //移动有关
        void peo_move(int fang,int hfang);
        void move(int fang,int hfang);
        void tu_move(int fang);
        void face_to(int fang);

        //数据库
        Database data;
        void picture_push_one(char type,void * val);
        void input_stack();

    private:    
        //当前图片
        int pic_now;
        //人图动 标志
        int rtd;
        //主人物


};

#endif
//
