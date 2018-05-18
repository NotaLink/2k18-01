#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

class Affin {
public:
    string alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ.-_0123456789";
    int a;
    int b;
    int ap;
    int t = alfabeto.length(); // 66

    int mcd (int a, int b){
        int c;
        while (a!=b){
            if (a>b) a=a-b;
            else     b=b-a;
        }
        c=a;
        return c;
    }

   int xGCD(int a, int b, int &x, int &y) {
    if(b == 0) {
       x = 1;
       y = 0;
       return a;
    }

    int x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return y;
    }

    Affin(){
        int x,y;
        srand(time(NULL));
        a = rand()%51;
        b = rand()%101;
        while(mcd(a,t) != 1){
            a = rand()%51;
        }
        ap = xGCD(a,t,x,y);
        cout << "A: " << a << endl;
        cout << "B: " << b <<endl;
        cout << "ap: "<< ap << endl;
        //gcdExtended(a,t,x,y);
       // cout << *x << endl;
    }

    string Cifrado(string mensaje){
        int ascii,num;
        string res ;
        for(int i = 0;i < mensaje.length();i++){
            ascii = mensaje[i];
            num = (((a*ascii) + b)%t)+ 32;
            res = res + ((char)num);
        }
    return res;
    }

    string Decifrado(string mensaje){
        int ascii,num;
        string res ;
        for(int i = 0;i < mensaje.length();i++){
            ascii = mensaje[i];
            num = (((ap*ascii) - b)%t) - 32;
            res = res + ((char)num);
        }
    return res;
    }
};


int main(){
    Affin affin1;
    string mensaje,cripting,uncripting;
    cout << "Mensaje a Encriptar: "<<endl;
    std::getline(cin,mensaje);
    cripting = affin1.Cifrado(mensaje);
    cout << "Mensaje encriptado: " << cripting << endl;
    uncripting = affin1.Decifrado(cripting);
    cout << "Mensaje decifrado: " << uncripting << endl;
    return 0;
}
