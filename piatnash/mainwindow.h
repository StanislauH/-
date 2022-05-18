#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ShowTable();

private slots:
    void on_table1_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    QTableWidgetItem *mas[4][4];
};
#endif // MAINWINDOW_H
