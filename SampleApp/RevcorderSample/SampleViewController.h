//
//  SampleViewController.h
//  RevTranscriptionSample
//
//  Created by Bassam Mehanni on 7/15/14.
//  Copyright (c) 2014 rev. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface SampleViewController : UIViewController

@property (nonatomic, retain) IBOutlet UIButton *transcribeBtn;
@property (nonatomic, retain) IBOutlet UIButton *logoutBtn;

-(IBAction)transcribeButtonPressed:(id)sender;
-(IBAction)logoutButtonPressed:(id)sender;

@end
