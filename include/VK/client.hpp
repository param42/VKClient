#pragma once
#include <string>
#include <map>
#include <vector>
#include "VK/json.hpp"
#include <thread>
#include <mutex>
namespace VK {

	class User {
	public:

		std::string name;
		int id;
		User(std::string namee,  int idd) {
			name = namee;
			id = idd;
		}

	};

	class FRTThread
	{
	public:
		std::vector<User> users;
		int counter = 0;
		std::mutex mutex;
		bool v;
		 
		std::vector<std::thread> vec_thread;

		FRTThread(std::vector<VK::User> users_, bool flag_v);


		auto print_one_friend(int id)->void;
		auto launch_threads(int n)->bool;
		 

		~FRTThread();
	};


	class Client {
	public:

		std::vector<User> users;
		using json = nlohmann::json;
		using dict_t = std::map<std::string, std::string>;
		dict_t _settings;



		Client(dict_t settings);
		auto check_connection() -> bool;
		auto check_connection_server()->bool;
		auto get_frientd_online()->bool;
		auto get_token()->std::string;
		auto launch_threads_to_see_friends()->bool;
		
		static auto write_callback(char * data, size_t size, size_t nmemb, void * buff)->size_t;
	};

}
