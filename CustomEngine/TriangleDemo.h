#ifndef _TRI_DEMO_H_
#define _TRI_DEMO_H_

#include "Dx11Base.h"


class TriangleDemo : public Dx11Base
{
public:
	TriangleDemo();
	virtual ~TriangleDemo();

	bool LoadContent();
	void UnloadContent();

	void Update(float dt);
	void Render();

private:
	ID3D11VertexShader* solidColorVS_;
	ID3D11PixelShader* solidColorPS_;

	ID3D11InputLayout* inputLayout_;
	ID3D11Buffer* vertexBuffer_;
};
#endif