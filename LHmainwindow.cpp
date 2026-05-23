#include "./ui_mainwindow.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    socket->connectToHost("192.168.1.197", 1234);
    connect(ui->lineEdit, &QLineEdit::returnPressed,
            this, &MainWindow::return_key_sender);
    connect(socket, &QTcpSocket::readyRead,
            this, &MainWindow::readMessage);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::usermsgtolabel(QString usrmsg){

    QListWidgetItem *usermsg=
        new QListWidgetItem(usrmsg);
    usermsg->setForeground(Qt::black);
    ui->listWidget->addItem(usermsg);
    ui->listWidget->scrollToBottom();

}
void MainWindow::return_key_sender()
{
    QString msg = ui->lineEdit->text();

    if (!msg.isEmpty())
    {
        // show locally

        // 🔥 SEND TO LAN SERVER
        socket->write(("ME:" + msg).toUtf8());

        ui->lineEdit->clear();
    }
}
void MainWindow::readMessage()
{
    QString msg = QString(socket->readAll());

    if (msg.startsWith("ME:")) {
        msg.remove(0, 3); // remove tag
        usermsgtolabel("You: " + msg);
    }
    else {
        usermsgtolabel("Friend: " + msg);
    }
}

