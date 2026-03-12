//
//  SFResult.h
//  SifliOCore
//
//  Created by Sean on 2024/8/9.
//

#import <Foundation/Foundation.h>
#import <SifliOCore/SFCoreError.h>

NS_ASSUME_NONNULL_BEGIN

@interface SFResult : NSObject
@property(nonatomic,assign)BOOL success;
@property(nonatomic,strong)SFCoreError *error;
- (instancetype)initWithSuccess:(BOOL)success error:(nullable SFCoreError *)error;
@end

@interface SFDataResult : SFResult
@property(nonatomic,strong)NSData *data;
- (instancetype)initWithSuccess:(BOOL)success data:(nullable NSData *)data error:(nullable SFCoreError *)error;
@end

// 泛型子类：携带具体类型的数据
@interface SFResultT<__covariant ObjectType> : SFResult
@property (nonatomic, strong, nullable) ObjectType data;
- (instancetype)initWithSuccess:(BOOL)success
                           data:(nullable ObjectType)data
                          error:(nullable SFCoreError *)error;
@end

NS_ASSUME_NONNULL_END
