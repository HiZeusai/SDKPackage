//
//  GSAppConfig.h
//  GSSDK
//
//  Created by YOKA on 2023/4/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZSAppConfig : NSObject
/// 组件
@property (nonatomic, copy, readonly, class) NSDictionary *plugins;

+ (NSArray *)pluginsWithType:(NSString *)type;
+ (NSArray *)supportLoginPlatform;
+ (NSDictionary *)plugins;
@end

NS_ASSUME_NONNULL_END
