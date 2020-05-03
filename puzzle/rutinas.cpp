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
void mergeM(vector<vector<vector<int>>> &_posA,vector<vector<vector<int>>> &_indx,vector<vector<bool>> &_posF){
    srand((unsigned)time(NULL));
    for(int n=0; n<100; n++){
        int _i1=randint();
        int _j1=randint();
        int _i2=randint();
        int _j2=randint();
        swap(_posA[_i1][_j1],_posA[_i2][_j2]);
        swap(_posF[_i1][_j1],_posF[_i2][_j2]);
        swap(_indx[_i1][_j1],_indx[_i2][_j2]);
    }
}
