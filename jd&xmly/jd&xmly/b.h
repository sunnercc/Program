//
//  b.h
//  jd&xmly
//
//  Created by ifuwo on 2018/12/13.
//  Copyright © 2018 sunner. All rights reserved.
//

#ifndef b_h
#define b_h


// runtime使用场景
// 1. 方法交换，替换系统方法 黑魔法 method swizzling
// 2. 在分类中增加属性。 使用关联对象 association
// 3. 字典转模型

// 为什么能做到运行时替换方法？
// 因为oc是一种动态语言，不是静态语言，oc会在运行的时候，通过objc_object中的isa指针找到
// objc_class中的方法列表。铜鼓选择子sel在方法类表中查找对应的imp.然后执行。我们可以动态的交换imp
// 来达到运行时替换方法

// 如果是在C语言中如何实现?
// c 语言是静态语言，无法做到.

// block的实现？
// block本质是一个指向结构体的指针，结构体的实现，需要传入代码块函数的地址，以及对block描述的结构体地址。
// 执行的时候，block会拿到结构体,获取结构体体中的代码块实现的地址。来执行

// 注意事项？
// 注意循环引用问题
// 当block的代码实现中使用了一个类对象，要注意类对象是否强引用了block。如果强引用了，就会造成循环引用，导致类对象无法正常释放.

// 为什么能够获取外部变量？
// 通过__block修饰的对象。会被包装成一个结构体，它的地址会被传入block结构体中。当方法执行的时候，会拿到block中的修饰的结构体指针，来拿到修饰的对象。就可以获得外部变量了.

// runloop是什么？哪些场景会用？有哪些源，通知？
// 运行循环
// 常驻线程
// nstimer
// 自动释放池

// autoreleasePool的实现原理
// a.h releasepoll的底层实现

// 如何保证嵌套pool的正确管理？
// 每次push会传入哨兵对象，每次pop会释放对象直到哨兵对象。所以可以正确管理

// 内存管理机制？
// a.h 内存管理原则

// weak如何实现？
// sidetable
// sidetables是一个hash表，key:obj value:sidetable
// sidetable中变量 ref, enties;
// ref : 管理引用计数 map -> 使用了分离锁的思想。
// enties 数组: 存储了执行obj对象的所有weak指针的地址

// 多线程中GCD，OperationQueue使用场景？多线程中碰到的挑战？如何解决？
//









#endif /* b_h */
