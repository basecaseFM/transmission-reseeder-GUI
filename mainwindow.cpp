#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ADD_DIR_clicked()
{

    QString selected_DIR;
    selected_DIR = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                          "/home",
                                          QFileDialog::ShowDirsOnly
                                              | QFileDialog::DontResolveSymlinks);
    ui->LIST_OF_DIRs->addItem(selected_DIR);
}

void MainWindow::on_REMOVE_DIR_clicked()
{
    qDeleteAll(ui->LIST_OF_DIRs->selectedItems());
}

void MainWindow::on_Run_BUTTON_clicked()
{

    QDir currentDIR;
    QString pathReseeder = currentDIR.absoluteFilePath("reseeder.sh");
        for ( int row = 0 ; row < ui->LIST_OF_DIRs->count() ; row++)
        {
            QString str = ui->LIST_OF_DIRs->item(row)->text();
            QDirIterator it(str, QStringList() << "*.magnetLINK", QDir::Files, QDirIterator::Subdirectories);
            while (it.hasNext())
               ui->magnetlink_FOUND_PATH->addItem( it.next());
        }

        QProcess execMAGNETLINK;
        QStringList args;
        args << ui->IP_TR_REMOTE->text() <<ui->PORT_TR_REMOTE->text() << ui->USERNAMR_TR_REMOTE->text() << ui->PASSWORD_TR_REMOTE->text();

       for ( int row = 0 ; row < ui->magnetlink_FOUND_PATH->count() ; row++)
        {

            QString mag_PATH = ui->magnetlink_FOUND_PATH->item(row)->text();
            args.push_front(mag_PATH) ;
            execMAGNETLINK.execute (pathReseeder, args);
            execMAGNETLINK.waitForFinished(-1);
            execMAGNETLINK.close();
            args.removeFirst();

        }
}

