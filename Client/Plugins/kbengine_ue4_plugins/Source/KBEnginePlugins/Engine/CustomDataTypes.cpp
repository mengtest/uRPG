#include "CustomDataTypes.h"
#include "EntityDef.h"
#include "KBDebug.h"
#include "DataTypes.h"
#include "Runtime/Core/Public/Misc/Variant.h"

namespace KBEngine
{

void DATATYPE_ENTITY_FORBID_COUNTER::createFromStreamEx(MemoryStream& stream, ENTITY_FORBID_COUNTER& datas)
{
	uint32 size = stream.readUint32();
	while(size > 0)
	{
		--size;
		datas.Add(stream.readInt8());
	};

}

void DATATYPE_ENTITY_FORBID_COUNTER::addToStreamEx(Bundle& stream, const ENTITY_FORBID_COUNTER& v)
{
	stream.writeUint32((uint32)v.Num());
	for(int i=0; i<v.Num(); ++i)
	{
		stream.writeInt8(v[i]);
	};
}

void DATATYPE_ENTITYID_LIST::createFromStreamEx(MemoryStream& stream, ENTITYID_LIST& datas)
{
	uint32 size = stream.readUint32();
	while(size > 0)
	{
		--size;
		datas.Add(stream.readInt32());
	};

}

void DATATYPE_ENTITYID_LIST::addToStreamEx(Bundle& stream, const ENTITYID_LIST& v)
{
	stream.writeUint32((uint32)v.Num());
	for(int i=0; i<v.Num(); ++i)
	{
		stream.writeInt32(v[i]);
	};
}

void DATATYPE_AVATAR_DATA::createFromStreamEx(MemoryStream& stream, AVATAR_DATA& datas)
{
	datas.param1 = stream.readInt8();
	datas.param2 = stream.readBlob();
}

void DATATYPE_AVATAR_DATA::addToStreamEx(Bundle& stream, const AVATAR_DATA& v)
{
	stream.writeInt8(v.param1);
	stream.writeBlob(v.param2);
}

void DATATYPE_AVATAR_INFOS::createFromStreamEx(MemoryStream& stream, AVATAR_INFOS& datas)
{
	datas.dbid = stream.readUint64();
	datas.name = stream.readUnicode();
	datas.raceType = stream.readUint8();
	datas.level = stream.readUint16();
	data_DataType.createFromStreamEx(stream, datas.data);
}

void DATATYPE_AVATAR_INFOS::addToStreamEx(Bundle& stream, const AVATAR_INFOS& v)
{
	stream.writeUint64(v.dbid);
	stream.writeUnicode(v.name);
	stream.writeUint8(v.raceType);
	stream.writeUint16(v.level);
	data_DataType.addToStreamEx(stream, v.data);
}

void DATATYPE_AVATAR_INFOS_LIST::createFromStreamEx(MemoryStream& stream, AVATAR_INFOS_LIST& datas)
{
	values_DataType.createFromStreamEx(stream, datas.values);
}

void DATATYPE_AVATAR_INFOS_LIST::addToStreamEx(Bundle& stream, const AVATAR_INFOS_LIST& v)
{
	values_DataType.addToStreamEx(stream, v.values);
}


}