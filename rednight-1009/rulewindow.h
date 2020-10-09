#ifndef RULEWINDOW_H
#define RULEWINDOW_H
#include"QLabel"
#include <QWidget>

class rulewindow : public QWidget
{
    Q_OBJECT
public:
    explicit rulewindow(QWidget *parent = nullptr);
    QLabel * rule =NULL;

signals:

public slots:
};

#endif // RULEWINDOW_H
