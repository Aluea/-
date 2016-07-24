#ifndef __ARTON__
#define __ARTON__
class Arton_base{
    public:
        Arton_base();
        ~Arton_base();
        void set_a(double a_x,double a_y,double a_z);
        inline void set_v(double x,double y,double z);
        inline void set_xy(double x,double y,double z);
        void smail_v();//缩小速度
        void smail_v(double c);
        int get_id_pic();
        void cal_v();//计算v
        void cal_s();//计算位置
        double x,y,z;
        double v_x,v_y,v_z;
        double a_x,a_y,a_z;
        int belong;
        int type;
        int state;
        int size;
    protected:
        int *id_pic;
        int id_count;
    private:

};
class Arton_green:public Arton_base{
    public:
        Arton_green(double x, double y, double z);
        Arton_green(double x, double y, double z,double v_x,double v_y,double v_z);
        ~Arton_green();

};

#endif
