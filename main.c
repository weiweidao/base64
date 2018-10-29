#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "base64.h"

static void
test(unsigned char *encode, unsigned int encodelen,
     char *decode, unsigned int decodelen)
{
	char *encode_out;
	unsigned char *decode_out;

	encode_out = malloc(BASE64_ENCODE_OUT_SIZE(encodelen));
	decode_out = malloc(BASE64_DECODE_OUT_SIZE(decodelen));
	assert(encode_out);
	assert(decode_out);

	assert(base64_encode(encode, encodelen, encode_out) == decodelen);
	
	
	
	assert(memcmp(encode_out, decode, decodelen) == 0);
	assert(base64_decode(decode, decodelen, decode_out) == encodelen);
	assert(memcmp(decode_out, encode, encodelen) == 0);

	free(encode_out);
	free(decode_out);
}

int main(void)
{
	int i=0;
	char *encodeString_in="Man";
	char *decodeString_in="TWFu";
	
	char *encodeString_out = user_base64_encode(encodeString_in,strlen(encodeString_in));
	
	printf("encodeString_in [%s] \tencodeString_out [%s]\n  strlen=%d\n",encodeString_in,encodeString_out,(unsigned int)strlen(encodeString_out));

	
	free(encodeString_out);
	
	
	unsigned char* decodeString_out= user_base64_decode(decodeString_in,strlen(decodeString_in));
	
	printf("decodeString_in [%s] \tdecodeString_out [%s]\n",decodeString_in,decodeString_out);
	free(decodeString_out);
/*	
	test((void *)"", 0, "", 0);
	test((void *)"f", 1, "Zg==", 4);
	test((void *)"fo", 2, "Zm8=", 4);
	test((void *)"foo", 3, "Zm9v", 4);
	test((void *)"foob", 4, "Zm9vYg==", 8);
	test((void *)"fooba", 5, "Zm9vYmE=", 8);
	test((void *)"foobar", 6, "Zm9vYmFy", 8);
*/
	return 0;
}
