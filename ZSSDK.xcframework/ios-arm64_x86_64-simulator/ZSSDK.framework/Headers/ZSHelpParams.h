//
//  GSHelpParams.h
//  GSSDK
//
//  Created by YOKA on 2023/5/18.
//

#import "GSParamsBase.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, GSHelpMethod) {
    GSHelpMethodOpenService = 1
};

@interface ZSHelpParams : GSParamsBase

@property (nonatomic, assign, readonly) GSHelpMethod helpMethod;

- (void)openService;

@end

NS_ASSUME_NONNULL_END
