 
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
					std::cout << j_response << std::endl;
					return true;
				}
				else {
					curl_easy_cleanup(curl);
					std::cout << buffer << std::endl;
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

	auto Client::get_token()->std::string {
		if(_settings["token"]!="")
		return _settings["token"];
	}

	auto Client::check_connection_server()->bool {

		 

		CURL *curl;
		curl = curl_easy_init();
		std::string buffer = "";
		if (curl)
		{


			std::string fields = "client_id=5687691&client_secret=XZ3RUDfYgfgf&redirect_uri=https://oauth.vk.com/blank.html&code=";
			fields += _settings["code"];

			curl_easy_setopt(curl, CURLOPT_URL, "https://oauth.vk.com/access_token?");
			curl_easy_setopt(curl, CURLOPT_POSTFIELDS, fields.c_str());
			curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, fields.length());
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, VK::Client::write_callback);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);

			if (curl_easy_perform(curl) == CURLE_OK)
			{
				json jsn_token = (json::parse(buffer.c_str()))["access_token"];

				if (!jsn_token.is_null()) {
					std::string s = jsn_token;
					_settings["token"] = s;
					std::cout<<s<<std::endl;
					curl_easy_cleanup(curl);
					 
				}

			return true;

			}
		}
		curl_easy_cleanup(curl);
		return false;


	}
auto Client::get_friends_vector()->std::vector<User> {
		return users;
	}
	auto Client::get_frientd_online()->bool {
 		
		if(_settings["token"]=="") return false;
		std::string buffer = "";
		char errorBuffer[CURL_ERROR_SIZE];
		CURL *curl;
		curl = curl_easy_init();

		if (curl) {
			std::string data_to_send = "access_token=" + _settings["token"] + "&v=5.59";
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

				return true;
			}
			else {
				std::cout << "error! " << errorBuffer << std::endl;
			}
			return false;
		}
	}

	auto Client::launch_threads_to_see_friends()->bool {

		 
		std::string s;
		int n;
		std::cin >> s;

		if (s == "get_friends_-v") {
			FRTThread th(users,true);
			std::cout << "Number of threads:" << std::endl;
			std::cin >> n;
			return th.launch_threads(n);
		}
		if (s == "get_friends") {
			FRTThread th(users,false);
			std::cout << "Number of threads:" << std::endl;
			std::cin >> n;
			return th.launch_threads(n);
		}
		return false;


	}






	FRTThread::FRTThread(std::vector<VK::User> users_,bool flag_v) {
		v = flag_v;
		users = users_;
	}

	auto FRTThread::print_one_friend(int id)->void {
		do {
			mutex.lock();
			if (counter < users.size()) {
				if (v) {
					std::cout << "number_of_thread: " << id << std::endl << "thread_id " << std::this_thread::get_id() << std::endl << "USER ID:" << users[counter].id << std::endl << std::endl;
				}
				else {
					std::cout << users[counter].id << '\n';
				}
			}
			++counter;
			mutex.unlock();
			std::this_thread::sleep_for(std::chrono::seconds(2));

		} while (counter < users.size());
	}

	auto FRTThread::launch_threads(int n)->bool {

		counter = 0;
		
		if (n<1 || n>std::thread::hardware_concurrency()) {

			return false;
		}

		for (size_t i = 0; i < n; i++)
		{
			vec_thread.push_back(std::thread(&FRTThread::print_one_friend, this, i));
		}

		for (size_t i = 0; i < n; i++)
		{
			vec_thread[i].join();
		}
		return true;
	}

 

	FRTThread::~FRTThread()
	{
	}





}
