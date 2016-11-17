#pragma once
#include <string>
#include <map>
#include "Json.hpp"
namespace VK {
	class Client {
	public:

		using json = nlohmann::json;
		using dict_t = std::map<std::string, std::string>;
		dict_t _settings;
	
		Client(dict_t settings);
		auto check_connection() -> bool;
		auto get_frientd()->bool;

		//static int write_callback(char *data, size_t size, size_t nmemb, std::string *buffer);
		static auto write_callback(char * data, size_t size, size_t nmemb, void * buff)->size_t;
	};
}
