#ifndef MESSAGELISTMODEL_H
#define MESSAGELISTMODEL_H

#include <QAbstractListModel>
#include <collectioninterfaces.h>
#include <vector>
#include <utils.h>

class MessageListModel : public QAbstractListModel, public IMessageListModel
{
    Q_OBJECT

public:
    explicit MessageListModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    int columnCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


public:
    void Add(Message *message) override;

private:
    void add(QString msg, QString userId);
    Message* createMessage(QString userId, QString msg);
private:

    QList<Message*> m_list;
};

#endif // MESSAGELISTMODEL_H
