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

int main()
{ 
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
