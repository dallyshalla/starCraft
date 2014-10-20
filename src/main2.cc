#include <iostream>
#include <string>

class member {
  public:
  int starCoins;
  std::string username;
  std::string inventory[4000];
  int inventoryQuantities[4000];
  std::string gainedInventory[4000];
  int gainedQuantities[4000];
  int locator;
  public:
    void buy(std::string);
    void sell(std::string);    
    void destroyItems(std::string);
    void storeNewItem(std::string);
    void loadCoins(std::string)
    {
      starCoins = 10000;
    }
};
void createItems(std::string, std::string, int, member);
int funActions(std::string);
std::string activeUser;
int answer;
int response;
int stateanswer;
int lateanswer;
int quantity;
std::string name;
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
    mem1.inventory[0] = mem1.username;
    mem1.gainedInventory[0] = mem1.username;
    mem1.locator++;
    mem1.gainedQuantities[0] = 10000;
    mem1.inventoryQuantities[0] = 10000;
    std::cout << mem1.username << " you'll start off with " << mem1.starCoins << " starCoins, use them wisely" << std::endl;
  }
  else if (answer != 1)
  {
    return 0;
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
    mem2.inventory[0] = mem2.username;
    mem2.gainedInventory[0] = mem2.username;
    mem2.gainedQuantities[0] = 10000;
    mem2.inventoryQuantities[0] = 10000;
    std::cout << mem2.username << " you'll start off with " << mem2.starCoins << " starCoins, use them wisely" << std::endl; 
  }
  else if (answer != 1)
  {
    return 0;
  }
  std::cout << "Now that you are in, and so is yourself twice or your friend you can now decide to simulate economy :)" << std::endl;
  std::cout << std::endl;
  std::cout << "select who is acting now" << std::endl;
  std::cout << "1. " << mem1.username << std::endl;
  std::cout << "2. " << mem2.username << std::endl;
  std::cin >> answer;
  if(answer == 1)
  {
    activeUser = mem1.username;
    std::cout << "welcome " << mem1.username << " you are the active user" << std::endl;
  }
  else if (answer == 2) 
  {
    activeUser = mem2.username;
    std::cout << "welcome " << mem2.username << " you are the active user" << std::endl;
  }
  do
  {
    lateanswer = funActions(activeUser);
    if(lateanswer == 1)
    {
      std::cout << "You can create an item" << std::endl;
      std::cout << "what is the name of the item" << std::endl;
      std::cin >> name;
      std::cout << "what is the amout of " << name << " that will exist" << std::endl;
      std::cin >> quantity;
      createItems(activeUser, name, quantity, mem1);
    }
    if (lateanswer == 2)
    {
      for(int i = 0; i <= mem1.locator; i++)
      {
        std::cout << mem1.inventory[i] << std::endl;
      }
    
    }
    std::cout << " are you finished ? type 0 if you're done, otherwise press anything" << std::endl;
    std::cin >> stateanswer;

  } while (stateanswer != 0);

  return 0;

}

int funActions(std::string nameOfUser)
{
  int response = 100;
    std::cout << nameOfUser << "Your commands are as follows" << std::endl;
    std::cout << "1. createItems" << std::endl;
    std::cout << "2. View Created Items" << std::endl;
    std::cout << "3. View starCoin balance" << std::endl;
    std::cout << "4. View Gained Items" << std::endl;
    std::cout << "5. Destroy Created Items" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cin >> response;

  return response;

}
void createItems(std::string userName, std::string nameOfItem, int quantity, member mems)
{
  mems.inventory[mems.locator] = nameOfItem;
  mems.inventoryQuantities[mems.locator] = quantity;
  mems.locator++; //have to do this by reference


}
