#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
MainWindow::MainWindow(QWidget *parent) ://constructor de la UI
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //definicion de la matriz de posiciones
    posC={  {  { {100,100} },{ {300,100} },{ {500,100} }  },//esto NO representa el tablero
            {  { {100,300} },{ {300,300} },{ {500,300} }  },
            {  { {100,500} },{ {300,500} },{ {500,500} }  }   };
    posA=posC;//posicion de los botones igual a la matriz de comprobacion al comenzar la partida, es decir, ordenado

    posF={  {  { false },{ false },{ false }  },//esta lo unico que hace es seguir la casilla vacia con el true
            {  { false },{ false },{ false }  },//esto SI representa el tablero
            {  { false },{ false },{ true  }  }   };

    indx =      {   {  { {0,0} },{ {0,1} },{ {0,2} }  },//matriz para indexar
                    {  { {1,0} },{ {1,1} },{ {1,2} }  },
                    {  { {2,0} },{ {2,1} },{ {2,2} }  }   };

    imagS=1;//seleccion de la imagen por default
    /*FUNCION DE SELECCION DE LA IMAGEN QUE SE GUARDARA COMO ENTERO EN imagS*/
    MainWindow::setimag(imagS);//se llama a la funcion de asignacion de imagenes
    mergeM(posA,indx,posF);
    MainWindow::setpos(posA);

}


MainWindow::~MainWindow()//destructor de la UI
{
    delete ui;
}
//funcion movimiento de las casillas
void move(){

}
//funcion donde botones leen posicion
void MainWindow::setpos(vector<vector<vector<int>>> &posV){
    ui->p1->setGeometry(posV[0][0][0],posV[0][0][1],200,200);
    ui->p2->setGeometry(posV[0][1][0],posV[0][1][1],200,200);
    ui->p3->setGeometry(posV[0][2][0],posV[0][2][1],200,200);
    ui->p4->setGeometry(posV[1][0][0],posV[1][0][1],200,200);
    ui->p5->setGeometry(posV[1][1][0],posV[1][1][1],200,200);
    ui->p6->setGeometry(posV[1][2][0],posV[1][2][1],200,200);
    ui->p7->setGeometry(posV[2][0][0],posV[2][0][1],200,200);
    ui->p8->setGeometry(posV[2][1][0],posV[2][1][1],200,200);
}

//funcion para poner las imagenes en las casillas
void MainWindow::setimag(int numI){

    QString path1=":/imag/imag/";       //ruta general al resurce file
    path1=path1+QString::number(numI);  //ruta general al resurce file con la imagen seleccionada

    QString path2="_1.jpg";             //ruta concreta a cada fragmento de imagen
    QPixmap icono1(path1+path2);        //importar la imagen desde el resource file
    QIcon ButtonIcon1(icono1);          //establecer imagen como un objeto icono
    ui->p1->setIcon(ButtonIcon1);       //asignarselo al boton correspondiente
    ui->p1->setIconSize(ui->p1->size());//ajustar el tamaño de la imagen al boton

    path2="_2.jpg";
    QPixmap icono2(path1+path2);
    QIcon ButtonIcon2(icono2);
    ui->p2->setIcon(ButtonIcon2);
    ui->p2->setIconSize(ui->p1->size());

    path2="_3.jpg";
    QPixmap icono3(path1+path2);
    QIcon ButtonIcon3(icono3);
    ui->p3->setIcon(ButtonIcon3);
    ui->p3->setIconSize(ui->p1->size());

    path2="_4.jpg";
    QPixmap icono4(path1+path2);
    QIcon ButtonIcon4(icono4);
    ui->p4->setIcon(ButtonIcon4);
    ui->p4->setIconSize(ui->p1->size());

    path2="_5.jpg";
    QPixmap icono5(path1+path2);
    QIcon ButtonIcon5(icono5);
    ui->p5->setIcon(ButtonIcon5);
    ui->p5->setIconSize(ui->p1->size());

    path2="_6.jpg";
    QPixmap icono6(path1+path2);
    QIcon ButtonIcon6(icono6);
    ui->p6->setIcon(ButtonIcon6);
    ui->p6->setIconSize(ui->p1->size());

    path2="_7.jpg";
    QPixmap icono7(path1+path2);
    QIcon ButtonIcon7(icono7);
    ui->p7->setIcon(ButtonIcon7);
    ui->p7->setIconSize(ui->p1->size());

    path2="_8.jpg";
    QPixmap icono8(path1+path2);
    QIcon ButtonIcon8(icono8);
    ui->p8->setIcon(ButtonIcon8);
    ui->p8->setIconSize(ui->p1->size());
}

void MainWindow::on_p1_clicked()
{
    int i = 0;
    int j = 0;
    //MainWindow::setpos(posC);
}

void MainWindow::on_p2_clicked()
{
    int i = 0;
    int j = 1;
}

void MainWindow::on_p3_clicked()
{
    int i = 0;
    int j = 2;
}

void MainWindow::on_p4_clicked()
{
    int i = 1;
    int j = 0;
}

void MainWindow::on_p5_clicked()
{
    int i = 1;
    int j = 1;
}

void MainWindow::on_p6_clicked()
{
    int i = 1;
    int j = 2;
}

void MainWindow::on_p7_clicked()
{
    int i = 2;
    int j = 0;
}

void MainWindow::on_p8_clicked()
{
    int i = 2;
    int j = 1;
}
