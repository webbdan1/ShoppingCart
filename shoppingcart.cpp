#include "shoppingcart.h"
#include "ui_shoppingcart.h"

ShoppingCart::ShoppingCart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShoppingCart)
{
    ui->setupUi(this);
    // send a merchandise object as the addItem(Merch) function parameter
    connect(this->parent(), SIGNAL(addMerch(Merchandise*)), this,
            SLOT(addMerch(Merchandise*)));
    connect(ui->deleteItem, SIGNAL(clicked()), ui->deleteItem,
            SLOT(beenClicked()));
    connect(ui->deleteItem, SIGNAL(iChanged(QObject*)), this,
            SLOT(actOnChange(QObject*)));
    connect(ui->checkout, SIGNAL(clicked()), ui->checkout,
            SLOT(beenClicked()));
    connect(ui->checkout, SIGNAL(iChanged(QObject*)), this,
            SLOT(actOnChange(QObject*)));
}

ShoppingCart::~ShoppingCart()
{
    delete ui;
}

void ShoppingCart::actOnChange(QObject* obj) {
    if (obj == ui->deleteItem) {
        QList<QTableWidgetItem*> items = ui->itemTable->selectedItems();
        QSet<int> rowset;
        for (int i = 0; i < items.size(); i++) {
            rowset.insert(items[i]->row());
        }
        //remove selected items from cart
        QList<int> rowlist = rowset.toList();
        std::sort(rowlist.begin(), rowlist.end());
        std::reverse(rowlist.begin(), rowlist.end());
        for (int i = 0; i < rowlist.size(); i++) {
            ui->itemTable->removeRow(rowlist[i]);
        }
    } else if (obj == ui->checkout) {
        QPalette palette;
        palette.setColor(QPalette::WindowText, Qt::red);
        ui->totalLabel->setPalette(palette);
        QString total_str = "TOTAL: $";
        QList<QTableWidgetItem*> items;

        for (int i = 0; i < (ui->itemTable->rowCount()); i++) {
            items.append(ui->itemTable->item(i, 1));
        }
        double total = 0.0;
        //add up total
        for (int i = 0; i < items.size(); i++) {
            total += (items[i]->text()).toDouble();
        }
        total_str = total_str + QString::number(total, 'f', 2);
        ui->totalLabel->setText(total_str);
        ui->checkout->setDisabled(true);
        ui->deleteItem->setDisabled(true);
    }
}

void ShoppingCart::on_checkout_clicked()
{
    emit checkout();
}

void ShoppingCart::addMerch(Merchandise* merch) {
    //new table items
    QTableWidgetItem *merch_name = new QTableWidgetItem;
    QTableWidgetItem *merch_price = new QTableWidgetItem;
    int rows = ui->itemTable->rowCount();
    merch_name->setText(merch->getName());
    merch_price->setText(QString::number(merch->getPrice()));
    //add to table
    ui->itemTable->insertRow(rows);
    ui->itemTable->setItem(rows, 0, merch_name);
    ui->itemTable->setItem(rows, 1, merch_price);
}

void ShoppingCart::closeEvent(QCloseEvent* event) {
    emit close();
    event->accept();
}
