#ifndef __LIFE__
#define __LIFE__
class Life{
    public:
        Life();
        void set(int state,int id,int x,int y,int z,int width,int height);
        ~Life();
        void setid(int id,int n);
        int getpic_id(int x);
        int getarea_id();
        int get_id_count();
        int x,y,z;
        int x_true,y_true,z_true,width,height;
    private:
        int idarea;
        int *id_pic;
        int id_count;
        bool id_pic_use;




};
#endif
