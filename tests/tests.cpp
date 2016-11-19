#include <VK/client.hpp>
#include "catch.hpp"


 

SCENARIO("test")
{
    GIVEN("invalid token")
    {
        std::map<std::string, std::string> invalid_settings{{"token", "097867564gfhjf352435465745g45g5f4f342h7j56hre6j"}};

        WHEN("initialize")
        {
            VK::Client client(invalid_settings);

            THEN("return false")
            {
                REQUIRE(!client.check_connection());
            }
        }
    }

    GIVEN("valid token")
    {
        std::map<std::string, std::string> valid_settings{{"token", "672f98cc5c7b4e740e51d9360ad1126bc4484599fd41290b4f9759b74003ff23e545c521b652d73e9e93b"}};

        WHEN("initialize")
        {
            VK::Client client(valid_settings);

            THEN("return true")
            {
                REQUIRE(client.check_connection());
            }
        }
    }
    GIVEN("GET_FRIEND_ONLINE")
    {
     std::map<std::string, std::string> valid_settings{{"token", "672f98cc5c7b4e740e51d9360ad1126bc4484599fd41290b4f9759b74003ff23e545c521b652d73e9e93b"}};
     WHEN("GET_FRIEND")
     {
        VK::Client client(valid_settings);
        THEN("RETURN FRIEND")
        {
           REQUIRE(client.get_frientd_online().size()!=0);
           }
         }
      }
      GIVEN("GET_FRIEND_ONLINE_no")
    {
     std::map<std::string, std::string> INvalid_settings{{"token", "b40e14604f5ffc4f3406d6c3dbe0c116477e09d"}};
     WHEN("GET_FRIEND")
     {
        VK::Client client(INvalid_settings);
        THEN("RETURN FRIEND")
        {
           REQUIRE(client.get_frientd_online().size()==0);
           }
         }
      }
}
