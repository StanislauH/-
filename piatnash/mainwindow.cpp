#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <QMessageBox>
#include <QRandomGenerator>
#include <algorithm>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i = 0;i<4;i++){
        ui->table1->setRowHeight(i,100);
        ui->table1->setColumnWidth(i,100);
    }
    std::random_device rd;
   std::mt19937 g(rd());

    std::vector <int> a;
    for(int i=1;i<=16;i++) a.push_back(i);
    std::shuffle(a.begin(), a.end(), g);


    for(int i=0;i<4;i++) {
        for(int k=0;k<4;k++) {
            mas[i][k] = new QTableWidgetItem(QString::number(a.back()));
            a.pop_back();
        }
    }
    ShowTable();

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::ShowTable()
{
    for(int i=1;i<=4;i++){
        for(int k=1;k<=4;k++){

            QString x = mas[i-1][k-1]->text();
            if(x=="16"){
                ui->table1->setItem(i-1,k-1, new QTableWidgetItem());
            } else
            ui->table1->setItem(i-1,k-1, new QTableWidgetItem(x));
        }
    }
}


void MainWindow::on_table1_cellClicked(int row, int column)
{
    int x1 = row, y1 = column+1;
    int x2 = row, y2 = column-1;
    int x3 = row+1, y3 = column;
    int x4 = row-1, y4 = column;

    for(int i=0;i<4;i++) {
        for(int k=0;k<4;k++) {
            if(i==x1&&k==y1) {
                if(mas[i][k]->text()=="16") {
                    QTableWidgetItem *x = mas[row][column];
                    QTableWidgetItem *y = mas[i][k];
                    QString s = x->text();
                    QString s2 = "16";
                    x->setText(s2);
                    y->setText(s);
                    mas[row][column] = x;
                    mas[i][k] = y;
                    goto ex;
                }
            }
            if(i==x2&&k==y2) {
                if(mas[i][k]->text()=="16") {
                    QTableWidgetItem *x = mas[row][column];
                    QTableWidgetItem *y = mas[i][k];
                    QString s = x->text();
                    QString s2 = "16";
                    x->setText(s2);
                    y->setText(s);
                    mas[row][column] = x;
                    mas[i][k] = y;
                    goto ex;
                }
            }
            if(i==x3&&k==y3) {
                if(mas[i][k]->text()=="16") {
                    QTableWidgetItem *x = mas[row][column];
                    QTableWidgetItem *y = mas[i][k];
                    QString s = x->text();
                    QString s2 = "16";
                    x->setText(s2);
                    y->setText(s);
                    mas[row][column] = x;
                    mas[i][k] = y;
                    goto ex;
                }
            }
            if(i==x4&&k==y4) {
                if(mas[i][k]->text()=="16") {
                    QTableWidgetItem *x = mas[row][column];
                    QTableWidgetItem *y = mas[i][k];
                    QString s = x->text();
                    QString s2 = "16";
                    x->setText(s2);
                    y->setText(s);
                    mas[row][column] = x;
                    mas[i][k] = y;
                    goto ex;
                }
            }
        }
    }
    ex:;

    QString m[4][4] = {{"1","2","3","4"},{"5","6","7","8"},{"9","10","11","12"},{"13","14","15","16"}};
    bool a = 1;
    for(int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if ((i==3)&&(j==3)){
                continue;
            }
            if(mas[i][j]->text()!=m[i][j]){
              a = 0;
            }
        }
    }


    if (a==1){
        QMessageBox::warning(this, "Поздравляем", "Вы выйграли");
    }

    ShowTable();
}
