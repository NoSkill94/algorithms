#include <iostream>
using namespace std;

unsigned int NWD(int n, int a)
{
	int u0 = 1, u1 = 0, v0 = 0, v1 = 1, q, tmp, mod = n;

	while (a != 0)
	{
		q = n / a;
		tmp = n % a;

		n = a;
		a = tmp;

		tmp = u0 - (q * u1);
		u0 = u1;
		u1 = tmp;

		tmp = v0 - (q * v1);
		v0 = v1;
		v1 = tmp;
	}

	if (n == 1)
	{
		while (v0 > mod) v0 = mod - v0;

		while (v0 < 0) v0 = mod + v0;

		return v0;
	}
	else return 0;
}

unsigned int odwrotnosc(int n, int a)
{
	unsigned int wynik;

	if ((wynik = NWD(n, a)) != 0) return wynik;
	else return 0;
}

int main()
{
	int n, a, tmp = 0;

	cout << "Sprawdz czy istnieje odwrotnosc!" << endl;

	cout << "Prosze podac modulo n: ";
	cin >> n;
	cout << endl;

	while (!tmp)
	{
		cout << "Prosze podac liczbe a: ";
		cin >> a;
		cout << endl;

		tmp = odwrotnosc(n, a);

		if (a > 0) cout << "Liczba odwrotna do " << a << " w modulo " << n << " to: " << tmp << endl;
		else cout << "Blad: nie ma liczby odwrotnej do " << a << " w modulo " << n << endl;
	}

	return 0;
}
