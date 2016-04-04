#include <stdlib.h>

#include "CuTest.h"
#include "DHString.h"

void TestSizeWithNullString(CuTest *tc) {
  DHString *string = dhstring_new(NULL);
  void *actual = string;
  void *expected = NULL;
  CuAssertPtrEquals(tc, expected, actual);
  dhstring_free(string);
}

void TestSizeWithEmptyString(CuTest *tc) {
  DHString *string = dhstring_new("");
  const unsigned int actual = dhstring_size(string);
  const unsigned int expected = 0;
  CuAssertIntEquals(tc, expected, actual);
}

void TestSizeWithShortString(CuTest *tc) {
  DHString *string = dhstring_new("Hello world!");
  const unsigned int actual = dhstring_size(string);
  const unsigned int expected = 12;
  CuAssertIntEquals(tc, expected, actual);
}

CuSuite* DHStringSizeGetSuite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestSizeWithNullString);
  SUITE_ADD_TEST(suite, TestSizeWithEmptyString);
  SUITE_ADD_TEST(suite, TestSizeWithShortString);
  return suite;
}
