#pragma once

#include "engine/core/scene/node.h"
#include "physx_base.h"

namespace Echo
{
	class PhysxBody : public Node 
	{
		ECHO_CLASS(PhysxBody, Node)

	public:
		PhysxBody();
		virtual ~PhysxBody();

		// type
		const StringOption& getType() { return m_type; }
		void setType(const StringOption& type) { m_type.setValue(type.getValue()); }

		// get physx body
		physx::PxRigidActor* getPxBody() { return m_pxBody; }

		// linear velocity
		void setLinearVelocity(const Vector3& velocity);
		Vector3 getLinearVelocity();

		// apply force
		void addForce(const Vector3& force);

	private:
		// update
		virtual void updateInternal(float elapsedTime) override;

	private:
		physx::PxRigidActor*m_pxBody = nullptr;
		StringOption		m_type;
	};
}
