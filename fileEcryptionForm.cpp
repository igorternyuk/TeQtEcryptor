#include "fileEcryptionForm.hpp"
#include "ui_fileecryptionform.h"
#include "tecipher.hpp"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <QFileSystemModel>
#include <QCompleter>
#include <QDebug>

FileEcryptionForm::FileEcryptionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileEcryptionForm)
{
    ui->setupUi(this);
    auto fsModel = new QFileSystemModel(this);
    fsModel->setRootPath(QDir::rootPath());
    QCompleter *completer = new QCompleter(fsModel, this);
    ui->lineEditInputFile->setCompleter(completer);
}

FileEcryptionForm::~FileEcryptionForm()
{
    delete ui;
}

void FileEcryptionForm::on_btnEncrypt_clicked()
{
    auto sourceFilePath = ui->lineEditInputFile->text();
    if(sourceFilePath.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Input file not specified");
        return;
    }

    auto startDir = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation)
            .value(0, QDir::homePath());
    auto outputFilePath = QFileDialog::getSaveFileName(this, "Select target file...",
                      startDir, "Text files (*.txt);;All files (*.*)");

    if(outputFilePath.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Output file not specified");
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

    if(!cipher.encryptFileWithCombinedMethod(password, sourceFilePath, outputFilePath))
    {
        QMessageBox::critical(this, "Error",
                              cipher.getLastError());
        return;
    }

    QMessageBox::information(this, "Success",
                             "The file was succssfully encrypted");
}

void FileEcryptionForm::on_btnDecrypt_clicked()
{
    auto sourceFilePath = ui->lineEditInputFile->text();
    if(sourceFilePath.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Input file not specified");
        return;
    }
    auto startDir = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation)
            .value(0, QDir::homePath());
    QString outputFilePath = QFileDialog::getSaveFileName(this, "Select target file...",
                      startDir, "Text files (*.txt);;All files (*.*)");
    if(outputFilePath.isEmpty())
    {
        QMessageBox::critical(this, "Error", "Output file not specified");
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

    if(!cipher.decryptFileWithCombinedMethod(password, sourceFilePath,
                                             outputFilePath))
    {
        QMessageBox::critical(this, "Error", cipher.getLastError());
        return;
    }

    QMessageBox::information(this, "Success",
                             "The file was succssfully decrypted");
}

void FileEcryptionForm::on_toolButton_clicked()
{
    auto startDir = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation)
            .value(0, QDir::homePath());
    auto inputFilePath = QFileDialog::getOpenFileName(this,
                      "Select the file to be encrypted...",
                      startDir, "Text files (*.txt);;All files (*.*)");
    if(inputFilePath.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Input file not specified");
        return;
    }
    ui->lineEditInputFile->setText(inputFilePath);
}

