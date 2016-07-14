#ifndef __LIFE__
#define __LIFE__
class Life{
    public:
        Life(int id,int x,int y,int z,int width,int height);
        ~Life();
    private:
        int x_true,y_true,z_true,width_true,height_true;
        int x_win,y_win,width_win,height_win;
        int id_pic;
};
#endif
