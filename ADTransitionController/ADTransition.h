//
//  ADTransition.h
//  Transition
//
//  Created by Patrick Nollet on 21/02/11.
//  Copyright 2011 Applidium. All rights reserved.
//

// Abstract class

#import <Foundation/Foundation.h>
#import <QuartzCore/CoreAnimation.h>

extern NSString * ADTransitionAnimationKey;
extern NSString * ADTransitionAnimationInValue;
extern NSString * ADTransitionAnimationOutValue;

@class ADTransition;
@protocol ADTransitionDelegate
@optional
- (void)pushTransitionDidFinish:(ADTransition *)transition;
- (void)popTransitionDidFinish:(ADTransition *)transition;
@end

typedef enum {
    ADTransitionTypeNull,
    ADTransitionTypePush,
    ADTransitionTypePop
} ADTransitionType;

typedef enum {
    ADTransitionRightToLeft,
    ADTransitionLeftToRight,
    ADTransitionTopToBottom,
    ADTransitionBottomToTop
} ADTransitionOrientation;


@interface ADTransition : NSObject {
    id <ADTransitionDelegate> _delegate;
    ADTransitionType _type;
}

@property (nonatomic, assign) id <ADTransitionDelegate> delegate;
@property (nonatomic, assign) ADTransitionType type;
@property (nonatomic, readonly) NSTimeInterval duration; // abstract
@property (nonatomic, assign) BOOL isModal;             //def NO. 

+ (ADTransition *)nullTransition;
- (ADTransition *)reverseTransition;
- (NSArray *)getCircleApproximationTimingFunctions;
@end
