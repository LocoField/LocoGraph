#include "PCars2SharedMemory.h"



PCars2SharedMemory::PCars2SharedMemory()
{
}


PCars2SharedMemory::~PCars2SharedMemory()
{
	if( hFileMapping != nullptr ) CloseHandle(hFileMapping);
	if( pDataMapped != nullptr ) UnmapViewOfFile(pDataMapped);
	if( pDataLocal != nullptr ) delete pDataLocal;
}

bool PCars2SharedMemory::initialize()
{
	const char* MAP_OBJECT_NAME = "$pcars2$";

	hFileMapping = OpenFileMappingA(PAGE_READONLY, FALSE, MAP_OBJECT_NAME);
	if( hFileMapping == nullptr )
	{
		//printf("Could not open file mapping object (%d).\n", GetLastError());
		return false;
	}

	// Get the data structure
	pDataMapped = (SharedMemory*) MapViewOfFile(hFileMapping, PAGE_READONLY, 0, 0, sizeof(SharedMemory));
	if( pDataMapped == nullptr )
	{
		//printf("Could not map view of file (%d).\n", GetLastError());
		return false;
	}

	// Ensure we're sync'd to the correct data version
	if( pDataMapped->mVersion != SHARED_MEMORY_VERSION )
	{
		//printf("Data version mismatch\n");
		return false;
	}

	pDataLocal = new SharedMemory;
	return true;
}

void PCars2SharedMemory::update()
{
	while( pDataMapped->mSequenceNumber % 2 != 0 )
	{
		// Odd sequence number indicates, that write into the shared memory is just happening
		Sleep(1);
	}

	memcpy(pDataLocal, pDataMapped, sizeof(SharedMemory));
}

