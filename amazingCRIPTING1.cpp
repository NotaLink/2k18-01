#include <iostream>
#include <string>

using namespace std;


string encriptamiento(string mensaje,int n,int m){
        string mensajeFinal="";
        string aux="";
        int topes[]={n*n,(n*2)+(n/2)-1,n*n,(n*3)-2};
        int switch1[]={1,0,-1,1};
        int cuadrados;
        int vi,i,j,cont,elem,k,pos,mod;
        int posMensaje=0;
        int Inicio=(n-1)/2;
        bool flag;
        int filas[n];
        int suma=0;
        for(i=0;i<n;i++)
        {
            filas[i]=0;
        }
        for(i=0;i<m;i++)
        {
            suma+=topes[i%4];
        }
        for(i=mensaje.length();i<=suma;i++)
        {
            mensaje+="x";
        }
        for(i=0;i<m;i++)
        {
            cuadrados=i%4;
            aux="";
            if(!cuadrados)
            {
                k=1;
                vi=0;
                elem=n;
                flag=true;
                cont=0;
                pos=-1;
                mod=switch1[vi];
                for(j=posMensaje;j<topes[0]+posMensaje;j++)
                {
                    pos+=mod;
                    aux.insert(pos,1,mensaje[j]);
                    cont++;
                    if(cont==elem&&j)
                    {
                        if(flag)
                        {
                            elem--;
                            flag=false;
                        }else
                        {
                            flag=true;
                        }
                        if(vi==3)
                        {
                            vi=0;
                            k+=2;
                        }else
                        {
                            vi++;
                        }
                        mod=switch1[vi];
                        if(vi==0||vi==2)
                        {
                            mod*=k;
                        }
                        cont=0;
                    }
                }
                for(int j=0;j<n;j++)
                {
                    mensajeFinal.insert(filas[j],aux.substr(j*n,n));
                    for(k=j;k<n;k++) filas[k]+=n;
                }
                posMensaje+=topes[0];
            }
            else if(cuadrados==1)
            {
                cont=-1;
                elem=posMensaje+n-Inicio;
                for(pos=posMensaje;pos<elem;pos++)
                {
                    cont++;
                    aux.insert(cont,1,mensaje[pos]);
                    posMensaje++;
                }
                elem+=(n-Inicio-1);
                for(pos=posMensaje;pos<elem;pos++)
                {
                    aux.insert(cont,1,mensaje[pos]);
                    cont--;
                    posMensaje++;
                }
                elem+=Inicio;
                for(pos=posMensaje;pos<elem;pos++)
                {
                    aux.insert(cont,1,mensaje[pos]);
                    posMensaje++;
                }
                elem+=(Inicio-1);
                for(pos=posMensaje;pos<elem;pos++)
                {
                    cont+=2;
                    aux.insert(cont,1,mensaje[pos]);
                    posMensaje++;
                }
                elem=posMensaje+n-Inicio-1;
                for(pos=posMensaje;pos<elem;pos++)
                {
                    cont+=3;
                    aux.insert(cont,1,mensaje[pos]);
                    posMensaje++;
                }
                if(Inicio) aux.append(1,mensaje[posMensaje]);
                posMensaje++;
                if(Inicio)
                {
                    mensajeFinal.insert(filas[0],aux.substr(0,1));
                    for(k=0;k<n;k++)
                        filas[k]+=1;
                }
                else
                {
                    mensajeFinal.insert(filas[0],aux.substr(0,n));
                    for(k=0;k<n;k++)
                        filas[k]+=2;
                }
                for(j=1;j<Inicio;j++)
                {
                    mensajeFinal.insert(filas[j],aux.substr((2*j)-1,2));
                    for(k=j;k<n;k++)
                        filas[k]+=2;
                }
                for(j=1;j<n-1;j++)
                {
                    mensajeFinal.insert(filas[j],aux.substr(((3*(j-Inicio))+(2*Inicio)-1),3));
                    for(k=j;k<n;k++)
                        filas[k]+=3;
                }
                mensajeFinal.insert(filas[j],aux.substr(aux.length()-2,2));
                for(k=j;k<n;k++)
                    filas[k]+=2;
            }
            else if(cuadrados==2)
            {
                k=1;
                vi=0;
                elem=1;
                flag=false;
                cont=0;
                pos=0;
                mod=switch1[vi];
                for(j=posMensaje;j<topes[2]+posMensaje;j++)
                {
                    if(cont==elem)
                    {
                        if(flag)
                        {
                            flag=false;
                            elem++;
                        }else
                        {
                            flag=true;
                        }
                        if(vi==0)
                        {
                            vi=3;
                        }
                        else{
                            if(vi==2)
                        {
                                k+=2;
                            }
                            vi--;
                        }
                        mod=switch1[vi];
                        if(vi==0||vi==2)
                        {
                            mod*=k;
                        }
                        cont=0;
                    }
                    aux.insert(pos,1,mensaje[j]);
                    pos+=mod;
                    if(pos<0)
                    {
                        pos=0;
                    }else if(pos>aux.length())
                    {
                        pos=aux.length();
                    }
                    cont++;
                }
                for(int j=0;j<n;j++)
                {
                    mensajeFinal.insert(filas[j],aux.substr(j*n,n));
                    for(k=j;k<n;k++)
                        filas[k]+=n;
                }
                posMensaje+=topes[0];
            }
            else if(cuadrados==3)
            {
                pos=0;
                vi=0;
                cont=0;
                for(j=posMensaje;j<posMensaje+topes[3];j++)
                {
                    aux.insert(pos,1,mensaje[j]);
                    cont++;
                    if(cont==n)
                    {
                        vi=2;
                    }else if(cont==(n*2)-1)
                    {
                        vi=-1;
                    }else if(cont==(n*2))
                    {
                        vi=-2;
                    }
                    pos+=vi;
                    if(pos>aux.length())
                        pos=aux.length();
                }
                mensajeFinal.insert(filas[0],aux.substr(0,2));
                for(k=0;k<n;k++)
                    filas[k]+=2;
                for(j=1;j<n-1;j++){
                    mensajeFinal.insert(filas[j],aux.substr((j*3)-1,3));
                    for(k=j;k<n;k++)
                        filas[k]+=3;
                }
                mensajeFinal.insert(filas[n-1],aux.substr(aux.length()-2,2));
                filas[n-1]+=2;
                posMensaje+=topes[3];
            }
        }
        return mensajeFinal;
}

int main(){
    string mensaje = "Escribir, por ejemplo:  La noche está estrellada, y tiritan, azules, los astros, a lo lejos. El viento de la noche gira en el cielo y canta. ";
    //string mensaje = ""
    //string mensaje;
    int n=6,m=6;
    //cout << "Que mensaje desea encriptar?: " <<endl;
    //std::getline(std::cin,mensaje);
    //cout << "De cuanto x cuanto sera la matriz?: " << endl;
    //cin >> n;
    //cout << "En cuantos cuadrados lo desea poner?: " <<endl;
    //cin >> m;
    string code = encriptamiento(mensaje,n,m);
    cout << code <<endl;


}
