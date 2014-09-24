 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "PortControl.h"
#include "BKN.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  control = new BKN();
m_control = new PortControl();


    fillparam();

connect(m_control,SIGNAL(ReceivedPortName(QString)),SLOT(saveport(QString)));
connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(soed()));
connect(m_control,SIGNAL(error(QString)),SLOT(error(QString)));
connect(m_control,SIGNAL(test(test1)),SLOT(test(test1)));

//ываываыва
}

MainWindow::~MainWindow()
{
    delete ui;
}
 void MainWindow::saveport(QString str){
QByteArray a;
     ui->comboBox->addItem(str);
     control->connect_BKN("COM2");
     control->CMD_SET_STAT();
     QByteArray array;
      array.resize(6);
             array[0] = 0x7E;
             array[1] = 0x01;
             array[2] = 0x7D;
             array[3] = 0x5E;
             array[4] = 0x80;
             array[5] = 0x7E;

 }

 void MainWindow::test(test1 t){

     int k=t.baudRat9600;
 }
   void MainWindow::soed(){
       m_control->SetPortParam(ui->comboBox->currentText(),ui->comboBox_2->currentText(),ui->comboBox_3->currentText());
   m_control->ConnectPort();
   QString str="2";
   m_control->writePort(str);

   //m_control->readPort();
   /////////ролролрол
   ///345345345
   /// 3453455
///11111111111111
   }
 void MainWindow::fillparam(){

QStringList str_port;
QStringList str_speed;
QStringList str_stopbits;

     m_control->ReadPortParameter();

int k=m_control->t;

for(int i=0;i<m_control->Portlist.size();i++){

    str_port.append(m_control->Portlist.at(i));
    saveport(str_port.at(i));

}

for(int i=0;i<m_control->Speedlist.size();i++){

    str_speed.append(m_control->Speedlist.at(i));
    savespeed(str_speed.at(i));

}
for(int i=0;i<m_control->StopBitlist.size();i++){

    str_stopbits.append(m_control->StopBitlist.at(i));
    savestopbits(str_stopbits.at(i));

}

//saveport(str);

 }
 void MainWindow::savespeed(QString str){

     ui->comboBox_2->addItem(str);

 }
 void MainWindow::savestopbits(QString str){

     ui->comboBox_3->addItem(str);
 }
void MainWindow::error(QString error1){
     //QMessageBox::warning(this, tr(error1);
            QMessageBox::critical(0, tr("Ошибка"), error1);
}
