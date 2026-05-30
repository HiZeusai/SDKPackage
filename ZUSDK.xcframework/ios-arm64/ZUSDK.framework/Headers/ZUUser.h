//
//  PBUser.h
//  PBSDK
//
//  Created by yoka on 2024/6/3.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

/// 用于PB登录返回的数据对象
@interface ZUUser : NSObject
@property (nonatomic, strong) NSString *userId;             // 用户ID
@property (nonatomic, strong) NSString *token;              //用户的Token
@property (nonatomic, strong) NSString *loginPlatform;        //登录类型
@property (nonatomic, strong) NSString *nickname;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *gender;
@property (nonatomic, assign, readonly) NSInteger login_type_code;      // 登录类型Code
@property (nonatomic, strong) NSString *accId;
@property (nonatomic, strong) NSArray *platforms;
@property (nonatomic, strong) NSString *profile;
@property (nonatomic, strong) NSString *age;










-(NSString *)getValidName;
//需要有脱敏
-(NSString *)getValidNameOpenDesensitization:(BOOL)desensitization;
- (instancetype)initWithDictionary:(NSDictionary *)dic;
+ (NSDictionary *)dictionaryWithUserModel:(ZUUser *)model;

@end

NS_ASSUME_NONNULL_END
