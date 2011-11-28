//
//  ILibUtil.m
//
//  Created by ToKoRo on 2009-12-03.
//  Last Change: 2011-09-15.
//

#import "ILibUtil.h"

CGRect CGRectWithLeftAndTop( CGRect baseRect, CGFloat left, CGFloat top ) {
  baseRect.origin.x = left;
  baseRect.origin.y = top;
  return baseRect;
}

CGRect CGRectWithTranslation( CGRect baseRect, CGFloat x, CGFloat y ) {
  baseRect.origin.x += x;
  baseRect.origin.y += y;
  return baseRect;
}

CGPoint CGPointCenterByRect( CGRect rect ) {
  return CGPointMake( rect.origin.x + rect.size.width / 2,
                      rect.origin.y + rect.size.height / 2 );
}

CGRect CGRectWithSize( CGRect baseRect, CGSize size ) {
  baseRect.size = size;
  return baseRect;
}

CGRect CGRectWithWidthAndHeight( CGRect baseRect, CGFloat width, CGFloat height ) {
  return CGRectWithSize( baseRect, CGSizeMake( width, height ) );
}

CGRect CGRectWithWidth( CGRect baseRect, CGFloat width ) {
  baseRect.size.width = width;
  return baseRect;
}

CGRect CGRectWithHeight( CGRect baseRect, CGFloat height ) {
  baseRect.size.height = height;
  return baseRect;
}

CGRect CGRectInsetWithAlignment( CGRect bigRect, CGRect smallRect, CGFloat dx, CGFloat dy, ILAlignment alignment ) {
  CGRect rect = smallRect;
  if ( ILAlignmentLeft & alignment ) {
    rect.origin.x = bigRect.origin.x + dx;
  } else if ( ILAlignmentRight & alignment ) {
    rect.origin.x = bigRect.origin.x + bigRect.size.width - smallRect.size.width - dx;
  } else if ( ILAlignmentCenter & alignment ) {
    rect.origin.x = bigRect.origin.x + ( bigRect.size.width - smallRect.size.width ) / 2 + dx;
  } 
  if ( ILAlignmentTop & alignment ) {
    rect.origin.y = bigRect.origin.y + dy;
  } else if ( ILAlignmentBottom & alignment ) {
    rect.origin.y = bigRect.origin.y + bigRect.size.height - smallRect.size.height - dy;
  } else if ( ILAlignmentMiddle & alignment ) {
    rect.origin.y = bigRect.origin.y + ( bigRect.size.height - smallRect.size.height ) / 2 + dy;
  } 
  return rect;
}

CGRect CGRectOnTheRect( CGRect targetRect, CGRect theRect, ILAlignment alignment ) {
  if ( ILAlignmentLeft & alignment || ILAlignmentRight & alignment ) {
    return CGRectInsetWithAlignment( theRect, targetRect, targetRect.size.width * -1, 0.0, alignment | ILAlignmentMiddle );
  }
  if ( ILAlignmentTop & alignment || ILAlignmentBottom & alignment ) {
    return CGRectInsetWithAlignment( theRect, targetRect, 0.0, targetRect.size.height * -1, ILAlignmentCenter | alignment );
  }
  return theRect;
}

NSString* NSStringFromChars( const char* chars ) {
  return [NSString stringWithUTF8String:chars];
}

NSString* NSStringNotNull( NSString* string ) {
  return string ? string : @"";
}

NSString* NSStringFromInteger( NSInteger integer ) {
  return [NSString stringWithFormat:@"%d", integer];
}

