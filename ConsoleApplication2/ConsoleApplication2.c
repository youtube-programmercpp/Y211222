#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE* const fp = fopen("..\\8316.txt", "r");
	if (fp) {
		char s1[64];
		char s2[64];
		char s3[64];
		char s4[64];
		char s5[64];
		char s6[64];
		char s7[64];
		while (fscanf(fp, "%s%s%s%s%s%s%s", s1, s2, s3, s4, s5, s6, s7) == 7) {
			printf("%s, %s, %s, %s, %s, %s, %s\n", s1, s2, s3, s4, s5, s6, s7);
		}
		fclose(fp);
	}
}
