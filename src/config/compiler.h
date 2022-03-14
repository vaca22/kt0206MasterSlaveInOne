/**
 ****************************************************************************************
 *
 * @file gnuarm/compiler.h
 *
 * @brief Definitions of compiler specific directives.
 *
 * @author WeighSong
 *
 *
 * Copyright (C), 2017 - 2018, KT Micro,Inc.
 *
 ****************************************************************************************
 */

#ifndef _COMPILER_H_
#define _COMPILER_H_


// Please put the defines shared by makefile projects and AndeSight projects

#define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

// GCC < 4.8.2 (Before BSP400 gcc version)
// Check the GCC version for toolchain builtin macro compatible issue.
#if GCC_VERSION < 40802

#ifdef NDS32_BASELINE_V3
#define __NDS32_ISA_V3__	NDS32_BASELINE_V3
#endif

#ifdef NDS32_BASELINE_V3M
#define __NDS32_ISA_V3M__	NDS32_BASELINE_V3M
#endif

#endif

// Chkeck whether the following intrinsic functions are supported by toolchain.
// Some intrinsic functions are not supported by old toolchain and need to be wrapped.
#ifndef __ASSEMBLER__

#include <nds32_intrinsic.h>

#ifndef __nds32__mtsr_isb
#define __nds32__mtsr_isb(val, srname)  \
do {__nds32__mtsr(val, srname);__nds32__isb();} while(0)
#endif

#ifndef __nds32__mtsr_dsb
#define __nds32__mtsr_dsb(val, srname)	\
do {__nds32__mtsr(val, srname);__nds32__dsb();} while(0)
#endif

#endif

#ifndef	CFG_MAKEFILE

// The defines are only used by AndeSight projects

//----------------------------------------------------------------------------------------------------

// Users can configure the defines in this area
// to match different environment setting

// Platform select : AG101P / AE210P / AG102
//#define	CFG_AG102		// platform is AG102
//#define	CFG_AE210P		// platform is AE210P
#define	CFG_AG101P		// platform is AG101P

// Address mode select
//#define	CFG_16MB		// platform is 16MB, if it isn't defined, platform is 4GB

// Support ZOL select			// do ZOL supporting when CPU supports ZOL
#define	CFG_HWZOL

// Code coverage select
//#define	CFG_GCOV		// do code coverage support

// Simulation environment select
//#define	CFG_SIMU		// do simulation on SID

// Build mode select
// The BUILD_MODE can be specified to BUILD_XIP/BUILD_BURN/BUILD_LOAD only.
//
// NOTE: The BUILD_SIMU is not supported any more. Please uncomment CFG_SIMU
//       to select simulation environment.
#define BUILD_MODE	BUILD_XIP	// NOTE: AE210P support BUILD_XIP only


//----------------------------------------------------------------------------------------------------
// The followings are predefined settings
// Please do not modify them

#define	BUILD_LOAD	1		// The program is loaded by GDB or eBIOS
#define	BUILD_BURN	2		// The program is burned to the flash, but run in RAM
							// demo-ls2 use BURN mode
#define	BUILD_XIP	3		// The program is burned to the flash and run in the flash
							// To use this mode, xip linker script files must be used
							// demo-ls1 use XIP mode

#undef BUILD_MODE
#define BUILD_MODE	BUILD_XIP


#ifndef __NDS32_EXT_EX9__
	// This toolchain cannot support EX9
	#define CONFIG_NO_NDS32_EXT_EX9
#endif

#if BUILD_MODE == BUILD_BURN
	// Burn mode
	#define CFG_LLINIT      // do low level init
	#define CFG_REMAP       // do remap
#elif BUILD_MODE == BUILD_XIP
	// XIP mode
	#define CFG_LLINIT      // do low level init
#else
	// Load mode
#endif

#ifdef __NDS32_ISA_V3M__
	// v3m toolchain only support 16MB
	#undef CFG_16MB
	#define CFG_16MB
#endif

// Platform configure check
#ifdef CFG_AG102
#ifdef CFG_16MB
#error "AG102 does NOT supports CFG_16MB"
#endif
#endif

#ifdef CFG_AE210P
#if BUILD_MODE != BUILD_XIP
#error "AE210P supports BUILD_XIP only"
#endif
#endif

#endif // CFG_MAKEFILE


/* Define to enable diagnostic debugging support. */
/* #undef DEBUG */

/* Define to enable experimental code. */
/* #undef EXPERIMENTAL */

/* Define to 1 if you have the <assert.h> header file. */
#define HAVE_ASSERT_H 1

/* Define to 1 if you have the <dlfcn.h> header file. */
/* #undef HAVE_DLFCN_H */

/* Define to 1 if you have the <errno.h> header file. */
#define HAVE_ERRNO_H 1

/* Define to 1 if you have the `fcntl' function. */
/* #undef HAVE_FCNTL */

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the `fork' function. */
/* #undef HAVE_FORK */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <limits.h> header file. */
#define HAVE_LIMITS_H 1

/* Define if your MIPS CPU supports a 2-operand MADD16 instruction. */
/* #undef HAVE_MADD16_ASM */

/* Define if your MIPS CPU supports a 2-operand MADD instruction. */
/* #undef HAVE_MADD_ASM */

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `pipe' function. */
/* #undef HAVE_PIPE */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have <sys/wait.h> that is POSIX.1 compatible. */
/* #undef HAVE_SYS_WAIT_H */

/* Define to 1 if you have the <unistd.h> header file. */
/* #undef HAVE_UNISTD_H */

/* Define to 1 if you have the `waitpid' function. */
/* #undef HAVE_WAITPID */

/* Define to disable debugging assertions. */
/* #undef NDEBUG */

/* Define to optimize for accuracy over speed. */
/* #undef OPT_ACCURACY */

/* Define to optimize for speed over accuracy. */
/* #undef OPT_SPEED */

/* Define to enable a fast subband synthesis approximation optimization. */
/* #undef OPT_SSO */

/* Define to influence a strict interpretation of the ISO/IEC standards, even
   if this is in opposition with best accepted practices. */
/* #undef OPT_STRICT */

/* Name of package */
#define PACKAGE "libmad"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "support@underbit.com"

/* Define to the full name of this package. */
#define PACKAGE_NAME "MPEG Audio Decoder"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "MPEG Audio Decoder 0.15.0b"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "libmad"

/* Define to the version of this package. */
#define PACKAGE_VERSION "0.15.0b"

/* The size of a `int', as computed by sizeof. */
#define SIZEOF_INT 4

/* The size of a `long', as computed by sizeof. */
#define SIZEOF_LONG 4

/* The size of a `long long', as computed by sizeof. */
#define SIZEOF_LONG_LONG 8

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */
#define VERSION "0.15.0b"

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define as `__inline' if that's what the C compiler calls it, or to nothing
   if it is not supported. */
// #define inline __inline
#define __INLINE static __attribute__((__always_inline__)) inline

//define the __STATIC to make it unuseful
#define __STATIC static

/// define the IRQ handler attribute for this compiler
#define __IRQ // __attribute__((__interrupt__("IRQ")))

/// define the BLE IRQ handler attribute for this compiler
#define __BTIRQ

/// define the BLE IRQ handler attribute for this compiler
#define __BLEIRQ

/// define the FIQ handler attribute for this compiler
#define __FIQ __attribute__((__interrupt__("FIQ")))

/// define size of an empty array (used to declare structure with an array size not defined)
#define __ARRAY_EMPTY

/// Function returns struct in registers (4 in rvds, var with gnuarm).
/// With Gnuarm, feature depends on command line options and
/// impacts ALL functions returning 2-words max structs
/// (check -freg-struct-return and -mabi=xxx)
#define __VIR

/// function has no side effect and return depends only on arguments
#define __PURE __attribute__((const))

/// symbol is defined weakly (silently replaced by NULL at link if not defined)
/// GCC 3.4 for ARM may not accept it, must be tested. Error meanwhile.
//#if __GNUC__ >= 4
//#define __WEAK __attribute__((weak))
//#else
//#error "check weak with gnuarm 3.4"
//#endif

/// Align instantiated lvalue or struct member on 4 bytes
#define __ALIGN4 __attribute__((aligned(4)))

/// __MODULE__ comes from the RVDS compiler that supports it
#ifndef __MODULE__
#define __MODULE__ __FILE__
#endif /* __MODULE__  */

/// Pack a structure field
#define __PACKED __attribute__ ((__packed__))

/// Put a variable in a memory maintained during deep sleep
#define __LOWPOWER_SAVED

#endif // _COMPILER_H_
