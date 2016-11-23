 
#include "FRTThread.hpp"


FRTThread::FRTThread(std::vector<VK::User> users_) {
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

auto FRTThread::cin()->bool{

	std::string s;
int n;
std::cin >> s;

if (s == "get_friends_with_logs") {
	v = true;
	std::cout << "Number of threads:" << std::endl;
	std::cin >> n;
	return launch_threads(n);
}
if (s == "get_friends") {
	v = false;
	std::cout << "Number of threads:" << std::endl;
	std::cin >> n;
	return launch_threads(n);
}
return false;

}

FRTThread::~FRTThread()
{
}
