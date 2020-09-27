#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include"rulewindow.h"

#include <QMainWindow>

class gamewindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit gamewindow(QWidget *parent = nullptr);
    //重写绘图事件
    void paintEvent(QPaintEvent *);
    rulewindow * ruleScene=NULL;
signals:

public slots:
};

#endif // GAMEWINDOW_H
