#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Persona{
  private:
    int c;
    string abc="abcdefghijklmnopqrstuvwxyz";
    int tam=abc.size();
  public:
  Persona(int c1){
    c=c1;
  }

  int resto(int a, int n){
    int q,r;
    if (a<0){
      q=a/n;
      r=a-((q-1)*n);
      return r;
    }
    else{
      q=a/n;
      r=a-(q*n);
      return r;
    }
  }

  string cifrado(string mensaje){
      string msjc;
      for(int i=0;i<mensaje.size();i++){
            for(int j=0;j<tam;j++){
                if(mensaje[i]==abc[j]){
                    if(j+c>abc.size()-1){
                        msjc=msjc+abc[resto(j+c,tam)];
                    }
                    else{
                        msjc=msjc+abc[j+c];
                    }
                }
            }

      }
      return msjc;
  }
  string descifrado(string mensaje){
      string msjc;
      for(int i=0;i<mensaje.size();i++){
            for(int j=0;j<tam;j++){
                if(mensaje[i]==abc[j]){
                    if(j-c<0){
                        msjc=msjc+abc[(j-c)+tam];
                    }
                    else{
                        msjc=msjc+abc[j-c];
                    }
                }
            }

      }
      return msjc;
  }

};

int main() {
    Persona emisor(5);
    string x=emisor.cifrado("holacomo");
    cout<<x<<endl;
    string y=emisor.descifrado(x);
    cout<<y<<endl;
    //
    cout<<"esto es el criptoanalisis consta en probar 26 veces y buscar la palabra que tenga sentido"<<endl;
    for(int i=0;i<26;i++){
     Persona x(i);
     cout<<x.descifrado("ipmbdpnp")<<endl;
      }



    return 0;

}
