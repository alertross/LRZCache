//
//  NSObject+LRZCoding.h
//  LRZLocalCache
//
//  Created by 刘强 on 2018/5/31.
//  Copyright © 2018年 LightReason. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (LRZCoding)
/**
 * 可以代替手写归档协议方法,支持
 * 继承类，对象嵌套以及字典、数组中持有对象
 */
-(void)encodeWithCoder:(NSCoder *)aCoder;
-(id)initWithCoder:(NSCoder *)aDecoder;

/**
 * 用于从字典生成模型类对象
 */
+(id)objectFromDic:(NSDictionary*)dic;
+(NSArray *)objectArrayFromArray:(NSArray *)array;

@end
