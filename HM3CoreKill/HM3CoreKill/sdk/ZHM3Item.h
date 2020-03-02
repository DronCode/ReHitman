#pragma once

#include <cstdint>
#include <sdk/ZSTD.h>
#include <sdk/ZGEOM.h>
#include <sdk/ZEntityLocator.h>
#include <sdk/ZHM3ItemTemplate.h>

namespace ioi { namespace hm3 {

	class ZHM3Item
	{
	public:
		// === members ===
		ZEntityLocator* m_entityLocator; //0x0004
		char pad_0008[4]; //0x0008
		uint32_t __MEMCHECK__; //0x000C
		char pad_0010[48]; //0x0010
		ZEntityLocator* m_entityLocator2; //0x0040
		char pad_0044[64]; //0x0044
		ZGEOM* m_GEOM; //0x0084
		char pad_0088[20]; //0x0088

		// === vftable ===
		virtual void Function_0000(); //#0000 +0000 .rdata:0079801c
		virtual void Function_0001(); //#0001 +0004 .rdata:00798020
		virtual void Function_0002(); //#0002 +0008 .rdata:00798024
		virtual void Function_0003(); //#0003 +000c .rdata:00798028
		virtual void Function_0004(); //#0004 +0010 .rdata:0079802c
		virtual void Function_0005(); //#0005 +0014 .rdata:00798030
		virtual void Function_0006(); //#0006 +0018 .rdata:00798034
		virtual void Function_0007(); //#0007 +001c .rdata:00798038
		virtual void Function_0008(); //#0008 +0020 .rdata:0079803c
		virtual void Function_0009(); //#0009 +0024 .rdata:00798040
		virtual void Function_0010(); //#0010 +0028 .rdata:00798044
		virtual void Function_0011(); //#0011 +002c .rdata:00798048
		virtual void Function_0012(); //#0012 +0030 .rdata:0079804c
		virtual std::intptr_t getClassID(); //#0013 +0034 .rdata:00798050
		virtual void Function_0014(); //#0014 +0038 .rdata:00798054
		virtual void Function_0015(); //#0015 +003c .rdata:00798058
		virtual void Function_0016(); //#0016 +0040 .rdata:0079805c
		virtual void Function_0017(); //#0017 +0044 .rdata:00798060
		virtual void Function_0018(); //#0018 +0048 .rdata:00798064
		virtual void Function_0019(); //#0019 +004c .rdata:00798068
		virtual void Function_0020(); //#0020 +0050 .rdata:0079806c
		virtual void Function_0021(); //#0021 +0054 .rdata:00798070
		virtual void Function_0022(); //#0022 +0058 .rdata:00798074
		virtual void Function_0023(); //#0023 +005c .rdata:00798078
		virtual void Function_0024(); //#0024 +0060 .rdata:0079807c
		virtual void Function_0025(); //#0025 +0064 .rdata:00798080
		virtual void Function_0026(); //#0026 +0068 .rdata:00798084
		virtual void Function_0027(); //#0027 +006c .rdata:00798088
		virtual void Function_0028(); //#0028 +0070 .rdata:0079808c
		virtual void Function_0029(); //#0029 +0074 .rdata:00798090
		virtual void Function_0030(); //#0030 +0078 .rdata:00798094
		virtual void Function_0031(); //#0031 +007c .rdata:00798098
		virtual void Function_0032(); //#0032 +0080 .rdata:0079809c
		virtual void Function_0033(); //#0033 +0084 .rdata:007980a0
		virtual void Function_0034(); //#0034 +0088 .rdata:007980a4
		virtual void Function_0035(); //#0035 +008c .rdata:007980a8
		virtual void Function_0036(); //#0036 +0090 .rdata:007980ac
		virtual void Function_0037(); //#0037 +0094 .rdata:007980b0
		virtual void Function_0038(); //#0038 +0098 .rdata:007980b4
		virtual void Function_0039(); //#0039 +009c .rdata:007980b8
		virtual void Function_0040(); //#0040 +00a0 .rdata:007980bc
		virtual void Function_0041(); //#0041 +00a4 .rdata:007980c0
		virtual void Function_0042(); //#0042 +00a8 .rdata:007980c4
		virtual void Function_0043(); //#0043 +00ac .rdata:007980c8
		virtual void Function_0044(); //#0044 +00b0 .rdata:007980cc
		virtual void Function_0045(); //#0045 +00b4 .rdata:007980d0
		virtual void Function_0046(); //#0046 +00b8 .rdata:007980d4
		virtual void Function_0047(); //#0047 +00bc .rdata:007980d8
		virtual void Function_0048(); //#0048 +00c0 .rdata:007980dc
		virtual void Function_0049(); //#0049 +00c4 .rdata:007980e0
		virtual void Function_0050(); //#0050 +00c8 .rdata:007980e4
		virtual void Function_0051(); //#0051 +00cc .rdata:007980e8
		virtual void Function_0052(); //#0052 +00d0 .rdata:007980ec
		virtual void Function_0053(); //#0053 +00d4 .rdata:007980f0
		virtual void Function_0054(); //#0054 +00d8 .rdata:007980f4
		virtual void Function_0055(); //#0055 +00dc .rdata:007980f8
		virtual void Function_0056(); //#0056 +00e0 .rdata:007980fc
		virtual void Function_0057(); //#0057 +00e4 .rdata:00798100
		virtual void Function_0058(); //#0058 +00e8 .rdata:00798104
		virtual void Function_0059(); //#0059 +00ec .rdata:00798108
		virtual void Function_0060(); //#0060 +00f0 .rdata:0079810c
		virtual void Function_0061(); //#0061 +00f4 .rdata:00798110
		virtual void Function_0062(); //#0062 +00f8 .rdata:00798114
		virtual void Function_0063(); //#0063 +00fc .rdata:00798118
		virtual int Function_0064(const char*); //#0064 +0100 .rdata:0079811c
		virtual void Function_0065(); //#0065 +0104 .rdata:00798120
		virtual void Function_0066(); //#0066 +0108 .rdata:00798124
		virtual void Function_0067(); //#0067 +010c .rdata:00798128
		virtual void Function_0068(); //#0068 +0110 .rdata:0079812c
		virtual void Function_0069(); //#0069 +0114 .rdata:00798130
		virtual void Function_0070(); //#0070 +0118 .rdata:00798134
		virtual void Function_0071(); //#0071 +011c .rdata:00798138
		virtual void sendEvent(std::intptr_t ev, int unk0, int unk1); //#0072 +0120 .rdata:0079813c
		virtual void Function_0073(); //#0073 +0124 .rdata:00798140
		virtual void sendEventWithSTDOBJ(ZSTDOBJ* stdObj, std::intptr_t ev, int* pResult); //#0074 +0128 .rdata:00798144
		virtual void Function_0075(); //#0075 +012c .rdata:00798148
		virtual void Function_0076(); //#0076 +0130 .rdata:0079814c
		virtual void Function_0077(); //#0077 +0134 .rdata:00798150
		virtual void Function_0078(); //#0078 +0138 .rdata:00798154
		virtual void Function_0079(); //#0079 +013c .rdata:00798158
		virtual void Function_0080(); //#0080 +0140 .rdata:0079815c
		virtual void Function_0081(); //#0081 +0144 .rdata:00798160
		virtual void Function_0082(); //#0082 +0148 .rdata:00798164
		virtual void Function_0083(); //#0083 +014c .rdata:00798168
		virtual void Function_0084(); //#0084 +0150 .rdata:0079816c
		virtual void Function_0085(); //#0085 +0154 .rdata:00798170
		virtual void Function_0086(); //#0086 +0158 .rdata:00798174
		virtual void Function_0087(); //#0087 +015c .rdata:00798178
		virtual void Function_0088(); //#0088 +0160 .rdata:0079817c
		virtual void Function_0089(); //#0089 +0164 .rdata:00798180
		virtual void Function_0090(); //#0090 +0168 .rdata:00798184
		virtual void Function_0091(); //#0091 +016c .rdata:00798188
		virtual void Function_0092(); //#0092 +0170 .rdata:0079818c
		virtual void Function_0093(); //#0093 +0174 .rdata:00798190
		virtual void Function_0094(); //#0094 +0178 .rdata:00798194
		virtual void Function_0095(); //#0095 +017c .rdata:00798198
		virtual void Function_0096(); //#0096 +0180 .rdata:0079819c
		virtual void Function_0097(); //#0097 +0184 .rdata:007981a0
		virtual void Function_0098(); //#0098 +0188 .rdata:007981a4
		virtual void Function_0099(); //#0099 +018c .rdata:007981a8
		virtual void Function_0100(); //#0100 +0190 .rdata:007981ac
		virtual void Function_0101(); //#0101 +0194 .rdata:007981b0
		virtual void Function_0102(); //#0102 +0198 .rdata:007981b4
		virtual void Function_0103(); //#0103 +019c .rdata:007981b8
		virtual void Function_0104(); //#0104 +01a0 .rdata:007981bc
		virtual void Function_0105(); //#0105 +01a4 .rdata:007981c0
		virtual void Function_0106(); //#0106 +01a8 .rdata:007981c4
		virtual void Function_0107(); //#0107 +01ac .rdata:007981c8
		virtual void Function_0108(); //#0108 +01b0 .rdata:007981cc
		virtual void Function_0109(); //#0109 +01b4 .rdata:007981d0
		virtual void Function_0110(); //#0110 +01b8 .rdata:007981d4
		virtual void Function_0111(); //#0111 +01bc .rdata:007981d8
		virtual void Function_0112(); //#0112 +01c0 .rdata:007981dc
		virtual void Function_0113(); //#0113 +01c4 .rdata:007981e0
		virtual void Function_0114(); //#0114 +01c8 .rdata:007981e4
		virtual void Function_0115(); //#0115 +01cc .rdata:007981e8
		virtual void Function_0116(); //#0116 +01d0 .rdata:007981ec
		virtual void Function_0117(); //#0117 +01d4 .rdata:007981f0
		virtual void Function_0118(); //#0118 +01d8 .rdata:007981f4
		virtual void Function_0119(); //#0119 +01dc .rdata:007981f8
		virtual void Function_0120(); //#0120 +01e0 .rdata:007981fc
		virtual void Function_0121(); //#0121 +01e4 .rdata:00798200
		virtual void Function_0122(); //#0122 +01e8 .rdata:00798204
		virtual void Function_0123(); //#0123 +01ec .rdata:00798208
		virtual void Function_0124(); //#0124 +01f0 .rdata:0079820c
		virtual void Function_0125(); //#0125 +01f4 .rdata:00798210
		virtual void Function_0126(); //#0126 +01f8 .rdata:00798214
		virtual void Function_0127(); //#0127 +01fc .rdata:00798218
		virtual void Function_0128(); //#0128 +0200 .rdata:0079821c
		virtual void Function_0129(); //#0129 +0204 .rdata:00798220
		virtual void Function_0130(); //#0130 +0208 .rdata:00798224
		virtual void Function_0131(); //#0131 +020c .rdata:00798228
		virtual void Function_0132(); //#0132 +0210 .rdata:0079822c
		virtual void Function_0133(); //#0133 +0214 .rdata:00798230
		virtual void Function_0134(); //#0134 +0218 .rdata:00798234
		virtual void Function_0135(); //#0135 +021c .rdata:00798238
		virtual void Function_0136(); //#0136 +0220 .rdata:0079823c
		virtual void Function_0137(); //#0137 +0224 .rdata:00798240
		virtual void Function_0138(); //#0138 +0228 .rdata:00798244
		virtual void Function_0139(); //#0139 +022c .rdata:00798248
		virtual void Function_0140(); //#0140 +0230 .rdata:0079824c
		virtual void Function_0141(); //#0141 +0234 .rdata:00798250
		virtual void Function_0142(); //#0142 +0238 .rdata:00798254
		virtual void Function_0143(); //#0143 +023c .rdata:00798258
		virtual void Function_0144(); //#0144 +0240 .rdata:0079825c
		virtual void Function_0145(); //#0145 +0244 .rdata:00798260
		virtual void Function_0146(); //#0146 +0248 .rdata:00798264
		virtual void Function_0147(); //#0147 +024c .rdata:00798268
		virtual void Function_0148(); //#0148 +0250 .rdata:0079826c
		virtual void Function_0149(); //#0149 +0254 .rdata:00798270
		virtual void Function_0150(); //#0150 +0258 .rdata:00798274
		virtual void Function_0151(); //#0151 +025c .rdata:00798278
		virtual void Function_0152(); //#0152 +0260 .rdata:0079827c
		virtual void Function_0153(); //#0153 +0264 .rdata:00798280
		virtual void Function_0154(); //#0154 +0268 .rdata:00798284
		virtual void Function_0155(); //#0155 +026c .rdata:00798288
		virtual void Function_0156(); //#0156 +0270 .rdata:0079828c
		virtual ZHM3ItemTemplate* getItemTemplate(); //#0157 +0274 .rdata:00798290
		virtual void Function_0158(); //#0158 +0278 .rdata:00798294
		virtual void Function_0159(); //#0159 +027c .rdata:00798298
		virtual void Function_0160(); //#0160 +0280 .rdata:0079829c
		virtual void Function_0161(); //#0161 +0284 .rdata:007982a0
		virtual void Function_0162(); //#0162 +0288 .rdata:007982a4
		virtual void Function_0163(); //#0163 +028c .rdata:007982a8
		virtual void Function_0164(); //#0164 +0290 .rdata:007982ac
		virtual void Function_0165(); //#0165 +0294 .rdata:007982b0
		virtual void Function_0166(); //#0166 +0298 .rdata:007982b4
		virtual void Function_0167(); //#0167 +029c .rdata:007982b8
		virtual void Function_0168(); //#0168 +02a0 .rdata:007982bc
		virtual void Function_0169(); //#0169 +02a4 .rdata:007982c0
		virtual void Function_0170(); //#0170 +02a8 .rdata:007982c4
		virtual void Function_0171(); //#0171 +02ac .rdata:007982c8
		virtual void Function_0172(); //#0172 +02b0 .rdata:007982cc
		virtual void Function_0173(); //#0173 +02b4 .rdata:007982d0
		virtual void Function_0174(signed int amount); //#0174 +02b8 .rdata:007982d4 (unknown setter)
		virtual void Function_0175(); //#0175 +02bc .rdata:007982d8

		// === custom ===
		static ZHM3Item* findItemByID(int itemID);
	}; //Size: 0x009C
}}