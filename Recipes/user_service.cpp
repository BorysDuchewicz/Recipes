#include "user_service.h"
#include "user_validator.h"

User UserService::get_user()
{
	while (true)
	{
		std::string name = UserDataService::get_string("Podaj imie: ");
		int age = UserDataService::get_int("Podaj wiek: ");
		Sex sex = UserDataService::get_sex("Podaj plec (wpisz Man or Women): ");
		double weight = UserDataService::get_double("Podaj wage: ");
		double height = UserDataService::get_double("Podaj wzrost: ");
		User u = User{ name,age,sex,weight,height };
		UserValidator val;
		if (val.validator(u).empty())
		{
			return u;
		}
		std::cout << val;	
	}
}

void UserService::save_most_optimal() const
{
	recipes->write_best_price_to_kcl_txt();//zapis w pliku txt
	recipes->write_best_price_to_kcl_json();//zapis w pliku json
}

void UserService::recommend_recipes(const User& u) const
{
	std::cout << "Masz zdrowa wage aby ja podtrzymac polecamy: " << std::endl;
	auto j = recipes->diet(u.kcl_demand());
	double kcl = 0;
	if (j != std::nullopt)
	{
		for (const auto& i : *j)
		{
			std::cout << *i << std::endl;
			kcl += i->kcal();
		}
		std::cout << "Kalorie przyswojone w ciagu dnia: " << kcl << std::endl;
	}
	else
	{
		std::cout << "Za malo przepisow aby zrobic jadlospis" << std::endl;
	}
}

UserService::UserService(const Recipes& recipes)
{
	this->recipes = std::make_unique<Recipes>(recipes);
}

void UserService::main()
{
	recipes->write_best_price_to_kcl_txt();
	recipes->write_best_price_to_kcl_json();
	
	User u = this->get_user();
	
	std::cout <<"Twoje bmi: "<< u.bmi() << std::endl;
	std::cout <<"Zapotrzebowanie: "<< u.kcl_demand() << std::endl;
	std::cout <<"Stan: " <<u.is_your_weight_ok() << std::endl;
	if(u.is_your_weight_ok()=="Norma")
	{
		recommend_recipes(u);
	}
	save_most_optimal();
}