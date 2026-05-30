//
//  GSHttpClient+Urls.h
//  GSCoreKit
//
//  Created by yoka on 2024/11/5.
//

#import "GSHttpClient.h"

NS_ASSUME_NONNULL_BEGIN

@interface GSHttpClient (Urls)

/// 异步多域名请求
/// @param urls URL数组
/// @param body  body参数
/// @param completion completion description
- (void)asyncPOSTRequestUrls:(NSArray *)urls
                        body:(id)body
                  completion:(GSHttpResHandle)completion;

- (GSHttpResponse *)syncPOSTRequestUrls:(NSArray *)urls body:(id)body;

@end

NS_ASSUME_NONNULL_END
