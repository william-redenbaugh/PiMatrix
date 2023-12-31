#ifndef _EVENT_TYPE_LIST_H
#define _EVENT_TYPE_LIST_H

typedef enum{
    EVENT_NONE = 0,
    EVENT_LED_UPDATE,
    EVENT_LED_BRIGHTNESS_UPDATE,
    EVENT_DISPLAY_UPDATE,
    EVENT_STATUS_LED_ON,
    EVENT_LED_OFF,
    EVENT_LED_TURN_RIGHT,
    EVENT_LED_TURN_LEFT,
    EVENT_LED_FLASH_SLOWING_DOWN,
    EVENT_LED_ON,
    EVENT_STATUS_LED_OFF, 
    EVENT_END,
}event_type_t;


typedef struct event_data{
    event_type_t event_id; 
    void *data_ptr;
}event_data_t;

#define EVENT_TYPE_EVENT_END EVENT_END

#endif