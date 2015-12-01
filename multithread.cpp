1)
// Mutex - Lock 解决多线程同时操作同一资源
//              带来问题，1）忘记unlock或unlock前throw。
//                          解决方法：RAII(Resource Acquisition is initialization), e.g. std::lock_guard
//                        2）对多个mutex对象加锁，出现死锁。
//                          解决方法：A 保持顺序一致； B 标准库std::lock, std::try_lock 对多个mutex加锁

2) synchronization primitive
condiation_variable
cv_notify_one/all, cv_wait(lck)


实现同步：
本章定义了四种可用的同步类型，并且讨论实现同步的注意事项。
1、互斥锁（mutex）
2、条件变量(condition variable)
3、多读单写锁(multi-read,single-write lock)
4、信号量(semophore)
5、进程间同步(process synchronization)
6、同步原语的比较(compare primitive)

1）使用特殊变量实现同步，volatile,寄存器的值重新计算，非原子操作
2）lock/unlock
3）
