#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <map>
#include "Logger.h"
#include "ArrayList.h"
//cckove arraye sa spravaju ako pointre

//std::tuple<int, int, int, int> navratova()
//{
//	return { 0,1,2,3 };
//}
template <typename T> // pri template sa dlhsie kompiluju, ale je to rychlejsie celkom pri pouzivani
T max(T a, T b)
{
	return a > b ? a : b;
}

int main(int argc, char* argv[])
{
	////int poleC[10] == std::array<int,10> poleCpp;   poleCpp.size()
	//std::vector<double> decimalNumber;
	//for (double &hodnota : decimalNumber) // neda sa prechadzat for eachom a vymazat
	//{
	//	printf("%f", hodnota);
	//}
	//for (auto itr = decimalNumber.begin(); itr != decimalNumber.end(); ) // tu uz mozes vymazat
	//{
	//	double& hodnota = (*itr); //tymto dostaneme hodnotu iteratora
	//	if (hodnota != 0.)
	//	{
	//		itr = decimalNumber.erase(itr); // mazanie znevaliduje iterator  vymazes posledny napr a potom chces pristupovat k dalsiemu  ak sa itr = .end
	//	}
	//	else  ++itr;
	//}
	////syntax na mazanie podla hodnoty
	//decimalNumber.erase(std::remove(decimalNumber.begin(), decimalNumber.end(), 0), decimalNumber.end()); // prenasa vsetky prvky rovnake na koniec vectoru a potom to odsekne ten koniec, remove vrati iterator na prvu hodnotu, ktora je rovnaka
	//std::list<std::string> names;
	//names.sort();// ma v sebe naimplenovane zoradovanie
	////names.rbegin(); od konca
	//std::map<int, std::string> obce;
	//std::pair<int, std::string> riadok; // iterator prechadza jednotlive pairy ako keby    umoznuje vracat aj viac hodnot cez reuturn ako v pythone
	//std::tuple<int, int, int, int> navratova; // nekonecne vela ich mozeme vratit 
	//int prvy = std::get<0>(navratova);
	//for (auto itr = obce.begin(); itr != obce.end(); ++itr) // vracia to pair ako keby
	//{
	//	auto obsah = (*itr).second;
	//}
	////float a = 5.2, b = 10.83;
	////printf("%f", max(a, b));
	//Auto car;

	//auto itr = obce.find(5);
	//if (itr != obce.end())
	//{
	//	//najdeny
	//}
	//else //nenajdeny
	ArrayList<bool> majuPravdu;
	majuPravdu.add(true);
	majuPravdu.add(false);
	majuPravdu.add(true);
	bool* data = majuPravdu.getData();
	for (size_t i = 0; i < majuPravdu.getSize(); ++i)
	{
		printf("%s", data[i] == true ? "true" : "false");
	}

	return 0;
}