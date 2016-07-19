#ifndef __M_MAP__
#define __M_MAP__
class M_map{
    public:
        M_map(int x,int y,int w,int h,int id);
        ~M_map();
        int get_id_pic() const;
        int x,y,w,h;
    private:
        int id_pic;
};
#endif
