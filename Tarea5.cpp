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
void encriptar(){
    int n,cont,mod;
    do{
        cout<<"ingresa tu clave privada: ";
        cin >> n;
        n=n%256;
        if (n<0)
            n+=256;
        cont=MCD(n,256);
    }while (!cont);
    int inverso=inversoMod(n,256,cont);
    ifstream myfile ("plain1.txt");
    cout<<"La clave pública es: "<< inverso<<endl;
    string texto="";
    if (myfile.is_open()){
        string aux;
        while (myfile.good()){
            getline(myfile,aux);
            texto+=aux;
            texto+=char(10);
            texto+=char(13);
        }
        texto.resize (texto.size () - 2);
    }
    for(int i=0;i<texto.size();i++){
        texto[i] =char((texto[i]*n)%256);
    }
    cout <<texto;
    ofstream myOutFile ("cipher.txt");
    if (myOutFile.is_open())    {
        myOutFile << texto;
        myOutFile.close();
    }
}
void desencriptar(){
    int n;
    cout<<"ingresa clave publica: ";
    cin>> n;
    ifstream myfile ("cipher.txt");
    string texto="";
    if (myfile.is_open()){
        string aux;
        while (myfile.good()){
            getline(myfile,aux);
            texto+=aux;
            texto+=char(10);
            texto+=char(13);
        }
        texto.resize (texto.size () - 2);
    }
    for(int i=0;i<texto.size();i++){
        texto[i] =char((texto[i]*n)%256);
    }
    cout <<texto;
    ofstream myOutFile ("plain2.txt");
    if (myOutFile.is_open())    {
        myOutFile << texto;
        myOutFile.close();
    }
}
int main(){
    char c;
    cout <<"Quieres (e)Encriptar o (d)Desencriptar"<<endl;
    cin >> c;
    if(c=='e'){
        encriptar();
    }else if(c=='d'){
        desencriptar();
    }

    return 0;
}
