//
//  GsCode.h
//  GSSDK
//
//  Created by sen on 2021/12/14.
//

#ifndef GSCode_h
#define GSCode_h

/// 请勿使用，后期会移除

/**
 * 通用
 */
#define STATUS_SUCCESS                  0
#define STATUS_FAILED                   1
#define STATUS_ERROR                    2
#define STATUS_CANCEL                   3
#define STATUS_PROCESS                  4
#define STATUS__UNKNOWN                 -1
#define STATUS_HTTP_200                 200
#define STATUS_HTTP_404                 404
#define STATUS_HTTP_500                 500

/**
 * 网络状态
 */
#define NETWORK_TYPE_RESTRICTED         101         // 网络受限
#define NETWORK_TYPE_NOTRESTRICTED      102         // 网络不受限

/**
 * 检查版本
 */
#define CHECK_VERSION_TYPE_NEW          1200        //检查到有版本更新
#define CHECK_VERSION_TYPE_WITHOUT_NEW  1201        //检查到没有版本更新
#define CHECK_VERSION_TYPE_WITHOUT      1202        //没有版本更新接口


#pragma mark 具体成功与失败一般是判定是否为0作为标识



#define BASE_APPNAMN_OR_CHANNEL_INVALID           1001         //AppName没有注册或者渠道错误
#define BASE_APPID_NOT_EXIST                      1002         //appId 不存在
#define BASE_CHECKSUM_NOT_EXIST                   1003         //checkSum 不存在
#define BASE_TIMESTAMP_NOT_EXIST                  1004         //timestamp 不存在
#define BASE_DEVICE_TYPE_NOT_EXIST                1005         //device_type 不存在
#define BASE_APPID_ERROR                          1006         //appId error
#define BASE_PLUGINS_EMPTY                        1007         //plugins 空




#define LOGIN_TOKEN_INVALID                       2001         //token不对
#define LOGIN_OPENID_OR_PLATFORM_EMPTY            2002          //openId或者传的平台为空
#define LOGIN_NOT_SUPPORT_PLATFORM                2003         //不支持的平台
#define LOGIN_DEVICEID_EMPTY                      2004        //deviceId不能为空
#define LOGIN_ONLY_TOURIST_PLATFORM               2005         //仅支持游客登录
#define LOGIN_ACCID_EMPTY                         2006         //accId为空
#define LOGIN_TOKEN_VERIFY_FAILURE                2007         //token验证失败




#define BIND_USERID_NOT_EMPTY                     3001         //userId不能为空
#define BIND_ACCID_NOT_FIND                       3002         //accId没有找到
#define BIND_OPENID_OR_PLATFORM_EMPTY             3003         //openId或者传的平台为空
#define BIND_ONLY_ONE_PLATFORM_NOT_UNBIND         3004         //仅绑定了一种平台不能解绑



#define PAY_PRODUCTID_NOT_EMPTY                   4001         //productId不能为空
#define PAY_ORDERID_NOT_EMPTY                     4002         //orderId不能为空
#define PAY_ORDERID_HAS_EXIST                     4003         //orderID已经存在
#define PAY_TOKEN_NOT_EMPTY                       4004         //支付token不能为空
#define PAY_TRANSACTIONID_NOT_EMPTY               4005        //交易ID号不能为空
#define PAY_RECHARGE_PLATFORM_ERROR               4006         //支付平台错误
#define PAY_ORDERID_NOT_EXIST                     4007         //订单不存在
#define PAY_ORDER_VERIFY_FAILED                   4008         //订单校验失败

//#define INIT_SUCCESS                        18        //初始化成功
//#define INIT_FAILED                         19        //初始化成功
//#define QUERY_REAL_NAME_SCUCESS             20        //查询实名认证信息成功
//#define QUERY_REAL_NAME_FAILED              21        //查询实名认证信息失败
//#define INIT_UNINIT                         22        //没有初始化
//#define LOGIN_UNLOGIN                       23        //没有登录
//#define NO_NETWORK                          24        //没有网络


#endif /* GsCode_h */
