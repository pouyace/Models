#ifndef DFMODELITEM_H
#define DFMODELITEM_H
#include "DFParameters.h"
#include <QObject>
#include <QModelIndex>
class QTimer;
using namespace DFParameters;
class DFModelItem : public QObject
{
    Q_OBJECT
public:
    DFModelItem();

    bool validity() const;
    void setAllFeatures(double freq, qint64 bw, double threshold, double resolution, double gain, int channelNo);
    void setFrequency(double freq);
    void setBandWidth(qint64 bw);
    void setThreshold(double threshold);
    void setResolution(double resolution);
    void setGain(double gain);
    void setChannelNO(int channelNo);
    void setModelIndex(QModelIndex modelIndex);
    QModelIndex modelIndex() const;
    DFItem dfItem() const;

private:
    DFItem item;
    bool _validity = false;
    QTimer *timerDataValidity = nullptr;
    int duration = 2000;
    QModelIndex _modelIndex;

private://method
    void setupTimer();


public slots:
    void setDFItem(DFItem value);
    void onSetValidity(bool value);
    void setDuration(int value);
    void onSetValidityFalse();

signals:
    void itemChanged(DFItem val);
    void itemValidityChanged(bool);
    void startTimer(int);
    void validityChanged(DFModelItem*);
};

#endif // DFMODELITEM_H
