#ifndef LIB_TCT_H_
#define LIB_TCT_H_

#ifdef __cplusplus
extern "C" {
#endif

#define TCT_START_SIGN "{{"
#define TCT_END_SIGN "}}"
#define TCT_START_SIGN_LEN (sizeof(TCT_START_SIGN)-1)
#define TCT_END_SIGN_LEN (sizeof(TCT_END_SIGN)-1)

typedef struct _tct_arguments_t {
	struct _tct_arguments_t* next;
	char data[0];
} tct_arguments_t;

typedef struct _tct_section_t {
	char* data;
	size_t length;
	struct _tct_section_t* next;
} tct_section_t;

#define tct_get_value(a, n) tct_get_valuen(a, n, strlen(n))
#define tct_find_argument(a, n) tct_find_arguments(a, n, strlen(n))
#define tct_add_argument(a, ...) {a = tct_add_argument_(a, __VA_ARGS__);}

#ifdef __cplusplus
} // extern "C"
#endif

#endif