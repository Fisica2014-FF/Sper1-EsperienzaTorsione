#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double o0, so0, os, sos, gamma, sgamma;
	cerr << "Inserire in ordine omegas, suo errore, gamma, suo errore. " << endl;
	cin >> os >> sos >> gamma >> sgamma;
	o0 = sqrt( ( os * os ) + ( gamma * gamma ) );
	so0 = sqrt( 1 / ( (gamma * gamma ) + ( os * os ) ) * ( ( sgamma *  gamma * gamma ) + ( sos * os * os ) ) );
	cout << o0 << "\t" << so0 << endl;
	return 0;
}
