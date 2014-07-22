//
//  RevApiError.h
//  revcorder
//
//  Created by Dan Kokotov on 9/27/12.
//  Copyright (c) 2012 rev.com. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    RevNetworkError,
    RevUnauthorizedError,
    RevForbiddenError,
    RevNotFoundError,
    RevApplicationError
} RevErrorType;

@interface RevApiFieldError : NSObject

@property (readonly, nonatomic) NSString* fieldName;
@property (readonly, nonatomic) NSArray* messages;

- (id)initWithAttributes:(NSDictionary *)attributes;
- (NSString *) errorDescription;

@end

@interface RevApiError : NSObject

@property (readonly, nonatomic, strong) NSError* httpError;
@property (readonly, nonatomic) NSInteger httpStatusCode;
@property (readonly, nonatomic) NSInteger applicationCode;
@property (readonly, nonatomic, strong) NSString* applicationMessage;
@property (readonly, nonatomic, strong) NSArray* fieldErrors;

- (id) initWithError:(NSError *)error;
- (id) initWithHttpStatusCode:(NSUInteger) statusCode;

- (RevErrorType) errorType;
- (NSString *) errorDescription;
- (NSString *) loginErrorDescription;
- (NSString *) signUpErrorDescription;
- (NSString *) paymentErrorDescription;

@end
