#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* 键值对 int->string */
typedef struct{
	int key;
	char *val;
} Pair;

/* 开放寻址哈希表 */
typedef struct{
	int size;			// 键对值数量
	int capacity;		// 哈希表扩容
	double loadThres;	// 触发扩容的负载因子阈值
	int extendRatio;	// 扩容倍数
	Pair **buckets;		// 桶数组 
	Pair *TOMBSTONE;	// 删除标记
} HashMapOpenAddressing;


void extend(HashMapOpenAddressing *hashMap);

/* 构造函数 */
HashMapOpenAddressing *newHashMapOpenAddressing()
{
	HashMapOpenAddressing *hashMap = (HashMapOpenAddressing*)malloc(sizeof(HashMapOpenAddressing));
	hashMap->size = 0;
	hashMap->capacity = 4;
	hashMap->loadThres = 2.0 / 3.0;
	hashMap->extendRatio = 2;
	hashMap->buckets = (Pair**)calloc(hashMap->capacity, sizeof(Pair*));
	hashMap->TOMBSTONE = (Pair*)malloc(sizeof(Pair));
	hashMap->TOMBSTONE->key = -1;
	hashMap->TOMBSTONE->val = "-1";

	return hashMap;
}

/* 析构函数 */
void delHashMapOpenAddressing(HashMapOpenAddressing *hashMap)
{
	for(int i = 0 ; i < hashMap->capacity; i++)
	{
		Pair *pair = hashMap->buckets[i];
		if(pair != NULL && pair != hashMap->TOMBSTONE)
		{
			free(pair->val);
			free(pair);
		}
	}
	free(hashMap->buckets);
	free(hashMap->TOMBSTONE);
	free(hashMap);
}

/* 哈希函数 */
int hashFunc(HashMapOpenAddressing *hashMap, int key)
{
	return key % hashMap->capacity;
}

/* 负载因子 */
double loadFactor(HashMapOpenAddressing *hashMap)
{
	return (double)hashMap->size / (double)hashMap->capacity;
}

/* 搜索key对应的桶索引 */
int findBucket(HashMapOpenAddressing *hashMap, int key)
{
	int index = hashFunc(hashMap, key);
	int firstTombstone = -1;
	// 线性探测，当遇到空桶时跳出
	while(hashMap->buckets[index] != NULL)
	{
		if(hashMap->buckets[index]->key == key)
		{
			if(firstTombstone != -1)
			{
				hashMap->buckets[firstTombstone] = hashMap->buckets[index];
				hashMap->buckets[index] = hashMap->TOMBSTONE;
				return firstTombstone;
			}
			return index;
		}

		// 当遇到首个懒删除的标记时
		if(firstTombstone == -1 && hashMap->buckets[index] == hashMap->TOMBSTONE)
		{
			firstTombstone = index;
		}

		// 计算桶索引，越过尾部则返回头部
		index = hashFunc(hashMap, index + 1);
	}

	// 若 key 不存在，则返回添加点的索引
	return firstTombstone == -1 ? index : firstTombstone;
}


/* 查询操作 */
char* get(HashMapOpenAddressing *hashMap, int key)
{
	// 搜索key对应的桶索引
	int index = findBucket(hashMap, key);
	// 若找到键值对，则返回对应val
	if(hashMap->buckets[index] != NULL && hashMap->buckets[index] != hashMap->TOMBSTONE)
	{
		return hashMap->buckets[index]->val;
	}
	
	// 返回空
	return NULL;
}

/* 添加操作 */
void put(HashMapOpenAddressing *hashMap, int key, char *val)
{
	// 当负载因子超过阈值时，执行扩容
	if(loadFactor(hashMap) > hashMap->loadThres)
	{
		extend(hashMap);
	}

	// 搜索key对应的桶索引
	int index = findBucket(hashMap, key);

	// 如果找到键值对，则覆盖val
	if(hashMap->buckets[index] != NULL && hashMap->buckets[index] != hashMap->TOMBSTONE)
	{
		free(hashMap->buckets[index]->val);
		hashMap->buckets[index]->val = (char*)malloc(sizeof(strlen(val) + 1));
		strcpy(hashMap->buckets[index]->val, val);
		/* 下面这句完全没有必要因为strcpy 的函数原先如下 
		char *strcpy（char *est，const char *src）
		{
			assert((dest!=NULL)&&(src!=NULL));
			char *address=dest;
			while((*dest++ = *src++)!='\0');//直到src字符串结束符'\0'
			return address;
		}
		* 自带尾零，所以不需要再复制\0；
		*/
		// hashMap->buckets[index]->val[strlen(val)] = '\0';
		return;
	}

	// 若键值对不存在，则添加该键值对
	Pair *pair = (Pair*)malloc(sizeof(Pair));
	pair->key = key;
	pair->val = (char*)malloc(sizeof(strlen(val) + 1));
	strcpy(pair->val, val);

	hashMap->buckets[index] = pair;
	hashMap->size++;
}

/* 删除操作 */
void removeItem(HashMapOpenAddressing *hashMap, int key)
{
	// 搜索 Key 对应的桶索引 
	int index = findBucket(hashMap, key);

	// 若找到键值对，则用删除标记覆盖它
	if(hashMap->buckets[index] != NULL && hashMap->buckets[index] != hashMap->TOMBSTONE)
	{
		Pair *pair = hashMap->buckets[index];
		free(pair->val);
		free(pair);
		hashMap->buckets[index] = hashMap->TOMBSTONE;
		hashMap->size--;
	}
}

/* 扩容哈希表 */
void extend(HashMapOpenAddressing *hashMap)
{
	// 暂存原哈希表
	Pair **bucketsTmp = hashMap->buckets;
	int oldCapacity = hashMap->capacity;

	// 初始化扩容后的新哈希表
	hashMap->capacity *= hashMap->extendRatio;
	hashMap->buckets = (Pair**)calloc(hashMap->capacity, sizeof(Pair*));
	hashMap->size = 0;

	// 将键值对从原哈希表搬运至新哈希表
	for(int i = 0 ; i < oldCapacity; i++)
	{
		Pair* pair = bucketsTmp[i];
		if(pair != NULL && pair != hashMap->TOMBSTONE)
		{
			put(hashMap, bucketsTmp[i]->key, bucketsTmp[i]->val);
			free(pair->val);
			free(pair);
		}
	}
	free(bucketsTmp);
}

/* 打印哈希表 */
void print(HashMapOpenAddressing *hashMap)
{
	for(int i = 0; i < hashMap->capacity; i++)
	{
		Pair *pair = hashMap->buckets[i];
		if(pair == NULL)
		{
			printf("NULL\n");
		}
		else if(pair == hashMap->TOMBSTONE)
		{
			printf("TOMBSTONE\n");
		}
		else 
		{
			printf("%d -> %s\n", pair->key, pair->val);
		}
	}

}










