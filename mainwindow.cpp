#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->buttonGroup, &QButtonGroup::buttonClicked, this, &MainWindow::updateRateLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::counterChange(QKeyEvent *event)
{
    int counter = ui->counterLabel->text().toInt();
    if (event->key() == Qt::Key_B) {
        counter++;
        ui->counterLabel->setText(QString::number(counter));
    }

    if (event->key() == Qt::Key_C) {
        ui->counterEdit->setText("");
    }
}

void MainWindow::on_counterReset_clicked()
{
    ui->counterLabel->setText("0");
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    std::string strCheck = ui->counterEdit->toPlainText().toStdString();
    QString resultNum;
    for (char ch : strCheck) {
        if (!isdigit(ch)) {
            ui->counterEdit->setText("");
            break;
        } else {
            resultNum.append(ch);
        }
        if (event->key() == Qt::Key_Enter) {
            ui->counterLabel->setText(resultNum);
            ui->counterEdit->setText("");
        }
    }
}

void MainWindow::updateRateLabel(QAbstractButton *button)
{
    ui->rateLabel->setText(button->text());
}


