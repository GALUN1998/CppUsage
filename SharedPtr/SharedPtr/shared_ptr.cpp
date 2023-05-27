//
//  shared_ptr.cpp
//  SharedPtr
//
//  Created by galun on 2021/9/5.
//

#include "shared_ptr.hpp"
#include <iostream>

template<typename T>
class SharedPtr {
private:
    size_t* m_count_;
    T* m_ptr_;

public:
    // 默认构造函数
    SharedPtr(): m_ptr_(nullptr), m_count_(new size_t) {}
    // 带参构造函数
    SharedPtr(T* ptr): m_ptr_(ptr), m_count_(new size_t) { m_count_ = 1; }
    // 拷贝构造函数
    SharedPtr(const SharedPtr& ptr) {
        m_count_ = ptr.m_count_;
        m_ptr_ = ptr.m_ptr_;
        ++(*m_count_);
    }
    // 移动构造函数
    SharedPtr(SharedPtr&& ptr): m_ptr_(ptr.m_ptr_), m_count_(ptr.m_count_) { ++(*m_count_); }
    // 析构函数
    ~SharedPtr() {
        --(*m_count_);
        if(*m_count_ == 0) {
            delete m_ptr_;
            delete m_count_;
            m_ptr_ = nullptr;
            m_count_ = nullptr;
        }

    }
    void operator=(const SharedPtr& ptr) {
        // std::move可以转化为引用，不用拷贝
        SharedPtr(std::move(ptr));
    }
    void operator=(SharedPtr&& ptr) {
        SharedPtr(std::move(ptr));
    }
    T& operator*() { return *m_ptr_; }
    T* operator->() { return m_ptr_; }
    T* get() { return m_ptr_; }
    size_t use_count() { return *m_count_; }
    bool unique() { return *m_count_ == 1; }
    void swap(SharedPtr& ptr) { std::swap(*this, ptr); }
};
