#include "chat.h"
Chat::Chat() {
	// выделение памяти, инициализация
	mem_size = 8;
	chain_tops = new ChainNode * [mem_size];
	for (int i = 0; i < mem_size; i++) {
		chain_tops[i] = nullptr;
	}
	count = 0;
}
Chat::~Chat() {
	// прибираем за собой
	for (int i = 0; i < mem_size; i++)
		if (chain_tops[i] != nullptr)
			delete chain_tops[i];
	delete[] chain_tops;
}
int Chat::hash_func(char login[LOGINLENGTH]){
	// вычисляем индекс
	int sum = 0, i = 0;
	for (; i < strlen(login); i++) {
		sum += login[i];
	}
	// метод деления
	return sum % mem_size; // значение точно будет между 0 и memsize
}
uint* Chat::mySha1(char _pass[], int pass_length)
{
	uint* sha1HashPassord = sha1(_pass, pass_length);
	return sha1HashPassord;
}
void Chat::reg(char _login[LOGINLENGTH], char _pass[], int pass_length)
{
	uint* pass_sha1_hash = sha1(_pass, pass_length);
	int index = hash_func(_login);
	if (chain_tops[index] != nullptr) {
		/* если цепока с таким индексом уже есть, то
          создаем новый узел и делаем его верхним */
   	ChainNode* newNode = new ChainNode(_login, pass_sha1_hash);
 	newNode->next = chain_tops[index];
	chain_tops[index] = newNode;
	}
	else {
		chain_tops[index] = new ChainNode(_login, pass_sha1_hash);
	}
	count++;
}
void  Chat::add(char _login[LOGINLENGTH], uint* _password)
{
	// пересчет таблицы, если много элементов внутри
	// боремся с коллизиями
	//if (count / mem_size > 3)
	//	resize();
	int index = hash_func(_login); // вычислили индекс в массиве
	if (chain_tops[index] != nullptr) {
		int a = 1;
		/* если цепока с таким индексом уже есть, то
		создаем новый узел и делаем его верхним */
		//	ChainNode* newNode = new ChainNode(_login, _password);/*
		/*	newNode->next = chain_tops[index];
			chain_tops[index] = newNode;*/
	}
	else {
		// если нет цепочки с таким хешем
		//ChainNode* newNode = new ChainNode(_login, _password);
		chain_tops[index] = new ChainNode(_login, _password);
	}
	count++;
}