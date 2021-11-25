#include <math.h>
#include <cmath> 

#include "MathUtil.h"

//
//Compute distance between 2 city data points using the Haversine formula
//
double MathUtil::ComputeDistance(double lat1Deg, double lat2Deg, double long1Deg, double long2Deg)
{
	double lat1Rad = Deg2Rad(lat1Deg);
	double long1Rad = Deg2Rad(long1Deg);
	double lat2Rad = Deg2Rad(lat2Deg);
	double long2Rad = Deg2Rad(long2Deg);
	double u = sin((lat2Rad - lat1Rad) / 2);
	double v = sin((long2Rad - long1Rad) / 2);
	return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1Rad) * cos(lat2Rad) * v * v));
}