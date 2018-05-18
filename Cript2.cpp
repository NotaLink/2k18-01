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

int main() {
	string pt;
	string ct;
	string ct2[ct.length()];
	int filas,columnas;
	char **Matriz;
    cout << "Mensaje a Encriptar: " << endl;
    cin.ignore();
	std::getline(std::cin,pt);
	cout << endl << "Clave para Descifrar?: ";
	cin >> filas;
	cout << endl;
	ct = encriptar(pt);
	columnas = ct.length();
	Matriz = new char*[filas];
	for(int i =0;i< filas;i++){
        Matriz[i] = new char[columnas];
	}
	for(int i=0;i<filas;i++){
        for(int j =0;j<columnas;j++){
            Matriz[i][j] = '^';
        }
	}
	int a = 0,b = 0,c = 0,d =0;

	for(int z = 0;z<columnas/2;z++){
        for(int i=0;i<filas;i++){
            for(int j =0;j<columnas;j++){
                if(a== filas-1){
                    c = 1;
                }
                if(a == 0){
                    c = 0;
                }
                if(c == 0){
                    if(i == a && j == b){
                        Matriz[i][j] = ct[b];
                        a++;
                        b++;
                    }
                }
                if(c == 1){
                    if(i == a && j == b){
                        Matriz[i][j] = ct[b];
                        a--;
                        b++;
                    }
                }

            }
        }
	}
     for(int i=0;i<filas;i++){
        for(int j =0;j<columnas;j++){
            cout <<Matriz[i][j] << " ";
        }
        cout << endl;
	}
	 for(int i=0;i<filas;i++){
        for(int j =0;j<columnas;j++){
            if(Matriz[i][j] != '^'){
                ct2[d] = Matriz[i][j];
                d++;
            }
        }
    }
	cout << endl << ct << endl;
	cout << endl << ct2 << endl;
	return 0;
}
