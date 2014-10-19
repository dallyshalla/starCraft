#include <iostream>
#include <string>

class member {
  public:
  int starCoins;
  std::string username;
  std::string inventory[4000];
  int inventoryQuantities[4000];
  std::string gainedInventory[4000];
  int gainedQuantites[4000];
  int locator;
  public:
    void buy(std::string);
    void sell(std::string);
    void createItems(std::string);
    void destroyItems(std::string);
    void storeNewItem(std::string);
    void loadCoins(std::string)
    {
      starCoins = 10000;
    }
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
    mem1.loadCoins(mem1.username);
    std::cout << mem1.username << " you'll start off with " << mem1.starCoins << " starCoins, use them wisely" << std::endl;
  }
  std::cout << "You can make a second user and simulate exchange" << std::endl;
  std::cout << "1. Start a new user" << std::endl;
  std::cout << "0. Exit" << std::endl;
  std::cin >> answer;
  if(answer == 1) 
  {
    std::cout << "What is user2's name to be?" << std::endl;
    std::cin >> mem2.username;
    mem2.loadCoins(mem2.username);
    std::cout << mem2.username << " you'll start off with " << mem2.starCoins << " starCoins, use them wisely" << std::endl; 
  }
  

  return 0;

}
