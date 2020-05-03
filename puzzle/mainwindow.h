#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
using namespace std;
namespace Ui {
class MainWindow;
}
//Cabeceras de las funciones propias



//
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    vector<vector<vector<int>>> posA,posC;//matrices de posiciones. Instantanea y de comprobacion
    vector<vector<bool>> posF;//matiz para posicionar la casilla libre
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setpos(vector<vector<vector<int>>> &posV);
    void setimag(int numI);


private slots:
    void on_p1_clicked();

    void on_p2_clicked();

    void on_p3_clicked();

    void on_p4_clicked();

    void on_p5_clicked();

    void on_p6_clicked();

    void on_p7_clicked();

    void on_p8_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
