#pragma once
#include <iostream>
template <class T> // class zredukuje ze nemozeme pouzit na nic ine co nebude triedou
class Logger
{
public:
	Logger() { std::cout << "Vytvoril sa typ:"<< typeid(T).name() << std::endl; } // typeid dava info o triede
	virtual ~Logger() { std::cout << "Vymazal sa typ:" << typeid(T).name() << std::endl; }
};
class Auto :  public Logger<Auto>
{
	using Logger::Logger; // znamena ze nech to vygeneruje vsetky konstruktory co ma aj logger
};
