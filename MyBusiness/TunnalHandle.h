#pragma once
#include "ManualHandle.h"
class Component;
class CTunnalHandle : public ManualHandle
{
public:
	CTunnalHandle(Component* compo = nullptr);
	void Install() override;
	void Update() override;
	void UnInstall() override;
	void Reload() override;
private:
	Component* m_compo;
};

