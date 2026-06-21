//
//  GSConstants.h
//  GS
//
//  Created by yoka on 2022/1/29.
//  Copyright © 2022 Boson. All rights reserved.
//

#ifndef GSEnum_h
#define GSEnum_h
typedef NS_ENUM(NSInteger, ZSCallbackType) {
    ZSCallbackType_INIT = 0,
    ZSCallbackType_LOGIN,
    ZSCallbackType_LOGOUT,
    ZSCallbackType_PAY,
    ZSCallbackType_SHARE,
    ZSCallbackType_LOGIN_BIND,
    ZSCallbackType_PRODUCT_BIND,
    ZSCallbackType_DELETE_ACCOUNT,
    ZSCallbackType_QUERY_PRODUCT_DETAILS,
    ZSCallbackType_TRACK_EVENT,
    ZSCallbackType_AD_FINISH_LOADING,
    ZSCallbackType_AD,
    ZSCallbackType_AD_DID_Show,
    ZSCallbackType_AD_DID_CLICK,
    ZSCallbackType_AD_DID_HIDE,
    ZSCallbackType_AD_DID_FAIL_DISPLAY,
    ZSCallbackType_AD_DID_PAY_REVENUE,
    ZSCallbackType_AD_REMOVE_BANNER,
    /// 激励视频：用户满足条件应发放奖励（AppLovin didRewardUser）
    ZSCallbackType_AD_DID_REWARD_USER,
    /// Adjust deferred deeplink；extendCode: 1=Adjust 自动打开，0=游戏自行处理
    ZSCallbackType_ADJUST_DEFERRED_DEEPLINK,
};

// Log level for Bugly Log
typedef NS_ENUM(NSUInteger, ZSBuglyLogLevel) {
    ZSBuglyLogLevelSilent  = 0,
    ZSBuglyLogLevelError   = 1,
    ZSBuglyLogLevelWarn    = 2,
    ZSBuglyLogLevelInfo    = 3,
    ZSBuglyLogLevelDebug   = 4,
    ZSBuglyLogLevelVerbose = 5,
};

typedef NS_ENUM(NSInteger,ZSWebOrientationType){
    ZSWebOrientationLandScape = 0,//横屏 默认横屏
    ZSWebOrientationPortrait = 1  //竖屏
};

#endif /* GSEnum_h */
