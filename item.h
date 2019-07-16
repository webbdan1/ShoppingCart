#ifndef ITEM_H
#define ITEM_H

#include "merchandise.h"

class Item : public Merchandise
{
protected:
    QString m_companyName;
    QString m_funFact;
    double m_weight;
    QString m_technologyType;

public:
    Item()=default;
    Item(const Item& item)=default;
    virtual ~Item()=default;

    void setCompanyName(const QString& name);
    void setFunFact(const QString& fact);
    void setWeight(const double& weight);
    void setTechnologyType(const QString& tech);
    QString getCompanyName() const;
    QString getFunFact() const;
    double getWeight() const;
    QString getTechnologyType() const;
    virtual void Accept(Visitor* v);
};

#endif // ITEM_H
