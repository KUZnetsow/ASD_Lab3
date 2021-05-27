#include <iostream>
#include <fstream>
#include <string>
#include "WFIAlgorithm.h"

using namespace std;

int WFIAlgorithm::getCityIndex(string city) {
	for (int i = 0; i < count; i++) {
		if (cities[i] == city) {
			return i;
		}
	}
	return -1;
}

void WFIAlgorithm::init() {
	for (int k = 0; k < count; ++k) {
		for (int i = 0; i < count; ++i) {
			for (int j = 0; j < count; ++j) {
				adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
			}
		}
	}
	inited = true;
}

WFIAlgorithm::WFIAlgorithm(string path) {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			adjMatrix[i][j] = i == j ? 0 : INF;
		}
	}
	ifstream file(path);
	if (file.is_open()) {
		std::string firstCity, secondCity, firstPrice, secondPrice;

		while (getline(file, firstCity, ';'))
		{
			getline(file, secondCity, ';');
			getline(file, firstPrice, ';');
			getline(file, secondPrice, '\n');
			if (firstPrice != "N/A") {
				addPrice(firstCity, secondCity, stoi(firstPrice));
			}
			if (secondPrice != "N/A") {
				addPrice(secondCity, firstCity, stoi(secondPrice));
			}
		}
	}
	file.close();
}

void WFIAlgorithm::addPrice(string first, string second, int price) {
	int firstPos = getCityIndex(first);
	int secondPos = getCityIndex(second);
	if (firstPos == -1) {
		firstPos = count;
		cities[firstPos] = first;
		count += 1;
	}
	if (secondPos == -1) {
		secondPos = count;
		cities[secondPos] = second;
		count += 1;
	}
	adjMatrix[firstPos][secondPos] = price;
}

int WFIAlgorithm::getMinimumPrice(string first, string second) {
	if (!inited) {
		init();
	}
	int firstPos = getCityIndex(first);
	int secondPos = getCityIndex(second);
	if (firstPos == -1 || secondPos == -1 || adjMatrix[firstPos][secondPos] == INF) {
		return -1;
	}
	return adjMatrix[firstPos][secondPos];
}
