//
//  ILibUtil.h
//
//  Created by ToKoRo on 2009-11-18.
//  Last Change: 2010-09-27.
//

#import <UIKit/UIKit.h>

#pragma mark ----- enums -----

typedef enum
{
  ILAlignmentLeft =    0x1 << 0,
  ILAlignmentRight =   0x1 << 1,
  ILAlignmentCenter =  0x1 << 2,
  ILAlignmentTop =     0x1 << 3,
  ILAlignmentBottom =  0x1 << 4,
  ILAlignmentMiddle =  0x1 << 5,
} ILAlignment;

#pragma mark ----- const -----

static const UIViewAutoresizing UIViewAutoresizingFlexibleAll = UIViewAutoresizingFlexibleWidth |
                                                                UIViewAutoresizingFlexibleHeight |
                                                                UIViewAutoresizingFlexibleLeftMargin |
                                                                UIViewAutoresizingFlexibleRightMargin |
                                                                UIViewAutoresizingFlexibleTopMargin |
                                                                UIViewAutoresizingFlexibleBottomMargin;

static const UIViewAutoresizing UIViewAutoresizingFlexibleSize = UIViewAutoresizingFlexibleWidth |
                                                                 UIViewAutoresizingFlexibleHeight;

static const UIViewAutoresizing UIViewAutoresizingFlexibleMargins = UIViewAutoresizingFlexibleLeftMargin |
                                                                    UIViewAutoresizingFlexibleRightMargin |
                                                                    UIViewAutoresizingFlexibleTopMargin |
                                                                    UIViewAutoresizingFlexibleBottomMargin;

#pragma mark ----- Utility for CGPoint -----

CGPoint CGPointCenterByRect( CGRect rect );

#pragma mark ----- Utility for CGRect -----

CGRect CGRectWithLeftAndTop( CGRect baseRect, CGFloat left, CGFloat top );

CGRect CGRectWithTranslation( CGRect baseRect, CGFloat x, CGFloat y );

CGRect CGRectWithSize( CGRect baseRect, CGSize size );

CGRect CGRectWithWidthAndHeight( CGRect baseRect, CGFloat width, CGFloat height );

CGRect CGRectWithWidth( CGRect baseRect, CGFloat width );

CGRect CGRectWithHeight( CGRect baseRect, CGFloat height );

CGRect CGRectInsetWithAlignment( CGRect bigRect, CGRect smallRect, CGFloat dx, CGFloat dy, ILAlignment alignment );

CGRect CGRectOnTheRect( CGRect targetRect, CGRect theRect, ILAlignment alignment );

#pragma mark ----- Utility for NSString -----

NSString* NSStringFromChars( const char* chars );
NSString* NSStringNotNull( NSString* string );
NSString* NSStringFromInteger( NSInteger integer );

#pragma mark ----- Utility for UIColor -----
#define HEXCOLOR(c) [UIColor colorWithRed:((c>>16)&0xFF)/255.0 \
green:((c>>8)&0xFF)/255.0 \
blue:(c&0xFF)/255.0 \
alpha:1.0];

#define HEXRED(c) ((c>>16)&0xFF)/255.0
#define HEXGREEN(c) ((c>>8)&0xFF)/255.0
#define HEXBLUE(c) (c&0xFF)/255.0

#define RED(d) d/255.0
#define GREEN(d) d/255.0
#define BLUE(d) d/255.0