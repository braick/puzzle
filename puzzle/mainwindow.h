#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QTimer>
using namespace std;
namespace Ui {
class MainWindow;
}
//Cabeceras de las funciones propias
/////////////////////////////////////////////////////////
int randint();
void mergeM(vector<vector<int>> &buttNum);
void findElement(vector<vector<int>> &vvi,int elm,int *i,int *j);
void moveB(vector<vector<int>> &_buttPos, int p);
////////////////////////////////////////////////////////

//
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    vector<vector<int>> buttonPos;//declaracion de la matriz de posiciones
    int imagS,imagMAX,t;
    void setpos(vector<vector<int>> posF);//declaracion de los metodos propios de la clase ventana
    void setimag(int numI);

public slots:

    void tfunct();

private slots:
    void on_p1_clicked();

    void on_p2_clicked();

    void on_p3_clicked();

    void on_p4_clicked();

    void on_p5_clicked();

    void on_p6_clicked();

    void on_p7_clicked();

    void on_p8_clicked();

    void on_flechaD_clicked();

    void on_flechaI_clicked();

    void on_start_clicked();

private:
    Ui::MainWindow *ui;

    QTimer *timer;

};

#endif // MAINWINDOW_H
