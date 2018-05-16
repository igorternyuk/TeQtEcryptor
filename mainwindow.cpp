#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "fileEcryptionForm.hpp"
#include "plainTextEncryptionForm.hpp"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(size());
    this->setWindowTitle("TeEcryptor");
    ui->stackedWidget->addWidget(new FileEcryptionForm(this));
    ui->stackedWidget->addWidget(new PlainTextEncryptionForm(this));
    this->setCentralWidget(ui->stackedWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionEcrypt_plain_text_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_actionEncrypt_file_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_actionQuit_triggered()
{
    auto reply = QMessageBox::question(this, "Confirm quit, please",
                          "Do you really want to quit?",
                          QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        this->close();
    }
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this, "About Qt");
}
