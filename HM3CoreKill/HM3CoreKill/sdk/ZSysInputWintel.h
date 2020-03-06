#pragma once

#include <cstdint>
#include <sdk/ZMouseWintel.h>
#include <sdk/ZKeyboardWintel.h>

namespace ioi { namespace hm3 {

	// Created with ReClass.NET 1.2 by KN4CK3R

	class ZSysInputWintel
	{
	public:
		char pad_0004[12]; //0x0004
		ZMouseWintel* m_mouseDevice; //0x0010
		ZKeyboardWintel* m_keyboardDevice; //0x0014

		virtual void Function_0000(); //#0 +0 .rdata:0075f75c
		virtual void Function_0001(); //#1 +4 .rdata:0075f760
		virtual void Function_0002(); //#2 +8 .rdata:0075f764
		virtual void Function_0003(); //#3 +c .rdata:0075f768
		virtual void Function_0004(); //#4 +10 .rdata:0075f76c
		virtual void Function_0005(); //#5 +14 .rdata:0075f770
		virtual void Function_0006(); //#6 +18 .rdata:0075f774
		virtual void Function_0007(); //#7 +1c .rdata:0075f778
		virtual void Function_0008(); //#8 +20 .rdata:0075f77c
		virtual void Function_0009(); //#9 +24 .rdata:0075f780
		virtual void Function_0010(); //#10 +28 .rdata:0075f784
		virtual void Function_0011(); //#11 +2c .rdata:0075f788
		virtual void Function_0012(); //#12 +30 .rdata:0075f78c
		virtual void Function_0013(); //#13 +34 .rdata:0075f790
		virtual void Function_0014(); //#14 +38 .rdata:0075f794
		virtual void Function_0015(); //#15 +3c .rdata:0075f798
		virtual void Function_0016(); //#16 +40 .rdata:0075f79c
		virtual void Function_0017(); //#17 +44 .rdata:0075f7a0
		virtual void Function_0018(); //#18 +48 .rdata:0075f7a4
		virtual void Function_0019(); //#19 +4c .rdata:0075f7a8
		virtual void Function_0020(); //#20 +50 .rdata:0075f7ac
		virtual void Function_0021(); //#21 +54 .rdata:0075f7b0
		virtual void Function_0022(); //#22 +58 .rdata:0075f7b4
		virtual void Function_0023(); //#23 +5c .rdata:0075f7b8
		virtual void Function_0024(); //#24 +60 .rdata:0075f7bc
		virtual void Function_0025(); //#25 +64 .rdata:0075f7c0
		virtual void Function_0026(); //#26 +68 .rdata:0075f7c4
		virtual void Function_0027(); //#27 +6c .rdata:0075f7c8
		virtual int Function_0028(bool ); //#28 +70 .rdata:0075f7cc
		virtual void Function_0029(); //#29 +74 .rdata:0075f7d0
	}; //Size: 0x0018

}}