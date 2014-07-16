//
//  DetailViewController.m
//  RevcorderSample
//
//  Created by Bassam Mehanni on 7/7/14.
//  Copyright (c) 2014 rev. All rights reserved.
//

#import "DetailViewController.h"
#import "RevTranscription.h"
#import "RevApiWrapper.h"
#import "RecordingInfo.h"

@interface DetailViewController ()
@property (strong, nonatomic) UIPopoverController *masterPopoverController;
- (void)configureView;
@end

@implementation DetailViewController

@synthesize transcribeBtn;

#pragma mark - Managing the detail item

- (void)setDetailItem:(id)newDetailItem
{
    if (_detailItem != newDetailItem) {
        _detailItem = newDetailItem;
        
        // Update the view.
        [self configureView];
    }

    if (self.masterPopoverController != nil) {
        [self.masterPopoverController dismissPopoverAnimated:YES];
    }        
}

- (void)configureView
{
    // Update the user interface for the detail item.

    if (self.detailItem) {
        self.detailDescriptionLabel.text = [self.detailItem description];
    }
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    [self configureView];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)transcribeButtonPressed:(id)sender {
    NSString *preloadSampleRecordingPath = [[NSBundle mainBundle] pathForResource:@"SampleRecording" ofType:@"m4a"];
    
   RecordingInfo * recording = [[RecordingInfo alloc] init];
    recording.name = @"Sample Recording";
    recording.duration = 2. * 60.;
    recording.filePath = preloadSampleRecordingPath;
    recording.contentMimeType = @"audio/mp4";
    
    [RevTranscription presentTranscriptionInterfaceForParentViewController:self forRecording:recording withSuccessBlock:^(NSString *orderUri) {
        NSLog(@"Revcorder success with URI %@", orderUri);
    } failureBlock:^(RevApiError *error) {
        NSLog(@"Revcorder error");
    }];
}

-(IBAction)logoutButtonPressed:(id)sender {
    [[RevApiWrapper sharedSession] logout];
}

#pragma mark - Split view

- (void)splitViewController:(UISplitViewController *)splitController willHideViewController:(UIViewController *)viewController withBarButtonItem:(UIBarButtonItem *)barButtonItem forPopoverController:(UIPopoverController *)popoverController
{
    barButtonItem.title = NSLocalizedString(@"Master", @"Master");
    [self.navigationItem setLeftBarButtonItem:barButtonItem animated:YES];
    self.masterPopoverController = popoverController;
}

- (void)splitViewController:(UISplitViewController *)splitController willShowViewController:(UIViewController *)viewController invalidatingBarButtonItem:(UIBarButtonItem *)barButtonItem
{
    // Called when the view is shown again in the split view, invalidating the button and popover controller.
    [self.navigationItem setLeftBarButtonItem:nil animated:YES];
    self.masterPopoverController = nil;
}

@end
