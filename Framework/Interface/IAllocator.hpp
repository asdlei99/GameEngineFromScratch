#pragma once
#include <cstdint>
#include <cstdlib>

#include "IMemoryManager.hpp"
#include "Interface.hpp"

namespace My {
_Interface_ IAllocator {
   public:
    // debug patterns
    const uint8_t PATTERN_ALIGN = 0xFC;
    const uint8_t PATTERN_ALLOC = 0xFD;
    const uint8_t PATTERN_FREE = 0xFE;

    IAllocator(IMemoryManager * pMmgr) : m_pMemoryManager(pMmgr){}
    virtual ~IAllocator();

    virtual void* Allocate(size_t size) = 0;
    virtual void Free(void* p) = 0;
    virtual void FreeAll() = 0;

   protected:
    IMemoryManager* m_pMemoryManager;
};
}  // namespace My