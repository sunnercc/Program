//
//  c.h
//  jd&xmly
//
//  Created by ifuwo on 2018/12/13.
//  Copyright © 2018 sunner. All rights reserved.
//

#ifndef c_h
#define c_h

//[※]@property中有哪些属性关键字？
// strong weak assgin nonatomic atomic retain setter getter readonly readwrite

//[※]weak属性需要在dealloc中置nil么？
// 不需要 weak会自动置nil

//[※※]@synthesize和@dynamic分别有什么作用？
// @synthesize自动合成set get ivar
// @dynamic 不生成 set get

//[※※※]ARC下，不显式指定任何属性关键字时，默认的关键字都有哪些？
// readwrite atomic retain

//[※※※]用@property声明的NSString（或NSArray，NSDictionary）经常使用copy关键字，为什么？如果改用strong关键字，可能造成什么问题？
// 使用copy 保证对象的本质不会被破坏，依然是不可变类型
// 使用strong， 有可能本质变为可变类型。破坏本质, 有可能会发生方法无法找到，会crash

//[※※※]@synthesize合成实例变量的规则是什么？假如property名为foo，存在一个名为_foo的实例变量，那么还会自动合成新变量么？
// 会生成_开头的变量
// 不会自动合成新的变量

//[※※※※※]在有了自动合成属性实例变量之后，@synthesize还有哪些使用场景？
// synthesize name = _helloname
// 可以更改自动合成变量的名称

//[※※]objc中向一个nil对象发送消息将会发生什么？
// 没有任何反应

//[※※※]objc中向一个对象发送消息[obj foo]和objc_msgSend()函数之间有什么关系？
// objc_msgSend(obj, @selector(foo))

//[※※※]什么时候会报unrecognized selector的异常？
// 1. 根据sel查找imp
// 2. 如果找不到, 进入resolveinstancemethod ， 增加方法 addMethod
// 3. 如果没有增加方法，进入 快速消息转发 forwarding target , 返回需要转发给的哪个类
// 4. 如果没有， 进入慢消息转发
// 4.1 methodSignature 方法签名
// 4.2 forwading invocation

//[※※※※]一个objc对象如何进行内存布局？（考虑有父类的情况）
// isa

//[※※※※]一个objc对象的isa的指针指向什么？有什么作用？
// 指向 objc_class
// 找到对象方法
// 找到类方法

//[※※※※]下面的代码输出什么？
//@implementation Son : Father
//- (id)init
//{
//    self = [super init];
//    if (self) {
//        NSLog(@"%@", NSStringFromClass([self class]));
//        NSLog(@"%@", NSStringFromClass([super class]));
//    }
//    return self;
//}
//@end
// son

//[※※※※]runtime如何通过selector找到对应的IMP地址？（分别考虑类方法和实例方法）
// 实例方法
// 通过isa找到objc_class
// 找到objc_class中的chche。先遍历cache ，在找methodlist
// 类方法
// 通过isa-> objc_class isa -> metaClass
// 找到metaClass中的cache。 先cache。 后methodlist


//[※※※※]使用runtime Associate方法关联的对象，需要在主对象dealloc的时候释放么？
// 不需要。 dealloc的时候，会自动remove_associate

//[※※※※※]objc中的类方法和实例方法有什么本质区别和联系？
// 没什么区别 ，结构体一样 objc_class isa -> metaClass

//[※※※※※]_objc_msgForward函数是做什么的，直接调用它将会发生什么？
// 当方法的imp找不到的时候，会调用这个函数获取imp。进入消息转发
// 直接调用，就不会走自己的实现，会直接进入消息转发

//[※※※※※]runtime如何实现weak变量的自动置nil？
// sidetable
// sidetables是一个hash表，key:obj value:sidetable
// sidetable中变量 ref, enties;
// ref : 管理引用计数 map -> 使用了分离锁的思想。
// enties 数组: 存储了执行obj对象的所有weak指针的地址
// 当对象释放的时候，会遍历enties，置nil

//[※※※※※]能否向编译后得到的类中增加实例变量？能否向运行时创建的类中添加实例变量？为什么？
// ？

//[※※※]runloop和线程有什么关系？
// 一个runloop对应一个线程。主线程的runloop是有系统默认创建，默认开启的，子线程的runloop没有开启，需要手动开启

//[※※※]runloop的mode作用是什么？
// 根据mode的不同，来响应不同mode下的事件

//[※※※※]以+ scheduledTimerWithTimeInterval...的方式触发的timer，在滑动页面上的列表时，timer会暂定回调，为什么？如何解决？
// timer在defaultMode下
// 列表拖动的时候，runloop切换了mode为trackmode。timer不在trachmode下，所以timer停止
// 将trachmode下加入timer就可以解决这个问题了。 timer addrunloopModel: commond

//[※※※※※]猜想runloop内部是如何实现的？
// 死循环
// ？

//[※]objc使用什么机制管理对象内存？
// 引用计数

//[※※※※]ARC通过什么方式帮助开发者管理内存？
// 在特定的地方插入reatin release dealloc autorelease代码

//[※※※※]不手动指定autoreleasepool的前提下，一个autorealese对象在什么时刻释放？（比如在一个vc的viewDidLoad中创建）
// 在每一次的runloop循环迭代完成之后.

//[※※※※]BAD_ACCESS在什么情况下出现？
// 野指针的情况下

//[※※※※※]苹果是如何实现autoreleasepool的？
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

//[※※]使用block时什么情况会发生引用循环，如何解决？
// block 被当前类强引用
// block 代码中使用了当前类的强指针
// block 代码中使用当前类的弱指针

//[※※]在block内如何修改block外部变量？
// __block

//[※※※]使用系统的某些block api（如UIView的block版本写动画时），是否也考虑引用循环问题？
// 不用考虑，因为当前类并没有强引用UIView。不存在引用循环

//[※※]GCD的队列（dispatch_queue_t）分哪两种类型？
// searil 串行
// con 并发

//[※※※※]如何用GCD同步若干个异步调用？（如根据若干个url异步加载多张图片，然后在都下载完成后合成一张整图）
// 使用 dispach_group_notify

//[※※※※]dispatch_barrier_async的作用是什么？
// 栅栏函数
// 保证前面的任务执行结束。才开始执行当前
// 保证当前任务执行结束，才开始执行后面的任务

//[※※※※※]苹果为什么要废弃dispatch_get_current_queue？
// ？

//[※※※※※]以下代码运行结果如何？
//
//- (void)viewDidLoad
//{
//    [super viewDidLoad];
//    NSLog(@"1");
//    dispatch_sync(dispatch_get_main_queue(), ^{
//        NSLog(@"2");
//    });
//    NSLog(@"3");
//}
// 输出1 。然后相互等待 卡死

//[※※]addObserver:forKeyPath:options:context:各个参数的作用分别是什么，observer中需要实现哪个方法才能获得KVO回调？
// obesrver 观察者
// forkeypath 属性path
// option: 观察选项
// context:
//

//[※※※]如何手动触发一个value的KVO
// willchanged
// didchanged

//[※※※]若一个类有实例变量NSString *_foo，调用setValue:forKey:时，可以以foo还是_foo作为key？
// ？

//[※※※※]KVC的keyPath中的集合运算符如何使用？
// ?

//[※※※※]KVC和KVO的keyPath一定是属性么？
// ?

//[※※※※※]如何关闭默认的KVO的默认实现，并进入自定义的KVO实现？
// ?

//[※※※※※]apple用什么方式实现对一个对象的KVO？
// 生成一个子类，集成自被观察者。NSNOtifyKVO_a
// NSNOtifyKVO_a 重写set get

//[※※]IBOutlet连出来的视图属性为什么可以被设置成weak?
// ?

//[※※※※※]IB中User Defined Runtime Attributes如何使用？
// ？

//[※※※]如何调试BAD_ACCESS错误
// 开启检测僵尸对象开关

//[※※※]lldb（gdb）常用的调试命令？
// po



#endif /* c_h */
