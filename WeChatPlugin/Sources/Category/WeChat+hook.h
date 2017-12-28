//
//  WeChat+hook.h
//  WeChatPlugin
//
//  Created by TK on 2017/4/19.
//  Copyright © 2017年 tk. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "WeChatPlugin.h"

@interface NSObject (WeChatHook) <AccountServiceExt>

+ (void)hookWeChat;

- (void)onUserLogout;

@end
