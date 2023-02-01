#include <iostream>
using namespace std;
//nome do arquivo binario usado no programa
const string FILENAME = "data_athlete_event.bin";

struct Instancia{
    string name;
    string location;
    string comment;
    string type;
    int size;
    string distribution;
    string depot;
    int routeTime;
    int timeWindow;
    int capacity;

	void mostrarCampos(){
		cout << "Nome: " << name << endl;
		cout << "Localizacao: " << location << endl;
		cout << "Commentario: " << comment << endl;
		cout << "Tipo: " << type << endl;
		cout << "Tamanho: " << size << endl;
		cout << "Distribuicao: " << distribution << endl;
		cout << "Deposito: " << depot << endl;
		cout << "Tempo de Rota: " << routeTime << endl;
		cout << "Janela de Tempo: " << timeWindow << endl;
		cout << "Capacidade: " << capacity << endl;
	}
};

struct Node{
    int id;
    float lat;
    float lon;
    int dem;
    int etw;
    int ltw;
    int dur;
    int p;
    int d;

    void mostrarCampos(){
		cout << "Id: " << id << endl;
		cout << "Latitude: " << lat << endl;
		cout << "Longitude: " << lon << endl;
		cout << "Demanda: " << dem << endl;
		cout << "Inicio: " << etw << endl;
		cout << "Final: " << ltw << endl;
		cout << "Duracao: " << dur << endl;
		cout << "Par de coleta: " << p << endl;
		cout << "Par de entrega: " << d << endl;
	}
};
