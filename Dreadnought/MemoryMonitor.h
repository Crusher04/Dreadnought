#ifndef MEMORYMONITOR_H
#define MEMORYMONITOR_H

#include <iostream>
#include <memory>
#include <fstream>
#include <stdlib.h>
#include <crtdbg.h>

    class DataCollector {
    public:
        size_t totalBytesAllocated = 0;
        size_t totalBytesFreed = 0;
        size_t totalAllocationRequests = 0;
        size_t totalFreeRequests = 0;
        
        std::ofstream myFile;

        DataCollector() = default;
        ~DataCollector() {
            myFile.open("MemoryMonitor.csv", std::ios::app);

            if(myFile.is_open())
            {
                
                myFile << "\nMonitoring Files at destination: " << __FILE__ << "\n";
                myFile << "Allocated/Deallocated Total Bytes\n  ";
                for (int i = 0; i < 64; i++)
                    myFile << "-";
                myFile << "\nTotal Bytes Allocated: " << totalBytesAllocated << " \nTotal Bytes Freed: " << totalBytesFreed << "\n";
                myFile << "Total Allocation Requests: " << totalAllocationRequests << " \nTotal Deallocation Requests: " << totalFreeRequests << "\n";

                if (totalAllocationRequests > totalFreeRequests)
                    myFile << "\n Leak Detected of " << (totalBytesAllocated - totalBytesFreed) << " bytes!\n";

            }
            else
            {
                std::cerr << "\n\t**Failed to open MemoryMonitor.csv**\n";
            }
            myFile.close();

            
        }
    };

    DataCollector nomnom = DataCollector();


void* operator new(std::size_t numBytes) {
    nomnom.totalBytesAllocated += numBytes;
    nomnom.totalAllocationRequests += 1;

    return std::malloc(numBytes);

}

void operator delete(void* memoryLocation, std::size_t numBytes) {
    //std::cout << "freeing " << numBytes << " bytes of memory\n";
    nomnom.totalBytesFreed += numBytes;
    nomnom.totalFreeRequests += 1;
    std::free(memoryLocation);

}

/// This is a trick to get access to numBytes 
/// w/o wild typecasts. 
struct ArraySize{
    std::size_t numBytes;
};

/// I did a little hack to hide the total number of bytes
/// allocated in the array itself. 
void* operator new[](std::size_t numBytes) {
    //std::cout << "allocating an array of " << numBytes << " bytes of memory\n";
    ArraySize* array = reinterpret_cast<ArraySize*>(std::malloc(numBytes + sizeof(ArraySize)));
    if( array ) array->numBytes = numBytes;

    nomnom.totalBytesAllocated += numBytes;
    nomnom.totalAllocationRequests += 1;

    return array + 1;
}

/// This overload doesn't work as advertised in VS22
void operator delete[](void* memoryLocation) {
    ArraySize* array = reinterpret_cast<ArraySize*>(memoryLocation) - 1;
    //std::cout << "freeing array "<< array->numBytes << " bytes of memory\n";

    nomnom.totalBytesFreed += array->numBytes;
    nomnom.totalFreeRequests += 1;

    free(array);
}

void* CreateMemoryPool(size_t sz) {
    std::cout << "allocating " << sz << " bytes of memory\n";
    return std::malloc(sz);
}

void DeleteMemoryPool(void* memoryPool, size_t sz) {
    std::cout << "freeing " << sz << " bytes of memory\n";
    free(memoryPool);
}


#endif