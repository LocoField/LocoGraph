#pragma once

#include "SharedMemory.h"

#include <Windows.h>

class PCars2SharedMemory
{
public:
	PCars2SharedMemory();
	~PCars2SharedMemory();

public:
	bool initialize();
	void update();

public:
	SharedMemory* pDataLocal = nullptr;

protected:
	HANDLE hFileMapping = nullptr;
	const SharedMemory* pDataMapped = nullptr;
};

