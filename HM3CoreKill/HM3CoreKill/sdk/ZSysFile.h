#pragma once

#include <cstdint>

#include <sdk/ZSTD.h>

namespace ioi {
namespace hm3 {

	class ZSysFileWintel
	{
	public:
		/// === members ===
		LINKREFTAB* m_bigFilesToLoad; //0x0004
		int32_t m_field8; //0x0008
		int32_t m_fieldC; //0x000C
		char pad_0010[252]; //0x0010
		LINKREFTAB* m_unkLinkRefTab; //0x010C
		char pad_0110[40]; //0x0110

		/// === vftable ===
		virtual void Function_0000(); //#0 +0 .rdata:0075ecf4
		virtual void Function_0001(); //#1 +4 .rdata:0075ecf8
		virtual void Function_0002(); //#2 +8 .rdata:0075ecfc
		virtual void Function_0003(); //#3 +c .rdata:0075ed00
		virtual void Function_0004(); //#4 +10 .rdata:0075ed04
		virtual void Function_0005(); //#5 +14 .rdata:0075ed08
		virtual void Function_0006(); //#6 +18 .rdata:0075ed0c
		virtual void Function_0007(); //#7 +1c .rdata:0075ed10
		virtual void Function_0008(); //#8 +20 .rdata:0075ed14
		virtual void Function_0009(); //#9 +24 .rdata:0075ed18
		virtual void Function_0010(); //#10 +28 .rdata:0075ed1c
		virtual void Function_0011(); //#11 +2c .rdata:0075ed20
		virtual void Function_0012(); //#12 +30 .rdata:0075ed24
		virtual void Function_0013(); //#13 +34 .rdata:0075ed28
		virtual void Function_0014(); //#14 +38 .rdata:0075ed2c
		virtual void Function_0015(); //#15 +3c .rdata:0075ed30
		virtual void Function_0016(); //#16 +40 .rdata:0075ed34
		virtual void Function_0017(); //#17 +44 .rdata:0075ed38
		virtual void Function_0018(); //#18 +48 .rdata:0075ed3c
		virtual void Function_0019(); //#19 +4c .rdata:0075ed40
		virtual void Function_0020(); //#20 +50 .rdata:0075ed44
		virtual void Function_0021(); //#21 +54 .rdata:0075ed48
		virtual void Function_0022(); //#22 +58 .rdata:0075ed4c
		virtual void Function_0023(); //#23 +5c .rdata:0075ed50
		virtual void Function_0024(); //#24 +60 .rdata:0075ed54
		virtual void Function_0025(); //#25 +64 .rdata:0075ed58
		virtual void Function_0026(); //#26 +68 .rdata:0075ed5c
		virtual void Function_0027(); //#27 +6c .rdata:0075ed60
		virtual void Function_0028(); //#28 +70 .rdata:0075ed64
		virtual void Function_0029(); //#29 +74 .rdata:0075ed68
		virtual void Function_0030(); //#30 +78 .rdata:0075ed6c
		virtual void Function_0031(); //#31 +7c .rdata:0075ed70
		virtual void Function_0032(); //#32 +80 .rdata:0075ed74
		virtual void Function_0033(); //#33 +84 .rdata:0075ed78
		virtual void Function_0034(); //#34 +88 .rdata:0075ed7c
		virtual void Function_0035(); //#35 +8c .rdata:0075ed80
		virtual void Function_0036(); //#36 +90 .rdata:0075ed84
		virtual void Function_0037(); //#37 +94 .rdata:0075ed88
		virtual void Function_0038(); //#38 +98 .rdata:0075ed8c
		virtual void Function_0039(); //#39 +9c .rdata:0075ed90
		virtual void Function_0040(); //#40 +a0 .rdata:0075ed94
		virtual void Function_0041(); //#41 +a4 .rdata:0075ed98
		virtual void Function_0042(); //#42 +a8 .rdata:0075ed9c
		virtual void Function_0043(); //#43 +ac .rdata:0075eda0
		virtual void Function_0044(); //#44 +b0 .rdata:0075eda4
		virtual void Function_0045(); //#45 +b4 .rdata:0075eda8
		virtual void Function_0046(); //#46 +b8 .rdata:0075edac
		virtual void Function_0047(); //#47 +bc .rdata:0075edb0
		virtual void Function_0048(); //#48 +c0 .rdata:0075edb4
		virtual void Function_0049(); //#49 +c4 .rdata:0075edb8
		virtual void Function_0050(); //#50 +c8 .rdata:0075edbc
		virtual void Function_0051(); //#51 +cc .rdata:0075edc0
		virtual void Function_0052(); //#52 +d0 .rdata:0075edc4
		virtual void Function_0053(); //#53 +d4 .rdata:0075edc8
		virtual void Function_0054(); //#54 +d8 .rdata:0075edcc
		virtual void Function_0055(); //#55 +dc .rdata:0075edd0
		virtual void Function_0056(); //#56 +e0 .rdata:0075edd4
		virtual void Function_0057(); //#57 +e4 .rdata:0075edd8
		virtual void Function_0058(); //#58 +e8 .rdata:0075eddc
		virtual void Function_0059(); //#59 +ec .rdata:0075ede0
		virtual void Function_0060(); //#60 +f0 .rdata:0075ede4
		virtual void Function_0061(); //#61 +f4 .rdata:0075ede8
		virtual void Function_0062(); //#62 +f8 .rdata:0075edec
		virtual void Function_0063(); //#63 +fc .rdata:0075edf0
		virtual void Function_0064(); //#64 +100 .rdata:0075edf4
		virtual void Function_0065(); //#65 +104 .rdata:0075edf8
		virtual void Function_0066(); //#66 +108 .rdata:0075edfc
		virtual void Function_0067(); //#67 +10c .rdata:0075ee00
		virtual void Function_0068(); //#68 +110 .rdata:0075ee04
		virtual void Function_0069(); //#69 +114 .rdata:0075ee08
		virtual void Function_0070(); //#70 +118 .rdata:0075ee0c
		virtual void Function_0071(); //#71 +11c .rdata:0075ee10
		virtual void Function_0072(); //#72 +120 .rdata:0075ee14
		virtual void Function_0073(); //#73 +124 .rdata:0075ee18
		virtual void Function_0074(); //#74 +128 .rdata:0075ee1c
		virtual void Function_0075(); //#75 +12c .rdata:0075ee20
		virtual void Function_0076(); //#76 +130 .rdata:0075ee24
		virtual void Function_0077(); //#77 +134 .rdata:0075ee28
		virtual void Function_0078(); //#78 +138 .rdata:0075ee2c
		virtual void Function_0079(); //#79 +13c .rdata:0075ee30
		virtual void Function_0080(); //#80 +140 .rdata:0075ee34
		virtual void Function_0081(); //#81 +144 .rdata:0075ee38
		virtual void Function_0082(); //#82 +148 .rdata:0075ee3c
		virtual void Function_0083(); //#83 +14c .rdata:0075ee40
		virtual void Function_0084(); //#84 +150 .rdata:0075ee44
	};

}}