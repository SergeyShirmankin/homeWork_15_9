#include <string>
#include <iomanip>
#include <iostream>
#include "sha1.h"
#include "chat.h"

int main()
{
	//myTest();
    Chat myChat;
	char us1[] = "user1";
	char ps1[] = "qwerty12345";

 //   uint* pResult = myChat.mySha1(ps1, sizeof(ps1) - 1);
	//for (int i = 0; i < 5; i++) {
	//	std::cout << std::hex << std::setw(8) << std::setfill('0') << pResult[i] << " ";
	//}
	myChat.reg(us1, ps1, sizeof(ps1) - 1);

	return 0;
}