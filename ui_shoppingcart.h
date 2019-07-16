/********************************************************************************
** Form generated from reading UI file 'shoppingcart.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOPPINGCART_H
#define UI_SHOPPINGCART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include "mpushbutton.h"

QT_BEGIN_NAMESPACE

class Ui_ShoppingCart
{
public:
    QTableWidget *itemTable;
    mPushButton *deleteItem;
    mPushButton *checkout;
    QLabel *totalLabel;

    void setupUi(QDialog *ShoppingCart)
    {
        if (ShoppingCart->objectName().isEmpty())
            ShoppingCart->setObjectName(QStringLiteral("ShoppingCart"));
        ShoppingCart->setEnabled(true);
        ShoppingCart->resize(642, 463);
        itemTable = new QTableWidget(ShoppingCart);
        if (itemTable->columnCount() < 2)
            itemTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        itemTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        itemTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        itemTable->setObjectName(QStringLiteral("itemTable"));
        itemTable->setGeometry(QRect(30, 10, 561, 351));
        itemTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        itemTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        itemTable->horizontalHeader()->setStretchLastSection(true);
        itemTable->verticalHeader()->setVisible(false);
        deleteItem = new mPushButton(ShoppingCart);
        deleteItem->setObjectName(QStringLiteral("deleteItem"));
        deleteItem->setGeometry(QRect(30, 380, 111, 41));
        checkout = new mPushButton(ShoppingCart);
        checkout->setObjectName(QStringLiteral("checkout"));
        checkout->setGeometry(QRect(460, 380, 131, 41));
        totalLabel = new QLabel(ShoppingCart);
        totalLabel->setObjectName(QStringLiteral("totalLabel"));
        totalLabel->setGeometry(QRect(150, 380, 291, 61));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        totalLabel->setFont(font);
        totalLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(ShoppingCart);

        QMetaObject::connectSlotsByName(ShoppingCart);
    } // setupUi

    void retranslateUi(QDialog *ShoppingCart)
    {
        ShoppingCart->setWindowTitle(QApplication::translate("ShoppingCart", "Shopping Cart", nullptr));
        QTableWidgetItem *___qtablewidgetitem = itemTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ShoppingCart", "Item", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = itemTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ShoppingCart", "Price", nullptr));
        deleteItem->setText(QApplication::translate("ShoppingCart", "Delete", nullptr));
        checkout->setText(QApplication::translate("ShoppingCart", "Checkout", nullptr));
        totalLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ShoppingCart: public Ui_ShoppingCart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOPPINGCART_H
