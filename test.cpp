#include <string>
#include <iomanip>
#include <iostream>
#include "sha1.h"
#include "chat.h"
#include "hash_table.h"
void  myTest() 
{
	Chat myChat;

	char us1[] = "user1";
	char ps1[] = "qwerty12345";
	myChat.reg(us1, ps1, 12);

	char us2[] = "user2";
	char ps2[] = "asdfg";
	myChat.reg(us2, ps2, 6);

	char us3[] = "user3";
	char ps3[] = "zsdrt";
	myChat.reg(us3, ps3, 6);

	char us4[] = "us";
	char ps4[] = "zsdrt";

	bool test1 = myChat.login(us1, ps1, 12);
	bool test2 = myChat.login(us4, ps4, 3);
	//	Throw text : in test() chechsize*/

	HashTable ht;

	ht.add((char*)"str1", 10);
	ht.add((char*)"str2", 15);
	ht.add((char*)"str3", 2);
	ht.add((char*)"str4", 6);
	ht.add((char*)"str5", 7);
	ht.add((char*)"str6", 4);
	ht.add((char*)"str7", 9);

	int	res1 = ht.find((char*)"str1");
	int	res2 = ht.find((char*)"str2");
	int	res3 = ht.find((char*)"str3");
	int	res4 = ht.find((char*)"str4");
	int	res5 = ht.find((char*)"str5");
	int	res6 = ht.find((char*)"str6");
	int	res7 = ht.find((char*)"str7");
	int	res8 = ht.find((char*)"st");


	ht.del((char*)"str4");
	ht.del((char*)"str5");
	ht.del((char*)"str6");

	int	res11 = ht.find((char*)"str1");
	int	res12 = ht.find((char*)"str2");
	int	res13 = ht.find((char*)"str3");
	int	res14 = ht.find((char*)"str4");
	int	res15 = ht.find((char*)"str5");
	int	res16 = ht.find((char*)"str6");
	int	res17 = ht.find((char*)"str7");

}