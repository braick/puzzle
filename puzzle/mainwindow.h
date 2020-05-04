#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
using namespace std;
namespace Ui {
class MainWindow;
}
//Cabeceras de las funciones propias

int randint();
void mergeM(vector<vector<int>> &buttNum);
void findElement(vector<vector<int>> &vvi,int elm,int *i,int *j);

//
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    vector<vector<vector<int>>> posA,posC,indx;//matrices de posiciones. Instantanea y de comprobacion
    vector<vector<bool>> posF;//matiz para posicionar la casilla libre
    vector<vector<int>> buttonPos;
    int imagS;

    void setpos(vector<vector<int>> posF);
    void setimag(int numI);
    //void move(vector<vector<vector<int>>> &posC,vector<vector<bool>> &freeC, int i, int j);



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
