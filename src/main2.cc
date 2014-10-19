#include <iostream>
#include <string>

class member {
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

int main()
{
  member mem1;
  member mem2;
  
  return 0;

}
