//
//  ManufacturerDataHelper.h
//  SifliOCore
//
//  Created by congqiang on 2026/5/19.
//

#import <Foundation/Foundation.h>
#import <SifliOCore/SFResult.h>

NS_ASSUME_NONNULL_BEGIN

@interface ManufacturerDataHelper : NSObject

/// 从manufactureer data里读取mac数据
/// - Parameter manufacturerData: manufacturer data
+ (SFResultT<NSData *> *)readMacWidthData:(NSData *)manufacturerData;
+ (nullable NSString *)macStringWithData:(NSData *)data;
@end

NS_ASSUME_NONNULL_END
