 

#include <curl/curl.h>
#include "VK/client.hpp"
#include <vector>
#include <time.h>
#include <thread>
#include <future>
#include <chrono>
 
 

int main()
	
{	
	std::string code;
	std::cout << "Для получения code пройдите по данному url:" << std::endl;
	std::cout << "https://oauth.vk.com/authorize?client_id=5687691&display=page&redirect_uri=https://oauth.vk.com/blank.html&scope=friends&response_type=code&v=5.60" << std::endl;
	code = "93fb58133ff3a7e9d9";
	
	
	VK::Client client({ { "code", code } });
	if (client.check_connection_server()) {
		std::cout << "the connection is successful" << std::endl;

		if (client.get_frientd_online()) {
			std::cout << "Friends received successfully" << std::endl;

			try {
				std::string command;
				 
				std::cout << "Enter a command:" << std::endl;
				std::cin >> command;
				if (!std::cin) throw std::invalid_argument("Wrong command");

				if (command == "get_friends_v") {	 
					client.launch_threads_to_see_friends(true);
				}
				if (command == "get_friends") {
					client.launch_threads_to_see_friends(false);
				}

			}
			catch (const std::invalid_argument& e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}
	system("pause");
	return 0;
 
}

