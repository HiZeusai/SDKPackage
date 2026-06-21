//
//  GSSDK.h
//  GSSDK
//
//  Created by yoka on 2022/1/29.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
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
#import "ZSSDKPublic.h"
#import "ZSAdSessionTypes.h"
#import "ZSRewardedAdSession.h"
#import "ZSSplashAdSession.h"
#import "ZSInterstitialAdSession.h"
#import "ZSBannerAdSession.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZSSDK : NSObject

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
/// @param url 请求域名地址
/// @param appId appId
/// @param completion 返回参数
- (void)initWithUrl:(NSString *)url
              appId:(NSString *)appId
     withCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(configure(url:appId:completion:));

/// 客户端方便动态配置参数
/// @param params 参数
/// @param pluginName 插件名字
- (void)setPluginParams:(NSDictionary<NSString *, id> *)params
             withPlugin:(NSString *)pluginName
NS_SWIFT_NAME(setPluginParams(_:forPlugin:));

/// Adjust deferred deeplink 回调（block 模式）。
/// @param completion ret=STATUS_SUCCESS；result=deeplink URL；extendCode=1 Adjust 自动打开，0 游戏自行处理
- (void)setAdjustDeferredDeeplinkCompletion:(void(^)(int ret, NSString *result, int extendCode))completion
NS_SWIFT_NAME(setAdjustDeferredDeeplinkCompletion(_:));

/// 同步读取 Keychain 中已缓存的 IDFA（未授权时可能为空）。
- (NSString *)getIDFA NS_SWIFT_NAME(getIDFA());

/// 请求 ATT 并异步返回 IDFA。
/// @param completion 返回参数
- (void)getIDFAInfo:(void(^)(NSString *result))completion
NS_SWIFT_NAME(getIDFAInfo(completion:));

/// @param completion 返回参数
- (void)getIDFVInfo:(void(^)(NSString *result))completion
NS_SWIFT_NAME(getIDFVInfo(completion:));

/// @param completion 返回参数
- (void)getAccidInfo:(void(^)(NSString *result))completion
NS_SWIFT_NAME(getAccidInfo(completion:));

/// 平台登陆接口
/// @param completion 返回参数
- (void)loginWithCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(login(completion:));

/// 平台登出接口
/// @param completion 返回参数
- (void)logoutWithCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(logout(completion:));

/// 支付
/// @param payParams 支付参数
/// @param completion 返回参数
- (void)pay:(ZSPayParams *)payParams
withCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(pay(_:completion:));

/// 查询商品信息接口
/// @param productIds 商品信息id
/// @param completion 返回参数
- (void)queryProductDetails:(NSArray<NSString *> *)productIds
             withCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(queryProductDetails(_:completion:));

/// 重支付接口
- (void)listenTransationPay
NS_SWIFT_NAME(listenTransationPayment());



/// 绑定UserId
/// @param gameZone 区服
/// @param userI产品方的userId
/// @param accId accId
/// @param completion 返回参数
- (void)bindUserIdWithGameZone:(NSString *)gameZone
                        userId:(NSString *)userId
                         accId:(NSString *)accId
                withCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(bindUser(gameZone:userId:accId:completion:));


/// 绑定渠道的用户体系页面的绑定页面
/// @param completion 返回参数
- (void)bindAccountWithCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(bindAccount(completion:));

/// 自定义事件
/// @param key 自定义事件key
/// @param parameters 自定义事件参数
- (void)eventCustom:(NSString *)key
        parameters:(nullable NSDictionary<NSString *, id> *)parameters
NS_SWIFT_NAME(trackEvent(_:parameters:));



/// 分享
/// @param ZSShareParams 支付参数
/// @param completion 返回参数
- (void)share:(ZSShareParams *)shareParams
withCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(share(_:completion:));

#pragma mark - 开屏广告

- (ZSSplashAdSession *)prepareSplashAdSessionWithUnitId:(NSString *)unitId
                                       andPlacementId:(NSString *)placementId
NS_SWIFT_NAME(prepareSplashAdSession(unitId:placementId:));

#pragma mark - 插屏广告

- (ZSInterstitialAdSession *)prepareInterstitialAdSessionWithUnitId:(NSString *)unitId
                                                   andPlacementId:(NSString *)placementId
NS_SWIFT_NAME(prepareInterstitialAdSession(unitId:placementId:));

#pragma mark - 激励视频广告

- (ZSRewardedAdSession *)prepareRewardedSessionWithUnitId:(NSString *)unitId
                                           andPlacementId:(NSString *)placementId
NS_SWIFT_NAME(prepareRewardedSession(unitId:placementId:));

#pragma mark - 横幅广告

- (ZSBannerAdSession *)prepareBannerAdSessionWithUnitId:(NSString *)unitId
                                       andPlacementId:(NSString *)placementId
                                               adSize:(CGSize)adSize
                                        containerView:(nullable UIView *)containerView
NS_SWIFT_NAME(prepareBannerAdSession(unitId:placementId:size:container:));


- (void)loadNativeAd NS_SWIFT_NAME(loadNativeAd());

/// 扩展接口
/// @param paramsBase 需要功能的属性
- (void)handleExtendedMethod:(GSParamsBase *)paramsBase
NS_SWIFT_NAME(handle(_:));

@end

NS_ASSUME_NONNULL_END
