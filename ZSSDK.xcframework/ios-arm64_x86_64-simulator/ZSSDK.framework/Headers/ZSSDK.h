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
@class UIView;

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


/// 隐私权限申请
/// @param completion 返回参数
- (void)getIDFAInfo:(void(^)(NSString *result))completion
NS_SWIFT_NAME(getIDFAInfo(completion:));

/// @param completion 返回参数
- (void)getIDFVInfo:(void(^)(NSString *result))completion
NS_SWIFT_NAME(getIDFVInfo(completion:));


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

// 开屏广告 - 带 completion
- (void)loadSplashAd:(NSString *)unitId
      andPlacementId:(NSString *)placementId
      withCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(loadSplashAd(unitId:placementId:completion:));


- (void)showSplashAd:(NSString *)unitId
     andPlacementId:(NSString *)placementId
      withCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(showSplashAd(unitId:placementId:completion:));


// 插屏广告 - 带 completion
- (void)loadInterstitiaAd:(NSString *)unitId
          andPlacementId:(NSString *)placementId
           withCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(loadInterstitialAd(unitId:placementId:completion:));


- (void)showInterstitialAd:(NSString *)unitId
           andPlacementId:(NSString *)placementId
            withCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(showInterstitialAd(unitId:placementId:completion:));


// 激励视频广告 - 带 completion
- (void)loadRewardVideoAd:(NSString *)unitId
           andPlacementId:(NSString *)placementId
           withCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(loadRewardedAd(unitId:placementId:completion:));


- (void)showRewardVideoAd:(NSString *)unitId
           andPlacementId:(NSString *)placementId
           withCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(showRewardedAd(unitId:placementId:completion:));


// 横幅广告 - 带 completion
- (void)loadBannerAd:(NSString *)unitId
      andPlacementId:(NSString *)placementId
              adSize:(CGSize)adSize
              adView:(UIView *)adView
      withCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(loadBannerAd(unitId:placementId:size:in:completion:));


- (void)showBannerAd:(NSString *)unitId
      andPlacementId:(NSString *)placementId
              adSize:(CGSize)adSize
              adView:(UIView *)adView
      withCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(showBannerAd(unitId:placementId:size:in:completion:));


- (void)removeBannerAd:(NSString *)unitId
        andPlacementId:(NSString *)placementId
        withCompletion:(void(^)(int ret, NSString *result,int extendCode))completion
NS_SWIFT_NAME(removeBannerAd(unitId:placementId:completion:));


- (void)loadNativeAd NS_SWIFT_NAME(loadNativeAd());

/// 扩展接口
/// @param paramsBase 需要功能的属性
- (void)handleExtendedMethod:(GSParamsBase *)paramsBase
NS_SWIFT_NAME(handle(_:));

@end

NS_ASSUME_NONNULL_END
