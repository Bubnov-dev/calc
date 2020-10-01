#include "mainwindow.h"
#include "ui_mainwindow.h"
double numFst;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    connect(ui->b0, SIGNAL(clicked()), this, SLOT(digit_nums()));
    connect(ui->b1, SIGNAL(clicked()), this, SLOT(digit_nums()));
    connect(ui->b2, SIGNAL(clicked()), this, SLOT(digit_nums()));
    connect(ui->b3, SIGNAL(clicked()), this, SLOT(digit_nums()));
    connect(ui->b4, SIGNAL(clicked()), this, SLOT(digit_nums()));
    connect(ui->b5, SIGNAL(clicked()), this, SLOT(digit_nums()));
    connect(ui->b6, SIGNAL(clicked()), this, SLOT(digit_nums()));
    connect(ui->b7, SIGNAL(clicked()), this, SLOT(digit_nums()));
    connect(ui->b8, SIGNAL(clicked()), this, SLOT(digit_nums()));
    connect(ui->b9, SIGNAL(clicked()), this, SLOT(digit_nums()));
    connect(ui->bPlus, SIGNAL(clicked()), this, SLOT(math_ops()));
    connect(ui->bMinus, SIGNAL(clicked()), this, SLOT(math_ops()));
    connect(ui->bDiv, SIGNAL(clicked()), this, SLOT(math_ops()));
    connect(ui->bMult, SIGNAL(clicked()), this, SLOT(math_ops()));
    ui->bPlus->setCheckable(true);
    ui->bMinus->setCheckable(true);
    ui->bDiv->setCheckable(true);
    ui->bMult->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_nums(){
    QPushButton *button = (QPushButton *) sender();

    double a = (ui->result->text() + button->text()).toDouble();
    QString str = QString::number(a);
    ui->result->setText(str);
}

void MainWindow::math_ops(){
    QPushButton *button = (QPushButton *) sender();

    numFst = (ui->result->text()).toDouble();
    ui->history->setText(QString::number(numFst) + button->text());
    button -> setChecked(true);
    ui->result->setText("0");
}



int MainWindow::on_bEq_clicked()
{
    double numSnd = (ui->result->text()).toDouble();
    double res;
    QString qRes;

    if (ui->bPlus->isChecked()){
        res = numFst+numSnd;
        ui->bPlus->setChecked(false);
    }
    else if (ui->bMinus->isChecked()){
        res = numFst-numSnd;
        ui->bMinus->setChecked(false);
    }
    else if (ui->bMult->isChecked()){
        res = numFst*numSnd;
        ui->bMult->setChecked(false);
    }
    else if (ui->bDiv->isChecked()){
        res = numFst/numSnd;
        ui->bDiv->setChecked(false);
    }
    else{
        ui->result->setText("0");
        ui->history->setText("history");
        numFst=0;
        numSnd=0;
        res=0;
        return 0;
    }
    qRes = QString::number(res);
    QString tmp = ui->history->text();
    ui->history->setText(tmp + QString::number(numSnd) + "=" +qRes);
    ui->result->setText(qRes);
    return 0;
}
