#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(__APPLE__)
#  define COMMON_DIGEST_FOR_OPENSSL
#include <CommonCrypto/CommonDigest.h>
#  define SHA1 CC_SHA1
#else
#include <openssl/md5.h>
#endif

int main() 
{
    int n;
    unsigned char digest[16];
    char *password = "test123";
    int length = strlen(password);
    //char strlen;

    char *out = (char *) malloc(30);
    MD5_CTX c;
    MD5_Init(&c);

    while (length > 0) {
        if (length > 512) {
            MD5_Update(&c, password, 512);
        } else {
            MD5_Update(&c, password, length);
        }
        length -= 512;
        password += 512;

    }

    MD5_Final(digest, &c);

    for (n = 0; n < 16; ++n) {
        snprintf(&(out[n*2]), 16*2, "%02x", (unsigned int)digest[n]);
    }
    printf("%s\n", out);

    char *pass = out;
    printf("pass : %s\n", pass);
    
return 0;
}
