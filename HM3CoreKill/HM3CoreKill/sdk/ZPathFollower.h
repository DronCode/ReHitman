#pragma once

#include <sdk/ZLinkedListNodeBase.h>
#include <sdk/ZSTD.h>
#include <sdk/ZGlacierRTTI.h>

namespace ioi { namespace hm3 {

	class ZHM3Actor;

	class ZPathFollower : public ZLinkedListNodeBase
	{
	public:
		/// === members ===
		// { skipped entities from ZLinkedListNodeBase }
		char pad_0014[16]; //0x0014
		ZHM3Actor* m_actor; //0x0024
		char pad_0028[4]; //0x0028
		ZGlacierRTTI* m_RTTI; //0x002C
		ioi::REFTAB m_reftab; //0x0030
		ioi::ZLIST* m_currentPathPointsList; //0x004C
		int32_t m_pointsCount; //0x0050
		int32_t pad_0001; //0x0054
		int32_t pad_0002; //0x0058
		int32_t pad_0003; //0x005C
		int32_t pad_0004; //0x0060
		int32_t pad_0005; //0x0064
		int32_t m_pointsAvUnk0; //0x0068
		int32_t pad_0007; //0x006C

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0079d9fc
		virtual void Function_0001(); //#1 +4 .rdata:0079da00
		virtual void Function_0002(); //#2 +8 .rdata:0079da04
		virtual void Function_0003(); //#3 +c .rdata:0079da08
		virtual void Function_0004(); //#4 +10 .rdata:0079da0c
		virtual void Function_0005(); //#5 +14 .rdata:0079da10
		virtual void Function_0006(); //#6 +18 .rdata:0079da14
		virtual void Function_0007(); //#7 +1c .rdata:0079da18
		virtual void Function_0008(); //#8 +20 .rdata:0079da1c
		virtual void Function_0009(); //#9 +24 .rdata:0079da20
		virtual void Function_0010(); //#10 +28 .rdata:0079da24
		virtual void Function_0011(); //#11 +2c .rdata:0079da28
		virtual void Function_0012(); //#12 +30 .rdata:0079da2c
		virtual void Function_0013(); //#13 +34 .rdata:0079da30
		virtual void Function_0014(); //#14 +38 .rdata:0079da34
		virtual void Function_0015(); //#15 +3c .rdata:0079da38
		virtual void Function_0016(); //#16 +40 .rdata:0079da3c
		virtual void Function_0017(); //#17 +44 .rdata:0079da40
		virtual int assignPath(ZPathFollower* anotherPath); //#18 +48 .rdata:0079da44
		virtual const char* getTypeName(); //#19 +4c .rdata:0079da48
		virtual void Function_0020(); //#20 +50 .rdata:0079da4c
		virtual void Function_0021(); //#21 +54 .rdata:0079da50
		virtual void Function_0022(); //#22 +58 .rdata:0079da54
		virtual void Function_0023(); //#23 +5c .rdata:0079da58
		virtual void Function_0024(); //#24 +60 .rdata:0079da5c
		virtual void Function_0025(); //#25 +64 .rdata:0079da60
		virtual void Function_0026(); //#26 +68 .rdata:0079da64
		virtual void Function_0027(); //#27 +6c .rdata:0079da68
		virtual void Function_0028(); //#28 +70 .rdata:0079da6c
		virtual void processIncomingEvents(signed int evType, int arg0, int arg1); //#29 +74 .rdata:0079da70
		virtual void Function_0030(); //#30 +78 .rdata:0079da74
		virtual void Function_0031(); //#31 +7c .rdata:0079da78
		virtual void Function_0032(); //#32 +80 .rdata:0079da7c
		virtual void Function_0033(); //#33 +84 .rdata:0079da80
		virtual void setRuntimeInformation(ioi::hm3::ZGlacierRTTI* rtti); //#34 +88 .rdata:0079da84
		virtual void Function_0035(); //#35 +8c .rdata:0079da88


		/// sub_654380 <- Switch to path # | signature : int __thiscall sub654380(ZPathFollower*, int pathIndex)
	};

} }