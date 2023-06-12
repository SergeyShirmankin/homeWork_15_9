#include "chat.h"
#include "iostream"
#include "string.h"

Chat::Chat() {
	data_count = 0;
}
void Chat::reg(char _login[LOGINLENGTH], char _pass[], int pass_length)
{
	uint* pass_sha1_hash = sha1(_pass, pass_length);
	data[data_count] = AuthData(_login, pass_sha1_hash);
	data_count++;
}
bool Chat::login(char _login[LOGINLENGTH], char _pass[], int pass_length)
{
	uint* pass_sha1_hash = sha1(_pass, pass_length);
	bool is_Equal = false;
	for (int i = 0; i < data_count; i++)
	{
		if (_login && strcmp(data[i].login, _login) == 0)
		{
			for (int a = 0; a < 5; a++)
			{
				if (pass_sha1_hash[a] == data[i].pass_sha1_hash[a])
					is_Equal = true;
				else
					is_Equal = false;
				a++;
			}
			if (is_Equal)
			{
				return true;
			}
		}

		//	delete[] pass_sha1_hash;
	}
	return false;
}
