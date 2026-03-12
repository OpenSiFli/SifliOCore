//
//  SFCoreError.h
//  SifliOCore
//
//  Created by Sean on 2023/10/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, SFCoreErrorType) {
    SFCoreErrorTypeUnkown = 0,
    SFCoreErrorTypeTimeout,
    SFCoreErrorTypeCanceled,
    SFCoreErrorTypeDisconnected,
    SFCoreErrorTypeFailedToConnect,
    SFCoreErrorTypeUserStop,
    SFCoreErrorTypeInvalidParameter,
    SFCoreErrorTypeReadFileError,
    SFCoreErrorTypeDeviceCode,
    SFCoreErrorTypeUnavailableBleStatus
};

@interface SFCoreError : NSObject

/// 错误码
/// 0-100 为SFCoreErrorType 范围
/// 超过100为具体业务模块的错误码
@property (nonatomic,assign)NSUInteger errorType;
@property (nonatomic,copy)NSString *errInfo;

/// 设备错误码


- (instancetype)initWithType:(SFCoreErrorType)type info:(NSString *)info;
- (instancetype)initWithCode:(NSUInteger)code info:(NSString *)info;

+ (SFCoreError *)initWithCode:(NSUInteger)code info:(NSString *)info;
+ (SFCoreError *)initWithDeviceCode:(uint16_t)code;

@end
NS_ASSUME_NONNULL_END
