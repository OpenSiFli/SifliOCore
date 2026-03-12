//
//  SFStringUtil.h
//  SifliOCore
//
//  Created by Sean on 2024/8/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SFStringUtil : NSObject
+ (BOOL)isNullOrEmpty:(NSString *)str;
+ (BOOL)isValidHexString:(NSString *)str;
+ (NSString *)paddingHexString:(NSString *)src toLen:(NSUInteger)len;

/**
     * 专门为文件路径生成MD5文件名
     * @param filePath 文件路径字符串
     * @return 32位小写MD5字符串，用作文件名
     */
+ (NSString *)md5FileNameFromString:(NSString *)filePath;

/// 将数据按utf8编码转为NSString
/// @param data 数据
+ (NSString *)parseBytesToString:(NSData *)data;

/// 将文本转为utf8数据
/// @param text 文本
+ (NSData *)utf8BytesOfString:(NSString *)text;
@end

NS_ASSUME_NONNULL_END
