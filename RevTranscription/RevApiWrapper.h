//
//  RevApiWrapper.h
//  revcorder
//
//  Created by Dan Kokotov on 9/24/12.
//  Copyright (c) 2012 rev.com. All rights reserved.
//

// make our own reachability constants, so we are not exposing a dependence on AFNetworking
typedef enum {
    NetworkReachabilityStatusUnknown          = -1,
    NetworkReachabilityStatusNotReachable     = 0,
    NetworkReachabilityStatusReachableViaWWAN = 1,
    NetworkReachabilityStatusReachableViaWiFi = 2,
} NetworkReachabilityStatus;

@class RevUser;
@class RevDiscountCoupon;
@class RevApiError;
@class RevPayment;
@class RevCreditCard;
@class RevPaymentOptions;
@class RevTranscriptionOptions;
@class RevTranscriptionOrder;

@interface RevApiWrapper : NSObject

@property (nonatomic, strong) NSString *userKey;
@property (nonatomic, readonly) NetworkReachabilityStatus reachabilityStatus;
@property (nonatomic) BOOL allowsInvalidCertificate;

+ (void)setSharedSession:(RevApiWrapper *)session;
+ (RevApiWrapper *)sharedSession;
- (id) initWithClientKey:(NSString *)clientKey andUserKey:(NSString *)userApiKey isSandbox:(Boolean)isSandbox;
- (NSString *)getBaseUrl;
- (id) initWithClientKey:(NSString *)clientKey isSandbox:(Boolean)isSandbox;

#pragma mark - reachability

- (void) setReachabilityCallback:(void (^)(NetworkReachabilityStatus status))block;
// check connecitivy by attempting a simple GET of any api call. success will be called as long as
// some respoonse was returned, even if it was a 4xx or 5xx
- (void) attemptConnectionWithSuccess:(void (^)())successBlock failure:(void (^)(RevApiError* error))failureBlock;

#pragma mark - account api

- (void) loginWithEmail:(NSString*)email andPassword:(NSString *)password
                success:(void (^)(RevUser *user))successBlock failure:(void (^)(RevApiError* error))failureBlock;

- (void) registerWithEmail:(NSString*)email password:(NSString *)password
                 firstName:(NSString *)firstName lastName:(NSString *)lastName
                   success:(void (^)(RevUser *user))successBlock failure:(void (^)(RevApiError* error))failureBlock;
- (void) getPaymentOptionsWithSuccess:(void (^)(RevPaymentOptions *paymentOptions))successBlock failure:(void (^)(RevApiError* error))failureBlock;
- (void) saveCreditCard:(RevCreditCard *)card success:(void (^)(void))successBlock failure:(void (^)(RevApiError* error))failureBlock;
- (void) logout;
- (void) getMobileConfig:(void (^)(NSMutableArray *))successBlock failure:(void (^)(RevApiError *))failureBlock;

#pragma mark - inputs api

- (void) uploadMediaWithDataStream:(NSInputStream *)stream filename:(NSString *)filename size:(long long) streamSize
                          mimeType:(NSString *) mimeType
                          progress:(void (^)(long long totalBytesWritten, long long totalBytesExpectedToWrite))progressBlock
                           success:(void (^)(NSString *mediaUri))successBlock failure:(void (^)(RevApiError* error))failureBlock;

#pragma mark - orders api

- (void) placeTranscriptionOrderWithReference:(NSString *)reference comment:(NSString *)comment
                                      payment:(RevPayment *)payment options:(RevTranscriptionOptions *)options
                                        success:(void (^)(NSString *orderUri))successBlock failure:(void (^)(RevApiError* error))failureBlock;

- (void) getOrderForUri:(NSString *)uri
                success:(void (^)(RevTranscriptionOrder *order))successBlock failure:(void (^)(RevApiError* error))failureBlock;

#pragma mark - attachments api

- (void) saveAttachmentContentForUri:(NSString *)uri withContentType:(NSString *)contentType toFile:(NSString *)filePath
                            progress:(void (^)(long long, long long))progressBlock
                             success:(void (^)())successBlock failure:(void (^)(RevApiError* error))failureBlock;


#pragma mark - coupons api

- (void) getCouponForCode:(NSString *)code  success:(void (^)(RevDiscountCoupon *coupon))successBlock failure:(void (^)(RevApiError* error))failureBlock;

#pragma mark operations management
- (BOOL) hasPendingOperations;
- (long long) remainingContentLengthForCurrentOperation;
@end

@interface RevApiWrapper (FileUpload)
- (void) uploadMediaWithFilePath:(NSString *)path
                        mimeType:(NSString *)mimeType
                        progress:(void (^)(long long totalBytesWritten, long long totalBytesExpectedToWrite))progressBlock
                         success:(void (^)(NSString *mediaUri))successBlock failure:(void (^)(RevApiError* error))failureBlock;
@end