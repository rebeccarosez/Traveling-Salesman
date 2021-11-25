#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "TravelingSalesmanDP.h"
#include "TravelingSalesmanMST.h"

using namespace std;

//read data from TravelingSalesman file, pass it to the correct Traveling salesman class
void ComputeShortesPathFromFile(const char* filePath)
{
	vector<CityData> cityData;

	ifstream file(filePath);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			//format is CITY NAME, DEGREES LAT. N, MINUTES LAT. N, DEGREES LONG. W, MINUTES LONG. W
			stringstream ss(line.c_str());
			string substr;
			string name;
			//City Name
			getline(ss, substr, ',');
			name = substr;
			//Degrees lat
			getline(ss, substr, ',');
			int degLat = atoi(substr.c_str());
			//Minutes lat
			getline(ss, substr, ',');
			int minLat = atoi(substr.c_str());
			//Degrees long
			getline(ss, substr, ',');
			int degLong = atoi(substr.c_str());
			//Minutes long
			getline(ss, substr, ',');
			int minLong = atoi(substr.c_str());

			double lat = degLat + minLat / 60.0;
			double lon = degLong + minLong / 60.0;

			CityData cd(name.c_str(), lat, lon);

			if (name != "")
			{
				cityData.push_back(cd);
			}
		}
		file.close();
	}

	if (cityData.size() < 3)
	{
		cout << "Error: Input file lists only " << cityData.size() << " citites.\n";
		return;
	}
	if (cityData.size() < MAX_NUM_DP_CITIES)
	{
		TravelingSalesmanDP salesman(cityData);
		salesman.ComputeShortestPath();
	}
	else
	{
		TravelingSalesmanMST salesman(cityData);
		salesman.ComputeShortestPath();
	}
}
	

int main(int argc, char** argv) 
{
	if (argc != 2)
	{
		cout << "\nMust enter file path\n";
		return 1;
	}

	const char* filePath = argv[1];
	ifstream fs(filePath);
	cout << argv[0];
	if (!fs.good())
	{
		cout << "\nFilepath " << filePath << " does not exist!\n";
		return 1;
	}

	ComputeShortesPathFromFile(filePath);

	return 0;
}
