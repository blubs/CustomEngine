#ifndef _TRI_DEMO_H_
#define _TRI_DEMO_H_

#include "Dx11Base.h"


class TextureDemo : public Dx11Base
{
public:
	TextureDemo();
	virtual ~TextureDemo();

	bool LoadContent();
	void UnloadContent();

	void Update(float dt);
	void Render();

private:
	ID3D11VertexShader* colorMapVS_;
	ID3D11PixelShader* colorMapPS_;

	ID3D11InputLayout* inputLayout_;
	ID3D11Buffer* vertexBuffer_;

	ID3D11ShaderResourceView* colorMap_;
	ID3D11SamplerState* colorMapSampler_;
};
#endif