#ifndef USERSPAGE_H
#define USERSPAGE_H

#include <QWidget>

class QTableWidget;

class UsersPage : public QWidget
{
public:
    explicit UsersPage(QWidget *parent = nullptr);

private:
    QTableWidget *userTable;

    void loadUsers();
    void editSelectedUser();
};

#endif
