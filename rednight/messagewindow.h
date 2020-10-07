#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H
#include"QLabel"
#include <QWidget>

class messagewindow : public QWidget
{
    Q_OBJECT
public:
    explicit messagewindow(QWidget *parent = nullptr);
    QLabel * message =NULL;
signals:

public slots:
};

#endif // MESSAGEWINDOW_H
