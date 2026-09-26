#include "UsersPage.h"
#include "UserManager.h"
#include "EditUserDialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>
#include <QMessageBox>

UsersPage::UsersPage(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *title = new QLabel("Users", this);
    title->setStyleSheet("font-size: 20px; font-weight: bold;");

    layout->addWidget(title);

    userTable = new QTableWidget(this);

    userTable->setColumnCount(5);

    userTable->setHorizontalHeaderLabels({
        "Username",
        "UID",
        "GID",
        "Home",
        "Shell"
    });

    userTable->horizontalHeader()->setStretchLastSection(true);
    userTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    userTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    layout->addWidget(userTable);
    QPushButton *editButton = new QPushButton(
    "Edit User",
    this
	);
	
	layout->addWidget(editButton);
	
	connect(
	    editButton,
	    &QPushButton::clicked,
	    this,
	    &UsersPage::editSelectedUser
	);

    loadUsers();
}

void UsersPage::loadUsers()
{
    UserManager manager;
    QList<User> users = manager.getUsers();

    userTable->setRowCount(users.size());

    for (int row = 0; row < users.size(); ++row)
    {
        const User &user = users[row];

        userTable->setItem(
            row, 0,
            new QTableWidgetItem(user.username)
        );

        userTable->setItem(
            row, 1,
            new QTableWidgetItem(QString::number(user.uid))
        );

        userTable->setItem(
            row, 2,
            new QTableWidgetItem(QString::number(user.gid))
        );

        userTable->setItem(
            row, 3,
            new QTableWidgetItem(user.home)
        );

        userTable->setItem(
            row, 4,
            new QTableWidgetItem(user.shell)
        );
    }
}
void UsersPage::editSelectedUser()
{
    int row = userTable->currentRow();

    if (row < 0)
    {
        QMessageBox::information(
            this,
            "Edit User",
            "Please select a user first."
        );

        return;
    }

    QString username =
        userTable->item(row, 0)->text();

    QString shell =
        userTable->item(row, 4)->text();

    EditUserDialog dialog(
        username,
        shell,
        this
    );

    if (dialog.exec() == QDialog::Accepted)
    {
        loadUsers();
    }
}
