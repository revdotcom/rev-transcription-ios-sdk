//
//  RecordingInfo.h
//  RevCorderSDK
//
//  Created by Dan Kokotov on 7/11/14.
//  Copyright (c) 2014 rev. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RecordingInfo  : NSObject

@property (nonatomic) NSString* name;
@property (nonatomic) NSString* contentMimeType;
@property (nonatomic) NSString* filePath;
@property (nonatomic) NSTimeInterval duration;
@property (nonatomic) NSString* orderUri;
@property (nonatomic, readonly) NSString* orderNumber;

@end

