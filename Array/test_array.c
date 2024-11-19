#include"array.c"

int main()
{
	// 初始化数组操作
	int arr[5] = { 0 };
	int nums[5] = { 1 , 3 , 2 , 5 , 4 };
	int sizeNum = sizeof(nums) / sizeof(nums[0]);

	// 打印数组中各元素 
	printNums(nums, sizeNum);

	// 随机访问数组元素
	printf("随机访问数组nums：%d\n", randomAccess(nums, sizeof(nums) / sizeof(nums[0])));

	int insertNum = 12;
	int insertIndex = 3;
	// 插入某个元素
	printf("在nums[%d]处插入元素%d\n", insertIndex, insertNum);
	insert(nums, sizeNum, insertNum, insertIndex);
	printNums(nums, sizeNum);

	// 删除某个元素
	int removeIndex = 2;
	printf("删除nums[%d]处的元素\n", removeIndex);
	removeItem(nums, sizeNum, removeIndex);
	printNums(nums, sizeNum);

	// 查找元素
	int findNum1 = 3;
	int findNum2 = 17;
	printf("查找元素%d\n", findNum1);
	printf("查找元素索引%d\n", find(nums, sizeNum, findNum1));

	
	printf("查找元素%d\n", findNum2);
	printf("查找元素索引%d\n", find(nums, sizeNum, findNum2));
	
	// 数组扩容操作
	int enlarge = 5;
	int *ptr = nums;
	ptr = extend(ptr, sizeNum, enlarge);
	sizeNum += enlarge;
	printf("将nums扩展%d位\n", enlarge);
	printNums(ptr, sizeNum);

	return 0;
}

