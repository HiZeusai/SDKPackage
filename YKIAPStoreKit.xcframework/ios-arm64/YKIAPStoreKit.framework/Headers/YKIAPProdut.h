//
//  YKIAPProdut.h
//  YKIAPStoreKit
//
//  Created by qingyun on 2024/8/22.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface YKIAPProdut : NSObject
@property (nonatomic, strong) NSString *productId;             //商品名：com.xxx.xxx
@property (nonatomic, strong) NSString *localeCurrencyCode;    //货币类型：CHY
@property (nonatomic, strong) NSString *price;                 //价格6
@property (nonatomic, strong) NSString *localizedDescription;  //商品描述
@property (nonatomic, strong) NSString *currencySymbol;        //货币符号¥
@property (nonatomic, strong) NSString *priceAndCurrencySymbol;//货币符号¥6.00
@end

NS_ASSUME_NONNULL_END
