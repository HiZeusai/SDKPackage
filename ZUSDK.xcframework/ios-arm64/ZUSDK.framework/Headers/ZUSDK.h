//
//  PBSDK.h
//  PBSDK
//
//  Created by yoka on 2024/5/28.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <ZUSDK/ZUSDKConfig.h>
#import <ZUSDK/GResult.h>
#import <ZUSDK/ZUUser.h>
#import <ZUSDK/ZUUserResult.h>
#warning 具体int值需要重新定义
typedef NS_ENUM(NSUInteger, ZUSocialType) {
    ZUSocialTypeFacebook = 13,
    ZUSocialTypeGoogle = 14,
    ZUSocialTypeApple = 15,
    ZUSocialTypeTwitter = 16,
    ZUSocialTypeLine = 17
};

typedef void (^OpenWebViewBlock)(NSDictionary *param);

@interface ZUSDK : NSObject

@property (nonatomic, copy, readonly, class) NSString *SDKVer;

@property (nonatomic, copy) NSArray *supportLoginPlatform;

+ (instancetype)sharedInstance;

- (void)initConfigWithBlock:(void(^)(BOOL initResult))block;

/// 登录
- (void)login:(ZUUserResultBlock)completion;

/// 显示TostView
- (void)showSuccessToastView:(void (^)(BOOL))block;

///监听订单接口，务必在支付成功后进行调用，角色相关的信息按照以下格式进行传参
///@{@"roleId":@"",@"roleName":@"",@"serverId":@"",@"serverName":@""}
- (void)enterGame:(NSDictionary *)gameInfo;

/// 三方
- (void)socialBindWithCompletion:(ZUUserResultBlock)completion;

///获取绑定列表
- (NSArray *)getAccountBindList;

- (void)logout:(void(^)(BOOL))completion;

///三方跳转
+ (void)application:(UIApplication *)application openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;
+ (void)application:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> *))restorationHandler;
@end
