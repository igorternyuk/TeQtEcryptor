#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionEcrypt_plain_text_triggered();

    void on_actionEncrypt_file_triggered();

    void on_actionQuit_triggered();

    void on_actionAbout_Qt_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
