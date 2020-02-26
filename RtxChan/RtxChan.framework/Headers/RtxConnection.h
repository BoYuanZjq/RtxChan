#ifndef __RTX_CONNECTION_H__
#define __RTX_CONNECTION_H__
#include <stdint.h>
#include "dync_export.h"

class RtxConnectionEvent
{
public:
	RtxConnectionEvent(void) {};
	virtual ~RtxConnectionEvent(void) {};

	virtual void OnRTXSessionDescription(const char*strIdd, bool bOffer, const char*strDesc) = 0;
	virtual void OnRTXIceRestartSessionDescription(const char*strIdd, bool bOffer, const char*strDesc) = 0;
	virtual void OnRTXIceCandidate(const char*strIdd, const char*strCand) = 0;

	virtual void OnRTXChanOpen(const char*strIdd, bool audio, bool video) = 0;
	virtual void OnRTXChanAudReady(const char*strIdd, bool ready) = 0;
	virtual void OnRTXChanVidReady(const char*strIdd, bool ready) = 0;
	virtual void OnRTXChanClose(const char*strIdd) = 0;
	virtual void OnRTXChanRequestKeyFrame(const char*strIdd) = 0;
	virtual void OnRTXChanRecvVideoData(const char*strIdd, bool bKeyFrame, const char*pData, int nLen, bool bContinue, uint32_t nTimestamp) = 0;
	virtual void OnRTXChanRecvAudioData(const char*strIdd, const char*pData, int nLen, uint16_t nSeqn, uint32_t nTimestamp) = 0;

	virtual void OnRTXDataChannelStatus(const char*strIdd, bool enabled) = 0;
	virtual void OnRTXDataChannelMsg(const char*strIdd, const char*strMsg) = 0;

	virtual void OnRTXStats(int nSendBytes, int nRecvBytes, int nPktLost, int nRtt) = 0;
};

class DYNC_API RtxConnection
{
protected:
	RtxConnection(void) {};
public:
	virtual ~RtxConnection(void) {};

public:

	virtual void SetIdd(const char* strIdd) = 0;
	virtual void AddIceServer(const char* strUri, const char* strAccount, const char* strPassword) = 0;

	virtual bool InitializePeerConnection(bool bEnableAudio, bool bEnableVideo, bool bEnableData, bool bDataReliable) = 0;
	virtual void CreateOffer(bool recvAudio, bool recvVideo) = 0;
	virtual void RecvOfferAnswer(const char* strSDP) = 0;
	virtual void RecvICE(const char*  strIce) = 0;
	virtual void SetIceRestart() = 0;
	virtual void Close() = 0;

	virtual void SendDataMsg(const char* strMsg) = 0;
	virtual void SendVideoData(bool bKeyFrame, const char*pData, int nLen) = 0;
	virtual void SendAudioData(const char*pData, int nLen) = 0;
	virtual void ResetExtTimestamp() = 0;
	virtual void SendVideoDataT(bool bKeyFrame, bool bFec, const char*pData, int nLen, uint32_t nTimestamp) = 0;
	virtual void SendAudioDataT(const char*pData, int nLen, int nSeqn, uint32_t nTimestamp) = 0;
};

#endif	// __RTX_CONNECTION_H__
