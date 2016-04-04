struct _DHString;
typedef struct _DHString DHString;

DHString *dhstring_copy(DHString *string);
void dhstring_free(DHString *string);
DHString *dhstring_new(const char *string);
void dhstring_reverse_in_place(DHString *string);
unsigned int dhstring_size(DHString *string);
const char *dhstring_to_array(DHString *string);
