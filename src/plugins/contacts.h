#ifndef CONTACTS_H
#define CONTACTS_H

#include "../cplugin.h"

#include <QHash>
#include <QSet>
#include <QVariantMap>
#include <QStringList>
#if QT_VERSION < 0x050000
# include <qmobilityglobal.h>
#else
# include <qcontactsglobal.h>
#endif

#ifdef QTM_NAMESPACE
QTM_BEGIN_NAMESPACE
#elif defined QTCONTACTS_USE_NAMESPACE
QTCONTACTS_BEGIN_NAMESPACE
#endif
class QContact;
class QContactManager;
#ifdef QTM_NAMESPACE
QTM_END_NAMESPACE
QTM_USE_NAMESPACE
#elif defined QTCONTACTS_USE_NAMESPACE
QTCONTACTS_END_NAMESPACE
QTCONTACTS_USE_NAMESPACE
#endif


class Contacts : public CPlugin
{
    Q_OBJECT
public:
    explicit Contacts();

    void init();

signals:

public slots:
    void saveContact(int scId, int ecId, const QVariantMap &params);
    void findContacts(int scId, int ecId, const QStringList &fields, const QString &filter, bool multiple);

private:
    static Contacts *m_contacts;

    QString cordovaFieldNameToQtDefinitionName(const QString &cordovaFieldName) const;
    QString jsonedContact(const QContact &contact, const QStringList &fields = QStringList()) const;

    QHash<QString, QString> m_fieldNamePairs;
    QSet<QString> m_notSupportedFields;
    QContactManager *m_manager;
};

#endif // CONTACTS_H