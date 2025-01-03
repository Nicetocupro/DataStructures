#include<stdio.h>
#include<stdlib.h>
#define MODULUS 1000000007

/* 加法哈希 */
int addHash(char *key)
{
	long long hash = 0;
	for(int i = 0; i < strlen(key); i++)
	{
		hash = (hash + (unsigned char)key[i]) % MODULUS;
	}
	return (int)hash;
}

/* 乘法哈希 */
int mulHash(char* key)
{
	long long hash = 0;
	for(int i = 0; i < strlen(key); i++)
	{
		hash = (31 * hash + (unsigned char)key[i]) % MODULUS;
	}
	return (int)hash;
}

/* 异或哈希 */
int xorHash(char *key)
{
	int hash = 0;

	for(int i = 0; i < strlen(key); i++)
	{
		hash ^= (unsigned char)key[i];
	}

	return hash & MODULUS;
}

/* 旋转哈希 */
int rotHash(char *key)
{
	long long hash = 0;
	for(int i = 0; i < strlen(key); i++)
	{
		hash = ((hash << 4) ^ (hash >> 28) ^ (unsigned char)key[i]) % MODULUS;
	}

	return (int)hash;
}
