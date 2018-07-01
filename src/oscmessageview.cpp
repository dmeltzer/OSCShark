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
#include "oscmessageview.h"

#include <QScrollBar>
OSCMessageView::OSCMessageView(QWidget *parent)
    : QListView(parent)
{
     setViewMode(QListView::ListMode);
     setMinimumWidth(650);
     setMinimumHeight(400);



}

void OSCMessageView::setModel(QAbstractItemModel *itemModel)
{
    QListView::setModel(itemModel);
    connect(model(), SIGNAL(rowsAboutToBeInserted(const QModelIndex &,int,int)), this, SLOT(storeIndex()));
    connect(model(), SIGNAL(rowsAboutToBeRemoved(const QModelIndex &,int,int)), this, SLOT(storeIndex()));
    connect(model(), SIGNAL(rowsInserted(const QModelIndex &,int,int)), this, SLOT(maintainScroll(const QModelIndex &,int,int)));
    connect(model(), SIGNAL(rowsRemoved(const QModelIndex &,int,int)), this, SLOT(maintainScroll(const QModelIndex &,int,int)));
}

void OSCMessageView::storeIndex()
{
    m_topIndex = indexAt(QPoint(8,8));
}

void OSCMessageView::maintainScroll(const QModelIndex &parent, int begin, int end)
{
    // If we are at the bottom and an item is inserted, continue to scroll down
    QScrollBar *bar = verticalScrollBar();
    if (bar->value() == bar->maximum())
    {
        scrollToBottom();
    }
    // Otherwise remain in place
    scrollTo(m_topIndex, QAbstractItemView::PositionAtTop); // Grab First index in view;

}
