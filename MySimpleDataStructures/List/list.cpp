#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
 * 需要注意，因为C语言没有列表相关的数据结构，因此这里使用C++语言的vector
 */
void printNums(vector<int> nums)
{
	for(int i = 0; i < nums.size(); i++)
	{
		printf("访问元素vector[%d]:%d\n", i, nums[i]);
	}
	return;
}

int main()
{
	// 初始化操作
	// 无初始值
	vector<int> nums0;
	// 有初始值
	vector<int> nums = {1, 3, 2, 5, 4};

	// 访问元素
	printNums(nums);

	// 更新元素
	nums[1] = 0;
	printf("更新元素后\n");
	printNums(nums);

	// 清空列表
	nums.clear();
	printf("列表清空操作\n");
	printNums(nums);

	// 在尾部添加元素
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(4);
	printf("尾部添加元素之后\n");
	printNums(nums);

	// 在中间插入元素
	nums.insert(nums.begin() + 3, 6);
	printf("中间插入元素之后\n");
	printNums(nums);

	// 删除元素之后
	nums.erase(nums.begin() + 3);
	printf("删除元素之后\n");
	printNums(nums);

	// 遍历列表
	printf("遍历列表\n");
	int i = 0;
	for(int num : nums)
	{
		printf("访问元素vector[%d]:%d\n", i, num);
		i++;
	}

	// 拼接列表操作
	vector<int> nums1 = {6, 8, 7, 10, 9};

	nums.insert(nums.end(), nums1.begin(), nums1.end());
	printf("拼接操作之后\n");
	printNums(nums);

	// 排序操作
	sort(nums.begin(), nums.end());
	printf("排序操作之后\n");
	printNums(nums);


	return 0;
}




