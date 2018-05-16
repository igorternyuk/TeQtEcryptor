#ifndef PLAINTEXTENCRYPTIONFORM_HPP
#define PLAINTEXTENCRYPTIONFORM_HPP

#include <QWidget>

namespace Ui
{
    class PlainTextEncryptionForm;
}

class PlainTextEncryptionForm : public QWidget
{
    Q_OBJECT

public:
    explicit PlainTextEncryptionForm(QWidget *parent = nullptr);
    ~PlainTextEncryptionForm();

private slots:
    void on_btnEncrypt_clicked();

    void on_btnDecrypt_clicked();

private:
    Ui::PlainTextEncryptionForm *ui;
};

#endif // PLAINTEXTENCRYPTIONFORM_HPP
