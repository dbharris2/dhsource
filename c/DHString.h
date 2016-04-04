struct _DHString;
typedef struct _DHString DHString;

void dhstring_free(DHString *string);
DHString *dhstring_new(const char *string);
unsigned int dhstring_size(DHString *string);
