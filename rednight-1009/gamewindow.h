#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include"rulewindow.h"
#include"messagewindow.h"
#include"person.h"
#include <QMainWindow>
class gamewindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit gamewindow(QWidget *parent = nullptr);
    //重写绘图事件
    void paintEvent(QPaintEvent *);
    rulewindow * ruleScene=NULL;
    messagewindow * messageScene=NULL;
    messagewindow * nullscene=NULL;
    void headvoteEvent(int num,person ps[]);
    void dayvote(int num,person ps[]);

signals:
    //写一个自定义信号，告诉主场景返回
    void gameBack();

public slots:
};

#endif // GAMEWINDOW_H
