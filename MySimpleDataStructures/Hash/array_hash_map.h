#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1000

/* 键值对 int->string */
typedef struct{
	int key;
	char *val;
} Pair;

/* 基于数组实现的哈希表 */
typedef struct{
	Pair *buckets[MAX_SIZE];
	int capacity;
} ArrayHashMap;

typedef struct{
	void *set;
	int len;
} MapSet;

/* Hash函数 */
int hashFunc(ArrayHashMap *hmap, int key)
{
	return key % hmap->capacity;
}

/* 构造函数 */
ArrayHashMap *newArrayHashMap()
{
	ArrayHashMap *hmap = (ArrayHashMap *)malloc(sizeof(ArrayHashMap));
	for(int i = 0 ; i < MAX_SIZE; i++)
	{
		hmap->buckets[i] = NULL;
	}

	hmap->capacity = MAX_SIZE;
	return hmap;
}

/* 析构函数 */
void delArrayHashMap(ArrayHashMap *hmap)
{
	for(int i = 0 ; i < hmap->capacity; i++)
	{
		if(hmap->buckets[i] != NULL)
		{
			free(hmap->buckets[i]->val);
			free(hmap->buckets[i]);
		}
	}
	free(hmap);
}

/* 添加操作 */
void put(ArrayHashMap *hmap, const int key, const char *val)
{
	Pair *pair = (Pair *)malloc(sizeof(Pair));
	pair->key = key;
	pair->val = (char*)malloc(strlen(val) + 1);

	strcpy(pair->val, val);

	int index = hashFunc(hmap, key);
	hmap->buckets[key] = pair;
}

/* 删除操作 */
void removeItem(ArrayHashMap *hmap, const int key)
{
	int index = hashFunc(hmap, key);
	Pair *Pair = hmap->buckets[index];
	if(Pair == NULL)
	{
		return;
	}
	hmap->buckets[index] = NULL;

	free(Pair->val);
	free(Pair);
}

/* 获取所有键值对 */
void pairSet(ArrayHashMap *hmap, MapSet *set)
{
	Pair *entries;
	int i = 0, index = 0, total = 0;

	/* 统计有效的键值对数量 */
	for(int i = 0; i < hmap->capacity; i++)
	{
		if(hmap->buckets[i] != NULL)
		{
			total++;
		}
	}
	entries = (Pair*)malloc(total * sizeof(Pair));
	for(int i = 0; i < hmap->capacity; i++)
	{
		if(hmap->buckets[i] != NULL)
		{
			entries[index].key = hmap->buckets[i]->key;
			entries[index].val = (char*)malloc(strlen(hmap->buckets[i]->val) + 1);
			strcpy(entries[index].val, hmap->buckets[i]->val);
			index++;
		}
	}
	set->set = entries;
	set->len = total;
}

/* 获取所有键 */
void keySet(ArrayHashMap *hmap, MapSet *set)
{
	int *keys;
	int i = 0, index = 0;
	int total = 0;
	
	/* 统计有效的键值对数量 */
	for(int i = 0; i < hmap->capacity; i++)
	{
		if(hmap->buckets[i] != NULL)
		{
			total++;
		}
	}
	keys = (int*)malloc(total * sizeof(int));

	for(int i = 0; i < hmap->capacity; i++)
	{
		if(hmap->buckets[i] != NULL)
		{
			keys[index] = hmap->buckets[i]->key;
			index++;
		}
	}
	set->set = keys;
	set->len = total;
}

/* 获取所有值 */
void valueSet(ArrayHashMap *hmap, MapSet *set)
{
	char **vals;
	int i = 0, index = 0, total = 0;

	/* 统计有效的键*/
	for(int i = 0; i < hmap->capacity; i++)
	{
		if(hmap->buckets[i] != NULL)
		{
			total++;
		}
	}
	vals = (char**)malloc(total * sizeof(char*));

	for(int i = 0; i < hmap->capacity; i++)
	{
		if(hmap->buckets[i] != NULL)
		{
			vals[index] = hmap->buckets[i]->val;
			index++;
		}
	}
	set->set = vals;
	set->len = total;
}

/* 打印哈希表 */
void print(ArrayHashMap *hmap)
{
	int i;
	MapSet set;
	pairSet(hmap, &set);
	Pair *entries = (Pair*)set.set;

	for(int i = 0; i < set.len; i++)
	{
		printf("%d -> %s\n", entries[i].key, entries[i].val);
		free(entries[i].val);
	}
	free(set.set);
}

