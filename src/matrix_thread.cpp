#include "matrix_thread.h"
#include "global_includes.h"
static os_mut_t matrix_mutx; 

#ifdef LED_MATRIX_DEBUGGING
#define led_matrix_println(e) println(e)
#else
#define led_matrix_println(e) void(e)
#endif

static int led_matrix_frame_length; 

uint8_t frame_data[12288];

static local_eventqueue_t matrix_queue;

void new_matrix_frame_msg(ipc_sub_ret_cb_t ret){

    int len = ret.msg_header.message_len;
    uint8_t *data = ret.data;

    os_mut_entry_wait_indefinite(&matrix_mutx);
    // Copy data over to frame
    if(len >= sizeof(frame_data)){
        memcpy(frame_data, data, sizeof(frame_data));
    }
    os_mut_exit(&matrix_mutx);

    event_data_t event_data;
    local_eventqueue_enqueue(&matrix_queue, event_data);
}

void matrix_thread(void *params){
    for(;;){
        event_data_t data;
        local_eventqueue_dequeue(&matrix_queue, &data);
        os_mut_entry_wait_indefinite(&matrix_mutx);
        // LED_STRIP_SHOW!!S
        os_mut_exit(&matrix_mutx);
        os_thread_sleep_ms(10);
    }
}

void matrix_thread_init(void *params){
    os_mut_init(&matrix_mutx);
    // Setup matrix thread
    ipc_attach_cb(IPC_TYPE_LED_ANIMATION_TYPE, new_matrix_frame_msg);

    local_eventqueue_init(&matrix_queue, 3);
}