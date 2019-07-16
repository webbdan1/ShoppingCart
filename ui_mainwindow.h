/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "mpushbutton.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTableWidget *itemTable;
    QTableWidget *bundleTable;
    mPushButton *loadDatabase;
    mPushButton *cartAdd;
    mPushButton *cartToggle;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(942, 736);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        itemTable = new QTableWidget(centralWidget);
        if (itemTable->columnCount() < 4)
            itemTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        itemTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        itemTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        itemTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        itemTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        itemTable->setObjectName(QStringLiteral("itemTable"));
        itemTable->setGeometry(QRect(40, 10, 841, 281));
        itemTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        itemTable->setAlternatingRowColors(false);
        itemTable->setSelectionMode(QAbstractItemView::ExtendedSelection);
        itemTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        itemTable->setGridStyle(Qt::SolidLine);
        itemTable->setCornerButtonEnabled(true);
        itemTable->horizontalHeader()->setCascadingSectionResizes(false);
        itemTable->horizontalHeader()->setStretchLastSection(true);
        itemTable->verticalHeader()->setVisible(false);
        itemTable->verticalHeader()->setCascadingSectionResizes(false);
        bundleTable = new QTableWidget(centralWidget);
        if (bundleTable->columnCount() < 3)
            bundleTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        bundleTable->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        bundleTable->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        bundleTable->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        bundleTable->setObjectName(QStringLiteral("bundleTable"));
        bundleTable->setGeometry(QRect(40, 300, 841, 181));
        bundleTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        bundleTable->setSelectionMode(QAbstractItemView::ExtendedSelection);
        bundleTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        bundleTable->horizontalHeader()->setStretchLastSection(true);
        bundleTable->verticalHeader()->setVisible(false);
        loadDatabase = new mPushButton(centralWidget);
        loadDatabase->setObjectName(QStringLiteral("loadDatabase"));
        loadDatabase->setGeometry(QRect(50, 510, 211, 41));
        cartAdd = new mPushButton(centralWidget);
        cartAdd->setObjectName(QStringLiteral("cartAdd"));
        cartAdd->setGeometry(QRect(390, 510, 171, 41));
        cartToggle = new mPushButton(centralWidget);
        cartToggle->setObjectName(QStringLiteral("cartToggle"));
        cartToggle->setGeometry(QRect(710, 510, 161, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 942, 39));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Database", nullptr));
        QTableWidgetItem *___qtablewidgetitem = itemTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Product Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = itemTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = itemTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = itemTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Special Attribute", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = bundleTable->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Bundle Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = bundleTable->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = bundleTable->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Savings", nullptr));
        loadDatabase->setText(QApplication::translate("MainWindow", "Load Database", nullptr));
        cartAdd->setText(QApplication::translate("MainWindow", "Add to Cart", nullptr));
        cartToggle->setText(QApplication::translate("MainWindow", "Show Cart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
