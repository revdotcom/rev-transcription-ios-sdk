//
//  SampleViewController.m
//  RevTranscriptionSample
//
//  Created by Bassam Mehanni on 7/15/14.
//  Copyright (c) 2014 rev. All rights reserved.
//

#import "SampleViewController.h"
#import "RevTranscription.h"
#import "RevApiWrapper.h"
#import "RecordingInfo.h"

@interface SampleViewController ()

@end

@implementation SampleViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
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


/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
