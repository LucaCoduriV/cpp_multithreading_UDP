#ifndef MULTITHREADING_DATAGRAM_H
#define MULTITHREADING_DATAGRAM_H

namespace UDP{
   struct Datagram{
      using ID = uint16_t;
      static constexpr size_t BufferMaxSize = 1400;
      static constexpr size_t DataMaxSize = BufferMaxSize - sizeof(ID);
      struct Header{
         ID id;
         ID ack;
         uint64_t previousAcks;
      };

      Header header;
      std::array<uint8_t, DataMaxSize> data;

   };
}

#endif //MULTITHREADING_DATAGRAM_H
