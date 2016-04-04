#import "DHString.h"

#import <stdlib.h>
#import <string.h>

struct _DHString {
  char *characters;
  int size;
};

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

unsigned int dhstring_size(DHString *string) {
  if (string == NULL || string->characters == NULL) {
    return 0;
  } else {
    return strlen(string->characters);
  }
}
