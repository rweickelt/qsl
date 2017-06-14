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

#include "serialinterface.h"
#include <rpc/mpimessageheader.h>
#include "mpihostmessage.h"


SerialInterface::SerialInterface()
{
    m_state = Disconnected;

    m_port.setPortName("/dev/ttyACM3");
    m_port.setBaudRate(115200);
    if (!m_port.open(QIODevice::ReadWrite))
    {
        QString errorMessage = QString("Could not open PinProbe driver at '%1': %2").arg(
                   m_port.portName(),
                   m_port.errorString());

        qWarning() << errorMessage;
        ::exit(-1);
    }

    m_state = Connected;
    m_rxState = RxDelimiter;
    m_rxBytesNeeded = 1;
    m_rxBuffer.reserve(1024);

    connect(&m_port, &QSerialPort::readyRead, this, &SerialInterface::handleReadyRead);
    connect(&m_port, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &SerialInterface::handleError);

    QSharedPointer<MpiHostMessage> message(new MpiHostMessage());
    message->header.type = RpcHeader::Reset;
    this->sendMessage(message);
}

SerialInterface::~SerialInterface()
{
    m_port.close();
}


void SerialInterface::handleReadyRead()
{
    while (m_port.bytesAvailable() >= m_rxBytesNeeded)
    {
        const RpcHeader& header = reinterpret_cast<const RpcHeader&>(*m_rxBuffer.data());
        RxState nextState = RxInvalidState;

        switch(m_rxState)
        {
        case RxDelimiter:
            m_rxBuffer.append(m_port.read(m_rxBytesNeeded));
            if (header.delimiters[m_rxBuffer.length() - 1] != RpcHeader::DelimiterByte) {
                m_rxBuffer.clear();
            }
            if (m_rxBuffer.length() == RpcHeader::DelimiterLength) {
                nextState = RxHeader;
                m_rxBytesNeeded = sizeof(RpcHeader) - RpcHeader::DelimiterLength;
            } else {
                nextState = RxDelimiter;
                m_rxBytesNeeded = 1;
            }
            break;
        case RxHeader:
            m_rxBuffer.append(m_port.read(m_rxBytesNeeded));
            if (header.delimiter != RpcHeader::DelimiterWord) {
                nextState = RxDelimiter;
                m_rxBytesNeeded = 1;
            } else {
                nextState = RxPayload;
                m_rxBytesNeeded = header.payloadLength;
            }
            break;
        case RxPayload:
            m_rxBuffer.append(m_port.read(m_rxBytesNeeded));
            // Todo: Check data integrity
        {
            QSharedPointer<MpiHostMessage> message(new MpiHostMessage());
            message->header = header;
            message->data = m_rxBuffer.constData() + sizeof(RpcHeader);
            qDebug() << "Buffer content: " << m_rxBuffer;
            emit messageReceived(message);
        }
            m_rxBuffer.clear();
            m_rxBuffer.reserve(sizeof(RpcHeader));
            nextState = RxHeader;
            m_rxBytesNeeded = sizeof(RpcHeader);
            break;
        case RxInvalidState:
            qFatal("RxInvalid state");
            break;
        }
        m_rxState = nextState;
    }
}


void SerialInterface::handleError(QSerialPort::SerialPortError error)
{
    m_state = Error;
    if (error != QSerialPort::NoError)
    {
        QString message = QString("In SerialInterface at port '%1': %2")
                      .arg(m_port.portName())
                      .arg(m_port.errorString());
        qWarning() << message;
        ::exit(-1);
    }
}


void SerialInterface::sendMessage(QSharedPointer<MpiHostMessage> message)
{
    message->header.delimiter = RpcHeader::DelimiterWord;
    message->header.payloadLength = message->data.length();

    m_port.write(reinterpret_cast<const char*>(&message->header), sizeof(RpcHeader));
    m_port.write(reinterpret_cast<const char*>(message->data.constData()), message->data.length());
    m_port.flush();
}

