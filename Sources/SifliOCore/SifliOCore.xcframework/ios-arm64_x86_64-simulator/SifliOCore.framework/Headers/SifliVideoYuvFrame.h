//
//  SifliVideoYuvFrame.h
//  SifliOCore
//
//  Created by congqiang on 2026/5/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SifliVideoYuvFrame : NSObject
@property (nonatomic,strong) NSData *yuvI420;
@property (nonatomic,assign) uint32_t width;
@property (nonatomic,assign) uint32_t height;
@end

NS_ASSUME_NONNULL_END
