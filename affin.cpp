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
    int mcd (int a, int b){
        int c;
        while (a!=b){
            if (a>b) a=a-b;
            else     b=b-a;
        }
        c=a;
        return c;
    }
    Affin(){
        int t = alfabeto.length(); //66
        srand(time(NULL));
        a = rand()%51;
        cout << a << endl;
        while(mcd(a,t) != 1){
            a = rand()%51;
            cout << a << endl;
        }
    }

};


int main(){
    Affin affin1;

    return 0;
}
