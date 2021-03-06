#ifndef MISSIOMODEL_H
#define MISSIOMODEL_H

#include <QObject>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QMetaClassInfo>
#include <QDebug>
#include <QDateTime>

struct Mission{
    unsigned int id = 0;
    QString name = "";
    unsigned int user_id = 0;
    QString start_date = QDateTime::currentDateTime().toString("yyyy-MM-dd | HH-mm");
    QString end_date = QDateTime::currentDateTime().toString("yyyy-MM-dd | HH-mm");
    QString last_action_date = QDateTime::currentDateTime().toString("yyyy-MM-dd | HH-mm");
    bool finished = false;

};

class MissioModel : public QSqlTableModel
{
    Q_OBJECT
    Q_CLASSINFO("author", "Zaur Kadokhov")
    Q_CLASSINFO("email", "kadokhovzaur@yandex.ru")

public:
    explicit MissioModel(QSqlDatabase &aDb, QObject *aParent = Q_NULLPTR);
    bool isDatabaseReady();
    void addMission(const Mission &aMission);
    void changeMission(const Mission &aMission);
    void removeMissionId(const unsigned int &aId);

signals:
    void error(QString);

public slots:

    // QAbstractItemModel interface
public:
    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // MISSIOMODEL_H
