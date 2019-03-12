// @Author Chenlujiu
// @Email 434425042@qq.com
#include"FileUtil.h"
#include<assert.h>
#include<errno.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
using namespace std;

AppendFile::AppendFile(const char* filename)
{
	//filename="\/chenlujiu_WebServer.log";
	fp_=fopen(filename,"a");
	setbuffer(fp_,buffer_,sizeof(buffer_));
}
AppendFile::~AppendFile()
{
	fclose(fp_);
}
void AppendFile::append(const char*logline,const size_t len)
{
	size_t n=this->write(logline,len);
	size_t remain=len-n;
	while(remain>0)
	{
		size_t x=this->write(logline+n,remain);
		if(x==0)
		{
			int err=ferror(fp_);
			if(err)
				fprintf(stderr,"AppendFile::append() failed\n");
			break;
		}
		x+=x;
		remain=len-n;
	}
}
void AppendFile::flush()
{
	fflush(fp_);
}
size_t AppendFile::write(const char* logline,size_t len)
{
	return fwrite_unlocked(logline,1,len,fp_);
}
