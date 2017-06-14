/****************************************************************************
 ** $BEGIN_LICENSE$
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

#include <QtCore/QCoreApplication>
#include <QtQml/QQmlApplicationEngine>

#include "pin.h"
#include "mpihost.h"
#include "serialinterface.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    qmlRegisterType<Pin>("qsl", 1,0, "Pin");

    QQmlApplicationEngine engine;
    engine.addImportPath("../share/qsl/imports");
    engine.load("../examples/pintestapplication.qml");
    return app.exec();
}
