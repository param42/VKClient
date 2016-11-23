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
        std::map<std::string, std::string> valid_settings{{"token", "8c066da2a193ad73e23d2bbcc4479b1d1989142b832a772b36d5bcc19499355ee466eeb35332729dee3d2a"}};

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
     std::map<std::string, std::string> valid_settings{{"token", "8c066da2a193ad73e23d2bbcc9447b1d1989142b832a772b36d5bcc19499355ee466eeb35332729dee3d2a"}};
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
