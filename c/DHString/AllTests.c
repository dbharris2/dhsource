#include <stdio.h>

#include "CuTest.h"

CuSuite* DHStringCopyGetSuite();
CuSuite* DHStringReverseGetSuite();
CuSuite* DHStringSizeGetSuite();

void RunAllTests(void) {
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();

  CuSuiteAddSuite(suite, DHStringCopyGetSuite());
	CuSuiteAddSuite(suite, DHStringReverseGetSuite());
	CuSuiteAddSuite(suite, DHStringSizeGetSuite());

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}

int main(void) {
	RunAllTests();
}
