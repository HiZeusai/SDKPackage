//
//  ShareParams.h
//  GSSDK
//
//  Created by sen on 2021/12/14.
//

#import <Foundation/Foundation.h>
#import "GSParamsBase.h"
#import "ZSEnum.h"
@interface ZSShareParams : GSParamsBase

@property (strong, nonatomic) NSString *title;               //分享的标题，最大30个字符
//@property (strong, nonatomic) NSString *titleUrl;            //标题链接
//@property (strong, nonatomic) NSString *sourceName;          //分享此内容显示的出处名称
@property (strong, nonatomic) NSString *sourceUrl;           //出处链接
@property (strong, nonatomic) NSString *content;             //内容，最大130个字符
@property (strong, nonatomic) NSString *url;                 //链接，微信分享的时候会用到

@property (strong, nonatomic) NSData *imageData;
@property (strong, nonatomic) NSString *imageUrl;              //图片地址
@property (nonatomic, strong) NSString *imagePath;
@property (strong, nonatomic) NSString *platform;            //分享平台
@property (assign, nonatomic) NSInteger shareScene;
@property (assign, nonatomic) NSInteger dialogMode;                             //是否全屏还是对话框
@property (nonatomic, strong) NSString *shareType;   // 1 image 2 web 3 text
@end
