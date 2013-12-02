/***************************************************************
Transform Class: Provides a transform component to objects.

Author: Valentin Hinov
Date: 06/09/2013
Version: 1.0
**************************************************************/

#ifndef _TRANSFORM_H
#define _TRANSFORM_H

#include "Component.h"
#include "../utilities/math/MathUtils.h"

class Transform : public Component {
public:
	// Default constructor should not be used
	Transform() : Component(nullptr) {}

	Transform(const GameObject * const gameObject) : Component(gameObject), position(0,0,0),rotation(0,0,0),scale(1,1,1){
		
	}

	Transform(const GameObject * const gameObject, Vector3 &position, Vector3 &rotation, Vector3 &scale = Vector3(1,1,1)) 
		: Component(gameObject), position(position),rotation(rotation),scale(scale){
		
	}

	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	void GetTransformMatrix(Matrix &matrix) {
		Matrix m = Matrix::CreateScale(scale);
		matrix*=m;
		m = Matrix::CreateRotationX(rotation.x);
		matrix*=m;
		m = Matrix::CreateRotationY(rotation.y);
		matrix*=m;
		m = Matrix::CreateRotationZ(rotation.z);	
		matrix*=m;
		m = Matrix::CreateTranslation(position);
		matrix*=m;
	}

	~Transform(){}	
};

#endif