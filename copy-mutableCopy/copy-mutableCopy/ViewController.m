//
//  ViewController.m
//  copy-mutableCopy
//
//  Created by ifuwo on 2018/12/5.
//  Copyright © 2018 sunner. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [self demo1];
    [self demo2];
    [self demo3];
    [self demo4];
}

- (void)demo1
{
    printf("\n demo1 begin :");
    
    NSString *str1 = @"123";  // 常量区分配
    NSString *str2 = [str1 copy];
    NSMutableString *str3 = [str1 mutableCopy];
    printf("\n str1 -> = %p \n str2 -> = %p \n str3 -> = %p", str1, str2, str3);
    
    printf("\n demo1 end.\n");
    
//    str1 -> = 0x1072d9088
//    str2 -> = 0x1072d9088
//    str3 -> = 0x600001c2c000
    
    // 可以看出
    // str1指向的地址和str2指向的地址是同一个地址.str2并没有开辟新的空间,仅仅是指针的拷贝.
    // str1指向的地址和str3指向的地址不是同一个地址。str3开辟了新的空间.
}

- (void)demo2
{
    printf("\n demo2 begin :");
    
    NSString *str1 = @"123"; // 常量区分配
    NSMutableString *m_str1 = [NSMutableString stringWithString:str1];  // 堆区重新分配
    NSString *m_str2 = [m_str1 copy];
    NSMutableString *m_str3 = [m_str1 mutableCopy];
    printf("\n m_str1 -> = %p \n m_str2 -> = %p \n m_str3 -> = %p", m_str1, m_str2, m_str3);
    
    printf("\n demo2 end.\n");
    
//    m_str1 -> = 0x600003143b40
//    m_str2 -> = 0xbe9e1c56d14b79e2
//    m_str3 -> = 0x600003143e70
    
    // 可以看出
    // m_str1指向的地址和str2指向的地址不是同一个地址. str2开辟了新的空间.
    // m_str1指向的地址和str3指向的地址不是同一个地址。str3开辟了新的空间
}

- (void)demo3
{
    printf("\n demo3 begin :");
    
    // 验证容器NSArray
    NSArray *arr1 = @[@1, @2, @3];
    NSArray *arr2 = [arr1 copy];
    NSMutableArray *arr3 = [arr1 mutableCopy];
    printf("\n arr1 -> = %p \n arr2 -> = %p \n arr3 -> = %p", arr1, arr2, arr3);
    printf("\n arr1 items:");
    for (int i = 0; i < arr1.count; i++) {
        printf("\n %d -> = %p", i, arr1[i]);
    }
    printf("\n arr2 items:");
    for (int i = 0; i < arr2.count; i++) {
        printf("\n %d -> = %p", i, arr1[i]);
    }
    printf("\n arr2 items:");
    for (int i = 0; i < arr2.count; i++) {
        printf("\n %d -> = %p", i, arr1[i]);
    }
    
    printf("\n demo3 end.\n");
    
//    arr1 -> = 0x600001490090
//    arr2 -> = 0x600001490090
//    arr3 -> = 0x6000014900c0
//    arr1 items:
//    0 -> = 0xb690da9c196700a8
//    1 -> = 0xb690da9c19670098
//    2 -> = 0xb690da9c19670088
//    arr2 items:
//    0 -> = 0xb690da9c196700a8
//    1 -> = 0xb690da9c19670098
//    2 -> = 0xb690da9c19670088
//    arr2 items:
//    0 -> = 0xb690da9c196700a8
//    1 -> = 0xb690da9c19670098
//    2 -> = 0xb690da9c19670088
    
    // 可以看出
    // arr1指向的地址和arr2指向的地址是同一个地址.str2并没有开辟新的空间,仅仅是指针的拷贝.
    // arr1中的子元素指向的地址和arr2中的子元素指向的地址是同一个地址, 子元素没有开辟内存，仅仅是指针的拷贝
    // arr1指向的地址和str3指向的地址不是同一个地址。arr3开辟了新的空间.
    // arr1中的子元素指向的地址和arr3中的子元素指向的地址是同一个地址, 子元素没有开辟内存，仅仅是指针的拷贝
    
}

- (void)demo4
{
    printf("\n demo4 begin :");
    
    // 验证容器NSArray
    NSArray *arr1 = @[@1, @2, @3];
    NSMutableArray *m_arr1 = [NSMutableArray arrayWithArray:arr1];
    NSArray *m_arr2 = [arr1 copy];
    NSMutableArray *m_arr3 = [arr1 mutableCopy];
    printf("\n m_arr1 -> = %p \n m_arr2 -> = %p \n m_arr3 -> = %p", m_arr1, m_arr2, m_arr3);
    printf("\n m_arr1 items:");
    for (int i = 0; i < m_arr1.count; i++) {
        printf("\n %d -> = %p", i, m_arr1[i]);
    }
    printf("\n m_arr2 items:");
    for (int i = 0; i < m_arr2.count; i++) {
        printf("\n %d -> = %p", i, m_arr1[i]);
    }
    printf("\n m_arr2 items:");
    for (int i = 0; i < m_arr2.count; i++) {
        printf("\n %d -> = %p", i, m_arr1[i]);
    }
    
    printf("\n demo4 end.\n");
    
//    m_arr1 -> = 0x6000014900c0
//    m_arr2 -> = 0x600001490090
//    m_arr3 -> = 0x600001490030
//    m_arr1 items:
//    0 -> = 0xb690da9c196700a8
//    1 -> = 0xb690da9c19670098
//    2 -> = 0xb690da9c19670088
//    m_arr2 items:
//    0 -> = 0xb690da9c196700a8
//    1 -> = 0xb690da9c19670098
//    2 -> = 0xb690da9c19670088
//    m_arr2 items:
//    0 -> = 0xb690da9c196700a8
//    1 -> = 0xb690da9c19670098
//    2 -> = 0xb690da9c19670088
    
    // 可以看出
    // m_arr1指向的地址和m_str2指向的地址是同一个地址. arr2开辟了新的空间.
    // m_arr1中的子元素指向的地址和m_arr2中的子元素指向的地址是同一个地址, 子元素没有开辟内存，仅仅是指针的拷贝
    // m_str1指向的地址和m_str3指向的地址不是同一个地址。str3开辟了新的空间
    // m_arr1中的子元素指向的地址和m_arr3中的子元素指向的地址是同一个地址, 子元素没有开辟内存，仅仅是指针的拷贝
    
}


// 验证
// 得出结论
// 综合结果
// copy产生不可变类型
// 不可变类型 -> copy -> 不可变类型 : 不开辟空间
// 可变类型 -> copy -> 不可变类型 : 开辟空间
// mutableCopy产生可变类型
// 不可变类型 -> mutableCopy -> 可变类型 : 开辟空间
// 可变类型 -> copy -> 可变类型 : 开辟空间
// 容器类中的子元素仅仅指针拷贝,不开辟空间


@end
