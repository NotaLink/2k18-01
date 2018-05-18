#include <iostream>
#include <sstream>
#include<string>
using namespace std;

string transformar_numeros(string a,int x){
    string res;
    if(x == 1){
        if(a[0] == '1') res = res+"Uno";
        else if(a[0] == '2') res = res+"Dos";
        else if(a[0] == '3') res = res+"Tres";
        else if(a[0] == '4') res = res+"Cuatro";
        else if(a[0] == '5') res = res+"Cinco";
        else if(a[0] == '6') res = res+"Seis";
        else if(a[0] == '7') res = res+"Siete";
        else if(a[0] == '8') res = res+"Ocho";
        else if(a[0] == '9') res = res+"Nueve";
        else res = res+"Cero";
    }
    else if(x == 2){
        if (a[0] == '1' && a[1] == '1'){res = res+"Once";  return res;}
        else if (a[0] == '1' && a[1] == '2'){res = res+"Doce";  return res;}
        else if (a[0] == '1' && a[1] == '3'){res = res+"Trece";  return res;}
        else if (a[0] == '1' && a[1] == '4'){res = res+"Catorce"; return res;}
        else if (a[0] == '1' && a[1] == '5'){res = res+"Quince";  return res;}
        if(a[0] == '1') res = res+"diez";
        else if(a[0] == '2') res = res+"veinte";
        else if(a[0] == '3') res = res+"Treinta";
        else if(a[0] == '4') res = res+"Cuarenta";
        else if(a[0] == '5') res = res+"Cincuenta";
        else if(a[0] == '6') res = res+"Sesenta";
        else if(a[0] == '7') res = res+"Setenta";
        else if(a[0] == '8') res = res+"Ochenta";
        else if(a[0] == '9') res = res+"Noventa";
        else res = res+"";

        if(a[1] == '1') res = res+"y uno";
        else if(a[1] == '2') res = res+" y dos";
        else if(a[1] == '3') res = res+" y tres";
        else if(a[1] == '4') res = res+" y cuatro";
        else if(a[1] == '5') res = res+" y cinco";
        else if(a[1] == '6') res = res+" y seis";
        else if(a[1] == '7') res = res+" y siete";
        else if(a[1] == '8') res = res+" y ocho";
        else if(a[1] == '9') res = res+" y nueve";
        else res = res+"";
    }
    else {
        if (a[0] == '1' && a[1] == '0' && a[2] == '0'){res = res+"Cien"; return res;}
        else if (a[0] == '1' && a[1] == '1' && a[2] == '0'){res = res+"Ciento Diez"; return res;}
        else if (a[0] == '1' && a[1] == '1' && a[2] == '1'){res = res+"Ciento Once"; return res;}
        else if (a[0] == '1' && a[1] == '1' && a[2] == '2'){res = res+"Ciento Doce"; return res;}
        else if (a[0] == '1' && a[1] == '1' && a[2] == '3'){res = res+"Ciento Trece"; return res;}
        else if (a[0] == '1' && a[1] == '1' && a[2] == '4'){res = res+"Ciento Catorce"; return res;}
        else if (a[0] == '1' && a[1] == '1' && a[2] == '5'){res = res+"Ciento Quince";  return res;}
        if(a[0] == '1') res = res+"Ciento ";
        else if(a[0] == '2') res = res+"Doscientos ";
        else if(a[0] == '3') res = res+"Trescientos ";
        else if(a[0] == '4') res = res+"Cuatrocientos ";
        else if(a[0] == '5') res = res+"Quinientos ";
        else if(a[0] == '6') res = res+"Seiscientos ";
        else if(a[0] == '7') res = res+"Setecientos ";
        else if(a[0] == '8') res = res+"Ochocientos ";
        else if(a[0] == '9') res = res+"Novecientos ";
        else res = res+"";

        if(a[1] == '1') res = res+"diez";
        else if(a[1] == '2') res = res+"veinte";
        else if(a[1] == '3') res = res+"Treinta";
        else if(a[1] == '4') res = res+"Cuarenta";
        else if(a[1] == '5') res = res+"Cincuenta";
        else if(a[1] == '6') res = res+"Sesenta";
        else if(a[1] == '7') res = res+"Setenta";
        else if(a[1] == '8') res = res+"Ochenta";
        else if(a[1] == '9') res = res+"Noventa";
        else res = res+"";

        if(a[2] == '1') res = res+" y uno";
        else if(a[2] == '2') res = res+" y dos";
        else if(a[2] == '3') res = res+" y tres";
        else if(a[2] == '4') res = res+" y cuatro";
        else if(a[2] == '5') res = res+" y cinco";
        else if(a[2] == '6') res = res+" y seis";
        else if(a[2] == '7') res = res+" y siete";
        else if(a[2] == '8') res = res+" y ocho";
        else if(a[2] == '9') res = res+" y nueve";
        else res = res+"";
    }
    return res;

}


int main()
{
    std::ostringstream ss;
    std::string a = "";
    std::string b = "";
    std::string c = "";
    std::string d = "";
    long long n;
    int dig = 0;
    int adig,bdig,cdig,ddig;
    cout << "Ingrese un numero entre 0 y 999,999,999,999 sin comas por favor: " << endl;
    cin >> n;
    ss << n;
    std::string str = ss.str();
    while (n > 0){
    n = n/10;
    ++dig;
    }
    switch(dig){
    case 1:
        a = str.substr(0,1);
        adig = 1;
        cout << transformar_numeros(a,adig);
        break;
    case 2:
        a = str.substr(0,2);
        adig = 2;
        cout << transformar_numeros(a,adig);
        break;
    case 3:
        a = str.substr(0,3);
        adig = 3;
        cout << transformar_numeros(a,adig);
        break;
    case 4:
        a = str.substr(0,1);
        adig = 1;
        b = str.substr(1,3);
        bdig = 3;
        cout << transformar_numeros(a,adig) << " mil ";
        cout << transformar_numeros(b,bdig);
        break;
    case 5:
        a = str.substr(0,2);
        adig = 2;
        b = str.substr(2,3);
        bdig = 3;
        cout << transformar_numeros(a,adig) << " mil ";
        cout << transformar_numeros(b,bdig);
        break;
    case 6:
        a = str.substr(0,3);
        adig = 3;
        b = str.substr(3,3);
        bdig = 3;
        cout << transformar_numeros(a,adig) << " mil ";
        cout << transformar_numeros(b,bdig);
        break;
    case 7:
        a = str.substr(0,1);
        adig = 1;
        b = str.substr(1,3);
        bdig = 3;
        c = str.substr(4,3);
        cdig = 3;
        cout << transformar_numeros(a,adig) << " millones ";
        cout << transformar_numeros(b,bdig) << " mil ";
        cout << transformar_numeros(c,cdig);
        break;
    case 8:
        a = str.substr(0,2);
        adig = 2;
        b = str.substr(2,3);
        bdig = 3;
        c = str.substr(5,3);
        cdig = 3;
        cout << transformar_numeros(a,adig) << " millones ";
        cout << transformar_numeros(b,bdig) << " mil ";
        cout << transformar_numeros(c,cdig);
        break;
    case 9:
        a = str.substr(0,3);
        adig = 3;
        b = str.substr(3,3);
        bdig = 3;
        c = str.substr(6,3);
        cdig = 3;
        cout << transformar_numeros(a,adig) << " millones ";
        cout << transformar_numeros(b,bdig) << " mil ";
        cout << transformar_numeros(c,cdig);
        break;
    case 10:
        a = str.substr(0,1);
        adig = 1;
        b = str.substr(1,3);
        bdig = 3;
        c = str.substr(4,3);
        cdig = 3;
        d = str.substr(7,3);
        ddig = 3;
        cout << transformar_numeros(a,adig) << " billones ";
        cout << transformar_numeros(b,bdig) << " millones ";
        cout << transformar_numeros(c,cdig) << " mil ";
        cout << transformar_numeros(d,ddig);
        break;
    case 11:
        a = str.substr(0,2);
        adig = 2;
        b = str.substr(2,3);
        bdig = 3;
        c = str.substr(5,3);
        cdig = 3;
        d = str.substr(8,3);
        ddig = 2;
        cout << transformar_numeros(a,adig) << " billones ";
        cout << transformar_numeros(b,bdig) << " millones ";
        cout << transformar_numeros(c,cdig) << " mil ";
        cout << transformar_numeros(d,ddig);
        break;
    case 12:
        a = str.substr(0,3);
        adig = 3;
        b = str.substr(3,3);
        bdig = 3;
        c = str.substr(6,3);
        cdig = 3;
        d = str.substr(9,3);
        ddig = 3;
        cout << transformar_numeros(a,adig) << " billones ";
        cout << transformar_numeros(b,bdig) << " millones ";
        cout << transformar_numeros(c,cdig) << " mil ";
        cout << transformar_numeros(d,ddig);
        break;
    }


    return 0;

}
