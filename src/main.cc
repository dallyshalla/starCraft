#include <iostream>
#include <istream>
#include "../include/buy.h"
int buy1;
int trade1;
std::string buyitem;
std::string tradeitem;
using namespace starcraft;
int balance1 = 1000;
int balance2 = 1000;
std::string user1;
std::string user2;
int yesorno;

int main()
{
  std::cout << "enter username 1" << std::endl;
  std::cin >> user1; 
  std::cout << "enter a name for user 2" << std::endl;
  std::cin >> user2;
  std::cout << "want to see user 1 and user 2 balance? 0 for yes 1 for no" << std::endl;
  std::cin >> yesorno;
  if(yesorno == 0) 
  {
    std::cout << "user 1 balance: " << balance1 << "SafeCoin" << std::endl;
    std::cout << "user 2 balance: " << balance2 << "SafeCoin" << std::endl;
  }
  std::cout << "enter an item" << std::endl;
  std::cin >> buyitem;
  std::cout << "enter the quantity" << std::endl;
  std::cin >> buy1;
  std::cout << "enter the traded item" << std::endl;
  std::cin >> tradeitem;
  std::cout << "enter the quantity of the trade item" << std::endl;
  std::cin >> trade1;

  return 0;  
}
