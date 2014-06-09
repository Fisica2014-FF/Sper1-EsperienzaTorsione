#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
 int n,m = 0;
 double temp;
 vector<double> data;
 vector<double> dist;
 while(cin >> temp)		//Riempie il vector DATA con i dati e li conta (n)
 {
	data.push_back(temp);
	n++;
 }

cout << "ENNE: " << n << endl;		//TOGLIERE

 //sort(data.begin() , data.begin() + n);
 
for ( int i = 0 ; i < n ; i ++ ) cout << "Dato: " << data.at(i) << endl; //TOGLIERE
 
 /*for ( int i = 0 ; i < n ; i++ )		//Algoritmo per ordinare il vector contenente i dati
 {
	for ( int j = 0 ; j < n ; j++ )
	{
	 if ( data.at(i) < data.at(j) && j < i )
	 {
		 temp = data.at(j);
		 data.at(j) = data.at(i);
		 data.at(i) = temp;
	 }
	}
 }





 for (int i = 0 ; i < n - 1 ; i++)		//Trova i periodi
 {
	temp= ( data.at(i + 1) - data.at(i) ) * 2;	//Fattore 2 legato al fatto che serve un periodo, cio� il doppio della d
	dist.push_back(temp);	
	m++;
 }
 

 double sommasigma, somma, media, sigma = 0;
 for( int i = 0 ; i < m ; i++ )			//Calcolo media
 {
	somma += dist.at(i);
 }

 media = somma / m;

 for( int i = 0 ; i < m - 1; i++ )			//Calcolo sigma
 {
	sommasigma += ( dist.at(i) - media ) * ( dist.at(i) - media );
 }
 sigma = sqrt ( sommasigma / ( m - 1 ) );


 cout << media << "\t" << sigma << endl;		//Output */
 return 0;
}