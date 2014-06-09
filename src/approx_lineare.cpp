/*
 * approx_lineare.cpp

 *
 *  Created on: Jun 9, 2014
 *      Author: francesco
 */

#include <vector>
using std::vector;

class funzione_punti_lineare {
	std::vector<long double> vectx;
	std::vector<long double> vecty;

	//x dev'essere ordinato?
	funzione_punti_lineare(std::vector<long double> vx, std::vector<long double> vy) {
		vectx = vx;
		vecty = vy;
	}

	long double operator()(double x) {
		long long i = 0;
		while(vectx.at(i) <= x)
			i++;

		long double x0 = vectx.at(i);
		long double y0 = vecty.at(i);

		long double x1 = vectx.at(i+1);
		long double y1 = vecty.at(i+1);

		//Coeff. angolare, DeltaY/DeltaX
		long double m = (y1 - y0) / (x1 - x0);
		long double y = m*(x-x0)+y0;

		return y;
	}
};



