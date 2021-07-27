#ifndef DFMODEL_H
#define DFMODEL_H
#include <QObject>
#include <QAbstractListModel>
#include "dfmodelitem.h"

class DFModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Attribute{role_Frequency = Qt::UserRole+1, role_Bandwidth, role_threshold, role_resolution,role_gain,role_ChannelNO,role_itemValidity, role_End};
    DFModel(QObject *parent = nullptr);


//    virtual int columnCount(const QModelIndex &parent) const override;
    virtual QModelIndex index(int row, int column = 0, const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
//    Q_INVOKABLE virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    virtual QHash<int,QByteArray> roleNames() const override;


    QList<DFModelItem> items();
    void clear();
    void appendItem(DFModelItem *item);
    void appendItem(QList<DFModelItem*> listItems);
private slots:
    void onItemValidityChanged(DFModelItem* modelItem);
private:
    QList<DFModelItem*> _items;
    QHash<int ,QByteArray> _roleNames;

    void setupRoles();
    void setupItemConnectios(DFModelItem *dfItem);
};

#endif // DFMODEL_H
