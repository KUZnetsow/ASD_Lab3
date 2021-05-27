#include <iostream>
#include "WFIAlgorithm.h"

using namespace std;

int main() {
	WFIAlgorithm* prices = new WFIAlgorithm("./prices.txt");
	cout << prices->getMinimumPrice("London", "Paris") << endl;
	cout << prices->getMinimumPrice("Paris", "Moscow") << endl;
	cout << prices->getMinimumPrice("Moscow", "Pekin") << endl;
	return 0;
}