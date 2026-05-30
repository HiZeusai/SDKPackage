//
//  GSSDKData.h
//  GSSDK
//
//  Created by yoka on 2022/1/30.
//  Copyright © 2022 Boson. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ZSData : NSObject
// sdk
@property (nonatomic, copy) NSString *sdkUserID;        // 3rdsdk用户id
// game
@property (nonatomic, copy) NSString *gameUserID;       // 游戏角色ID
@property (nonatomic, copy) NSString *gameUserName;     // 游戏角色名称
@property (nonatomic, copy) NSString *gameUserLevel;    // 游戏角色等级
@property (nonatomic, copy) NSString *serverId;         // 游戏服务器ID
@property (nonatomic, copy) NSString *serverName;       // 游戏服务器名称

/// 禁用 init 初始化
- (instancetype)init NS_UNAVAILABLE;
/// 禁用 new 初始化
+ (instancetype)new NS_UNAVAILABLE;

+ (instancetype)sharedInstance;

- (void)reset;

@end


