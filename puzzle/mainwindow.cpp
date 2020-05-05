#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
//#include <QTimer>
using namespace std;
MainWindow::MainWindow(QWidget *parent) ://constructor de la UI
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    buttonPos={     {  { 1 },{ 2 },{ 3 }  },
                    {  { 4 },{ 5 },{ 6 }  },        //esto SI representa el tablero
                    {  { 7 },{ 8 },{ 0 }  }   };

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(tfunct()));//definicion del objeto del cronometro
    t=0;//inicio del temporizador en 0

    imagS=1;//seleccion de la imagen por default


    QPixmap fD(":/imag/imag/fD.png");//imagen de la flecha derecha
    QIcon iconD(fD);
    ui->flechaD->setIcon(iconD);
    ui->flechaD->setIconSize(ui->flechaD->size());

    QPixmap fI(":/imag/imag/fI.png");//imagen de la flecha izquierda
    QIcon iconI(fI);
    ui->flechaI->setIcon(iconI);
    ui->flechaI->setIconSize(ui->flechaI->size());

    imagMAX=2;//numero de imagenes en el resource pack
    QPixmap pix(":/imag/imag/1.jpg");//seleccion de la primera imagen por default
    ui->label_2->setPixmap(pix.scaled(ui->label_2->width(),ui->label_2->height(),Qt::KeepAspectRatio));

    ui->panel_final->setVisible(false);//hacer invisible el panel final
    ui->fin_partida->setVisible(false);//                  boton final partida

}


MainWindow::~MainWindow()//destructor de la UI
{
    delete ui;
}

//funcion donde botones leen posicion
void MainWindow::setpos(vector<vector<int>> posF){
    int i=0,j=0;


    //definicion de la matriz de posiciones
    vector<vector<vector<int>>> posV={  {  { {100,100} },{ {300,100} },{ {500,100} }  },//esto NO representa el tablero
                                        {  { {100,300} },{ {300,300} },{ {500,300} }  },//esto es estatico
                                        {  { {100,500} },{ {300,500} },{ {500,500} }  }   };

    findElement(posF,1,&i,&j);
    ui->p1->setGeometry(posV[i][j][0],posV[i][j][1],200,200);

    i=0;j=0;
    findElement(posF,2,&i,&j);
    ui->p2->setGeometry(posV[i][j][0],posV[i][j][1],200,200);

    i=0;j=0;
    findElement(posF,3,&i,&j);
    ui->p3->setGeometry(posV[i][j][0],posV[i][j][1],200,200);

    i=0;j=0;
    findElement(posF,4,&i,&j);
    ui->p4->setGeometry(posV[i][j][0],posV[i][j][1],200,200);

    i=0;j=0;
    findElement(posF,5,&i,&j);
    ui->p5->setGeometry(posV[i][j][0],posV[i][j][1],200,200);

    i=0;j=0;
    findElement(posF,6,&i,&j);
    ui->p6->setGeometry(posV[i][j][0],posV[i][j][1],200,200);

    i=0;j=0;
    findElement(posF,7,&i,&j);
    ui->p7->setGeometry(posV[i][j][0],posV[i][j][1],200,200);

    i=0;j=0;
    findElement(posF,8,&i,&j);
    ui->p8->setGeometry(posV[i][j][0],posV[i][j][1],200,200);
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


void MainWindow::check(vector<vector<int>> &_buttonPos){

    vector<vector<int>> buttonPosRef={      {  { 1 },{ 2 },{ 3 }  },
                                            {  { 4 },{ 5 },{ 6 }  },
                                            {  { 7 },{ 8 },{ 0 }  }   };
    if(_buttonPos==buttonPosRef){
        ui->panel_final->setVisible(true);//hacer visible el panel final
        ui->fin_partida->setVisible(true);//                  boton final partida
        timer->stop();
        QString tex1="HAS GANADO\n\n Completado en:";
        QString tex2=QString::number(t);
        QString tex3=" segundos";

        ui->panel_final->setText(tex1+tex2+tex3);

    }

}


void MainWindow::on_p1_clicked()
{

    int buttIdent = 1;
    //int bi=0,bj=0;
    moveB(buttonPos,buttIdent);
    MainWindow::setpos(buttonPos);
    check(buttonPos);
}

void MainWindow::on_p2_clicked()
{
    int buttIdent = 2;
    moveB(buttonPos,buttIdent);
    MainWindow::setpos(buttonPos);
    check(buttonPos);
}

void MainWindow::on_p3_clicked()
{
    int buttIdent = 3;
    moveB(buttonPos,buttIdent);
    MainWindow::setpos(buttonPos);
    check(buttonPos);
}

void MainWindow::on_p4_clicked()
{
    int buttIdent = 4;
    moveB(buttonPos,buttIdent);
    MainWindow::setpos(buttonPos);
    check(buttonPos);
}

void MainWindow::on_p5_clicked()
{
    int buttIdent = 5;
    moveB(buttonPos,buttIdent);
    MainWindow::setpos(buttonPos);
    check(buttonPos);
}

void MainWindow::on_p6_clicked()
{
    int buttIdent = 6;
    moveB(buttonPos,buttIdent);
    MainWindow::setpos(buttonPos);
    check(buttonPos);
}

void MainWindow::on_p7_clicked()
{
    int buttIdent = 7;
    moveB(buttonPos,buttIdent);
    MainWindow::setpos(buttonPos);
    check(buttonPos);
}

void MainWindow::on_p8_clicked()
{
    int buttIdent = 8;
    moveB(buttonPos,buttIdent);
    MainWindow::setpos(buttonPos);
    check(buttonPos);
}

void MainWindow::tfunct(){
    //static int t=0;
    ui->label->setText( QString::number(t));
    //ui->lcdNumber->set
    t++;
}

void MainWindow::on_flechaD_clicked()
{
    if(imagS<imagMAX){
        imagS++;
        QString p1=":/imag/imag/";
        QString p2=QString::number(imagS);
        QString p3=".jpg";
        QPixmap pix(p1+p2+p3);
        ui->label_2->setPixmap(pix.scaled(ui->label_2->width(),ui->label_2->height(),Qt::KeepAspectRatio));

    }
}
void MainWindow::on_flechaI_clicked()
{
    if(imagS>1){
        imagS--;
        QString p1=":/imag/imag/";
        QString p2=QString::number(imagS);
        QString p3=".jpg";
        QPixmap pix(p1+p2+p3);
        ui->label_2->setPixmap(pix.scaled(ui->label_2->width(),ui->label_2->height(),Qt::KeepAspectRatio));

    }
}

void MainWindow::on_start_clicked()
{
    ui->label_2->setVisible(false);
    ui->start->setVisible(false);
    ui->flechaD->setVisible(false);
    ui->flechaI->setVisible(false);

    //////todo esto va a ir dentro del boton start
    /*FUNCION DE SELECCION DE LA IMAGEN QUE SE GUARDARA COMO ENTERO EN imagS*/
    MainWindow::setimag(imagS);//se llama a la funcion de asignacion de imagenes
    mergeM(buttonPos);
    MainWindow::setpos(buttonPos);
    timer->start(1000);
}

void MainWindow::on_fin_partida_clicked()
{

}

