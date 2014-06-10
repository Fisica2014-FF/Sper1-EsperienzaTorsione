#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	double temp1, temp2;
	vector <double> datax;
	vector <double> datay;

	while(cin >> temp1)
	{
		cin >> temp2;
		datax.push_back(temp1);
		datay.push_back(temp2);
	}	

	int n =datax.size();

	for(int i = 0 ; i < n ; i++)
	{
		datay.at(i) = log( abs( datay.at(i) * 2 * M_PI ) );
		cout << datax.at(i) << "\t" << datay.at(i) << endl;
	}	
	return 0;
}
