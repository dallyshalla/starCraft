#include <iostream>
#include <string>
#include <vector>
//we need a program that could persistently store a username that could store:
//that person's created items, their acquired items in the form of names and quantities;
//They should also be able to store safeCoins, and Bitcoins in the form of importable private keys
//these keys will not persist beyond a session. only the private key balance will be used during
//a session; and the memory of the private key will not persist beyond an open session.

std::string user[40000];
std::vector<std::string> users;
void increaseInt(int&);
void menu(int&);
int lol;

int main()
{
  int answer = 100;
  int selection = 0;
  std::vector<std::string> userNames;
  std::string user,user2, user1;
  std::vector<int> gainQ1, gainQ2, ownQ1, ownQ2;
  std::vector<std::string> gainN1, gainN2, ownN1, ownN2;
  
  do {
    menu(answer);
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
      /*else if (answer == 2)
      {
        std::cout << "Enter user2's name" << std::endl;
        std::cin >> user2;
        std::cout << user2 << " :user2's name" << std::endl;
        answer = 100;
      }*/
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
        std::cout << "Username: " << index << ". " << userNames.at(index) << std::endl;
      }
    }
     
    
  } while(answer != 0);

 /* 
  for(;;)
  {
    std::cout << "Welcome to star Craft Version - Infinity" << std::endl;
    std::cout << "1. Set usernames" << std::endl;
  
    std::cin >> answer;

    if((answer<1 || answer>1)&& answer!= 27)
    {
      switch(answer) {
        case 1:
          increaseInt(lol);
          break;
        case 27:
          return 0;
      }
    }

      else {
        std::cout << "Invalid";
        continue;
    }
  }
  
  // the menu
  while(answer != 00) {
      std::cout << "Welcome to star Craft Version. Infinity" << std::endl;
      std::cout << "1. Set usernames" << std::endl;

      do {
        std::cin >> answer;
      } while((answer<1 || answer>1)&&answer!=27); //esc=ASCII 27
      
      switch(answer) {
      
        case 1:
          break;
        
        default:
          std::cout << "Bad Option"<< std::endl; //Well it will never execute!
          break ;
      }

    } */
  increaseInt(lol);

  return 0;
}
void menu(int& selector)
{
    std::cout << "Welcome to star Craft Version - Infinity" << std::endl;
    std::cout << "1. Set Usernames" << std::endl;
    std::cout << "2. Select Active User" << std::endl;
    std::cout << "00. Exit" << std::endl;
    std::cin >> selector;
}


void increaseInt(int& wlol) {
  wlol++;
  std::cout << wlol << std::endl;
}
