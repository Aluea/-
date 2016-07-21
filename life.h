#ifndef __LIFE__
#define __LIFE__
//人物怪物基类
class Life{
    public:
        Life();
        ~Life();
        int getpic_id(int n) const;
        int get_id_count() const;
        inline void set_a(int a_x,int a_y,int a_z);
        inline void cal_v();//计算v
        inline void cal_s();//计算位置
        int x,y,z,ax,ay,az,vx,vy,vz;
        int width,height;
    protected:
        int *id_pic;
        int id_count;
    private:

};
#endif
