#ifndef __RTPP_CONNECTION_H__
#define __RTPP_CONNECTION_H__
#include "RtxConnection.h"

class DYNC_API RtppConnection : public RtxConnection
{
public:
	virtual ~RtppConnection(void) {};

	//* 创建带独立线程的实例
	static RtppConnection*Create(RtxConnectionEvent&callback);
	//* 创建共享线程的实例 - 用于发布端只发送Fec包场景
	static RtppConnection*CreateS(RtxConnectionEvent&callback);

protected:
	RtppConnection(void) {};
};

#endif	// __RTX_CONNECTION_H__