#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <QFile>
#include <QDirIterator>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ADD_DIR_clicked();

    void on_REMOVE_DIR_clicked();

    void on_Run_BUTTON_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
