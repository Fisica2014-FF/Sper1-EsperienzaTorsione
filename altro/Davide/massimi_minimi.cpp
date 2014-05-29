#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
	int dimensione = 10; 
	int i = 0;
	vector <double> valori(dimensione);
	while(cin >> valori[i])			//Mette i dati nel vector
	{
		i++;
		if (i >= dimensione - 2 )
		{
			dimensione = dimensione * 2;
			valori.resize(dimensione);		//Aumenta la dimensione
		{
	}
	int dim_min = 10;
	int dim_max = 10;
	int j = 0;
	vector <double> massimi(dim_max);		//Crea vector in cui mettere i massimi
	vector <int> max_dist(dim_max);			//Crea vector in cui scrivere posizione massimi
	for (int i = 1 ; i < ( dimensione - 1 ) ; i++)
	{
		if (valori[i] > valori[i-1] && valori[i] > valori[i+1])	//Trova i massimi
		{
			massimi[j] = valori[i];
			max_dist[j] = i + 1;
			j++;
			if (j >= dim_max) 
			{
				dim_max = dim_max * 2;
				massimi.resize(dim_max);
				max_dist.resize(dim_max);
			 }
		}
	}
	vector <double> minimi(dim_min);
	vector <int> min_dist(dim_min);
	j = 0;
	for (int i = 1 ; i < ( dimensione - 1 ) ; i++)
	{
		if (valori[i] < valori[i-1] && valori[i] < valori[i+1])
		{
			minimi[j] = valori[i];
			min_dist[j] = i + 1;
			j++;
			if (j >= dim_min)
			{
				dim_min = dim_min * 2;
				minimi.resize(dim_min);
				min_dist.resize(dim_min);
			}
		}
	}




	i = 0;		//Algoritmo per la visualizzazione dei risultati
	cout << "Massimi: " << endl;
	while (massimi[i] != 0)
	{
		cout << massimi[i] << endl;
		i++;
	}
	i = 0;
	cout << "A una posizione di: " << endl;
	while (max_dist[i] != 0)
	{
		cout << max_dist[i] << endl;
		i++;
	}


	i = 0;
	cout << "Minimi: " << endl;
	while (minimi[i] != 0)
	{
		cout << minimi[i] << endl;
		i++;
	}
	i = 0;
	cout << "A una posizione di: " << endl;
	while (min_dist[i] != 0)
	{
		cout << min_dist[i] << endl;
		i++;
	}

	return 0;
}}
}
