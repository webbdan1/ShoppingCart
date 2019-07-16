#include "item.h"

void Item::setCompanyName(const QString &name)
{
    m_companyName=name;
}

void Item::setTechnologyType(const QString &tech)
{
    m_technologyType=tech;
}

void Item::setFunFact(const QString &fact)
{
    m_funFact=fact;
}

void Item::setWeight(const double &weight)
{
    m_weight=weight;
}

QString Item::getCompanyName() const
{
    return m_companyName;
}

QString Item::getFunFact() const
{
    return m_funFact;
}

double Item::getWeight() const
{
    return m_weight;
}

QString Item::getTechnologyType() const
{
    return m_technologyType;
}

void Item::Accept(Visitor *v) {
    v->VisitItem(this);
}
