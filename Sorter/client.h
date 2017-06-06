#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpSocket> // for receiving from the server
#include <QDataStream> // for communicating with the server
#include <QTcpServer> // for sending to the server

// forward declarations, or else Qt will complain
class QComboBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTcpSocket;
class QTcpServer;
class QNetworkSession;

class Client : public QDialog
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = Q_NULLPTR);

private slots:
    void requestNewFortune(); // sends a request for a new fortune from the server
    void setNewFortune(); // sets the new fortune
    void readFortune();
    void displayError(QAbstractSocket::SocketError socketError);
    void enableGetFortuneButton(); // allows the requestNewFortune button to work
    void enableAddButton(); // allows the addNewFortune button to work
    void sessionOpened(); // called whenever a network connection session is opened

private:
    QComboBox *hostCombo;
    QLineEdit *portLineEdit;
    QLineEdit *addLineEdit;
    QPushButton *addButton;
    QLabel *statusLabel;
    QLabel *successLabel;
    QPushButton *getFortuneButton;
    QString newFortune;
    QString tempFortune; // used to set placeholder text in addLineEdit when requestFortune() happens so it sends an empty string, which is ignored in server

    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QDataStream in;
    QDataStream out;
    QString currentFortune;

    QNetworkSession *networkSession;
    int fortuneStop = 0; // used as a flag to stop readFortune() if the add fortune button is pressed
};

#endif
