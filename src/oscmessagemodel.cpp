/***************************************************************************
** Polarize Positioning                                                   **
**                                                                        **
** Copyright (C) 2018                                             **
**                                                                        **
** This program is free software; you can redistribute it and/or modify   **
** it under the terms of the GNU General Public License as published by   **
** the Free Software Foundation; either version 3 of the License, or      **
** (at your option) any later version.                                    **
** This program is distributed in the hope that it will be useful,        **
** but WITHOUT ANY WARRANTY; without even the implied warranty of         **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          **
** GNU General Public License for more details.                           **
** You should have received a copy of the GNU General Public License      **
** along with this program; if not, write to the Free Software Foundation,**
** Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA      **
***************************************************************************/
#include "oscmessagemodel.h"

OSCMessageModel::OSCMessageModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

QVariant OSCMessageModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    return QVariant();
}

int OSCMessageModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return messagesReceived.size();
}

QVariant OSCMessageModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!

    if (role==Qt::DisplayRole) {
        return messagesReceived.value(index.row());
    }
    return QVariant();
}

bool OSCMessageModel::addMessage(const QString &message)
{

    int row = messagesReceived.size();
    beginInsertRows(QModelIndex(), row, row);
    messagesReceived.append(message);
    endInsertRows();

    // Prune as necessary
    pruneMessages();

    return true;
}

void OSCMessageModel::setMaxMessages(int messages)
{
     if (messages > 0 )
         retainedMessages = messages;
     pruneMessages();
}

// Remove messages > max number set to retain.
void OSCMessageModel::pruneMessages()
{
    if (messagesReceived.count() >= retainedMessages) {
        beginRemoveRows(QModelIndex(), 0, 0);
        messagesReceived.removeAt(0);
        endRemoveRows();
    }
}
bool OSCMessageModel::clear()
{
    beginResetModel();
    messagesReceived.clear();
    endResetModel();

    return true;
}
