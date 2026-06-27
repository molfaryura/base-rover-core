// Logic of the robot states, handling crashes
#ifndef FSM_H
#define FSM_H

#include <stdlib.h>
#include <stdint.h>

typedef struct{
    int8_t speed_left;
    int8_t speed_right;
    time_t last_packet_time;

} State;

typedef enum{
    STATE_INIT,
    STATE_IDLE,
    STATE_MANUAL,
    STATE_SAFE_STOP
} FSM;

typedef struct {
    uint8_t command_id;
    int8_t speed_left;
    int8_t speed_right;
    uint8_t checksum;
} __attribute__((__packed__)) MotorCommand;

#endif
