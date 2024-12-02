#include"linked_list.c"

int main()
{
	// 初始化节点
	ListNode* n0 = newListNode(1);
	ListNode* n1 = newListNode(3);
	ListNode* n2 = newListNode(2);
	ListNode* n3 = newListNode(5);
	ListNode* n4 = newListNode(4);
	
	// 构建节点之间的引用
	n0->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	// 打印链表，观察链表的值
	printLinkedList(n0);

	printf("在链表插入节点\n\n");
	ListNode *p1 = newListNode(10);
	ListNode *p2 = newListNode(17);

	insert(n1, p1);
	insert(p1, p2);
	printLinkedList(n0);
	
	printf("将上述插入节点进行删除\n\n");
	removeItem(p1);
	removeItem(n1);
	printLinkedList(n0);

	printf("查询上述节点\n");
	ListNode *p = (ListNode*)malloc(sizeof(ListNode));
	printf("p 地址: %p\n", (void*)p);
	if (p == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	printf("节点分配成功\n");
	p->val = 0;
	printf("节点值初始化成功\n");
	p->next = NULL;
	printf("节点 next 指针初始化成功\n");


	p = access(n0, 0);
	printf("查询第0个节点：%d\n", p->val);
	p = access(n0, 1);
	printf("查询第1个节点：%d\n", p->val);
	p = access(n0, 2);
	printf("查询第2个节点：%d\n", p->val);
	p = access(n0, 3);
	printf("查询第3个节点：%d\n", p->val);
	p = access(n0, 4);
	printf("查询第4个节点：%d\n", p->val);
	p = access(n0, 5);
	if(p == NULL)
	{
		printf("第五个节点不存在\n\n");
	}
	else
	{
		printf("查询第5个节点：%d\n\n", p->val);
	}

	printf("查找值为3的节点：%d\n", find(n0, 3));
	printf("查找值为5的节点：%d\n", find(n0, 5));
	printf("查找值为10的节点：%d\n", find(n0, 10));



	return 0;
}

