#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QDialog>
#include <QFont>
#include <QtAlgorithms>
#include "database.h"

namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QDialog
{
    Q_OBJECT

public:
    explicit ShoppingCart(QWidget *parent = nullptr);
    ~ShoppingCart();

signals:
    void checkout();
    void close();

private:
    Ui::ShoppingCart *ui;
    virtual void closeEvent(QCloseEvent*);

private slots:
    void actOnChange(QObject*);
    void on_checkout_clicked();
    void addMerch(Merchandise*);
};

#endif // SHOPPINGCART_H
