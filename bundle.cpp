#include "bundle.h"

Bundle::~Bundle()
{
    for(unsigned i=0;i<m_items.size(); i++){
        delete m_items[i];
    }
}

void Bundle::removeItem(Merchandise *item)
{
    remove(m_items.begin(),m_items.end(),item);
}

Merchandise* Bundle::getChild(unsigned int index)
{
    return m_items[index];
}

Bundle::Bundle(const QString& name, const double& price)
{
    m_name = name;
    m_price = price;
}

void Bundle::addItem(Merchandise* item)
{
    m_items.push_back(item);
}

void Bundle::setSavings(double savings) {
    m_savings = savings;
}

vector<Merchandise*> Bundle::getItems() const
{
    return m_items;
}

double Bundle::getSavings() const
{
    return m_savings;
}

unsigned int Bundle::getSize() const
{
    return m_items.size();
}

void Bundle::Accept(Visitor *v)
{
    v->VisitBundle(this);
}
