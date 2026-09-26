#ifndef EDITUSERDIALOG_H
#define EDITUSERDIALOG_H

#include <QDialog>

class QComboBox;

class EditUserDialog : public QDialog
{
public:
    EditUserDialog(
        const QString &username,
        const QString &currentShell,
        QWidget *parent = nullptr
    );

private:
    QString username;
    QComboBox *shellBox;

    void save();
};

#endif // EDITUSERDIALOG_H
