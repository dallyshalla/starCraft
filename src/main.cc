#include <iostream>
#include <string>
#include <vector>
//we need a program that could persistently store a username that could store:
//that person's created items, their acquired items in the form of names and quantities;
//They should also be able to store safeCoins, and Bitcoins in the form of importable private keys
//these keys will not persist beyond a session. only the private key balance will be used during
//a session; and the memory of the private key will not persist beyond an open session.
//Refactor Notes: Put menus into methods
//process activeUser;

std::string user[40000];
std::vector<std::string> users;
void createItem();
void menu(int&,std::vector<std::string>);
long long activeSelection;
int lol;
std::vector<int> row();
int main()
{
  int activeSelection2(0);
  std::string activeUser = "";
  std::vector<std::vector<int> > userdatas;
  activeSelection = 0;
  int answer = 100;
  int selection = 0;
  std::vector<int> itemName;
  std::vector<std::string> userNames;
  std::string user,user2, user1;
  std::vector<int> gainQ1, gainQ2, ownQ1, ownQ2;
  std::vector<std::string> gainN1, gainN2, ownN1, ownN2;
  
  do {
    menu(answer, userNames);
    if(answer == 1)
    {
      std::cout << "1. Add a username" << std::endl;
      std::cout << "2. Return each username" << std::endl;
      std::cin >> answer;
      if (answer == 1)
      {
        std::cout << "Enter desired name: " << std::endl << std::endl;
        std::cin >> user;
        userNames.push_back(user);

        std::cout << userNames.at(userNames.size()-1) << std::endl << " you are acknowledged, :)" << std::endl;
        answer = 100;
      }
      else if (answer == 2)
      {
        for(long index=0; index<(long)userNames.size(); ++index)
        {
          std::cout << userNames.at(index) << std::endl;
        }
        answer = 100;
      }
    }
    else if (answer == 2)
    {
      std::cout << "Select the active user" << std::endl;
      for(long index=0; index<(long)userNames.size(); ++index) {
        std::cout << "Username: " << index+1 << ". " << userNames.at(index) << std::endl;
      }
      std::cout << "Which one of the above are you?  . - input your number" << std::endl;
      do
      {
      std::cin >> activeSelection;
        if (activeSelection > userNames.size() || activeSelection < 0)
        {
          std::cout << "selection out of range" << std::endl;
          activeSelection = 0;
        }
      } while(activeSelection > userNames.size() || activeSelection <= 0);
      activeUser = userNames.at(activeSelection-1);
      std::cout << activeUser << std::endl;
    }
    else if (answer == 3)
    {
      std::cout << "Greetings " << activeUser << std::endl;
      std::cout << "1. Start Item Creation Process" << std::endl;
      std::cout << "2. Change active user" << std::endl;
      std::cout << "3. Add users" << std::endl;
      std::cout << "00. Exit ==- this one will exit the entire program -==" << std::endl;
      std::cin >> answer;
      if(answer == 1)
      {
        std::cout << activeUser << " You've started the item creation process" << std::endl;
      }
      if(answer == 2)
      {

      }
      if(answer == 3)
      {
      }
      // build out createItem();
    }
    
  } while(answer != 0);
  return 0;
}

void createItem(std::vector<std::vector<int> > quant1, std::vector<std::string> name1, std::string username)
{
    std::vector<int> row;
    makeRow(quant1);
    //quant1.push_back(name1.find(username), row);
}
void menu(int& selector, std::vector<std::string> userStore)
{
    std::cout << "Welcome to star Craft Version - Infinity" << std::endl;
    std::cout << "1. Set Usernames" << std::endl;
    if(userStore.size() > 0)
    {
        std::cout << "2. Select Active User" << std::endl;
        std::cout << "3. Create Item (use only if after 2 *this needs some more work*)" << std::endl;
    }
    std::cout << "00. Exit" << std::endl;
    std::cin >> selector;
}
