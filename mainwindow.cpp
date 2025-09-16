#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

void MainWindow::on_radioButton_clicked()
{
    ui->rateLabel->setText("1/2");
}


void MainWindow::on_radioButtons_clicked()
{

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int counter = ui->counterLabel->text().toInt();
    if (event->key() == Qt::Key_B) {
        counter++;
        ui->counterLabel->setText(QString::number(counter));
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->counterLabel->setText("0");
}

