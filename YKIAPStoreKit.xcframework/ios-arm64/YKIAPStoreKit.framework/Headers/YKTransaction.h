//
//  YKTransaction.h
//  YKIAPStoreKit
//
//  Created by qingyun on 2024/6/20.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface YKTransaction : NSObject
@property (nonatomic, strong) NSString *productId;             //商品名：com.xxx.xxx
@property (nonatomic, strong) NSString *transactionId;         //苹果返回的ID：2000000637533031
@property (nonatomic, strong) NSString *receipt;               //base64 
/// 业务订单号，对应 requestPurchase 的 withUsername 参数
@property (nonatomic, strong) NSString *sdkTradeNo;
/// StoreKit 2 购买时传入的 appAccountToken（UUID 字符串），由苹果交易原样返回；StoreKit 1 路径为空
@property (nonatomic, strong) NSString *appAccountToken;
@property (nonatomic, strong) NSString *localeCurrencyCode;    //货币类型：CHY
@property (nonatomic, strong) NSString *price;                 //价格
// 苹果 Transaction 的完整信息
@property (nonatomic, strong) NSString *originalTransactionId; // 原始交易ID
@property (nonatomic, strong) NSString *purchaseDate;          // 购买日期
@property (nonatomic, strong) NSString *purchaseDateTimeStamp; // 购买日期的时间戳
@property (nonatomic, strong) NSString *revocationDate;        // 撤销日期
@property (nonatomic, strong) NSString *revocationDateTimeStamp; // 撤销日期时间戳
@property (nonatomic, strong) NSString *expirationDate;        // 过期日期
@property (nonatomic, strong) NSString *expirationDateTimeStamp;  // 过期日期时间戳
@property (nonatomic, strong) NSString *isUpgraded;            // 是否升级
@property (nonatomic, strong) NSString *offerType;             // 优惠类型
@property (nonatomic, strong) NSString *offerID;               // 优惠ID
@property (nonatomic, strong) NSString *revocationReason;      // 撤销原因
@property (nonatomic, strong) NSString *environment;           // 环境
@property (nonatomic, strong) NSString *storefront;            // 商店
@property (nonatomic, strong) NSString *transactionState;      // 交易状态

- (instancetype)initWithSKPaymentTransaction:(SKPaymentTransaction *)transaction;
@end

NS_ASSUME_NONNULL_END
