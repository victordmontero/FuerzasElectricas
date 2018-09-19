#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Vector3D.h"

#define Ke 8987539422

using namespace std;

struct Carga
{
	Vector3D pos;
	double carga;
};

struct Fuerza
{
	Vector3D pos;
	double magnitud;
};

char ObtenerOpciones();
void IntroducirCargas(vector<Carga> &cargas);
void VerCargas(vector<Carga> &cargas);
void ObtenerFuerzas(vector<Fuerza> &fuerzas, const vector<Carga> &cargas);

int main()
{
	Vector3D vec1(1, 1, 1);
	Vector3D vec2(1, 2, 3);
	vector<Carga> cargas;
	vector<Fuerza> fuerzas;
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
			fuerzas.clear();
			ObtenerFuerzas(fuerzas, cargas);
			break;

		case 4:
			for (size_t i = 0; i < fuerzas.size(); i++)
			{
				cout << fuerzas[i].magnitud << " : " <<
					fuerzas[i].pos.toString() << endl;
			}
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
		<< "4-Imprimir Fuerzas" << endl
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
		cout << "Para salir entre \"0 0 0 0\"" << endl;
		cout << "x,y,z-> ";
		cin >> carga.pos.x >> carga.pos.y >> carga.pos.z;
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
	for (size_t i = 0; i < cargas.size(); i++)
	{
		Carga carga = cargas[i];
		cout << "x=" << carga.pos.x << " y=" << carga.pos.y << " z=" << carga.pos.z
			<< " C=" << carga.carga << endl;
	}
}

void ObtenerFuerzas(vector<Fuerza> &fuerzas, const vector<Carga> &cargas)
{
	cout << string(47, '-') << endl;
	for (size_t i = 0; i < cargas.size(); i++)
	{
		for (size_t j = 0; j < cargas.size(); j++)
		{
			if (i != j){
				Fuerza F;
				double distance = cargas.at(i).pos.squareDistanteTo(cargas.at(j).pos);
				F.magnitud = Ke * (cargas.at(i).carga * cargas.at(j).carga) / distance;
				double fx = 1;
				double fy = 1;
				double fz = 0.7071067812;

				F.pos = Vector3D(acos(fx), asin(fy), asin(fz))*F.magnitud;

				fuerzas.push_back(F);
			}
		}
	}
}