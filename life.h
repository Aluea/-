#ifndef __LIFE__
#define __LIFE__
//人物怪物基类
class Life{
    public:
        Life();
        ~Life();
        int getpic_id(int n) const;
        int get_id_count() const;
        int x,y,z;
    protected:
        int width,height;
        int *id_pic;
        int id_count;
    private:

};
#endif
