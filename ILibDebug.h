//
//  ILibDebug.h
//
//  Created by ToKoRo on 2009-12-03.
//  Last Change: 2011-12-11.
//

#define NSLogFunction() NSLog( @"%s", __func__ )
#define NSLogLine() NSLog( @"%s: %d", __FILE__, __LINE__ )
#define NSLogStackTarce() NSLog( @"Stack trace: %@", [NSThread callStackSymbols] )

#if defined(DEBUG) //< A

#if !defined(NSLog)
#define NSLog( args... ) NSLog( args )
#endif

#else //< A

#define NSLog( args... )

#endif //< A
