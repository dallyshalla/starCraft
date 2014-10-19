#include <iostream>
#include <string>

class member {
  public:
  std::string username;
  std::string inventory[4000];
  int inventoryQuantities[4000];
  std::string gainedInventory[4000];
  int gainedQuantites[4000];
  int startCoins;
  public:
    void buy(std::string);
    void sell(std::string);
    void createItems(std::string);
    void destroyItems(std::string);
    void storeNewItem(std::string);

};
int answer;
int main()
{
  member mem1;
  member mem2;
  std::cout << "welcome to star Craft v0.0.1" << std::endl;
  std::cout << "1. Start a username" << std::endl;
  std::cout << "0. exit" << std::endl;
  std::cin >> answer;
  if(answer == 1)
  {
    std::cout << "What is your username to be?" << std::endl;
    std::cin >> mem1.username;
    std::cout << mem1.username << std::endl;
  
  
  }
  return 0;

}
