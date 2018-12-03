//
//  ViewController.m
//  Lock
//
//  Created by ifuwo on 2018/11/22.
//  Copyright © 2018 ifuwo. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    @try {
        objc_sync_enter(obj);
    } @catch (NSException *exception) {
        <#Handle an exception thrown in the @try block#>
    } @finally {
        <#Code that gets executed whether or not an exception is thrown#>
    }
}


@end
