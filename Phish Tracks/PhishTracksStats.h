//
//  PhishTracksStats.h
//  Phish Tracks
//
//  Created by Alec Gorge on 7/23/13.
//  Copyright (c) 2013 Alec Gorge. All rights reserved.
//

#import <AFNetworking/AFNetworking.h>
#import "PhishTracksStatsHistoryItem.h"

@interface PhishTracksStats : AFHTTPClient

+ (PhishTracksStats*)sharedInstance;

@property NSString *authToken;
@property BOOL isAuthenticated;
@property NSString *username;
@property NSInteger userId;

- (void)testUsername:(NSString *)username
			password:(NSString *)password
			callback:(void (^)(BOOL success))cb
			 failure:(void ( ^ ) ( AFHTTPRequestOperation *, NSError *))failure;

- (void)reauth:(void (^)(BOOL success))cb
	   failure:(void ( ^ ) ( AFHTTPRequestOperation *, NSError *))failure;

- (void)signOut:(void (^)(BOOL success))cb
		failure:(void ( ^ ) ( AFHTTPRequestOperation *, NSError *))failure;

- (void)playedTrack:(PhishSong *)song
		   fromShow:(PhishShow *)show
			success:(void (^)(void))cb
			failure:(void ( ^ ) ( AFHTTPRequestOperation *, NSError *))failure;

- (void)stats:(void (^)(NSDictionary *stats, NSArray *history))cb
	  failure:(void ( ^ ) ( AFHTTPRequestOperation *, NSError *))failure;

- (void)globalStats:(void (^)(NSDictionary *stats, NSArray *history))cb
			failure:(void ( ^ ) ( AFHTTPRequestOperation *, NSError *))failure;

@end
