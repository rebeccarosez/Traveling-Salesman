#pragma once

#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

class MathUtil
{
public:
	// convert decimal degrees to radians
	static inline double Deg2Rad(double deg)
	{ 
		return (deg * pi / 180.0);
	};

	// convert radians to decimal degrees
	static inline double Rad2Deg(double rad)
	{
		return (rad * 180.0 / pi);
	};

	//compute distance between 2 points given their latitude and longitude
	static double ComputeDistance(double lat1Deg, double lat2Deg, double long1Deg, double long2Deg);
};