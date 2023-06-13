#include "chat.h"
Chat::Chat() {
	// ��������� ������, �������������
	mem_size = 8;
	chain_tops = new ChainNode * [mem_size];
	for (int i = 0; i < mem_size; i++) {
		chain_tops[i] = nullptr;
	}
	count = 0;
}
Chat::~Chat() {
	// ��������� �� �����
	for (int i = 0; i < mem_size; i++)
		if (chain_tops[i] != nullptr)
			delete chain_tops[i];
	delete[] chain_tops;
}
int Chat::hash_func(char login[LOGINLENGTH]){
	// ��������� ������
	int sum = 0, i = 0;
	for (; i < strlen(login); i++) {
		sum += login[i];
	}
	// ����� �������
	return sum % mem_size; // �������� ����� ����� ����� 0 � memsize
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
		/* ���� ������ � ����� �������� ��� ����, ��
          ������� ����� ���� � ������ ��� ������� */
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
	// �������� �������, ���� ����� ��������� ������
	// ������� � ����������
	//if (count / mem_size > 3)
	//	resize();
	int index = hash_func(_login); // ��������� ������ � �������
	if (chain_tops[index] != nullptr) {
		int a = 1;
		/* ���� ������ � ����� �������� ��� ����, ��
		������� ����� ���� � ������ ��� ������� */
		//	ChainNode* newNode = new ChainNode(_login, _password);/*
		/*	newNode->next = chain_tops[index];
			chain_tops[index] = newNode;*/
	}
	else {
		// ���� ��� ������� � ����� �����
		//ChainNode* newNode = new ChainNode(_login, _password);
		chain_tops[index] = new ChainNode(_login, _password);
	}
	count++;
}