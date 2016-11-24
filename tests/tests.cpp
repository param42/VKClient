#include <VK/client.hpp>
#include "catch.hpp"


 

SCENARIO("test")
{
 
 std::string invalid_code="3423424";
 std::string valid_code="4956ba777a10520805";
 
 VK::Client invalide_client({{"code", invalid_code}});
 VK::Client valide_client({{"code", valid_code}});
 
    GIVEN("invalid token")
    {        
        WHEN("initialize")
        {     
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
            THEN("return true")
            {
                REQUIRE(valide_client.check_connection_server());
            }
        }
    }
    GIVEN("GET_FRIEND_ONLINE")
    {
      
     WHEN("GET_FRIEND")
     {
       
        THEN("RETURN FRIEND")
        {
           REQUIRE(valide_client.get_frientd_online().size()!=0);
           }
         }
      }
      GIVEN("GET_FRIEND_ONLINE_no")
    {
     
     WHEN("GET_FRIEND")
     {
        
        THEN("RETURN FRIEND")
        {
           REQUIRE(invalide_client.get_frientd_online().size()==0);
           }
         }
      }
}
