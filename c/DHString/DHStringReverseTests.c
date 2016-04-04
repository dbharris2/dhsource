#include <stdlib.h>

#include "CuTest.h"
#include "DHString.h"

void TestReverseWithNullString(CuTest *tc) {
  DHString *string = dhstring_new(NULL);
  void *actual = string;
  void *expected = NULL;
  CuAssertPtrEquals(tc, expected, actual);
}

void TestReverseWithEmptyString(CuTest *tc) {
  DHString *string = dhstring_new("");
  dhstring_reverse_in_place(string);
  const char *actual = dhstring_to_array(string);
  const char *expected = "";
  CuAssertStrEquals(tc, expected, actual);
}

void TestReverseWithShortString(CuTest *tc) {
  DHString *string = dhstring_new("Hello world!");
  dhstring_reverse_in_place(string);
  const char *actual = dhstring_to_array(string);
  const char *expected = "!dlrow olleH";
  CuAssertStrEquals(tc, expected, actual);
}

CuSuite* DHStringReverseGetSuite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestReverseWithNullString);
  SUITE_ADD_TEST(suite, TestReverseWithEmptyString);
  SUITE_ADD_TEST(suite, TestReverseWithShortString);
  return suite;
}
