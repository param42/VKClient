
#include "client.h"
#include <curl\curl.h>
#include <iostream>
#include <istream>
#include <string>
#include <string.h>
#include "Json.hpp"
namespace VK {

	
	Client::Client(dict_t settings) {
		_settings = settings;
	}

	//int Client::write_callback(char *data, size_t size, size_t nmemb, std::string *buffer)
	//{
	//	//переменная - результат, по умолчанию нулевая
	//	int result = 0;
	//	//проверяем буфер
	//	if (buffer != NULL)
	//	{
	//		//добавляем к буферу строки из data, в количестве nmemb
	//		buffer->append(data, size * nmemb);
	//		//вычисляем объем принятых данных
	//		result = size * nmemb;
	//	}
	//	//вовзращаем результат
	//	return result;
	//}

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

	 	//char* buffer = new char[1];
		//buffer[0] = '\0';
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
				//std::cout << buffer<<std::endl;
			 
				size_t pos = buffer.find("response");
				if (pos != std::string::npos) {
					curl_easy_cleanup(curl);
					return true;
				}
				else {
					curl_easy_cleanup(curl);
					return false;
				}
			}
			else {
				std::cout << "error! " << errorBuffer << std::endl;
			}
			curl_easy_cleanup(curl);
		}

	}


	auto Client::get_frientd()->bool {
		std::string buffer = "";
		char errorBuffer[CURL_ERROR_SIZE];
		CURL *curl;
		curl = curl_easy_init();

		if (curl) {
			std::string data_to_send = "access_token=" + _settings["token"] + "&v=5.59";
			CURLcode res;
			curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
			curl_easy_setopt(curl, CURLOPT_URL, "https://api.vk.com/method/friends.getOnline?");
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data_to_send.c_str());
			//curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, VK::Client::writer);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);



			if (curl_easy_perform(curl) == CURLE_OK)
			{
				std::cout << buffer << std::endl;
			}
			else {
				std::cout << "error! " << errorBuffer << std::endl;
			}


			curl_easy_cleanup(curl);
		}
	}
	
}
