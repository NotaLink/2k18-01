#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string>

using namespace std;

class RSA{
public:
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ.,-_()abcdefghijklmnopqrstuvwxyz 0123456789";
    string mensaje;
    int *res;
    int p = 0,q = 0,n,phiE,e,d,t;

    int inv(int r1,int r2){
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

    int mcd (int a, int b){
        int c;
        while (a!=b){
            if (a>b) a=a-b;
            else     b=b-a;
        }
        c=a;
        return c;
    }

    bool primo(int n){
        int cont = 0;
        //int s = sqrt(n);
        for(int i=2;i<=n;i++){
            if(n%i==0){
                cont++;
            }
        }
        if(cont==1)   return false;
        else          return true;
    }

    RSA(){
        cout << "Mensaje a Encriptar: "<<endl;
        std::getline(cin,mensaje);
        t = mensaje.length();
        res = new int[t];
        srand(time(NULL));
        p = rand();
        q = rand();
        while(primo(p)){
            p = rand();
        }
        while(primo(q)){
            q = rand();
        }
        n = p*q;
        p--;
        q--;
        phiE = p*q;
        e = rand()%phiE;
        while(mcd(phiE,e) != 1 && e<phiE){
            e = rand()%phiE;
        }
        d = inv(e,phiE);

        cout << "Clave publica: <" << e <<";" << n << ">" << endl;
        cout << "Clave privada: <" << d <<";" << n << ">" << endl;
    }

    void cifrado(){
        int num,found;
        for(int i = 0;i < mensaje.length();i++){
            found = alfabeto.find(mensaje[i]);
            num = pow(found,e);
            num = num%n;
            res[i] = num;
        }
    }
    void printres(){
        for(int i=0 ;i < t; i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }

};

int main(){
    RSA erreesea;
    string cripting;
    erreesea.cifrado();
    erreesea.printres();
    return 0;

}
