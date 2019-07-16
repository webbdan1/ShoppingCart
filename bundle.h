#ifndef BUNDLE_H
#define BUNDLE_H

#include <vector>
using std::vector;
#include "item.h"
#include "merchandise.h"

class Bundle : public Merchandise
{
protected:
    vector<Merchandise*> m_items;
    double m_savings;

public:
    Bundle()=default;
    Bundle(const QString& name, const double& price);
    Bundle(const Bundle& item)=default;
    virtual ~Bundle();

    void addItem(Merchandise* item);
    void removeItem(Merchandise* item);
    void setSavings(double);
    Merchandise* getChild(unsigned int index);
    vector<Merchandise*> getItems() const;
    double getSavings() const;
    unsigned int getSize() const;
    virtual void Accept(Visitor* v);
};

#endif // BUNDLE_H
