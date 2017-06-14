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

#ifndef SERIALINTERFACE_H
#define SERIALINTERFACE_H

#include <QtCore/QByteArray>
#include <QtCore/QHash>
#include <QtCore/QObject>
#include <QtCore/QSharedPointer>
#include <QtCore/QTimer>
#include <QtSerialPort/QtSerialPort>

class Pin;
class MpiHostMessage;

class SerialInterface : public QObject
{
    Q_OBJECT

public:
    SerialInterface();
    ~SerialInterface();

    enum State {
        Disconnected,
        Connected,
        Error
    };

signals:
    void messageReceived(QSharedPointer<MpiHostMessage>);

public slots:
    void sendMessage(QSharedPointer<MpiHostMessage> message);

private slots:
    void handleReadyRead();
    //void handleTimeout();
    void handleError(QSerialPort::SerialPortError error);

private:
    enum RxState
    {
        RxDelimiter,
        RxHeader,
        RxPayload,
        RxInvalidState
    };

    void sendTxMessage(const QByteArray& data);

    QSerialPort m_port;
    State m_state;

    RxState m_rxState;
    QByteArray m_rxBuffer;
    quint32 m_rxBytesNeeded;
};


#endif // SERIALINTERFACE_H
