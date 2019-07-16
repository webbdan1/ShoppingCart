#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "shoppingcart.h"
#include "database.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void addMerch(Merchandise*);

private:
    Ui::MainWindow *ui;
    ShoppingCart *cart = new ShoppingCart(this);
    Database* m_database = new Database;

private slots:
    void actOnChange(QObject*);
    void checkout();
};

#endif // MAINWINDOW_H
