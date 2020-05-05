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

//funcion para comprobar si la configuracion del puzle es resoluble
int getInvCount(vector<int> arr)
{
    int inv_count = 0;
    for (int i = 0; i < 9 - 1; i++)
        for (int j = i+1; j < 9; j++)
             if (arr[j] && arr[i] &&  arr[i] > arr[j])
                  inv_count++;
    return inv_count;
}

//conversion de la matriz de posiciones a un vector unidimensional
bool isSolvable(vector<vector<int>> vvi)
{

    vector<int> _butpos1d;
    vector<vector<int>>::iterator row;
    vector<int>::iterator col;
    for (row = vvi.begin(); row != vvi.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
           _butpos1d.push_back(*col);
        }
    }
    int invCount = getInvCount(_butpos1d);
    return (invCount%2 == 0);
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

    if(!isSolvable(buttNum)){
        mergeM(buttNum);
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
//funcion para encontrar el agujero si lo hay y sus cordenadas
bool findGap(vector<vector<int>> bPos, int *_iG, int *_jG, int _iB, int _jB ){

    vector <int> iV,jV;
    int dimi,dimj;

    if(_iB==0 || _iB==2){iV={1};dimi=1;}else{iV={0,2};dimi=2;}
    if(_jB==0 || _jB==2){jV={1};dimj=1;}else{jV={0,2};dimj=2;}

    for(int k=0; k<dimi;k++){//se comprueba la columna

        if(bPos[iV[k]][_jB]==0){
            *_iG=iV[k];
            *_jG=_jB;
            return true;
        }
    }

    for(int k=0;k<dimj;k++){//se comprueba la fila

        if(bPos[_iB][jV[k]]==0){
            *_iG=_iB;
            *_jG=jV[k];
            return true;
        }
    }

    return false;
}


//esta funcion movera los elementos dentro de la matriz si el movimiento es valido
void moveB(vector<vector<int>> &_buttPos, int p){

    int iB=0, jB=0;//index en la matriz del boton
    int iG=0, jG=0;//index del hueco si lo hubiera
    bool gap=false;//ident hueco
    findElement(_buttPos,p,&iB,&jB);//en los indices ya tengo la posicion del boton
    //hay que conseguir los indices adyacentes de la casilla

    gap=findGap(_buttPos,&iG,&jG,iB,jB);//la funcion modifica los indices en caso de encontrar el hueco y delvuelve true

    if(gap){//si se ha encontrado hueco

        swap(_buttPos[iB][jB],_buttPos[iG][jG]);//se intercambian las posiciones
    }


}

