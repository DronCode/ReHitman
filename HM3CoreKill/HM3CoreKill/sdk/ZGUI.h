#pragma once

#include <cstdint>

#define CONCAT_IMPL(a,b) a##b
#define CONCAT(a,b) CONCAT_IMPL(a,b)
#define MEMBER_PAD(id, size) unsigned char CONCAT(CONCAT(__pad_, id),__)[size];

namespace ioi { namespace hm3 {

	class ZGUI
	{
	public:
		virtual void UnknownFunction_0();// +0000
		virtual void UnknownFunction_1();// +0004
		virtual void UnknownFunction_2();// +0008
		virtual void UnknownFunction_3();// +000C
		virtual void UnknownFunction_4();// +0010
		virtual void UnknownFunction_5();// +0014
		virtual void UnknownFunction_6();// +0018
		virtual void UnknownFunction_7();// +001C
		virtual void UnknownFunction_8();// +0020
		virtual void UnknownFunction_9();// +0024
		virtual void UnknownFunction_10();// +0028
		virtual void UnknownFunction_11();// +002C
		virtual void UnknownFunction_12();// +0030
		virtual void UnknownFunction_13();// +0034
		virtual void UnknownFunction_14();// +0038
		virtual void UnknownFunction_15();// +003C
		virtual void UnknownFunction_16();// +0040
		virtual void UnknownFunction_17();// +0044
		virtual void UnknownFunction_18();// +0048
		virtual void UnknownFunction_19();// +004C
		virtual void UnknownFunction_20();// +0050
		virtual void UnknownFunction_21();// +0054
		virtual void UnknownFunction_22();// +0058
		virtual void UnknownFunction_23();// +005C
		virtual void UnknownFunction_24();// +0060
		virtual void UnknownFunction_25();// +0064
		virtual void UnknownFunction_26();// +0068
		virtual void UnknownFunction_27();// +006C
		virtual void UnknownFunction_28();// +0070
		virtual void UnknownFunction_29();// +0074
		virtual void UnknownFunction_30();// +0078
		virtual void UnknownFunction_31();// +007C
		virtual void UnknownFunction_32();// +0080
		virtual void UnknownFunction_33();// +0084
		virtual void UnknownFunction_34();// +0088
		virtual void UnknownFunction_35();// +008C
		virtual void UnknownFunction_36();// +0090
		virtual void UnknownFunction_37();// +0094
		virtual void UnknownFunction_38();// +0098
		virtual void UnknownFunction_39();// +009C
		virtual void UnknownFunction_40();// +00A0
		virtual void UnknownFunction_41();// +00A4
		virtual void UnknownFunction_42();// +00A8
		virtual void UnknownFunction_43();// +00AC
		virtual void UnknownFunction_44();// +00B0
		virtual void UnknownFunction_45();// +00B4
		virtual void UnknownFunction_46();// +00B8
		virtual void UnknownFunction_47();// +00BC
		virtual void UnknownFunction_48();// +00C0
		virtual void UnknownFunction_49();// +00C4
		virtual void UnknownFunction_50();// +00C8
		virtual void UnknownFunction_51();// +00CC
		virtual void UnknownFunction_52();// +00D0
		virtual void UnknownFunction_53();// +00D4
		virtual void UnknownFunction_54();// +00D8
		virtual void UnknownFunction_55();// +00DC
		virtual void UnknownFunction_56();// +00E0
		virtual void UnknownFunction_57();// +00E4
		virtual void UnknownFunction_58();// +00E8
		virtual void UnknownFunction_59();// +00EC
		virtual void UnknownFunction_60();// +00F0
		virtual void UnknownFunction_61();// +00F4
		virtual void UnknownFunction_62();// +00F8
		virtual void UnknownFunction_63();// +00FC
		virtual void UnknownFunction_64();// +0100
		virtual void UnknownFunction_65();// +0104
		virtual void UnknownFunction_66();// +0108
		virtual void UnknownFunction_67();// +010C
		virtual void UnknownFunction_68();// +0110
		virtual void UnknownFunction_69();// +0114
		virtual void UnknownFunction_70();// +0118
		virtual void UnknownFunction_71();// +011C
		virtual void UnknownFunction_72();// +0120
		virtual void UnknownFunction_73();// +0124
		virtual void UnknownFunction_74();// +0128
		virtual void UnknownFunction_75();// +012C
		virtual void UnknownFunction_76();// +0130
		virtual void UnknownFunction_77();// +0134
		virtual void UnknownFunction_78();// +0138
		virtual void UnknownFunction_79();// +013C
		virtual void UnknownFunction_80();// +0140
		virtual void UnknownFunction_81();// +0144
		virtual void UnknownFunction_82();// +0148
		virtual void UnknownFunction_83();// +014C
		virtual void UnknownFunction_84();// +0150
		virtual void UnknownFunction_85();// +0154
		virtual void UnknownFunction_86();// +0158
		virtual void UnknownFunction_87();// +015C
		virtual void UnknownFunction_88();// +0160
		virtual void UnknownFunction_89();// +0164
		virtual void UnknownFunction_90();// +0168
		virtual void UnknownFunction_91();// +016C
		virtual void UnknownFunction_92();// +0170
		virtual void UnknownFunction_93();// +0174
		virtual void UnknownFunction_94();// +0178
		virtual void UnknownFunction_95();// +017C
		virtual void UnknownFunction_96();// +0180
		virtual void UnknownFunction_97();// +0184
		virtual void UnknownFunction_98();// +0188
		virtual void UnknownFunction_99();// +018C
		virtual void UnknownFunction_100();// +0190
		virtual void UnknownFunction_101();// +0194
		virtual void UnknownFunction_102();// +0198
		virtual void UnknownFunction_103();// +019C
		virtual void UnknownFunction_104();// +01A0
		virtual void UnknownFunction_105();// +01A4
		virtual void UnknownFunction_106();// +01A8
		virtual void UnknownFunction_107();// +01AC
		virtual void UnknownFunction_108();// +01B0
		virtual void UnknownFunction_109();// +01B4
		virtual void UnknownFunction_110();// +01B8
		virtual void UnknownFunction_111();// +01BC
		virtual void UnknownFunction_112();// +01C0
		virtual void UnknownFunction_113();// +01C4
		virtual void UnknownFunction_114();// +01C8
		virtual void UnknownFunction_115();// +01CC
		virtual void UnknownFunction_116();// +01D0
		virtual void UnknownFunction_117();// +01D4
		virtual void UnknownFunction_118();// +01D8
		virtual void UnknownFunction_119();// +01DC
		
		/// ---------- MEMBERS -----------
		MEMBER_PAD(0, 0x5C);
		std::uintptr_t m_InventoryMenu;		//5C
		MEMBER_PAD(1, 0x1C);
		std::uintptr_t m_Unknown_WINPIC;	//7C
		//TODO: Complete it
	};

}}

#undef MEMBER_PAD
#undef CONCAT
#undef CONCAT_IMPL