#include<iostream>

using namespace std;

int distribution(int liczba, int*tab, int &n);
int assembling(int *tab, int &n);


int liczba = 0;


int main()
{
	int* tab = new int[9]; ////liczba z zakresu [0..10 000 000]
	int n = 0, suma = 0;
	do {
		cout << "Podaj liczbe z zakresu [0..10 000 000]" << endl;
		cin >> liczba;
	} while (liczba >10000000 || liczba < 0);

	cout << "\nReprezentacja dziesietna liczby: ";
	distribution(liczba, tab, n); // funkcja tworzy tablice której elementami s¹ kolejne cyfry reprezentacji dziesiêtniej podanej liczby

	for (int i = n - 1; i >= 0; i--)
	{
		cout << tab[i] << " ";
		suma += tab[i];
	}
	cout << "\nsuma cyfr liczby: " << suma;
	cout << "\nIlosc cyfr liczby: " << n << endl;

	assembling(tab, n);
	cout << "\nWynik (liczba * 17): " << liczba << "\n";

	suma = 0;

	cout << "\nReprezentacja dziesietna wyniku: ";
	for (int j = n - 1; j >= 0; j--)
	{
		cout << tab[j] << " ";
		suma += tab[j];
	}

	cout << "\nsuma cyfr wyniku: " << suma;
	cout << "\nIlosc cyfr wyniku: " << n << "\n\n";


	delete[]tab;
	system("pause");
	return 0;
}

int distribution(int liczba, int*tab, int &n) //funkcja na podstawie liczby zwraca tablice zlozona z cyfr tej liczby
{
	int i = 0, cyfra;

	do {
		cyfra = liczba % 10;
		tab[i] = cyfra;
		liczba /= 10;
		i++;
	} while (liczba != 0);
	n = i;

	return *tab, n;

}

int assembling(int *tab, int &n)  // funkcja pobiera tablice z distribution zamienia ja w liczbe i zwraca do funkcji distribution na rozklad
{
	int suma = 0, vol = 0;

	for (n; n < 0; n--) //z³o¿enie tablicy w liczbê
	{
		liczba += tab[n] * 10 ^ (n - 1);
	}

	liczba *= 17;
	distribution(liczba, tab, n);// wykorzystanie funkcji distribution do reprezentacji dzisiêtnej wyniku

	return liczba;
}