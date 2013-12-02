/*************************************************************
ServiceProvider.h: Provides access to the main services in the
engine.

Author: Valentin Hinov
Date: 04/09/2013
Version: 1.0
**************************************************************/
#ifndef _SERVICEPROVIDER_H_
#define _SERVICEPROVIDER_H_

#include "I_InputSystem.h"
#include "IGraphicsSystem.h"

class ServiceProvider {
public:		
	static ServiceProvider& Instance() {
		// Lazy initialize.
		if (mSingleton == nullptr)
			mSingleton = new ServiceProvider();

		return *mSingleton;
	}

	void Initialize(I_InputSystem* inputSystem, IGraphicsSystem* graphicsSystem) {
		if (mInitialized)
			return;

		pInputSystem = inputSystem;
		pGraphicsSystem = graphicsSystem;

		mInitialized = true;
	}

	I_InputSystem* GetInputSystem() { return pInputSystem; };
	IGraphicsSystem* GetGraphicsSystem() { return pGraphicsSystem; };

	~ServiceProvider() {
		pInputSystem = nullptr;
		pGraphicsSystem = nullptr;
	}

private:
	ServiceProvider() {mInitialized = false;}
	
private:
	static ServiceProvider *mSingleton;
	bool mInitialized;
	I_InputSystem* pInputSystem;
	IGraphicsSystem* pGraphicsSystem;
};

#endif
