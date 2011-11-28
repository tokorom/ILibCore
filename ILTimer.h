//
//  ILTimer.h
//
//  Created by ToKoRo on 2011-06-24.
//  Last Change: 2011-06-24.
//

typedef void (^ILTimerHandler_b)(void);

@interface ILTimer : NSObject

@property (nonatomic, assign) dispatch_source_t source;

- (void)startWithInterval:(NSUInteger)sec handler:(ILTimerHandler_b)block;
- (void)cancel;

@end
