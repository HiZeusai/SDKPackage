//
//  GResult.h
//
//
//  Created by Vison on 2024/8/18.
//  Copyright © 2024 GS. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface GResult : NSObject

@property (nonatomic, assign) NSInteger code;
@property (nonatomic, strong) NSString *message;

@property (nonatomic, strong, readonly) NSDictionary *JSONDictionary;
@property (nonatomic, strong, readonly) NSString *JSONString;

- (instancetype)initWithCode:(NSInteger)code message:(NSString *)message;

@end

typedef void(^GResultBlock)(GResult *result);
