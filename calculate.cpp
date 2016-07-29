#include<calculate.h>
#define MT 10000
//查询区
inline bool cal::getdf(pic_all *p){

    if(p->type<100){
        //empty
        return false;
    }
    else if(p->type>=100){
         Arton_base *lin;
        lin=datas->data_f[0].arton[p->id];
        if(!lin->a_x&&!lin->a_y&&!lin->a_z&&abs(lin->v_x)<0.001&&abs(lin->v_y)<0.001&&abs(lin->v_z)<0.001)
            return false;
        else return true;
    }
}
double F(double dis){
    double ret;
    if(dis>40.2){
        ret=0;
    }else if(dis>25){
        ret=50/dis;
    }else{
        ret=-328.15/(dis+6.25)+12.5;
    }
    return ret;
}



inline double cal::getjuli(pic_all *p,pic_all *q){
       double x1,y1,z1,x2,y2,z2;double juli;
       getxyz(p,&x1,&y1,&z1);
       getxyz(q,&x2,&y2,&z2);
        juli=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1);
        return juli;
}

inline void cal::getxy(pic_all *p,double *x,double *y){
    if(p->type<100){
            //empty
           *x=*y=0;
        }
        else if(p->type>=100){
        Arton_base *lin;
       lin=datas->data_f[0].arton[p->id];
       *x=lin->x;*y=lin->y;
    }
}
inline void cal::getxyz(pic_all *p,double *x,double *y,double *z){
    if(p->type<100){
            //empty
           *x=*y=*z=0;
        }
        else if(p->type>=100){
        Arton_base *lin;
       lin=datas->data_f[0].arton[p->id];
       *x=lin->x;*y=lin->y;*z=lin->z;
    }
}
inline void cal::getv(pic_all *p,double *vx,double *vy,double *vz){
    if(p->type<100){
            //empty
           *vx=*vy=*vz=0;
        }
        else if(p->type>=100){
        Arton_base *lin;
       lin=datas->data_f[0].arton[p->id];
       *vx=lin->v_x;*vy=lin->v_y;*vz=lin->v_z;

    }
}

inline void cal::geta(pic_all *p,double *ax,double *ay,double *az){
    if(p->type<100){
            //empty
           *ax=*ay=*az=0;
        }
        else if(p->type>=100){
        Arton_base *lin;
       lin=datas->data_f[0].arton[p->id];
       *ax=lin->a_x;*ay=lin->a_y;*az=lin->a_z;

    }
}

inline int cal::getbl(pic_all *p){
    if(p->type<100){
            //empty
           return -1;
        }
        else if(p->type>=100){
        Arton_base *lin;
       lin=datas->data_f[0].arton[p->id];
       return lin->belong;

    }

}

inline void cal::setxy(pic_all *p,double *x,double *y){
    if(p->type<100){
            //empty

        }
        else if(p->type>=100){
        Arton_base *lin;
       lin=datas->data_f[0].arton[p->id];
       lin->x=*x;lin->y=*y;
    }
}

inline void cal::setxyz(pic_all *p,double *x,double *y,double *z){
    if(p->type<100){
            //empty

        }
        else if(p->type>=100){
        Arton_base *lin;
       lin=datas->data_f[0].arton[p->id];
       lin->x=*x;lin->y=*y;lin->z=*z;
    }
}

inline void cal::setv(pic_all *p,double *vx,double *vy,double *vz){
    if(p->type<100){
            //empty

        }
        else if(p->type>=100){
        Arton_base *lin;
       lin=datas->data_f[0].arton[p->id];
       lin->v_x=*vx;lin->v_y=*vy;lin->v_z=*vz;

    }
}

inline void cal::seta(pic_all *p,double *ax,double *ay,double *az){
    if(p->type<100){
            //empty

        }
        else if(p->type>=100){
        Arton_base *lin;
       lin=datas->data_f[0].arton[p->id];
       lin->a_x=*ax;lin->a_y=*ay;lin->a_z=*az;

    }
}

inline void cal::setbl(pic_all *p,int e){
    if(p->type<100){
            //empty

        }
        else if(p->type>=100){
        Arton_base *lin;
       lin=datas->data_f[0].arton[p->id];
         lin->belong=e;}
}

//方法区
void cal::colide(pic_all *p,pic_all *q){
    double x1,x2,y1,y2,z1,z2,vx1,vx2,vy1,vy2,vz1,vz2;
    double cvx,cvy,cvz;
    double nvx1,nvx2,nvy1,nvy2,nvz1,nvz2;
    double vcx1,vcx2,vcx3,vcy1,vcy2,vcy3,vcz1,vcz2,vcz3;
    getxyz(p,&x1,&y1,&z1);
    getxyz(q,&x2,&y2,&z2);
    getv(p,&vx1,&vy1,&vz1);
    getv(q,&vx2,&vy2,&vz2);
    //qDebug("%f %f %f  %f %f %f",vx1,vy1,vz1,vx2,vy2,vz2);
    cvx=vx2;cvy=vy2;cvz=vz2;
    vcx1=vx1-=cvx;vcy1=vy1-=cvy;vcz1=vz1-=cvz;
    vcx2=x2-x1;vcy2=y2-y1;vcz2=z2-z1;
    double k1,k2,k3;
    k1=vcx1*vcx2+vcy1*vcy2+vcz1*vcz2;
    k2=vcx2*vcx2+vcy2*vcy2+vcz2*vcz2;
    k3=k1/(1.0*k2);
    //qDebug("k:%f %f %f",k1,k2,k3);
    vcx2*=k3;vcy2*=k3;vcz2*=k3;
    vcx3=vcx1-vcx2;
    vcy3=vcy1-vcy2;
    vcz3=vcz1-vcz2;
    nvx1=vcx3+cvx;nvx2=vcx2+cvx;
    nvy1=vcy3+cvy;nvy2=vcy2+cvy;
    nvz1=vcz3+cvz;nvz2=vcz2+cvz;
  //qDebug("%f %f %f  %f %f %f",nvx1,nvy1,nvz1,nvx2,nvy2,nvz2);
    setv(p,&nvx1,&nvy1,&nvz1);
    setv(q,&nvx2,&nvy2,&nvz2);

}
void cal::xun_js(pic_all *p, pic_all *q){
    Arton_virtual *lin;
    lin=datas->data_f[0].affairs[p->id]->virtual_list[0];
    double vcx,vcy,vcz,x,y,z,mod;
    getxyz(q,&x,&y,&z);
    vcx=lin->x-x;
    vcy=lin->y-y;
    vcz=lin->z-z;
    mod=sqrt(vcx*vcx+vcy*vcy+vcz*vcz);
    if(mod<20){
        vcx=0;
        vcy=0;
        vcz=0;
    }
    else if(mod<60){
        vcx*=3.0/mod;
        vcy*=3.0/mod;
        vcz*=3.0/mod;
    }
    else if(mod<200){
        vcx*=2/mod;
        vcy*=2/mod;
        vcz*=2/mod;
    }
    else{
        vcx=0;
        vcy=0;
        vcz=0;
    }
    geta(q,&x,&y,&z);
    x+=vcx;
    y+=vcy;
    z+=vcz;
    seta(q,&x,&y,&z);
}

void cal::m_search1(){
    at_count=0;pic_all lin;
    for(int k=0;k<=180;k++){
        for(int i=0;i<15;i++){
            for(int j=0;j<datas->data_f[0].map_count[k][i];j++){
                         lin=datas->data_f[0].map[k][i][j];
                         if(getdf(&lin)==true)
                         {
                             active_list[at_count++]=lin;
                         }
            }
        }
    }
    while(!datas->freshman.empty()){      //初生入库
        active_list[at_count++]=datas->freshman.top();
        datas->freshman.pop();
    }
}
 void cal::m_search2(){
     for(int i=0;i<at_count;i++){
         pre[i]=-1;
        // qDebug("%d %d",active_list[i].type,active_list[i].id);
     }
     double juli;
     fn_count=0;
     for(int i=0;i<at_count;i++){
         if(pre[i]==-1){
             pre[i]=fn_count++;
             //qDebug("++");
         for(int j=i+1;j<at_count;j++){
             if(pre[j]==-1){
             juli=getjuli(&active_list[i],&active_list[j]);
            // qDebug("JL %f",juli);
             if(juli<=MT)pre[j]=pre[i];
            }
         }
         }
     }
     for(int i=0;i<fn_count;i++){
         fn_list[i].x_max=0;
         fn_list[i].x_min=200;
         fn_list[i].y_max=0;
         fn_list[i].y_min=18;

     }
     double x,y;
     for(int i=0;i<at_count;i++){
       getxy(&active_list[i],&x,&y);

      x=x*1.0/DIS;y=y*1.0/DIS;
      // qDebug("xy %.0f %.0f",x,y);
       if(x>fn_list[pre[i]].x_max)fn_list[pre[i]].x_max=(int)x;
       if(x<fn_list[pre[i]].x_min)fn_list[pre[i]].x_min=(int)x;
       if(y>fn_list[pre[i]].y_max)fn_list[pre[i]].y_max=(int)y;
       if(y<fn_list[pre[i]].y_min)fn_list[pre[i]].y_min=(int)y;
     }
    // qDebug("AT %d",at_count);
 }
 void cal::main_js(){
     m_search1();
     m_search2();
     int b_z,b_y,b_s,b_x;
     for(int l=0;l<1;l++){
         if(fn_list[l].x_min-5>=0)
         b_z=fn_list[l].x_min-5;
         else b_z=0;
         if(fn_list[l].x_max+5<=180)
         b_y=fn_list[l].x_max+5;
         else b_y=180;
         if(fn_list[l].y_min-5>=0)
         b_x=fn_list[l].y_min-5;
         else b_x=0;
         if(fn_list[l].y_max+5<=18)
         b_s=fn_list[l].y_max+5;
         else b_s=18;
        // qDebug("sj%d %d %d %d",b_z,b_y,b_s,b_x);
         if(b_z<0||b_z>=180)b_z=0;
         if(b_y<0||b_y>=180)b_y=180;
         if(b_s<0||b_s>=18)b_s=0;
         if(b_x<0||b_x>=18)b_x=18;
         js_count=0;
         for(int k=0;k<180;k++){    //四极入库
             for(int i=0;i<=14;i++){
                 for(int j=0;j<datas->data_f[0].map_count[k][i];j++){

                    js_list[js_count++]=datas->data_f[0].map[k][i][j];

                 }
             }
         }
        // qDebug("ZM %d",js_count);

         // 前戏结束 正式开算
         for(int i=0;i<js_count;i++){
             Arton_base &A=*static_cast<Arton_base*>(datas->find_type(js_list[i]));
             A.set_a(0,0,0);
         }
         for(int i=0;i<datas->must_count;i++){
             //qDebug("%d",datas->must_count);
             for(int j=0;j<js_count;j++){
                 if(getbl(&js_list[j])==1){
                     xun_js(&datas->must_list[i],&js_list[j]);
                 }
             }
         }
         for(int i=0;i<js_count;i++){
             //单个受力
            // qDebug("%d",js_list[i].id);
             for(int j=i+1;j<js_count;j++){

                    // qDebug("%f",getjuli(&js_list[i],&js_list[j]));
                    // if(getjuli(&js_list[i],&js_list[j])<500)colide(&js_list[i],&js_list[j]);
                 if(getbl(&js_list[i])==getbl(&js_list[j])){
                     cal_f(js_list[i],js_list[j]);

                 }
                 else{
                     if(getjuli(&js_list[i],&js_list[j])<500)colide(&js_list[i],&js_list[j]);
                 }
             }

         }
         int x,y,z;
          for(int i=0;i<js_count;i++){
              Arton_base &A=*static_cast<Arton_base*>(datas->find_type(js_list[i]));
         if(abs(A.a_x)<0.7)A.a_x=0;
//        //  if(abs(A.a_x)>20){
//      //        if(A.a_x>0)x=1;else x=-1;
//      //        A.a_x=20*x;
//     //     }
              if(abs(A.a_y)<0.7)A.a_y=0;
//       //       if(abs(A.a_y)>20){
//       //           if(A.a_y>0)y=1;else y=-1;
//        //          A.a_y=20*y;
//          //    }
             if(abs(A.a_z)<0.7)A.a_z=0;
//       //      if(abs(A.a_z)>20){
//        //         if(A.a_z>0)z=1;else z=-1;
//        //         A.a_z=20*z;
//        //     }



                A.cal_v();


//                datas->move_project(js_list[i],A.x,A.y);
              A.cal_s();

          }



     }
 }

void cal::shouli(){
    if(datas->hero.y>0)datas->hero.ay=-2;
    if(datas->hero.y<0){
        datas->hero.ay=0;
        datas->hero.vy=0;
        datas->hero.y=0;
    }
}

void cal::sudujs(){
    datas->hero.vy+=datas->hero.ay;
}

void cal::weizhijs(){
    if(datas->hero.y+datas->hero.vy<0){
        datas->hero.y=0;
    }
    else datas->hero.y+=datas->hero.vy;
}

void cal::cal_f(const pic_all& a,const pic_all& b){
    Arton_base& A=*static_cast<Arton_base*>((datas->find_type(a)));
    Arton_base& B=*static_cast<Arton_base*>((datas->find_type(b)));
    double x=A.x-B.x;
    double y=A.y-B.y;
    double z=A.z-B.z;
    double dis=sqrt(x*x+y*y+z*z);
    if(dis==0){
        return;
    }
    double f=-F(dis);
    if(f==0)return;
     if(abs(f)<=0.75){
    int fx1,fx2,fy1,fy2,fz1,fz2;
    double vcx,vcy,vcz,vx1,vx2,vy1,vy2,vz1,vz2,mod;
   A.getv(&vx1,&vy1,&vz1);
    B.getv(&vx2,&vy2,&vz2);
    vcx=vx1-vx2;
    vcy=vy1-vy2;
    vcz=vz1-vz2;
    mod=abs(vcx*x+vcy*y+vcz*z)*1.0/dis;
    double k;
    if(mod>2)k=1;
    else k=mod/2.0;
    vcx=abs(x)*k*1.0/dis;
    vcy=abs(y)*k*1.0/dis;
    vcz=abs(z)*k*1.0/dis;
    if(vx1>0)fx1=1;
    else fx1=-1;
    if(vx2>0)fx2=1;
    else fx2=-1;
    if(vy1>0)fy1=1;
    else fy1=-1;
    if(vy2>0)fy2=1;
    else fy2=-1;
    if(vz1>0)fz1=1;
    else fz1=-1;
    if(vz2>0)fz2=1;
    else fz2=-1;
    vx1=(abs(vx1)-vcx)*fx1;
    vx2=(abs(vx2)-vcx)*fx2;
    vy1=(abs(vy1)-vcy)*fy1;
    vy2=(abs(vy2)-vcy)*fy2;
    vz1=(abs(vz1)-vcz)*fz1;
    vz2=(abs(vz2)-vcz)*fz2;

    A.v_x=vx1;A.v_y=vy1;A.v_z=vz1;
    B.v_x=vx2;B.v_y=vy2;B.v_z=vz2;
       // A.smail_v();
    }
    double lin=f/dis;
    double a_x,a_y,a_z;

         a_x=lin*x;
         a_y=lin*y;
         a_z=lin*z;

    A.set_a(A.a_x+a_x,A.a_y+a_y,A.a_z+a_z);
    B.set_a(B.a_x-a_x,B.a_y-a_y,B.a_z-a_z);
}
