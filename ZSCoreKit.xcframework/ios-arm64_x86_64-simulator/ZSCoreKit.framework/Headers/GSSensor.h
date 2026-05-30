//
//  GSSensor.h
//  GSCoreKit
//
//  Created by ritchie on 2024/8/19.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>
NS_ASSUME_NONNULL_BEGIN

@interface GSSensor : NSObject
@property (nonatomic, strong, nullable) CMDeviceMotion *motion;
+ (instancetype)shared;
- (NSString *)accelerationString;
- (NSString *)rotationRateString;
- (NSString *)magneticFieldString;
- (NSString *)gravityString;
@end

NS_ASSUME_NONNULL_END
