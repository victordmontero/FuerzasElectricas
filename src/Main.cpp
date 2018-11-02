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
	Carga() : carga(0.00) {}
};

struct Fuerza
{
	Vector3D pos;
	double magnitud;
	Fuerza(double magnitud) : magnitud(magnitud) {}
	Fuerza() : magnitud(0.00) {}
};

struct CampoElectrico : public Fuerza
{
	CampoElectrico() : Fuerza(1.00) {}
};

char ObtenerOpciones();
void IntroducirCargas(vector<Carga> &cargas);
void VerCargas(vector<Carga> &cargas);
void ObtenerFuerzas(vector<Fuerza> &fuerzas, const vector<Carga> &cargas);
void ObtenerCampos(vector<CampoElectrico> &campos, const vector<Carga> &cargas);
void ObtenerEnergia(const vector<Carga> &cargas);
void ObtenerPotencial(const vector<Carga> &cargas);

int main()
{
	vector<Carga> cargas;
	vector<Fuerza> fuerzas;
	vector<CampoElectrico> campos;

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
			campos.clear();
			ObtenerCampos(campos, cargas);
			break;

		case 5:
			ObtenerEnergia(cargas);
			break;

		case 6:
			ObtenerPotencial(cargas);
			break;

		case 7:
			cout << string(47, '-') << endl;
			for (size_t i = 0; i < fuerzas.size(); i++)
			{
				cout << fuerzas.at(i).magnitud << " : " << fuerzas.at(i).pos.toString() << endl;
			}
			break;

		case 8:
			cout << string(47, '-') << endl;
			for (size_t i = 0; i < campos.size(); i++)
			{
				cout << campos.at(i).magnitud << " : " << campos.at(i).pos.toString() << endl;
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
		<< "4-Calcular Campos e Imprimir Campo Electrico en un punto P" << endl
		<< "5-Calcular Energia Electrica" << endl
		<< "6-Calcular Potencial Electrico" << endl
		<< "7-Imprimir resultados de Fuerzas" << endl
		<< "7-Imprimir resultados de Campos" << endl
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
		cout << "x-> ";
		cin >> carga.pos.x;
		cout << "y-> ";
		cin >> carga.pos.y;
		cout << "z-> ";
		cin >> carga.pos.z;
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
			<< carga.pos.toString()
			<< " C=" << carga.carga << endl;
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
		cout << "Introduzca el indice de la carga (Ctrl+C para salir)"
			<< " [0-" << cargas.size() - 1 << "]" << endl
			<< "-> ";
		cin >> opc;
	}

	cout << string(47, '-') << endl;
	for (size_t i = 0; i < cargas.size(); i++)
	{
		if (opc != i)
		{
			double distance = cargas.at(opc).pos.distanteTo(cargas.at(i).pos);
			double magnitud = Ke * (((cargas.at(opc).carga * 1.0E-6) * (cargas.at(i).carga * 1.0E-6)) / (distance * distance * distance));

			Fuerza F;
			F.pos = magnitud * (cargas.at(opc).pos - cargas.at(i).pos);
			F.magnitud = F.pos.length();
			fuerzas.push_back(F);

			fuerzaTotal.pos += F.pos;
			fuerzaTotal.magnitud = fuerzaTotal.pos.length();
		}
	}
	cout << fuerzaTotal.magnitud << " micro N : " << fuerzaTotal.pos.toString() << endl;
}

void ObtenerCampos(vector<CampoElectrico> &campos, const vector<Carga> &cargas)
{
	CampoElectrico campo;
	Vector3D pos;

	if (cargas.empty())
	{
		cout << "Introduzca al menos una carga" << endl;
		return;
	}

	cout << "Introduzca el vector posicion del punto en este orden P(x,y,z):" << endl
		<< "->";
	cin >> pos.x >> pos.y >> pos.z;

	cout << string(47, '-') << endl;
	for (size_t i = 0; i < cargas.size(); i++)
	{
		double distance = pos.distanteTo(cargas.at(i).pos);
		double magnitud = Ke * (((cargas.at(i).carga * 1.0E-6)) / (distance * distance * distance));

		CampoElectrico E;
		E.pos = magnitud * (pos - cargas.at(i).pos);
		E.magnitud = E.pos.length();
		campos.push_back(E);

		campo.pos += E.pos;
		campo.magnitud = campo.pos.length();
	}

	cout << campo.magnitud << " micro N/C : " << campo.pos.toString() << endl;
}

void ObtenerPotencial(const vector<Carga> &cargas)
{
	double energiaTotal = 0;
	Vector3D pos;

	if (cargas.empty())
	{
		cout << "Introduzca al menos una carga" << endl;
		return;
	}

	cout << "Introduzca el vector posicion del punto en este orden P(x,y,z):" << endl
		<< "->";
	cin >> pos.x >> pos.y >> pos.z;

	cout << string(47, '-') << endl;
	for (size_t i = 0; i < cargas.size(); i++)
	{
		double distance = pos.distanteTo(cargas.at(i).pos);
		double magnitud = Ke * (((cargas.at(i).carga*1.0E-6)) / distance);

		energiaTotal += magnitud;
	}

	cout << "Energia en un Punto P" << pos.toString() << ":" << energiaTotal << " V (J/C)" << endl;
}

void ObtenerEnergia(const vector<Carga> &cargas)
{
	double potencialTotal = 0;

	if (cargas.empty())
	{
		cout << "Introduzca al menos dos cargas" << endl;
		return;
	}

	for (size_t i = 0; i < cargas.size(); i++)
	{
		for (size_t j = 0; j < cargas.size(); j++)
		{
			if (i < j)
			{
				double distance = cargas.at(i).pos.distanteTo(cargas.at(j).pos);
				double magnitud = Ke * (((cargas.at(i).carga * 1.0E-6)*(cargas.at(j).carga * 1.0E-6)) / distance);

				potencialTotal += magnitud;
			}
		}
	}
	cout << "Energia Electrica:" << potencialTotal << " J" << endl;
}