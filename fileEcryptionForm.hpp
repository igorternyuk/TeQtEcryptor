#ifndef FILEECRYPTIONFORM_HPP
#define FILEECRYPTIONFORM_HPP

#include <QWidget>

namespace Ui
{
    class FileEcryptionForm;
}

class FileEcryptionForm : public QWidget
{
    Q_OBJECT

public:
    explicit FileEcryptionForm(QWidget *parent = nullptr);
    ~FileEcryptionForm();

private:
    Ui::FileEcryptionForm *ui;
};

#endif // FILEECRYPTIONFORM_HPP
