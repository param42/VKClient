 

 #include <curl/curl.h>
#include "VK/client.hpp"
#include <vector>
#include <time.h>
#include <thread>
#include <future>
#include <chrono>
#include "VK/FRTThread.hpp"
std::string token = "127961f2d122ca42393fd8b9++++de04489e7cd785bb";

 

int main()
{
	VK::Client cl({ { "token", token } });
	std::vector<VK::User>users;
	if (cl.check_connection()) {
		 
		users = cl.get_frientd_online();


		for (int i = 0; i < users.size(); i++) {
			std::cout << users[i].id << std::endl;
		}
		std::cout << "____" << std::endl;
	}

	FRTThread ft(users);
	
		if (ft.cin()) {
			std::cout << "all_threads_end" << std::endl;
		}
		else {
			std::cout << "error";
		}


		system("pause");
		return 0;
	}

