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
    ZSCallbackType_AD_FINISH_LOADING,
    ZSCallbackType_AD,
    ZSCallbackType_TRACK_EVENT,
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
