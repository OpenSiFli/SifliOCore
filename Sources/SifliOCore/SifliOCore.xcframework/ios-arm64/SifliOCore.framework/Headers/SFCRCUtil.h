//
//  SFCRCUtil.h
//  SifliOCore
//
//  Created by congqiang on 2026/4/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SFCRCUtil : NSObject
/// CRC 从swit迁移而来
/// - Parameters:
///   - data:
///   - offset:
///   - length:
+ (uint32_t) CRC32_MPEG2:(NSData *)data offset:(NSInteger)offset length:(NSInteger)length;

/// 基于一个已有的Crc值，对数据片段进行crc计算，并返回crc值
/// - Parameters:
///   - data: 数据片段
///   - length: 数据长度
///   - lastCrc: 已有的crc值
+ (uint32_t) CRC32_MPEG2WithData:(NSData *)data  length:(NSInteger)length lastCrc:(uint32_t)lastCrc;
@end

NS_ASSUME_NONNULL_END
