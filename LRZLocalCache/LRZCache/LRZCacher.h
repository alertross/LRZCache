//
//  LRZCacher.h
//  LRZLocalCache
//
//  Created by 刘强 on 2018/5/31.
//  Copyright © 2018年 LightReason. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(int, ArchiveType)
{
    LRZFromJSONData = 0,
    LRZFromArchiveData
};

typedef NS_ENUM(int, CacheError)
{
    CacheErrorNoError             =  0,   //无错误
    CacheErrorCacheDataNotExist   = -1,   //取缓存时，缓存文件或数据不存在
    CacheErrorBadUnarchiveData    = -2,   //解档时，源数据错误
    CacheErrorBadArchiveData      = -3,   //归档时，输入源数据错误
    CacheErrorBadInJsonData       = -4,   //存档序列化时输入源数据错误
    CacheerrorBadOutJsonData      = -5,   //取档饭序列化时数据错误
    CacheErrorReadFileFailed      = -6,   //写文件错误
    CacheErrorWriteFileFailed     = -7    //读文件错误
};

@class LRZCacher;
typedef void (^LRZCacheObjSetBlock)(LRZCacher *cacher,CacheError error);
typedef void (^LRZCacheObjGetBlock)(LRZCacher *cacher,id obj,CacheError error);

@interface LRZCacher : NSObject
@property (nonatomic,assign) long maxSize;
@property (nonatomic,readonly) long totalSize;

/**
 * 单例模式 全局共享一个模型
 */
+(LRZCacher*)cacher;


#pragma mark - 缓存存取方法 -
/**
 * 从内存中读取数据,存在或不存在均直接返回
 *
 * @param key 缓存数据key
 *
 * @param uid 用户id
 */
-(id)objectInMemoryForKey:(NSString*)key userId:(NSString*)uid;


/**
 * 从缓存、disk中读取数据
 *
 * @param key 缓存数据key
 *
 * @param uid 当前用户id
 *
 * @param block 取到缓存后回调
 */
-(void)objectForKey:(NSString*)key userId:(NSString*)uid achive:(LRZCacheObjGetBlock)block;


/**
 * 缓存对象方法 非阻塞方法
 *
 * @param obj 待缓存对象 当前仅支持NSDictionary 和 NSArray
 *
 * 且其内部无其他对象模型
 *
 * @param key 缓存关键字
 *
 * @param uid 当前用户id
 *
 * @param needArchive 是否通过archive方法缓存
 *
 * @Param block 缓存完毕回调
 */
-(void)setObject:(id)obj forKey:(NSString*)key userId:(NSString*)uid useArchive:(ArchiveType)needArchive setted:(LRZCacheObjSetBlock)block;

#pragma mark - 缓存清除方法 -
/**
 * 清除某个缓存
 *
 * @param key 缓存key
 *
 * @param uid 当前用户id
 */
-(void)clearObject:(NSString*)key userId:(NSString *)uid;

/**
 * 删除某个用户对应的缓存
 *
 * @param uid 用户id
 */
-(void)clearObject:(NSString*)uid;

/**
 * 清除所有缓存
 */
-(void)clearAllObject;

@end
