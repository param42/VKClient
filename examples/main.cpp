
#include <curl\curl.h>
#include "client.h"


std::string token = "522b383faa06ad0e50c5b1c5ebb70a8fe1a92d285b3d61b40e14604f5ffc4f3406d6c3dbe0c116477e09d";

int main()
{
	
	VK::Client cl({ {"token", token} });
	
	if (cl.check_connection()) {
		std::cout << "yes";
	}
	else {
		std::cout << "no";
	}
	 
		system("pause");
		return 0;
	}





