#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <openssl/evp.h>

void die()
{
	fprintf(stderr, "usage: decision [--digest md4|md5|sha|ripemd] arg1 [arg2 .. argn]\n");
	exit(1);
}

int main(int argc, char* argv[])
{
	if(argc<2) {
		die();
	}
	srand(time(0));
	int base = 1;
	if(strcmp(argv[1], "--digest") == 0) {
		if(argc<4) {
			die();
		}
		base+=2;
		EVP_MD_CTX mdctx;
		const EVP_MD *md;
		unsigned char md_value[EVP_MAX_MD_SIZE];
		unsigned int md_len;
		OpenSSL_add_all_digests();

		md = EVP_get_digestbyname(argv[2]);
		if( !md ) {
			fprintf(stderr, "digest not recognised\n");
			die();
		}

		EVP_MD_CTX_init(&mdctx);
		EVP_DigestInit_ex(&mdctx, md, NULL);
		for(unsigned i=3; i<argc; i++) {
			EVP_DigestUpdate(&mdctx, argv[i], strlen(argv[i]));
		}
		EVP_DigestFinal_ex(&mdctx, md_value, &md_len);
		EVP_MD_CTX_cleanup(&mdctx);
		unsigned int init = *((unsigned int*)md_value);
		srand(init);
	}
	
	int random = rand() % (argc-base)+base;

	printf("%s\n", argv[random]);

	return 0;
}

