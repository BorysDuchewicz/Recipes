#pragma once
#include "user.h"
#include "recipes.h"
#include "user_data_service.h"

class UserService
{
private:
	std::unique_ptr<Recipes> recipes;
	User get_user();//metoda pozwalajaca u�ytkownikowi poda� dane potrzebne do policzenia bmi i zapotrzebowania kalorycznego
	void save_most_optimal() const;//metoda ktora wywoluje metody s�u��ce do zapisu najlepszej opcji (najmniejsza cena/kcl)
	void recommend_recipes(const User& u)const;
public:
	UserService(const Recipes& recipes);
	
	void main();//metoda w kt�rej wykonaj� si� wszystkie inne metody
	~UserService() = default;
};

