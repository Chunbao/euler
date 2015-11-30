// Mutex - Lock 解决多线程同时操作同一资源
//              带来问题，1）忘记unlock或unlock前throw。
//                          解决方法：RAII(Resource Acquisition is initialization), e.g. std::lock_guard
//                        2）对多个mutex对象加锁，出现死锁。
//                          解决方法：A 保持顺序一致； B 标准库std::lock, std::try_lock 对多个mutex加锁
