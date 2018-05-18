#include <iostream>
#include <stdlib.h>
using namespace std;

int GCD1(int a,int b){
    int r;
    r = a%b;
    if(r == 0){
        return b;
    }
    else
        a= b;
        cout << "a : " << a <<endl;
        b = r;
        cout << "b : " << b << endl;
        return GCD1(a,b);
}
int GCD2(int a,int b){
    int r;
    while(true){
        r=a%b;
        if(r==0){
            return b;
        }
        if(r>b/2){
            r=b-r;
        }
        a=b;
        b=r;
    }
}
int GCD3(int a, int b){
	if(b==0){
		return a;
	}
	return GCD3(b,a%b);
}
int GCD4(int a, int b){
	if(abs(b)>abs(a)){
		return GCD4(b,a);
	}
	if(b ==0){
		return a;
	}
	if(a%2==0 && b%2==0){
		return 2 * GCD4(a/2,b/2);
	}
	if(a%2==0 && b%2==1){
		return GCD4(a/2,b);
	}
	if(a%2==1 && b%2==0){
		return GCD4(a,b/2);
	}
	return GCD4((abs(a)-abs(b))/2,b);
}
int GCD5(int x,int y){
    int g=1;
    int t;
    while(!(x%2) &&!(y%2)){
        x=x>>1;
        y=y>>1;
        g=g<<1;
    }
    while(x){
        while(!(x%2))
            x/=2;
        while(!(y%2))
            y/=2;
        t=abs(x-y)/2;
        if(x>=y)
            x=t;
        else
            y=t;
    }
    return g*y;
}

int GCD6(int a , int b){
    while(a != b){
        if (a>b) {
            a = a-b;
        }
        else
            b = b -a;
    }
    return a;
}

int main(){
    int a,b;
    cout << "Ingrese 2 numeros: " << endl;
    //cin >> a >> b ;
    a = 412;
    b = 260;
    cout << "1: " <<GCD1(a,b) << endl;
    /*cout << "2: " <<GCD2(a,b) << endl;
    cout << "3: " <<GCD3(a,b) << endl;
    cout << "4: " <<GCD4(a,b) << endl;
    cout << "5: " <<GCD5(a,b) << endl;
    cout << "6: " <<GCD6(a,b) << endl;*/

    return 0;
}
