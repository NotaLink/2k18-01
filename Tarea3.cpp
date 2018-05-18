#include <iostream>

using namespace std;

int main()
{
    int cantDias[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int inicio =6;
    int mes,anho;
    cin >>mes>>anho;
    if (anho%4==0 && (anho%100!=0||anho%400==0)){
        cantDias[1]++;
    }
    int resA=anho-2000;
    long nDias;
    int diaInicio;
    if (resA>0){
        nDias=resA*365+((resA-1)/4)+1-int((resA-1)/100)+int((resA-1)/400);
        diaInicio=(inicio+nDias)%7;
    }else if(resA<0){
        nDias=(resA*-365)+(resA/-4)-int(resA/-100)+int(resA/-400);
        diaInicio=(inicio-nDias)%7+7;
    }
    for (int i=0;i<mes-1;i++){
        diaInicio+=cantDias[i];
    }
    diaInicio=diaInicio%7;
    cout << "  D  L  M  M  J  V  S"<<endl;
    for(int i=0;i<diaInicio;i++){
        cout<<"   ";
    }
    for(int i=1;i<=cantDias[mes-1];i++){
        if((i+diaInicio)%7==1){
            cout<<endl;
        }
        if(i<10){
            cout<<" ";
        }
        cout <<" " << i;
    }
    return 0;
}
