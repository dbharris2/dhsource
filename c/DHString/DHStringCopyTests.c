#include <stdlib.h>

#include "CuTest.h"
#include "DHString.h"

void TestCopyWithNullString(CuTest *tc) {
  DHString *string = dhstring_new(NULL);
  void *actual = dhstring_copy(string);
  void *expected = NULL;
  CuAssertPtrEquals(tc, expected, actual);
}

void TestCopyWithEmptyString(CuTest *tc) {
  DHString *string = dhstring_new("");
  const char *actual = dhstring_to_array(dhstring_copy(string));
  const char *expected = "";
  CuAssertStrEquals(tc, expected, actual);
}

void TestCopyWithShortString(CuTest *tc) {
  DHString *string = dhstring_new("Hello world!");
  const char *actual = dhstring_to_array(dhstring_copy(string));
  const char *expected = "Hello world!";
  CuAssertStrEquals(tc, expected, actual);
}

CuSuite* DHStringCopyGetSuite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestCopyWithNullString);
  SUITE_ADD_TEST(suite, TestCopyWithEmptyString);
  SUITE_ADD_TEST(suite, TestCopyWithShortString);
  return suite;
}
