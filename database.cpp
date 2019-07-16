#include "database.h"

Database::Database(const QString& technology, const QString& bundles)
{
  m_technologyFile = technology;
  m_bundlesFile = bundles;
  m_itemBuilder = new ItemBuilder();
  m_director = new CSVReader();
}

Database::~Database()
{
    delete m_itemBuilder;
    delete m_director;
    for(unsigned i=0;i<m_items.size();i++){
        delete m_items[i];
        delete m_directors[i];
        delete m_builders[i];
    }
    for(unsigned i=0;i<m_bundles.size();i++){
        delete m_bundles[i];
    }
}

void Database::loadDatabase()
{
    /***** build all items in Technology file *****/

    //open csv file
    QString backPath = "/home/daniel/dev/335/project02/Renner_Webb_Project2/Renner_Webb_Project2/";
    QFile f1(backPath + m_technologyFile);

    //if failed file open
    if(!f1.open(QIODevice::ReadOnly))
    {
        // gives the reason opening the file didn’t work. Usually because it wasn’t found.
        qDebug() << f1.errorString();
        // gives the current path the program’s .exe file is running at
        qDebug() << QDir::currentPath();
        throw f1.error();
    }
    //if successful file open
    else{
        //read each line
        while (!f1.atEnd())
       {
          //set up builder and director
          m_director = new CSVReader();
          m_itemBuilder = new ItemBuilder;
          m_directors.push_back(m_director);
          m_builders.push_back(m_itemBuilder);
          m_director->setBuilder(m_itemBuilder);
          QString line = f1.readLine();
          QStringList list = line.split(",");
          //pass line by line to director for building
          m_director->buildItem(list);
          //retrieve newly built item, push to container
          Item* item = m_itemBuilder->getItem();
          m_items.push_back(item);
       }
       f1.close();
    }

    //open csv file
    QFile f2(backPath + m_bundlesFile);
    //test open success
    if(!f2.open(QIODevice::ReadOnly))
    {
        //gives the reason opening the file didn’t work. Usually because it wasn’t found.
        qDebug() << f2.errorString();
        //gives the current path the program’s .exe file is running at
        qDebug() << QDir::currentPath();
        throw f2.error();
    }
    // if successful file open
    else{
        //read each line
        while (!f2.atEnd())
       {
          QString line = f2.readLine();
          QStringList list = line.simplified().split(",");
          //new bundle
          Bundle* bundle = new Bundle(list[0],list[1].toDouble());
          //add required items
          for(int i=2;i<list.length();i++){
              QString name=list[i];
              for(unsigned j=0; j < m_items.size(); j++){
                  if(m_items[j]->getName()==name){
                      bundle->addItem(m_items[j]);
                  }
              }
          }

          bundle->Accept(&m_v);
          // Subtract the price of the bundle you're checking, as that was
          // added to the total when being visited.
          double result = m_v.getResult();
          result -= bundle->getPrice();
          double savings = (result - bundle->getPrice())/result;
          bundle->setSavings(savings * 100);

          //push back newly created composite to m_bundles
          m_bundles.push_back(bundle);
       }
       f2.close();
    }
}

vector<Item*> Database::getItems() const
{
    return m_items;
}

vector<Bundle*> Database::getBundles() const
{
    return m_bundles;
}

QString Database::getBundlesFile() const
{
    return m_bundlesFile;
}

QString Database::getTechnologyFile() const
{
    return m_technologyFile;
}

void Database::setBundlesFiles(const QString &file)
{
    m_bundlesFile=file;
}

void Database::setTechnologyFile(const QString &file)
{
    m_technologyFile=file;
}
