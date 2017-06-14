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

#include <QtCore/QGlobalStatic>
#include "mpihost.h"

class SingleMpiHost : public MpiHost
{
public:
    SingleMpiHost() {}
};

Q_GLOBAL_STATIC(SingleMpiHost, singleHostInstance)

quint32 instances = 0;

MpiHost::MpiHost() : QObject()
{

}


MpiHost* MpiHost::instance()
{
    return singleHostInstance();
}


void MpiHost::parseMessage(QSharedPointer<MpiHostMessage> message)
{
    MpiHostObject* object = m_objects.value(message->header.objectId, NULL);
    Q_ASSERT_X(object != NULL, "MpiHost", qPrintable(QString("No object found for %1").arg(message->header.objectId)));
    object->callMethod(message);
}


quint32 MpiHost::registerInstance(MpiHostObject *object)
{
    instances++;
    m_objects.insert(instances, object);
    return instances;
}


void MpiHost::unregisterInstance(const MpiHostObject* object)
{
    m_objects.remove(object->id());
}

