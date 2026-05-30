//
//  PBSDKConfig.h
//  PBSDK
//
//  Created by yoka on 2024/5/28.
//

#import <Foundation/Foundation.h>
@interface ZUSDKConfig : NSObject

@property (nonatomic, strong) NSString *zeusUrl;
@property (nonatomic, strong) NSString *lang;
@property (nonatomic, strong) NSString *appId;            //平台的appID

@property (nonatomic, assign) BOOL  guestLoginOn;         // 设置游客登录是否默认开启
@property (nonatomic, strong) NSDictionary *loginSwitchConfig;//默认开关配置
@property (nonatomic, strong) NSString *agreementUrl;     //  用户协议的链接
@property (nonatomic, strong) NSString *privacyUrl;       //  隐私协议的链接
@property (nonatomic, strong) NSArray *supportLoginPlatform;


/// Twitter登录参数
@property (nonatomic, strong) NSString *twitterKey;
@property (nonatomic, strong) NSString *twitterSecret;

/// Line登录参数
@property (nonatomic, strong) NSString *lineChannelID;
@property (nonatomic, strong) NSString *lineUniversalLink;

+ (instancetype)sharedInstance;

- (instancetype)initWithUrl:(NSString *)zeusUrl appId:(NSString *)appId;


/// 设置Twitter参数
- (void)setTwitterKey:(NSString *)twitterKey twitterSecret:(NSString *)secret;

/// 设置Line参数
- (void)setLineChannelID:(NSString *)channelId universalLink:(NSString *)link;
@end
