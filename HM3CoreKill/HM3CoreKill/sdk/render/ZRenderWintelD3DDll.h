#pragma once

#include <cstdint>

#include <sdk/ZSTD.h>
#include <sdk/MathCommon.h>
#include <sdk/render/ZTextureManagerD3D.h>
#include <sdk/render/ZRenderMaterialBufferD3D.h>
#include <sdk/render/ZPrimControlWintel.h>

namespace ioi { namespace hm3 {

	struct ZVisibleEntitiesPool
	{
		int32_t _counter1;
		int32_t _counter2;
	};

	class ZRenderWintelD3DDll
	{
	public:
		// === data ===
		char* m_dllName; //0x0004
		int32_t m_field8; //0x0008
		int32_t m_fieldC; //0x000C
		int32_t m_field10; //0x0010
		ZTextureManagerD3D* m_textureManager; //0x0014
		ZPrimControlWintel* m_primControl; //0x0018
		ZRenderMaterialBufferD3D* m_renderMaterialBuffer; //0x001C
		char pad_0020[4]; //0x0020
		Vector3* m_unkVec3; //0x0024
		char pad_0028[28]; //0x0028
		class LINKREFTAB m_linkreftab; //0x0044
		char pad_006C[12]; //0x006C
		int32_t m_field78; //0x0078
		char pad_007C[8]; //0x007C
		float m_field84; //0x0084
		char pad_0088[28]; //0x0088
		int32_t m_fieldA4; //0x00A4
		float m_fieldA8; //0x00A8
		char pad_00AC[28]; //0x00AC

		// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:00763754
		virtual void Function_0001(); //#1 +4 .rdata:00763758
		virtual void Function_0002(); //#2 +8 .rdata:0076375c
		virtual void Function_0003(); //#3 +c .rdata:00763760
		virtual void Function_0004(); //#4 +10 .rdata:00763764
		virtual void Function_0005(); //#5 +14 .rdata:00763768
		virtual void Function_0006(); //#6 +18 .rdata:0076376c
		virtual void Function_0007(); //#7 +1c .rdata:00763770
		virtual void Function_0008(); //#8 +20 .rdata:00763774
		virtual void Function_0009(); //#9 +24 .rdata:00763778
		virtual void Function_0010(); //#10 +28 .rdata:0076377c
		virtual void Function_0011(); //#11 +2c .rdata:00763780
		virtual void Function_0012(); //#12 +30 .rdata:00763784
		virtual void Function_0013(); //#13 +34 .rdata:00763788
		virtual void Function_0014(); //#14 +38 .rdata:0076378c
		virtual void Function_0015(); //#15 +3c .rdata:00763790
		virtual void Function_0016(); //#16 +40 .rdata:00763794
		virtual void Function_0017(); //#17 +44 .rdata:00763798
		virtual void Function_0018(); //#18 +48 .rdata:0076379c
		virtual void Function_0019(); //#19 +4c .rdata:007637a0
		virtual void Function_0020(); //#20 +50 .rdata:007637a4
		virtual void Function_0021(); //#21 +54 .rdata:007637a8
		virtual void Function_0022(); //#22 +58 .rdata:007637ac
		virtual void Function_0023(); //#23 +5c .rdata:007637b0
		virtual void Function_0024(); //#24 +60 .rdata:007637b4
		virtual void Function_0025(); //#25 +64 .rdata:007637b8
		virtual void Function_0026(); //#26 +68 .rdata:007637bc
		virtual void Function_0027(); //#27 +6c .rdata:007637c0
		virtual void Function_0028(); //#28 +70 .rdata:007637c4
		virtual void Function_0029(); //#29 +74 .rdata:007637c8
		virtual void Function_0030(); //#30 +78 .rdata:007637cc
		virtual void Function_0031(); //#31 +7c .rdata:007637d0
		virtual void Function_0032(); //#32 +80 .rdata:007637d4
		virtual void Function_0033(); //#33 +84 .rdata:007637d8
		virtual void Function_0034(); //#34 +88 .rdata:007637dc
		virtual void Function_0035(); //#35 +8c .rdata:007637e0
		virtual void Function_0036(); //#36 +90 .rdata:007637e4
		virtual void Function_0037(); //#37 +94 .rdata:007637e8
		virtual void Function_0038(); //#38 +98 .rdata:007637ec
		virtual void Function_0039(); //#39 +9c .rdata:007637f0
		virtual void Function_0040(); //#40 +a0 .rdata:007637f4
		virtual void Function_0041(); //#41 +a4 .rdata:007637f8
		virtual void Function_0042(); //#42 +a8 .rdata:007637fc
		virtual void Function_0043(); //#43 +ac .rdata:00763800
		virtual void Function_0044(); //#44 +b0 .rdata:00763804
		virtual void Function_0045(); //#45 +b4 .rdata:00763808
		virtual void Function_0046(); //#46 +b8 .rdata:0076380C
	}; //Size: 0x0140

} }