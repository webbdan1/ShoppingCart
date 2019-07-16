#ifndef VISITOR_H
#define VISITOR_H
class Item;
class Bundle;

class Visitor
{
protected:
    Visitor() = default;
    Visitor(const Visitor& item) = default;
    virtual ~Visitor() = default;

public:
    virtual void VisitItem(Item*) = 0;
    virtual void VisitBundle(Bundle*) = 0;
    virtual double getResult() = 0;
};

#endif // VISITOR_H
