#define _VARIADIC_MAX 10

#if defined(__GNUC__)
    // #pragma GCC diagnostic ignored "-Weffc++"
    // #pragma GCC diagnostic ignored "-Wundef"
    // #pragma GCC diagnostic ignored "-Wpadded"
    // #pragma GCC diagnostic ignored "-Wmissing-noreturn"
	#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#if defined(__clang__)
    // #pragma clang diagnostic ignored "-Wweak-vtables"
    // #pragma clang diagnostic ignored "-Wglobal-constructors"
    // #pragma clang diagnostic ignored "-Wused-but-marked-unused"
    // #pragma clang diagnostic ignored "-Wshift-sign-overflow"
    // #pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
    #pragma clang diagnostic ignored "-Wunused-const-variable"
#endif
