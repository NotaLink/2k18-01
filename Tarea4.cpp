#include <iostream>
#include <fstream>
using namespace std;

int MCD(int n, int m,int cont=0){
    if(m>n){
        int aux=n;
        n=m;
        m=aux;
    }
    if(n%m==0){
        if(m==1){
            return cont;
        }
        return 0;
    }
    return MCD(m,n%m,cont+1);
}
int inversoMod(int n, int m,int cont){
    int p[cont+2];
    p[0]=0;
    p[1]=1;
    int q[cont];
    int mod=m;
    for(int i=0;i<cont+2;i++){
        if (i<cont){
            q[i]=m/n;
            int aux=m%n;
            m=n;
            n=aux;
        }
        if(i>=2){
            p[i]=(p[i-2]-p[i-1]*q[i-2])%mod;
            if(p[i]<0){
                p[i]+=256;
            }
        }
    }
    return p[cont+1];
}


int main(){
    int n,m,cont,mod;
    char c;
    cout<<"ingresa la operación (+),(*),(-),(i)"<<endl;
    cin>> c;
    if(c=='i'){
        do{
            cout<<"ingresa un numero y el modulo";
            cin>> n>>mod;
            n=n%mod;
            if (n<0)
                n+=mod;
            cont=MCD(n,mod);
            if(!cont){
                cout<<"El numero ingresado no tiene inverso modular";
            }
        }while (!cont);
         cout<<"El inverso modular de: "<<n<<"mod("<<mod<<") es:"<<inversoMod(n,mod,cont);
    }else {
        cout<<"ingresa dos numeros y el modulo";
        cin>> n>>m>>mod;
        long resultado;
        if(c=='+'){
            resultado=(n+m)%mod;
        }else if(c=='-'){
            resultado=(n-m)%mod;
        }else if(c=='*'){
            resultado=(n*m)%mod;
        }
        if (resultado<0){
            resultado+=mod;
        }
        cout<<n<<c<<m<<" mod "<<mod<<"="<<resultado;
    }
    return 0;
}
