//
//  ZSSplashAdSession.h
//  ZSSDK
//

#import <Foundation/Foundation.h>
#import "ZSAdSessionTypes.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZSSplashAdSession : NSObject

@property (nonatomic, copy, readonly) NSString *unitId;

@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onShow;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onClick;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onHide;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onPayRevenue;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onDisplayFailed;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithUnitId:(NSString *)unitId NS_DESIGNATED_INITIALIZER;

- (void)loadWithCompletion:(nullable ZSAdSessionEventHandler)completion
NS_SWIFT_NAME(load(completion:));

/// placementId 可选；传 nil 表示不做 AppLovin 场景统计。
- (void)showWithPlacementId:(nullable NSString *)placementId NS_SWIFT_NAME(show(placementId:));

- (void)invalidate;

@end

NS_ASSUME_NONNULL_END
