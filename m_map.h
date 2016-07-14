#ifndef __M_MAP__
#define __M_MAP__
class M_map{
    public:
        M_map(int id_pic,int x_win,int y_win,int width_win,int height_win);
        ~M_map();
    private:
        int x_win,y_win,width_win,height_win;
        int id_pic;//0~9为背景
};
#endif
