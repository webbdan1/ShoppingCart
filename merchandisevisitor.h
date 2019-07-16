#ifndef MERCHANDISEVISITOR_H
#define MERCHANDISEVISITOR_H
#include "visitor.h"
#include "merchandise.h"
#include "item.h"
#include "bundle.h"
#include <stack>
using std::stack;

class MerchandiseVisitor : public Visitor
{
private:
    stack<double> price_stack;

public:
    MerchandiseVisitor() = default;
    MerchandiseVisitor(const MerchandiseVisitor &orig) = default;
    virtual ~MerchandiseVisitor() = default;

    virtual void VisitItem(Item* item);
    virtual void VisitBundle(Bundle* bundle);
    virtual double getResult();

};

#endif // MERCHANDISEVISITOR_H
