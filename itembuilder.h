#ifndef ITEMBUILDER_H
#define ITEMBUILDER_H

#include "builder.h"
#include "item.h"

class ItemBuilder : public Builder
{
protected:
    Item* m_item;
public:
    ItemBuilder(){
        m_item = new Item();
    };
    ItemBuilder(const ItemBuilder& builder)=default;
    virtual ~ItemBuilder(){
        delete m_item;
    };

    void addName(QString name);
    void addPrice(QString price);
    void addTechnologyType(QString tech);
    void addCompanyName(QString name);
    void addWeight(QString weight);
    void addFunFact(QString fact);
    Item* getItem();
};

#endif // ITEMBUILDER_H
