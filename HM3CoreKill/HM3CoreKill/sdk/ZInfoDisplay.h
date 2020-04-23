#pragma once

#include <cstdint>
#include <sdk/ZEntityLocator.h>
#include <sdk/ZGlacierRTTI.h>
#include <sdk/ZLinkedListNodeBase.h>
#include <sdk/ZCHAROBJ.h>
#include <sdk/ZWINDOW.h>

namespace ioi { namespace hm3 {


	class ZInfoDisplay : public ZLinkedListNodeBase
	{
	public:
		/// === members ===
		char pad_0014[16]; //0x0014
		ZWINDOW* m_window; //0x0024
		char pad_0028[4]; //0x0028
		ZGlacierRTTI* m_RTTI; //0x002C
		ZCHAROBJ* m_textField0; //0x0030
		ZCHAROBJ* m_textField1; //0x0034
		char pad_0038[72]; //0x0038
		char* m_informationStr; //0x0080
		char* m_warningStr; //0x0084
		char* m_hintStr; //0x0088

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:007a18bc
		virtual void Function_0001(); //#1 +4 .rdata:007a18c0
		virtual void Function_0002(); //#2 +8 .rdata:007a18c4
		virtual void Function_0003(); //#3 +c .rdata:007a18c8
		virtual void Function_0004(); //#4 +10 .rdata:007a18cc
		virtual void Function_0005(); //#5 +14 .rdata:007a18d0
		virtual void Function_0006(); //#6 +18 .rdata:007a18d4
		virtual void Function_0007(); //#7 +1c .rdata:007a18d8
		virtual void Function_0008(); //#8 +20 .rdata:007a18dc
		virtual void Function_0009(); //#9 +24 .rdata:007a18e0
		virtual void Function_0010(); //#10 +28 .rdata:007a18e4
		virtual void Function_0011(); //#11 +2c .rdata:007a18e8
		virtual void Function_0012(); //#12 +30 .rdata:007a18ec
		virtual void Function_0013(); //#13 +34 .rdata:007a18f0
		virtual void Function_0014(); //#14 +38 .rdata:007a18f4
		virtual void Function_0015(); //#15 +3c .rdata:007a18f8
		virtual void Function_0016(); //#16 +40 .rdata:007a18fc
		virtual void Function_0017(); //#17 +44 .rdata:007a1900
		virtual void Function_0018(); //#18 +48 .rdata:007a1904
		virtual void Function_0019(); //#19 +4c .rdata:007a1908
		virtual void Function_0020(); //#20 +50 .rdata:007a190c
		virtual void Function_0021(); //#21 +54 .rdata:007a1910
		virtual void Function_0022(); //#22 +58 .rdata:007a1914
		virtual void Function_0023(); //#23 +5c .rdata:007a1918
		virtual void Function_0024(); //#24 +60 .rdata:007a191c
		virtual void Function_0025(); //#25 +64 .rdata:007a1920
		virtual void Function_0026(); //#26 +68 .rdata:007a1924
		virtual void Function_0027(); //#27 +6c .rdata:007a1928
		virtual void Function_0028(); //#28 +70 .rdata:007a192c
		virtual void Function_0029(); //#29 +74 .rdata:007a1930
		virtual void Function_0030(); //#30 +78 .rdata:007a1934
		virtual void Function_0031(); //#31 +7c .rdata:007a1938
		virtual void Function_0032(); //#32 +80 .rdata:007a193c
		virtual void Function_0033(); //#33 +84 .rdata:007a1940
		virtual void Function_0034(); //#34 +88 .rdata:007a1944
		virtual void Function_0035(); //#35 +8c .rdata:007a1948
		virtual void Function_0036(); //#36 +90 .rdata:007a194c
		virtual void Function_0037(); //#37 +94 .rdata:007a1950
		virtual void Function_0038(); //#38 +98 .rdata:007a1954
		virtual void Function_0039(); //#39 +9c .rdata:007a1958
		virtual void Function_0040(); //#40 +a0 .rdata:007a195c
		virtual void Function_0041(); //#41 +a4 .rdata:007a1960
		virtual void Function_0042(); //#42 +a8 .rdata:007a1964
		virtual void Function_0043(); //#43 +ac .rdata:007a1968
		virtual void Function_0044(); //#44 +b0 .rdata:007a196c
		virtual void Function_0045(); //#45 +b4 .rdata:007a1970
		virtual void Function_0046(); //#46 +b8 .rdata:007a1974
		virtual void Function_0047(); //#47 +bc .rdata:007a1978
		virtual void Function_0048(); //#48 +c0 .rdata:007a197c
		virtual void Function_0049(); //#49 +c4 .rdata:007a1980
		virtual void Function_0050(); //#50 +c8 .rdata:007a1984
		virtual void Function_0051(); //#51 +cc .rdata:007a1988
		virtual void Function_0052(); //#52 +d0 .rdata:007a198c
	}; //Size: 0x008C

} }