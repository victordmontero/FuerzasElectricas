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
};

struct Fuerza
{
	Vector3D pos;
	double magnitud;
};

Fuerza fuerzaTotal;

char ObtenerOpciones();
void IntroducirCargas(vector<Carga> &cargas);
void VerCargas(vector<Carga> &cargas);
void ObtenerFuerzas(vector<Fuerza> &fuerzas, const vector<Carga> &cargas, const Carga &carga);

int main()
{
	vector<Carga> cargas;
	vector<Fuerza> fuerzas;
	Carga cargaSeleccionada;
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
			ObtenerFuerzas(fuerzas, cargas,cargaSeleccionada);
			break;

		case 4:
			int opc;
			cout << "Introduzca el indice de la carga" << endl
				 << "-> ";
			cin >> opc;
			Index = opc;
			cargaSeleccionada = cargas[opc];
			break;

		case 5:
			// for (size_t i = 0; i < fuerzas.size(); i++)
			// {
			// 	cout << fuerzas[i].magnitud << " : " << fuerzas[i].pos.toString() << endl;
			// }
			cout << fuerzaTotal.magnitud << " : " << fuerzaTotal.pos.toString() << endl;
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
		 << "4-Seleccionar Carga" << endl
		 << "5-Imprimir Fuerzas" << endl
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

void ObtenerFuerzas(vector<Fuerza> &fuerzas, const vector<Carga> &cargas, const Carga &carga)
{
	cout << string(47, '-') << endl;
	for (size_t i = 0; i < cargas.size(); i++)
	{
		if (Index != i)
		{
			double distance = carga.pos.distanteTo(cargas.at(i).pos);
			double Fx = Ke * (((carga.carga * 1.0E-6) * (cargas.at(i).carga * 1.0E-6)) / (distance * distance * distance)) 
			* (cargas.at(i).pos.x - carga.pos.x);

			double Fy = Ke * (((carga.carga * 1.0E-6) * (cargas.at(i).carga * 1.0E-6)) / (distance * distance * distance)) 
			* (cargas.at(i).pos.y - carga.pos.y);

			double Fz = Ke * (((carga.carga * 1.0E-6) * (cargas.at(i).carga * 1.0E-6)) / (distance * distance * distance)) 
			* (cargas.at(i).pos.z - carga.pos.z);

			Fuerza F;
			F.pos = Vector3D(Fx,Fy,Fz);
			F.magnitud = sqrt((Fx*Fx)+(Fy*Fy)+(Fz*Fz));

			fuerzaTotal.pos += F.pos;
			fuerzaTotal.magnitud += F.magnitud;
		}
	}
}