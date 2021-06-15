#ifndef MULTITHREADING_ACKHANDLER_H
#define MULTITHREADING_ACKHANDLER_H

#include <cstdint>
#include <vector>

namespace UDP{
   class AckHandler{

   private:
      uint16_t mLastAck = -1;
      uint64_t mPreviousAcks = -1;
      uint64_t mNewAcks = 0;
      std::vector<uint16_t> mLoss;
      bool mLastAckIsNew{ false };

   public:
      AckHandler() = default;
      AckHandler(const AckHandler&) = default;
      AckHandler& operator=(const AckHandler&) = default;
      AckHandler(AckHandler&&) = default;
      AckHandler& operator=(AckHandler&&) = default;
      ~AckHandler() = default;

      [[nodiscard]] uint16_t lastAck() const;
      [[nodiscard]] uint64_t previousAcksMask() const;
      [[nodiscard]] std::vector<uint16_t> getNewAcks() const;
      std::vector<uint16_t>&& loss();

      void update(uint16_t newAck, uint64_t previousAcks, bool trackLoss = false);
      [[nodiscard]] bool isAcked(uint16_t ack) const;
      [[nodiscard]] bool isNewlyAcked(uint16_t ack) const;


   };
}

#endif //MULTITHREADING_ACKHANDLER_H
