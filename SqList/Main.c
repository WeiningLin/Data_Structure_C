#include "../head.h"
typedef int ElemType;
#include "structureDef.h"
#include "function.c"

int main ()
{
	List L;
	int i;
	ElemType e;
	
	init_list(&L);
	show_list_int(L);
	
	for (i=0; i<L.maxSize; i++)
	{
		insert_elem(&L, i+1, i);
	}
	show_list_int(L);
	
	insert_elem(&L, L.maxSize+2, i);
	
	insert_elem(&L, L.maxSize+1, i);
	show_list_int(L);
	
	delete_elem(&L, 5, &e);
	printf("被删除的是%d\n", e);
	show_list_int(L);
	
	return 0;
}
