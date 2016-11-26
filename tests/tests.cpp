#include <VK/client.hpp>
#include "catch.hpp"


 

SCENARIO("test")
{

 
    GIVEN("invalid token")
    {        
        WHEN("initialize")
        {     
          std::string invalid_code="";
          VK::Client invalide_client({{"code", invalid_code}});
            THEN("return false")
            {
                REQUIRE(!invalide_client.check_connection_server());
            }
        }
    }

    GIVEN("valid token")
   {
       
        WHEN("initialize")
        {   
         std::string valid_code="6b2f9с490781f45ecb";
        VK::Client valide_client({{"code", valid_code}});
            THEN("return true")
            {
                REQUIRE(valide_client.check_connection_server());
            }
        }
    }
    GIVEN("GET_FRIEND_ONLINE")
    {
      
     WHEN("initialize")
     {
        
       std::string valid_code="6b2f9c490781f45ecb";
       VK::Client valide_client({{"code", valid_code}});
 
        THEN("RETURN FRIEND")
        {
          
           REQUIRE(valide_client.get_frientd_online());
           }
         }
      }
      GIVEN("GET_FRIEND_ONLINE_no")
    {
     
     WHEN("initialize")
     {
           std::string invalid_code="";
          VK::Client invalide_client({{"code", invalid_code}});
        THEN("RETURN FRIEND")
        {
           REQUIRE(!invalide_client.get_frientd_online());
           }
         }
      }
}
