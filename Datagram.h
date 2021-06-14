//
// Created by lucac on 15.06.2021.
//

#ifndef MULTITHREADING_DATAGRAM_H
#define MULTITHREADING_DATAGRAM_H

namespace UDP{
   struct Datagram{
      using ID = uint16_t;
      static constexpr size_t BufferMaxSize = 1400;
      static constexpr size_t DataMaxSize = BufferMaxSize - sizeof(ID);

      ID id;
      std::array<uint8_t, DataMaxSize> data;
   };
}

#endif //MULTITHREADING_DATAGRAM_H
