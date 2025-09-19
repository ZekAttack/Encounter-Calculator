#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->buttonGroup, &QButtonGroup::buttonClicked, this, &MainWindow::updateRateLabel);
    QObject::connect(ui->counterIncrease, &QButtonGroup::buttonClicked, this, &MainWindow::updateCounterLabel);
    this->setWindowTitle("Encounter Calculator");
    updateResultEncounter();
    updateResultRate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_counterReset_clicked()
{
    ui->counterLabel->setText("0");
    updateResultEncounter();
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_B) {
        int counter = ui->counterLabel->text().toInt();
        counter++;
        QString returnNum;
        returnNum.setNum(counter);
        ui->counterLabel->setText(returnNum);
    }
}

void MainWindow::updateRateLabel(QAbstractButton *button)
{
    ui->rateLabel->setText(button->text());
    updateResultEncounter();
    updateResultRate();
}

void MainWindow::updateCounterLabel(QAbstractButton *button)
{
    int counter = ui->counterLabel->text().toInt();
    counter = counter + button->text().toInt();
    QString returnNum;
    returnNum.setNum(counter);
    ui->counterLabel->setText(returnNum);
    updateResultEncounter();
}


void MainWindow::updateResultEncounter()
{
    std::string separator = ui->rateLabel->text().toStdString();
    std::string partB = separator.substr(2, separator.length());
    double rate = 1 / std::stod(partB);
    double probOccur = (1 - std::pow((1-rate), ui->counterLabel->text().toInt())) * 100;
    QString insertNum;
    insertNum.setNum(probOccur);
    ui->resultEncounter->setText("At " + ui->counterLabel->text() + " encounter(s), you have a " + insertNum + "% chance of occuring.");
}

void MainWindow::updateResultRate()
{
    std::string separator = ui->rateLabel->text().toStdString();
    std::string partB = separator.substr(2, separator.length());
    double rate = 1 / std::stod(partB);
    int enc25 = std::ceil((std::log(1-0.25))/std::log(1-rate));
    int enc50 = std::ceil((std::log(1-0.5))/std::log(1-rate));
    int enc75 = std::ceil((std::log(1-0.75))/std::log(1-rate));
    int enc99 = std::ceil((std::log(1-0.99))/std::log(1-rate));
    QString insertNum, insertNum2, insertNum3, insertNum4;
    insertNum.setNum(enc25);
    insertNum2.setNum(enc50);
    insertNum3.setNum(enc75);
    insertNum4.setNum(enc99);
    ui->resultRate->setText("At a rate of " + ui->rateLabel->text() +
                            ", it will take " + insertNum + " encounter(s) for a 25% chance, "
                            + insertNum2 + " encounter(s) for a 50% chance, "
                            + insertNum3 + " encounter(s) for a 75% chance and "
                            + insertNum4 + " encounter(s) for a 99% chance.");
}
