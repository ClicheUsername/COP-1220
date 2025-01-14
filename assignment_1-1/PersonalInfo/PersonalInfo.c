#include <stdio.h>

void PrintPersonalInfo(char* name, char* dob, char* work, char* cell) {
	printf("%s\n", name);
	printf("%s\n", dob);
	printf("work %s\n", work);
	printf("cell %s\n", cell);
	printf("\n");

	return;
}

int main(void) {
	printf("Unit Test 1:\n");
	PrintPersonalInfo("Lucinda Potter", "6/24/1992", "000-000-0101", "000-000-0189");

	printf("Unit Test 2:\n");
	PrintPersonalInfo("John Smith", "8/15/1978", "000-111-0101", "000-111-0189");

	printf("Unit Test 3:\n");
	PrintPersonalInfo("Chris Johnson", "8/15/1978", "000-222-0101", "000-222-0189");

	printf("Unit Test 4:\n");
	PrintPersonalInfo("Robert Hall", "2/27/1949", "000-444-0101", "000-444-0189");

	return 0;
}
