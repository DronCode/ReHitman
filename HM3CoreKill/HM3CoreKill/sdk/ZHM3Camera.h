#pragma once

#include <cstdint>
#include <sdk/MathCommon.h>
#include <sdk/ZGlacierRTTI.h>
#include <sdk/ZHM3CameraClass.h>
#include <sdk/ZLinkedListNodeBase.h>

namespace ioi {
namespace hm3 {
	class ZHM3Camera : public ZLinkedListNodeBase
	{
	public:
		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0078d99c
		virtual void Function_0001(); //#1 +4 .rdata:0078d9a0
		virtual void Function_0002(); //#2 +8 .rdata:0078d9a4
		virtual void Function_0003(); //#3 +c .rdata:0078d9a8
		virtual void Function_0004(); //#4 +10 .rdata:0078d9ac
		virtual void Function_0005(); //#5 +14 .rdata:0078d9b0
		virtual void Function_0006(); //#6 +18 .rdata:0078d9b4
		virtual void Function_0007(); //#7 +1c .rdata:0078d9b8
		virtual void Function_0008(); //#8 +20 .rdata:0078d9bc
		virtual void Function_0009(); //#9 +24 .rdata:0078d9c0
		virtual void Function_0010(); //#10 +28 .rdata:0078d9c4
		virtual void Function_0011(); //#11 +2c .rdata:0078d9c8
		virtual void Function_0012(); //#12 +30 .rdata:0078d9cc
		virtual void Function_0013(); //#13 +34 .rdata:0078d9d0
		virtual void Function_0014(); //#14 +38 .rdata:0078d9d4
		virtual void Function_0015(); //#15 +3c .rdata:0078d9d8
		virtual void Function_0016(); //#16 +40 .rdata:0078d9dc
		virtual void Function_0017(); //#17 +44 .rdata:0078d9e0
		virtual void Function_0018(); //#18 +48 .rdata:0078d9e4
		virtual void Function_0019(); //#19 +4c .rdata:0078d9e8
		virtual void Function_0020(); //#20 +50 .rdata:0078d9ec
		virtual void Function_0021(); //#21 +54 .rdata:0078d9f0
		virtual void Function_0022(); //#22 +58 .rdata:0078d9f4
		virtual void Function_0023(); //#23 +5c .rdata:0078d9f8
		virtual void Function_0024(); //#24 +60 .rdata:0078d9fc
		virtual void Function_0025(); //#25 +64 .rdata:0078da00
		virtual void Function_0026(); //#26 +68 .rdata:0078da04
		virtual void Function_0027(); //#27 +6c .rdata:0078da08
		virtual void Function_0028(); //#28 +70 .rdata:0078da0c
		virtual void Function_0029(); //#29 +74 .rdata:0078da10
		virtual void Function_0030(); //#30 +78 .rdata:0078da14
		virtual void Function_0031(); //#31 +7c .rdata:0078da18
		virtual void Function_0032(); //#32 +80 .rdata:0078da1c
		virtual void Function_0033(); //#33 +84 .rdata:0078da20
		virtual void Function_0034(); //#34 +88 .rdata:0078da24
		virtual void Function_0035(); //#35 +8c .rdata:0078da28
		virtual void Function_0036(); //#36 +90 .rdata:0078da2c
		virtual void Function_0037(); //#37 +94 .rdata:0078da30
		virtual void Function_0038(); //#38 +98 .rdata:0078da34
		virtual void Function_0039(); //#39 +9c .rdata:0078da38
		virtual void Function_0040(); //#40 +a0 .rdata:0078da3c
		virtual void Function_0041(); //#41 +a4 .rdata:0078da40
		virtual void Function_0042(); //#42 +a8 .rdata:0078da44
		virtual void Function_0043(); //#43 +ac .rdata:0078da48
		virtual void Function_0044(); //#44 +b0 .rdata:0078da4c
		virtual void Function_0045(); //#45 +b4 .rdata:0078da50
		virtual void Function_0046(); //#46 +b8 .rdata:0078da54
		virtual void Function_0047(); //#47 +bc .rdata:0078da58
		virtual void Function_0048(); //#48 +c0 .rdata:0078da5c

		/// === members ===
		
		char pad_0014[16];					//0x0014
		ZHM3CameraClass* m_cameraClass;		//0x0024
		char pad_0028[4];					//0x0028
		ZGlacierRTTI* m_RTTI;				//0x002C
		char pad_0030[4];					//0x0030
		Vector2 m_CameraSpaceSize;			//0x0034
		float m_ZCamOffset;					//0x003C 
		float m_camZoom;					//0x0040 
		float N00001B61;					//0x0044 
		int32_t N00001B62;					//0x0048 
		float N00001B6D;					//0x004C 
		float m_fogDist;					//0x0050 (default 30000.0)
		char pad_0x0054[0x50];				//0x0054
		float N00001B83;					//0x00A4 
		char pad_0x00A8[0x10];				//0x00A8
		float N00001B88;					//0x00B8 
		char pad_0x00BC[0x10];				//0x00BC
	}; //Size=0x009C


}}