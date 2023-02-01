#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "header.hpp"

using namespace std;

bool lerArquivo(string nomeArq, Instancia &instancia, Node* &nos, int** &MA){
    ifstream txt(nomeArq);

    if(txt){
        string str, str2;
		char a;
		int campo = 0;
		bool aspasDuplas = true;
		
		//o csv é lido caractere por caractere
        txt >> str;
		do{
            getline(txt, str2);
            size_t start = str2.find_first_not_of(" ");
            str2 = str2.substr(start);
            switch(campo){
                case 0:
                    instancia.name = str2;
                    break;
                case 1:
                    instancia.location = str2;
                    break;
                case 2:
                    instancia.comment = str2;
                    break;
                case 3:
                    instancia.type = str2;
                    break;
                case 4:
                    instancia.size = stoi(str2);
                    break;
                case 5:
                    instancia.distribution = str2;
                    break;
                case 6:
                    instancia.depot = str2;
                    break;
                case 7:
                    instancia.routeTime = stoi(str2);
                    break;
                case 8:
                    instancia.timeWindow = stoi(str2);
                    break;
                case 9:
                    instancia.capacity = stoi(str2);
                    break;
                default:
                    break;
            }
            campo++;

            txt >> str;
		}while (str != "NODES");
        
        nos = new Node[instancia.size];

        for(int i=0; i<instancia.size; i++){
            txt >> str;
            nos[i].id = stoi(str);
            txt >> str;
            nos[i].lat = stof(str);
            txt >> str;
            nos[i].lon = stof(str);
            txt >> str;
            nos[i].dem = stoi(str);
            txt >> str;
            nos[i].etw = stoi(str);
            txt >> str;
            nos[i].ltw = stoi(str);
            txt >> str;
            nos[i].dur = stoi(str);
            txt >> str;
            nos[i].p = stoi(str);
            txt >> str;
            nos[i].d = stoi(str);
        }

        MA = new int*[instancia.size];
        for(int i=0; i<instancia.size; i++)
            MA[i] = new int[instancia.size];
        
        
        txt >> str;
        for(int i=0; i<instancia.size; i++){
            for(int j=0; j<instancia.size; j++){
                txt >> str;
                MA[i][j] = stoi(str);
            }
        }

		txt.close();

		return true;
	}
	else
		return false;
}

int main(){

    Instancia instancia;
    Node* nos;
    int** MA;

    string nomeArq;
	cout << "Digite o nome da instancia (sem a extensao): ";
	cin >> nomeArq;
    nomeArq = "instances/" + nomeArq + ".txt";

    lerArquivo(nomeArq, instancia, nos, MA);

    instancia.mostrarCampos();
    nos[5].mostrarCampos();

    delete nos;
    for(int i=0; i<instancia.size; i++)
        delete MA[i];
    delete MA;

    return 0;
}