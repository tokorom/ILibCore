//
//  ILTimer.m
//
//  Created by ToKoRo on 2011-06-24.
//  Last Change: 2011-06-24.
//

#import "ILTimer.h"

@implementation ILTimer

@synthesize source = source_;

- (void)dealloc {
  if ( self.source ) {
    dispatch_release( self.source ), self.source = nil;
  }
}

- (void)cancel {
  if ( self.source ) {
    dispatch_source_cancel( self.source );
  }
}

- (void)startWithInterval:(NSUInteger)sec handler:(ILTimerHandler_b)block {
  //タイマーのソースを作成
  dispatch_queue_t queue = dispatch_get_global_queue( DISPATCH_QUEUE_PRIORITY_DEFAULT, 0 );
  self.source = dispatch_source_create( DISPATCH_SOURCE_TYPE_TIMER, 0, 0, queue );
  dispatch_time_t start = dispatch_time( DISPATCH_TIME_NOW, 0 );
  uint64_t interval = NSEC_PER_SEC * sec;
  dispatch_source_set_timer( self.source, start, interval, 0 );

  // タイマーループ
  dispatch_source_set_event_handler( self.source, block );

  // キャンセル時の動作 
  dispatch_source_set_cancel_handler( self.source, ^{
    dispatch_release( self.source ), self.source = nil;
  });

  // タイマー開始 
  dispatch_resume( self.source );
}

@end
