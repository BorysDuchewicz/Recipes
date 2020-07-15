#pragma once
#include "enums.h"

// klasa to przechowywania inforamcji o pojedynczym skladniku i wykonujaca 2 operacje 
class Component
{
private:
	std::string name;
	int calories;
	double weight;
	double price;
	
public:
	Component() = default;
	Component(const std::string& name, const int& calories, const double& weight, const double& price);


	double kcal()const;//oblicza kalorie na podstawie wagi ktora musimy dodac do przepisu i ilosci kalori na 100g
	double final_price()const;//oblicza cene przy podanej ilosci skaldnika i ceny za kilogram


	//getery pozwalajace na odwolywanie sie do poszczegolnych elementow tej klasy
	std::string get_name()const;
	int get_calories()const;
	double get_weight()const;
	double get_price()const;
	friend std::ostream& operator<<(std::ostream& out, const Component& comp);
	friend json comp_to_json(const Component& comp);//zwraca w formacie json

	~Component() = default;
};



