#include <iostream>
using namespace std;

int calculaCerrajero(int v[], int n){
	int i = 0, d = n - 1, sumi = v[i], sumd = v[d];
	while (i <= n && sumd != sumi){
		if (sumi < sumd){
			i++;
			sumi += v[i];
		}
		else if (sumd < sumi){
			d--;
			sumd += v[d];
		}
	}
	return i;
}

bool resuelve() {
	int n;
	int v[1000000];
	cin >> n;
	if (n == 0)
		return false;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	cout << calculaCerrajero(v, n) << endl;

	return true;
}

int main() {

	while (resuelve()){ ; }
	return 0;
}