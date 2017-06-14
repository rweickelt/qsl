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

#ifndef RPCHOST_H
#define RPCHOST_H

#include <QtCore/QHash>
#include <QtCore/QObject>
#include <QtCore/QSharedPointer>

#include "mpihostmessage.h"
#include "mpihostobject.h"

class MpiHost : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(MpiHost)

public:

    quint32 registerInstance(MpiHostObject* object);
    void unregisterInstance(const MpiHostObject* object);
    static MpiHost* instance();

public slots:
    void parseMessage(QSharedPointer<MpiHostMessage> message);

signals:
    void messageCreated(QSharedPointer<MpiHostMessage>);

public slots:

private:
    friend class SingleRpcHost;

    MpiHost();

    QHash<quint32, MpiHostObject*> m_objects;

};

#endif // RPCHOST_H
