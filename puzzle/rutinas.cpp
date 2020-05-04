#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
//funcion de numeros enteros aleatorios
int randint()
{
    //static int seed=(unsigned)time(NULL);
    //srand(seed); //use current time as seed for random generator

    for(int i=0; i<100000;i++){
    rand();
    }

    //for(int i=0; i<50;i++){
    //cout<<rand()%3<<endl;

    return rand()%3;


}
//funcion para mezclar la matriz de coordenadas
void mergeM(vector<vector<int>> &buttNum){
    srand((unsigned)time(NULL));
    for(int n=0; n<100; n++){
        int _i1=randint();
        int _j1=randint();
        int _i2=randint();
        int _j2=randint();

        swap(buttNum[_i1][_j1],buttNum[_i2][_j2]);
    }
}

//devuelve los indices del elemento a buscar en un vector 2D  de enteros
void findElement(vector<vector<int>> &vvi,int elm,int *i,int *j){

    vector<vector<int>>::iterator row;
    vector<int>::iterator col;
    for (row = vvi.begin(); row != vvi.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
            if (*col==elm) {
                return;
            }
            (*j)++;
        }
        *j=0;
        (*i)++;
    }

}
/*
//esta funcion movera los elementos dentro de la matriz si el movimiento es valido
void move(vector<vector<int>> &identM, int p){


}
*/
