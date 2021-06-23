#ifndef	DESKTOPMANUALHANDLE_H_
#define DESKTOPMANUALHANDLE_H_

#include "ManualHandle.h"

class Component;
class CDesktopHandle : public ManualHandle
{
public:
	CDesktopHandle(Component* compo);
	void Install() override;
	void Update() override;
	void UnInstall() override;
	void Reload() override;
private:
	Component* m_compo;
};



#endif

