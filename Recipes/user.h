#pragma once
#include "recipes.h"
class User
{
private:
	std::string name;
	int age;
	Sex sex;
	double weight;
	double height;
	
public:

	User()=default;
	User(const std::string& name, const int& age,const Sex& sex ,const double& weight, const double& height);


	std::string get_name()const;
	int get_age()const;
	Sex get_sex()const;
	double get_weight()const;
	double get_height()const;
	double kcl_demand() const;//wyznacza zapotrzebowanie kaloryczne
	double bmi() const;//wyznacza bmi
	std::string is_your_weight_ok();//sprawdza czy nasze bmi jest ok
	friend std::ostream& operator<<(std::ostream& out, const User& user);
};

