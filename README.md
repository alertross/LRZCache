# LRZCache
ios一个简单的缓存方案，内存缓存+本地缓存


说明
1. 支持自动归档解档模型，只要在你的头文件模型里面引入
NSObject＋LRZCoding.h 头文件

2.
支持将NSDictionary 转化成模型，只要在你的头文件模型里面引入
NSObject＋LRZCoding.h 头文件，效率高

3.
支持模型的快速缓存。不管是UITableview的datasource还是其他页面的数据，引入LRZCacher.h文件后
可以通过 uid＋key将相关数据缓存到内存和本地，并可以快速存取
