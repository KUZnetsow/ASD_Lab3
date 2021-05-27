#pragma once
#include <string>

using namespace std;

class WFIAlgorithm
{
private:
	string cities[100];
	int INF = 10000000;
	int count = 0;
	int adjMatrix[100][100];
	bool inited = false;
	int getCityIndex(string city);
	void addPrice(string first, string second, int price);
	void init();
public:
	WFIAlgorithm(string path);
	int getMinimumPrice(string first, string second);
};

