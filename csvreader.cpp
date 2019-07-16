#include "csvreader.h"

void CSVReader::setBuilder(Builder *builder)
{
    m_itemBuilder=builder;
}

void CSVReader::buildItem(const QStringList& list)
{
    m_itemBuilder->addTechnologyType(list[0]);
    m_itemBuilder->addName(list[1]);
    m_itemBuilder->addCompanyName(list[2]);
    m_itemBuilder->addWeight(list[3]);
    m_itemBuilder->addPrice(list[4]);
    m_itemBuilder->addFunFact(list[5]);
}
