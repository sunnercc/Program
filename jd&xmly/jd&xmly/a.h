//
//  a.h
//  jd&xmly
//
//  Created by ifuwo on 2018/12/6.
//  Copyright © 2018 sunner. All rights reserved.
//

#ifndef a_h
#define a_h

// 关键字的区别:
// readonly : 修饰任何类型，仅仅生成get方法
// readwrite: 修饰任何类型，生成get方法，又生成set方法
// strong: 修饰对象类型. 强引用被修饰对象。
// weak: 修饰对象类型。弱引用被修饰对象，当被修饰对象释放的时候，weak修饰的对象指针会指向nil
// unsafe_unretained: (不safe不retain): 修饰对象类型。弱引用被修饰对象。与weak相似。区别在于:当被修饰对象释放的时候，weak修饰的对象指针不会指向nil,会造成野指针。
// copy: 修饰不可变对象类型。强引用被修饰对象。

// 内存管理原则:
// 1. alloc/new/copy/mutablecopy开头的方法，生成并持有对象。 引用计数+1
// 2. retain 持有对象， 引用计数+1
// 3. release 释放对象， 引用计数-1
// 4. dealloc 废弃对象。
// 5. 自己持有的对象，自己可以释放
// 6. 非自己持有的对象， 自己不能释放
// 7. 非自己生成的对象，自己也可以持有(通过retain)

// arc如何实现weak
// sidetable
// sidetables是一个hash表，key:obj value:sidetable
// sidetable中变量 ref, enties;
// ref : 管理引用计数 map -> 使用了分离锁的思想。
// enties 数组: 存储了执行obj对象的所有weak指针的地址

// releasepoll的底层实现
// 已经写了一篇博客来描述relasepoll的底层实现
// relasepoll是有一个AutorelesePage类来管理的。
// AutorelesePage是一个双向链表，通过parent和child
// AutorelesePage是通过游标next来存储autorelease对象的
// @autorelesepoll{}大括号开始的时候，会调用AutorelesePage的push方法.
// @autorelesepoll{}大括号开始的时候，会调用AutorelesePage的pop方法.
// 哨兵对象
// 在{的时候，会push进去一个哨兵对象，压入栈顶。通过返回哨兵对象
// 在}的时候，会传入哨兵对象给pop方法，依次弹出autorelease，并发送release消息。直到哨兵对象
// relasepoll的释放是在每一次runloop迭代结束的时候释放的。
// 一个relasepoll对象一个线程
// 一个线程对应一个AutorelesePage链表。（可能有多页）

// 如何统计错误日志
// 友盟统计, 百度统计

// cf的内存管理
// create copy release

// cf对象转化为oc对象，内存如何管理
// brige: oc对象保持引用。cf不保持引用
// brige_retain: oc对象保持引用。 cf保持引用
// brige_transfor : oc对象不保持引用。 cf保持引用

// view的drawrect为何会占内存
// view 画布过大，会开辟很大的空间

//view和layer的关系
// view至少有一个layer。
// view负责时间
// layer 负责显示


//响应链过程


//多线程


//多线程和数据库的同时访问问题


//数据库锁机制


//http udp tcp


//http响应体，响应头 请求头 请求体


//__block


//循环引用原理


//设计一个播放器架构


//堆区栈区。。的不同


//单粒的内存分配原理


//设计模式


//通知是异步还是同步
// 可以同步 可以异步


//异步和同步解释
// 是否阻塞当前线程


//runloop


//常用runtime


//category实现属性，内存管理过程


//sdk架构相关


//block底层实现


//解决手势冲突


//define和const





#endif /* a_h */
