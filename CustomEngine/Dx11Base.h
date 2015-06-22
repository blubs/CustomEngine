#ifndef _DX11_BASE_H_
#define _DX11_BASE_H_

#include <D3D11.h>
#include <D3DX11.h>
#include <DxErr.h>

//#pragma comment(lib,"d3d11.lib")
//#pragma comment(lib,"d3dx11.lib")

class Dx11Base
{
public:
	Dx11Base();
	virtual ~Dx11Base();

	bool Initialize(HINSTANCE hInstance, HWND hwnd);
	void Shutdown();

	bool CompileD3DShader(char* filePath, char* entry, char* shaderModel, ID3DBlob** buffer);

	virtual bool LoadContent();
	virtual void UnloadContent();
	virtual void Update(float dt) = 0;
	virtual void Render() = 0;
protected:
	HINSTANCE hInstance_;
	HWND hwnd_;
	D3D_DRIVER_TYPE driverType_;
	D3D_FEATURE_LEVEL featureLevel_;
	ID3D11Device* d3dDevice_;
	ID3D11DeviceContext* d3dContext_;
	IDXGISwapChain* swapChain_;
	ID3D11RenderTargetView* backBufferTarget_;
};

#endif