//
//  HttpHelper.h
//  QMGameSDK
//
//  Created by ZhouJing on 16/8/24.
//  Copyright © 2016年 SCH. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HttpHelper : NSObject

/**
 @brief 获取QMUser的实例对象
 */
+ (HttpHelper*)getInstance;

/**
 @brief 修改昵称
 @param
 
 params 可定制字典，支持的参数包括:
    sId      :NSString   登录会话标识，只在一次登录中生效。
    nickname :NSString   用户昵称
 
 responser 注册结果的回调函数，函数参数包括:
    statusCode  :int        状态码
    message     :NSString   状态信息
    data        :id         数据信息（此交易无数据信息）
 */
- (void)httpRequest : (NSDictionary*) params;


@end
