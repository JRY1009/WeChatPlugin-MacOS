//
//  WeChatPlugin.h
//  WeChatPlugin
//
//  Created by TK on 2017/4/19.
//  Copyright © 2017年 tk. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "TKWeChatPluginConfig.h"
#import "TKHelper.h"

FOUNDATION_EXPORT double WeChatPluginVersionNumber;
FOUNDATION_EXPORT const unsigned char WeChatPluginVersionString[];

#pragma mark - 微信原始的部分类与方法

@protocol AccountServiceExt <NSObject>
@optional
- (void)onGetOnlineInfoFinished;
- (void)onCurrentDeviceLockStateChanged:(BOOL)arg1;
- (void)onCurrentDeviceLockStateWillChange:(BOOL)arg1;
- (void)onCurrentNetworkLockStateWillChange:(BOOL)arg1;
- (void)onUserLogout;
- (void)onAuthLocked;
- (void)onAuthUpdateCert;
- (void)onAuthNeedUpdate:(int)arg1;
- (void)onAuthAlphaVersion:(NSString *)arg1;
- (void)onAuthNeedImageCode:(NSData *)arg1;
- (void)onAuthNeedSMSCode:(NSString *)arg1 withAuthTicket:(NSString *)arg2;
- (void)onAuthOkNeedReload;
- (void)onAuthKickOutWithReason:(NSString *)arg1 errorMsg:(NSString *)arg2;
- (void)onAuthKeyInfoInvalid:(NSString *)arg1;
- (void)onPreAuthOKOfUser:(NSString *)arg1;
- (void)onAuthFaildForInvalidCGISessionID;
- (void)onAuthFaildWithWrongPasswordOrUsername;
- (void)onAuthFaild:(NSString *)arg1;
- (void)onManualAuthHalfOK;
- (void)onAuthOK:(BOOL)arg1;
@end

@interface MMLoginOneClickViewController : NSObject
@property(nonatomic) NSTextField *descriptionLabel;
- (void)onLoginButtonClicked:(id)arg1;
@property(nonatomic) NSButton *loginButton;
@end

@interface AccountService : NSObject
- (id)GetLastLoginUserName;
- (id)GetLastLoginAutoAuthKey;
- (BOOL)canAutoAuth;
- (void)AutoAuth;
- (void)ManualLogin:(id)arg1 withPassword:(id)arg2;
- (void)ManualLogout;
- (void)QRCodeLoginWithUserName:(id)arg1 password:(id)arg2;
- (void)onRSACertUpdateFail;
- (void)onRSACertUpdated;
- (void)onCertNeedUpdate;
- (void)UpdateCert;
- (void)onIDCRedirect:(id)arg1;
- (void)onAuthNeedUpdate:(int)arg1;
- (void)onAuthAlphaVersion:(id)arg1;
- (void)onAuthNeedSMSCode:(id)arg1 withAuthTicket:(id)arg2;
- (void)onAuthNeedImageCode:(id)arg1;
- (void)onAuthKeyInfoInvalidOfUser:(id)arg1 nickName:(id)arg2;
- (void)onAuthPushLoginURL:(id)arg1 errorMsg:(id)arg2;
- (void)onAuthKickOutWithReason:(id)arg1 errorMsg:(id)arg2;
- (void)onAuthFaildWithWrongPasswordOrUsername;
- (void)onAuthFaildForInvalidCGISessionID;
- (void)onAuthFaild:(id)arg1;
- (void)onAuthOKOfUser:(id)arg1 withSessionKey:(id)arg2 withServerId:(id)arg3 autoAuthKey:(id)arg4 isAutoAuth:(BOOL)arg5;
- (void)onManualAuthFinalOK;
- (void)onManualAuthHalfOKWithSessionKey:(id)arg1 withServerId:(id)arg2 autoAuthKey:(id)arg3;
- (void)onPreAuthOKOfUser:(id)arg1 nickName:(id)arg2;
@end

@interface MMLoginViewController : NSObject
@property(retain, nonatomic) MMLoginOneClickViewController *oneClickViewController;
@end

@interface MMMainWindowController : NSWindowController
@property(retain, nonatomic) MMLoginViewController *loginViewController;
- (void)onAuthOK;
- (void)onLogOut;
@end

@interface MessageService : NSObject
- (void)onRevokeMsg:(id)arg1;
- (void)OnSyncBatchAddMsgs:(NSArray *)arg1 isFirstSync:(BOOL)arg2;
- (id)SendTextMessage:(id)arg1 toUsrName:(id)arg2 msgText:(id)arg3 atUserList:(id)arg4;
- (id)SendFileAppMsgTo:(id)arg1 fileName:(id)arg2 filePath:(id)arg3;
- (id)GetMsgData:(id)arg1 svrId:(long)arg2;
- (void)AddLocalMsg:(id)arg1 msgData:(id)arg2;
- (BOOL)updateFileInformationInDBWithMessage:(id)arg1;
@end

@interface MMServiceCenter : NSObject
+ (id)defaultCenter;
- (id)getService:(Class)arg1;
@end

@interface SKBuiltinString_t : NSObject
@property(retain, nonatomic, setter=SetString:) NSString *string; // @synthesize string;
@end

@interface AddMsg : NSObject
@property(retain, nonatomic, setter=SetContent:) SKBuiltinString_t *content; // @synthesize content;
@property(retain, nonatomic, setter=SetFromUserName:) SKBuiltinString_t *fromUserName; // @synthesize fromUserName;
@property(nonatomic, setter=SetMsgType:) int msgType; // @synthesize msgType;
@property(retain, nonatomic, setter=SetToUserName:) SKBuiltinString_t *toUserName; // @synthesize toUserName;
@property (nonatomic, assign) unsigned int createTime;
@end

@interface MMChatsViewController : NSViewController <NSTableViewDataSource, NSTableViewDelegate>
@property(nonatomic) __weak NSTableView *tableView;
@end

@interface WeChat : NSObject
+ (id)sharedInstance;
@property(nonatomic) MMChatsViewController *chatsViewController;
@property(retain, nonatomic) MMMainWindowController *mainWindowController;
@property(nonatomic) BOOL isAppTerminating;
@end

@interface ContactStorage : NSObject
- (id)GetSelfContact;
- (id)GetContact:(id)arg1;
- (id)GetAllFriendContacts;
- (id)GetAllFavContacts;
- (id)GetContactList:(unsigned int)arg1 ContactType:(unsigned int)arg2;
- (id)GetContactWithUserName:(id)arg1 updateIfNeeded:(BOOL)arg2;
- (id)GetContactsWithUserNames:(id)arg1;
- (id)init;
- (id)genTencentNewsContact;
- (id)genContactDataFromModContact:(id)arg1;
- (id)allKeysOfContactCache;
- (id)getContactCache:(id)arg1;
- (id)getContactFromModContact:(id)arg1;
- (id)GenBrandHolderContact;
- (id)GetAllBrandContacts;
@end

@interface GroupStorage : NSObject
- (id)GetAllGroups;
- (id)GetGroupMemberListWithGroupUserName:(id)arg1;
- (id)GetGroupMemberListWithGroupUserName:(id)arg1 limit:(unsigned int)arg2;
- (id)GetGroupContactList:(unsigned int)arg1 ContactType:(unsigned int)arg2;
- (id)GetGroupMemberContact:(id)arg1;
- (id)GetGroupContactsWithUserNames:(id)arg1;
- (id)GetGroupContact:(id)arg1;
- (id)init;
- (id)genGroupMemberFromRoomInfo:(id)arg1;
- (id)genGroupMemberFromModContact:(id)arg1;
- (id)genGroupContactFromModContact:(id)arg1 dicGroupMember:(id)arg2;
- (id)getGroupMemberContactCache:(id)arg1;
- (id)getGroupContactCacheKeys;
- (id)getGroupContactCache:(id)arg1;
- (id)contactWithMemberResp:(id)arg1;
@end


@interface WCContactData : NSObject
@property(retain, nonatomic) NSString *m_nsUsrName; // @synthesize m_nsUsrName;
@property(nonatomic) unsigned int m_uiFriendScene;  // @synthesize m_uiFriendScene;
@end

@interface MessageData : NSObject
- (id)initWithMsgType:(long long)arg1;
@property(retain, nonatomic) NSString *fromUsrName;
@property(retain, nonatomic) NSString *toUsrName;
@property(retain, nonatomic) NSString *msgContent;
@property(retain, nonatomic) NSString *msgPushContent;
@property(nonatomic) int messageType;
@property(nonatomic) int msgStatus;
@property(nonatomic) int msgCreateTime;
@property(nonatomic) int mesLocalID;
@end

@interface CUtility : NSObject
+ (BOOL)HasWechatInstance;
+ (unsigned long long)getFreeDiskSpace;
+ (void)ReloadSessionForMsgSync;
+ (id)GetCurrentUserName;
@end

@interface MMSessionInfo : NSObject
@property(nonatomic) BOOL m_bIsTop; // @synthesize m_bIsTop;
@property(nonatomic) BOOL m_bShowUnReadAsRedDot;
@property(nonatomic) BOOL m_isMentionedUnread; // @synthesize
@property(retain, nonatomic) NSString *m_nsUserName; // @synthesize m_nsUserName;
@property(retain, nonatomic) WCContactData *m_contact;
@end


@protocol MMChatsTableCellViewDelegate <NSObject>
@optional
- (void)cellViewReloadData:(MMSessionInfo *)arg1;
@end

@interface MMChatsTableCellView : NSTableCellView
@property(nonatomic) __weak id <MMChatsTableCellViewDelegate> delegate;
@property(retain, nonatomic) MMSessionInfo *sessionInfo;
- (void)menuWillOpen:(id)arg1;
- (void)contextMenuSticky;
- (void)contextMenuDelete;

@end

@interface MMSessionMgr : NSObject
@property(retain, nonatomic) NSMutableArray *m_arrSession;
- (id)GetSessionAtIndex:(unsigned long long)arg1;
- (void)MuteSessionByUserName:(id)arg1;
//- (void)TopSessionByUserName:(id)arg1;
- (void)UnmuteSessionByUserName:(id)arg1;
- (void)UntopSessionByUserName:(id)arg1;
- (void)deleteSessionWithoutSyncToServerWithUserName:(id)arg1;
- (void)sortSessions;
@end

@interface LogoutCGI : NSTableCellView
- (void)sendLogoutCGIWithCompletion:(id)arg1;
- (void)logoutCallback:(BOOL)arg1;
@end

#pragma mark - 调用 NSSearchPathForDirectoriesInDomains 的一些方法
@interface PathUtility : NSObject
+ (id)getSysCachePath;
+ (id)getSysDocumentPath;
+ (id)getSysLibraryPath;
@end

@interface MemoryMappedKV : NSObject
+ (id)mappedKVPathWithID:(id)arg1;
@end

@interface JTStatisticManager : NSObject
@property(retain, nonatomic) NSString *statFilePath;
@end
