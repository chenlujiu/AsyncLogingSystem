// @Author Chenlujiu
// @Email 434425042@qq.com
#pragma once
#include"noncopyable.h"
#include<string>

class AppendFile:noncopyable
{
public:
	explicit AppendFile(const char*);
	~AppendFile();
	void append(const char*logline,const size_t len);
	void flush();
private:
	size_t write(const char*logline,size_t len);
	FILE* fp_;
	char buffer_[64*1024];
};
