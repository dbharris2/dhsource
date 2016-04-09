#include "DHString.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct _DHString {
  char *characters;
  unsigned int size;
};

// Private API

bool _string_is_null(DHString *string) {
  return string == NULL || string->characters == NULL;
}

bool _string_is_null_or_empty(DHString *string) {
  return _string_is_null(string) || strlen(string->characters) == 0;
}

unsigned int _string_length(DHString *string) {
  if (_string_is_null_or_empty(string)) {
    return 0;
  } else {
    return strlen(string->characters);
  }
}

const char _string_char_at(DHString *string, const unsigned int index) {
  if (_string_is_null_or_empty(string)) {
    return '\0';
  } else {
    return string->characters[index];
  }
}

// Public API

bool dhstring_contains(DHString *string, DHString *otherString) {
  if (_string_is_null_or_empty(string) || _string_is_null_or_empty(otherString)) {
    return false;
  } else {
    const unsigned int stringLength = _string_length(string);
    const unsigned int otherStringLength = _string_length(otherString);

    if (stringLength < otherStringLength) {
      return false;
    } else {
      int stringIndex;
      for (stringIndex = 0; stringIndex < stringLength; stringIndex++) {
        int otherStringIndex = 0;
        if (_string_char_at(string, stringIndex) == _string_char_at(otherString, otherStringIndex)) {
          int tempStringIndex = stringIndex;
          for (otherStringIndex = 0; otherStringIndex < otherStringLength; otherStringIndex++) {
            if (_string_char_at(string, tempStringIndex) == _string_char_at(otherString, otherStringIndex)) {
              tempStringIndex++;
            } else {
              break;
            }
          }
          if (otherStringIndex == otherStringLength) {
            return true;
          }
        }
      }
    }
    return false;
  }
}

DHString *dhstring_copy(DHString *string) {
  if (string == NULL) {
    return NULL;
  } else {
    return dhstring_new(string->characters);
  }
}

void dhstring_free(DHString *string) {
  free(string);
}

DHString *dhstring_new(const char *string) {
  if (string == NULL) {
    return NULL;
  } else {
    const unsigned int size = strlen(string);
    DHString *dhstring = malloc(sizeof(DHString));
    dhstring->characters = malloc(sizeof(char) * size);
    strcpy(dhstring->characters, string);
    dhstring->size = size;
    return dhstring;
  }
}

void dhstring_reverse_in_place(DHString *string)
{
  if (!_string_is_null(string)) {
    char *characters = string->characters;
    const unsigned int size = string->size;
    int i;
    for (i = 0; i < dhstring_size(string)/2; i++) {
      const char temp = characters[size-i-1];
      characters[size-i-1] = characters[i];
      characters[i] = temp;
    }
  }
}

unsigned int dhstring_size(DHString *string) {
  if (_string_is_null(string)) {
    return 0;
  } else {
    return strlen(string->characters);
  }
}

const char *dhstring_to_array(DHString *string) {
  if (_string_is_null(string)) {
    return NULL;
  } else {
    return string->characters;
  }
}
