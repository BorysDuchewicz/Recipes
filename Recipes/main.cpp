#include "user_service.h"


int main()
{
	try
	{
		Recipes r("recipes");
		UserService u{ r };
		u.main();
	}
	catch(const AppException& e)
	{
		std::cout <<e.error_message();
	}
	return 0;
}