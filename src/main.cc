#include <iostream>
#include <istream>
class Authentication {
  public:
    void storeID(std::string);
    std::string userID;

};
class Buy {
  std::string userID;
  public:
    void buy(std::string, std::string, int, std::string, int);
    int plusplus(int a, int b)
    {
      return a - b;
    } 
};
//look at the comments :D
void createUser(std::string); //make a username and a unique one
void createItem(std::string); //take a parameter of username and make an item from it
void sellItem(std::string); //using username allow the sale of that persons item for any other item
void buyItem(std::string); //using username allow the buy of any item that may ever exist in the future or that exists currently

class coinBalance {
  std::string user;
  int balance;
}


void storeItem(std::string, std::string, std::string[], int, int[], int&);
void tradeItem(std::string, std::string, int, std::string, int);
int location1 = 0;
int location2 = 0;
std::string newitemname1;
int newitemquantity1;
int buy1;
int trade1;
int iquantity1[4000];
int iquantity2[4000];
std::string iname1[4000];
std::string iname2[4000];
std::string buyitem;
std::string tradeitem;
using namespace starcraft;
int balance1 = 1000;
int balance2 = 1000;
std::string user1;
std::string user2;
int answer;
int yesorno;
int setBalance(int);
void getBalance(std::string);
int main()
{
  std::cout << "Welcome to Project star Craft v0.0.1" << std::endl;
  std::cout << "1. Make a new user ID" << std::endl;
  std::cout << "2. Enter a star Craft Private Key" << std::endl;
  std::cout << "3. Exit" << std::endl;
  std::cin >> answer;
  if(answer == 1)
  {
    std::cout << "Enter a username: " << std::endl;
    std::cin >> user1;
  
  }
  std::cout << "make a new item" << std::endl;
  std::cout << "what is the name of your new item?" << std::endl;
  std::cin >> newitemname1;
  std::cout << "how much of " << newitemname1 <<  " will be made?" << std::endl;
  std::cin >> newitemquantity1;
  storeItem(newitemname1, iname1, newitemquantity1, iquantity1, location1);
  std::cout << "press 12 to retrieve made items" << std::endl;
  std::cout << iquantity1[0] << std::endl;
  std::cout << iname1[0] << std::endl;
  std::cout << location1 << std::endl;
  std::cin >> yesorno;
  if(yesorno == 12)
  {
    for(int i = 0; i < location1; i++)
    {
      std::cout << iname1[i] << std::endl;
      std::cout << iquantity1[i] << std::endl;
    }
  
  }
  Authentication auth;
  auth.userID = user1;
  Buy b;
  std::cout << "enter username 1" << std::endl;
  std::cin >> user1; 
  std::cout << "enter a name for user 2" << std::endl;
  std::cin >> user2;
  std::cout << "want to see user 1 and user 2 balance? 0 for yes 1 for no" << std::endl;
  std::cin >> yesorno;
  if(yesorno == 0) 
  {
    std::cout << "user 1 balance: " << balance1 << " SafeCoin" << std::endl;
    std::cout << "user 2 balance: " << balance2 << " SafeCoin" << std::endl;
  }
  std::cout << "enter an item" << std::endl;
  std::cin >> buyitem;
  std::cout << "enter the quantity" << std::endl;
  std::cin >> buy1;
  std::cout << "enter the traded item" << std::endl;
  std::cin >> tradeitem;
  std::cout << "enter the quantity of the trade item" << std::endl;
  std::cin >> trade1;
  std::cout << b.plusplus(buy1, trade1);

  return 0;  
}
void storeItem(std::string userId, std::string itemName, std::string storename[], int quantity, int quantitystore[], int& locator)
{
storename[locator] = itemName;
quantitystore[locator] = quantity;
locator++;
}
void tradeItem(std::string useridentity, std::string itemSold, int itemSoldQuantity, std::string itemBought, int itemBoughtQuantity)
{
  std::cout << useridentity;

}
