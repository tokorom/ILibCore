//
//  ILSingleton.h
//
//  Created by ToKoRo on 2010-01-21.
//  Last Change: 2011-10-01.
//

#define INTERFACE_FOR_SINGLETON(cls) \
+ (cls*)sharedInstance; \

#define IMPLEMENTATION_FOR_SINGLETON(cls) \
 \
static cls* sharedInstance = nil; \
+ (cls*)sharedInstance \
{ \
  static dispatch_once_t onceQueue; \
  dispatch_once( &onceQueue, ^{ \
    sharedInstance = [[cls alloc] init]; \
  }); \
  return sharedInstance; \
} \

