#include "stdafx.h"
#include <string>

int f(int a) {
	if (a == 0)return NULL;
	int t = a % 2;
	a /= 2;
	f(a);
	printf("%d", t);
}
int main()
{
	f(100);
	std::getchar();
    return 0;
}

