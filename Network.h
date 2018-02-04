#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QtMath>
#include <QDebug>
#include "IPv4Address.h"

class IPv4Address;

class Network : public QObject
{
    Q_OBJECT

  public:
    explicit Network(IPv4Address *address, int maskLength, QObject *parent = nullptr);
    Network(const Network &other);

    virtual ~Network();

    bool contains(IPv4Address *address);
    QString toString() const;
    IPv4Address *getAddress() const;
    IPv4Address *getBroadcastAddress() const;
    IPv4Address getFirstUsableAddress();
    IPv4Address getLastUsableAddress();
    quint32 getMask() const;
    QString getMaskString() const;
    int getMaskLength() const;
    quint32 getHost() const;
    QVector<Network*> getSubnets(); // produce two half-sized subnets
    long getTotalHosts(); // excluding network and broadcast
    bool isPublic();

    Network& operator=(Network *other);

  private:
    quint32 m_prefix;
    quint32 m_host;
    int m_maskLen;
    IPv4Address *m_address;
    IPv4Address *m_broadcast;


  signals:

  public slots:
};

#endif // NETWORK_H
