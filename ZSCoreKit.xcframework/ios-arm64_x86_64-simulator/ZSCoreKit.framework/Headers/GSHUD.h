//
//  GSHUD.h
//  ZSCoreKit
//
//  Created by 1234 on 2025/9/16.
//

#import <UIKit/UIKit.h>

#define GSHUDIns [GSHUD sharedInstance]
@interface GSHUD : UIView
@property (nonatomic, strong) UIControl *maskControl;
@property (nonatomic, strong) UIActivityIndicatorView *indicatorView;
@property (nonatomic, strong) UIView *customIndicatorView;

+ (instancetype)sharedInstance;

- (void)show;
- (void)dismiss;

// 用户只需要调用这个方法，传入自己的 View
- (void)setCustomView:(UIView *)customView;
@end
