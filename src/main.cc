#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <istream>
#include <vector>
#include <ctime>
#include "../include/sha512.h"


int menu1(std::vector<std::string>&, int&, std::vector<std::vector<int > >&);
void menuSelectAlias(std::vector<std::string>&, int&, int&, int&);
void menuExit(int&);
void menuMakeItem(std::vector<std::string>&, int&, int&, int&, std::vector<std::vector<std::string> >&,
    std::vector<std::vector<std::string> >&, std::vector<std::vector<int > >&);
void menuSendCoin(std::vector<std::string>&, std::vector<std::vector<int > >&, int&, int&, int&);
void menuSellItem(std::vector<std::string>&, int&, int&, std::vector<std::vector<std::string > >&, std::vector<std::vector<std::string > >&,
    std::vector<std::vector<int > >&, std::vector<std::vector<int > >&, std::vector<std::vector<std::string > >&,
    std::vector<std::vector<std::string > >&, std::vector<std::vector<std::string > >&, std::vector<std::vector<int > >&);
void menuBuyItem(std::vector<std::string>&, int&, int&);


int main(int argc, char** argv)
{
    std::vector<std::vector<std::string> > starCoinHash;
    //sellItem storage;
    std::vector<std::vector<std::string> > storeSellItemIdentityHash;
    std::vector<std::vector<std::string> > sellItemVectorNames;
    std::vector<std::vector<std::string> > sellItemVectorDescriptions;
    std::vector<std::vector<int> > sellItemVectorQuantities;
    std::vector<std::vector<int> > sellItemVectorOwnerIndex;
    std::vector<std::vector<std::string> > sellItemVectorOwnerName;
    
    //starCoin storage;
    std::vector<std::vector<int > > starCoin;

    //createItem storage;
    std::vector<std::vector<std::string> > itemNameVector;
    std::vector<std::vector<std::string> > itemDescriptionVector;
    std::vector<std::vector<int> > itemQuantityVector;  
    
    //realtime variables storage
    std::string itemNameStorage;
    std::string itemDescriptionStorage;
    int itemQuantityStorage(0);

    //store the active alias
    int aliasIndex(-1);

    //user response storage
    int answer(1);

    int indexChoice(0);
    int& indexReference = aliasIndex;

    //alias storage
    std::vector<std::string> userAliasVector;

    //item attributes storage
    std::vector<std::vector<int> > itemStorageVector;
    do
    {
      if(answer == 1)
      {
        answer = menu1(userAliasVector, aliasIndex, starCoin);
      }
      if(answer == 3)
      {
        menuMakeItem(userAliasVector, answer, aliasIndex, indexChoice, itemNameVector, itemDescriptionVector,
              itemQuantityVector);
      }
      if(answer == 2)
      {
        menuSelectAlias(userAliasVector, answer, aliasIndex, indexChoice);
      }
      if(answer == 4)
      {
        menuSendCoin(userAliasVector, starCoin, answer, indexChoice, aliasIndex);
      }
      if(answer == 5)
      {
          for(long long i=0; i<(long)starCoin.size(); ++i)
          {
            if(starCoin[i][0] == aliasIndex)
            {
              std::cout << " " << userAliasVector.at(aliasIndex) << " you have " << starCoin[i][1] << " starCoins " << std::endl;
              answer = 1;
            }
          }
      }
      if(answer == 6)
      {
        menuSellItem(userAliasVector, answer, aliasIndex, sellItemVectorNames, sellItemVectorDescriptions,
            sellItemVectorQuantities, sellItemVectorOwnerIndex, sellItemVectorOwnerName, itemNameVector, itemDescriptionVector,
            itemQuantityVector);
      }
      if(answer == 7)
      {
        answer = 1;
      }
      if(answer == 0)
      {
        menuExit(answer);
      }
      /*if(*indexPointer > -1)
      {
        menuMakeItem(userAliasVector, answer, aliasIndex, indexChoice);
      }*/
      std::cout << std::endl;
      if(aliasIndex > -1)
      {
        std::cout << aliasIndex << " " << userAliasVector.at(aliasIndex) << " is the active alias" << std::endl;
      }
      if(answer > 7)
      {
        answer = 1;
      }
    } while(answer != 0);

      return 0;
}

int menu1(std::vector<std::string>& aliasVector, int& isAlias, std::vector<std::vector<int > >& starCoins)
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
    if(aliasVector.size() > 0 && isAlias == -1)
    {
      std::cout << " 1. add alias " << std::endl;
      std::cout << " 2. select active alias " << std::endl;
      std::cout << " 0. exit " << std::endl;
      std::cin >> answer;
    }
    if(aliasVector.size() > 0 && isAlias > -1)
    {
      std::cout << " 1. add alias " << std::endl;
      std::cout << " 2. select active alias " << std::endl;
      std::cout << " 3. make an item on behalf of " << aliasVector[isAlias] << std::endl;
      std::cout << " 4. send starCoins " << std::endl;
      std::cout << " 5. check starCoin balance " << std::endl;
      std::cout << " 6. sell items " << std::endl;
      std::cout << " 7. buy items " << std::endl;
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
      {
        aliasVector.push_back(storeName);
        std::vector<int> rowForCoins;
        rowForCoins.push_back(aliasVector.size()-1);
        rowForCoins.push_back(10000);
        starCoins.push_back(rowForCoins);

        //security
        time_t t = time(0);
        std::cout << t << std::endl;
        std::vector<std::string> hashRowForCoins;
        int intNumber = aliasVector.size()-1+t;
        std::ostringstream ostr;
        ostr << intNumber;
        std::string intString = ostr.str();
        std::cout << storeName;
        std::string hashName;
        hashName = sha512(intString);
        hashRowForCoins.push_back(hashName);
        
      }
    }
    return answer;
}

void menuSelectAlias(std::vector<std::string>& aliasVector, int& answer, int& aliasIndex, int& indexchoice)
{
  long long checks;
  std::string stringChoice;
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
      if(aliasIndex > -1)
      {
        std::cout << " 4. view active alias " << std::endl;
      }
      std::cout << " 5. return to Main Menu " << std::endl;
      std::cout << " 6. choose acting alias " << std::endl;
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
      if(answer == 4)
      {
        std::cout << " selected alias is: " << aliasVector.at(aliasIndex) << std::endl;
        answer = 1;
      }
      if(answer == 5)
      {
        answer = 1;
      }
      if(answer == 6)
      {
        do
        {
          std::cout << " enter the number corresponding with the desired alias " << std::endl;
          std::getline(std::cin, stringChoice);
          if(choice > aliasVector.size() - 1)
          {
              std::cout << " your choice of " << choice << " is out of range " << std::endl;
              is = 1;
          }
          else
          {
              std::cout << " you have chosen " << aliasVector.at(choice) << " is this correct" << std::endl;
              std::cout << " type 'yes' or 'no' " << std::endl;
              std::cin >> stringAnswer;
              if(stringAnswer == "yes") aliasIndex = choice;
              else is = 1;
          }
        } while(is == 10);
        answer = 1;
      }
    }
}

void menuMakeItem(std::vector<std::string>& aliasVector, int& answer, int& aliasIndex, int& indexchoice,
    std::vector<std::vector<std::string> >& pushItemName, std::vector<std::vector<std::string> >& pushItemDescription,
    std::vector<std::vector<int> >& pushItemQuantity)
{
  std::string itemName;
  std::string itemDescription;
  std::string textAnswer;
  long long itemQuantity(0);
  if(answer == 3)
  {
    std::cout << " " << aliasVector.at(aliasIndex) << " welcome, you've arrived at Make Item " << std::endl;
    std::cout << " 1. start item creation " << std::endl;
    std::cout << " 2. list items owned by LL: " << aliasVector.at(aliasIndex) << std::endl;
    std::cout << " 3. store this item " << std::endl;
    std::cout << " 5. go home " << std::endl;
    std::cin >> answer;
    if(answer == 1)
    {
        std::cout << " we will need some standard input " << std::endl;
        std::cout << " please enter the name of your item " << std::endl;
        std::getline(std::cin,itemName);
        std::getline(std::cin,itemName);
        std::cout << " we have your item name, now we need how many quantities of that item you have " << std::endl;
        std::cin >> itemQuantity;
        std::cout << " great, now place a brief 100 letter description about your software " << std::endl;
        std::getline(std::cin,itemDescription);
        std::getline(std::cin,itemDescription);
        do
        {
          std::cout << " your item is " << itemName << " with a quantity of " << itemQuantity << " " << std::endl;
          std::cout << " described as: " << itemDescription << std::endl;
          std::cout << " if this is correct type 'yes' of not type 'no'" <<std::endl;
          std::cin >> textAnswer;
          if(textAnswer == "yes")
          {
            std::vector<std::string> stringNameStorage;
            stringNameStorage.push_back(aliasVector.at(aliasIndex));
            stringNameStorage.push_back(itemName);
            pushItemName.push_back(stringNameStorage);
            std::vector<std::string> stringDescriptionStorage;
            stringDescriptionStorage.push_back(aliasVector.at(aliasIndex));
            stringDescriptionStorage.push_back(itemDescription);
            pushItemDescription.push_back(stringDescriptionStorage);
            std::vector<int> intQuantityStorage;
            intQuantityStorage.push_back(aliasIndex);
            intQuantityStorage.push_back(itemQuantity);
            pushItemQuantity.push_back(intQuantityStorage);
            //store in a row aliasVector + itemName
            //then push that into the itemNameVector 
            //pushItemQuantity[aliasIndex].push_back(itemQuantity);
            //pushItemDescription[aliasIndex].push_back(itemDescription);
          }
        } while(textAnswer != "yes"); 
    }
    if(answer == 2)
    {
        for(long long i=0; i<(long)pushItemName.size(); ++i)
        {
          std::string storeActiveAlias = aliasVector.at(aliasIndex);
          std::string storeItemNaming = pushItemName[i][0];
            if(storeItemNaming == storeActiveAlias)
            {
              std::cout << std::endl;
              std::cout << " LL: Name: " << pushItemName[i][1] << " LL: Quantity: " << pushItemQuantity[i][1] << std::endl;
            }
        }
        answer = 3;
    }
    if(answer == 5)
    {
        answer = 1;
    }
  }
}

void menuSendCoin(std::vector<std::string>& aliasVector, std::vector<std::vector<int > >& starCoins, int& answer, int&
    indexchoice, int& aliasIndex)
{
    std::string stringAnswer = " ";
    int sendAmount(0);
    int chosenAlias(0);
    int enoughFunds(-1);
    std::cout << " welcome to send starCoin menu " << std::endl;
    std::cout << " 1. view your trusted alias's list and index number " << std::endl;
    std::cout << " 2. send starCoin to known alias by index number " << std::endl;
    std::cin >> answer;
    if(answer == 1)
    {
      std::cout << std::endl;
      for(long long i=0; i<(long)aliasVector.size(); ++i)
      {
        std::cout << i << " LL: " << aliasVector.at(i) << std::endl;
      }
    }
    std::cout << std::endl;
    if(answer == 2)
    {
      do
      {
        std::cout << std::endl;
        std::cout << " which index alias will you send starCoins to  " << std::endl;
        std::cin >> chosenAlias;
        std::cout << " send coins to " << aliasVector.at(chosenAlias) << " ? " << std::endl;
        std::cout << " enter 'yes' or 'no' " << std::endl;
        std::cin >> stringAnswer;
      } while(stringAnswer != "yes");
      stringAnswer = " ";
      do
      {
        std::cout << " how many starCoins will you send to " << aliasVector.at(chosenAlias) << std::endl;
        std::cin >> sendAmount;
        std::cout << " sending " << sendAmount << " " << aliasVector.at(chosenAlias) << std::endl;
        std::cout << " enter 'yes' if this correct or enter 'no' if this is incorrect " << std::endl;
        std::cin >> stringAnswer;
        if(stringAnswer == "yes")
        {
          std::cout << " sending " << sendAmount << " " << aliasVector.at(chosenAlias) << std::endl;
          for(long long i=0; i<(long)starCoins.size(); ++i)
          {
            if(starCoins[i][0] == aliasIndex)
            {
              int holder = sendAmount - 1;
              if(starCoins[i][1] < holder)
              {
                std::cout << " not enough balance to make this transaction, you have " << starCoins[i][1] <<
                  std::endl;
              }
              else
              {
                starCoins[i][1] -= sendAmount;
                for(long long j=0; j<(long)starCoins.size(); ++j)
                {
                  if(starCoins[j][0] == chosenAlias)
                  {
                    starCoins[j][1] += sendAmount;
                  }
                }
              }
            }
          }
        }
      } while(stringAnswer != "yes");
      answer = 1;
    }
}
//store each new instance of an item sale into a new spot on the vector. 
void menuSellItem(std::vector<std::string>& aliasVector, int& answer, int& aliasindex, std::vector<std::vector<std::string > >& sellListItemNames,
    std::vector<std::vector<std::string > >& sellListtItemDescription, std::vector<std::vector<int > >& sellListItemQuantities, std::vector<std::vector<int > >&
    sellListItemOwnerIndex, std::vector<std::vector<std::string > >& sellListItemOwnerName, std::vector<std::vector<std::string > >& ownedItemName, std::vector<std::vector<std::string > >& ownedItemDescription,
    std::vector<std::vector<int > >& ownedItemQuantity)
{
  int selectedItem(-1);
  int itemQuantityStore(-1);
  std::string itemNameStore;
  std::string itemDescriptionStore;
  std::string itemOwnerNameStore;
  int localAnswer(0);
  std::cout << " 1. list items owned by you " << aliasVector.at(aliasindex) << std::endl;
  std::cout << " 2. search item list by name " << std::endl;
  std::cout << " 3. search item list by description " << std::endl;
  std::cout << " 4. select an item to sell by index from list " << std::endl;
  std::cout << " 5. start item creation process " << std::endl;
  std::cout << " 6. exit Item Creation Menu " << std::endl;
  std::cin >> localAnswer;
  switch(localAnswer)
  {
    case 1:
     for(long long i=0; i<(long)ownedItemName.size(); ++i)
      {
        if(ownedItemName[i][0] == aliasVector.at(aliasindex))
        {
          std::cout << "index# LL: " << i << " LL: " << ownedItemQuantity[i][1] << " LL: " << ownedItemName[i][1] << " LL: " << ownedItemDescription[i][1] << std::endl;
        }
      }
      break;
    case 4:
      std::cout << " enter the index for the item " << std::endl;
      std::cin >> selectedItem;
      itemQuantityStore = ownedItemQuantity[selectedItem][1];
      answer = 1;
      break;
    case 5:
      answer = 3;
      break;
    case 6:
      answer = 1;
      break;
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
