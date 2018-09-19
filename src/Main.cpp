#include <iostream>
#include <vector>
#include <string>
#include "Vector3D.h"

#define Ke 8987539422

using namespace std;

struct Carga
{
	double x;
	double y;
	double z;
	double carga;
};

struct Fuerza
{
	double x;
	double y;
	double z;
	double magnitud;
};

char ObtenerOpciones();
void IntroducirCargas(vector<Carga> &cargas);
void VerCargas(vector<Carga> &cargas);
void ObtenerFuerzas(vector<Fuerza> &fuerzas, const vector<Carga> &cargas);
double ObtenerDistancia(double x1, double y1, double z1, double x2, double y2, double z2);

int main()
{
	Vector3D vec1(1, 1, 1);
	Vector3D vec2(1, 1, 1);
	vector<Carga> cargas;
	bool isRunning = true;
	while (isRunning)
	{
		char opc = ObtenerOpciones();
		switch (opc)
		{
		case 0:
			isRunning = false;
			break;

		case 1:
			IntroducirCargas(cargas);
			break;

		case 2:
			VerCargas(cargas);
			break;

		case 3:
			//TODO Fuerzas
			break;

		default:
			break;
		}
	}
}

char ObtenerOpciones()
{
	int opc = 0;
	cout << string(47, '-') << endl
		 << "FuerzasElectricas por Victor D. Montero (18-09-2018)" << endl;
	cout << "1-Introducir Cargas" << endl
		 << "2-Ver Cargas" << endl
		 << "3-Obtener Fuerzas" << endl
		 << "0-Salir" << endl
		 << "-> ";
	cin >> opc;

	return opc;
}

void IntroducirCargas(vector<Carga> &cargas)
{
	cout << string(47, '-') << endl;
	while (true)
	{
		Carga carga;
		cout << "Para salir entre carga 0" << endl;
		cout << "x,y,z-> ";
		cin >> carga.x >> carga.y >> carga.z;
		cout << "carga-> ";
		cin >> carga.carga;

		if (carga.carga == 0)
			break;

		cargas.push_back(carga);
	}
}

void VerCargas(vector<Carga> &cargas)
{
	cout << string(47, '-') << endl;
	for (int i = 0; i < cargas.size(); i++)
	{
		Carga carga = cargas[i];
		cout << "x=" << carga.x << " y=" << carga.y << " z=" << carga.z
			 << " C=" << carga.carga << endl;
	}
}

void ObtenerFuerzas(vector<Fuerza> &fuerzas, const vector<Carga> &cargas)
{
	char S = 0;
	for (size_t i = 0; i < cargas.size() - 1; i++)
	{
		for (size_t j = 0; j < cargas.size() - 1; j++)
		{
			// Fuerza F;
			// double magnitud = Ke * (cargas[i].carga * cargas[j].carga) /
		}
	}
}