//
//  ZSSDKPublic.h
//  ZSSDK
//
//  Created by 1234 on 2025/10/22.
//

#import <Foundation/Foundation.h>
#import "ZSEnum.h"
#import "ZSDelegateProtocol.h"
#import "ZSPayParams.h"
#import "ZSUserParams.h"
#import "ZSHelpParams.h"
#import "ZSShareParams.h"
#import "ZSCrashReportParams.h"
#import "ZSAppConfig.h"
#import "ZSWebParams.h"
#import "ZSData.h"
#import "ZSSplashAdSession.h"
#import "ZSInterstitialAdSession.h"
#import "ZSRewardedAdSession.h"
#import "ZSBannerAdSession.h"

@class UIView;
NS_ASSUME_NONNULL_BEGIN

@interface ZSSDKPublic : NSObject
@property (nonatomic, copy, readonly) NSString *SDKVer NS_SWIFT_NAME(sdkVersion);
/// 日志打印，默认为YES
@property (nonatomic, assign) BOOL logEnable;
/// loading框，默认为SDK的loading框
@property (nonatomic, strong, nullable) UIView *indicatorView;
/// 吐司开关，默认不打开如果想要SDK弹错误提示打开即可
@property (nonatomic, assign) BOOL toastEnable;

/// 禁用 init 初始化
- (instancetype)init NS_UNAVAILABLE;
/// 禁用 new 初始化
+ (instancetype)new NS_UNAVAILABLE;

+ (instancetype)sharedInstance NS_SWIFT_NAME(shared());

/// 平台初始接口
/// @param delegate 被委托对象
/// @param url 请求域名地址
- (void)initWithDeleagte:(id<ZSDelegateProtocol>)delegate
                     url:(NSString *)url
                   appId:(NSString *)appId
NS_SWIFT_NAME(configure(delegate:url:appId:));

/// 客户端方便动态配置参数
/// @param params 参数
/// @param pluginName 插件名字
- (void)setPluginParams:(NSDictionary<NSString *, id> *)params
             withPlugin:(NSString *)pluginName
NS_SWIFT_NAME(setPluginParams(_:forPlugin:));


/// 同步读取 Keychain 中已缓存的 IDFA（未授权时可能为空）。
- (NSString *)getIDFA NS_SWIFT_NAME(getIDFA());

/// 请求 ATT 并异步返回 IDFA。
/// @param completion 返回参数
- (void)getIDFAInfo:(void(^)(NSString *result))completion
NS_SWIFT_NAME(getIDFAInfo(completion:));

- (void)getIDFVInfo:(void(^)(NSString *result))completion
NS_SWIFT_NAME(getIDFVInfo(completion:));

/// 平台登陆接口
- (void)login NS_SWIFT_NAME(login());

/// 平台登出接口
- (void)logout NS_SWIFT_NAME(logout());

/// 支付
/// @param payParams 支付参数
- (void)pay:(ZSPayParams *)payParams NS_SWIFT_NAME(pay(_:));

/// 查询商品信息接口
/// @param productIds 商品信息id
- (void)queryProductDetails:(NSArray<NSString *> *)productIds
NS_SWIFT_NAME(queryProductDetails(_:));

/// 重支付接口
- (void)listenTransationPay
NS_SWIFT_NAME(listenTransationPayment());

/// 绑定UserId
- (void)bindUserIdWithGameZone:(NSString *)gameZone
                        userId:(NSString *)userId
                         accId:(NSString *)accId
NS_SWIFT_NAME(bindUser(gameZone:userId:accId:));

/// 分享
/// @param ZSShareParams 支付参数
/// @param completion 返回参数
- (void)share:(ZSShareParams *)shareParams
withCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(share(_:completion:));

/// 自定义事件
/// @param key 自定义事件key
/// @param parameters 自定义事件参数
- (void)eventCustom:(NSString *)key
        parameters:(nullable NSDictionary<NSString *, id> *)parameters
NS_SWIFT_NAME(trackEvent(_:parameters:));

#pragma mark - 广告（delegate 模式）

/// 广告事件走 `ZSDelegateProtocol`：`method == ZSCallbackType_AD`，`extendCode` 区分子类型。使用 `prepare*Session` 后调用 `-load` / `-show` / `-remove`（横幅）。

- (ZSSplashAdSession *)prepareSplashAdSessionWithUnitId:(NSString *)unitId
                                       andPlacementId:(NSString *)placementId
__attribute__((swift_attr("@MainActor")))
NS_SWIFT_NAME(prepareSplashAdSession(unitId:placementId:));

- (ZSInterstitialAdSession *)prepareInterstitialAdSessionWithUnitId:(NSString *)unitId
                                                   andPlacementId:(NSString *)placementId
__attribute__((swift_attr("@MainActor")))
NS_SWIFT_NAME(prepareInterstitialAdSession(unitId:placementId:));

- (ZSRewardedAdSession *)prepareRewardedSessionWithUnitId:(NSString *)unitId
                                           andPlacementId:(NSString *)placementId
__attribute__((swift_attr("@MainActor")))
NS_SWIFT_NAME(prepareRewardedSession(unitId:placementId:));

- (ZSBannerAdSession *)prepareBannerAdSessionWithUnitId:(NSString *)unitId
                                       andPlacementId:(NSString *)placementId
                                               adSize:(CGSize)adSize
                                        containerView:(nullable UIView *)containerView
__attribute__((swift_attr("@MainActor")))
NS_SWIFT_NAME(prepareBannerAdSession(unitId:placementId:size:container:));

- (void)loadNativeAd NS_SWIFT_NAME(loadNativeAd());

/// 扩展接口
/// @param paramsBase 需要功能的属性
- (void)handleExtendedMethod:(GSParamsBase *)paramsBase
NS_SWIFT_NAME(handle(_:));

@end

NS_ASSUME_NONNULL_END
