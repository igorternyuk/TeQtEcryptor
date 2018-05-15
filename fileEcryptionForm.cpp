#include "fileEcryptionForm.hpp"
#include "ui_fileecryptionform.h"

FileEcryptionForm::FileEcryptionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileEcryptionForm)
{
    ui->setupUi(this);
}

FileEcryptionForm::~FileEcryptionForm()
{
    delete ui;
}
