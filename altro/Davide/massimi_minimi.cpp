#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{ 
	int n = 0;
	vector <double> valori;
	double temp;						//Variabile temporanea contenente i valori
	double temp_neg;					//Variabile temporanea ausiliaria 1
	double temp_pos;					//Variabile temporanea ausiliaria 2
	while(cin >> temp)					//Mette i dati nel vector
	{
		valori.push_back(temp);
		n++;
	}
	int j = 0;
	vector <double> massimi;		//Crea vector in cui mettere i massimi
	vector <double> max_neg;		//Crea vector in cui mettere elemento precedente al massimo
	vector <double> max_pos;		//Crea vector in cui mettere elemento successivo al massimo
	vector <int> max_dist;			//Crea vector in cui scrivere posizione massimi
	vector <int> max_dist_neg;
	vector <int> max_dist_pos;
	double temp_dist;				//Crea variabile temporanea per la distanza dei valori
	double temp_dist_neg;
	double temp_dist_pos;

	for (int i = 1 ; i < ( n - 1 ) ; i++)
	{
		if (valori.at(i) > valori.at(i-1) && valori.at(i) >= valori.at(i+1) )	//Trova i massimi
		{
			temp = valori.at(i);
			temp_neg = valori.at(i-1);
			temp_pos = valori.at(i+1);
			temp_dist = (i + 1);
			temp_dist_neg = i ;
			temp_dist_pos = i + 2;
			massimi.push_back(temp);
			max_neg.push_back(temp_neg);
			max_pos.push_back(temp_pos);
			max_dist.push_back(temp_dist);
			max_dist_neg.push_back(temp_dist_neg);
			max_dist_pos.push_back(temp_dist_pos);

			j++;

		}
	}
	vector <double> minimi;
	vector <double> min_neg;
	vector <double> min_pos;
	vector <int> min_dist;
	vector <int> min_dist_neg;
	vector <int> min_dist_pos;
	j = 0;
	for (int i = 1 ; i < ( n - 1 ) ; i++)
	{
		if (valori.at(i) < valori.at(i-1) && valori.at(i) <= valori.at(i+1) )
		{
			temp = valori.at(i);
			temp_neg = valori.at(i-1);
			temp_pos = valori.at(i+1);
			temp_dist = i + 1;
			temp_dist_neg = i ;
			temp_dist_pos = i + 2;
			minimi.push_back(temp);
			min_neg.push_back(temp_neg);
			min_pos.push_back(temp_pos);
			min_dist.push_back(temp_dist);
			min_dist_neg.push_back(temp_dist_neg);
			min_dist_pos.push_back(temp_dist_pos);

			j++;
		}
	}



	double delta, da, db, dc, a, b, c, vortex, vortey;		//Parametri della parabola
	vector <double> xverticiMAX;					//Vector contenente i risultati del programma
	vector <double> yverticiMAX;

	double max_size = massimi.size();
	double min_size = minimi.size();

	for (int i = 0 ; i < max_size ; i++)
	{
		delta = (	( max_dist.at(i)     * max_dist_pos.at(i) * max_dist_pos.at(i) ) +
					( max_dist_neg.at(i) * max_dist.at(i)     * max_dist.at(i) )     +
					( max_dist_neg.at(i) * max_dist_neg.at(i) * max_dist_pos.at(i) ) -
					( max_dist_neg.at(i) * max_dist_neg.at(i) * max_dist.at(i) )     -
					( max_dist.at(i)     * max_dist.at(i)     * max_dist_pos.at(i) ) -
					( max_dist_neg.at(i) * max_dist_pos.at(i) * max_dist_pos.at(i) )	);


	da = (	( max_neg.at(i) * max_dist.at(i)     * max_dist_pos.at(i) * max_dist_pos.at(i) ) +
			( max_pos.at(i) * max_dist_neg.at(i) * max_dist.at(i)     * max_dist.at(i) )     +
			( massimi.at(i) * max_dist_neg.at(i) * max_dist_neg.at(i) * max_dist_pos.at(i) ) -
			( max_pos.at(i) * max_dist_neg.at(i) * max_dist_neg.at(i) * max_dist.at(i) )     -
			( max_neg.at(i) * max_dist.at(i)     * max_dist.at(i)     * max_dist_pos.at(i) ) - 
			( massimi.at(i) * max_dist_neg.at(i) * max_dist_pos.at(i) * max_dist_pos.at(i) ) );


	db = (	( massimi.at(i) * max_dist_pos.at(i) * max_dist_pos.at(i) ) +
			( max_neg.at(i) * max_dist.at(i)     * max_dist.at(i) )     +
			( max_pos.at(i) * max_dist_neg.at(i) * max_dist_neg.at(i) ) -
			( massimi.at(i) * max_dist_neg.at(i) * max_dist_neg.at(i) ) -
			( max_pos.at(i) * max_dist.at(i)     * max_dist.at(i) )     -
			( max_neg.at(i) * max_dist_pos.at(i) * max_dist_pos.at(i) ) 	);


	dc = (	( max_pos.at(i) * max_dist.at(i) )     +
			( massimi.at(i) * max_dist_neg.at(i) ) +
			( max_neg.at(i) * max_dist_pos.at(i) ) -
			( max_neg.at(i) * max_dist.at(i) )     -
			( massimi.at(i) * max_dist_pos.at(i) ) -
			( max_pos.at(i) * max_dist_neg.at(i) )	  );

		a = da / delta;
		b = db / delta;
		c = dc / delta;
		vortex = - b / ( 2 * c );
		vortey = - ( b * b - 4 * a * c ) / ( 4 * c );
		xverticiMAX.push_back(vortex * 0.05); //Presente valore di conversione delle x
		yverticiMAX.push_back(vortey); 
	}


	vector <double> xverticiMIN;
	vector <double> yverticiMIN;

	for (int i = 0 ; i < min_size ; i++)
	{
		delta = (	( min_dist.at(i)     * min_dist_pos.at(i) * min_dist_pos.at(i) ) +
					( min_dist_neg.at(i) * min_dist.at(i)     * min_dist.at(i) )    +
					( min_dist_neg.at(i) * min_dist_neg.at(i) * min_dist_pos.at(i) ) -
					( min_dist_neg.at(i) * min_dist_neg.at(i) * min_dist.at(i) )    -
					( min_dist.at(i)     * min_dist.at(i)     * min_dist_pos.at(i) ) -
					( min_dist_neg.at(i) * min_dist_pos.at(i) * min_dist_pos.at(i) )	);


	da = (	( min_neg.at(i) * min_dist.at(i)     * min_dist_pos.at(i) * min_dist_pos.at(i) ) +
			( min_pos.at(i) * min_dist_neg.at(i) * min_dist.at(i)     * min_dist.at(i) )     +
			( minimi.at(i)  * min_dist_neg.at(i) * min_dist_neg.at(i) * min_dist_pos.at(i) ) -
			( min_pos.at(i) * min_dist_neg.at(i) * min_dist_neg.at(i) * min_dist.at(i) )     -
			( min_neg.at(i) * min_dist.at(i)     * min_dist.at(i)     * min_dist_pos.at(i) ) - 
			( minimi.at(i)  * min_dist_neg.at(i) * min_dist_pos.at(i) * min_dist_pos.at(i) ) );


	db = (	( minimi.at(i)   * min_dist_pos.at(i) * min_dist_pos.at(i) ) +
			( min_neg.at(i)  * min_dist.at(i)     * min_dist.at(i) )     +
			( min_pos.at(i)  * min_dist_neg.at(i) * min_dist_neg.at(i) ) -
			( minimi.at(i)   * min_dist_neg.at(i) * min_dist_neg.at(i) ) -
			( min_pos.at(i)  * min_dist.at(i)     * min_dist.at(i) )     -
			( min_neg.at(i)  * min_dist_pos.at(i) * min_dist_pos.at(i) ) 	);


	dc = (	( min_pos.at(i) * min_dist.at(i) )     +
			( minimi.at(i)   * min_dist_neg.at(i) ) +
			( min_neg.at(i)  * min_dist_pos.at(i) ) -
			( min_neg.at(i)  * min_dist.at(i) )     -
			( minimi.at(i)   * min_dist_pos.at(i) ) -
			( min_pos.at(i) * min_dist_neg.at(i) )	  );


		a = da / delta;
		b = db / delta;
		c = dc / delta;		
		vortex = - b / ( 2 * c );
		vortey = - ( b * b - 4 * a * c ) / ( 4 * c );
		xverticiMIN.push_back(vortex * 0.05);
		yverticiMIN.push_back(vortey);
	}


	vector<int> eliminamassimi; //vector contenente la posizione dei valori da eliminare
	vector<int> eliminaminimi;
	int temperasemax;
	int temperasemin;

	

	for (int i = 0 ; i < max_size - 1 ; i++) //Permette di trovare eventuali massimi fasulli
	{
		if (abs (xverticiMAX.at(i) - xverticiMAX.at(i+1)) < 0.8 ) //Intervallo considerato errore
		{
			if (abs( yverticiMAX.at(i) ) - abs( yverticiMAX.at(i+1) ) >= 0)
			{
				temperasemax = i+1;
				eliminamassimi.push_back(temperasemax);
			} else if (abs ( yverticiMAX.at(i) ) - abs ( yverticiMAX.at(i+1) ) < 0 && temperasemax != i)
			 {
				temperasemax = i;
				eliminamassimi.push_back(temperasemax);
			 }
		}
	}


	for (int i = 0 ; i < min_size - 1; i++) //Permette di trovare eventuali minimi fasulli
	{
		if (abs (xverticiMIN.at(i) - xverticiMIN.at(i+1)) < 0.8 )
		{
			if (abs ( yverticiMIN.at(i) ) - abs ( yverticiMIN.at(i+1) ) <= 0)
			{
				temperasemin = i+1;
				eliminaminimi.push_back(temperasemin);
			} else if (abs ( yverticiMIN.at(i) ) - abs ( yverticiMIN.at(i+1) ) > 0 && temperasemin != i )
			 {
				temperasemin = i;
				eliminaminimi.push_back(temperasemin);
			 }
		}
	} 


	int puliziamax = eliminamassimi.size();
	int puliziamin = eliminaminimi.size();
	int n = 0; //Variabile necessaria per regolare la modifica posizione vettori

	for (int i = 0 ; i < puliziamax ; i++) //Pulisce il vector definitivo di massimi
	{
		xverticiMAX.erase( xverticiMAX.begin() + eliminamassimi.at(i - n) );
		yverticiMAX.erase( yverticiMAX.begin() + eliminamassimi.at(i - n) );
		n++;
	}

	n = 0;

	for (int i = 0 ; i < puliziamin ; i++) //Pulisce il vector definitivo di minimi
	{
		xverticiMIN.erase( xverticiMIN.begin() + eliminaminimi.at(i - n) );
		yverticiMIN.erase( yverticiMIN.begin() + eliminaminimi.at(i - n) );
		n++;
	}

	double max_v_size  = xverticiMAX.size();
	double min_v_size = xverticiMIN.size();


		//cout << "Le x dei massimi valgono: " << endl;
	for (int i = 0 ; i < max_v_size ; i++)
	{
		cout << xverticiMAX.at(i) << "\t" << yverticiMAX.at(i) << endl;
	}


	//cout << "Le x dei minimi valgono: " << endl;
	for (int i = 0 ; i < min_v_size ; i++)
	{
		cout << xverticiMIN.at(i) << "\t" << yverticiMIN.at(i) << endl;
	}


/*

	 int q = 0;									//Algoritmo per la visualizzazione dei risultati
	cout << "Massimi: " << endl;
	for (double massimi)
	{
		cout << massimi.at(q) << endl;
		q++;
	}
	q = 0;
	cout << "A una posizione di: " << endl;
	while (max_dist.at(q) != 0)
	{
		cout << max_dist.at(q) << endl;
		q++;
	}


	q = 0;
	cout << "Minimi: " << endl;
	while (minimi.at(q) != 0)
	{
		cout << minimi.at(q) << endl;
		q++;
	}
	q = 0;
	cout << "A una posizione di: " << endl;
	while (min_dist.at(q) != 0)
	{
		cout << min_dist.at(q) << endl;
		q++;
	}
*/
	return 0;

}
