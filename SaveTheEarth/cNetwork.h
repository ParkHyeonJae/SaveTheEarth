#pragma once
#define PORT 9000

class cNetwork
{
private:
	//SOCKET m_Socket;

public:

	BOOL InitNet();
	BOOL UpdateNet();
	BOOL ReleaseNet();
};

