//
//  ILibDebug.h
//
//  Created by ToKoRo on 2009-12-03.
//  Last Change: 2011-07-10.
//

#import <objc/runtime.h>

#if defined(DEBUG)

//FOUNDATION_EXPORT void NSLog(NSString *format, ...) __attribute__((format(__NSString__, 1, 2)));
//FOUNDATION_EXPORT void NSLogv(NSString *format, va_list args);

#if !defined(NSLog)
#define NSLog( args... ) NSLog( args )
#endif

#define ILibDebugLog( str ) \
{ \
  for ( int i = 0; i < [str length]; i += 64 ) { \
    NSLog( [str substringWithRange:NSMakeRange( i, 64 )] ); \
  } \
}

#else

#if !defined(NSLog)
#define NSLog( args... )
#endif

#define ILibDebugLog( str )

#endif
#if defined(DEBUG)

#if !defined(NSLog)
#define NSLog( args... ) NSLog( args, 0 )
#endif

#else

#if !defined(NSLog)
#define NSLog( args... )
#endif

#endif

/**
 * ObjectのProperty一覧をデバッグ出力する 
 */
static void ILDebugPrintPropertyList( id object ) {
#ifdef DEBUG
 unsigned int outCount, i;
 objc_property_t *properties = class_copyPropertyList([object class], &outCount);
 for(i = 0; i < outCount; i++) {
  objc_property_t property = properties[i];
  const char *propName = property_getName(property);
  const char *propType = property_getAttributes(property);
  NSString *propertyName = [NSString stringWithUTF8String:propName];
  NSString *propertyType = [NSString stringWithUTF8String:propType];
  NSLog(@"- %@: %@", propertyName, propertyType);
 }
 free(properties);
#endif
}

