#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Vector3D.h"

#define Ke 8987539422
int Index = 0;

using namespace std;

struct Carga
{
	Vector3D pos;
	double carga;
	Carga() :carga(0.00){}
};

struct Fuerza
{
	Vector3D pos;
	double magnitud;
	Fuerza(double magnitud) :magnitud(magnitud){}
	Fuerza() :magnitud(0.00){}
};

char ObtenerOpciones();
void IntroducirCargas(vector<Carga> &cargas);
void VerCargas(vector<Carga> &cargas);
void ObtenerFuerzas(vector<Fuerza> &fuerzas, const vector<Carga> &cargas);

int main()
{
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
			cout << string(47, '-') << endl;
			for (size_t i = 0; i < fuerzas.size(); i++)
			{
				cout << fuerzas.at(i).magnitud << " : " << fuerzas.at(i).pos.toString() << endl;
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
		<< "3-Calcular fuerzas e Imprimir fuerza total" << endl
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
		cout << i << ": "
			<< "<" << carga.pos.x << ", " << carga.pos.y << ", " << carga.pos.z
			<< "> C=" << carga.carga << endl;
	}
}

void ObtenerFuerzas(vector<Fuerza> &fuerzas, const vector<Carga> &cargas)
{
	Fuerza fuerzaTotal = Fuerza();
	int opc = -1;

	if (cargas.empty())
	{
		cout << "Introduzca por lo menos dos cargas" << endl;
		return;
	}

	while (opc < 0 || opc >= cargas.size())
	{
		cout << "Introduzca el indice de la carga (Ctrl+C para salir)" << " [0-" << cargas.size() - 1 << "]" << endl
			<< "-> ";
		cin >> opc;
	}

	cout << string(47, '-') << endl;
	for (size_t i = 0; i < cargas.size(); i++)
	{
		if (Index != i)
		{
			double distance = cargas.at(opc).pos.distanteTo(cargas.at(i).pos);
			double magnitud = Ke * (((cargas.at(opc).carga * 1.0E-6) * (cargas.at(i).carga * 1.0E-6)) / (distance * distance * distance));

			Fuerza F;
			F.pos = magnitud * (cargas.at(i).pos - cargas.at(opc).pos);
			F.magnitud = F.pos.length();
			fuerzas.push_back(F);

			fuerzaTotal.pos += F.pos;
			fuerzaTotal.magnitud += F.magnitud;
		}
	}
	cout << fuerzaTotal.magnitud << " : " << fuerzaTotal.pos.toString() << endl;
}