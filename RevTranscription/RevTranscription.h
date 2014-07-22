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
#import "RevApiError.h"

typedef void (^RevSuccessBlock)(NSString *orderUri);
typedef void (^RevFailedBlock)(RevApiError *error);


@interface RevTranscription : NSObject

// initialize the SDK with given API client key. Set isSandbox to YES during
// testing to work with the Rev Sandbox environment, and set it to NO
// for production
+ (void) initWithClientKey:(NSString *)clientKey isSandbox:(BOOL)isSandbox;

// log out the currently logged in Rev user
+ (void) logout;

// Modally present the Rev TC view
+ (void)presentTranscriptionInterfaceForParentViewController:(UIViewController *)parentViewController forRecording:(RecordingInfo *) recording
                                        withSuccessBlock:(RevSuccessBlock)successBlock
                                            failureBlock:(RevFailedBlock)failedBlock;

@end
