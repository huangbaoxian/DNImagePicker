//
//  DNImagePickerController.h
//  ImagePicker
//
//  Created by DingXiao on 15/2/10.
//  Copyright (c) 2015年 Dennis. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DNImagePicker.h"

@class ALAssetsLibrary;
@class ALAssetsFilter;
FOUNDATION_EXTERN NSString *kDNImagePickerStoredGroupKey;
typedef NS_ENUM(NSUInteger, DNImagePickerFilterType) {
    DNImagePickerFilterTypeNone,
    DNImagePickerFilterTypePhotos,
    DNImagePickerFilterTypeVideos,
};

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
FOUNDATION_EXTERN ALAssetsFilter * ALAssetsFilterFromDNImagePickerControllerFilterType(DNImagePickerFilterType type);
#pragma clang diagnostic pop



@class DNImagePickerController;
@protocol DNImagePickerControllerDelegate <NSObject>
@optional
/**
 *  imagePickerController‘s seleted photos
 *
 *  @param imagePickerController
 *  @param imageAssets           the seleted photos packaged DNAsset type instances
 *  @param fullImage             if the value is yes, the seleted photos is full image
 */
- (void)dnImagePickerController:(DNImagePickerController *)imagePicker
                     sendImages:(NSArray *)imageAssets
                    isFullImage:(BOOL)fullImage;

- (void)dnImagePickerControllerDidCancel:(DNImagePickerController *)imagePicker;
@end


@interface DNImagePickerController : UINavigationController

@property (nonatomic, assign) DNImagePickerFilterType filterType;
@property (nonatomic, weak) id<DNImagePickerControllerDelegate> imagePickerDelegate;

@property (nonatomic, readonly) ALAssetsLibrary *assetsLibrary;

@end
