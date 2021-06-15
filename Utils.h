#ifndef MULTITHREADING_UTILS_H
#define MULTITHREADING_UTILS_H

#include <cstdint>

namespace Utils{
   bool IsSequenceNewer(uint16_t sNew, uint16_t sLast);
   uint16_t SequenceDiff(uint16_t sNew, uint16_t sLast);

   void SetBit(uint64_t& bitfield, uint8_t n);
   void UnsetBit(uint64_t& bitfield, uint8_t n);
   bool HasBit(uint64_t bitfield, uint8_t n);

   template<class INTEGER>
   struct Bit {};
   template<>
   struct Bit<uint64_t> {
      static constexpr uint64_t Right = 0b0000000000000000000000000000000000000000000000000000000000000001;
   };
}

#endif //MULTITHREADING_UTILS_H
