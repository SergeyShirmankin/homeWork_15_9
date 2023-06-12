#include "hash_table.h"

void HashTable::del(FruitName fr_name) {
	int index = hash_func(fr_name);
	ChainNode* top = chain_tops[index];
	ChainNode* prev = nullptr;
	while (top != nullptr) {
		if (!strcmp(fr_name, top->fruit_name))
		{
			if (prev != nullptr)
			{
				prev->next = top->next;
			}
			else
			{
				chain_tops[index] = top->next;
			}
			delete top;
			count--;
			break;
		}
		prev = top;
		top = top->next;

	}
}
int HashTable::find(FruitName fr_name)
{
	int index = hash_func(fr_name);
	ChainNode* top = chain_tops[index];
	while (top != nullptr) 
	{
		if (!strcmp(fr_name, top->fruit_name))
			return top->fruit_count;
		top = top->next;
	}
	return -1;
}
