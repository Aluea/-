#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtGui>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void yidong();
    void genghuan();
    ~MainWindow();
protected:
    void keyPressEvent( QKeyEvent *event);
    void paintEvent (QPaintEvent *event);
private:
    Ui::MainWindow *ui;
    QPixmap *tu[4];
    QRect *tuq[4];
    int dq;
};

#endif // MAINWINDOW_H
