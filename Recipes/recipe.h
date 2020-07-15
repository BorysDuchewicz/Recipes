#pragma once
#include "component.h"

//klasa przepis przechowujaca date utworzenia danego przepisu oraz skladniki ktore sa wymagane z odpowidnia iloscia
class Recipe 
{
private:
	std::string name;
	int day;
	int month;
	int year;
	Category category;
	std::vector<std::unique_ptr<Component>> components;
public:
	Recipe() = default;
	Recipe(const std::string& name, const int& day, const int& month, const int& year,const Category& category,
	       std::vector<Component> components);

	//operatory przenoszenia i kopiowana aby mozna bylo wykonywac te operacje na unique_ptr
	Recipe(const Recipe& recipe);
	Recipe(Recipe&& recipe) noexcept;
	Recipe operator=(const Recipe& recipe);
	Recipe& operator=(Recipe&& recipe) noexcept;

	//pozwala na pobranie poszczególnych danych
	std::string get_name()const;
	int get_day()const;
	int get_month()const;
	int get_year()const;
	Category get_category()const;
	
	double kcal() const;//oblicza calkowita ilosc kalori dania
	double final_price() const;//liczby calkowita cene dania
	~Recipe() = default;
	friend std::ostream& operator<<(std::ostream& out, const Recipe& recipe);
	friend json to_json(const Recipe& recipe);//zwraca w formacie json
};

