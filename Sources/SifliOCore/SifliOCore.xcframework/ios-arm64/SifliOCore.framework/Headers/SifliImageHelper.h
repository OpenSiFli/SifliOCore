//
//  SifliImageHelper.h
//  SifliOCore
//
//  Created by congqiang on 2026/5/6.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import <SifliOCore/SifliVideoYuvFrame.h>

NS_ASSUME_NONNULL_BEGIN

/// 视频/图像投屏的转换协议。这个协议需要专门的图像库SifliImageLib.framework实现。
@protocol SifliImageHelper <NSObject>
@optional
/// 将UIImage 转为jpeg数据
/// - Parameters:
///   - quality: jpeg 质量
- (NSData *)makeYCbCrJpgWithImage:(UIImage *)image quality:(float)quality;
- (NSData *)makeYCbCrJpgWithPixcel:(CVPixelBufferRef)image quality:(float)quality;


/// 将UIImage转为yuv i420数据
/// - Parameter image: 图像数据
- (NSData *)makeI420WithImage:(UIImage *)image;
- (SifliVideoYuvFrame *)makeI420WithVideoFrame:(CMSampleBufferRef)sample;
- (SifliVideoYuvFrame *)makeI420WithPixelFrame:(CVPixelBufferRef)sample;


/// 将YUV I420数据转为jpeg.
/// 支持目标尺寸控制，方向旋转，质量控制
/// 通常用于视频投屏
/// - Parameters:
///   - srcI420: YUV I420数据
///   - srcWidth: 图像原始宽度
///   - srcHeight: 图像原始高度
///   - dstWidth: 图像目标宽度
///   - dstHeight: 图像目标高度
///   - rotation: 旋转方向 0,90,180,270
///   - isMirror: 是否水平镜像
///   - quality: jpeg质量参数0~1
- (NSData *)processToJpegWithI420:(NSData *)srcI420
                         srcWidth:(uint32_t)srcWidth
                        srcHeight:(uint32_t)srcHeight
                         dstWidth:(uint32_t)dstWidth
                        dstHeight:(uint32_t)dstHeight
                         rotation:(int)rotation
                         isMirror:(BOOL)isMirror
                          quality:(float)quality;

@end

NS_ASSUME_NONNULL_END
