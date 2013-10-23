#if !defined(DATATYPES_H)
#define DATATYPES_H

typedef unsigned char uint8;
typedef char int8;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned int uint32;
typedef int int32;
typedef unsigned long long uint64;
typedef long long int64;
typedef float float32;
typedef double float64;
typedef int HANDLE;

#if defined(_TMS320C6X)
typedef unsigned long uint40;
typedef long int40;
#endif

#endif
