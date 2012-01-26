//
//  ILGCD.h
//
//  Created by ToKoRo on 2011-06-19.
//  Last Change: 2012-01-26.
//

#define MAIN_QUEUE( th ) dispatch_async( dispatch_get_main_queue(), ^{ th } )
#define GLOBAL_QUEUE( th ) dispatch_async( dispatch_get_global_queue( DISPATCH_QUEUE_PRIORITY_DEFAULT, 0 ), ^{ th } )

#define MAIN_THREAD( bl ) dispatch_async( dispatch_get_main_queue(), bl )
#define GLOBAL_THREAD( bl ) dispatch_async( dispatch_get_global_queue( DISPATCH_QUEUE_PRIORITY_DEFAULT, 0 ), bl )

typedef void (^ILGCDBlock_b)(void);
