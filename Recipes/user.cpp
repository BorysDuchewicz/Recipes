#include "user.h"

User::User(const std::string& name, const int& age,const Sex& sex,const double& weight, const double& height)
	:name{ name }, age{ age }, sex{ sex }, weight{ weight }, height{ height }{}

std::string User::get_name() const
{
	return this->name;
}

int User::get_age() const
{
	return this->age;
}

Sex User::get_sex() const
{
	return this->sex;
}

double User::get_weight() const
{
	return this->weight;
}

double User::get_height() const
{
	return this->height;
}

double User::kcl_demand() const
{
	if(sex_to_str(this->sex)=="Women")
	{
		return 655.1 + (9.563 * weight) + (1.85 * height) - (4.676 * age);
	}
	else
	{
		return 66.5 + (13.75* weight) + (5.003* height) - (6.775 * age);
	}
}

double User::bmi() const
{
	return weight / pow(height / 100, 2);
}

std::string User::is_your_weight_ok()
{
	const double bmi = this->bmi();
	if(bmi<16)
	{
		return "Duza niedowaga";
	}
	else if(bmi>=16 && bmi <18.5)
	{
		return "Niedowaga";
	}
	else if(bmi>=18.5 && bmi<25)
	{
		return "Norma";
	}
	else if (bmi >= 25 && bmi < 30)
	{
		return "Nadwaga";
	}
	else if (bmi >= 30 && bmi < 35)
	{
		return "Otylosc";
	}
	else if (bmi >= 35 && bmi < 40)
	{
		return "Otylosc 2 stopnia";
	}
	else
	{
		return "Otylosc 3 stopnia";
	}
}

std::ostream& operator<<(std::ostream& out, const User& user)
{
	return out << user.name << " " << user.age << " " << user.weight << user.height << std::endl;
}
