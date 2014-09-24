#ifndef PortControl_H
#define PortControl_H
#include <QtSerialPort/QSerialPortInfo>
#include <QObject>
#include <QStringList>
#include <QBitArray>
class QSerialPort;

class PortControl : public QObject
{
    Q_OBJECT
public:
    explicit PortControl(QObject *parent = 0);
    ~PortControl();
    struct Settings {
        QString name;
        qint32 baudRat9600;
        QString portname[10];
        int t;

//        QString stringBaudRate;
//        QSerialPort::StopBits stopBits;
       // QString stringStopBits;
    };
    struct test1 {
        QString name;
        qint32 baudRat9600;
    };

void ReadPortParameter();
void SetPortParam(const QString &portname,QString speed,QString stopbits);
void ConnectPort();
void writePort(QString writedata);
void readPort();
void receivedData();
bool receivedByteData(quint8 new_byte);
int t;
bool startFound = false;
int startPointer = 0;
bool replaceFlag = false;
int realBytesCount = 0;
QByteArray buf;
int writePointer = 0;
QStringList Portlist;
QStringList Speedlist;
QStringList StopBitlist;
quint16 crc16_byte(  quint16 crc,quint8 len);
quint16 crc16_modbus1(QByteArray data,quint32 len);
qint16  make_raw_data(const quint8 *data, quint16 len, quint8 *packet_data);
qint16 make_raw_data1(QByteArray data, quint16 lenhth,QByteArray packet_data);

QByteArray packet_data1;
signals:
   void ReceivedPortName( QString str);             // Получено новое SMS
  void error(QString error);
  void readdata(QByteArray readdata);
  void test(test1 t);

public slots:

void connectt();
private slots:
void read();

private:
Settings PortSpeed;
QSerialPort *m_port;


};







#endif // PortControl_H
