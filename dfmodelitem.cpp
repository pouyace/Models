#include "dfmodelitem.h"
#include <QTimer>
#include <QDebug>
DFModelItem::DFModelItem()
{
    setupTimer();

}

bool DFModelItem::validity() const
{
    return _validity;
}

void DFModelItem::setFrequency(double freq)
{
    item._frequency = freq;
}

void DFModelItem::setBandWidth(qint64 bw)
{
    item._bandWidth = bw;
}

void DFModelItem::setThreshold(double threshold)
{
    item._threshold = threshold;
}

void DFModelItem::setResolution(double resolution)
{
    item._resolution = resolution;
}

void DFModelItem::setGain(double gain)
{
    item._gain = gain;
}

void DFModelItem::setChannelNO(int channelNo)
{
    item._ChannelNO = channelNo;
}

void DFModelItem::setModelIndex(QModelIndex modelIndex)
{
    _modelIndex = modelIndex;
}

QModelIndex DFModelItem::modelIndex() const
{
    return _modelIndex;
}

DFItem DFModelItem::dfItem() const
{
    return item;
}

void DFModelItem::setupTimer()
{
    timerDataValidity = new QTimer(this);

    timerDataValidity->setTimerType(Qt::VeryCoarseTimer);

    connect(this,&QObject::destroyed,timerDataValidity,&QObject::deleteLater);
    connect(timerDataValidity  ,&QTimer::timeout   ,this   ,&DFModelItem::onSetValidityFalse);
    connect(this , &DFModelItem::startTimer , timerDataValidity ,static_cast<void (QTimer::*)(int)>(&QTimer::start));

    timerDataValidity->setInterval(duration);
    timerDataValidity->setSingleShot(true);
}

void DFModelItem::onSetValidity(bool value)
{
    if(_validity != value)
    {
        _validity = value;
        emit itemValidityChanged(_validity);
        emit validityChanged(this);
    }
}

void DFModelItem::setDuration(int value)
{
    duration = value;
}

void DFModelItem::onSetValidityFalse()
{
    onSetValidity(false);
}

void DFModelItem::setDFItem(DFItem value)
{
    if(item != value)
    {
        item = value;
        emit this->itemChanged(item);
        emit this->startTimer(duration);
        onSetValidity(true);
    }
}
