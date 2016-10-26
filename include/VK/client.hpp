#include <string>
#include <map>

namespace Facebook{
  class Client{
  public:
    using dict_t = std::map<std::string, std::string>;
    Client(dict_t settings);
    auto check_connection() -> bool;
  };
}
