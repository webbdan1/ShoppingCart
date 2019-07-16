#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    m_database = new Database();
    ui->setupUi(this);

    connect(cart, SIGNAL(checkout()), this, SLOT(checkout()));
    connect(cart, SIGNAL(close()), ui->cartToggle, SLOT(beenClicked()));
    connect(ui->cartToggle, SIGNAL(clicked()), ui->cartToggle,
            SLOT(beenClicked()));
    connect(ui->cartToggle, SIGNAL(iChanged(QObject*)), this,
            SLOT(actOnChange(QObject*)));
    connect(ui->loadDatabase, SIGNAL(clicked()), ui->loadDatabase,
            SLOT(beenClicked()));
    connect(ui->loadDatabase, SIGNAL(iChanged(QObject*)), this,
            SLOT(actOnChange(QObject*)));
    connect(ui->cartAdd, SIGNAL(clicked()), ui->cartAdd,
            SLOT(beenClicked()));
    connect(ui->cartAdd, SIGNAL(iChanged(QObject*)), this,
            SLOT(actOnChange(QObject*)));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_database;
}

void MainWindow::actOnChange(QObject* obj) {
    if (obj == ui->cartToggle) {
        if (ui->cartToggle->text() == "Show Cart") {
            cart->show();
            ui->cartToggle->setText("Hide Cart");
        } else {
            cart->hide();
            ui->cartToggle->setText("Show Cart");
        }
    } else if (obj == ui->loadDatabase) {
        ui->loadDatabase->setDisabled(true);
        // Load Data code
        m_database->loadDatabase();
        vector<Item*> items = m_database->getItems();
        vector<Bundle*> bundles = m_database->getBundles();
        for(int i=0; i<items.size();i++){
            //create new table item and fill fields
            QTableWidgetItem *name = new QTableWidgetItem;
            name->setText(items[i]->getName());
            QTableWidgetItem *techType = new QTableWidgetItem;
            techType->setText(items[i]->getTechnologyType());
            QTableWidgetItem *price = new QTableWidgetItem;
            QString priceAsString = QString::number(items[i]->getPrice());
            price->setText(priceAsString);
            QTableWidgetItem *fact = new QTableWidgetItem;
            fact->setText(items[i]->getFunFact());
            //add to table
            ui->itemTable->insertRow(i);
            ui->itemTable->setItem(i,0, name);
            ui->itemTable->setItem(i,1, techType);
            ui->itemTable->setItem(i,2, price);
            ui->itemTable->setItem(i,3, fact);
        }
        for(int i=0; i<bundles.size();i++){
            //create new table item and fill fields
            QTableWidgetItem *name = new QTableWidgetItem;
            name->setText(bundles[i]->getName());
            QTableWidgetItem *price = new QTableWidgetItem;
            QString priceAsString = QString::number(bundles[i]->getPrice());
            price->setText(priceAsString);
            QTableWidgetItem *savings = new QTableWidgetItem;
            QString savingsAsString = QString::number((qRound(bundles[i]->getSavings())));
            savings->setText(savingsAsString + "%");
            //add to table
            ui->bundleTable->insertRow(i);
            ui->bundleTable->setItem(i,0, name);
            ui->bundleTable->setItem(i,1, price);
            ui->bundleTable->setItem(i,2, savings);

        }
    } else if (obj == ui->cartAdd) {
        // Grab the selections and get the name and price for each to transfer
        // over to the shopping cart
        QList<QTableWidgetItem*> items = ui->itemTable->selectedItems();
        QList<QTableWidgetItem*> bundles = ui->bundleTable->selectedItems();
        QString name;
        QString price;
        vector<Item*> data_items = m_database->getItems();
        vector<Bundle*> data_bundles = m_database->getBundles();
        Item *item = new Item;
        Bundle *bundle = new Bundle;
        for (int i = 0; i < items.size(); i += 4) {
            for (unsigned j = 0; j < data_items.size(); j++) {
                if (items[i]->text() == data_items[j]->getName()) {
                    item = data_items[j];
                    emit(addMerch(item));
                    break;
                }

            }
        }
        for (int i = 0; i < bundles.size(); i += 3) {
            for (unsigned j = 0; j < data_bundles.size(); j++) {
                if (bundles[i]->text() == data_bundles[j]->getName()) {
                    bundle = data_bundles[j];
                    emit(addMerch(bundle));
                    break;
                }

            }
        }
    }
}

void MainWindow::checkout() {
    ui->loadDatabase->setDisabled(true);
    ui->cartAdd->setDisabled(true);
    ui->cartToggle->setDisabled(true);
}
