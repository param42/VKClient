#pragma once
#include <string>
#include <map>
#include <vector>
#include "VK/json.hpp"
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


	class Client {
	public:

		std::vector<User> users;
		using json = nlohmann::json;
		using dict_t = std::map<std::string, std::string>;
		dict_t _settings;



		Client(dict_t settings);
		auto check_connection() -> bool;
		auto get_frientd_online()->std::vector<User>;

		//static int write_callback(char *data, size_t size, size_t nmemb, std::string *buffer);
		static auto write_callback(char * data, size_t size, size_t nmemb, void * buff)->size_t;
	};

}
