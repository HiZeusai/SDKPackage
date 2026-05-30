//
//  GSWebParams.h
//  GSSDK
//
//  Created by yoka on 2023/11/8.
//

#import "GSParamsBase.h"
#import "ZSEnum.h"

@interface ZSWebParams : GSParamsBase
@property (nonatomic, strong, readonly) NSString *webUrl;
@property (nonatomic, assign, readonly) ZSWebOrientationType orientationType;

/// 传入webView的链接
/// - Parameter webUrl: 链接参数
- (void)setWebUrl:(NSString *)webUrl;

/// 设置屏幕方向
/// - Parameter orientationType: 横竖屏参数传值
- (void)setOrientationType:(ZSWebOrientationType)orientationType;
@end
