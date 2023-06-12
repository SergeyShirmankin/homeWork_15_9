#include "hash_table.h"

HashTable::HashTable() {
	// ��������� ������, �������������
	mem_size = 8;
	chain_tops = new ChainNode * [mem_size];
	for (int i = 0; i < mem_size; i++) {
		chain_tops[i] = nullptr;
	}
	count = 0;
}
HashTable::~HashTable() {
	// ��������� �� �����
	for (int i = 0; i < mem_size; i++)
		if (chain_tops[i] != nullptr)
			delete chain_tops[i];
	delete[] chain_tops;
}
int HashTable::hash_func(FruitName fr_name) {
	// ��������� ������
	int sum = 0, i = 0;
	for (; i < strlen(fr_name); i++) {
		sum += fr_name[i];
	}
	// ����� �������
	return sum % mem_size; // �������� ����� ����� ����� 0 � memsize
}
void HashTable::add(FruitName fr_name, int fr_count) {
	// �������� �������, ���� ����� ��������� ������
	// ������� � ����������
	if (count / mem_size > 3)
		resize();
	int index = hash_func(fr_name); // ��������� ������ � �������
	if (chain_tops[index] != nullptr) {
		/* ���� ������ � ����� �������� ��� ����, ��
		������� ����� ���� � ������ ��� ������� */
		ChainNode* newNode = new ChainNode(fr_name, fr_count);
		newNode->next = chain_tops[index];
		chain_tops[index] = newNode;
	}
	else {
		// ���� ��� ������� � ����� �����
		chain_tops[index] = new ChainNode(fr_name, fr_count);
	}
	count++;
}

void HashTable::resize() {
	ChainNode** save_ct = chain_tops; // ���������� ������ ������
	int oldSize = mem_size;

	mem_size *= 2;  // ����������� ������ � ��� ����  
	count = 0; // �������� ���������� ���������
	chain_tops = new ChainNode * [mem_size]; // �������� ����� ������
	for (int i = 0; i < mem_size; i++) {
		chain_tops[i] = nullptr;
	}

	for (int i = 0; i < oldSize; i++) {
		ChainNode* current = save_ct[i];
		while (current != nullptr) {
			// ������������� ���� � ��������� � ����� ������
			add(current->fruit_name, current->fruit_count);
			current = current->next;
		}
		// ������ �� �����
		delete current;
	}
	// ������ �� �����
	delete[] save_ct;
}