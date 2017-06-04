#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpSocket>
#include <QDataStream>
#include <QMutex>
#include <QThread>

class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
class QNetworkSession;

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = Q_NULLPTR);
    QMutex* QMutex_ptr = NULL;

signals:
    void sendSignal(QString);

private slots:
    void displayError(QAbstractSocket::SocketError socketError);
    void enableStartButton();
    void sessionOpened();
    void requestNumberList();
    void readNumberList();

private:
    QComboBox *hostCombo;
    QLineEdit *portLineEdit;
    QLabel *statusLabel;
    QLabel *successLabel;
    QPushButton *startButton;

    QTcpSocket *tcpSocket;
    QDataStream in;

    QNetworkSession *networkSession;
};

#endif
