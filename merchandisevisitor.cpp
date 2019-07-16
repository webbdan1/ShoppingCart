#include "merchandisevisitor.h"

void MerchandiseVisitor::VisitItem(Item* item) {
    price_stack.push(item->getPrice());
}

void MerchandiseVisitor::VisitBundle(Bundle* bundle) {
    double sum = bundle->getPrice();
    for (unsigned i = 0; i < bundle->getSize(); i++) {
        bundle->getChild(i)->Accept(this);
    }
    for (unsigned i = 0; i < bundle->getSize(); i++) {
        sum += price_stack.top();
        price_stack.pop();
    }
    price_stack.push(sum);
}

double MerchandiseVisitor::getResult()  {
    double result = price_stack.top();
    price_stack.pop();
    return result;
}
