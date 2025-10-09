#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "signalsclass.h"



int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    SignalsClass testClass;

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("trims_automodinstaller", "Main");

    QQmlContext * rootContext = engine.rootContext();
    rootContext->setContextProperty("classA", &testClass) ;

    return app.exec();
}
