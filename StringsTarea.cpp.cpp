#include<string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
using namespace std;
//18.7 a
string rot13(string palabra){
    for(int i=0;i<palabra.size();i++){
    if(palabra[i]>=65&&palabra[i]<=90){
        palabra[i]+=13;
       if (palabra[i]>90)
        {palabra[i]=(palabra[i]-90)+65;}

    }
    else if (palabra[i]>=97&&palabra[i]<=122){
        if(palabra[i]<110)
            palabra[i]+=13;
        else{
            palabra[i]-=13;
       }
    }
    }
    return palabra;
}
//18.7 b
string decodrot13(string palabra){
    for(int i=0;i<palabra.size();i++){
        if(palabra[i]>=65&&palabra[i]<=90){
            if(palabra[i]>=78)
                palabra[i]-=13;
            else{
                palabra[i]+=13;
        }
        }
        else if (palabra[i]>=97&&palabra[i]<=122){
            if(palabra[i]>=110)
                palabra[i]-=13;
            else{
                palabra[i]+=13;
           }
        }
    }
    return palabra;
}
//18.7 c
// No sería dificil descifrarlo sin la clave, sería posible facilmente con un programa que itere 26 veces
//probandolo como clave y en una de esas 26 sería facil de reconocer la palabra con sentido,
//Y al tener una supercomputadora yo creo que no afectaría nada en el funcionamiento, sino en la velocidad al ejecutarse

//18.11
string concatenar(string nombre,string apellido){
   string c(nombre + apellido);
   return c;
}
//18.12

//18.19
string insertasterisc(string palabra){
    palabra.insert(palabra.size() / 2, "******");
    return palabra;
}
//18.21
void tokens(string texto){
   int a=texto.size()-1;
   int b;
   while(a){
      b=texto.find_first_of(",;.?¡¿!()-" );
      a=b;
      if(b==string::npos) {
        break;
    }
      texto.replace(a,1," ");
    }
    cout<<texto<<endl;
    char * ptr1=strtok(&texto[0]," ");
    while(ptr1!=NULL){
        cout<<ptr1<<endl;
        ptr1=strtok(NULL," ");
    }
}
//18.22

string invertir(string palabra){
    string::reverse_iterator iterador = palabra.rbegin();
    while (iterador != palabra.rend())
    {
        cout << *iterador;
        ++iterador;
    }
    cout << endl;
}
//18.27

bool ascendente(string a,string b){
    return a<b;
}
bool descendente(string a,string b){
    return a>b;
}
void Ordseleccion(string palabra[],int tam,bool(*compara)(string, string)){
    int menorOmayor;
    for(int i=0;i<tam-1;i++){
        menorOmayor=i;
        for(int index=i+1;index<tam;index++)
            if(!(*compara)(palabra[menorOmayor],palabra[index])){
                menorOmayor=index;
            }
            swap(palabra[menorOmayor],palabra[i]);
        }
    }


void Ordenar(string palabra[],int orden,int tam){
 if(orden==1){
    Ordseleccion(palabra,tam,ascendente);
 }
 else{
    Ordseleccion(palabra,tam,descendente);
 }
 for(int i=0;i<tam;i++){
  cout<<palabra[i]<<endl;
 }

}

int main()
{

    return 0;
}
