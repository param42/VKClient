#pragma once
#include <thread>
#include <future>
#include <chrono>
#include <vector>
#include "client.h"
class FRTThread
{
public:

	int counter = 0;
	std::mutex mutex;
	bool v;
	std::vector<VK::User> users;
	std::vector<std::thread> vec_thread;

	FRTThread(std::vector<VK::User> users_);


	auto print_one_friend(int id)->void;
	auto launch_threads(int n)->bool;
	auto cin()->bool;

	~FRTThread();
};

