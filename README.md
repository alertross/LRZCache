# LRZCache
ios一个简单的缓存方案，内存缓存+本地缓存

### 说明
#### 1. 
##### 支持自动归档解档模型，
##### 只要在你的头文件模型里面引入
##### NSObject＋LRZCoding.h 头文件

#### 2.
##### 支持将NSDictionary 转化成模型，
##### 只要在你的头文件模型里面引入
##### NSObject＋LRZCoding.h 头文件，效率高

#### 3.
##### 支持模型的快速缓存。
##### 不管是UITableview的datasource还是其他页面的数据，
##### 引入LRZCacher.h文件后可以通过 uid＋key将相关数据缓存到内存和本地，并可以快速存取


 ```
本存储方案是通过两个索引 uid + key 的方式 可以很灵活的实现各种本地存储的设计需求
比如：
uid1:
user1 + page1
user1 + page2
...
uid..n:
uid..n: + page..n
uid..n: + page..n
任意组合方式

最后都会归纳为组合key:
在方法：-(NSString *)memoryKeyOfKey:(NSString *)key userId:(NSString *)uid
中 uid + key == [NSString stringWithFormat:@"%@|%@",key,uid]; 的形式进行操作

具体参数解释：
*  | ------------------|-----------------------------------------------------------------------
*  | 参数               | 描述
*  | ------------------|-----------------------------------------------------------------------
*  | ioQueue_busy      | 用来进行写入文件的线程，不堵塞当前操作线程，并在串行队列中一次进行写入操作
*  | ------------------|-----------------------------------------------------------------------
*  | sizeOfKey         | 用来存放uid+key索引对应下二进制文件的大小【NSMutableDictionary类型】。
*  | ------------------|-----------------------------------------------------------------------
*  | objOfKey          | 当从磁盘进行读取后给本参数赋值，之后再次对uid+key索引下的数据访问直接读取objOfKey。
*  | ------------------|-----------------------------------------------------------------------
*  | archiveTypeOfKey  | 用来存放uid+key索引对应下二进制文件的类型是否是归档类型【NSMutableDictionary类型】。
*  | ------------------|-----------------------------------------------------------------------
 ```

**eg:**
```
NSMutableArray *mudic = [self fixedDataArray]; //generate data
[[LRZCacher cacher] setObject:mudic // save data to local disk and cache
forKey:@"channel_1"
userId:@"lightReason"
useArchive:YES
setted:^(LRZCacher *cacher, CacheError error) {
//TODO...
}];
```
