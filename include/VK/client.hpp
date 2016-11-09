
#include <string>
#include <map>

namespace Vk {
	class Client {
	public:
		using dict_t = std::map<std::string, std::string>;

		Client() {};
		Client(dict_t settings) : settings_(settings) {};
		auto check_connection() -> bool;

	private:
		dict_t settings_;
	};
}
