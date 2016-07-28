#ifndef __AFFAIRS__
#define __AFFAIRS__
#include<caster.h>
#include<arton.h>
class Affairs{
public:
  Arton_virtual *virtual_list[100];
  //pic_all true_list[500];
  int virtual_count,true_count;
  int dec[100][100];
  int state;
  int count,time_line;//时间计位器
  Affairs(int ge,int sta,int counts);
  void jiwei(){count++;}
  void jiancha(){
      if(count>=time_line){
          state=1;
      }
  }

};

#endif
