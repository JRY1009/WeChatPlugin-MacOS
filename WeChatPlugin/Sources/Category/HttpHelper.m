//
//  HttpHelper.m
//  QMGameSDK
//
//  Created by ZhouJing on 16/8/24.
//  Copyright © 2016年 SCH. All rights reserved.
//

#import "HttpHelper.h"
#import "Constant.h"

@implementation HttpHelper

+ (HttpHelper*)getInstance
{
    __strong static HttpHelper* instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[self alloc] init];
    });
    
    return instance;
}

- (void)httpRequest : (NSDictionary*) params
{
    
    //map 转 json
    NSError* error = nil;
    NSData* baseData = [NSJSONSerialization dataWithJSONObject:params options:kNilOptions error:&error];
    
    //json 转 string
    NSString* paramsString = [[NSString alloc] initWithData:baseData encoding:NSUTF8StringEncoding];
    
    //请求
    NSURL *URL = [NSURL URLWithString:REQUEST_URL];
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] initWithURL:URL cachePolicy:NSURLRequestUseProtocolCachePolicy timeoutInterval:30];
    request.HTTPMethod = @"POST";
    request.HTTPBody = [paramsString dataUsingEncoding:NSUTF8StringEncoding];
    
    NSOperationQueue *queue = [[NSOperationQueue alloc] init];
    [NSURLConnection
     sendAsynchronousRequest:request
     queue:queue completionHandler:^(NSURLResponse *response, NSData *data, NSError *error) {
         
         dispatch_async(dispatch_get_main_queue(), ^{
             
             if ([data length] >0 && error == nil) {
                 //请求成功 do something

             }
             else if ([data length] == 0 && error == nil) {
                 //未知错误 do something
             }
             else if (error != nil) {
                 NSString* errorString = [[NSString alloc] initWithFormat:@"%@", error];
                 //错误error do something
             }
         });
         
     }];
}

@end
