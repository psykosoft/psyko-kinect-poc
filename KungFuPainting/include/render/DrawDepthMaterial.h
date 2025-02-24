#ifndef _PSYKO_DRAWDEPTHMATERIAL_
#define _PSYKO_DRAWDEPTHMATERIAL_

#include <d3d11.h>
#include "render/Material.h"
#include "render/Texture2D.h"

namespace psyko
{
	class DrawDepthMaterial : public Material
	{
	public:
		DrawDepthMaterial(ID3D11Device* device);
		virtual ~DrawDepthMaterial();

		virtual void SetMeshInstanceState(const MeshInstance* meshInstance) const;
		void SetTexture(Texture2D* value) { texture = value; }
		int Init() { return LoadFromRawEffect(L"fx/DrawRect.fx"); }
		
		inline float GetWidth() const { return transform[0]; }
		inline float GetHeight() const { return transform[5]; }
		inline void SetWidth(float value) { transform[0] = value; }
		inline void SetHeight(float value) { transform[5] = value; }

		inline float GetX() const { return transform[12]; }
		inline float GetY() const { return transform[13]; }
		inline void SetX(float value) { transform[12] = value; }
		inline void SetY(float value) { transform[13] = value; }

		inline void SetTexWidth(float value) { texDimensions[0] = value; }
		inline void SetTexHeight(float value) { texDimensions[1] = value; }

	private:
		Texture2D* texture;
		float transform[16];
		float texDimensions[2];
	};
}
#endif