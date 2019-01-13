// What is the value of the local variable x at the end of main?
/*
 * The local x in main hides the global x before the local x's initializer is considered.
 * Therefore the local x is being initialized with itself (the local unitialized variable)
 */
#include<stdio.h>
int x = 5;
int main(int argc, char** argv)
{
	int x = x;
	printf("%d", x);
	return 0;
}
// x is thus, undefined

