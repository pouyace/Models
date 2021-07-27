#include <QGuiApplication>
#include <QObject>
#include <QAbstractListModel>
#include <QQmlApplicationEngine>
#include "dfmodel.h"
#include <QApplication>
#include <QListView>
#include <QQmlContext>
//#include <QQuickView>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
//    QApplication a(argc, argv);
    QQmlApplicationEngine engine;//
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    QList<DFModelItem*> modelItems;

    DFItem df;
    df._frequency = 20;
    df._bandWidth = 20;
    df._threshold = 20;
    df._resolution = 20;
    df._gain = 2000;
    df._ChannelNO = 2;
    DFModelItem *dfItem = new DFModelItem();
    dfItem->setFrequency(80);
    dfItem->setBandWidth(80);
    dfItem->setResolution(80);
    dfItem->setThreshold(80);
    dfItem->setGain(80);
    dfItem->setChannelNO(1);

    DFModelItem *dfItem2 = new DFModelItem();
    dfItem2->setFrequency   (785785);
    dfItem2->setBandWidth   (70);
    dfItem2->setResolution  (70);
    dfItem2->setThreshold   (70);
    dfItem2->setGain        (70);
    dfItem2->setChannelNO   (2);

    DFModelItem *dfItem3 = new DFModelItem();
    dfItem3->setFrequency   (90);
    dfItem3->setBandWidth   (90);
    dfItem3->setResolution  (90);
    dfItem3->setThreshold   (90);
    dfItem3->setGain        (90);
    dfItem3->setChannelNO   (3);

//    dfItem3->onSetValidity(1);

    DFModelItem *dfItem4 = new DFModelItem();
    dfItem4->setFrequency   (900);
    dfItem4->setBandWidth   (900);
    dfItem4->setResolution  (900);
    dfItem4->setThreshold   (900);
    dfItem4->setGain        (900);
    dfItem4->setChannelNO   (3);


    dfItem4->setDFItem(df);

    modelItems.append(dfItem);
    modelItems.append(dfItem2);
    modelItems.append(dfItem3);
    modelItems.append(dfItem4);


    DFModel *myModel = new DFModel();
    myModel->appendItem(modelItems);

    engine.rootContext()->setContextProperty("myModel", myModel);
    engine.load(url);
    return app.exec();
}
