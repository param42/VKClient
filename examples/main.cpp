#include "stdafx.h"
#include "client.h"
#include <iostream>

#include <iostream>

int main()
{

	//setlocale(LC_ALL, "rus");
	std::string access_token="===access_token_this===";
	Vk::Client data({ { "token", access_token } });
	data.check_connection();
	system("pause");
	return 0;
}















//// VKClient.cpp : Defines the entry point for the console application.
////
////#include "client.hpp"
//#include "stdafx.h"
//#include <stdio.h>
//#include <curl/curl.h>
//#include <string.h>
//#include <iostream>
//int main()
//{
//
//	CURL *curl;
//	CURLcode res;
//	 
//	curl = curl_easy_init();
//	if (curl) {
//		std::string s;
//		curl_easy_setopt(curl, CURLOPT_URL, "https://www.yandex.ru/");
//	
//		//curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
//		//curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
//		//curl_easy_setopt(curl, CURLOPT_RETURNTRANSFER, true);
//		//std::string result = curl_exec(curl);
//		//curl_easy_perform();
//
//		//
//		////...
//		//curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str_AuthResponse);
//		//curl_easy_setopt(curl, CURLOPT_URL, "http://vk.com/login.php");
//		//curl_easy_setopt(curl, CURLOPT_POST, true);
//		//curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "email=myemailname123@mail.ru&pass=mypassword123");
//		////...
//		//curl_easy_perform();
//	}
//	curl_easy_perform(curl);
//	system("pause");
//    return 0;
//}

// VKClient.cpp : Defines the entry point for the console application.
//
//#include "client.hpp"
//#include "stdafx.h"
//#include <stdio.h>
//#include <curl/curl.h>
//#include <string>
//#include <iostream>

//
//
//
//
//int main()
//{
//
//	
//	system("pause");
//	return 0;
//}
//
//
//CURL *curl = curl_easy_init();
//if (curl) {
//	CURLcode res;
//	//curl_easy_setopt(curl, CURLOPT_URL, "http://yandex.ru/");
//	//curl_easy_setopt(curl, CURLOPT_URL, "https://www.yandex.ru/");
//	res = curl_easy_perform(curl);
//
//	if (res == CURLE_OK) {
//		long response_code;
//		res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
//
//	}
//
//	curl_easy_cleanup(curl);
//}
//
//curl_easy_perform(curl);
///*
//CURL *curl;
////CURLcode res;


//
//curl = curl_easy_init();
//if (curl) {
//std::string s;
//std::string buffer = "";
//
//std::string s = "https://api.vk.com/method/METHOD_NAME?PARAMETERS&access_token=ACCESS_TOKEN&v=V";
////curl_easy_setopt(curl, CURLOPT_URL, "https://www.yandex.ru/");
//curl_easy_setopt(curl, CURLOPT_URL, s);
//curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, f);
//curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);



//curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
//curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
//curl_easy_setopt(curl, CURLOPT_RETURNTRANSFER, true);
//std::string result = curl_exec(curl);
//curl_easy_perform();

//
////...
//curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str_AuthResponse);
//curl_easy_setopt(curl, CURLOPT_URL, "http://vk.com/login.php");
//curl_easy_setopt(curl, CURLOPT_POST, true);
//curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "email=myemailname123@mail.ru&pass=mypassword123");
////...
//curl_easy_perform();
//}
//curl_easy_perform(curl);
//*/

//
////устанавливаю параметры
//curl_easy_setopt(Curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0");
//curl_easy_setopt(Curl, CURLOPT_FOLLOWLOCATION, 1);
//curl_easy_setopt(Curl, CURLOPT_AUTOREFERER, 1);
//curl_easy_setopt(Curl, CURLOPT_COOKIEJAR, "cookie.txt");
//curl_easy_setopt(Curl, CURLOPT_COOKIELIST, "cookie.txt");
//curl_easy_setopt(Curl, CURLOPT_SSL_VERIFYPEER, 0);
//curl_easy_setopt(Curl, CURLOPT_SSL_VERIFYHOST, 0);
//
////Перехожу по адресу [url]https://login.vk.com/?act=login[/url] и выдергиваю оттуда ip_h ig_h
//curl_easy_setopt(Curl, CURLOPT_URL, "https://login.vk.com/?act=login");
//curl_easy_setopt(Curl, CURLOPT_WRITEDATA, &content);
//curl_easy_setopt(Curl, CURLOPT_WRITEFUNCTION, write_data_str);
//curl_easy_perform(Curl);
//ip_h = GetMARKLink(content, MARKip_h, 0);
//ig_h = GetMARKLink(content, MARKig_h, 0);
//
//
//
////Далее делаю POST запрос и подставляю туда мыло, пароль ip_h  ig_h
//curl_easy_setopt(Curl, CURLOPT_URL, "https://login.vk.com/?act=login");
//URL = "&role=al_frame&expire=&captcha_sid=&captcha_key=&_origin=https%3A%2F%2Fvk.com&ip_h=" +
//ip_h + "&lg_h=" + ig_h + "&email=" + escape(Curl, Email) + "&pass=" + escape(Curl, Password);
//curl_easy_setopt(Curl, CURLOPT_POST, 1);
//curl_easy_setopt(Curl, CURLOPT_POSTFIELDS, URL.c_str());
//curl_easy_setopt(Curl, CURLOPT_POSTFIELDSIZE, URL.length());
//curl_easy_perform(Curl);






//
////устанавливаю параметры
//curl_easy_setopt(Curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:38.0) Gecko/20100101 Firefox/38.0");
//curl_easy_setopt(Curl, CURLOPT_FOLLOWLOCATION, 1);
//curl_easy_setopt(Curl, CURLOPT_AUTOREFERER, 1);
//curl_easy_setopt(Curl, CURLOPT_COOKIEJAR, "cookie.txt");
//curl_easy_setopt(Curl, CURLOPT_COOKIELIST, "cookie.txt");
//curl_easy_setopt(Curl, CURLOPT_SSL_VERIFYPEER, 0);
//curl_easy_setopt(Curl, CURLOPT_SSL_VERIFYHOST, 0);
//
////Перехожу по адресу [url]https://login.vk.com/?act=login[/url] и выдергиваю оттуда ip_h ig_h
//curl_easy_setopt(Curl, CURLOPT_URL, "https://login.vk.com/?act=login");
//curl_easy_setopt(Curl, CURLOPT_WRITEDATA, &content);
//curl_easy_setopt(Curl, CURLOPT_WRITEFUNCTION, write_data_str);
//curl_easy_perform(Curl);
//ip_h = GetMARKLink(content, MARKip_h, 0);
//ig_h = GetMARKLink(content, MARKig_h, 0);
//
//
//
////Далее делаю POST запрос и подставляю туда мыло, пароль ip_h  ig_h
//curl_easy_setopt(Curl, CURLOPT_URL, "https://login.vk.com/?act=login");
//URL = "&role=al_frame&expire=&captcha_sid=&captcha_key=&_origin=https%3A%2F%2Fvk.com&ip_h=" +
//ip_h + "&lg_h=" + ig_h + "&email=" + escape(Curl, Email) + "&pass=" + escape(Curl, Password);
//curl_easy_setopt(Curl, CURLOPT_POST, 1);
//curl_easy_setopt(Curl, CURLOPT_POSTFIELDS, URL.c_str());
//curl_easy_setopt(Curl, CURLOPT_POSTFIELDSIZE, URL.length());
//curl_easy_perform(Curl);


