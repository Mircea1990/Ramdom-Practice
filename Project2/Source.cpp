#include<iostream>
#include<stdint.h>
#include<string>

using namespace std;

struct Laptop
{
	char* model;
	int RAM;
	double memorie;
	double pret;
};

Laptop citesteLaptop()
{
	Laptop laptop;
	cout << "Model laptop: \n";
	char buffer [20];
	cin >> buffer;
	laptop.model = new char [strlen(buffer) + 1];
	strcpy_s(laptop.model, strlen(buffer) + 1, buffer);

	cout << "Memorie RAM: \n";
	cin >> laptop.RAM;

	cout << "Spatiu de memorie: \n";
	cin >> laptop.memorie;

	cout << "Pret laptop: \n";
	cin >> laptop.pret;

	return laptop;
}

void dezalocataLaptop(Laptop* laptop, int n)
{
	cout << endl;
	for(int i = 0; i < n; i++)
	{
		delete [] laptop->model;
	}
	cout << "Dezalocare laptop" << endl;
}

void afisareLaptop(Laptop laptop)
{
	cout << "Model laptop: " << laptop.model <<
		"\nMemorie RAM laptop: " << laptop.RAM <<
		"\nMemorie laptop: " << laptop.memorie <<
		"\nPret laptop: " << laptop.pret;
}

Laptop** citesteMatriceLaptopuri(int* nrLinii, int** nrColoane)
{
	cout << "Cate linii are matricea? ";
	scanf_s("%d", nrLinii);
	*nrColoane = (int*) malloc(sizeof(int) * (*nrLinii));
	Laptop** matrice;
	matrice = (Laptop**)malloc (sizeof(Laptop*)*(*nrLinii));
	for(int i = 0; i < *nrLinii; i++)
	{
		cout << "Cate elemente avem pe linia: " << i << " ?";
		scanf_s("%d", &((*nrColoane) [i]));
		matrice [i] = (Laptop*) malloc(sizeof(Laptop) * (*nrColoane) [i]);
		for(int j = 0; j < (*nrColoane) [i]; j++)
		{
			matrice [i][j] = citesteLaptop();
		}
	}
	return matrice;
}

void afisareVectoriLaptopuri(Laptop* vector, int nrElemente)
{
	for(int i = 0; i < nrElemente; i++)
	{
		afisareLaptop(vector [i]);
	}
}

void afisareMatriceLaptopuri(Laptop** matrice, int nrLinii, int* nrColoane)
{
	for(int i = 0; i < nrLinii; i++)
	{
		afisareVectoriLaptopuri(matrice [i], nrColoane [i]);
		cout << endl;
	}
}


int main()
{
	Laptop laptop;
	laptop = citesteLaptop();
	afisareLaptop(laptop);

	dezalocataLaptop(&laptop, 1);

	Laptop** laptopuri;
	int nrLinii = 0;
	int* nrColoane;

	laptopuri = citesteMatriceLaptopuri(&nrLinii, &nrColoane);
	afisareMatriceLaptopuri(laptopuri, nrLinii, nrColoane);

	
}

