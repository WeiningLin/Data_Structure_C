/* 基本操作 */

void init_list(pList L)
{
	/* 初始化：得到初始长度的空表 */
	
	L->data = (ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
	
	if ( !(L->data) )
	{
		printf("初始化失败！\n");
		exit(-1);	//终止整个程序
	}
	
	L->len = 0;
	L->maxSize = LIST_INIT_SIZE;
	
	return;
}

void add_maxSize(pList L)
{
	/* 扩展表的maxSize */
	/* realloc:指针名=（数据类型*）realloc（要改变内存大小的指针名，新的大小） */
	
	ElemType *newbase;
	newbase = (ElemType *)realloc(L->data, sizeof(ElemType)*(L->maxSize+LIST_INCREMENT));
	
	if ( !newbase )
	{
		printf("扩展失败！\n");
		exit(-1);
	}
	
	L->data = newbase;
	L->maxSize += LIST_INCREMENT;
	
	return;
}

int is_list_empty(List L)
{
	/* 判断表是否为空：空为真，非空为假 */
	
	if ( !L.len )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int find_elem(List L, ElemType e)
{
	/* 查找元素：返回元素下标，没找到返回-1 */
	
	int i;
	
	for (i=0; i<L.len; i++)
	{
		if ( L.data[i] == e )
		{
			return i;
		}
	}
	return -1;
}

void show_list_int(List L)
{
	/* 显示表的信息：偷懒，先假定ElemType为int */
	
	int i;
	
	if ( is_list_empty(L) )
	{
		printf("表为空！\n"); 
	}
	else
	{
		printf("len=%d\tmaxSize=%d\n", L.len, L.maxSize);
		for (i=0; i<L.len; i++)
		{
			printf("%d ", L.data[i]);
		}
		printf("\n");
	}
	
	return;
}

int insert_elem(pList L, int i, ElemType e)
{
	/* 插入元素：将元素e插入表的第i个位置处，i的范围为[1, len+1] */
	
	if (i<1 || i>(L->len)+1)
	{
		printf("位置不合法！\n");
		return 0;
	}
	
	if (L->len == L->maxSize)
	{
		add_maxSize(L);
	}
	
	int k;
	for (k=(L->len)-1; k>=i-1; k--)
	{
		L->data[k+1] = L->data[k];
	}
	L->data[i-1] = e;
	L->len ++;
	
	return 1;
}

int delete_elem(pList L, int i, ElemType *e)
{
	/* 删除元素：将元素e从表中第i个位置处删除，并返回e的值，i的范围为[1, len+1] */
	
	if ( is_list_empty(*L) )
	{
		printf("表为空，删除失败！\n");
		return 0;
	}
	
	if (i<1 || i>L->len)
	{
		printf("位置不合法！\n");
		return 0;
	}
	
	*e = L->data[i-1];	// ！ 
	int k;
	for (k=i-1; k<L->len; k++)
	{
		L->data[k] = L->data[k+1]; 
	}
	L->len --;
	return 1;
	
}
