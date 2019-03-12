// @Author Chenlujiu
// @Email 434425042@qq.com
#pragma once
#include"noncopyable.h"
#include<pthread.h>
#include<cstdio>

class MutexLock:noncopyable
{
public:
	MutexLock()
	{
		pthread_mutex_init(&mutex,NULL);
	}
	~MutexLock()
	{
		pthread_mutex_lock(&mutex);
		pthread_mutex_destroy(&mutex);
	}
	void lock()
	{
		pthread_mutex_lock(&mutex);
	}
	void unlock()
	{
		pthread_mutex_unlock(&mutex);
	}
private:
	pthread_mutex_t mutex;
private:
	friend class Condition;
};

class MutexLockGuard:noncopyable
{
public:
	explicit MutexLockGuard(MutexLock& _mutex):
	mutex(_mutex)
	{
		mutex.lock();
	}
	~MutexLockGuard()
	{
		mutex.unlock();
	}
private:
	MutexLock& mutex;
};