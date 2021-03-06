#pragma once

#include <stdint.h>

int maxMsgBoxId();

enum MsgBoxError {
    MBE_NO_ERROR = 0,
    MBE_INVALID_ID = 1,
    MBE_NOT_INITIALIZED = 2,
    MBE_INVALID_ARGS = 3
};

struct MsgBoxInfo {
    void *memory; // buffer to store messages.
    uint8_t msgSize;
    uint8_t msgMaxCount;
};

#pragma pack (push, 1)
struct MessageHeader {
    uint8_t senderPID;
    uint8_t isParent;
    uint16_t reserved;
};
#pragma pack (pop)

struct Message {
    struct MessageHeader header;
    uint8_t body[0];
};

enum MsgBoxError initMsgBox(int id, const struct MsgBoxInfo *);

enum MsgBoxError recvMsgFrom(int id, struct Message *buffer);

enum MsgBoxError recvAnyMsg(struct Message *buffer);

enum MsgBoxError closeMsgBox(int id);

enum MsgBoxError moveMsgBox(int id, void *newLocation);

struct Packet {
    int pid;
    int msgBoxId;
    void *message;
};

enum SendError {
    SE_NO_ERROR = 0,
    SE_DEST_NOT_REACHABLE = 1,
    SE_DEST_TOO_BUSY = 2,
    SE_INVALID_ARGS = 3
};

enum SendError sendPacket(const struct Packet *packet);

