#include <ck/Features.h>
#include <ck/HM3Game.h>
#include <ck/HM3Offsets.h>

#include <sdk/ZEventBuffer.h>
#include <sdk/ZEngineDatabase.h>
#include <sdk/ZGameGlobals.h>
#include <sdk/InterfacesProvider.h>
#include <sdk/CTelePortList.h>

namespace ck {

	void teleportPlayer()
	{
		ioi::hm3::ZEngineDatabase* engineDB = HM3Game::GetSystemInterface()->m_engineDataBase;
		ioi::hm3::ZEventBuffer* evBuffer = ioi::hm3::getGlacierInterface<ioi::hm3::ZEventBuffer>(ioi::hm3::EventBuffer);
		ioi::hm3::CCOM* comObject = ioi::hm3::getCCOMObjectFromEngineDB(engineDB);

		typedef void (__thiscall* ZGetEntityByTheirName)(ioi::hm3::CCOM*, const char*, int&);
		typedef void*(__thiscall* ZGetRawEntity)(ioi::hm3::ZEventBuffer*, int);
		typedef void (__thiscall* ZExecuteTeleport)(void*, int);

		ZGetEntityByTheirName	getEntityIdByTheirName	= (ZGetEntityByTheirName)HM3Offsets::ZGetEntityByTheirName_Func; // sub_426BA0 | aref from 0065B556
		ZGetRawEntity			getRawEntity			= (ZGetRawEntity)HM3Offsets::ZGetRawEntity_Func;
		ZExecuteTeleport		executeTeleport			= (ZExecuteTeleport)HM3Offsets::ZExecuteTeleport_Func;

		int entityId = 0x0;
		getEntityIdByTheirName(comObject, "rTeleportList", entityId);
		HM3_DEBUG("[ EntityID is %d ]\n", entityId);

		if (entityId != 0)
		{
			void* entityPtr = getRawEntity(evBuffer, entityId);
			HM3_DEBUG("[ Entity at 0x%.8X ]\n", entityPtr);
			executeTeleport(entityPtr, 1);
		}
	}

	void printTeleportPointsInCurrentLevel()
	{
		ioi::hm3::ZEngineDatabase* engineDB = HM3Game::GetSystemInterface()->m_engineDataBase;
		ioi::hm3::ZEventBuffer* evBuffer = ioi::hm3::getGlacierInterface<ioi::hm3::ZEventBuffer>(ioi::hm3::EventBuffer);
		ioi::hm3::CCOM* comObject = ioi::hm3::getCCOMObjectFromEngineDB(engineDB);

		typedef void(__thiscall* ZGetEntityByTheirName)(ioi::hm3::CCOM*, const char*, int&);
		typedef void* (__thiscall* ZGetRawEntity)(ioi::hm3::ZEventBuffer*, int);
		typedef void(__thiscall* ZExecuteTeleport)(void*, int);

		ZGetEntityByTheirName	getEntityIdByTheirName = (ZGetEntityByTheirName)HM3Offsets::ZGetEntityByTheirName_Func; // sub_426BA0 | aref from 0065B556
		ZGetRawEntity			getRawEntity = (ZGetRawEntity)HM3Offsets::ZGetRawEntity_Func;
		ZExecuteTeleport		executeTeleport = (ZExecuteTeleport)HM3Offsets::ZExecuteTeleport_Func;

		int entityId = 0x0;
		getEntityIdByTheirName(comObject, "rTeleportList", entityId);
		HM3_DEBUG("[ EntityID is %d ]\n", entityId);

		if (entityId != 0)
		{
			void* entityPtr = getRawEntity(evBuffer, entityId);
			
			ioi::hm3::CTelePortList* teleportsList = reinterpret_cast<ioi::hm3::CTelePortList*>(entityPtr);
			
			HM3_DEBUG(" --- [ Teleports %d ] ---\n", teleportsList->m_teleportPointsList->m_refTab->subItemsCount);
			for (int teleportId = 0; teleportId < teleportsList->m_teleportPointsList->m_refTab->subItemsCount; teleportId++)
			{
				const auto position = teleportsList->m_teleportPointsList->entities[teleportId].pValue->position;
				const auto name = teleportsList->m_teleportPointsList->entities[teleportId].pValue->objectName;

				HM3_DEBUG(" * Teleport point at { %.8f ; %.8f ; %.8f } with name \"%s\"\n", position.x, position.y, position.z, name);
			}
		}
	}

	void setTeleportPointForAllTeleports(float x, float y, float z)
	{
		ioi::hm3::ZEngineDatabase* engineDB = HM3Game::GetSystemInterface()->m_engineDataBase;
		ioi::hm3::ZEventBuffer* evBuffer = ioi::hm3::getGlacierInterface<ioi::hm3::ZEventBuffer>(ioi::hm3::EventBuffer);
		ioi::hm3::CCOM* comObject = ioi::hm3::getCCOMObjectFromEngineDB(engineDB);

		typedef void(__thiscall* ZGetEntityByTheirName)(ioi::hm3::CCOM*, const char*, int&);
		typedef void* (__thiscall* ZGetRawEntity)(ioi::hm3::ZEventBuffer*, int);
		typedef void(__thiscall* ZExecuteTeleport)(void*, int);

		ZGetEntityByTheirName	getEntityIdByTheirName = (ZGetEntityByTheirName)HM3Offsets::ZGetEntityByTheirName_Func; // sub_426BA0 | aref from 0065B556
		ZGetRawEntity			getRawEntity = (ZGetRawEntity)HM3Offsets::ZGetRawEntity_Func;
		ZExecuteTeleport		executeTeleport = (ZExecuteTeleport)HM3Offsets::ZExecuteTeleport_Func;

		int entityId = 0x0;
		getEntityIdByTheirName(comObject, "rTeleportList", entityId);
		HM3_DEBUG("[ EntityID is %d ]\n", entityId);

		if (entityId != 0)
		{
			void* entityPtr = getRawEntity(evBuffer, entityId);
			ioi::hm3::CTelePortList* teleportsList = reinterpret_cast<ioi::hm3::CTelePortList*>(entityPtr);

			for (int teleportId = 0; teleportId < teleportsList->m_teleportPointsList->m_refTab->subItemsCount; teleportId++)
			{
				teleportsList->m_teleportPointsList->entities[teleportId].pValue->position = ioi::Vector3{ x, y, z };
			}
		}
	}

}