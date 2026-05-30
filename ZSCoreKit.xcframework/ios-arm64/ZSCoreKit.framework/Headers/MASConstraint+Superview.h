//
//  MASConstraint+Superview.h
//  GSCoreKit
//
//  Created by ritchie on 2024/7/15.
//

#import "MASConstraint.h"
#import "MASViewConstraint.h"
NS_ASSUME_NONNULL_BEGIN

@interface MASConstraint (Superview)
- (MASConstraint *(^)(void))mas_equalToSuperview;
- (MASConstraint *(^)(void))equalToSuperview;

- (MASConstraint *(^)(void))mas_greaterThanOrEqualToSuperview;
- (MASConstraint *(^)(void))greaterThanOrEqualToSuperview;

- (MASConstraint *(^)(void))mas_lessThanOrEqualToSuperview;
- (MASConstraint *(^)(void))lessThanOrEqualToSuperview;

- (NSLayoutConstraint *)layoutConstraint;
@end

@interface MASViewConstraint (NSLayoutConstraint)
- (NSLayoutConstraint *)layoutConstraint;

@end

NS_ASSUME_NONNULL_END
