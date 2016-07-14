#ifndef __M_MAP__
#define __M_MAP__
class M_map{
    public:
        M_map();
        void set(int idarea,int id_pic,int x,int y,int w,int h);
        ~M_map();
        int get_idarea() const;
        int get_id_pic() const;
        int x,y,w,h;
    private:

        int idarea;//0~9为背景
        int id_pic;
};
#endif
