#ifndef BUILDER_H
#define BUILDER_H

#include <QString>
#include "merchandise.h"
#include "item.h"

class Builder
{
protected:
    Builder()=default;
    virtual ~Builder()=default;
public:
    virtual void addName(QString name)=0;
    virtual void addPrice(QString price)=0;
    virtual void addTechnologyType(QString tech)=0;
    virtual void addCompanyName(QString name)=0;
    virtual void addWeight(QString weight)=0;
    virtual void addFunFact(QString fact)=0;
    virtual Item* getItem()= 0;
};

#endif // BUILDER_H
