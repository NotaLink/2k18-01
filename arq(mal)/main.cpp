#include<iostream>
using namespace std;
template <typename t>
void mostrar(t);

void mostrar(unsigned int a){
    for(int i =0;i<32;i++){
        if(a&(1<<31)){
            cout<<1;
        }else{
            cout<<0;
        }
        a=a<<1;
    }
}
void mostrar(int a){
    for(int i =0;i<32;i++){
        if(a&(1<<31)){
            cout<<1;
        }else{
            cout<<0;
        }
        a=a<<1;
    }
}
void mostrar(unsigned char a){
    for(int i =0;i<8;i++){
        if(a&(1<<7)){
            cout<<1;
        }else{
            cout<<0;
        }
        a=a<<1;
    }
}
void mostrar(char a){
    for(int i =0;i<8;i++){
        if(a&(1<<7)){
            cout<<1;
        }else{
            cout<<0;
        }
        a=a<<1;
    }
}
void sinSigno(int x, int y) {
	bool q1 = false;
	int Cont,n = 8;
	unsigned char m,q,A = 0;
	m=x;
	q=y;
	Cont=n;
	cout << "       Numero a:      Numero b:    " <<endl;
	while(Cont){
		if(q&1){
			unsigned int aux=A;
			A+=m;
			if(A<aux){
				q1=true;
			}
		}
		q=q>>1;
		if(A&1){
			q+=1<<(n-1);
		}
		A=A>>1;
		if(q1){
			A+=1<<(n-1);
		}
		q1=false;
		Cont--;
		cout<<q1<<"      ";
		mostrar(A);
		cout<<"        ";
		mostrar(q);
		cout<<endl;
	}
	cout <<endl << "Resultado decimal: " <<endl;
	cout<<((unsigned long)A<<32)+q <<endl;
}

void conSigno(int x, int y){
    char a = 0,n = 8,m,q;
    bool q1=false;
    m=x;q=y;
    int Cont=n;
    cout << "Numero a:     Numero b:  "<<endl;
    while (Cont){
        mostrar(a);
		cout<<"      ";
		mostrar(q);
		cout<<" "<<q1<<endl;
		if((q&1)&&(!q1)){
		    a-=m;
		}else if((!(q&1))&&q1){
		    a+=m;
		}
		q1=q&1;
		q=q>>1;
		if(a&1&&!(q&(1<<(n-1)))){
            q+=(1<<(n-1));
		}else if(!(a&1)&&q&(1<<(n-1))){
            q-=(1<<(n-1));
		}
		a=(a>>1);
		Cont--;
    }

    cout<<endl << "Resultado binario:\n";
    mostrar(a);
    cout<<" ";
    mostrar(q);
    cout<<endl <<"\nResultado decimal:\n";
    if(n==32){
        cout<<((long)a<<32)+(unsigned int)q;
    }else{
        cout<<((int)a<<8)+(unsigned char)q;
    }
}
int main(){
    sinSigno(10,11);
    return 0;
}
