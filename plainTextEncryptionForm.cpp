#include "plainTextEncryptionForm.hpp"
#include "ui_plaintextencryptionform.h"

PlainTextEncryptionForm::PlainTextEncryptionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlainTextEncryptionForm)
{
    ui->setupUi(this);
}

PlainTextEncryptionForm::~PlainTextEncryptionForm()
{
    delete ui;
}
