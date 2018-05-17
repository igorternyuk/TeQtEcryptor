#include "plainTextEncryptionForm.hpp"
#include "ui_plaintextencryptionform.h"
#include "tecipher.hpp"
#include <QMessageBox>
#include <QDebug>

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

void PlainTextEncryptionForm::on_btnEncrypt_clicked()
{
    QString textToEcrypt = ui->textEditInput->toPlainText();
    if(textToEcrypt.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Nothing to encrypt");
        return;
    }

    QString password = ui->lineEditPassword->text();
    QString repeatPassword = ui->lineEditRepeatPassword->text();

    if(password != repeatPassword)
    {
        QMessageBox::critical(this, "Password error", "Password mismatch");
        return;
    }

    TeCipher cipher;

    if(!cipher.loadPublicKeyByteArrayFromFile("public.pem"))
    {
        QMessageBox::critical(this, "Could not load RSA public key",
                              cipher.getLastError());
        return;
    }

    QString encryptedText;
    //qDebug() << "Trying to encrypt with password: " << passphrase;
    if(!cipher.encryptPlainTextWithCombinedMethod(password, textToEcrypt,
                                                  encryptedText))
    {
        QMessageBox::critical(this, "Encryption error",
                              cipher.getLastError());
        return;
    }
    //qDebug() << "encryptedData:" << encryptedData.toBase64();
    ui->textEditOutput->setText(encryptedText);
    QMessageBox::information(this, "Success",
                             "The text was succssfully encrypted");

}

void PlainTextEncryptionForm::on_btnDecrypt_clicked()
{
    QString textToDecrypt = ui->textEditInput->toPlainText();

    if(textToDecrypt.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Nothing to encrypt");
        return;
    }

    QString password = ui->lineEditPassword->text();
    QString repeatPassword = ui->lineEditRepeatPassword->text();

    if(password != repeatPassword)
    {
        QMessageBox::critical(this, "Password error", "Password mismatch");
        return;
    }

    TeCipher cipher;

    if(!cipher.loadPrivateKeyByteArrayFromFile("private.pem"))
    {
        QMessageBox::critical(this, "Could not load RSA private key",
                              cipher.getLastError());
        return;
    }

    QString decryptedText;

    if(!cipher.decryptPlainTextWithCombinedMethod(password, textToDecrypt,
                                                  decryptedText))
    {
        QMessageBox::critical(this, "Decryption error",
                              cipher.getLastError());
        return;
    }
    ui->textEditOutput->setText(decryptedText);
    QMessageBox::information(this, "Success",
                             "The file was succssfully decrypted");
}
