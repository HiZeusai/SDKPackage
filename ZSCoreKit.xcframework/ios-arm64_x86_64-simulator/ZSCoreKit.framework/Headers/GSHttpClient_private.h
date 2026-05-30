//
//  GSHttpClient_private.h
//  GSCoreKit
//
//  Created by yoka on 2024/11/5.
//

#ifndef GSHttpClient_private_h
#define GSHttpClient_private_h

#import "GSHttpClient.h"
#import "GSHttpRequest.h"
#import "GSLogger.h"

@interface GSHttpClient()

@property (nonatomic, strong) GSHttpRequest *httpReq;

- (void)asyncRequest:(GSHttpResHandle)completion;
- (GSHttpResponse *)syncRequest;

@end

#endif /* GSHttpClient_private_h */
