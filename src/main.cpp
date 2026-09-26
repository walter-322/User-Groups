#include <QApplication>
#include <QMainWindow>

#include "UsersPage.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow window;

    window.setWindowTitle("Users and Groups");
    window.resize(1000, 650);

    UsersPage *usersPage = new UsersPage(&window);

    window.setCentralWidget(usersPage);

    window.show();

    return app.exec();
}
