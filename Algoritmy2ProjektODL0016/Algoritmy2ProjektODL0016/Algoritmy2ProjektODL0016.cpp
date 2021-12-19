// Algoritmy2ProjektODL0016.cpp
//


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/**
 * pomocná funkce, která vrací větší z dvou hodnot
 * \param a	Integer k porovnání
 * \param b Integer k porovnání
 * \return Větší číslo
 */
int getMax(int a, int b) {
	return a > b ? a : b;
}


/**
 * Pomocná funkce pro načtení čísel ze souboru
 * \param s String cesty k souboru
 * \return Vektor intů načtených ze souboru
 */
vector<int> readFromFile(string s) {

	int x;
	vector<int> v;
	fstream file(s);

	while (file >> x)
	{
		v.push_back(x);
	}

	
	return v;
}


/**
 * Hlavní funkce celého algoritmu
 * \param x Vektor intů, ze kterého vypočítáme největší vepsaný obdelník v histogramu, nevím jak zobrazit v doxy source code spolu s komenty, takže po Returns číst ty komenty radši ve zdrojáku
 * \return Největší vepsaný obdelník z histogramu
 */
int getMaxAreaHistogram(vector<int> x) {

	int top = 0;

	for (int i = 0; i < x.size(); i++)	/*! získáme nejvyšší číslo z vektoru */
	{
		top = getMax(top, x[i]);
	}

	if (top == 0)	/*! když je největší číslo 0, tak žádný obdelník není */
		return 0;

	int area = x.size();	/*! kdyby všechny čísla v histogramu byly 1, tak největší vepsaný obdelník je jeho šířka, v tomto případě velikost vektoru, protože všechny hodnoty mají šířku 1 */
	int temp_area = 0;

	for (int i = 1; i <= top; i++)	/*! inkrementujeme v jaké jsme výšce (top je nejvyšší)*/
	{

		for (int j = 0; j < x.size(); j++)	/** postupně procházíme vektor */
		{

			if (x[j] >= i)	/*! když hodnota na pozici vektoru je větší nebo rovna momentální výšce, pro kterou počítáme plochu, tak je souvislá a přičteme momentální výšku k temporary ploše */
			{
				temp_area += i;
			}
			else	/*! když hodnota na pozici vektoru je menší než momentální výška, tak nám končí momentální souvislost v histogramu, porovnáme, zda doposud souvislá plocha je vetší, než plocha kterou máme momentálně uloženou v area, jestli je, tak ji uložíme do area, temp area vynulujeme */
			{
				area = getMax(area, temp_area);
				temp_area = 0;
			}

		}

		/*! zbylé iterace mohly být souvislé a tak jsme se nedostali do else, proto uložíme do area vetší hodnotu a vynulujeme temporary area */
		area = getMax(area, temp_area);
		temp_area = 0;

	}

	return area;
}

/**
 * Funkce Main, akorát se volají funkce a vypisují se do příkazové řádky
 */
int main()
{

	cout << getMaxAreaHistogram(readFromFile("./TestovaciSada.txt")) << endl;
	cout << getMaxAreaHistogram(readFromFile("./TestovaciSada2.txt")) << endl;

}
