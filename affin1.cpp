#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

class Affin {
public:
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.,-_()abcdefghijklmnopqrstuvwxyz 0123456789";
    int a = 43;
    int b = 89;
    int ap = -8;
    int t = alfabeto.length(); // 69
    int mcd (int a, int b){
        int c;
        while (a!=b){
            if (a>b) a=a-b;
            else     b=b-a;
        }
        c=a;
        return c;
    }


    int eucExt(int r1,int r2){
        int aux,s1=1,s2=0,t1=0,t2=1,q;
        while(r2){
            q=r1/r2;
            aux=r1-(q*r2);
            r1=r2;
            r2=aux;
            aux=s1-(q*s2);
            s1=s2;
            s2=aux;
            aux=t1-(q*t2);
            t1=t2;
            t2=aux;
        }
        return s1;
    }

    Affin(){
        int x,y;
        srand(time(NULL));
        a = rand();
        b = rand();
        while(mcd(a,t) != 1){
            a = rand();
        }
        ap = eucExt(a,t);
        cout << "T: " << t <<endl;
        cout << "A: " << a <<endl;
        cout << "B: " << b <<endl;
        cout << "ap: "<< ap <<endl;
        }

    string Cifrado(string mensaje){
        int found = 0,num;
        string res = "";
        for(int i = 0;i < mensaje.length();i++){
            found = alfabeto.find(mensaje[i]);
            num = (((a*found)+b)%t);
            res = res + alfabeto[num];
        }
    return res;
    }

    string Decifrado(string mensaje){
        int found = 0,num;
        string res = "";
        for(int i = 0;i < mensaje.length();i++){
            found = alfabeto.find(mensaje[i]);
            found = found - b;
            num = (found*ap)%t;
            res = res + alfabeto[num];
        }
    return res;
    }
};


int main(){
    Affin affin1;
    string mensaje,cripting,uncripting;
    cout << "Mensaje a Encriptar: "<<endl;
    //std::getline(cin,mensaje);
    mensaje = "Para cada uno de los algoritmos calcule el máximo común divisor para los enteros 412 y 260,realizando un seguimiento numérico manual, indicando la variación de las variables paso a paso.";
    cripting = affin1.Cifrado(mensaje);
    cout << "Mensaje encriptado: " << cripting << endl;
    uncripting = affin1.Decifrado(cripting);
    cout << " Mensaje decifrado: " << uncripting << endl;
    return 0;
}
