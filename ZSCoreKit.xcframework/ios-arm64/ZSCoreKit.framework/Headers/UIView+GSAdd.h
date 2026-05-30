//
//  UIView+GSAdd.h
//  GSCoreKit
//
//  Created by ritchie on 2024/7/15.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (GSAdd)
- (void)gs_addBordersWithCornerRadius:(CGFloat)radius
                                width:(CGFloat)borderWidth
                                color:(UIColor *)color;

- (void)gs_addBordersWithCornerRadius:(CGFloat)radius
                                color:(UIColor *)color;

- (void)gs_addBordersWithCorners:(UIRectCorner)corners
                    cornerRadius:(CGFloat)cornerRadius
                           width:(CGFloat)borderWidth
                           color:(UIColor *)borderColor;

- (void)gs_removeBorders;
@end

NS_ASSUME_NONNULL_END
