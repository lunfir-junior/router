#include "QDebug"
#include "IPv4Address.h"

IPv4Address::IPv4Address(QString address, QObject *parent) : QObject(parent)
{
  QRegularExpressionMatch match;

  m_ipRegExp = new QRegularExpression("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");

  match = m_ipRegExp->QRegularExpression::match(&address);

  qDebug() << ( match.hasMatch() ? "matched  " : "dismatched  " ) << address;

//  delete *match;
}

IPv4Address::~IPv4Address() {

  delete m_ipRegExp;
}



