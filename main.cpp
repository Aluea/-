#include<m_ios.h>
#include <QApplication>
int main(int argc, char *argv[]){
    QApplication a(argc, argv);

  my_ios ws;
  ws.resize(700,350);
  ws.show();


    return a.exec();
}
