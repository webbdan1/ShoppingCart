#include "merchandise.h"

void Merchandise::setName(const QString &name)
{
    m_name = name;
}

void Merchandise::setPrice(const double &price)
{
    m_price = price;
}

double Merchandise::getPrice() const
{
    return m_price;
}

QString Merchandise::getName() const
{
    return m_name;
}
