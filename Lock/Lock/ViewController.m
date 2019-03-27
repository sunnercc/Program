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
    
    UIView *view = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 300, 300)];
    view.backgroundColor = [UIColor redColor];
    [self.view addSubview:view];
    NSLog(@"%@", view.layer.mask);
    view.layer.cornerRadius = 30;
    view.layer.masksToBounds = YES;
    NSLog(@"%@", view.layer.mask);
    
}


@end
