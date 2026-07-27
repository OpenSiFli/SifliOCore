//
//  SFBleShell.h
//  SifliOCore
//
//  Created by Sean on 2023/12/21.
//

#import <Foundation/Foundation.h>
#import <SifliOCore/SFCoreError.h>
#import <SifliOCore/SFModuleBase.h>
#import <SifliOCore/SFBleShellStatus.h>

NS_ASSUME_NONNULL_BEGIN

@interface SFSocketShell : NSObject<SFTransmissionShell,SFModuleDelegate>
@property (nonatomic,weak) id<SFBleShellDelegate> delegate;
@property (nonatomic,assign,readonly) BOOL isBusy;
@property (nonatomic,assign,readonly)SFBleShellStatus status;
//@property (nonatomic,copy,nullable) NSString *targetDevIdentifier;
//用于SerialTransPacket,默认为0x00,在子类根据业务指定
@property (nonatomic,assign)uint8_t cateID;
@property (nonatomic,strong,nullable) SFModuleBase *currentModule;
///停止工作，断开连接
- (void)stop;
- (void)clearCaches;
//返回蓝牙是否可用
- (SFBleCoreManagerState)bleCoreState;
///设置blecore的委托到自身，避免多模块工作冲突。
- (void)updateBleCoreDelegateToSelf;
///开始TCP监听
- (void)startTcpListen:(uint16_t)port;
- (void)setSocketMtu:(uint16_t)kMtu;

@end

NS_ASSUME_NONNULL_END
