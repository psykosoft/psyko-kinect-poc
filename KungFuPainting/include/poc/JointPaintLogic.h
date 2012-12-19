#ifndef _PSYKO_JOINTPAINTLOGIC_
#define _PSYKO_JOINTPAINTLOGIC_

#include <Windows.h>
#include <NuiApi.h>
#include <vector>
#include "poc/Painting.h"

namespace psyko
{

	class JointPaintLogic
	{
	public:
		JointPaintLogic(Painting* painting) : painting(painting) {}
		virtual ~JointPaintLogic() {}

		void AddJoint(int index) { joints.push_back(index); }
		
		void Update(matrix4x4& projection, ID3D11DeviceContext* deviceContext, const Vector4* positions);

		virtual void Activate() {}
		virtual void UpdateSim() {}
		virtual void UpdateJoint(matrix4x4& projection, const Vector4* positions, int index) = 0;

	protected:
		Painting* painting;

	private:
		std::vector<int> joints;
		
	};

	inline void JointPaintLogic::Update(matrix4x4& projection, ID3D11DeviceContext* deviceContext, const Vector4* positions)
	{
		ID3D11RenderTargetView* target = painting->GetRenderTargetView();
		
		deviceContext->OMSetRenderTargets(1, &target, 0);
		
		D3D11_VIEWPORT viewport;
		viewport.TopLeftX = 0;
		viewport.TopLeftY = 0;
		viewport.Width = (float)painting->GetTextureWidth();
		viewport.Height = (float)painting->GetTextureHeight();
		viewport.MinDepth = 0;
		viewport.MaxDepth = 1;		
		deviceContext->RSSetViewports(1, &viewport);

		UpdateSim();

		for (auto it = joints.begin(); it != joints.end(); ++it) {
			UpdateJoint(projection, positions, *it);
		}
	}
}
#endif