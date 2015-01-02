#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QtQml>
#include "../common/boardmodel.h"
#include "../common/boardlistmodelwrapper.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    BoardModel * model = new BoardModel(13, 13);
    BoardListModelWrapper * listWrapper = new BoardListModelWrapper(model);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("boardTableModel",  model);
    engine.rootContext()->setContextProperty("boardListModel",  listWrapper);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
