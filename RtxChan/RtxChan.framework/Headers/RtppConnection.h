#ifndef __RTPP_CONNECTION_H__
#define __RTPP_CONNECTION_H__
#include "RtxConnection.h"

class DYNC_API RtppConnection : public RtxConnection
{
public:
	virtual ~RtppConnection(void) {};

	//* �����������̵߳�ʵ��
	static RtppConnection*Create(RtxConnectionEvent&callback);
	//* ���������̵߳�ʵ�� - ���ڷ�����ֻ����Fec������
	static RtppConnection*CreateS(RtxConnectionEvent&callback);

protected:
	RtppConnection(void) {};
};

#endif	// __RTX_CONNECTION_H__