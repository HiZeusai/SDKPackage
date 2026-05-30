//
//  GSOpenUDID.h
//  GSCoreKit
//
//  Created by yoka on 2024/5/16.
//

#import <Foundation/Foundation.h>
#define GSOpenUDIDErrorNone          0
#define GSOpenUDIDErrorOptedOut      1
#define GSOpenUDIDErrorCompromised   2
@interface GSOpenUDID : NSObject{
}
+ (NSString*) getDeviceUDID;
+ (NSString*) valueWithError:(NSError**)error;
+ (void) setOptOut:(BOOL)optOutValue;
/// Returns an RFC 4122 compliant UUID string (36 chars with hyphens).
+ (NSString *)standardUUIDString;
@end
