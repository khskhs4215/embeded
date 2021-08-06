#include <stdio.h>

void fileCopy(char * src, char * des)
{
	FILE * read = fopen(src, "rb");
	FILE * write = fopen(des, "wb");
	FILE * error = NULL;
	char buffer[1024];
	int counting;
	
	if(read == NULL || write == NULL) {
		error = fopen("error.txt", "wt");
		fputs("파일을 읽거나 생성할 수 없습니다.\n", error);
		if (error != NULL) fclose(error);
		return;
	}
	
	while(1) {
		counting = fread(buffer, sizeof(char), sizeof(buffer), read);
		if(counting < sizeof(buffer)) {
			  fwrite(buffer, sizeof(char), counting, write);
			  break;
		} else {
			fwrite(buffer, sizeof(char), sizeof(buffer), write);
		}

	}
	if (read != NULL) fclose(read);
	if (write != NULL) fclose(write);
}

int main(void)
{
	fileCopy("dog.mp4", "dog_copy.mp4");
	return 0;
}

