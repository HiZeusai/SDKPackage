//
//  ZSInterstitialAdSession.h
//  ZSSDK
//

#import <Foundation/Foundation.h>
#import "ZSAdSessionTypes.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZSInterstitialAdSession : NSObject

@property (nonatomic, copy, readonly) NSString *unitId;
@property (nonatomic, copy, readonly) NSString *placementId;

@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onShow;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onClick;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onHide;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onPayRevenue;
@property (nonatomic, copy, nullable) ZSAdSessionEventHandler onDisplayFailed;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithUnitId:(NSString *)unitId andPlacementId:(NSString *)placementId NS_DESIGNATED_INITIALIZER;

- (void)loadWithCompletion:(nullable ZSAdSessionEventHandler)completion
NS_SWIFT_NAME(load(completion:));

- (void)show NS_SWIFT_NAME(show());

- (void)invalidate;

@end

NS_ASSUME_NONNULL_END
