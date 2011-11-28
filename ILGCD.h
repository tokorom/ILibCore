//
//  ILGCD.h
//
//  Created by ToKoRo on 2011-06-19.
//  Last Change: 2011-08-04.
//

#define MAIN_QUEUE( th ) dispatch_async( dispatch_get_main_queue(), ^{ th } )
#define GLOBAL_QUEUE( th ) dispatch_async( dispatch_get_global_queue( DISPATCH_QUEUE_PRIORITY_DEFAULT, 0 ), ^{ th } )

typedef void (^ILGCDBlock_b)(void);
