//
//  ZSRewardedAdSession.h
//  ZSSDK
//

#import <Foundation/Foundation.h>
#import "ZSAdSessionTypes.h"

NS_ASSUME_NONNULL_BEGIN

typedef ZSAdSessionEventHandler ZSRewardedAdEventHandler;

/// 单次激励广告展示会话：在 `-show` 前设置各 `on*` block；展示在关闭或展示失败后自动卸载 `GSCallbackManager` 中对应槽位。
/// 仅在与 `initWithUrl:appId:withCompletion:` 相同的 block 模式下生效；delegate 初始化时广告仍走 `onResultCode`。
@interface ZSRewardedAdSession : NSObject

@property (nonatomic, copy, readonly) NSString *unitId;
@property (nonatomic, copy, readonly) NSString *placementId;

@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onShow;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onClick;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onHide;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onPayRevenue;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onReward;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onDisplayFailed;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithUnitId:(NSString *)unitId andPlacementId:(NSString *)placementId NS_DESIGNATED_INITIALIZER;

/// 预加载（`extendCode == AD_FINISH_LOADING`）。
- (void)loadWithCompletion:(nullable ZSAdSessionEventHandler)completion
NS_SWIFT_NAME(load(completion:));

/// 安装生命周期 block 并请求展示。
- (void)show NS_SWIFT_NAME(show());

/// 清除已安装的展示相关 block；若在 `loadWithCompletion:` 后尚未收到加载回调，同时清除加载 completion。
- (void)invalidate;

@end

NS_ASSUME_NONNULL_END
