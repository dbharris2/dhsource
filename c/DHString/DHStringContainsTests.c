#include <stdbool.h>
#include <stdlib.h>

#include "CuTest.h"
#include "DHString.h"

void TestContainsWithNullString(CuTest *tc) {
  DHString *string = dhstring_new(NULL);
  DHString *otherString = dhstring_new(NULL);

  bool actual = dhstring_contains(string, otherString);
  bool expected = false;
  CuAssertIntEquals(tc, expected, actual);

  string = dhstring_new("test");
  otherString = dhstring_new(NULL);

  actual = dhstring_contains(string, otherString);
  expected = false;
  CuAssertIntEquals(tc, expected, actual);

  string = dhstring_new(NULL);
  otherString = dhstring_new("test");

  actual = dhstring_contains(string, otherString);
  expected = false;
  CuAssertIntEquals(tc, expected, actual);
}

void TestContainsWithEmptyString(CuTest *tc) {
  DHString *string = dhstring_new("");
  DHString *otherString = dhstring_new("");

  bool actual = dhstring_contains(string, otherString);
  bool expected = false;
  CuAssertIntEquals(tc, expected, actual);

  string = dhstring_new("test");
  otherString = dhstring_new("");

  actual = dhstring_contains(string, otherString);
  expected = false;
  CuAssertIntEquals(tc, expected, actual);

  string = dhstring_new("");
  otherString = dhstring_new("test");

  actual = dhstring_contains(string, otherString);
  expected = false;
  CuAssertIntEquals(tc, expected, actual);
}

void TestContainsWithShortString(CuTest *tc) {
  DHString *string = dhstring_new("racecars");
  DHString *otherString = dhstring_new("car");

  bool actual = dhstring_contains(string, otherString);
  bool expected = true;
  CuAssertIntEquals(tc, expected, actual);

  string = dhstring_new("racecars");
  otherString = dhstring_new("cart");

  actual = dhstring_contains(string, otherString);
  expected = false;
  CuAssertIntEquals(tc, expected, actual);

  string = dhstring_new("racecars");
  otherString = dhstring_new("so_many_racecars");

  actual = dhstring_contains(string, otherString);
  expected = false;
  CuAssertIntEquals(tc, expected, actual);
}

CuSuite* DHStringContainsGetSuite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, TestContainsWithNullString);
  SUITE_ADD_TEST(suite, TestContainsWithEmptyString);
  SUITE_ADD_TEST(suite, TestContainsWithShortString);
  return suite;
}
