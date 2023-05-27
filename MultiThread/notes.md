```c++
// lock_guard用法
lock_guard<mutex> lg(m_mutex);
lock_guard<mutex> lg(m_mutex, adopt_lock);

// unique_lock用法
unique_lock<mutex> ul(m_mutex, adopt_lock);		// 前提是已经lock了
unique_lock<mutex> ul(m_mutex, try_to_lock);	// 前提是不能先lock，与owns_lock()函数配合使用
unique_lock<mutex> ul(m_mutex, defer_lock); 	// 前提是不能先lock，初始化一个没有上锁的mutex

// unique_lock成员函数
ret = ul.owns_lock()	// 与try_to_lock配合使用

// 灵活，可以随时解锁
ul.lock();
u1.unlock();					// 临时处理非共享代码处理

ret = u1.try_lock();	// 尝试加锁，不阻塞；返回值要么为true，要么为false

mutex* mutex_ptr = ul.release();					// unique_lock与mutex解绑
mutex_ptr->unlock();											// 解绑后需要手动解锁

// unique_lock对mutex所有权的转移
unique_lock<mutex> ul1(m_mutex);
unique_lock<mutex> ul2(move(ul1));				// move将ul1变为右值
// 或写一个类成员函数，该函数返回一个unique_lock对象（局部变量），系统会自动调用unique_lock的移动构造函数

// 创建一个函数，这个函数只能执行一次
static void executeOnce() {
  // To do
}
once_flag m_flag;
// call_once放在一个公共区域内
call_once(m_flag, executeOnce);


// condition_variable和wait()和notify_one()
```

![image-20210922231127636](https://tva1.sinaimg.cn/large/008i3skNgy1gupt6nc0clj618w0cyn0102.jpg)
