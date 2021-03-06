//
//  FsprgStoreParameters.h
//  FsprgEmbeddedStore
//
//  Created by Lars Steiger on 2/19/10.
//  Copyright 2010 FastSpring. All rights reserved.
//

#import <Cocoa/Cocoa.h>

/*! Constants for setOrderProcessType: */
extern NSString * const kFsprgOrderProcessDetail;
extern NSString * const kFsprgOrderProcessInstant;
extern NSString * const kFsprgOrderProcessCheckout;

/*! Constants for setMode: */
extern NSString * const kFsprgModeActive;
extern NSString * const kFsprgModeActiveTest;
extern NSString * const kFsprgModeTest;


/*!
 * FastSpring store parameters. FsprgStoreParameters is backed by a NSMutableDictionary that
 * can be accessed and modified via the raw and setRaw: methods.
 */
@interface FsprgStoreParameters : NSObject

@property (nonatomic, assign) BOOL hasContactDefaults;
@property (nonatomic, copy) NSMutableDictionary *raw;

+ (FsprgStoreParameters *)parameters;
+ (FsprgStoreParameters *)parametersWithRaw:(NSMutableDictionary *)aRaw;

- (NSURLRequest *)toURLRequest;
- (NSURL *)toURL;

- (instancetype)init;
- (instancetype)initWithRaw:(NSMutableDictionary *)aRaw;

/*!
 * Pass a language code via the URL to bypass automatic language detection.
 * Example: de
 */
- (NSString *)language;
- (void)setLanguage:(NSString *)aLanguage;

/*!
 * Use kFsprgOrderProcessDetail or kFsprgOrderProcessInstant.
 */
- (NSString *)orderProcessType;
- (void)setOrderProcessType:(NSString *)anOrderProcessType;

/*!
 * Store path name and product path name.
 * These are found in a full product URL such as sites.fastspring.com/<STOREPATH>/product/<PRODUCTPATH>
 */
- (void)setStoreId:(NSString *)aStoreId withProductId:(NSString *)aProductId;
- (NSString *)storeId;
- (void)setStoreId:(NSString *)aStoreId;
- (NSString *)productId;
- (void)setProductId:(NSString *)aProductId;

/*!
 * Use kFsprgModeActive, kFsprgModeActiveTest or kFsprgModeTest.
 */
- (NSString *)mode;
- (void)setMode:(NSString *)aMode;

/*!
 * Used for "External Tracking". Go to "Link Sources" inside SpringBoard.
 * Example: november_sale_post
 */
- (NSString *)campaign;
- (void)setCampaign:(NSString *)aCampaign;

/*!
 * Used for advanced and atypical store configuration options.
 */
- (NSString *)option;
- (void)setOption:(NSString *)anOption;

/*!
 * Pass a custom referrer via the URL to override the automatically detected referring URL (HTTP_REFERER).
 * The value passed in this parameter is available in notifications and data exports. If a value is 
 * passed in this parameter then no data will be stored from the HTTP_REFERER header.
 * Example: xyz123
 */
- (NSString *)referrer;
- (void)setReferrer:(NSString *)aReferrer;

/*!
 * Used for "External Tracking". Go to "Link Sources" inside SpringBoard.
 * Example: my_blog
 */
- (NSString *)source;
- (void)setSource:(NSString *)aSource;

/*!
 * Pass a coupon code via the URL to automatically apply a coupon to the order so that the customer 
 * does not need to enter it. A corresponding coupon code must be setup and associated with a promotion.
 * Example: DECSPECIAL987
 */
- (NSString *)coupon;
- (void)setCoupon:(NSString *)aCoupon;

/*!
 * This parameter has many uses within SpringBoard. A tag is a variable that can hold any positive integer value.
 * If no value is specified, it holds a value of 1. Tags can be used by parts of the order process. Adding multiple
 * tag parameters can be achieved by separating each tag (sometimes with numeric value) with a comma, as shown below.
 *
 * mytaga,mytagb,mytagc=2,anothertag=8
 */
- (NSString *)tags;
- (void)setTags:(NSString *)aTags;

- (BOOL)hasContactDefaults;
- (NSString *)contactFname;
- (void)setContactFname:(NSString *)aContactFname;
- (NSString *)contactLname;
- (void)setContactLname:(NSString *)aContactLname;
- (NSString *)contactEmail;
- (void)setContactEmail:(NSString *)aContactEmail;
- (NSString *)contactCompany;
- (void)setContactCompany:(NSString *)aContactCompany;
- (NSString *)contactPhone;
- (void)setContactPhone:(NSString *)aContactPhone;

@end
