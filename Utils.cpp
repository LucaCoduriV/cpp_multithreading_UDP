#include "Utils.h"
#include <limits>
#include <cassert>

namespace Utils{
   bool IsSequenceNewer(uint16_t sNew, uint16_t sLast)
   {
      if (sNew == sLast)
         return false;
      return (sNew > sLast && sNew - sLast <= std::numeric_limits<uint16_t>::max() / 2) // cas simple : 4 > 2
             || (sNew < sLast && sLast - sNew > std::numeric_limits<uint16_t>::max() / 2); // dépassement : 2 > 65534
   }

   uint16_t SequenceDiff(uint16_t sNew, uint16_t sLast)
   {
      if (sNew == sLast)
         return 0;
      assert(IsSequenceNewer(sNew, sLast)); //!< S’ils ne sont pas dans le bon ordre le diff n’a pas beaucoup de sens et n’est pas permis
      if (sNew > sLast && sNew - sLast <= std::numeric_limits<uint16_t>::max() / 2)
         return sNew - sLast;
      //!< dépassement
      return (std::numeric_limits<uint16_t>::max() - sLast) + sNew + 1; //!< +1 pour compter le 0 : si sLast == sMax && sNew == 0, la difference est 1
   }

   void SetBit(uint64_t& bitfield, const uint8_t n)
   {
      assert(n < 64);
      bitfield |= (Bit<uint64_t>::Right << n);
   }
   void UnsetBit(uint64_t& bitfield, const uint8_t n)
   {
      assert(n < 64);
      bitfield &= (~(Bit<uint64_t>::Right << n));
   }
   bool HasBit(uint64_t bitfield, const uint8_t n)
   {
      assert(n < 64);
      return (bitfield & (Bit<uint64_t>::Right << n)) != 0;
   }

}