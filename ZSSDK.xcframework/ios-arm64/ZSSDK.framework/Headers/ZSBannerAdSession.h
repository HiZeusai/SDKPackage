//
//  ZSBannerAdSession.h
//  ZSSDK
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ZSAdSessionTypes.h"

NS_ASSUME_NONNULL_BEGIN

/// 横幅广告会话：`load` → `show` → `remove`。
@interface ZSBannerAdSession : NSObject

@property (nonatomic, copy, readonly) NSString *unitId;
@property (nonatomic, copy, readonly) NSString *placementId;
@property (nonatomic, assign, readonly) CGSize adSize;
@property (nonatomic, weak, readonly, nullable) UIView *containerView;

@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onShow;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onClick;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onHide;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onPayRevenue;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onDisplayFailed;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithUnitId:(NSString *)unitId
                andPlacementId:(NSString *)placementId
                          adSize:(CGSize)adSize
                   containerView:(nullable UIView *)containerView NS_DESIGNATED_INITIALIZER;

/// 创建横幅视图并预加载（`AD_FINISH_LOADING`）。
- (void)loadWithCompletion:(nullable ZSAdSessionEventHandler)completion
NS_SWIFT_NAME(load(completion:));

/// 安装 `on*` 并请求展示/刷新。
- (void)show NS_SWIFT_NAME(show());

/// 移除横幅视图并卸载 session 已安装的展示回调；`extendCode` 为 `ZSCallbackType_AD_REMOVE_BANNER`。
- (void)removeWithCompletion:(nullable ZSAdSessionEventHandler)completion
NS_SWIFT_NAME(remove(completion:));

/// 等价于 `removeWithCompletion:nil`。
- (void)invalidate;

@end

NS_ASSUME_NONNULL_END
