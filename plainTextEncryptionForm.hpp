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

private:
    Ui::PlainTextEncryptionForm *ui;
};

#endif // PLAINTEXTENCRYPTIONFORM_HPP
