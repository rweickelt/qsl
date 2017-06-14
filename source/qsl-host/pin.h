/****************************************************************************
 ** $BEGIN_LICENSE$
 **
 ** Quick System Loader
 ** Copyright (C) 2017 QSL Project
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.

 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.

 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **
 ** $END_LICENSE$
****************************************************************************/

#ifndef PIN_H
#define PIN_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include "mpihostobject.h"

class Pin : public QObject, public MpiHostObject
{
    Q_OBJECT

    Q_PROPERTY(quint32 ioid MEMBER m_ioid)
    Q_PROPERTY(QString type MEMBER m_type)
    Q_PROPERTY(quint32 value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit Pin(QObject *parent = 0);
    quint32 value() const;
    void setValue(quint32 value);

signals:
    void valueChanged();

protected:
    QByteArray serialize() const override;
    void callMethod(const QSharedPointer<MpiHostMessage>& message) override;

private:
    quint32 m_ioid;
    QString m_type;
    quint32 m_value;
};

inline quint32 Pin::value() const { return m_value; }

#endif // PIN_H
