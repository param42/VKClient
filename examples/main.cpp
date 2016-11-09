#include <vk/client.hpp>
#include <iostream>

int main()
{
    std::string token;
 //https://oauth.vk.com/authorize?client_id=5687691&display=page&redirect_uri=https://oauth.vk.com/blank.html&scope=friends&response_type=token&v=5.52
    std::cout << "token"<<std::endl;
    std::cin >> token;
    Vk::Client vk_cl({{"token", token}});

    if (vk_cl.check_connection())
        std::cout << "Connected." << std::endl;

    vk_cl.get_friends();

    return 0;
}
