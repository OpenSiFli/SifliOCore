//
//  SFOLogManager.h
//  SifliOCore
//
//  Created by Sean on 2023/11/10.
//

#import <Foundation/Foundation.h>
#import <SifliOCore/SFOLog.h>

NS_ASSUME_NONNULL_BEGIN
@class SFOLogManager;
@protocol SFOLogManagerDelegate <NSObject>

- (void)logManager:(SFOLogManager *)manager level:(SFOLogLevel)level log:(NSString *)log;

@end

@interface SFOLogManager : NSObject
@property (nonatomic,assign) BOOL logEnable;

/// 输出日志等级,默认为SFOLoginfo级
@property (nonatomic,assign) SFOLogLevel logLevel;
@property (nonatomic,weak) id<SFOLogManagerDelegate> delegate;
+ (SFOLogManager *)shared;
@end

NS_ASSUME_NONNULL_END
