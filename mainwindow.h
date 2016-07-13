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
    void keyReleaseEvent( QKeyEvent *event);
private:
    Ui::MainWindow *ui;
    QPixmap *tu[4];
    QRect *tuq[4];
    int dq;
    QTimer *jishi;
    bool jip;
    int fang;
    public slots:
 void yidong();
};

#endif // MAINWINDOW_H
