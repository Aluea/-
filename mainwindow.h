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

    void genghuan();
    ~MainWindow();
protected:
    void keyPressEvent( QKeyEvent *event);
    void paintEvent (QPaintEvent *event);
<<<<<<< HEAD
    void keyReleaseEvent( QKeyEvent *event);
=======
    void move_peo(char ch);
>>>>>>> shizhilvren
private:
    Ui::MainWindow *ui;
    QPixmap *tu[4];
    QPixmap *tu_peo_left;
    QRect *tuq[4];
    QRect *tuq_peo;

    int dq;
    QTimer *jishi;
    bool jip;
    int fang;
    public slots:
 void yidong();
};

#endif // MAINWINDOW_H
