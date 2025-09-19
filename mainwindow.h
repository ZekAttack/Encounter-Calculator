#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAbstractButton>
#include <QKeyEvent>
#include <cmath>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateRateLabel(QAbstractButton *button);
    void updateCounterLabel(QAbstractButton *button);

private slots:
    void on_counterReset_clicked();



private:
    Ui::MainWindow *ui;
    void updateResultEncounter();
    void updateResultRate();
    void keyPressEvent (QKeyEvent *event);
};
#endif // MAINWINDOW_H
