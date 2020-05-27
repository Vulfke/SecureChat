#include "messagelistmodel.h"

MessageListModel::MessageListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

QVariant MessageListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}

int MessageListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return m_list.size();
}

int MessageListModel::columnCount(const QModelIndex &parent) const {
    return 1;
}

QVariant MessageListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if(role == Qt::DisplayRole) {
        switch(index.column()) {
        case 0:
            return QVariant(QString(m_list[index.row()]->Msg().c_str()));
        }
    }

    // FIXME: Implement me!
    return QVariant();
}

void MessageListModel::Add(Message *message)
{
    beginResetModel();
    m_list.push_back(message);
    endResetModel();
}
