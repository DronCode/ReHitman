#pragma once

#include <sdk/ZSTD.h>
#include <sdk/ZGlacierRTTI.h>

namespace ioi {
namespace hm3 {

	// Created with ReClass.NET 1.2 by KN4CK3R

	class CTelePortList /// TypeInfo at 0x99CB30
	{
	public:
		char pad_0004[32]; //0x0004
		ZLIST* m_pointsList; //0x024
		char pad_0028[24]; //0x0028

		virtual void Function_0000(); //#0 +0 .rdata:007779cc
		virtual void Function_0001(); //#1 +4 .rdata:007779d0
		virtual void Function_0002(); //#2 +8 .rdata:007779d4
		virtual void Function_0003(); //#3 +c .rdata:007779d8
		virtual void Function_0004(); //#4 +10 .rdata:007779dc
		virtual void Function_0005(); //#5 +14 .rdata:007779e0
		virtual void Function_0006(); //#6 +18 .rdata:007779e4
		virtual void Function_0007(); //#7 +1c .rdata:007779e8
		virtual void Function_0008(); //#8 +20 .rdata:007779ec
		virtual void Function_0009(); //#9 +24 .rdata:007779f0
		virtual void Function_0010(); //#10 +28 .rdata:007779f4
		virtual void Function_0011(); //#11 +2c .rdata:007779f8
		virtual void Function_0012(); //#12 +30 .rdata:007779fc
		virtual void Function_0013(); //#13 +34 .rdata:00777a00
		virtual void Function_0014(); //#14 +38 .rdata:00777a04
		virtual void Function_0015(); //#15 +3c .rdata:00777a08
		virtual void Function_0016(); //#16 +40 .rdata:00777a0c
		virtual void Function_0017(); //#17 +44 .rdata:00777a10
		virtual void Function_0018(); //#18 +48 .rdata:00777a14
		virtual void Function_0019(); //#19 +4c .rdata:00777a18
		virtual void Function_0020(); //#20 +50 .rdata:00777a1c
		virtual void Function_0021(); //#21 +54 .rdata:00777a20
		virtual void Function_0022(); //#22 +58 .rdata:00777a24
		virtual void Function_0023(); //#23 +5c .rdata:00777a28
		virtual void Function_0024(); //#24 +60 .rdata:00777a2c
		virtual void Function_0025(); //#25 +64 .rdata:00777a30
		virtual void Function_0026(); //#26 +68 .rdata:00777a34
		virtual void Function_0027(); //#27 +6c .rdata:00777a38
		virtual void Function_0028(); //#28 +70 .rdata:00777a3c
		virtual void Function_0029(); //#29 +74 .rdata:00777a40
		virtual void Function_0030(); //#30 +78 .rdata:00777a44
		virtual void Function_0031(); //#31 +7c .rdata:00777a48
		virtual int Function_0032(ZLIST* list); //#32 +80 .rdata:00777a4c
		virtual void Function_0033(); //#33 +84 .rdata:00777a50
		virtual void setRuntimeTypeInfo(ZGlacierRTTI* rtti); //#34 +88 .rdata:00777a54
		virtual void Function_0035(); //#35 +8c .rdata:00777a58

		static CTelePortList* create();
	}; //Size: 0x0040

}}