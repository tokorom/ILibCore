//
//  ILSingleton.h
//
//  Created by ToKoRo on 2010-01-21.
//  Last Change: 2010-10-01.
//

#define INTERFACE_FOR_SINGLETON(cls) \
+ (cls*)sharedInstance; \
+ (void)releaseSharedInstance; \

#define IMPLEMENTATION_FOR_SINGLETON(cls) \
static cls* sharedInstance = nil; \
static BOOL allowRelease = NO; \
 \
+ (cls*)sharedInstance { \
  @synchronized( self ) { \
    if ( nil == sharedInstance ) { \
      [[self alloc] init]; \
    }  \
  } \
  return sharedInstance; \
} \
 \
+ (void)releaseSharedInstance { \
  @synchronized( self ) { \
    if ( nil != sharedInstance ) { \
      allowRelease = YES; \
      [sharedInstance release]; \
      sharedInstance = nil; \
      allowRelease = NO; \
    }  \
  } \
} \
 \
+ (id)allocWithZone:(NSZone*)zone { \
  @synchronized( self ) { \
    if ( nil == sharedInstance ) { \
      sharedInstance = [super allocWithZone:zone]; \
      return sharedInstance; \
    }  \
  } \
  return nil; \
} \
 \
- (id)copyWithZone:(NSZone*)zone { \
  return self; \
} \
 \
- (id)retain { \
  return self; \
} \
 \
- (unsigned)retainCount { \
  return NSUIntegerMax; \
} \
 \
- (void)release { \
  @synchronized( self ) { \
    if ( allowRelease ) { \
      [super release]; \
    }  \
  } \
} \
 \
- (id)autorelease { \
  return self; \
} \

