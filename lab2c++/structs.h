#include <time.h>
typedef  enum { male, female, undefined } gender;

struct customer {
    char lastName[30];
    gender gend;
    tm birthday;
    int numOfStaff;
};