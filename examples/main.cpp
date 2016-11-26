 

 #include <curl/curl.h>
#include "VK/client.hpp"
#include <vector>
#include <time.h>
#include <thread>
#include <future>
#include <chrono>
#include "VK/FRTThread.hpp"

 

int main()
	
{	std::string code;
	std::cout << "Для получения code пройдите по данному url:" << std::endl;
	std::cout << "https://oauth.vk.com/authorize?client_id=5454862&display=page&redirect_uri=https://oauth.vk.com/blank.html&scope=friends&response_type=code&v=5.60" << std::endl;
	std::cout << "code = ";
	std::cin >> code;
	VK::Client client({ { "code", code } });

	if(client.check_connection_server()) {

		FRTThread threads_friends(client.get_frientd_online());

		threads_friends.cin();

	}
		system("pause");
		return 0;
	}

