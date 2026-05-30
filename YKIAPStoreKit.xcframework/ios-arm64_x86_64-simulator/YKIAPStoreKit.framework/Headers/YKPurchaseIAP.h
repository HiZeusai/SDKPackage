//
//  YKPurchaseIAP.h
//  YKIAPStoreKit
//
//  Created by qingyun on 2024/6/20.
//

#import <Foundation/Foundation.h>
@class YKTransaction;
@class YKIAPResult;
@class YKPromotionalOfferInfo;

@protocol YKPurchaseIAPDelegate;

typedef NS_ENUM(NSUInteger, YKIAPStoreKitType) {
    YKIAP_StoreKitTypeAuto           = 0,    /**< 自动切换OS15以上用StoreKit2   */
    YKIAP_StoreKit1                  = 1,    /**< StoreKit1    */
};

NS_ASSUME_NONNULL_BEGIN

typedef void(^YKPurchaseIAPBlock)(YKIAPResult *result);

@interface YKPurchaseIAP : NSObject

+ (instancetype)sharedInstance;
- (instancetype)init NS_UNAVAILABLE;

/**
 * 获取商品信息
 * param productIds  数组类型 苹果后台配置的productIds  如NSArray *arr = @[@"com.yoka.newsgs.rmb60", @"com.yoka.newsgs.rmb488", @"com.yoka.newsgs.rmb12"];
 * param type  请求方式
 * completion  回调block
 */
- (void)getProductInfo:(NSArray<NSString *> *)productIds withType:(YKIAPStoreKitType)type completion:(YKPurchaseIAPBlock)completion;

/**
 * 发起支付请求
 * param productId  苹果后台配置的productId
 * param type  请求方式
 * param orderId  业务订单号，购买成功/失败回调中可通过 YKTransaction.sdkTradeNo 取回
 * param udid 标准 UUID 字符串，iOS 15+ StoreKit2 会作为 appAccountToken 传给苹果（不参与促销签名）
 * callback  purchaseSuccess purchasefailed
 */
- (void)requestPurchase:(NSString *)productId withType:(YKIAPStoreKitType)type withUsername:(NSString*)orderId  withUDID:(NSString*)udid withDelegate:(id)delegate;

/**
 * 发起支付请求（支持促销优惠）
 * param productId  苹果后台配置的productId
 * param type  请求方式
 * param orderId  业务订单号，购买成功/失败回调中可通过 YKTransaction.sdkTradeNo 取回
 * param udid 标准 UUID 字符串，iOS 15+ StoreKit2 会作为 appAccountToken 传给苹果（不参与促销签名）
 * param promotionalOfferInfo  促销优惠签名信息（可选，如果传入则使用促销优惠购买）
 * callback  purchaseSuccess purchasefailed
 */
- (void)requestPurchase:(NSString *)productId withType:(YKIAPStoreKitType)type withUsername:(NSString*)orderId withUDID:(NSString*)udid withPromotionalOfferInfo:(nullable YKPromotionalOfferInfo *)promotionalOfferInfo withDelegate:(id)delegate;



/**
 * 发起支付请求
 * param productId  苹果后台配置的productId
 * param type  请求方式
 * aram applicationUsername  自定义order
 * callback  purchaseSuccess purchasefailed
 */
-(void)listenTransation:(id)delegate;

/**
 * 结束订单
 * 注意！ 一定要在支付验证成功后及时结束当前订单
 */
- (void)finishTransaction;

/**
 * 结束监听
 * 注意！切换账号的时候结束
 */
- (void)removePaymentQueue;

@end

@protocol YKPurchaseIAPDelegate <NSObject>

@optional
- (void)purchaseSuccess:(YKIAPResult *)result;
- (void)purchasefailed:(YKIAPResult *)result;
- (void)shouldAddStorePayment:(YKIAPResult *)result;
@end

NS_ASSUME_NONNULL_END
