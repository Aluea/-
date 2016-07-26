#include<systems.h>
m_system::m_system(QWidget *parent):QWidget(parent){
    show_zb=0;
    rtd=0;
    data.new_background(0,0,0,800,350,0);
    data.new_background(0,796,0,800,350,1);
    data.new_background(0,2*796,0,800,350,2);
    data.new_background(0,3*796,0,800,350,3);
    data.new_project(100,100,100,50,0);
    data.new_project(100,150,100,50,0);
   // data.new_project(100,300,100,50);
   // data.new_project(100,700,100,50);
    //for(int i=0;i<4;i++){
      //  data.new_project(100,rand()%500,rand()%180,50);
        //data.new_project(100,300,0,50);
    //}
    ft=1;
    jisuan.datas=&data;
    connect(&con_ji,SIGNAL(timeout()),this,SLOT(upbase()));

    con_ji.start(30);
}
//操纵
void m_system::beckon(int x, int y){
    int x0,y0,z0;
    x0=x+show_zb;
    z0=data.hero.z;
    y0=144+(z0)/2-(y);
    data.new_project(100,x0,y0,z0,0);
}

//更新
void m_system::upbase(){
    jisuan.shouli();
    jisuan.sudujs();
    jisuan.weizhijs();
    jisuan.main_js();

    //临时写法
   /* {      int lin_count=0;
        for(int i=0;i<200;i++){
            for(int j=0;j<18;j++){
                for(int k=0;k<data.data_f[data.hear].map_count[i][j];k++){
                    if(data.data_f[data.hear].map[i][j][k].type==100){

                        for(int x=0;x<200;x++){
                            for(int y=0;y<18;y++){
                                for(int z=0;z<data.data_f[data.hear].map_count[x][y];z++){
                                    if(data.data_f[data.hear].map[x][y][z].type==100){
                                       /* double jl;
                                        jl=jisuan.getjuli(&data.data_f[data.hear].map[i][j][k],&data.data_f[data.hear].map[x][y][z]);
                                       if(jl)qDebug("%f",jl);
                                        if(jl<=250&&jl>50){
                                            qDebug("afgaf");
                                           if(lin_count==0){
                                               jisuan.colide(&data.data_f[data.hear].map[i][j][k],&data.data_f[data.hear].map[x][y][z]);
                                               lin_count=1;

                                           }
                                        }
                                        jisuan.cal_f(data.data_f[data.hear].map[i][j][k],data.data_f[data.hear].map[x][y][z]);

                                    }
                                }
                            }
                        }

                    }
                }
            }
        }
        int x,y,z;
        for(int i=0;i<200;i++){
            for(int j=0;j<18;j++){
                for(int k=0;k<data.data_f[data.hear].map_count[i][j];k++){
                    if(data.data_f[data.hear].map[i][j][k].type==100){
                        Arton_base &A=*static_cast<Arton_base*>(data.find_type(data.data_f[data.hear].map[i][j][k]));
                    if(abs(A.a_x)<0.5)A.a_x=0;
                    if(abs(A.a_x)>20){
                        if(A.a_x>0)x=1;else x=-1;
                        A.a_x=20*x;
                    }
                        if(abs(A.a_y)<0.5)A.a_y=0;
                        if(abs(A.a_y)>20){
                            if(A.a_y>0)y=1;else y=-1;
                            A.a_y=20*y;
                        }
                       if(abs(A.a_z)<0.5)A.a_z=0;
                       if(abs(A.a_z)>20){
                           if(A.a_z>0)z=1;else z=-1;
                           A.a_z=20*z;
                       }



                        A.cal_v();
                        A.cal_s();
                        A.set_a(0,0,0);
                    }
                }
            }
        }
    }*/

}
 m_system::~m_system(){

 }

 void m_system::picture_push_one(char type,void * val){

 }

 void m_system::key_in(const char key_val,int key_now/*-1*/){

 }

 void m_system::mouse_in(int mouse_x,int mouse_y,int mouse_now){
 }

 //stack<pic_new>* System::get_new_project(){

 //}

 void m_system::calculate(){

 }

 void m_system::face_to(int fang){
     ft=fang;

     //lin.is_new=false;
     //lin.type=0;//人
    // lin.m_exit=true;

 }
 void m_system::show_search(){
     int tou,wei;
     tou=show_zb/20;
     if(tou>0)tou-=1;
     wei=(show_zb+700)/20;
     wei+=1;
     //qDebug("%d %d",tou,wei);
     h_count=0;
     for(int k=tou;k<=wei;k++){
         for(int i=0;i<18;i++){
             for(int j=0;j<data.data_f[0].map_count[k][i];j++){

                 harvest[h_count++]=data.data_f[0].map[k][i][j];

             }
         }
     }
 }

 void m_system::input_stack(){
      pic lin;int dq;
       dq=show_zb/796;

       show_search();
       for(int i=0;i<h_count;i++){
           if(harvest[i].type==100){

               lin.id_pic=data.data_f[0].arton[harvest[i].id]->get_id_pic();
               lin.x=data.data_f[0].arton[harvest[i].id]->x-show_zb;
               lin.y=data.data_f[0].arton[harvest[i].id]->z/2+144-data.data_f[0].arton[harvest[i].id]->y;
               lin.z=data.data_f[0].arton[harvest[i].id]->z;
               lin.w=lin.h=data.data_f[0].arton[harvest[i].id]->size;
             //  qDebug("%d ",lin.h);
               picture.push(lin);
           }
   }

      lin.id_pic=data.hero.getpic_id(ft);
      //lin.idarea=data.hero.getarea_id();
      lin.z=data.hero.z;
      lin.x=data.hero.x-show_zb;
      lin.y=data.hero.z/2+144-data.hero.y;
      lin.h=data.hero.height;
      lin.w=data.hero.width;
      picture.push(lin);

      if(dq<4){
          //lin.idarea=data.data_f[0].background[dq].get_idarea();
          lin.id_pic=data.data_f[0].background[dq]->get_id_pic();
          lin.x=data.data_f[0].background[dq]->x-show_zb;
          lin.y=data.data_f[0].background[dq]->y;
          lin.z=0;
          lin.w=data.data_f[0].background[dq]->w;
          lin.h=data.data_f[0].background[dq]->h;
          picture.push(lin);
      }

      if(dq+1<4){
          //lin.idarea=data.data_f[0].background[dq+1]->get_idarea();
          lin.id_pic=data.data_f[0].background[dq+1]->get_id_pic();
          lin.x=data.data_f[0].background[dq+1]->x-show_zb;
          lin.y=data.data_f[0].background[dq+1]->y;
          lin.z=0;
          lin.w=data.data_f[0].background[dq+1]->w;
          lin.h=data.data_f[0].background[dq+1]->h;
          picture.push(lin);
      }






}


 void m_system::move(int fang,int hfang){
     if(fang==-1){
         if(rtd==0){
             if(data.hero.x-show_zb<=140){
                 rtd=1;
                 tu_move(fang);
             }
             else{
                 peo_move(fang,0);
             }
         }
         if(rtd==1){
             if(data.hero.x-show_zb>=450){
                 rtd=0;
                 peo_move(fang,0);
             }
             else{
                 tu_move(fang);
             }
         }
     }
     if(fang==1){
         if(rtd==0){
             if(data.hero.x-show_zb>=500){
                 rtd=1;
                 tu_move(fang);
             }
             else{
                 peo_move(fang,0);
             }
          }
          if(rtd==1){
             if(data.hero.x-show_zb<=300){
                 rtd=0;
                 peo_move(fang,0);
             }
             else{
                 tu_move(fang);
             }
         }
     }
     if(hfang==-1){
         peo_move(0,hfang);
     }
     if(hfang==1){
         peo_move(0,hfang);
     }

 }



 void m_system::peo_move(int fang,int hfang){
     data.hero.x+=fang*2;
     if(data.hero.z>10&&hfang<0)
     data.hero.z+=hfang*4;
     if(data.hero.z<230&&hfang>0)
      data.hero.z+=hfang*4;
 }

 void m_system::tu_move(int fang){
     data.hero.x+=fang*2;
     show_zb+=fang*2;
 }
