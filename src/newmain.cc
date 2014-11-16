#include <iostream>
#include <string>
#include <vector>
#include "../include/sha512.h"


int menu1(std::vector<std::string>&);
void menuSelectAlias(std::vector<std::string>&, int&, int&, int&);
void menuExit(int&);
void menuMakeItem(std::vector<std::string>&, int&, int&, int&);

int main(int argc, char** argv)
{
    int aliasIndex(-1);
    int answer(1);
    int indexChoice(0);
    std::vector<std::string> userAliasVector;
    std::vector<std::vector<int> > itemStorageVector;
    do
    {
      if(answer == 1)
      {
        answer = menu1(userAliasVector);
      }
      if(answer == 2)
      {
        menuSelectAlias(userAliasVector, answer, aliasIndex, indexChoice);
      }
      if(answer == 0)
      {
        menuExit(answer);
      }
      if(aliasIndex > -1)
      {
        menuMakeItem(userAliasVector, answer, aliasIndex, indexChoice);
      }
      std::cout << aliasIndex;
    } while(answer != 0);

      return 0;
}

int menu1(std::vector<std::string>& aliasVector)
{
    int answer(0);
    long long checks(0);
    std::string stringAnswer;
    std::string storeName;
    if(aliasVector.size() == 0)
    {
      std::cout << " 1. add an alias " << std::endl;
      std::cout << " 0. exit " << std::endl;
      std::cin >> answer;
    }
    if(aliasVector.size() > 0)
    {
      std::cout << " 1. add alias " << std::endl;
      std::cout << " 2. select active alias " << std::endl;
      std::cout << " 0. exit " << std::endl;
      std::cin >> answer;
    }
    if(answer == 1)
    {
      std::cout << " enter the name of the alias " << std::endl;
      std::cin >> storeName;
      for(long long i=0; i<(long)aliasVector.size(); ++i)
      {
        if(storeName != aliasVector.at(i)) { checks++; }
      }
      if(checks != aliasVector.size())
      {
        std::cout << " this alias has already been made " << std::endl;
      }
      else 
      aliasVector.push_back(storeName);
    }
    return answer;
}

void menuSelectAlias(std::vector<std::string>& aliasVector, int& answer, int& aliasIndex, int& indexchoice)
{
  long long checks;
  std::string stringAnswer;
  std::string storeName;
  long long choice(0);
  int is(0);
    if(answer == 2)
    {
      std::cout << " select an alias " << std::endl;
      std::cout << " 1. search " << std::endl;
      std::cout << " 2. list each alias " << std::endl;
      std::cout << " 3. make new alias " << std::endl;
      std::cout << " 4. view active alias " << std::endl;
      std::cout << " 5. go home " << std::endl;
      std::cout << " 91. set alias index " << std::endl;
      std::cout << " 0. exit program " << std::endl;
      std::cin >> answer;
      if(answer == 1)
      {
        std::cout << " search for a specific name " << std::endl;
        std::cin >> stringAnswer;
        for(long long i = 0; i<(long)aliasVector.size(); ++i)
        {
          answer = 22;
          if(aliasVector.at(i) == stringAnswer)
          {
            std::cout << std::endl;
            std::cout << " alias found " << std::endl;
            std::cout << i << " " << aliasVector.at(i) << std::endl;
            answer = 2;
            i = aliasVector.size();
          }
        }
        if(answer == 22)
        {
          std::cout << " alias not found " << std::endl;
          answer = 2;
        }
      }
      if(answer == 2)
      {
        for(long long i=0; i<(long)aliasVector.size(); ++i)
        {
          std::cout << i << " " << aliasVector.at(i) << std::endl;
        }
      }
      if(answer == 3)
      { 
        std::cout << " enter the name of the alias " << std::endl;
        std::cin >> storeName;
        for(long long i=0; i<(long)aliasVector.size(); ++i)
        {
          if(storeName != aliasVector.at(i)) { checks++; }
        }
        if(checks != aliasVector.size())
        {
          std::cout << " this alias has already been made " << std::endl;
          answer = 2;
        }
        else 
        {
          aliasVector.push_back(storeName);
          std::cout << " " << storeName << " you are ackowledged " << std::endl;
        }
      }
      if(answer == 5)
      {
        answer = 1;
      }
      if(answer == 91)
      {
        do
        {
          std::cout << " enter the number corresponding with the desired alias " << std::endl;
          std::cin >> choice;
          std::cout << " you have chosen " << aliasVector.at(choice) << " is this correct" << std::endl;
          std::cout << " type 'yes' or 'no' " << std::endl;
          std::cin >> stringAnswer;
          if(stringAnswer == "yes") aliasIndex = choice;
          else is = 1;
        } while(is == 10);
        answer = 1;
      }
    }
}

void menuMakeItem(std::vector<std::string>& aliasVector, int& answer, int& aliasIndex, int& indexchoice)
{
  if(answer == 11)
  {
    std::cout << " " << aliasVector.at(aliasIndex) << " welcome, you've arrived at Make Item " << std::endl;
    std::cout << " 1. start item creation " << std::endl;
    std::cout << " 2. view status of current item " << std::endl;
    std::cout << " 3. store this item " << std::endl;
    std::cout << " 5. go home " << std::endl;
    std::cin >> answer;
  }
}
void menuExit(int& answer)
{
  if(answer == 0)
  {
    std::cout << " you are about to exit, type 0 to confirm type 1 to cancel exiting " << std::endl;
    std::cin >> answer;
    if(answer == 0)
    {
      std::cout << " have a nice day " << std::endl;
    }
    else
      answer = 1;
  }
}
