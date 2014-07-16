RevTranscription iOS SDK
========================

The RevTranscription iOS SDK allows your app to integrate with [Rev Transcription](https://www.rev.com/transcription) services, so users of your app can place transcription orders for audio files within your app.

Registering for SDK usage
-------------------------

- To get started with RevTranscription SDK you will need to request for Rev API access at [www.rev.com/api](http://www.rev.com/api).
- You will receive an email with API access information, uncluding an API Client Key. The API Client Key is used to identify your app to our API.

Running the Sample App
----------

1. Open the project file in SampleApp\RevTranscriptionSample.xcodeproj
1. Fill in your API Client Key
1. Once running make sure you can place a transcription order (use credit card: 4111-1111-1111-1111 for testing)

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

In your AppDelegate.m file, add a call to initialize the Rev Transcription SDK to your didFinishLaunchingWithOptions method:

```obj-c
//MyAppDelegate.m
#import "RevTranscription.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
	// ...
	
	// Replace "YourApiKey" with the Client API Key you were emailed
	// Set isSandbox to YES while testing your app, once you are ready for production, switch it to NO
	// Be sure to use the sandbox API Client Key if isSandbox is set to YES, and the production API Client Key otherwise
	[RevTranscription initWithClientKey:@"YourApiKey" isSandbox:YES];
}
```

In your View Controller where you want to launch the UI for placing a Rev Transcription order:

```obj-c
//SomeViewController.m
#import "RevTranscription.h"
#import "RevApiWrapper.h"
#import "RecordingInfo.h"

- (IBAction)transcribeButtonPressed:(id)sender {
	RecordingInfo * recording = [[RecordingInfo alloc] init]; // an object that contains info about the recording that needs to be transcribed 
	recording.name = @"Sample Recording"; //name of the recording
	recording.duration = 120.; // file duration in seconds
	recording.filePath = @"\path\to\file"; // absolute path to the audio file
	recording.contentMimeType = @"audio/mp4"; // The file mime type

	// successBlock and failureBlock are optional - they are called when the Rev Transcription order
	// view controller is closed after successfully placing an order or after an error with placing
	// an order occurred. 
	[RevTranscription presentTranscriptionInterfaceForParentViewController:self forRecording:recording 
		withSuccessBlock:^(NSString *orderUri) {
			NSLog(@"RevTranscription success with URI %@", orderUri);
		} failureBlock:^(RevApiError *error) {
			NSLog(@"RevTranscription error");
		}];
}

```
