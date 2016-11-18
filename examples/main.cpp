 


#include <curl/curl.h>
#include "VK/client.hpp"
#include <vector>

 

int main()
{
	setlocale(LC_ALL, "Russian");
	VK::Client cl({ {"token", token} });
	
	if (cl.check_connection()) {
		std::vector<VK::User>users;
			users=cl.get_frientd_online();


			for (int i = 0; i < users.size(); i++) {
				std::cout << users[i].id << std::endl;
			}

	}
		

		system("pause");
		return 0;
	}

