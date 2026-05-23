#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTcpSocket>
#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    void usermsgtolabel(QString usrmsg);
    void return_key_sender();
    QTcpSocket *socket;
    void readMessage();
};
#endif // MAINWINDOW_H
