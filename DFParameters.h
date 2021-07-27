#ifndef DFPARAMETERS_H
#define DFPARAMETERS_H
#include <QObject>

namespace DFParameters{

enum DFOperationMode {
    Fix,
    Scan
};

struct DFItem{
    double  _frequency =0;
    qint64  _bandWidth =0;
    double  _threshold;
    double  _resolution;
    double  _gain;
    int     _ChannelNO;

    inline bool operator != (const DFItem &b){
        return (_gain!=b._gain)
                && (_ChannelNO!=b._ChannelNO)
                && (_bandWidth!=b._bandWidth)
                && (_frequency!=b._frequency)
                && (_threshold!=b._threshold)
                && (_resolution!=b._resolution);}
};

struct DFDirection{
    double azimuth;
    double elevation;
    double QUALITY;
    double AzimuthDeviation;

    inline bool operator != (const DFDirection &b){
        return (azimuth!=b.azimuth)
                && (elevation!=b.elevation)
                && (QUALITY!=b.QUALITY)
                && (AzimuthDeviation!=b.AzimuthDeviation);}

};

}
#endif // DFPARAMETERS_H
