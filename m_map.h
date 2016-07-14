#ifndef __M_MAP__
#define __M_MAP__
class M_map{
    public:
        M_map(int id_pic_chuang,int id_pic,int x_win,int y_win);
        ~M_map();
        int get_id_pic_chuang() const;
        int get_id_pic() const;

    private:
        int x_win,y_win;
        int id_pic_chuang;//0~9为背景
        int id_pic;
};
#endif
