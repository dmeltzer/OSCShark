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
#ifndef IPLINEEDIT_H
#define IPLINEEDIT_H

#include <QLineEdit>
#include <QFrame>

//=============================================================================
class CustomIpEditor : public QFrame
{
    Q_OBJECT
public:
    explicit CustomIpEditor(QWidget *parent = nullptr);
    virtual ~CustomIpEditor() {}
};

//=============================================================================
class IPLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    IPLineEdit(QWidget *parent = nullptr);
    IPLineEdit(const QString & contents = "", QWidget *parent = nullptr);
    virtual ~IPLineEdit() {}

signals:
    void jumpForward();
    void jumpBackward();

public slots:
    void jumpIn();

protected:
    virtual void focusInEvent(QFocusEvent *event);
    virtual void keyPressEvent(QKeyEvent * event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    bool selectOnMouseRelease;
};

#endif // IPLINEEDIT_H
