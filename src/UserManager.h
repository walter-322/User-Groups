#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <QString>
#include <QList>

enum class UserType
{
    Human,
    System
};

struct User
{
    QString username;
    int uid;
    int gid;
    QString home;
    QString shell;
    UserType type;
};

class UserManager
{
public:
    QList<User> getUsers() const;
    bool updateShell(const QString &username, const QString &shell);
};

#endif // USERMANAGER_H
