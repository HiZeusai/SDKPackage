//
//  YKPromotionalOfferInfo.h
//  YKIAPStoreKit
//
//  Created on 2024/12/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 促销优惠签名信息
/// 用于 StoreKit 2 的 Promotional Offer 购买
@interface YKPromotionalOfferInfo : NSObject

/// 优惠 ID（必填）
@property (nonatomic, strong) NSString *offerID;

/// 密钥 ID（必填）
@property (nonatomic, strong) NSString *keyID;

/// 随机数（必填）
@property (nonatomic, strong) NSString *nonce;

/// 签名（必填）
@property (nonatomic, strong) NSString *signature;

/// 时间戳（必填）
@property (nonatomic, strong) NSString *timestamp;

/// 强制使用生产环境签名验证（用于测试生产环境签名流程）
/// 设置为 YES 时，即使在 DEBUG 模式下也会要求提供真实签名
@property (nonatomic, assign) BOOL forceProductionSignatureValidation;

/// 检查所有必填字段是否都已设置
- (BOOL)isValid;

@end

NS_ASSUME_NONNULL_END

