#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void die()
{
	fprintf(stderr, "usage: decision arg1 [arg2 .. argn]\n");
	exit(1);
}

int main(int argc, char* argv[])
{
	if(argc<2)
	{
		die();
	}
	int random = time(0) % (argc-1)+1;

	printf("%s\n", argv[random]);

	return 0;
}

