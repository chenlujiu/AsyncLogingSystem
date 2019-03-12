// @Author Chenlujiu
// @Email 434425042@qq.com
#pragma once

class noncopyable
{
protected:
	noncopyable()=default;
	~noncopyable()=default;
private:
	noncopyable(const noncopyable&)=delete;
	const noncopyable& operator=(const noncopyable&)=delete;
};