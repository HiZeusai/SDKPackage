//
//  UserParams.h
//  GSSDK
//
//  Created by sen on 2021/12/14.
//

#import <Foundation/Foundation.h>
#import "GSParamsBase.h"

typedef NS_ENUM(NSInteger, GSUserMethod) {
    GSUserMethodBind = 1,
    GSUserMethodSwitch,
    GSUserMethodHideGuest,
};

@interface ZSUserParams : GSParamsBase

@property (nonatomic, assign, readonly) GSUserMethod userMethod;
@property (nonatomic, assign, readonly) BOOL isPublicSecurity;

- (void)setUserBind;
- (void)setUserSwitch;
- (void)setHideGuest;

@end
