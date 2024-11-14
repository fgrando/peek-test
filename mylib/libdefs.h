#ifndef LIBDEFS_H_
#define LIBDEFS_H_

#ifdef _cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

// TODO: add for other compiles as well...
#define DLL_PUBLIC __attribute__((visibility("default")))

#endif