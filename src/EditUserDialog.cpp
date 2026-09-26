#include "EditUserDialog.h"
#include "UserManager.h"

#include <QComboBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>

EditUserDialog::EditUserDialog(
    const QString &username,
    const QString &currentShell,
    QWidget *parent
)
    : QDialog(parent),
      username(username)
{
    setWindowTitle("Edit User");
    resize(400, 200);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *title = new QLabel(
        "Edit user: " + username,
        this
    );

    title->setStyleSheet(
        "font-size: 18px; font-weight: bold;"
    );

    layout->addWidget(title);

    QFormLayout *form = new QFormLayout();

    shellBox = new QComboBox(this);

    shellBox->addItems({
        "/bin/bash",
        "/bin/sh",
        "/bin/zsh",
        "/bin/fish",
        "/usr/bin/bash",
        "/usr/bin/zsh",
        "/usr/bin/fish",
        "/usr/bin/nologin"
    });

    int index = shellBox->findText(currentShell);

    if (index >= 0)
        shellBox->setCurrentIndex(index);

    form->addRow("Login Shell:", shellBox);

    layout->addLayout(form);

    QDialogButtonBox *buttons = new QDialogButtonBox(
        QDialogButtonBox::Cancel |
        QDialogButtonBox::Save,
        this
    );

    layout->addWidget(buttons);

    connect(
        buttons,
        &QDialogButtonBox::rejected,
        this,
        &QDialog::reject
    );

    connect(
        buttons,
        &QDialogButtonBox::accepted,
        this,
        &EditUserDialog::save
    );
}

void EditUserDialog::save()
{
    QString shell = shellBox->currentText();

    UserManager manager;

    if (!manager.updateShell(username, shell))
    {
        QMessageBox::critical(
            this,
            "Error",
            "Failed to change the login shell."
        );

        return;
    }

    accept();
}
