 
#include "VK/client.hpp"
#include <curl/curl.h>
#include <iostream>
#include <istream>
#include <string>
#include <string.h>
#include "VK/json.hpp"
namespace VK {


	Client::Client(dict_t settings) {
		
		_settings = settings;
		_settings["token"] = "8c066da2a193ad73e23d2bbcc447b1d1989142b832a772b36d5bcc19499355ee466eeb35332729dee3d2a";
		
	}

	 

	auto Client::write_callback(char * data, size_t size, size_t nmemb, void * buff) -> size_t
	{
		size_t result = 0;

		if (buff)
		{
			result = size * nmemb;
			((std::string*)buff)->append(data, 0, result);
		}

		return result;
	}

	auto Client::check_connection()->bool
	{
	  
		std::string buffer = "";
		char errorBuffer[CURL_ERROR_SIZE];
		CURL *curl;
		curl = curl_easy_init();

		if (curl) {
			std::string data_to_send = "access_token=" + _settings["token"] + "&v=5.59";
			CURLcode res;
			curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
			curl_easy_setopt(curl, CURLOPT_URL, "https://api.vk.com/method/account.getProfileInfo?");
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data_to_send.c_str());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

			
			if (curl_easy_perform(curl) == CURLE_OK)
			{

				json j_response = (json::parse(buffer.c_str()))["response"];
				if (!j_response.is_null()) {
					curl_easy_cleanup(curl);
					return true;
				}
				else {
					curl_easy_cleanup(curl);
					return false;
				}
				std::cout << buffer;
		
			}
			else {
				std::cout << "error! " << errorBuffer << std::endl;
			}
			curl_easy_cleanup(curl);
		}

	}



	auto Client::get_frientd_online()->std::vector<User>  {
		std::string buffer = "";
		char errorBuffer[CURL_ERROR_SIZE];
		CURL *curl;
		curl = curl_easy_init();
		
		if (curl) {
			std::string data_to_send = "access_token=" + _settings["token"] + "&v=5.59";
			CURLcode res;
			curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
			curl_easy_setopt(curl, CURLOPT_URL, "https://api.vk.com/method/friends.get?fields=name&count=5");
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data_to_send.c_str());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, VK::Client::write_callback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

			if (curl_easy_perform(curl) == CURLE_OK)
			{
			json j_friend = json::parse(buffer.c_str())["response"]["items"];
						
			for (json::iterator it = j_friend.begin(); it != j_friend.end(); ++it) {
				 
				users.push_back(User((*it)["first_name"], (*it)["id"]));
			}
				
			return users;
			}
			else {
			std::cout << "error! " << errorBuffer << std::endl;
			}
		}
	}
	
}
