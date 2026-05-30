//
//  GSSDKDelegateProtocol.h
//  GSSDK
//
//  Created by yoka on 2022/1/29.
//  Copyright © 2022 Boson. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ZSDelegateProtocol <NSObject>

- (void)onResultCode:(int)code method:(ZSCallbackType)method result:(NSString *)result andExtendCode:(int)extendCode;

@end
