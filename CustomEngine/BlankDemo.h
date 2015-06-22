#ifndef _BLANK_DEMO_H_
#define _BLANK_DEMO_H_

#include "Dx11Base.h"


class BlankDemo : public Dx11Base
{
public:
	BlankDemo();
	virtual ~BlankDemo();

	bool LoadContent();
	void UnloadContent();

	void Update(float dt);
	void Render();
};

#endif