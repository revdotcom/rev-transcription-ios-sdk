//
//  DetailViewController.h
//  RevcorderSample
//
//  Created by Bassam Mehanni on 7/7/14.
//  Copyright (c) 2014 rev. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DetailViewController : UIViewController <UISplitViewControllerDelegate> {
    IBOutlet UIButton *launchBtn;
}

@property (strong, nonatomic) id detailItem;
@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;
@property (nonatomic, retain) IBOutlet UIButton *transcribeBtn;
@property (nonatomic, retain) IBOutlet UIButton *logoutBtn;

-(IBAction)transcribeButtonPressed:(id)sender;
-(IBAction)logoutButtonPressed:(id)sender;

@end
