#include <stdio.h>
#include <stdlib.h>

char* my_strcpy(char* dest, const char* src){
	char* original_dest = dest;
	
	while(*src != '\0'){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return original_dest;
}

int main(){
	
	const char* src = "hello world!";
	char* dest = (char*)malloc(strlen(src)+1);
	my_strcpy(dest, src);
	
	printf("dest = %s", dest);
	free(dest);
	
	return 0;
}