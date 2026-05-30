//
//  GSCrashReportParams.h
//  GSSDK
//
//  Created by YOKA on 2023/6/14.
//

#import "GSParamsBase.h"
#import "ZSEnum.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, GSCrashReportMethod) {
    GSCrashReportMethodSetInfo = 1,
    GSCrashReportMethodSetUserValue,
    GSCrashReportMethodPrintLog,
    GSCrashReportMethodReportException
};

@interface ZSCrashReportParams : GSParamsBase

@property (nonatomic, assign, readonly) GSCrashReportMethod crashReportMethod;
@property (nonatomic, strong, readonly) NSMutableArray *methodMutArr;

@property (nonatomic, copy, readonly) NSString *userId;
@property (nonatomic, copy, readonly) NSString *version;
@property (nonatomic, copy, readonly) NSString *tag;
@property (nonatomic, copy, readonly) NSString *value;
@property (nonatomic, copy, readonly) NSString *key;
@property (nonatomic, assign, readonly) ZSBuglyLogLevel level;
@property (nonatomic, copy, readonly) NSString *logTag;
@property (nonatomic, copy, readonly) NSString *msg;
@property (nonatomic, assign, readonly) NSUInteger category;
@property (nonatomic, copy, readonly) NSString *aName;
@property (nonatomic, copy, readonly) NSString *aReason;
@property (nonatomic, copy, readonly) NSArray *aStackArray;
@property (nonatomic, copy, readonly) NSDictionary *info;

- (void)setUserId:(NSString *)userId appVersion:(nullable NSString *)version tag:(nullable NSString *)tag;
- (void)setUserValue:(NSString *)value forkey:(NSString *)key;
- (void)printLog:(ZSBuglyLogLevel)level tag:(nullable NSString *)tag log:(NSString *)msg;
// 类型(Cocoa=3,CSharp=4,JS=5,Lua=6)
- (void)reportException:(NSUInteger)category name:(NSString *)aName reason:(NSString *)aReason callStack:(NSArray *)aStackArray extraInfo:(nullable NSDictionary *)info;

@end

NS_ASSUME_NONNULL_END
