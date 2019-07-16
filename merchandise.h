#ifndef MERCHANDISE_H
#define MERCHANDISE_H

#include<QString>
#include "visitor.h"

class Merchandise
{
protected:
    QString m_name;
    double m_price;

public:

    Merchandise()=default;
    Merchandise(const Merchandise& merch)=default;
    virtual ~Merchandise()=default;

    QString getName() const;
    double getPrice() const;
    void setName(const QString& name);
    void setPrice(const double& price);
    virtual void Accept(Visitor*) = 0;
};

#endif // MERCHANDISE_H
