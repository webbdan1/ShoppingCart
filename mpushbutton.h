#ifndef MPUSHBUTTON_H
#define MPUSHBUTTON_H
#include <QPushButton>

class mPushButton : public QPushButton
{
    Q_OBJECT

public:
    mPushButton(QWidget *w):QPushButton(w){}

signals:
    void iChanged(QObject*);

public slots:
    void beenClicked();

};

#endif // MPUSHBUTTON_H
