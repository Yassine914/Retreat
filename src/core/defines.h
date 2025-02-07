#ifndef DEFINES_H
#define DEFINES_H

// unsigned int types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// typedef size_t usize;

// signed int types
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// floating point types
typedef float f32;
typedef double f64;

// for bit fields (accessing bit no. x)
#define BIT(x) (1 << x)

// define static assertions
#if defined(__clang__) || defined(__gcc__) || defined(__GNUC__)
    #define ST_ASSERT _Static_assert
#else
    #define ST_ASSERT static_assert
#endif

// platform detection

// windows
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
    #define IPLATFORM_WINDOWS 1
    #ifndef _WIN64
        #error "64-bit is required on windows."
    #endif
// linux
#elif defined(__linux__) || defined(__gnu_linux__)
    #define IPLATFORM_LINUX 1
#elif defined(__unix__)
    #define IPLATFORM_UNIX 1
#elif defined(__POSIX__)
    #define IPLATFORM_POSIX 1
// catch any other unsupported OS
#else
    #error "platform is not supported."
#endif

#endif // DEFINES_H