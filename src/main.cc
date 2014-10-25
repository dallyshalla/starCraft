#include <iostream>
#include <string>
#include <vector>
//we need a program that could persistently store a username that could store:
//that person's created items, their acquired items in the form of names and quantities;
//They should also be able to store safeCoins, and Bitcoins in the form of importable private keys
//these keys will not persist beyond a session. only the private key balance will be used during
//a session; and the memory of the private key will not persist beyond an open session.
std::string userName(std::string);
std::string user[40000];
std::vector<std::string> users;
void increaseInt(int&);
int lol;

int main()
{
  increaseInt(lol);
  std::cout << userName("hello") << std::endl;

  return 0;
}
std::string userName(std::string user) {

  return user;
}

void increaseInt(int& wlol) {
  wlol++;
  std::cout << wlol << std::endl;
}
