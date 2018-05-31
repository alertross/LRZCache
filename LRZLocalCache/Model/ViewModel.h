//
//  ViewModel.h
//  LRZLocalCache
//
//  Created by 刘强 on 2018/5/31.
//  Copyright © 2018年 LightReason. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSObject+LRZCoding.h"

@interface ViewModel : NSObject

@property (nonatomic,copy) NSString *name;
@property (nonatomic,copy) NSString *location;
@property (nonatomic,copy) NSString *sex;
@property (nonatomic,copy) NSString *headUrl;

@end
