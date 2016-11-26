#include <VK/client.hpp>
#include "catch.hpp"


 

SCENARIO("test")
{
 
 std::string invalid_code="";
 std::string valid_code="fc7b68be1f83dd344c";
 
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
          
           REQUIRE(valide_client.get_frientd_online());
           }
         }
      }
      GIVEN("GET_FRIEND_ONLINE_no")
    {
     
     WHEN("GET_FRIEND")
     {
        
        THEN("RETURN FRIEND")
        {
           REQUIRE(!invalide_client.get_frientd_online());
           }
         }
      }
}
