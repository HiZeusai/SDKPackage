//
//  FacilityInformationUntil.h
//
//  Created by zls on 2019/5/10.
//  Copyright © 2019年 zls. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface GSDeviceInfor : NSObject

/// 设备指纹
@property (nonatomic, strong, readonly, class) NSString *c_oneID;
@property (nonatomic, strong, readonly, class) NSString *s_oneID;
@property (nonatomic, assign, readonly, class) BOOL isVPNConnected;

// 1.获取设备名称 user-assigned device name (e.g. @"My iPhone").
+ (NSString *)getDeviceName;

// 获取手机名称 iPhone
+ (NSString *)getDeviceModel;

//获取os_version 16.2
+ (NSString *)getOs_version;

//获取操作系统
+ (NSString *)getDeviceSystemName;

//获取屏幕的分辨率
+ (CGSize)getPhoneSize;

// 屏幕倍率
+ (NSString *)screenScale;

// 获取内存大小
+ (NSString *)totalMemorySize;

/** 获取当前网络 */
+ (NSString *)getCurrentNerWork;
//获取App版本信息

+ (NSString *)appBundleId;

+ (NSString *)appVersion;

+ (NSString *)appBuildVersion;

+ (NSString *)appName;

// 客户端时间戳
+ (NSString *)clientTime;

+ (NSString *)getOpenUDID;

//获取UUID
+ (NSString *)pbOldGetUUID;

// 是否获取到idfa
+ (BOOL )idfaEnable;

// 获取IDFA
+ (NSString *)getIDFA;

// 保存IDFA
+ (void)saveIDFA:(NSString *)idfa;

// 获取IDFV
+ (NSString *)getIDFV;

//** 获取设备型号 */ x86_64 iPhone9,1
+ (NSString *)deviceCode;

// os_type 用户设备类型 1:web 2:wap , 3:android,4:iphone,5:ipad,6:pc,7:wp,0:other
+(NSString *)getOs_Type;

// 获取MAC地址
+ (NSString *)getMACAddress;

//获取android_id
+ (NSString *)getAndroid_ID;

//获取device_uuid
+ (NSString *)getDevice_UUID;

//获取设备当前网络IP地址（包括4G 等）
+ (NSString *)getIPAddress:(BOOL)preferIPv4;

+ (BOOL)checkNetwork;

+ (BOOL)isSimulator;

+(NSString*)getLanguage;

+ (BOOL)isJailbroken;

/// 设备ID，存储在KeyChain
+ (NSString *)getOpenUDID;

#pragma mark - CAID 使用字段
// 手机开机时间
+ (NSString *)bootTimeInSec;

// 系统更新时间
+ (NSString *)sysFileTimeMicroseconds;

// 时区（值如：28800）
+ (NSString *)timeZone;

// 设备名称md5值
+ (NSString *)deviceMd5Name;

// 系统版本
+ (NSString *)systemVersion;

// 磁盘总大小（单位KB）
+ (NSString *)diskTotalSize;

// 运营商
+ (NSString *)carrier;

// 国家码
+ (NSString *)countryCode;

// 设备machine 如： iphone 13
+ (NSString *)machine;

// 文件初始化时间（1605927157.069868958）
+ (NSString *)fileInitTime;

// 设备model （D54pAP）
+ (NSString *)model;

// mntId （C1CE088FB2206454D9E454C6BCBB630D811B3792B1C912EC4C480FD3422986E1@/dev/disk1s1）
// mnt_id 为新增参数，需要终端 APP 侧增加参数获取，为了避免 APP 升级较慢获取不到参数导致的 CAID 生
//成问题，作为过渡阶段，本次升级版本 mnt_id 不参与计算也不做校验，在没有获取到的情况下，可以不传输，不 会影响 CAID 的生成，但建议尽快增加参数获取，在下一版本算法更新中，即会加入计算
+ (NSString *)mntId;
//电池电量
+(int)getBatteryCapacity;

+ (NSString *)att;

+ (NSString *)aie;

+ (int64_t)totalDiskSpace;

+ (int64_t)freeDiskSpace;

+ (NSUInteger)userMemory;

+ (NSString *)getScreenSize;

+ (int64_t)getBootTime;

+ (int64_t)getPurchaseDate;

+ (NSString*)getInstallationTime;

+ (BOOL)isOffline;

+(NSString*)getCurrentTime;

+ (NSDictionary *)allMacs;

+ (NSString *)en0Mac;
//电池电量百分比
+(NSString*)getBatteryPre02;
//电池电量
+(int)getBatteryPre;
//是否支持astc_support
+ (BOOL)isDeviceSupportsASTC;
//电池的充电状态
+(NSString*)getBatterState;
//手机屏幕亮度
+(NSString*)getBrightNess;
//WIFI 地址  bassid 信息
+ (NSString *)getBSSID;
//所属国家
+ (NSString*)getCurrentCountry;
//CPU 核心数
+(NSString*)getCpuCount;
//CPU频率
+ (NSUInteger)getCPUFrequency;
//CPU型号
+ (NSString *)getCPUModel;
//CPU架构
+ (NSString *)getCPUArchitecture;
//判断代码是否在调试
+ (BOOL)isDebuggerAttached;
//距离传感器
+ (BOOL)getProximitySensorState;
//DNS信息
+ (NSString*)fetchDNSInformationForHost:(NSString *)hostname;
//GPU
+ (NSString *)getGPUName;
//GPU
+ (NSString *)getGPUModel;
//重力传感器
//typedef void (^GravityUpdateCompletion)(NSString *gravityData);
//+ (void)startGravityUpdatesWithCompletion:(GravityUpdateCompletion)completion;
//输入法列表
+ (NSString*)getInputList ;
////是否为模拟器
//+ (BOOL)isSimulator;
////系统语言
//+(NSString*)getLanguage;
//设备型号代码
+ (NSString*)getDevMachine;
//移动信号国家码
+(NSString*)getMcc;
//移动信号网络号码
+(NSString*)getMnc;
//openGL版本号
+ (NSString*)getOpenGLVersion ;
//权限列表
+(NSString*)getPermission;
//屏幕
+(CGRect)getPhysicalScreenSize ;
//进程ID
+(NSString*)getProcessID;
//进程名称
+ (NSString*)getProcessName;
//SIM卡状态
+ (NSString*)getSIMCardStatus;
//USB状态（只能用于检测MFi 认证的USB是否有链接）
+ (NSString*)checkConnectedAccessories;
//无线电版本字符串
+ (NSString*)getBasebandVersion;
//获取模拟器信息
+(NSString*)getSimulatorInfo;
//获取SSID信息（WIFI名称）
+(NSString*)getWiFiSSID;
//系统名称
+ (NSString*)getSystemName;
//系统版本
+ (NSString*)getSystemVersion;
//已经开机的时间
+ (NSString*)getUptime;
//VPN是否打开
+ (BOOL)isVPNEnabled;
//WIFI的IP地址
+ (NSString *)getWiFiIPAddress;
//WIFI的MAC地址
+ (NSString *)getWiFiMacAddress ;
//这个标识符是与设备相关的，并且在设备的生命周期内保持不变
+ (NSString *)getDeviceUUID;
//IDFA 是否开启
+ (BOOL)isIDFAEnabled;
//icould
+ (void)checkICloudAvailability;
//icould 令牌
+(NSString*)getIcloudToken;
////openUdid iOS code: https://github.com/ylechelle/OpenUDID
//+ (NSString *)getOpenUDID;
//物理内存
+ (NSString *) memory;
////设备启动时间
//+(NSString *)bootTimeInSec;
//系统更新时间
+(NSString *)sysFileTime;
//硬盘容量
+(NSString *)disk;
+ (NSString *)getCarrier;
+ (NSString*)convertToJSONData:(id)infoDict;
//判断当前网络类型
+(NSString *)currentNetworkType;
//苹果ASA TOKEN，用来标识ASA用户（客户端上报给服务器，服务器再去调用苹果接口判断是否是ASA用户）
+(NSString*)getAdToken;
//设备可用内存
+ (NSString*)getAvailableStorage;
//硬盘可用容量
+ (NSString*)getAvailableDiskSpace ;

+ (NSInteger )clientTimeInteger;

// App 声明周期 Id，声明周期内不变
+ (NSString *)appLifeId;
@end
