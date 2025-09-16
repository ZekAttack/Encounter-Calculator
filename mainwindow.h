#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

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

private slots:
    void on_radioButton_clicked();

    void on_radioButtons_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void keyPressEvent (QKeyEvent *event);
};
#endif // MAINWINDOW_H
