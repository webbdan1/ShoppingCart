#include "itembuilder.h"

void ItemBuilder::addName(QString name)
{
    m_item->setName(name);
}

void ItemBuilder::addPrice(QString price)
{
    m_item->setPrice(price.toDouble());
}

void ItemBuilder::addTechnologyType(QString tech)
{
    m_item->setTechnologyType(tech);
}

void ItemBuilder::addCompanyName(QString name)
{
    m_item->setCompanyName(name);
}

void ItemBuilder::addWeight(QString weight)
{
    m_item->setWeight(weight.toDouble());
}

void ItemBuilder::addFunFact(QString fact)
{
    m_item->setFunFact(fact);
}

Item* ItemBuilder::getItem()
{
    return m_item;
}
