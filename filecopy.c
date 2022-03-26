#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	/* check for correct arguments */
	if (argc < 4) {
		printf("The required args: ./filecopy.c <destination1> <destination2> <sourcefile>\n");
	}

	char *destfile1 = argv[1];
	char *destfile2 = argv[2];
	char *srcfile = argv[3];

	FILE *source = fopen(srcfile, "r");

	if (!source) {
		printf("Unable to open file %s for reading", srcfile);
		return 1;
	}

	FILE *dest1 = fopen(destfile1, "w");
	FILE *dest2 = fopen(destfile2, "w");
	if (!dest1) {
		printf("Error opening %s for writing", destfile1);
		return 1;
	}
	if (!dest2) {
		printf("Error opening %s for writing", destfile2);
		return 1;
	}

	char buffer[512];
	int size  = fread(buffer, 1, 1024, source);
	while (size > 0) {
		fwrite(buffer, sizeof(char), strlen(buffer), dest1);
		fwrite(buffer, sizeof(char), strlen(buffer), dest2);
		size = fread(buffer, 1, 1024, source);
	}
	fclose(source);
	fclose(dest1);
	fclose(dest2);
	return 0;
}

