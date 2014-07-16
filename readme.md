RevTranscription iOS SDK
========================

The RevTranscription iOS SDK allows you to integrate with [Rev Transcription](https://www.rev.com/transcription) services, to allow your users to place Transcription orders.

Registering for SDK usage
-------------------------

- To get started with RevTranscription SDK you will need to request access at [www.rev.com/api](http://www.rev.com/api).
- Once you are granted access, you'll be given an API Client Key, that you can use to integrate with our API.


Sample App
----------

1. Open the project file in SampleApp\RevTranscriptionSample.xcodeproj
1. Fill in your API Client Key
1. Once running make sure you can place the sample transcription order (use credit card: 4111-1111-1111-1111 for testing)

Adding RevTranscription to Your Project
---------------------------------------

1. Open your project in Xcode
1. Right-click on your project in the files tab of the left pane and
   select "Add Files to '<PROJECT_NAME>'"
1. Navigate to where you uncompressed the RevTranscription SDK and select the 
   RevTranscription subfolder
1. Select "Copy items into destination group's folder"
1. Press Add button
1. Select your project file in 
   the file explorer, select your target, and select the "Build Phases" sub-tab.
   Under "Link Binary with Libraries", press the + button, select 
   libRevTranscription.a (note that if you are using xCode 5 this might be added automatically), and press Add. Repeat for SystemConfiguration.framework if
   necessary.
1. Build your application. At this point you should have no build failures or
   warnings

Using RevTranscription in Your Project
--------------------------------------

In your AppDelegate.m file:

```obj-c
//MyAppDelegate.m
#import "RevTranscription.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
	// ...
	
	// Add your API Key here
	// Set isSandbox to YES while testing your app, once you are ready for production, switch it to NO
	[RevTranscription initWithClientKey:@"YourApiKey" isSandbox:YES];
}
```

In your View:

```obj-c
//SomeViewController.m
#import "RevTranscription.h"
#import "RevApiWrapper.h"
#import "RecordingInfo.h"

- (IBAction)transcribeButtonPressed:(id)sender {
	RecordingInfo * recording = [[RecordingInfo alloc] init]; // an object that contains info about the recording that needs to be transcribed 
	recording.name = @"Sample Recording"; //name of the recording
	recording.duration = 2. * 60.; // file duration in seconds
	recording.filePath = @"\path\to\file";
	recording.contentMimeType = @"audio/mp4"; // The file mime type

	[RevTranscription presentTranscriptionInterfaceForParentViewController:self forRecording:recording 
		withSuccessBlock:^(NSString *orderUri) {
			NSLog(@"RevTranscription success with URI %@", orderUri);
		} failureBlock:^(RevApiError *error) {
			NSLog(@"RevTranscription error");
		}];
}

```