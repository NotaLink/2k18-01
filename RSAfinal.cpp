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
    long long *res ;
    long long p = 0,q = 0,n,phiE,e,d,t,t1;

    long long modulo(long long a,long long m){
    long long div = a/m;
    long long modx = div*m;
    long long moda = a - modx;
    if(moda < 0){
        moda = moda + m;
    }
    return moda;
    }

    long long inv(long long r1,long long r2){
        long long aux,s1=1,s2=0,t1=0,t2=1,q,key = r2;
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
        if(s1 < 0){
            s1+=key;
        }
        return s1;
    }

    long long mcd (long long a, long long b){
        long long c;
        while (a!=b){
            if (a>b) a=a-b;
            else     b=b-a;
        }
        c=a;
        return c;
    }


    long long expmod(long long a,long long n,long long m){
        long long exp = 1;
        while(n != 0){
            if(modulo(n,2) != 0){
                exp = (exp*a);
                exp = modulo(exp,m);
            }
            a = a*a;
            a = modulo(a,m);
            n = n/2;
        }
        return exp;
    }


    bool primo(long long n){
        long long cont = 0;
        for(long long i=2;i<n;i++){
            if(modulo(n,i)==0){
                cont++;
            }
        }
        if(cont >= 1)   return false;
        else          return true;
    }

    RSA(){
        cout << "Mensaje a Encriptar: "<<endl;
        std::getline(cin,mensaje);
        t = mensaje.length();
        res = new long long[t];
        t1 = alfabeto.length();
        srand(time(NULL));
        p = rand()%1000;
        q = rand()%1000;
        while(!primo(p)){
            p = rand();
        }
        while(!primo(q)){
            q = rand();
        }
        n = p*q;
        phiE = (p-1)*(q-1);
        e = rand()%phiE;
        while(mcd(phiE,e) != 1 && e<phiE){
            e = rand()%phiE;
        }
        d = inv(e,phiE);
        cout << "p: " << p << endl;
        cout << "q: " << q << endl;
        cout << "n: " << n << endl;
        cout << "phiE: " << phiE << endl;
        cout << "e: " << e << endl;
        cout << "d: " << d << endl << endl << endl;
        cout << "Clave publica: < " << e <<" ; " << n << " >" << endl;
        cout << "Clave privada: < " << d <<" ; " << n << " >" << endl;
    }

    void cifrado(){
        long long num,found;
        for(long long i = 0;i < mensaje.length();i++){
            found = alfabeto.find(mensaje[i]);
            num = expmod(found,e,n);
            res[i] = num;
        }
    }

    string decifrado(){
        string res1 = "";
        long long num = 0,found = 0;
        for(long long i=0;i<t;i++){
            num = expmod(res[i],d,n);
            num = modulo(num,t1);
            cout << num << endl;
            res1+=alfabeto[num];
        }
        //cout << res1;
        return res1;
    }

    void printres(){
        for(long long i=0 ;i < t; i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
    ~RSA(){
        delete res;
    }

};

 int main(){
    RSA erreesea;
    string cripting;
    erreesea.cifrado();
    erreesea.printres();
    cout << erreesea.decifrado();
    return 0;

}
