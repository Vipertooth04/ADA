#include <iostream>
#include <vector>

using namespace std;


void Conteo_monedas(float P, vector<int> v1) {
	int aux = static_cast<int>(P * 10);
	for (int i = 0; i < v1.size(); i++)
	{
		cout <<static_cast<float>(v1[i])/10 << " ";
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++)
	{
		cout << aux / v1[i]<<" ";
		aux = aux % v1[i];
	}
}

int main() {
	vector<int> M1 = { 50,20,10,5,2,1 };
	float cant = 58.80;
	Conteo_monedas(cant, M1);
}