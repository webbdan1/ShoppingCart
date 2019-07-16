#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QList>
#include <vector>
using std::vector;
#include "itembuilder.h"
#include "csvreader.h"
#include "item.h"
#include "bundle.h"
#include "merchandise.h"
#include "merchandisevisitor.h"

class Database
{
protected:
    QString m_technologyFile;
    QString m_bundlesFile;
    ItemBuilder* m_itemBuilder;
    CSVReader* m_director;
    vector<Item*> m_items;
    vector<Bundle*> m_bundles;
    MerchandiseVisitor m_v;
    vector<CSVReader*> m_directors;
    vector<ItemBuilder*> m_builders;
public:
    Database(const QString& technology="Technology.csv", const QString& bundles="Bundles.csv");
    Database(const Database &orig) = default;
    virtual ~Database();

    void loadDatabase();
    vector<Item*> getItems() const;
    vector<Bundle*> getBundles() const;
    QString getTechnologyFile() const;
    QString getBundlesFile() const;
    void setTechnologyFile(const QString& file);
    void setBundlesFiles(const QString& file);
};

#endif // DATABASE_H
