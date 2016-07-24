#ifndef __CALCULATE__
#define __CALCULATE__
#include<database.h>
#include<arton.h>
struct tuan{
    int x_max;
    int x_min;
    int y_max;
    int y_min;
};

class cal{
public :
    cal(){}
    Database *datas;
    //查询方法
inline bool getdf(pic_all *p);
inline double getjuli(pic_all *p,pic_all *q);
inline void getxy(pic_all *p,double *x,double *y);
inline void getxyz(pic_all *p,double *x,double *y,double *z);
inline void getv(pic_all *p,double *vx,double *vy,double *vz);
inline void geta(pic_all *p,double *ax,double *ay,double *az);
inline int getbl(pic_all *p);
inline void setxy(pic_all *p,double *x,double *y);
inline void setxyz(pic_all *p,double *x,double *y,double *z);
inline void setv(pic_all *p,double *vx,double *vy,double *vz);
inline void seta(pic_all *p,double *ax,double *ay,double *az);
inline void setbl(pic_all *p,int e);
   //寻找列表
    void m_search1();
    void m_search2();
    // 计算修改
    void shouli();
    void sudujs();
    void weizhijs();
    //计算
    void main_js();
    //运转法则
    void colide(pic_all *p,pic_all *q);


private:
   pic_all active_list[1000];
   int pre[1000]; //存上级
   int at_count;
   tuan fn_list[1000];
   int fn_count;
   pic_all js_list[1000];
   int js_count;

};


#endif
