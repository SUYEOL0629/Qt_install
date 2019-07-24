#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void msges(){
    QMessageBox msg;
    msg.information(nullptr,"Check LCD", "Put in your money for Vending Machine");
}

void Widget::checkMoney(){
    if (money > 1300){
        ui->whiskey->setEnabled(true);
    }
    else {
        ui->whiskey->setEnabled(false);
    }

    if (money > 1200){
        ui->rum->setEnabled(true);
    }
    else {
        ui->rum->setEnabled(false);
    }

    if (money > 1000){
        ui->vodka->setEnabled(true);
    }
    else {
        ui->vodka->setEnabled(false);
    }
}

void Widget::chageMoney(int n){
    money += n;
    ui->lcdNumber->display(QString::number(money));
    checkMoney();
}

void Widget::checkCoin() {

    won500 = money/500;
    cMoney = money%500;

    won100 = cMoney/100;
    cMoney = cMoney%100;

    won50 = cMoney/50;
    cMoney = cMoney%50;

    won10 = cMoney/10;
    cMoney = cMoney%10;

    chageMoney(-money);
}

void Widget::on_pb10_clicked()
{
    chageMoney(10);
}

void Widget::on_pb50_clicked()
{
    chageMoney(50);
}

void Widget::on_pb100_clicked()
{
    chageMoney(100);
}

void Widget::on_pb500_clicked()
{
    chageMoney(500);
}

void Widget::on_whiskey_clicked()
{
    chageMoney(-1300);
}

void Widget::on_rum_clicked()
{
    chageMoney(-1200);
}

void Widget::on_vodka_clicked()
{
    chageMoney(-1000);
}

void Widget::on_pushButton_clicked()
{
    checkCoin();
    QMessageBox msg;
    msg.information(nullptr,"Have a good day",
                    "500won : " + QString::number(won500) + "\n" +
                    "100won : " + QString::number(won100) + "\n" +
                    "50won : " + QString::number(won50) + "\n" +
                    "10won : " + QString::number(won10)
                    ,("Get it"));
}
