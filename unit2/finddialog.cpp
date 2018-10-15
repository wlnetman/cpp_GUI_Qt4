#include <QtGui>
#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent) : QDialog(parent)
{
    label = new QLabel(tr("Find &What:"));
    lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox("Match &case");
    backwardCheckBox = new QCheckBox("Search &backward");

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("Close"));
}
