//
//  RevCorderSDK.h
//  RevCorderSDK
//
//  Created by Bassam Mehanni on 7/7/14.
//  Copyright (c) 2014 rev. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "RecordingInfo.h"

@class RevApiError;

typedef void (^RevSuccessBlock)(NSString *orderUri);
typedef void (^RevFailedBlock)(RevApiError *error);


@interface RevTranscription : NSObject

+ (void) initWithClientKey:(NSString *)clientKey isSandbox:(BOOL)isSandbox;

// Modally present the Rev TC view
+ (void)presentTranscriptionInterfaceForParentViewController:(UIViewController *)parentViewController forRecording:(RecordingInfo *) recording
                                        withSuccessBlock:(RevSuccessBlock)successBlock
                                            failureBlock:(RevFailedBlock)failedBlock;

@end
