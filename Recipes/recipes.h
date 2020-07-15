#pragma once
#include "recipe_loader.h"

//klasa obslugujaca przepisy
class Recipes
{
private:
	std::vector<std::unique_ptr<Recipe>> recipes;
	Recipe best_price_to_kcal();//wyznacza najlepszy stosunek ceny do kalori
	std::vector<Recipe> find_all_breakfasts();
	std::vector<Recipe> find_all_dinners();
	std::vector<Recipe> find_all_suppers();
public:
	Recipes() = default;	
	Recipes(const std::string& file_name);

	//opearotory przenoszace aby nie bylo problemow z przenoszeniem i kopiowaniem unique_ptr
	Recipes(const Recipes& recipes);
	Recipes(Recipes&& recipes) noexcept;
	Recipes operator=(const Recipes& recipes);
	Recipes& operator=(Recipes&& recipes) noexcept;
	
	void write_best_price_to_kcl_txt();//zapisuje do pliku txt
	void write_best_price_to_kcl_json();//zapisuje do pliku json
	
	std::optional<std::vector<std::unique_ptr<Recipe>>> diet(const double& kcl);//wyznacza dania ktore najlepiej jest nam zjesc aby byc jak najblizej zapotrzebowania kalorycznego
	friend std::ostream& operator<< (std::ostream& out, const Recipes& recipes);
	~Recipes() = default;
};

