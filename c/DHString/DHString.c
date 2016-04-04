#import "DHString.h"

#import <stdbool.h>
#import <stdlib.h>
#import <string.h>

struct _DHString {
  char *characters;
  unsigned int size;
};

// Private API

bool _string_is_null(DHString *string) {
  return string == NULL || string->characters == NULL;
}


// Public API

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
