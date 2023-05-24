#include <iostream>
#include <vector>
using namespace std;

void Mochila(int M, vector<vector<int>>v1, vector<float>v2) {
	for (int i = 0; i < v2.size(); i++)
	{
		v2[i] = 0;
	}
	int pesoact = 0;
	while (pesoact<M)
	{
		float aux = 0;
		int	aux1 = 0;
		for (int i = 0; i < v1.size(); i++)
		{
			if ((v1[i][1]/v1[i][0])>aux)
			{
				aux = (v1[i][1] / v1[i][0]);
				aux1 = i;
			}
		}
		if (pesoact+ v1[aux1][0] <=M)
		{
			v2[aux1] = 1;
			pesoact = pesoact + v1[aux1][0];
			v1[aux1][1] = 0;
		}
		else
		{
			v2[aux1] = ((M-pesoact)*10)/ v1[aux1][0];
			v2[aux1] = v2[aux1] * 0.1;
			pesoact = M;
		}
	}
	for (int i = 0; i < v2.size(); i++)
	{
		cout <<"[" << v2[i] << "] ";
	}
}

int main()
{
	vector<vector<int>>v1 = { {10,10},{3,1},{3,7},{4,1} };
	vector<float>v2 = {0,0,0,0};
	Mochila(10, v1, v2);
	
}
