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

#ifndef RPCOBJECT_H
#define RPCOBJECT_H

#include <QtCore/QSharedPointer>
#include <QtCore/QtGlobal>

class MpiHostMessage;

/*
Objects of this class can be serialized and cloned on a remote unit. They are
then losely connected. An RpcObject instance may call slots on the remote
target unit whereas remote objects may call slots on the host unit.

After registering at RpcHost, an RpcObject gets assigned a 32 bit identifier
which is similar to the address on the target for simplicity.
*/
class MpiHostObject
{
    friend class MpiHost;

public:
    MpiHostObject();
    virtual ~MpiHostObject();

protected:
    virtual void callMethod(const QSharedPointer<MpiHostMessage>& message) = 0;
    quint32 id() const;
    virtual QByteArray serialize() const = 0;

private:
    MpiHostObject(const MpiHostObject&);
    MpiHostObject& operator=(const MpiHostObject&);

    quint32 m_id;
};

inline quint32 MpiHostObject::id() const { return m_id; }

#endif // RPCOBJECT_H
