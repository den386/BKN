#ifndef BKN_H
#define BKN_H
#include <QtSerialPort/QSerialPortInfo>
#include <QObject>
#include <QStringList>
#include <QBitArray>
#include <QTimer>
class QSerialPort;

class BKN : public QObject
{
    Q_OBJECT
public:
    explicit BKN(QObject *parent = 0);
    ~BKN();
    struct BKN_status {
        QString str_error;
        int kod_error ;
    };
  void connect_BKN(const QString &portName);
  void CMD_SET_STAT();//установить статус
  int CMD_GET_STATUS(QString &str);// получить статус
  void CMD_GET_STATUS_AUTOMATION(QString &str);
  void write_data(QByteArray data);//запись в порт данных
  void  read_data_status(int time);//запуск таймера на чтение статуса

  QByteArray read_data();
 quint16  MaxServiceDataSize;
 quint16  maxLen;
 QByteArray buf;

  quint16 crc16_byte(  quint16 crc,quint8 len);
  quint16 crc16_modbus1(QByteArray data,quint32 len);
qint16 make_raw_data1(QByteArray data, quint16 lenhth,QByteArray *packet_data);
bool receivedByteData(quint8 new_byte);
void receivedData(QByteArray data);
int t;
bool startFound = false;
int startPointer = 0;
bool replaceFlag = false;
int realBytesCount = 0;
QByteArray  status_data_read;//статус данные
int writePointer = 0;
int control_status;//в переменную записывается 1 если данные записались в status_data_read
QByteArray packet_data;
signals:
  void connect_BKN_status(BKN_status con_BKN_stat);
  void status( int state,QString str);             // Получено новое SMS
//  void error(QString error);
//  void readdata(QByteArray readdata);
//  void test(test1 t);

public slots:
void read_data_slot();
//void connectt();
private slots:
//void read();

private:
//Settings PortSpeed;
QSerialPort *m_port;
QTimer      *m_timer;

};


#endif // BKN_H
