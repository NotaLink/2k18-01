#include<iostream>
using namespace std;

void binariopos(int N,int A[100],int n);
void binarioneg(int N,int A[100],int n); 
void sumar(int A[100],int B[100],int bits); 

int main()
{
	while(1)
	{ 		
		int m,q;  
		
		int M10[100];           
		int	M01[100];          
		int Q[100];              
		int aux;         
		int bits1=0,bits2=0,bits; 
		
		int AC[100];                            
		
		cout<<endl<<"\t\t\tMULTIPLICACION CON SIGNO";
		
		cout<<endl<<endl<<" => MULTIPLICANDO  :";
		cin>>m;
		aux=m;
		
		while(aux!=0){
			aux=aux/2;
			bits1++;
		}
		
		cout<<endl<<" => MULTIPLICADOR  :";
		cin>>q;
		aux=q;
		
		while(aux!=0){
			aux=aux/2;
			bits2++;
		}

		if(bits1>bits2)
			bits=bits1;
		else
			bits=bits2;
		
		bits=bits+1; 
		
		cout<<endl<<endl<<endl<<" => MULTIPLICANDO  :";
		
		if(m<0)
		{
			binarioneg(m,M01,bits); 
			for(int i=0;i<bits;i++)
				cout<<M01[i];
		}     
		else
		{
			binariopos(m,M10,bits); 
			for(int i=0;i<bits;i++)
				cout<<M10[i];
		}            
		
		
		if(m<0)
		{
			binariopos(m,M10,bits); 
			binarioneg(m,M01,bits); 
		}
		else
		{
			binariopos(m,M01,bits); 
			binarioneg(m,M10,bits);
		}		
		
		cout<<endl<<endl<<" => MULTIPLICADOR  :";
		
		if(q<0)
			binarioneg(q,Q,bits); 
		else  
			binariopos(q,Q,bits);
		
		for(int i=0;i<bits;i++)
			cout<<Q[i];	
		for(int i=0;i<bits;i++)
			AC[i]=0;
		

		cout<<endl<<endl<<endl;
		int mult,MULT[100];
		mult=q*m;
		if(mult<0)
			binarioneg(mult,MULT,2*bits); 
		else  
			binariopos(mult,MULT,2*bits); 
		cout<<"->>>  "<<m<<" * "<<q<<" = "<<m*q<<" = ";   
		for(int i=0;i<2*bits;i++)
			cout<<MULT[i];
		cout<<endl<<endl;   
		system("PAUSE");
		
	} 
	
	
	return EXIT_SUCCESS;
	
}


void binariopos(int N,int A[100],int n)
{
	int aux[100];
	int i=0,j=0;
	int bits;
	
	if(N<0) N=N*(-1);
	
	while(N!=0){
		aux[i]=N%2;
		N=N/2;
		i++;
	}	
	
	bits=i;
	
	
	for(i=0;i<bits;i++)
		A[i]=aux[i];
	
	
	
	for(i=bits;i<n;i++)
		A[i]=0;
	
	
	for(int i=n-1;i>=0;i--)
	{
		aux[j]=A[i];    
		j++;
	}
	
	for(int i=0;i<n;i++)
		A[i]=aux[i];
	
	
}


void binarioneg(int N,int A[100],int n)
{
	
	
	int aux[100];
	int i=0,j=0;
	int bits;
	int N1=N;
	
	if(N<0) N=N*(-1)-1;
	else N=N-1;
	
	while(N!=0){
		aux[i]=N%2;
		N=N/2;
		i++;
	}
	
	
	bits=i;
	
	for(i=0;i<bits;i++)
		A[i]=aux[i];
	
	for(i=bits;i<n;i++)
		A[i]=0;
	
	
	for(int i=0;i<n;i++)
	{
		if(A[i]==0)
			A[i]=1;
		else
			A[i]=0;
	}
	
	
	for(int i=n-1;i>=0;i--)
	{
		aux[j]=A[i];    
		j++;
	}
	
	
	for(int i=0;i<n;i++)
		A[i]=aux[i];
	
	if(N1==0)
		for(int i=0;i<n;i++)
		A[i]=0;
	
	
}

void sumar(int A[100],int B[100],int bits)
{
	int acarreo=0;
	int suma;
	int m=bits;
	
	for(int i=0;i<m;i++)
	{
		suma=A[m-(1+i)]+B[m-(1+i)]+acarreo;
		
		if(suma==0)
		{
			A[m-(1+i)]=suma;
			acarreo=0;
		}
		
		if(suma==1)
		{
			A[m-(1+i)]=suma;
			acarreo=0;
		}
		
		if(suma==2)
		{
			A[m-(1+i)]=(suma-2);
			acarreo=1;
		}
		
		if(suma==3)
		{
			A[m-(1+i)]=(suma-2);
			acarreo=1;
		}
		
	} 
}      
