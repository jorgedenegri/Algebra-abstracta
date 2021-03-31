#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Persona{
  private:
    int f;
    int c;
  public:
  //Creo el constructor persona para que me pida como parametros la clave en este caso f y c
  Persona(int c1,int c2){
    f=c1;
    c=c2;
  }
  //En mi funcion cifrado es donde va la logica principal del codigo,el primer for va aumentar (espacios en este caso " ")
  //que le faltan al final de la palabra, en el caso de que no falten no aumenta nada. Creo dos for
  //porque necesito recorrer f espacios c veces, una variable k que va a contener la posiciones del encriptado
  string cifrado(string mensaje){
      string msjc;
      for(int i=0;i<(f*c)-mensaje.size();i++){
          mensaje+="_";
      }
      for(int i=0;i<c;i++){
        for(int j=0,k=i;j<f;j++,k+=c){
          msjc=msjc+mensaje[k];
        }
      }
      cout<<"[[[[[[[MENSAJE CIFRADO]]]]]]"<<endl;
      cout<<endl;
      return msjc;
  }

  string descifrado(string mensaje){
      string msjd;
      for(int i=0;i<f;i++){
        for(int j=0,k=i;j<c;j++,k+=f){
          msjd=msjd+mensaje[k];
        }
      }
      cout<<"[[[[[[MENSAJE DESCIFRADO]]]]]]"<<endl;
      cout<<endl;
      return msjd;
  }
};

int main() {
	string pb;
	Persona emisor(3,6);
    Persona receptor(3,6);
    cout<<"ingrese palabra :"<<endl;
    cin>>pb;
    string x=emisor.cifrado(pb);
    cout<<x<<endl;
    cout<<endl;
    cout<<receptor.descifrado(x);

    return 0;

}
