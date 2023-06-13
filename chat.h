#pragma once
#pragma warning(disable : 4996)
#include "sha1.h"
#include "string.h"
#define SIZE 10
#define LOGINLENGTH 10
#define NAMELENGTH 10  // Зафикируем длину имени
typedef unsigned int uint;
class Chat 
{
public:
	Chat();
	~Chat();
	void reg(char _login[LOGINLENGTH], char _pass[], int pass_length);
	bool login(char _login[LOGINLENGTH], char _pass[], int pass_length);
	uint* mySha1(char _pass[], int pass_length);
	void add(char _login[LOGINLENGTH], uint* _password);
private:
	struct ChainNode
	{ // узел в цепочке
		ChainNode() :
			login(""),//ключ
			pass_sha1_hash(0) {//хеш пароль
		}
		ChainNode* next; // указатель на следующий узел в цепочке
		ChainNode(char _login[LOGINLENGTH], uint* sh1)
		{
			strcpy(login, _login);
			pass_sha1_hash = sh1;
			next = nullptr;
		}
		~ChainNode() {
			// удаляем друг за дружкой
			if (pass_sha1_hash != 0)
				delete[] pass_sha1_hash;
		}
		ChainNode& operator = (const ChainNode & other)
		{
			strcpy(login, other.login);

			if (pass_sha1_hash != 0)
				delete[] pass_sha1_hash;
			pass_sha1_hash = new uint[SHA1HASHLENGTHUINTS];

			memcpy(pass_sha1_hash, other.pass_sha1_hash, SHA1HASHLENGTHBYTES);

			return *this;
		}
		char login[LOGINLENGTH];
		uint* pass_sha1_hash;
	};
	// хеш-функция для поиска индекса цепочки
	int hash_func(char login[LOGINLENGTH]);
	ChainNode** chain_tops; // массив указателей на цепочки
	int mem_size; // количество выделенной памяти
	int count; // колиество добавленных пар ключ-значение
	//
	/*ChainNode data[SIZE];*/
	//int data_count;
};