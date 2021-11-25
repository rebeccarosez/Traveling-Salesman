#pragma once

#include <vector>
#include <map>
#include <bitset>

#include "TravelingSalesmanData.h"
#include "MSTUtil.h"

using namespace std;

class TravelingSalesmanMST
{
public:
	TravelingSalesmanMST(const vector<CityData>& cityData);

	void ComputeShortestPath();

private:
	void ComputeMST();
	void CalculateBestRoute();
	double ComputeDistanceBetweenCities(int a, int b);

	const vector<CityData> m_cityData;
	vector<vector<double>> m_distances; //m_distances[a][b] is the distance between city a and city b
	vector<int> m_bestRoute; //indexes of best route to take
	NodeData m_minSpanTree;
};