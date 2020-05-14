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
    *i=0;
    *j=0;
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
//funcion para encontrar el agujero alrededor de una posicion, si lo hay, y sus cordenadas
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














int calc_heu(vector<vector<int>> vvi){

    int _h=0;

    vector<vector<int>> ref={               {  { 1 },{ 2 },{ 3 }  },
                                            {  { 4 },{ 5 },{ 6 }  },
                                            {  { 7 },{ 8 },{ 0 }  }   };
    int n=0,k=0;
    //int iR=0,jR=0;


    vector<vector<int>>::iterator row;
    vector<int>::iterator col;
    for (row = vvi.begin(); row != vvi.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {


            if(*col!=ref[n][k] && *col!=0){
                _h++;
            }
            k++;
         }
        k=0;
        n++;
     }


    return _h;

}
//funcion para encotrar una matriz 2d en una matriz 3d
bool find_vector(vector<vector<int>> element,vector<vector<vector<int>>> list){

    vector<vector<vector<int>>>::iterator iter;

    for (iter = list.begin(); iter != list.end(); iter++) {

        if(element==*iter){
            return false;
        }
    }
    return true;//devuelve true si no encuentra el elemento en la lista
}



int piece_to_move(vector<vector<int>> &bPos,vector<vector<vector<int>>> &_prev, int _iB, int _jB ){

    //static int g=0;
    //g++;

    vector <int> iV,jV;
    int dimi,dimj;
    vector<vector<int>> mAux,mDef=bPos;

    int h_ini=10000;
    int piece=10;

    if(_iB==0 || _iB==2){iV={1};dimi=1;}else{iV={0,2};dimi=2;}
    if(_jB==0 || _jB==2){jV={1};dimj=1;}else{jV={0,2};dimj=2;}

    for(int k=0; k<dimi;k++){//se comprueba la columna
        mAux=bPos;
        swap(mAux[iV[k]][_jB],mAux[_iB][_jB]);//se intercambia el gap con la pieza

       int h = calc_heu(mAux);
       if(h<h_ini && find_vector(mAux,_prev)){
        h_ini=h;
        piece=mAux[_iB][_jB];
        mDef=mAux;

       }


    }

    for(int k=0;k<dimj;k++){//se comprueba la fila

        mAux=bPos;
        swap(mAux[_iB][jV[k]],mAux[_iB][_jB]);//se intercambia el gap con la pieza

        int h = calc_heu(mAux);
        if(h<h_ini && find_vector(mAux,_prev)){
         h_ini=h;
         piece=mAux[_iB][_jB];
         mDef=mAux;

        }

    }

    bPos=mDef;//cambia la matriz original a siguiente posicion
    _prev.push_back(bPos);
    return piece;//devuelve la pieza a mover
}


/*
void findElement(vector<vector<int>> &vvi,int elm,int *_i,int *_j){
    *_i=0;*_j=0;
    vector<vector<int>>::iterator row;
    vector<int>::iterator col;
    for (row = vvi.begin(); row != vvi.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
            if (*col==elm) {
                return;
            }
            (*_j)++;
        }
        *_j=0;
        (*_i)++;
    }

}
*/
void printVect(vector<vector<int>> &vvi){

    vector<vector<int>>::iterator row;
    vector<int>::iterator col;

    for (row = vvi.begin(); row != vvi.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {

            cout<<*col<<" ";
        }
        cout<<"\n"<<endl;
    }
    cout<<"\n\n"<<endl;
}



bool solv(vector<vector<int>> vecto, vector<int> &movments_array)
{

    vector<vector<int>> refrece={           {  { 1 },{ 2 },{ 3 }  },
                                            {  { 4 },{ 5 },{ 6 }  },
                                            {  { 7 },{ 8 },{ 0 }  }   };

    //printVect(vecto);

    vector<vector<vector<int>>> trace;
    trace.push_back(vecto);

    int f,c,k=0;

    while (refrece!=vecto) {

            findElement(vecto,0,&f,&c);//esto encuentra el gap
            movments_array.push_back( piece_to_move(vecto,trace,f,c));
            printVect(vecto);
            k++;

        if(k>1000){cout<<"Can't solve"<<endl;return false;}
    }

    return  true;
    cout<<k<<endl;
   // printVect(vecto);

}


