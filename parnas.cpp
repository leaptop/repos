#include <stdio.h>
struct st {
	int data;
};
int main()
{
	struct st s00;
	s00.data = 7;
	printf("%d\n", s00.data);
	struct st* s01;
	s01 = &s00;
	printf("hi\n");
	printf("%d\n", s01->data);

	return 0;
}