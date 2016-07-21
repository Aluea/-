#ifndef __ARTON__
#define __ARTON__
class Arton_base{
    public:
        Arton_base();
        ~Arton_base();
        inline void set_a(int a_x,int a_y,int a_z);
        inline void cal_v();//计算v
        inline void cal_s();//计算位置
        int x,y,z;
        int v_x,v_y,v_z;
        int a_x,a_y,a_z;
    protected:
        int *id_pic;
        int id_count;
    private:
};
class Arton_green:public Arton_base{
    public:
        Arton_green(int x, int y, int z);
        Arton_green(int x, int y, int z,int v_x,int v_y,int v_z);
        ~Arton_green();

};

#endif
