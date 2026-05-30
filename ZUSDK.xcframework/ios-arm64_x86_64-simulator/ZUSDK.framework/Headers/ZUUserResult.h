//
//  PBUserResult.h
//  PBSDK
//
//  Created by yoka on 2024/6/3.
//

#import <ZUSDK/GResult.h>
#import <ZUSDK/ZUUser.h>
NS_ASSUME_NONNULL_BEGIN

@interface ZUUserResult : GResult

@property (nonatomic, strong) ZUUser *user;

@end

typedef void(^ZUUserResultBlock)(ZUUserResult *result);


NS_ASSUME_NONNULL_END
