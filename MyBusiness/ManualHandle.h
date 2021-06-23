#ifndef IMANUALHANDLE_H_
#define IMANUALHANDLE_H_

class ManualHandle
{
public:
	virtual void Install()		= 0;
	virtual void Update()		= 0;
	virtual void UnInstall()	= 0;
	virtual void Reload()		= 0;
	virtual ~ManualHandle() {};
};

#endif
