//
//  SFZipHelper.h
//  SifliOCore
//
//  Created by Sean on 2026/1/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class SFZipHelper;
@protocol SFZipHelperDelegate <NSObject>

/// 将一个zip文件解压到指定目录
/// - Parameters:
///   - helper: helper实例
///   - path: zip文件路径
///   - destination: 目标目录
- (BOOL)zipHelper:(SFZipHelper *)helper unzipFileAtPath:(NSString *)path toDestination:(NSString *)destination;

/// 将一个目录压缩为zip文件，并保存到指定文件路径
/// - Parameters:
///   - helper: helper实例
///   - dir: 需要所谓为zip的源目录
///   - destination: zip文件的输出路径
///   - discussion:dir目录的最后一个component 将作为zip文件的第一层目录名。如果dir为 /var/.../dyn/,那么输出zip文件的第一层目录名为dyn
- (BOOL)zipHelper:(SFZipHelper *)helper zipFolder:(NSString *)dir toDestination:(NSString *)destination;

@end

@interface SFZipHelper : NSObject

/// zip,unzip 委托外部插件实现
@property(nonatomic,weak)id<SFZipHelperDelegate> zipDelegate;
+ (SFZipHelper *)shared;
- (BOOL)unzipFileAtPath:(NSString *)path toDestination:(NSString *)destination;
- (BOOL)zipFolder:(NSString *)dir toDestination:(NSString *)destination;
@end

NS_ASSUME_NONNULL_END
