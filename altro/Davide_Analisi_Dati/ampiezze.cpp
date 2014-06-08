#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int n = 0;
	int p = 0;
	double valore;
	vector <double> valori;
	vector <double> pos;
	vector <double> neg;
	while (cin >> valore)			//Mette i valori nel vector
	{
		valori.push_back(valore);
		n++;
	}
	for (int i = 0 ; i < n ; i++)		//Riconosce valori positivi o negativi
	{
		valore = valori.at(i);
		if (valore < 0)	
		{
			neg.push_back(valore);
		} else if (valore >= 0)
		  {
			pos.push_back(valore);
			p++;
		  }
	}

	double mediap, sigmap, median, sigman, media, sigma;
	double sommatoria = 0;
	for (int i = 0 ; i < p ; i++)			//Media e sigma per i positivi
	{
		sommatoria +=  pos.at(i);
	}
	mediap = sommatoria / p;
	double sommasigma = 0;
	for (int i = 0 ; i < p ; i++)
	{
		sommasigma += ( pos.at(i) - mediap ) * (pos.at(i) - mediap);
	}
	sigmap = sqrt( sommasigma / ( p -1 ) );


	sommatoria = sommasigma = 0;
	for (int i = 0 ; i < n - p ; i++)		//Media e sigma per i negativi
	{
		sommatoria +=  neg.at(i);
	}
	median = sommatoria / (n - p);
	for (int i = 0 ; i < n -p ; i++)
	{
		sommasigma += ( neg.at(i) - median ) * (neg.at(i) - median);
	}
	sigman = sqrt( sommasigma / ( n - p - 1 ) );

	media = ( mediap - median ) / 2;		//Valori definitivi
	sigma = ( sigmap + sigman ) / 2;

	
	cout << media << "\t" << sigma << endl;
	return 0;
} 
