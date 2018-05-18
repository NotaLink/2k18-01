#include <iostream>
#include <string>
using namespace std;
string encriptar(string pt){
	string ct;
	string alph = "abcdefghijklmnopqrstuvwxyz ,.+-_?!¿¡:;1234567890><{}[]*";
	string alph2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ,.+-_?!¿¡:;1234567890><{}[]*";
	for(int i=0 ; i<pt.length() ; i++){
		for(int j=0; j < alph.length() ; j++){
			if(pt[i] == alph[j]){
				ct = ct + alph[alph.length()-(j+1)];
			}
			else if(pt[i] == alph2[j]){
				ct = ct + alph2[alph2.length()-(j+1)];
			} 
		}
	}
	return ct;
}

string desencriptar(string pt){
	string ct;
	string alph = "abcdefghijklmnopqrstuvwxyz ,.+-_?!¿¡:;1234567890><{}[]*";
	string alph2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ,.+-_?!¿¡:;1234567890><{}[]*";
	for(int i=0 ; i<pt.length() ; i++){
		for(int j=0; j < alph.length() ; j++){
			if(pt[i] == alph[j]){
				ct = ct + alph[alph.length()-(j+1)];
			}
			else if(pt[i] == alph2[j]){
				ct = ct + alph2[alph2.length()-(j+1)];
			} 
		}
	}
	return ct;
}



int main() {
	string pt;
	string ct;
	string var;
	cout << "Que desea hacer?: "<<endl;
	cin >> var;
	if(var == "encriptar"){
		cout << "Mensaje a Encriptar: "<<endl;
		cin.ignore();
		std::getline(std::cin,pt);
		cout << encriptar(pt);
	}
	else{
		cout << "Mensaje a Desencriptar: "<< endl;
		cin.ignore();
		std::getline(std::cin,pt);
		cout << desencriptar(pt);
	}
	return 0;
}
