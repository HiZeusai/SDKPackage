//
//  UIImage+GSAdd.h
//  GSCoreKit
//
//  Created by ritchie on 2024/7/12.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (GSAdd)
+ (UIImage *)gs_imageWithNamed:(NSString *)name inBundle:(NSBundle *)bundle;
+ (UIImage *)gs_imageWithColor:(UIColor *)color;

- (UIImage *)gs_imageWithTintColor:(UIColor *)tintColor;
@end

NS_ASSUME_NONNULL_END
