//
//  SFBleShellStatus.h
//  SifliOCore
//
//  Created by Sean on 2025/9/18.
//

#ifndef SFBleShellStatus_h
#define SFBleShellStatus_h
NS_ASSUME_NONNULL_BEGIN
///1.0.9 优化蓝牙工作队列为专有队列
///1.0.10 发送流控优化
///1.0.11 发送间隔时间优化
///1.0.13 SSZipArchive隐藏在framework内部。
///1.0.14 订阅特征失败，输出错误信息
///1.0.15 支持表盘编辑sdk
///2.0.1 SSZipArchive剥离为外部插件
///2.1.1 地图导航投屏支持相关的优化，增加图像编码协议，网络层优化
///2.2.1 socket 内核升级为POSIX
///2.2.2 ble写入方式优化
static NSString * const kOCoreVersion = @"2.2.2";

typedef NS_ENUM(NSUInteger, SFBleShellStatus) {
    //空闲
    SFBleShellStatusNone = 0,
    //搜索设备
    SFBleShellStatusSearching = 1,
    //连接设备
    SFBleShellStatusConnecting = 2,
    //模块工作中
    SFBleShellStatusModuleWorking = 3,
    SFBleShellStatusSocketServerListening = 4,
    ///当socket server模式时，客户端加入后进入该状态
    SFBleShellStatusSocketClientConnected = 5
};

typedef NS_ENUM(NSUInteger, SFTransmissionMode) {
    //蓝牙 ble方式
    SFTransmissionModeBle = 0,
    //socket方式，用于pan,手机开启wifi热点的情形。
    SFTransmissionModeSocketServer = 2,
    SFTransmissionModeSocketClient = 3
};

@protocol SFTransmissionShell;
@protocol SFBleShellDelegate <NSObject>

- (void)bleShell:(id<SFTransmissionShell>)shell updateBleState:(SFBleCoreManagerState)state;
- (void)bleShell:(id<SFTransmissionShell>)shell updateShellState:(SFBleShellStatus)state;
- (void)bleShell:(id<SFTransmissionShell>)shell progress:(NSUInteger)completeBytes total:(NSUInteger)totalBytes;
- (void)bleShell:(id<SFTransmissionShell>)shell isSuccess:(BOOL)success error:(nullable SFCoreError *)error;

@end

@protocol SFTransmissionShell <NSObject>
@property (nonatomic,weak) id<SFBleShellDelegate> delegate;
@property (nonatomic,assign,readonly)SFBleShellStatus status;
- (BOOL)isBusy;
  /** 仅ble方式有效*/
- (void)stop;;

@optional
- (void)startTcpListen:(uint16_t)port;
- (void)setSocketMtu:(uint16_t)kMtu;

@end
NS_ASSUME_NONNULL_END

#endif /* SFBleShellStatus_h */
