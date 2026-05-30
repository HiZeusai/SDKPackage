//
//  PayParams.h
//  GSSDK
//
//  Created by sen on 2021/12/14.
//

#import <Foundation/Foundation.h>
#import "GSParamsBase.h"

@interface ZSPayParams : GSParamsBase

/// 产品方的订单号，请勿赋值
@property (nonatomic, copy) NSString *orderId;
/// 产品方的产品Id,请勿赋值
@property (nonatomic, copy) NSString *goodsId;
/// sdk生成的订单号
@property (nonatomic, copy) NSString *sdkTradeNo;

/// 共有参数
@property (nonatomic, copy) NSString *productId;
@property (nonatomic, copy) NSString *productName;
@property (nonatomic, strong) NSNumber *price;
@property (nonatomic, copy) NSString *serverId;
@property (nonatomic, copy) NSString *serverName;
@property (nonatomic, copy) NSString *roleId;
@property (nonatomic, copy) NSString *roleName;
@property (nonatomic, copy) NSString *roleLevel;
@property (nonatomic, copy) NSString *payNotifyUrl;
@property (nonatomic, copy) NSString *extension;
@property (nonatomic, copy) NSString *offerId;

//新增参数  ---新增为IAP查询使用
@property (nonatomic, copy) NSString *currency;
@property (nonatomic, copy) NSString *details;
@property (nonatomic, assign) BOOL isAvailable;  //是否查询成功
@property (nonatomic, copy) NSString *detailsDescription; //商品价格符号
@property (nonatomic, copy) NSString *currencyCode;  //商品价格代码
@property (nonatomic, copy) NSString *appAccountToken;//可配置，苹果标准的UUID格式

//新增参数 -----新增参数gameNotifyUrl 用于游戏进行测试gameNotifyUrl
@property (nonatomic, copy) NSString *gameNotifyUrl;


@end
