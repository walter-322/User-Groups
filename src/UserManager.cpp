#include "UserManager.h"
#include <QProcess>
#include <pwd.h>
#include <unistd.h>

QList<User> UserManager::getUsers() const
{
    QList<User> users;

    setpwent();

    struct passwd *entry;

    while ((entry = getpwent()) != nullptr)
    {
        User user;

        user.username = QString::fromLocal8Bit(entry->pw_name);
        user.uid = entry->pw_uid;
        user.gid = entry->pw_gid;
        user.home = QString::fromLocal8Bit(entry->pw_dir);
        user.shell = QString::fromLocal8Bit(entry->pw_shell);

        if (user.uid >= 1000)
        {
            user.type = UserType::Human;
        }
        else
        {
            user.type = UserType::System;
        }

        users.append(user);
    }

    endpwent();

    return users;
}
bool UserManager::updateShell(const QString &username, const QString &shell)
{
    QProcess process;

    process.start("sudo", {
        "usermod",
        "-s",
        shell,
        username
    });

    if (!process.waitForFinished())
        return false;

    return process.exitCode() == 0;
}
