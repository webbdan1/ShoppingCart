#ifndef CSVREADER_H
#define CSVREADER_H

#include <QList>
#include <QString>
#include "builder.h"

class CSVReader
{
protected:
    Builder* m_itemBuilder;
public:
    CSVReader()=default;
    virtual ~CSVReader()=default;
    CSVReader(const CSVReader &orig) = default;

    void setBuilder(Builder* builder);
    void buildItem(const QStringList& list);
};

#endif // CSVREADER_H
