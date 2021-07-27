#include "dfmodel.h"
#include <QDebug>
DFModel::DFModel(QObject *parent)
    :QAbstractListModel(parent)
{
    setupRoles();
}

QModelIndex DFModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row,column,parent))
        return QModelIndex();

    DFModelItem *childItem;

    childItem = _items.at(row);

    if(childItem){
        QModelIndex mIndex = createIndex(row,column,childItem);
        childItem->setModelIndex(mIndex);
        return mIndex;
    }
    return QModelIndex();
}

int DFModel::rowCount(const QModelIndex &parent) const
{
    return _items.count();
}

QVariant DFModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QModelIndex();

    DFModelItem *item = static_cast<DFModelItem *>(index.internalPointer());
    if(index.row() == 0){

    }
    switch(role){
    case role_Frequency:
        return QVariant(item->dfItem()._frequency);
    case Qt::DisplayRole:
        return QVariant(QString::number(item->dfItem()._frequency) + "\t" + QString::number(item->dfItem()._bandWidth) + "\t"  + QString::number(item->dfItem()._gain));
    case role_Bandwidth:
        return QVariant(item->dfItem()._bandWidth);
    case role_threshold:
        return QVariant(item->dfItem()._threshold);
    case role_gain:
        return QVariant(item->dfItem()._gain);
    case role_itemValidity:
        return QVariant(item->validity());
    case role_resolution:
        return QVariant(item->dfItem()._resolution);

    default:
        return QVariant();
    }
}

bool DFModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid()) return false;
    switch(role){
    case role_Bandwidth:
        emit this->dataChanged(index,index,{role_Bandwidth});
        break;
    case role_Frequency:
        emit this->dataChanged(index,index,{role_Frequency});
        break;
    case role_ChannelNO:
        emit this->dataChanged(index,index,{role_ChannelNO});
        break;
    case role_threshold:
        emit this->dataChanged(index,index,{role_threshold});
        break;
    case role_resolution:
        emit this->dataChanged(index,index,{role_resolution});
        break;
    case role_gain:
        emit this->dataChanged(index,index,{role_gain});
        break;
    case role_itemValidity:
        emit this->dataChanged(index,index,{role_itemValidity});
        break;
    default:
        break;
    }
    return false;
}

void DFModel::setupRoles()
{
    _roleNames = QAbstractListModel::roleNames();
    _roleNames.insert(role_Frequency,"Frequency");
    _roleNames.insert(role_Bandwidth,"Bandwidth");
    _roleNames.insert(role_threshold,"Threshold");
    _roleNames.insert(role_resolution,"Resolution");
    _roleNames.insert(role_gain,"Gain");
    _roleNames.insert(role_ChannelNO,"ChannelNumber");
    _roleNames.insert(role_itemValidity,"Validity");

}

void DFModel::setupItemConnectios(DFModelItem *dfItem)
{
    connect(dfItem, &DFModelItem::validityChanged, this, &DFModel::onItemValidityChanged);
}

QHash<int, QByteArray> DFModel::roleNames() const
{
    return _roleNames;
}

void DFModel::clear()
{
    _items.clear();
}

void DFModel::appendItem(DFModelItem *item)
{
    _items.append(item);
    setupItemConnectios(item);
}

void DFModel::appendItem(QList<DFModelItem *> listItems)
{
    QListIterator<DFModelItem*>listIterator(listItems);
    while(listIterator.hasNext()){
        DFModelItem *temp = listIterator.next();
        _items.append(temp);
        setupItemConnectios(temp);
    }
}

void DFModel::onItemValidityChanged(DFModelItem* modelItem)
{
    QModelIndex modelIndex = modelItem->modelIndex();
    emit dataChanged(modelIndex, modelIndex, {role_itemValidity});
}
